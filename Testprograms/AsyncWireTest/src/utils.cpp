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

int Utils::scl_sys, Utils::sda_sys, Utils::scl_hmi, Utils::sda_hmi, Utils::scl_gps, Utils::sda_gps;
Threads::Mutex Utils::wireMutex[3];
// EXTMEM uint8_t Utils::extHeap[Utils::EXT_HEAP_SIZE];

Utils::Utils(int scl_sys, int sda_sys, int scl_hmi, int sda_hmi, int scl_gps, int sda_gps)
{
  Utils::scl_sys = scl_sys;
  Utils::sda_sys = sda_sys;
  Utils::scl_hmi = scl_hmi;
  Utils::sda_hmi = sda_hmi;
  Utils::scl_gps = scl_gps;
  Utils::sda_gps = sda_gps;
  // sm_set_default_pool(extHeap, EXT_HEAP_SIZE, false, nullptr);  // use a memory pool on the external ram
}

FLASHMEM bool Utils::begin(void)
{
  bool res = true;
  if(!preferences.begin())
  {
    console.error.println("[UTILS] Failed to initialize preferences");
    res = false;
  }

  if(!turnOnWire(Wire))
  {
    console.error.println("[UTILS] Failed to initialize Wire (SYS)");
    res = false;
  }
  if(!turnOnWire(Wire1))
  {
    console.error.println("[UTILS] Failed to initialize Wire1 (HMI)");
    res = false;
  }
  if(!turnOnWire(Wire2))
  {
    console.error.println("[UTILS] Failed to initialize Wire2 (GPS)");
    res = false;
  }

  unlockWire(Wire);
  unlockWire(Wire1);
  unlockWire(Wire2);

  return res;
}

bool Utils::turnOnWire(TwoWire& wire)
{
  if(&wire == &Wire)
  {
    Wire.begin();
    Wire.setClock(SYS_WIRE_FREQENCY);
    Wire.setSCL(scl_sys);
    Wire.setSDA(sda_sys);
    return true;
  }
  else if(&wire == &Wire1)
  {
    Wire1.begin();
    Wire1.setClock(HMI_WIRE_FREQENCY);
    Wire1.setSCL(scl_hmi);
    Wire1.setSDA(sda_hmi);
    return true;
  }
  else if(&wire == &Wire2)
  {
    Wire2.begin();
    Wire2.setClock(GPS_WIRE_FREQENCY);
    Wire2.setSCL(scl_gps);
    Wire2.setSDA(sda_gps);
    return true;
  }
  return false;
}

bool Utils::turnOffWire(TwoWire& wire)
{
  if(&wire == &Wire)
  {
    Wire.end();
    return true;
  }
  else if(&wire == &Wire1)
  {
    Wire1.end();
    return true;
  }
  else if(&wire == &Wire2)
  {
    Wire2.end();
    return true;
  }
  return false;
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
  static uint32_t t = 0;
  if(millis() - t > 1000 / UPDATE_RATE)
  {
    t = millis();

    if(usbConnected())
    {
      usbStatus = console ? USB_ACTIVE : USB_CONNECTED;
    }
    else
    {
      usbStatus = USB_DISCONNECTED;
    }
  }
}
