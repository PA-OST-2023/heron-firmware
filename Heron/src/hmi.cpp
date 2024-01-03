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
uint64_t Hmi::timeNanoUtc = 0;
uint32_t Hmi::tUpdateMicros = 0;

FLASHMEM bool Hmi::begin(Utils& utilsRef)
{
  utils = &utilsRef;
  bool res = true;

  leds.clear();
  leds.begin();
  leds.setBrightness(255);
  delay(5);    // Avoid flickering by waiting dor DMA to be ready
  leds.show();

  Utils::lockWire(RTC_WIRE);
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
  Utils::unlockWire(RTC_WIRE);

  if(!buzzer.begin())
  {
    console.error.println("[HMI] Buzzer could not be initialized");
    res = false;
  }

  initialized = true;
  threads.addThread(update, (void*)this, 4096);
  console.ok.println("[HMI] Initialized");

  return res;
}

void Hmi::setTimeDate(uint16_t year, uint8_t month, uint8_t day, uint8_t hour, uint8_t minute, uint8_t second)
{
  DateTime time = DateTime(year, month, day, hour, minute, second);
  Utils::lockWire(RTC_WIRE);
  rtc.adjust(time);
  Utils::unlockWire(RTC_WIRE);
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

    static uint32_t tRtc = 0;
    if(millis() - tRtc > (1000.0 / RTC_UPDATE_RATE))
    {
      static uint8_t secOld = 0;
      tRtc = millis();
      Utils::lockWire(RTC_WIRE);
      DateTime time = ref->rtc.now();
      Utils::unlockWire(RTC_WIRE);
      if(time.second() != secOld)
      {
        secOld = time.second();
        ref->tUpdateMicros = micros();
      }
      ref->year = time.year();
      ref->month = time.month();
      ref->day = time.day();
      ref->hour = time.hour();
      ref->min = time.minute();
      ref->sec = time.second();

      DateTimeFields utc = {.sec = ref->sec,
                            .min = ref->min,
                            .hour = ref->hour,
                            .mday = (uint8_t)((int8_t)ref->day - 1),
                            .mon = (uint8_t)((int8_t)ref->month - 1),
                            .year = (uint8_t)(ref->year - 1900)};
      ref->timeNanoUtc = (uint64_t)makeTime(utc) * 1000000000ULL + ref->tUpdateMicros % 1000000ULL;
    }

    threads.delay(1000.0 / UPDATE_RATE);
  }
}
