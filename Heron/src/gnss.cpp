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

Gnss* Gnss::ref;

bool Gnss::begin(Utils& utilsRef)    // Don't mess with the Reset Pin, somehow it causes the GNSS module to not work anymore
{
  utils = &utilsRef;

  if(!gnss.begin(GPS_WIRE))
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
  gnss.setNavigationFrequency(2);                     // Set output to 2 times a second

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
    // if(gnss.getPVT())    // Check if new data is available
    // {
    //   latitude = gnss.getLatitude() / 10000000.0;
    //   longitude = gnss.getLongitude() / 10000000.0;
    //   altitude = gnss.getAltitudeMSL() / 1000.0;
    //   magneticDeclination = gnss.getMagDec();
    //   sateliteCount = gnss.getSIV();
    //   fix = gnss.getGnssFixOk();
    //   fixType = gnss.getFixType();

    //   console.log.printf("[GNSS] ExeTime: %dms, Lat: %.6f, Lon: %.6f, Alt: %.2fm, MagDec: %.2f, Sats: %d, Fix: %d, FixType: %d\n", millis() - tUpdate, latitude, longitude, altitude, magneticDeclination, sateliteCount, fix, fixType);
    // }

    gnss.checkUblox();        // Check for the arrival of new data and process it.
    gnss.checkCallbacks();    // Check if any callbacks are waiting to be processed.
    if(millis() - tUpdate > 50)
    {
      console.warning.printf("[GNSS] ExeTime: %d ms\n", millis() - tUpdate);
    }
  }
}

FLASHMEM void Gnss::callbackPVTdata(UBX_NAV_PVT_data_t* ubxDataStruct)
{
  console.log.print(F("[GNSS] Time: "));    // Print the time
  uint8_t hms = ubxDataStruct->hour;        // Print the hours
  if(hms < 10)
    console.log.print(F("0"));    // Print a leading zero if required
  console.log.print(hms);
  console.log.print(F(":"));
  hms = ubxDataStruct->min;    // Print the minutes
  if(hms < 10)
    console.log.print(F("0"));    // Print a leading zero if required
  console.log.print(hms);
  console.log.print(F(":"));
  hms = ubxDataStruct->sec;    // Print the seconds
  if(hms < 10)
    console.log.print(F("0"));    // Print a leading zero if required
  console.log.print(hms);
  console.log.print(F("."));
  unsigned long millisecs = ubxDataStruct->iTOW % 1000;    // Print the milliseconds
  if(millisecs < 100)
    console.log.print(F("0"));    // Print the trailing zeros correctly
  if(millisecs < 10)
    console.log.print(F("0"));
  console.log.print(millisecs);

  long latitude = ubxDataStruct->lat;    // Print the latitude
  console.log.print(F(" Lat: "));
  console.log.print(latitude);

  long longitude = ubxDataStruct->lon;    // Print the longitude
  console.log.print(F(" Long: "));
  console.log.print(longitude);
  console.log.print(F(" (degrees * 10^-7)"));

  long altitude = ubxDataStruct->hMSL;    // Print the height above mean sea level
  console.log.print(F(" Height above MSL: "));
  console.log.print(altitude);
  console.log.println(F(" (mm)"));
}
