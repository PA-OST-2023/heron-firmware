/******************************************************************************
* file    gnss.cpp
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

#include "gnss.h"
#include <TeensyThreads.h>
#include <console.h>

Gnss* Gnss::ref = nullptr;
uint64_t Gnss::timeNanoUtc = 0;
uint32_t Gnss::tUpdateMicros = 0;

bool Gnss::begin(Utils& utilsRef)
{
  utils = &utilsRef;
  pinMode(rstPin, OUTPUT);
  digitalWrite(rstPin, LOW);
  threads.delay(10);
  digitalWrite(rstPin, HIGH);
  threads.delay(200);

  if(!gnss.begin(Utils::gpsWire))
  {
    console.error.println("[GNSS] GNSS module not detected");
    return false;
  }
  else
  {
    console.ok.println("[GNSS] GNSS module initialized");
  }

  gnss.setI2COutput(COM_TYPE_UBX);                    // Set the I2C port to output UBX only (turn off NMEA noise)
  gnss.saveConfigSelective(VAL_CFG_SUBSEC_IOPORT);    // Save (only) the communications port settings to flash and BBR
  gnss.setNavigationFrequency(GNSS_UPDATE_RATE);      // Set output to n times a second
  // gnss.enableRTCMmessage(UBX_RTCM_1005, COM_PORT_I2C, 1);    // Enable message 1005 to output through I2C port, message every second
  // gnss.enableRTCMmessage(UBX_RTCM_1077, COM_PORT_I2C, 1);
  // gnss.enableRTCMmessage(UBX_RTCM_1087, COM_PORT_I2C, 1);
  // gnss.enableRTCMmessage(UBX_RTCM_1230, COM_PORT_I2C, 10);    // Enable message every 10 seconds

  gnss.setAutoPVTcallbackPtr(&callbackPVTdata);
  initialized = true;
  return true;
}

void Gnss::end(void)
{
  initialized = false;
}

void Gnss::update(void)
{
  if(!initialized)
  {
    return;
  }

  static uint32_t tUpdate = 0;
  if(millis() - tUpdate > (1000.0 / UPDATE_RATE))
  {
    tUpdate = millis();

    gnss.checkUblox();        // Check for the arrival of new data and process it.
    gnss.checkCallbacks();    // Check if any callbacks are waiting to be processed.
    if(millis() - tUpdate > I2C_PROCESSING_TIME_WARNING)
    {
      console.warning.printf("[GNSS] Possible I2C-Bus lockup (Time: %d ms)\n", millis() - tUpdate);
      utils->turnOffWire(Utils::gpsWire);
      delayMicroseconds(200);
      utils->turnOnWire(Utils::gpsWire);
    }
  }
}

uint64_t Gnss::getTimeNanoUtc(void)
{
  if(ref == nullptr)
  {
    return 0;
  }
  if(!ref->initialized || !ref->getFix() || !ref->timeValid)
  {
    return 0;
  }
  return ref->timeNanoUtc + ((int64_t)micros() - (int64_t)ref->tUpdateMicros) * 1000ULL;
}

void Gnss::callbackPVTdata(UBX_NAV_PVT_data_t* ubxDataStruct)
{
  if(ref == nullptr)
  {
    return;
  }
  ref->tUpdateMicros = micros();

  ref->latitude = ubxDataStruct->lat / 10000000.0;
  ref->longitude = ubxDataStruct->lon / 10000000.0;
  ref->altitude = ubxDataStruct->hMSL / 1000.0;
  ref->magneticDeclination = ubxDataStruct->magDec / 100.0;
  ref->sateliteCount = ubxDataStruct->numSV;
  ref->fixType = ubxDataStruct->fixType;
  ref->fix = ubxDataStruct->flags.bits.gnssFixOK;
  ref->timeValid = ubxDataStruct->valid.bits.fullyResolved;

  ref->year = ubxDataStruct->year;
  ref->month = ubxDataStruct->month;
  ref->day = ubxDataStruct->day;
  ref->hour = ubxDataStruct->hour;
  ref->min = ubxDataStruct->min;
  ref->sec = ubxDataStruct->sec;
  ref->nano = ubxDataStruct->nano;

  DateTimeFields utc = {.sec = ref->sec,
                        .min = ref->min,
                        .hour = ref->hour,
                        .mday = ref->day,
                        .mon = (uint8_t)((int8_t)ref->month - 1),
                        .year = (uint8_t)(ref->year - 1900)};
  ref->timeNanoUtc = (int64_t)makeTime(utc) * 1000000000ULL + (int64_t)ref->nano;
}
