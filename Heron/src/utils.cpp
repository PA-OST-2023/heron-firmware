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

Threads::Mutex Utils::wireMutex[3];
WDT_T4<WDT1> Utils::wdt;
I2CDriverWire Utils::sysWire(Master, Slave);      // SCL = 19, SDA = 18
I2CDriverWire Utils::hmiWire(Master1, Slave1);    // SCL = 16, SDA = 17
I2CDriverWire Utils::gpsWire(Master2, Slave2);    // SCL = 24, SDA = 25
const char* Utils::WIRE_NAMES[3] = {"SYS", "HMI", "GPS"};

FLASHMEM bool Utils::begin(void)
{
  bool res = true;
  console.log.printf("[UTILS] Starting watchdog (timeout: %ds)\n", WATCHDOG_TIMEOUT);
  wdt.begin(wdtConfig);
  wdt.feed();

  if(!preferences.begin())
  {
    console.error.println("[UTILS] Failed to initialize preferences");
    res = false;
  }
  operationTime = preferences.getLong("op_time");

  if(!turnOnWire(sysWire))
  {
    console.error.println("[UTILS] Failed to initialize Wire (SYS)");
    res = false;
  }
  if(!turnOnWire(hmiWire))
  {
    console.error.println("[UTILS] Failed to initialize Wire1 (HMI)");
    res = false;
  }
  if(!turnOnWire(gpsWire))
  {
    console.error.println("[UTILS] Failed to initialize Wire2 (GPS)");
    res = false;
  }

  unlockWire(sysWire);
  unlockWire(hmiWire);
  unlockWire(gpsWire);

  initialized = true;
  threads.addThread(update, this, 2048);
  return res;
}

bool Utils::turnOnWire(I2CDriverWire& wire, bool busReset)
{
  if(busReset)
  {
    busHardReset(wire);
  }
  if(&wire == &sysWire)
  {
    wire.begin();
    wire.setInternalPullups(InternalPullup::enabled_22k_ohm);
    wire.setTimeout(10);    // [ms]
    wire.setClock(SYS_WIRE_FREQENCY);
    return true;
  }
  else if(&wire == &hmiWire)
  {
    wire.begin();
    wire.setInternalPullups(InternalPullup::enabled_22k_ohm);
    wire.setTimeout(10);    // [ms]
    wire.setClock(HMI_WIRE_FREQENCY);
    return true;
  }
  else if(&wire == &gpsWire)
  {
    wire.begin();
    wire.setInternalPullups(InternalPullup::enabled_22k_ohm);
    wire.setTimeout(10);    // [ms]
    wire.setClock(GPS_WIRE_FREQENCY);
    return true;
  }
  return false;
}

bool Utils::turnOffWire(I2CDriverWire& wire)
{
  wire.end();
  return true;
}

FLASHMEM int Utils::scanWire(I2CDriverWire& wire)
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

int Utils::lockWire(I2CDriverWire& wire, int timeout)
{
  if(&wire == &sysWire)
  {
    return wireMutex[0].lock(timeout);
  }
  else if(&wire == &hmiWire)
  {
    return wireMutex[1].lock(timeout);
  }
  else if(&wire == &gpsWire)
  {
    return wireMutex[2].lock(timeout);
  }
  else
  {
    return -1;
  }
}

int Utils::unlockWire(I2CDriverWire& wire)
{
  if(&wire == &sysWire)
  {
    return wireMutex[0].unlock();
  }
  else if(&wire == &hmiWire)
  {
    return wireMutex[1].unlock();
  }
  else if(&wire == &gpsWire)
  {
    return wireMutex[2].unlock();
  }
  else
  {
    return -1;
  }
}

void Utils::busHardReset(I2CDriverWire& wire)
{
  // int scl = wire.getScl();
  // int sda = wire.getSda();
  // console.log.printf("[UTILS] Hard reset I2C bus %s (SCL: %d, SDA: %d)\n", WIRE_NAMES[wire.getBusId()], scl, sda);
  // pinMode(scl, OUTPUT);
  // pinMode(sda, OUTPUT);
  // digitalWrite(scl, HIGH);
  // digitalWrite(sda, HIGH);
  // delayMicroseconds(500);
  // digitalWrite(scl, LOW);
  // digitalWrite(sda, LOW);
  // delayMicroseconds(500);
  // digitalWrite(scl, HIGH);
  // digitalWrite(sda, HIGH);
  // delayMicroseconds(100);
}

float Utils::getCpuTemperature(void)
{
  static const float FILTER_COEFFICIENT = 0.01;
  static float temp = NAN;
  if(isnan(temp))
  {
    temp = tempmonGetTemp();
  }
  else
  {
    temp = temp * (1.0 - FILTER_COEFFICIENT) + tempmonGetTemp() * FILTER_COEFFICIENT;
  }
  return temp;
}

void Utils::update(void* parameter)
{
  Utils* ref = (Utils*)parameter;
  while(ref->initialized)
  {
    static uint32_t tOpTime = millis();
    if(millis() - tOpTime > OP_TIME_UPDATE_INTERVAL * 1000)
    {
      tOpTime = millis();
      ref->operationTime = ref->preferences.getLong("op_time", 0) + OP_TIME_UPDATE_INTERVAL;
      ref->preferences.putLong("op_time", ref->operationTime);
    }

    threads.delay(1000.0 / UPDATE_RATE);
  }
}
