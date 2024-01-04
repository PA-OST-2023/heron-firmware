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
uint64_t Hmi::timeNanoSync = 0;
uint32_t Hmi::tUpdateMicros = 0;

volatile int64_t Hmi::lastRtcTime = 0;
volatile int64_t Hmi::lastMicros = 0;
volatile int64_t Hmi::phaseError = 0;

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
  this->year = year;
  this->month = month;
  this->day = day;
  this->hour = hour;
  this->min = minute;
  this->sec = second;
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
      tRtc = millis();
      Utils::lockWire(RTC_WIRE);
      DateTime time = ref->rtc.now();
      Utils::unlockWire(RTC_WIRE);
      lastMicros = (int64_t)micros();

      ref->year = time.year();
      ref->month = time.month();
      ref->day = time.day();
      ref->hour = time.hour();
      ref->min = time.minute();
      ref->sec = time.second();
      DateTimeFields utc = {.sec = ref->sec,
                            .min = ref->min,
                            .hour = ref->hour,
                            .mday = ref->day,
                            .mon = (uint8_t)((int8_t)ref->month - 1),
                            .year = (uint8_t)(ref->year - 1900)};
      lastRtcTime = (int64_t)makeTime(utc) * 1000000 + ref->timeAdjustment;
      // ref->timeNanoUtc = (uint64_t)makeTime(utc) * 1000000000ULL;
      ref->timeNanoUtc = (uint64_t)makeTime(utc) * 1000000000ULL;
    }
    ref->runPhaseLockedLoop();
    // console.log.printf("%02d.%06d\n", ref->sec, (micros() + (int32_t)ref->timeAdjustment) % 1000000);
    console.log.printf("%lld\n", ref->timeAdjustment);

    threads.delay(1000.0 / UPDATE_RATE);
  }
}

uint64_t Hmi::getTimeNanoUtc(void)    // Crude way to get monotomic time (adds up delay time)
{
  static uint64_t timeNanoUtcOld = -1;
  static uint64_t diff = -1;

  if(timeNanoUtcOld == -1)
  {
    timeNanoUtcOld = timeNanoUtc;
  }
  uint64_t t = timeNanoSync + (micros() - tUpdateMicros) * 1000ULL;
  if(timeNanoUtc == timeNanoUtcOld)
  {
    return t;
  }
  diff += t - timeNanoUtc;
  timeNanoUtcOld = timeNanoUtc;
  if(diff > (2 * 1000000000 / RTC_UPDATE_RATE))
  {
    diff = 0;
    timeNanoSync = timeNanoUtc;
    tUpdateMicros = micros();
    return timeNanoUtc;
  }
  return t;
}

uint8_t Hmi::calculateWeekDay(uint16_t year, uint8_t month, uint8_t day)
{
  if(month < 3)    // Check if Jan or Feb
  {
    month += 10;
    year -= 1;
  }
  else
  {
    month -= 2;
  }
  uint16_t iModYear = year % 100;
  uint16_t iDivYear = year / 100;
  uint16_t iResult = ((26 * month - 2) / 10 + day + iModYear + (iModYear / 4) + (iDivYear / 4) - 2 * iDivYear) % 7;    // Zellers Algorithm
  if(iResult == 0)
  {
    iResult = 7;
  }
  return iResult;    // 1 = Monday, 2 = Tuesday, ...
}

bool Hmi::isDaylightSavingTime(uint16_t year, uint8_t month, uint8_t day, uint8_t hour)
{
  if(month < 3 || month > 10)
    return false;    // No daylight saving time in Jan, Feb, Nov, Dec
  if(month > 3 && month < 10)
    return true;    // Daylight saving time in Apr, May, Jun, Jul, Aug, Sep
  if(((month == 3) && (hour + 24 * day) >= (1 + 24 * (31 - (5 * year / 4 + 4) % 7))) ||
     ((month == 10) && (hour + 24 * day) < (1 + 24 * (31 - (5 * year / 4 + 1) % 7))))
  {
    return true;
  }
  return false;
}

void Hmi::convertUtcToLocalTime(uint16_t& year, uint8_t& month, uint8_t& day, uint8_t& hour, uint8_t& minute, uint8_t& second, int8_t utcOffsetHour)
{
  int newHour = hour + utcOffsetHour;    // Adjust the hour with the UTC offset
  if(newHour >= 24)                      // Handle rolling over to the next or previous day
  {
    newHour -= 24;
    day += 1;
  }
  else if(newHour < 0)
  {
    newHour += 24;
    day -= 1;
  }
  hour = newHour;
  const int daysInMonth[] = {31, 28 + (isLeapYear(year) ? 1 : 0), 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};    // Handle month and year rollover
  if(day > daysInMonth[month - 1])                                                                            // Adjust month and day for rollover
  {
    day = 1;
    month += 1;
    if(month > 12)
    {
      month = 1;
      year += 1;
    }
  }
  else if(day < 1)
  {
    month -= 1;
    if(month < 1)
    {
      month = 12;
      year -= 1;
    }
    day = daysInMonth[month - 1];
  }
}

void Hmi::runPhaseLockedLoop(void)
{
  int64_t currentRtcTime = lastRtcTime;
  int64_t currentMicros = lastMicros;
  // uint32_t currentTime = micros();

  phaseError = currentRtcTime - currentMicros; // Convert RTC time to microseconds if needed

  // PI Controller
  integral += phaseError;
  timeAdjustment = Kp * phaseError + Ki * integral;

  // Adjust micros() - this is symbolic as you cannot directly change micros()
  // You might need to adjust a separate timekeeping variable instead
  // currentTime += timeAdjustment;
}