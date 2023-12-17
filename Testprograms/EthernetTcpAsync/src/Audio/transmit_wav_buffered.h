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

#ifndef TRANSMIT_WAV_BUFFERED_H_
#define TRANSMIT_WAV_BUFFERED_H_

#include <Arduino.h>
#include <AudioStream.h>
#include <EventResponder.h>
#include <QNEthernet.h>
#include <circular_buffer.h>

using namespace qindesign::network;


class AudioTransmitWAVbuffered : public EventResponder, public AudioStream
{
public:
    static constexpr const size_t TCP_PACKET_MAX_SIZE = 1460;

	AudioTransmitWAVbuffered(unsigned char ninput, audio_block_t **iqueue);
	AudioTransmitWAVbuffered(void) : AudioTransmitWAVbuffered(2, inputQueueArray) {}
	virtual ~AudioTransmitWAVbuffered(void) {end();}
	bool begin(EthernetServer* tcpServer);
	void end(void);

	bool getBufferOverflowDetected(void)
	{
	  bool res = bufferOverflowDetected;
	  bufferOverflowDetected = false;
	  return res;
	}
  uint32_t getDataRate(void) {return bytesPerSecond;}     // bytes per second
	
	virtual void update(void);
	
	static uint8_t objcnt;
	size_t lowWater;
	// LogLastMinMax<uint32_t> bufferAvail;

  Circular_Buffer<uint8_t, 12 * 1024 * 1024> circularBuffer;
	
	friend class AudioTransmitWAVmono;
	friend class AudioTransmitWAVstereo;
	
private:
	audio_block_t *inputQueueArray[2];
	static void EventResponse(EventResponderRef evref);
	uint32_t flushBuffer(uint8_t* pb, size_t sz);
	volatile bool bufferOverflowDetected = false;

	uint32_t byteCounter = 0;
	uint32_t bytesPerSecond = 0;
	uint32_t secondTimer = 0;

	EthernetServer* server = nullptr;
  EthernetClient client;
	uint8_t chanCnt;
	bool initialized = false;
	volatile bool writePending = false;
	uint8_t objnum;

	size_t writeFully(EthernetClient &c, const uint8_t *buf, size_t size, uint32_t timeout)
  {
		uint32_t startT = millis();
		return qindesign::network::util::writeFully(c, buf, size, [&c, startT, timeout]()
		{
			return !static_cast<bool>(c) || (millis() - startT) >= timeout;
		});
		}
};

class AudioTransmitWAVmono : public AudioTransmitWAVbuffered
{
	public:
		AudioTransmitWAVmono(): AudioTransmitWAVbuffered(1,inputQueueArray) {}
};

class AudioTransmitWAVstereo : public AudioTransmitWAVbuffered
{
	public:
		AudioTransmitWAVstereo(): AudioTransmitWAVbuffered(2,inputQueueArray) {}
};

class AudioTransmitWAVquad : public AudioTransmitWAVbuffered
{
		audio_block_t *iqa[4];	
	public:
		AudioTransmitWAVquad(): AudioTransmitWAVbuffered(4,iqa) {}
};

class AudioTransmitWAVhex : public AudioTransmitWAVbuffered
{
		audio_block_t *iqa[6];	
	public:
		AudioTransmitWAVhex(): AudioTransmitWAVbuffered(6,iqa) {}
};

class AudioTransmitWAVoct : public AudioTransmitWAVbuffered
{
		audio_block_t *iqa[8];	
	public:
		AudioTransmitWAVoct(): AudioTransmitWAVbuffered(8,iqa) {}
};

class AudioTransmitWAV16 : public AudioTransmitWAVbuffered
{
		audio_block_t *iqa[16];	
	public:
		AudioTransmitWAV16(): AudioTransmitWAVbuffered(16,iqa) {}
};

class AudioTransmitWAV32 : public AudioTransmitWAVbuffered
{
		audio_block_t *iqa[32];	
	public:
		AudioTransmitWAV32(): AudioTransmitWAVbuffered(32,iqa) {}
};

#endif
