/******************************************************************************
* file    app.app
*******************************************************************************
* brief   Main application class, handles state machine
*******************************************************************************
* author  Florian Baumgartner
* version 1.0
* date    2023-10-31
*******************************************************************************
* MIT License
*
* Copyright (c) 2023 ICAI Interdisciplinary Center for Artificial Intelligence
*
* Permission is hereby granted, free of charge, to any person obtaining a copy
* of this software and associated documentation files (the "Software"), to deal
* in the Software without restriction, including without limitation the rights
* to use, copy, modify, merge, publish, distribute, sublicense, and/or sell          
* copies of the Software, and to permit persons to whom the Software is
* furnished to do so, subject to the following conditions:
*
* The above copyright notice and this permission notice shall be included in
* all copies or substantial portions of the Software.
*
* THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
* IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
* FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
* AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
* LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
* OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
* SOFTWARE.
******************************************************************************/

#include "app.h"
#include <console.h>
#include <TeensyThreads.h>

App* App::ref = nullptr;

App::App(AudioUtils& audio, Hmi& hmi, Gui& gui, Utils& utils) : audio(audio), hmi(hmi), gui(gui), utils(utils)
{
  ref = this;
}

bool App::begin(void)
{
  for(int i = 0; i < 32; i++)     // TODO: Get from EEPROM
  {
    channelEnabled[i] = true;
  }
  gui.setChannelEnabled(channelEnabled);
  hmi.setChannelEnabled(channelEnabled);
  audio.setChannelConfig(channelEnabled);

  gui.setRecordingState(false);
  gui.setChannelMonitor(0);

  threads.addThread(update, (void*)this, 4096);
  console.ok.println("[APP] Initialized");
  return true;
}

void App::callbackUpdateTime(void)
{
  uint8_t day, month, hour, minute, second;
  uint16_t year;
  ref->gui.getTimeDate(year, month, day, hour, minute, second);
  ref->hmi.setTimeDate(year, month, day, hour, minute, second);
  console.log.printf("[APP] Updated RTC-Time: %02d.%02d.%04d %02d:%02d:%02d\n", day, month, year, hour, minute, second);
}

void App::callbackSetRollerTime(void)
{
  uint8_t day, month, hour, minute, second;
  uint16_t year;
  ref->hmi.getTimeDate(year, month, day, hour, minute, second);
  ref->gui.setTimeDate(year, month, day, hour, minute, second);
}

