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

#include <Arduino.h>
#include <console.h>
#include <TeensyThreads.h>
#include "transmit_wav_buffered.h"


uint8_t AudioTransmitWAVbuffered::objcnt;

AudioTransmitWAVbuffered::AudioTransmitWAVbuffered(unsigned char ninput, audio_block_t **iqueue) : AudioStream(ninput, iqueue), lowWater(0xFFFFFFFF), chanCnt(ninput), writePending(false), objnum(objcnt++)
{
	setContext(this);
	attach(EventResponse);
}

bool AudioTransmitWAVbuffered::begin(EthernetUDP* udp, IPAddress& ip, uint16_t port)
{
  if(initialized)
  {
    console.warning.println("[TRANSMIT WAV BUFFERED] Modle was already initialized.");
    return false;
  }
  Udp = udp;
  destinationIp = ip;
  destinationPort = port;
  if(!Udp->begin(destinationPort))
  {
    console.error.println("[TRANSMIT WAV BUFFERED] UDP could not be initialized.");
    return false;
  }
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
  Udp->stop();
  initialized = false;
}

void AudioTransmitWAVbuffered::EventResponse(EventResponderRef evref)
{
	uint8_t* pb;                      // Pointer of buffer where data can be read from
	size_t sz;                        // Amount of data than can be read from the buffer
	AudioTransmitWAVbuffered* pPWB = (AudioTransmitWAVbuffered*) evref.getContext();

  int cycles = 0;
  while(true)
  {
    if(++cycles > 1024)
    {
      break;
    }
    pPWB->getNextWrite(&pb,&sz);	    // find out where and how much
    if(sz > pPWB->bufSize / 2)			  // never do more than half a buffer
    {
      sz = pPWB->bufSize / 2;
    }
    if(!pPWB->flushBuffer(pb,sz))		      // write out more file data from the buffer
    {
      break;
    }
  }
}

bool AudioTransmitWAVbuffered::flushBuffer(uint8_t* pb, size_t sz)
{
  uint16_t samplesPerpacket = UDP_PACKET_MAX_SIZE / (2 * chanCnt);    // Calculate the number of multichannel-samples that fit in one packet (2 bytes per sample)
  uint16_t bytesPerPacket = samplesPerpacket * 2 * chanCnt;           // Calculate the number of bytes ttaht correspond to the number of samples
  size_t outN = 0;                                                    // Effective amount of samples that have been sent out

	if(sz >= bytesPerPacket && initialized)                          // Data transfer triggered, but there's not enough data - ignore the request
	{
    // console.log.printf("[TRANSMIT WAV BUFFERED] Cycle: %d, Data in buffer: %d\n", maxCycles, sz);
    // if(maxCycles >= 2)
    // {
    //   break;
    // }
    // maxCycles++;

    if(!Udp->beginPacket(destinationIp, destinationPort))
    {
      console.error.println("[TRANSMIT WAV BUFFERED] UDP Could not begin packet.");
      // return;
      // break;
    }
    outN = Udp->write(pb + outN, bytesPerPacket);

    if(!Udp->endPacket())
    {
      console.error.println("[TRANSMIT WAV BUFFERED] UDP Could not end packet.");
      // return;
      // break;
    }

		if (outN != bytesPerPacket)                                        // failed to write out all data
		{
			console.warning.printf("[RECORD WAV BUFFERED] Transmitting of %d bytes failed: Transmitted %d\n", bytesPerPacket, outN);
      // TODO: Set flag
      // break;
		}

    byteCounter += outN;                                              // Count the bytes that have been sent out for the data rate calculation

		bufferAvail.newValue(getAvailable());                             // worse than lowWater
		writeExecuted(bytesPerPacket);
	}
  else
  {
    writePending = false;
    return false;
  }
	writePending = false;
  return true;
}

static void interleave(int16_t* buf,int16_t** blocks,uint16_t channels)     // interleave channels of audio from separate blocks into buf 
{
	if (1 == channels)    // mono, do the simple thing
	{
		if (nullptr != blocks[0])
			memcpy(buf,blocks[0],AUDIO_BLOCK_SAMPLES * sizeof *buf);
		else
			memset(buf,0,AUDIO_BLOCK_SAMPLES * sizeof *buf);
	}
	else
		for (uint16_t i=0;i<channels;i++)
		{
			int16_t* pd = buf+i;
			int16_t* ps = blocks[i];
			
			if (nullptr != ps)
			{
				for (int j=0;j<AUDIO_BLOCK_SAMPLES;j++)
				{
					*pd = *ps++;
					pd += channels;
				}
			}
			else      // null data, interpret as silence
			{
				for (int j=0;j<AUDIO_BLOCK_SAMPLES;j++)
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
	int alloCnt = 0; 	                                    // count of blocks successfully received

  if(millis() - secondTimer > 1000)
  {
    bytesPerSecond = byteCounter;
    byteCounter = 0;
    secondTimer = millis();
  }
	
	while(alloCnt < chanCnt)                              // receive the audio blocks to record
	{
		blocks[alloCnt] = receiveReadOnly(alloCnt);
		if (nullptr != blocks[alloCnt])
			data[alloCnt] = blocks[alloCnt]->data;
		alloCnt++;
	}

	if(initialized)                                       // only update if we're recording and not paused, but we must discard the received blocks!
	{
		if(alloCnt >= chanCnt)                              // received enough - extract the data
		{
			interleave(buf, data, chanCnt);	                  // make a chunk of data for the file
			result rdr = write((uint8_t*) buf, sizeof buf);   // send it to the buffer			
			if (ok != rdr && !writePending)  	                // there's now room for a buffer read and we haven't already asked
			{
        writePending = true;
				triggerEvent(0);
			}
			else if(rdr == invalid)
			{
			  bufferOverflowDetected = true;
        console.error.println("[TRANSMIT WAV BUFFERED] Buffer overflow detected.");
			}
		}
	}
	
	while(--alloCnt >= 0)                                 // relinquish our interest in these blocks
		if (nullptr != blocks[alloCnt])                     // stock release() can't cope with NULL pointer
			release(blocks[alloCnt]);
}
