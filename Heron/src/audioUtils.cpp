/******************************************************************************
* file    audioUtils.h
*******************************************************************************
* brief   Audio functions like recording, processing, etc.
*******************************************************************************
* author  Florian Baumgartner
* version 1.0
* date    2023-10-26
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

#include "audioUtils.h"
#include <AudioStream.h>
#include <TeensyThreads.h>
#include <console.h>

EXTMEM AudioInputTDM AudioUtils::tdmIn1;
EXTMEM AudioInputTDM2 AudioUtils::tdmIn2;
EXTMEM AudioTransmitWAV32 AudioUtils::transmitter;
EXTMEM AudioAnalyzePeak AudioUtils::peak[CHANNEL_COUNT];

AudioUtils::AudioUtils()
{
  AudioMemory(128);

        // for(int i = 0; i < CHANNEL_COUNT; i++)
     // {
     //   if(i < 16)
     //   {
     //     transmitterConnection[i] = new AudioConnection(tdmIn1, i, transmitter, i);
     //     peakConnection[i] = new AudioConnection(tdmIn1, i, peak[i], 0);
     //   }
     //   else
     //   {
     //     transmitterConnection[i] = new AudioConnection(tdmIn2, i - 16, transmitter, i);
     //     peakConnection[i] = new AudioConnection(tdmIn2, i - 16, peak[i], 0);
     //   }
     // }
}

AudioUtils::~AudioUtils()
{
     // for(int i = 0; i < CHANNEL_COUNT; i++)
     // {
     //   if(transmitterConnection[i] != nullptr)
     //   {
     //     delete transmitterConnection[i];
     //     transmitterConnection[i] = nullptr;
     //   }
     //   if(peakConnection[i] != nullptr)
     //   {
     //     delete peakConnection[i];
     //     peakConnection[i] = nullptr;
     //   }
     // }
}

bool AudioUtils::begin(void)
{
  for(int i = 0; i < ADAU7118_COUNT; i++)
  {
    if(!adau7118[i].begin(i & 1, ADAU7118::DECIMATION_RATIO_64))
    {
      console.error.printf("[AUDIO] Failed to initialize ADAU7118 %d\n", i);
      return false;
    }
    adau7118[i].setHighPassFilter(ADAU7118::FILTER_27_474HZ);
  }
  console.log.println("[AUDIO] Initialized ADAU7118");

  threads.addThread(update, this, 1024);
  console.ok.println("[AUDIO] Initialized");
  return true;
}

bool AudioUtils::startServer(int port)
{
  if(serverRunning)
  {
    console.warning.println("[AUDIO] Server is already running -> stop it first");
    transmitter.end();
  }
  return transmitter.begin(port);
}

bool AudioUtils::stopServer(void)
{
  if(!serverRunning)
  {
    console.warning.println("[AUDIO] Server is not running!");
    return false;
  }
  transmitter.end();
  return true;
}

float AudioUtils::getPeak(int channel)
{
  if(channel < 0 || channel >= CHANNEL_COUNT)
    return 0.0;
  if(peak[channel].available())
  {
    volumeValue[channel] = peak[channel].read();
  }
  return volumeValue[channel];
}

void AudioUtils::update(void* parameter)
{
  AudioUtils* ref = (AudioUtils*)parameter;
  while(true)
  {
             // if(ref->recorder != nullptr)
             // {
             //   if(ref->recording)
             //   {
             //     if(ref->recorder->getBufferOverflowDetected())
             //     {
             //       console.error.println("[AUDIO] Buffer overflow detected!");
             //       ref->recordingError = true;
             //       ref->recorder->stop();
             //     }
             //     if(ref->recorder->getWriteErrorDetected())
             //     {
             //       console.error.println("[AUDIO] Write error detected!");
             //       ref->recordingError = true;
             //       ref->recorder->stop();
             //     }
             //   }
             // }

                      // TODO: So something usefull with error status
    threads.delay(1000.0 / UPDATE_RATE);
  }
}