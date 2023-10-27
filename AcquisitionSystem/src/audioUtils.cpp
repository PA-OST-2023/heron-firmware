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
#include <console.h>
#include <AudioStream.h>
#include <SerialFlash.h>
#include <TeensyThreads.h>
#include <SD.h>

AudioUtils::AudioUtils()
{
  for(int i = 0; i < CHANNEL_COUNT; i++)
  {
    chanelEnabled[i] = true;
    recorderConnection[i] = nullptr;
  }
}

bool AudioUtils::begin(void)
{
  AudioMemory(60);

  float freq[32] = {261.63, 277.19, 293.67, 311.13, 329.63, 349.23, 369.99, 392.00, 415.30, 440.00, 466.16, 493.88, 523.25, 554.37, 587.33, 622.25, 659.25, 698.46, 739.99, 783.99, 830.61, 880.00, 932.33, 987.77, 1046.50, 1108.73, 1174.66, 1244.51, 1318.51, 1396.91, 1479.98, 1567.98};
  for(int i = 0; i < 32; i++)
  {
    sine[i].frequency(freq[i]);
    sine[i].amplitude(0.5);
  }

  threads.addThread(update, this, 1024);
  console.ok.println("[AUDIO] Initialized");
  return true;
}

bool AudioUtils::startRecording(const char* filename)
{
  if(recording)
  {
    console.warning.println("[AUDIO] Already recording");
    return false;
  }
  int channelsActive = 0;
  for(int i = 0; i < CHANNEL_COUNT; i++)
  {
    if(chanelEnabled[i]) channelsActive++;
  }
  if(channelsActive == 0)
  {
    console.error.println("[AUDIO] No channels active");
    return false;
  }
  if(recorder != nullptr)
  {
    while(recorder->disposeBuffer() == MemBuffer::invalid)
    {
      console.warning.println("[AUDIO] Waiting for recorder to dispose buffer");
      threads.delay(50);
    }
    delete recorder;
    recorder = nullptr;
    console.log.println("[AUDIO] Recorder Instance deleted");
  }
  recorder = new AudioRecordWAVbuffered(channelsActive, iqa);
  if(recorder == nullptr)
  {
    console.error.println("[AUDIO] Failed to create recorder");
    return false;
  }
  if(recorder->createBuffer(EXT_BUFFER_SIZE, bufMem))
  {
    console.error.println("[AUDIO] Failed to create buffer");
    return false;
  }
  if(!reconnectAudioBlocks())
  {
    console.error.println("[AUDIO] Failed to reconnect audio blocks");
    return false;
  }

  recording = true;
  recordingError = false;
  if(!recorder->recordSD(filename))
  {
    console.error.println("[AUDIO] Failed to start recording");
    recordingError = true;
    return false;
  }
  recordingStartTime = millis();
  console.log.printf("[AUDIO] Recording to ""%s"" (%d Channels)\n", filename, channelsActive);
  return true;
}

bool AudioUtils::stopRecording(void)
{
  if(!recording)
  {
    console.warning.println("[AUDIO] Not recording");
    return false;
  }
  recorder->stop();
  console.log.printf("[AUDIO] Recording stopped after %.2f seconds\n", getRecordingTime());
  recording = false;
  return true;
}

bool AudioUtils::getRecordingStatus(void)
{
  bool status = !recordingError;
  recordingError = false;
  return status;
}

int AudioUtils::getWavChannelNumber(int channel)
{
  if(channel < 0 || channel >= CHANNEL_COUNT) return -1;
  int wavChannel = 0;
  for(int i = 0; i < channel; i++)
  {
    if(chanelEnabled[i]) wavChannel++;
  }
  return wavChannel - 1;
}

bool AudioUtils::reconnectAudioBlocks(void)
{
  for(int i = 0; i < CHANNEL_COUNT; i++)
  {
    if(recorderConnection[i] != nullptr)
    {
      delete recorderConnection[i];
      recorderConnection[i] = nullptr;
    }
  }
  int channelIndex = 0;
  for(int i = 0; i < CHANNEL_COUNT; i++)
  {
    if(chanelEnabled[i])
    {
      recorderConnection[i] = new AudioConnection(sine[i], 0, *recorder, channelIndex++);
      if(recorderConnection[i] == nullptr)
      {
        console.error.printf("[AUDIO] Failed to connect recorder connection %d\n", i);
        return false;
      }
    }
  }

  return true;
}

void AudioUtils::update(void* parameter)
{
  AudioUtils* ref = (AudioUtils*)parameter;
  while(true)
  {
    if(ref->recorder != nullptr)
    {
      if(ref->recording)
      {
        if(ref->recorder->getBufferOverflowDetected())
        {
          console.error.println("[AUDIO] Buffer overflow detected!");
          ref->recordingError = true;
          ref->recorder->stop();
        }
        if(ref->recorder->getWriteErrorDetected())
        {
          console.error.println("[AUDIO] Write error detected!");
          ref->recordingError = true;
          ref->recorder->stop();
        }
      }
    }
    // TODO: So something usefull with error status
    threads.delay(250);
  }
}
