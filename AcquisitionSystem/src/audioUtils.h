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

#ifndef AUDIO_UTILS_H
#define AUDIO_UTILS_H

#include <Arduino.h>
#include <Audio.h>
#include "Audio/record_wav_buffered.h"

class AudioUtils
{
  public:
    static constexpr const size_t EXT_BUFFER_SIZE = 65536 * 64;    // 4 MB
    static constexpr const size_t CHANNEL_COUNT   = 32;

    AudioUtils();
    bool begin(void);
    bool startRecording(const char* filename);
    bool stopRecording(void);
    bool getRecordingStatus(void);
    int getWavChannelNumber(int channel);
    float getRecordingTime(void) {return recording? ((float)millis() - (float)recordingStartTime) / 1000.0 : 0.0;}
    bool setChannelConfig(int channel, bool enabled) {if(channel < CHANNEL_COUNT && channel >= 0) chanelEnabled[channel] = enabled; else return false; return true;}

  private:
    const AudioBuffer::bufType bufMem = AudioBuffer::inExt;
    bool chanelEnabled[CHANNEL_COUNT];
    uint32_t recordingStartTime = 0;
    bool recording = false;
    volatile bool recordingError = false;

    AudioSynthWaveformSine sine[32];

    audio_block_t *iqa[32];	// Audio input queue for recording
    AudioRecordWAVbuffered* recorder = nullptr;
    AudioConnection* recorderConnection[32];

    bool reconnectAudioBlocks(void);
    static void update(void* parameter);
};

#endif