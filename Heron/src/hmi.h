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

class Hmi
{
 public:
  static constexpr const uint32_t LED_COUNT = 81;
  static constexpr const uint32_t AUDIO_CHANNEL_COUNT = 32;
  static constexpr const float UPDATE_RATE = 30.0;       // Hz
  static constexpr const float RTC_UPDATE_RATE = 5.0;    // Hz
  static constexpr const int8_t UTC_TIME_OFFSET = 1;     // UTC+1
  static constexpr const double PLL_KP = 0.00;           // Proportional gain for PLL
  static constexpr const double PLL_KI = 0.01;           // Integral gain for PLL
  static constexpr const float LEDS_RAMP_TIME = 2.0;     // [s]
  static constexpr const float LEDS_OFF_TIME = 1.0;      // [s]
  static constexpr const uint8_t LEDS_MIN_BRIGHTNESS = 1;
  static constexpr const uint8_t LEDS_MAX_BRIGHTNESS = 255;


  typedef enum
  {
    STATUS_BOOTUP,
    STATUS_GPS_NOFIX,
    STATUS_GPS_FIX,
    STATUS_WARNING,
    STATUS_ERROR
  } systemStatus_t;

  typedef enum
  {
    MODE_AUDIO = 0,
    MODE_OST = 1
  } ledMode_t;

  constexpr Hmi(int rgbLedPin, int buzzerPin) : rgbLedPin(rgbLedPin), buzzer(Buzzer(buzzerPin)) {}
  bool begin(Utils& utilsRef);
  void setSystemStatus(systemStatus_t status) { systemStatus = status; }
  void setStreamingStatus(bool status) { streamingStatus = status; }
  void setGnssTimestampCallback(uint64_t (*callback)(void)) { getGnssTimestamp = callback; }
  void setAudioPeakCallback(float (*callback)(int channel)) { getAudioPeak = callback; }
  void setBuzzerEnabled(bool enabled);
  void setLedsEnabled(bool enabled);
  void setLedsBrightness(uint8_t brightness);
  void setLedsMode(ledMode_t mode);

  bool getBuzzerEnabled(void) { return buzzerEnabled; }
  bool getLedsEnabled(void) { return ledsEnabled; }
  uint8_t getLedsBrightness(void) { return ledsBrightness; }
  ledMode_t getLedsMode(void) { return ledsMode; }

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

  const int rgbLedPin;
  Buzzer buzzer;

 private:
  static uint8_t drawingMemory[LED_COUNT * 3];            //  3 bytes per LED
  DMAMEM static uint8_t displayMemory[LED_COUNT * 12];    // 12 bytes per LED
  WS2812Serial leds = WS2812Serial(LED_COUNT, displayMemory, drawingMemory, rgbLedPin, WS2812_GRB);
  RTC_PCF8563 rtc;

  bool buzzerEnabled = true;
  bool ledsEnabled = true;
  uint8_t ledsBrightness = 255;
  bool ledsBrightnessChanged = false;
  ledMode_t ledsMode = MODE_AUDIO;

  float brightnessModifier = 0.0;

  uint16_t year = 0;
  uint8_t month = 0;
  uint8_t day = 0;
  uint8_t hour = 0;
  uint8_t min = 0;
  uint8_t sec = 0;

  static uint64_t timeNanoUtc;    // Guido van Rossum's "nanoseconds since 1970
  static uint64_t timeNanoUtcInitial;
  static int64_t tineNanoUtcOffset;

  Utils* utils = nullptr;
  systemStatus_t systemStatus = STATUS_BOOTUP;
  bool streamingStatus = false;
  volatile bool rtcUpdatePending = false;
  volatile bool initialized = false;

  uint64_t (*getGnssTimestamp)(void) = nullptr;
  float (*getAudioPeak)(int channel) = nullptr;

  // LED Radius [mm]: 61.000, 135.639, 161.872, 208.113, 228.266, 269.257, 289.575, 330.393, 350.885
  const float RADIUS_DISTANCES[9] = {0.174, 0.387, 0.461, 0.593, 0.651, 0.767, 0.825, 0.942, 1.0};    // Normalized Radius

  static void update(void* parameter);
  void runPhaseLockedLoop(void);
  bool animationRampHandler(void);    // Return true if animation is finished and system is in normal operation
  void animationBootup(void);
  void animationAudio(void);
  void animationOst(bool blink = false);

  void setLedColorByRadius(int r, uint8_t red, uint8_t green, uint8_t blue);
};

#endif