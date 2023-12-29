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
#include <utils.h>

#define RTC_WIRE Wire1                                              // Wire interface to use

class Hmi
{
 public:
  static constexpr const uint32_t LED_COUNT = 81;
  static constexpr const uint32_t AUDIO_CHANNEL_COUNT = 32;
  static constexpr const float UPDATE_RATE = 30.0;    // Hz

  typedef enum
  {
    STATUS_BOOTUP,
    STATUS_OK,
    STATUS_WARNING,
    STATUS_ERROR
  } systemStatus_t;

  constexpr Hmi(int rgbLed, int buzzer) : rgbLed(rgbLed), buzzer(buzzer) {}
  bool begin(Utils& utilsRef);
  void setSystemStatus(systemStatus_t status) { systemStatus = status; }
  void setTimeDate(uint16_t year, uint8_t month, uint8_t day, uint8_t hour, uint8_t minute, uint8_t second);
  void getTimeDate(uint16_t& year, uint8_t& month, uint8_t& day, uint8_t& hour, uint8_t& minute, uint8_t& second);
  void getTime(uint8_t& hour, uint8_t& minute, uint8_t& second);
  void getDate(uint16_t& year, uint8_t& month, uint8_t& day);

  static uint32_t Color(uint8_t r, uint8_t g, uint8_t b, uint8_t w = 0) { return ((uint32_t)w << 24) | ((uint32_t)r << 16) | ((uint32_t)g << 8) | b; }

 private:
  const int rgbLed, buzzer;

  static uint8_t drawingMemory[LED_COUNT * 3];             //  3 bytes per LED
  DMAMEM static uint8_t displayMemory[LED_COUNT * 12];     // 12 bytes per LED
  WS2812Serial leds = WS2812Serial(LED_COUNT, displayMemory, drawingMemory, rgbLed, WS2812_GRB);
  RTC_PCF8563 rtc;

  Utils* utils = nullptr;
  systemStatus_t systemStatus = STATUS_BOOTUP;

  volatile bool initialized = false;

  static void update(void* parameter);
};

#endif