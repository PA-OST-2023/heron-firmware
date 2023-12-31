/******************************************************************************
* file    gnss.h
*******************************************************************************
* brief   GNSS module (handles location and time)
*******************************************************************************
* author  Florian Baumgartner
* version 1.0
* date    2023-12-31
*******************************************************************************
* MIT License
*
* Copyright (c) 2022 Crelin - Florian Baumgartner
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

#ifndef GNSS_H
#define GNSS_H

#include <Arduino.h>
#include <SparkFun_u-blox_GNSS_Arduino_Library.h>
#include <utils.h>

class Gnss
{
 public:
  static constexpr const float UPDATE_RATE = 10.0;                   // Hz
  static constexpr const size_t GNSS_UPDATE_RATE = 5;                // Hz
  static constexpr const size_t I2C_PROCESSING_TIME_WARNING = 50;    // [ms] Time after which a warning is printed if I2C processing takes very long

  enum class fixType_t : uint8_t
  {
    NO_FIX = 0,
    DEAD_RECKONING_ONLY = 1,
    FIX_2D = 2,
    FIX_3D = 3,
    GNSS_AND_DEAD_RECKONING = 4,
    TIME_ONLY_FIX = 5
  };

  Gnss(int rst) : rstPin(rst) { ref = this; }
  bool begin(Utils& utilsRef);
  void end(void);
  float getLatitude(void) { return latitude; }
  float getLongitude(void) { return longitude; }
  float getAltitude(void) { return max(altitude, 0.0); }
  float getMagneticDeclination(void) { return magneticDeclination; }
  int getSateliteCount(void) { return sateliteCount; }
  bool getFix(void) { return fix; }
  fixType_t getFixType(void) { return (fixType_t)fixType; }
  bool getTimeValid(void) { return timeValid; }
  void getTimeDate(uint16_t& year, uint8_t& month, uint8_t& day, uint8_t& hour, uint8_t& minute, uint8_t& second)
  {
    DateTimeFields time;
    breakTime(getTimeUtc(), time);
    year = time.year + 1900;
    month = time.mon + 1;
    day = time.mday;
    hour = time.hour;
    minute = time.min;
    second = time.sec;
  }
  void getTime(uint8_t& hour, uint8_t& minute, uint8_t& second)
  {
    DateTimeFields time;
    breakTime(getTimeUtc(), time);
    hour = time.hour;
    minute = time.min;
    second = time.sec;
  }
  void getDate(uint16_t& year, uint8_t& month, uint8_t& day)
  {
    DateTimeFields time;
    breakTime(getTimeUtc(), time);
    year = time.year + 1900;
    month = time.mon + 1;
    day = time.mday;
  }
  static uint32_t getTimeUtc(void) { return (uint32_t)(getTimeNanoUtc() / 1000000000ULL); }
  static uint64_t getTimeNanoUtc(void);    // returns 0 if time is not valid
  void update(void);

 private:
  const int rstPin;
  Utils* utils = nullptr;
  static Gnss* ref;

  float latitude = 0.0;
  float longitude = 0.0;
  float altitude = 0.0;
  float magneticDeclination = 0.0;
  int sateliteCount = 0;
  bool fix = false;
  uint8_t fixType = 0;
  bool timeValid = false;

  uint16_t year;    // Year (UTC)
  uint8_t month;    // Month, range 1..12 (UTC)
  uint8_t day;      // Day of month, range 1..31 (UTC)
  uint8_t hour;     // Hour of day, range 0..23 (UTC)
  uint8_t min;      // Minute of hour, range 0..59 (UTC)
  uint8_t sec;      // Seconds of minute, range 0..60 (UTC)
  int32_t nano;     // Fraction of second in nanoseconds

  static uint64_t timeNanoUtc;    // Guido van Rossum's "nanoseconds since 1970
  static uint32_t tUpdateMicros;

  SFE_UBLOX_GNSS gnss;
  volatile bool initialized = false;

  static void callbackPVTdata(UBX_NAV_PVT_data_t* ubxDataStruct);
};

#endif