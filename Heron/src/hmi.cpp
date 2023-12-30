/******************************************************************************
* file    hmi.cpp
*******************************************************************************
* brief   HMI functions to handle LEDs, buttons, etc.
*******************************************************************************
* author  Florian Baumgartner
* version 1.0
* date    2023-10-29
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

#include "hmi.h"
#include <TeensyThreads.h>
#include <console.h>

DMAMEM uint8_t Hmi::drawingMemory[Hmi::LED_COUNT * 3] = {};
DMAMEM uint8_t Hmi::displayMemory[Hmi::LED_COUNT * 12] = {};

FLASHMEM bool Hmi::begin(Utils& utilsRef)
{
  utils = &utilsRef;
  bool res = true;

  leds.clear();
  leds.begin();
  leds.setBrightness(255);
  delay(5);    // Avoid flickering by waiting dor DMA to be ready
  leds.show();

  utils->lockWire(RTC_WIRE);
  if(!rtc.begin(&RTC_WIRE))
  {
    console.error.println("[HMI] RTC could not be initialized");
    res = false;
  }
  if(rtc.lostPower())
  {
    console.warning.println("[HMI] RTC is NOT initialized, let's set the time!");
    rtc.adjust(DateTime(F(__DATE__), F(__TIME__)));
  }
  rtc.start();
  utils->unlockWire(RTC_WIRE);


  initialized = true;
  threads.addThread(update, (void*)this, 4096);
  console.ok.println("[HMI] Initialized");

  return res;
}

void Hmi::setTimeDate(uint16_t year, uint8_t month, uint8_t day, uint8_t hour, uint8_t minute, uint8_t second)
{
  DateTime time = DateTime(year, month, day, hour, minute, second);
  utils->lockWire(RTC_WIRE);
  rtc.adjust(time);
  utils->unlockWire(RTC_WIRE);
}

void Hmi::getTimeDate(uint16_t& year, uint8_t& month, uint8_t& day, uint8_t& hour, uint8_t& minute, uint8_t& second)
{
  utils->lockWire(RTC_WIRE);
  DateTime time = rtc.now();
  utils->unlockWire(RTC_WIRE);
  year = time.year();
  month = time.month();
  day = time.day();
  hour = time.hour();
  minute = time.minute();
  second = time.second();
}

void Hmi::getTime(uint8_t& hour, uint8_t& minute, uint8_t& second)
{
  utils->lockWire(RTC_WIRE);
  DateTime time = rtc.now();
  utils->unlockWire(RTC_WIRE);
  hour = time.hour();
  minute = time.minute();
  second = time.second();
}

void Hmi::getDate(uint16_t& year, uint8_t& month, uint8_t& day)
{
  utils->lockWire(RTC_WIRE);
  DateTime time = rtc.now();
  utils->unlockWire(RTC_WIRE);
  year = time.year();
  month = time.month();
  day = time.day();
}

void Hmi::update(void* parameter)
{
  Hmi* ref = (Hmi*)parameter;
  while(ref->initialized)
  {

    ref->leds.clear();
    if(ref->systemStatus != STATUS_BOOTUP)
    {
      switch(ref->systemStatus)
      {
        case STATUS_OK:
          ref->leds.setPixelColor(0, (millis() % 1000) < 500 ? Color(0, 255, 0) : Color(0, 0, 0));
          break;
        case STATUS_WARNING:
          ref->leds.setPixelColor(0, (millis() % 1000) < 500 ? Color(255, 255, 0) : Color(0, 0, 0));
          break;
        case STATUS_ERROR:
          ref->leds.setPixelColor(0, (millis() % 1000) < 500 ? Color(255, 0, 0) : Color(0, 0, 0));
          break;
        default:
          break;
      }
    }
    else    // Bootup animation
    {}
    ref->leds.show();

    threads.delay(1000.0 / UPDATE_RATE);
  }
}
