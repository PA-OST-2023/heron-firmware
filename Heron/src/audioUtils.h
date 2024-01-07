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

#include <ADAU7118.h>
#include <Arduino.h>
#include <Audio.h>
#include <utils.h>
#include "Audio/transmit_wav_buffered.h"

class AudioUtils
{
 public:
  static constexpr const size_t CHANNEL_COUNT = 32;
  static constexpr const size_t ADAU7118_COUNT = 4;
  static constexpr const float UPDATE_RATE = 30.0;    // Hz

  AudioUtils();
  bool begin(void);
  bool startServer(int port);
  bool stopServer(void);
  void clearBuffer(void) { transmitter.clearBuffer(); }
  bool getConnectionStatus(void) { return transmitter.getConnectionState(); }
  float getDataRateMBit(void) { return (transmitter.getDataRate() * 8.0) / 1024.0 / 1024.0; }
  float getBufferFillLevelPercent(void) { return transmitter.getBufferFillLevel() * 100.0; }
  bool getBufferOverflowDetected(void) { return transmitter.getBufferOverflowDetected(); }
  void setTimestampCallback(uint64_t (*callback)(void)) { transmitter.setTimestampCallback(callback); }
  void setBackupTimestampCallback(uint64_t (*callback)(void)) { transmitter.setBackupTimestampCallback(callback); }
  static float getPeak(int channel);

 private:
  ADAU7118 adau7118[ADAU7118_COUNT] = {ADAU7118(Utils::sysWire, 0x14), ADAU7118(Utils::sysWire, 0x15), ADAU7118(Utils::sysWire, 0x16),
                                       ADAU7118(Utils::sysWire, 0x17)};

  static AudioInputTDM tdmIn1;
  static AudioInputTDM2 tdmIn2;
  static AudioTransmitWAV32 transmitter;
  static AudioAnalyzePeak peak[CHANNEL_COUNT];

  AudioConnection transmitterConnection[CHANNEL_COUNT] = {
    AudioConnection(tdmIn1, 0, transmitter, 0),   AudioConnection(tdmIn1, 1, transmitter, 1),   AudioConnection(tdmIn1, 2, transmitter, 2),
    AudioConnection(tdmIn1, 3, transmitter, 3),   AudioConnection(tdmIn1, 4, transmitter, 4),   AudioConnection(tdmIn1, 5, transmitter, 5),
    AudioConnection(tdmIn1, 6, transmitter, 6),   AudioConnection(tdmIn1, 7, transmitter, 7),   AudioConnection(tdmIn1, 8, transmitter, 8),
    AudioConnection(tdmIn1, 9, transmitter, 9),   AudioConnection(tdmIn1, 10, transmitter, 10), AudioConnection(tdmIn1, 11, transmitter, 11),
    AudioConnection(tdmIn1, 12, transmitter, 12), AudioConnection(tdmIn1, 13, transmitter, 13), AudioConnection(tdmIn1, 14, transmitter, 14),
    AudioConnection(tdmIn1, 15, transmitter, 15), AudioConnection(tdmIn2, 0, transmitter, 16),  AudioConnection(tdmIn2, 1, transmitter, 17),
    AudioConnection(tdmIn2, 2, transmitter, 18),  AudioConnection(tdmIn2, 3, transmitter, 19),  AudioConnection(tdmIn2, 4, transmitter, 20),
    AudioConnection(tdmIn2, 5, transmitter, 21),  AudioConnection(tdmIn2, 6, transmitter, 22),  AudioConnection(tdmIn2, 7, transmitter, 23),
    AudioConnection(tdmIn2, 8, transmitter, 24),  AudioConnection(tdmIn2, 9, transmitter, 25),  AudioConnection(tdmIn2, 10, transmitter, 26),
    AudioConnection(tdmIn2, 11, transmitter, 27), AudioConnection(tdmIn2, 12, transmitter, 28), AudioConnection(tdmIn2, 13, transmitter, 29),
    AudioConnection(tdmIn2, 14, transmitter, 30), AudioConnection(tdmIn2, 15, transmitter, 31)};

  AudioConnection peakConnection[CHANNEL_COUNT] = {
    AudioConnection(tdmIn1, 0, peak[0], 0),   AudioConnection(tdmIn1, 1, peak[1], 0),   AudioConnection(tdmIn1, 2, peak[2], 0),
    AudioConnection(tdmIn1, 3, peak[3], 0),   AudioConnection(tdmIn1, 4, peak[4], 0),   AudioConnection(tdmIn1, 5, peak[5], 0),
    AudioConnection(tdmIn1, 6, peak[6], 0),   AudioConnection(tdmIn1, 7, peak[7], 0),   AudioConnection(tdmIn1, 8, peak[8], 0),
    AudioConnection(tdmIn1, 9, peak[9], 0),   AudioConnection(tdmIn1, 10, peak[10], 0), AudioConnection(tdmIn1, 11, peak[11], 0),
    AudioConnection(tdmIn1, 12, peak[12], 0), AudioConnection(tdmIn1, 13, peak[13], 0), AudioConnection(tdmIn1, 14, peak[14], 0),
    AudioConnection(tdmIn1, 15, peak[15], 0), AudioConnection(tdmIn2, 0, peak[16], 0),  AudioConnection(tdmIn2, 1, peak[17], 0),
    AudioConnection(tdmIn2, 2, peak[18], 0),  AudioConnection(tdmIn2, 3, peak[19], 0),  AudioConnection(tdmIn2, 4, peak[20], 0),
    AudioConnection(tdmIn2, 5, peak[21], 0),  AudioConnection(tdmIn2, 6, peak[22], 0),  AudioConnection(tdmIn2, 7, peak[23], 0),
    AudioConnection(tdmIn2, 8, peak[24], 0),  AudioConnection(tdmIn2, 9, peak[25], 0),  AudioConnection(tdmIn2, 10, peak[26], 0),
    AudioConnection(tdmIn2, 11, peak[27], 0), AudioConnection(tdmIn2, 12, peak[28], 0), AudioConnection(tdmIn2, 13, peak[29], 0),
    AudioConnection(tdmIn2, 14, peak[30], 0), AudioConnection(tdmIn2, 15, peak[31], 0)};

  bool serverRunning = false;
  static float volumeValue[CHANNEL_COUNT];

  static void update(void* parameter);
};

#endif