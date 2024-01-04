/******************************************************************************
* file    hmi.h
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

#ifndef HMI_H
#define HMI_H

#include <Arduino.h>
#include <RTClib.h>
#include <WS2812Serial.h>
#include <buzzer.h>
#include <melodies.h>
#include <utils.h>

#define RTC_WIRE Wire1    // Wire interface to use

class Hmi
{
 public:
  static constexpr const uint32_t LED_COUNT = 81;
  static constexpr const uint32_t AUDIO_CHANNEL_COUNT = 32;
  static constexpr const float UPDATE_RATE = 30.0;       // Hz
  static constexpr const float RTC_UPDATE_RATE = 5.0;    // Hz
  static constexpr const int8_t UTC_TIME_OFFSET = 1;     // UTC+1

  typedef enum
  {
    STATUS_BOOTUP,
    STATUS_OK,
    STATUS_WARNING,
    STATUS_ERROR
  } systemStatus_t;

  constexpr Hmi(int rgbLed, int buzzer) : rgbLedPin(rgbLed), buzzerPin(buzzer) {}
  bool begin(Utils& utilsRef);
  void setSystemStatus(systemStatus_t status) { systemStatus = status; }
  void setTimeDate(uint16_t year, uint8_t month, uint8_t day, uint8_t hour, uint8_t minute, uint8_t second);
  void getTimeDate(uint16_t& year, uint8_t& month, uint8_t& day, uint8_t& hour, uint8_t& minute, uint8_t& second)
  {
    year = this->year;
    month = this->month;
    day = this->day;
    hour = this->hour;
    minute = this->min;
    second = this->sec;
  }
  void getTime(uint8_t& hour, uint8_t& minute, uint8_t& second)
  {
    hour = this->hour;
    minute = this->min;
    second = this->sec;
  }
  void getDate(uint16_t& year, uint8_t& month, uint8_t& day)
  {
    year = this->year;
    month = this->month;
    day = this->day;
  }
  static uint32_t getTimeUtc(void) { return (uint32_t)(getTimeNanoUtc() / 1000000000ULL); }
  static uint64_t getTimeNanoUtc(void);
  static uint32_t Color(uint8_t r, uint8_t g, uint8_t b, uint8_t w = 0) { return ((uint32_t)w << 24) | ((uint32_t)r << 16) | ((uint32_t)g << 8) | b; }
  static uint8_t calculateWeekDay(uint16_t year, uint8_t month, uint8_t day);
  static bool isDaylightSavingTime(uint16_t year, uint8_t month, uint8_t day, uint8_t hour);
  static bool isLeapYear(uint16_t year) { return (year % 4 == 0) && (year % 100 != 0 || year % 400 == 0); }
  static void convertUtcToLocalTime(uint16_t& year, uint8_t& month, uint8_t& day, uint8_t& hour, uint8_t& minute, uint8_t& second,
                                    int8_t utcOffsetHour);

  const int rgbLedPin, buzzerPin;
  Buzzer buzzer = Buzzer(buzzerPin);

 private:
  static uint8_t drawingMemory[LED_COUNT * 3];            //  3 bytes per LED
  DMAMEM static uint8_t displayMemory[LED_COUNT * 12];    // 12 bytes per LED
  WS2812Serial leds = WS2812Serial(LED_COUNT, displayMemory, drawingMemory, rgbLedPin, WS2812_GRB);
  RTC_PCF8563 rtc;

  uint16_t year = 0;
  uint8_t month = 0;
  uint8_t day = 0;
  uint8_t hour = 0;
  uint8_t min = 0;
  uint8_t sec = 0;

  static uint64_t timeNanoUtc;    // Guido van Rossum's "nanoseconds since 1970
  static uint64_t timeNanoSync;
  static uint32_t tUpdateMicros;

  Utils* utils = nullptr;
  systemStatus_t systemStatus = STATUS_BOOTUP;
  volatile bool initialized = false;

  static void update(void* parameter);
};

#endif