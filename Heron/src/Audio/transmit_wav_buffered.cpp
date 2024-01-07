/******************************************************************************
* file    transmit_wav_buffered.h
*******************************************************************************
* brief   Audio Class for transmitting PCM-Stream via UDP
*******************************************************************************
* author  Florian Baumgartner
* version 1.0
* date    2023-11-15
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

#include "transmit_wav_buffered.h"
#include <Arduino.h>
#include <TeensyThreads.h>
#include <console.h>


using namespace qindesign::network;
uint8_t AudioTransmitWAVbuffered::objcnt;
EXTMEM CircularBuffer<AudioTransmitWAVbuffered::EXT_RAM_BUFFER_SIZE> AudioTransmitWAVbuffered::circularBuffer;

AudioTransmitWAVbuffered::AudioTransmitWAVbuffered(unsigned char ninput, audio_block_t** iqueue)
    : AudioStream(ninput, iqueue), chanCnt(ninput), writePending(false), objnum(objcnt++)
{
  setContext(this);
  attach(EventResponse);
}

bool AudioTransmitWAVbuffered::begin(int port, bool verboseOutput)
{
  if(initialized)
  {
    console.warning.println("[TRANSMIT WAV BUFFERED] Module was already initialized.");
    return false;
  }
  if(port < 0 || port > 65535)
  {
    console.error.printf("[TRANSMIT WAV BUFFERED] Invalid port number: %d\n", port);
    return false;
  }
  if(!server.begin(port))
  {
    console.error.printf("[TRANSMIT WAV BUFFERED] Could not start server on port %d\n", port);
    return false;
  }
  else
  {
    console.ok.printf("[TRANSMIT WAV BUFFERED] Server started on port %d\n", port);
  }
  verbose = verboseOutput;
  initialized = true;
  return true;
}

void AudioTransmitWAVbuffered::end(void)
{
  if(!initialized)
  {
    console.warning.println("[TRANSMIT WAV BUFFERED] Modle was not initialized.");
    return;
  }
  server.end();
  initialized = false;
}

void AudioTransmitWAVbuffered::EventResponse(EventResponderRef evref)
{
  AudioTransmitWAVbuffered* pPWB = (AudioTransmitWAVbuffered*)evref.getContext();
  pPWB->writePending = true;

  static uint8_t bufferBlock[TCP_PACKET_BLOCK_SIZE];
  if(pPWB->circularBuffer.availableToRead() > sizeof(bufferBlock))
  {
    pPWB->circularBuffer.peek(bufferBlock, sizeof(bufferBlock));
    uint32_t outN = pPWB->flushBuffer(bufferBlock, sizeof(bufferBlock));
    pPWB->circularBuffer.markBytesRead(outN);
    pPWB->byteCounter += outN;    // Count the bytes that have been sent out for the data rate calculation

    if(outN == sizeof(bufferBlock))
    {
      pPWB->lastSendTime = millis();
    }
    else
    {
      // console.warning.printf("[TRANSMIT WAV BUFFERED] Transmitting of %d bytes failed: Transmitted %d\n", sizeof(bufferBlock), outN);
    }
  }
  pPWB->writePending = false;
}

uint32_t AudioTransmitWAVbuffered::flushBuffer(uint8_t* pb, size_t sz)
{
  if(!initialized)
  {
    return 0;
  }

  bool searchForClient = true;
  size_t outN = 0;    // Effective amount of samples that have been sent out
  if(client)
  {
    if(client.connected())
    {
      searchForClient = false;
      uint32_t t0 = millis();
      while(true)
      {
        outN += client.write(pb + outN, sz - outN);
        Ethernet.loop();
        server.flush();
        if(outN >= sz)
        {
          break;
        }
        if(millis() - t0 >= TCP_SEND_TIMEOUT_US)
        {
          if(verbose)
          {
            console.warning.printf("[TRANSMIT WAV BUFFERED] Timeout after %d ms.\n", millis() - t0);
          }
          if(millis() - lastSendTime > TCP_CONNECTION_TIMEOUT_MS)    // If the last send was too long ago, we assume that the connection is lost
          {
            client.abort();
            searchForClient = true;
            console.warning.println("[TRANSMIT WAV BUFFERED] TCP Connection timeout -> close connection...");
          }
          break;
        }
      }
    }
  }

  if(searchForClient)
  {
    client = server.available();
    if(client)
    {
      console.log.println("[TRANSMIT WAV BUFFERED] Client connected");
      circularBuffer.clear();       // Clear buffer as soon as client connects to prevent instant overflow
    }
  }
  return outN;
}

static void interleave(int16_t* buf, int16_t** blocks, uint16_t channels)    // interleave channels of audio from separate blocks into buf
{
  if(1 == channels)    // mono, do the simple thing
  {
    if(nullptr != blocks[0])
      memcpy(buf, blocks[0], AUDIO_BLOCK_SAMPLES * sizeof *buf);
    else
      memset(buf, 0, AUDIO_BLOCK_SAMPLES * sizeof *buf);
  }
  else
    for(uint16_t i = 0; i < channels; i++)
    {
      int16_t* pd = buf + i;
      int16_t* ps = blocks[i];

      if(nullptr != ps)
      {
        for(int j = 0; j < AUDIO_BLOCK_SAMPLES; j++)
        {
          *pd = *ps++;
          pd += channels;
        }
      }
      else    // null data, interpret as silence
      {
        for(int j = 0; j < AUDIO_BLOCK_SAMPLES; j++)
        {
          *pd = 0;
          pd += channels;
        }
      }
    }
}


void AudioTransmitWAVbuffered::update(void)
{
  int16_t buf[chanCnt * AUDIO_BLOCK_SAMPLES];
  audio_block_t* blocks[chanCnt];
  int16_t* data[chanCnt] = {0};
  int alloCnt = 0;    // count of blocks successfully received

  if(millis() - secondTimer > TRANSMISSION_INTERVAL_RATE)
  {
    bytesPerInterval = byteCounter;
    byteCounter = 0;
    secondTimer = millis();
  }

  while(alloCnt < chanCnt)    // receive the audio blocks to record
  {
    blocks[alloCnt] = receiveReadOnly(alloCnt);
    if(nullptr != blocks[alloCnt])
      data[alloCnt] = blocks[alloCnt]->data;
    alloCnt++;
  }

  if(initialized)    // only update if we're recording and not paused, but we must discard the received blocks!
  {
    if(alloCnt >= chanCnt)    // received enough - extract the data
    {
      interleave(buf, data, chanCnt);    // make a chunk of data for the file

      header.blockIndex++;

      bool timeValid = false;
      if(getTimestamp)
      {
        header.timestamp = getTimestamp();
        if(header.timestamp != 0)
        {
          timeValid = true;
        }
      }
      if(!timeValid)    // primary source of time is not valid, check secondary
      {
        if(getBackupTimestamp)
        {
          header.timestamp = getBackupTimestamp();
          if(header.timestamp != 0)
          {
            timeValid = true;
          }
        }
      }
      if(!timeValid)    // secondary source of time is not valid, use micros()
      {
        header.timestamp = (uint64_t)micros() * 1000;    // TODO Get from GPS
      }

      if(circularBuffer.availableToWrite() < (sizeof(buf)))
      {
        circularBuffer.clear();
        bufferOverflowDetected = true;
      }
      else
      {
        circularBuffer.write((uint8_t*)&header, sizeof(header));
        circularBuffer.write((uint8_t*)buf, sizeof(buf));
        if(!writePending)
        {
          triggerEvent(0);
        }
      }
    }
  }

  while(--alloCnt >= 0)               // relinquish our interest in these blocks
    if(nullptr != blocks[alloCnt])    // stock release() can't cope with NULL pointer
      release(blocks[alloCnt]);
}
