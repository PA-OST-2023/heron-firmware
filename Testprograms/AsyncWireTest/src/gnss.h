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

#define GPS_WIRE Wire2    // Wire interface to use

class Gnss
{
 public:
  static constexpr const float UPDATE_RATE = 5.0;    // Hz

  Gnss(int rst) : rstPin(rst) {}
  bool begin(Utils& utilsRef);
  void end(void);
  float getLatitude(void) { return latitude; }
  float getLongitude(void) { return longitude; }
  float getAltitude(void) { return altitude; }
  float getMagneticDeclination(void) { return magneticDeclination; }
  int getSateliteCount(void) { return sateliteCount; }
  bool getFix(void) { return fix; }
  uint8_t getFixType(void) { return fixType; }

  static void update(void* parameter);

 private:
  const int rstPin;
  Utils* utils = nullptr;

  float latitude = 0.0;
  float longitude = 0.0;
  float altitude = 0.0;
  float magneticDeclination = 0.0;
  int sateliteCount = 0;
  bool fix = false;
  uint8_t fixType = 0;

  SFE_UBLOX_GNSS gnss;
  volatile bool initialized = false;

  // static void update(void* parameter);
};

#endif