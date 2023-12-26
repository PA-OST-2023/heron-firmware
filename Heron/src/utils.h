/******************************************************************************
* file    utils.h
*******************************************************************************
* brief   Utility functions like USB (Mass Storage, Serial, etc.), SD Card
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

#ifndef UTILS_H
#define UTILS_H

#include <Arduino.h>
#include <EEPROM.h>
#include <MTP_Teensy.h>
#include <SD.h>
#include <TeensyThreads.h>
#include <Wire.h>

class Utils
{
 public:
  static constexpr const float UPDATE_RATE = 1.0;    // Hz

  static constexpr const uint32_t EEPROM_ADDR_CHANNEL_ENABLED = 0;
  static constexpr const uint32_t EEPROM_ADDR_CHANNEL_NUMBER = 4;

  Utils(int scl_sys, int sda_sys, int scl_hmi, int sda_hmi, int scl_gps, int sda_gps);
  bool begin(const char* storageName = "SD Card");
  void update(void);
  int scanWire(TwoWire& wire);
  int lockWire(TwoWire& wire, int timeout = 0);
  int unlockWire(TwoWire& wire);
  bool isSdCardPresent(void) { return sdCardPresent; }
  bool getSdCardError(void) { return sdCardError; }
  bool usbConnected(void) { return !bitRead(USB1_PORTSC1, 7); }
  float getSdCardTotalSizeMb(void) { return (float)sdCardTotalSize / 1048576.0; }
  float getSdCardUsedSizeMb(void) { return (float)sdCardUsedSize / 1048576.0; }
  int lockSdCardAccess(uint32_t timeout = 0) { return sdCardMutex.lock(timeout); }
  int tryLockSdCardAccess(void) { return sdCardMutex.try_lock(); }
  int unlockSdCardAccess(void) { return sdCardMutex.unlock(); }

  // bool storeChannelEnabled(const bool* channelEnabled, int count);
  // void loadChannelEnabled(bool* channelEnabled, int count);
  // bool storeChannelNumber(int channelNumber);
  // int loadChannelNumber(void);

 private:
  const int scl_sys, sda_sys, scl_hmi, sda_hmi, scl_gps, sda_gps;
  Threads::Mutex wireMutex[3];
  Threads::Mutex sdCardMutex;
  char storageName[50];
  bool sdCardScanAccess = true;
  bool sdCardPresent = false;
  bool sdCardError = false;
  uint64_t sdCardTotalSize = 0;
  uint64_t sdCardUsedSize = 0;
};

#endif
