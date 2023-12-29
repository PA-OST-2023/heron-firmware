/******************************************************************************
* file    utils.cpp
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

#include "utils.h"
#include <console.h>
#include <static_malloc.h>
#include "SdCard/SdioTeensy.cpp"

// EXTMEM uint8_t Utils::extHeap[Utils::EXT_HEAP_SIZE];

Utils::Utils(int scl_sys, int sda_sys, int scl_hmi, int sda_hmi, int scl_gps, int sda_gps)
    : scl_sys(scl_sys), sda_sys(sda_sys), scl_hmi(scl_hmi), sda_hmi(sda_hmi), scl_gps(scl_gps), sda_gps(sda_gps)
{
  // sm_set_default_pool(extHeap, EXT_HEAP_SIZE, false, nullptr);  // use a memory pool on the external ram
}

FLASHMEM bool Utils::begin(const char* storageName)
{
  bool res = true;
  mtpEnabled = storageName != nullptr;
  if(mtpEnabled)
  {
    MTP.begin();
  }
  if(SD.begin(BUILTIN_SDCARD))
  {
    sdCardPresent = true;
    if(mtpEnabled)
    {
      MTP.addFilesystem(SD, storageName);
      console.log.printf("[UTILS] MTP Storage: %s\n", storageName);
    }
    console.ok.println("[UTILS] SD Card initialized");
  }
  else
  {
    console.warning.println("[UTILS] No SD Card detected");
    res = false;
  }
  setSdclk(100000);
  console.log.printf("[UTILS] Set SDDIO Frequency to %d kHz\n", ((SdioCard*)SD.sdfs.card())->kHzSdClk());

  Wire.begin();
  Wire.setClock(400000);
  Wire.setSCL(scl_sys);
  Wire.setSDA(sda_sys);
  unlockWire(Wire);

  Wire1.begin();
  Wire1.setClock(1000000);
  Wire1.setSCL(scl_hmi);
  Wire1.setSDA(sda_hmi);
  unlockWire(Wire1);

  Wire2.begin();
  Wire2.setClock(1000000);
  Wire2.setSCL(scl_gps);
  Wire2.setSDA(sda_gps);
  unlockWire(Wire2);

  return res;
}

FLASHMEM int Utils::scanWire(TwoWire& wire)
{
  uint8_t error, address;
  int deviceCount = 0;

  console.log.println("[UTILS] Scanning I2C bus...");
  for(address = 1; address < 127; address++)
  {
    wire.beginTransmission(address);
    error = wire.endTransmission();
    if(error == 0)
    {
      console.log.printf("[UTILS] I2C device found at address 0x%02X\n", address);
      deviceCount++;
    }
    else if(error == 4)
    {
      console.warning.printf("[UTILS] Unknown error at address 0x%02X\n", address);
    }
  }
  if(deviceCount == 0)
  {
    console.error.printf("[UTILS] No I2C devices found\n");
  }
  else
  {
    console.log.printf("[UTILS] Scan complete (%d devices found)\n", deviceCount);
  }
  return deviceCount;
}

int Utils::lockWire(TwoWire& wire, int timeout)
{
  if(&wire == &Wire)
  {
    return wireMutex[0].lock(timeout);
  }
  else if(&wire == &Wire1)
  {
    return wireMutex[1].lock(timeout);
  }
  else if(&wire == &Wire2)
  {
    return wireMutex[2].lock(timeout);
  }
  else
  {
    return -1;
  }
}

int Utils::unlockWire(TwoWire& wire)
{
  if(&wire == &Wire)
  {
    return wireMutex[0].unlock();
  }
  else if(&wire == &Wire1)
  {
    return wireMutex[1].unlock();
  }
  else if(&wire == &Wire2)
  {
    return wireMutex[2].unlock();
  }
  else
  {
    return -1;
  }
}

void Utils::update(void)    // Make sure this function is non-blocking!
{
  if(mtpEnabled)
  {
    if(tryLockSdCardAccess())
    {
      MTP.loop();
      unlockSdCardAccess();
    }
  }

  static uint32_t t = 0;
  if(millis() - t > 1000 / UPDATE_RATE)
  {
    t = millis();
  }
}

// bool Utils::storeChannelEnabled(const bool* channelEnabled, int count)
// {
//   uint32_t channels = 0x00000000;
//   for(int i = 0; i < count; i++)
//   {
//     if(channelEnabled[i])
//     {
//       bitSet(channels, i);
//     }
//   }
//   console.log.printf("[UTILS] EEPROM Store channel enabled: 0x%08X\n", channels);
//   return EEPROM.put(EEPROM_ADDR_CHANNEL_ENABLED, channels) != 0;
// }

// void Utils::loadChannelEnabled(bool* channelEnabled, int count)
// {
//   uint32_t channels;
//   EEPROM.get(EEPROM_ADDR_CHANNEL_ENABLED, channels);
//   console.log.printf("[UTILS] EEPROM Load channel enabled: 0x%08X\n", channels);
//   for(int i = 0; i < count; i++)
//   {
//     channelEnabled[i] = bitRead(channels, i);
//   }
// }

// bool Utils::storeChannelNumber(int channelNumber)
// {
//   console.log.printf("[UTILS] EEPROM Store channel number: %d\n", channelNumber);
//   return EEPROM.put(EEPROM_ADDR_CHANNEL_NUMBER, channelNumber) != 0;
// }

// int Utils::loadChannelNumber(void)
// {
//   int channelNumber = 0;
//   EEPROM.get(EEPROM_ADDR_CHANNEL_NUMBER, channelNumber);
//   console.log.printf("[UTILS] EEPROM Load channel number: %d\n", channelNumber);
//   return channelNumber;
// }