void App::update(void* parameter)
{
  App* app = (App*)parameter;
  while(true)
  {
    static uint32_t tRtc = 0;
    if(millis() - tRtc > 1000)
    {
      tRtc = millis();
      uint8_t hour, minute, second;
      app->hmi.getTime(hour, minute, second);
      app->gui.setTime(hour, minute);
    }

    bool channelConfigUpdated = false;
    static uint32_t tHmi = 0;
    if(millis() - tHmi > 50)
    {
      tHmi = millis();
      ref->gui.setVolume(ref->hmi.getVolume());
      // TODO: Set volume of headphones

      memcpy(ref->channelEnabledOld, ref->channelEnabled, sizeof(channelEnabled));
      ref->gui.getChannelEnabled(ref->channelEnabled);
      if(memcmp(ref->channelEnabledOld, ref->channelEnabled, sizeof(channelEnabled)) != 0)
      {
        console.log.println("[APP] Updated channel config");
        ref->gui.setChannelEnabled(ref->channelEnabled);    // Update Channel indices
        ref->hmi.setChannelEnabled(ref->channelEnabled);
        ref->audio.setChannelConfig(ref->channelEnabled);
        channelConfigUpdated = true;
      }

      Gui::SdCardStatus_t sdCardStatus = Gui::SD_CARD_MISSING;
      if(ref->utils.isSdCardPresent())
      {
        sdCardStatus = ref->utils.getSdCardError()? Gui::SD_CARD_ERROR : Gui::SD_CARD_OK;
      }
      ref->gui.setSdCardStatus(sdCardStatus);

      Gui::UsbStatus_t usbStatus = Gui::USB_DISCONNECTED;
      if(ref->utils.usbConnected())
      {
        usbStatus = console? Gui::USB_ACTIVE : Gui::USB_CONNECTED;
      }
      ref->gui.setUsbStatus(usbStatus);

      Gui::EthStatus_t ethStatus = Gui::ETH_DISCONNECTED;   // TODO: Get status from Ethernet Module
      ref->gui.setEthStatus(ethStatus);

      ref->gui.setDiskUsage(ref->utils.getSdCardUsedSizeMb(), ref->utils.getSdCardTotalSizeMb());
      ref->gui.setFileContainer(ref->utils.getFileContainer(), ref->utils.getFileContainerSize());

      ref->hmi.setRecordingStatus(ref->recording? ref->audio.getRecordingTime() : 0.0);     // Make Recording LED blink when recording
    }

    for(int i = 0; i < AudioUtils::CHANNEL_COUNT; i++)
    {
      ref->hmi.setLedVolume(i, ref->audio.getPeak(i));
    }

    bool mainScreenActive = ref->gui.isMainScreenActive();
    if(!ref->systemBooted && mainScreenActive)
    {
      ref->systemBooted = true;
      console.ok.println("[APP] System booted and is ready\n");
      console.print(CONSOLE_COLOR_BOLD_MAGENTA CONSOLE_BACKGROUND_DEFAULT);
      console.print("****************************************************\n\n");
      console.print(CONSOLE_COLOR_DEFAULT CONSOLE_BACKGROUND_DEFAULT);
    }
    if(mainScreenActive)
    {
      if(ref->hmi.getButtonSelectEvent())
      {
        ref->monitorChannel++;
        channelConfigUpdated = true;
      }
      if(channelConfigUpdated)
      {
        if(ref->getChannelCount() > 0)
        {
          for(; ref->monitorChannel < AudioUtils::CHANNEL_COUNT + 1; ref->monitorChannel++)
          {
            if(ref->channelEnabled[ref->monitorChannel])
            {
              break;
            }
          }
          if(ref->monitorChannel >= 32) ref->monitorChannel = -1;
        }
        else
        {
          console.warning.println("[APP] No channels enabled");
          ref->monitorChannel = -1;
        }
        ref->gui.setChannelMonitor(ref->monitorChannel);
        ref->hmi.setChannelMonitor(ref->monitorChannel);
      }

      if(ref->hmi.getButtonRecordEvent())
      {
        if(!ref->recording)
        {
          console.log.println("[APP] Button REC pressed (start recording)");
          uint8_t day, month, hour, minute, second;
          uint16_t year;
          ref->hmi.getDate(year, month, day);
          ref->hmi.getTime(hour, minute, second);
          uint32_t channelCoding = 0x00000000;
          for(int i = 0; i < AudioUtils::CHANNEL_COUNT; i++)
          {
            if(ref->channelEnabled[i])
            {
              channelCoding |= (1 << i);
            }
          }
          sprintf(ref->fileName, "%02d%02d%02d_%02d%02d%02d_%02d_%08lX.wav", year - 2000, month, day, hour, minute, second, ref->getChannelCount(), channelCoding);
          if(ref->utils.lockSdCardAccess())
          {
            // TODO: Move UI page to channels
            if(ref->audio.startRecording(ref->fileName))
            {
              ref->recording = true;
              ref->gui.setRecordingState(true);
            }
            else
            {
              ref->utils.unlockSdCardAccess();
              console.error.println("[APP] Could not start recording");
            }
          }
          else
          {
            console.error.println("[APP] Could not lock SD card access");
          }
        }
        else
        {
          console.log.println("[APP] Button REC pressed (stop recording)");
          if(ref->audio.stopRecording())
          {
            ref->recording = false;
            ref->gui.setRecordingState(false);
          }
          else
          {
            console.error.println("[APP] Could not stop recording");
          }
          console.log.println("[APP] Unlocking SD card access");
          ref->utils.unlockSdCardAccess();
        }
      }

      if(ref->recording)
      {
        ref->gui.setRecordingTime(ref->audio.getRecordingTime());
        ref->gui.setRemainingRecordingTime(ref->calculateRemainingRecordingTime(ref->audio.getRecordingTime()));
      }
    }

    if(ref->audio.getRecordingError())
    {
      console.error.println("[APP] Recording error");
      ref->recording = false;
      ref->audio.stopRecording();
      ref->gui.setRecordingState(false);
      ref->utils.unlockSdCardAccess();
      ref->error = "Recording error occured";
    }

    // TODO: Catch all warnings and error and update GUI and HMI (until the user acknowledges the warning/error by pressing on the message-box)
    // ref->gui.setSystemWarning(ref->warning);    // TODO: Remove warning after user interaction
    if(ref->error)
    {
      ref->hmi.setSystemStatus(Hmi::STATUS_ERROR);
    }
    else if(ref->warning)
    {
      ref->hmi.setSystemStatus(Hmi::STATUS_WARNING);
    }
    else if(ref->systemBooted)
    {
      ref->hmi.setSystemStatus(Hmi::STATUS_OK);
    }
      
    threads.delay(1000.0 / UPDATE_RATE);
  }
}

int App::getChannelCount(void)
{
  int count = 0;
  for(int i = 0; i < AudioUtils::CHANNEL_COUNT; i++)
  {
    if(channelEnabled[i]) count++;
  }
  return count;
}

float App::calculateRemainingRecordingTime(float recordingTime)
{
  int channelCount = getChannelCount();
  float totalSizeMb = utils.getSdCardTotalSizeMb();
  float usedSizeMb = utils.getSdCardUsedSizeMb();

  float remainingTime = 0.0;
  if(channelCount > 0)
  {
    float remainingSizeMb = (totalSizeMb - usedSizeMb) * 1024.0 * 1024.0;
    remainingTime = remainingSizeMb / ((float)channelCount * 2 * 44100);    // 2 Bytes per sample, n channels, 44100 samples per second
  }
  return remainingTime - recordingTime;
}
