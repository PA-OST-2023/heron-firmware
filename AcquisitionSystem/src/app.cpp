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
    if(millis() - tHmi > 100)
    {
      tHmi = millis();
      ref->gui.setVolume(ref->hmi.getVolume());
      // TODO: Set volume of headphones

      memcpy(ref->channelEnabledOld, ref->channelEnabled, sizeof(channelEnabled));
      ref->gui.getChannelEnabled(ref->channelEnabled);
      if(memcmp(ref->channelEnabledOld, ref->channelEnabled, sizeof(channelEnabled)) != 0)
      {
        console.log.println("[APP] Updated channel config");
        ref->gui.setChannelEnabled(ref->channelEnabled);    // Update Chanel indices
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

      ref->gui.setSystemWarning(ref->warning);
      // TODO: Remove warning after user interaction

      ref->utils.setSdCardScanAccess(!ref->recording);      // Disable SD-Card scan while recording
      ref->gui.setDiskUsage(ref->utils.getSdCardUsedSizeMb(), ref->utils.getSdCardTotalSizeMb());
    }

    for(int i = 0; i < AudioUtils::CHANNEL_COUNT; i++)
    {
      ref->hmi.setLedVolume(i, ref->audio.getPeak(i));
    }

    bool mainScreenActive = ref->gui.isMainScreenActive();
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
        static int fileNumber = 0;    // TODO: Remove later
        if(!ref->recording)
        {
          console.log.println("[APP] Button REC pressed");
          sprintf(ref->fileName, "test_%d.wav", fileNumber++);
          if(ref->audio.startRecording(ref->fileName))
          {
            ref->recording = true;
            ref->gui.setRecordingState(true);
          }
        }
        else
        {
          console.log.println("[APP] Button REC pressed");
          if(ref->audio.stopRecording())
          {
            ref->recording = false;
            ref->gui.setRecordingState(false);
          }
        }
      }

      if(ref->recording)
      {
        ref->gui.setRecordingTime(ref->audio.getRecordingTime());
        // TODO: Calculate remaining recording time
      }
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
