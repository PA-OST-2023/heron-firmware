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
  gnss.setNavigationFrequency(5);                     // Set output to 5 times a second

  // gnss.enableDebugging(console, false);    // TODO: Remove

  initialized = true;
  // threads.addThread(update, this, 8192);
  return true;
}

void Gnss::end(void)
{
  initialized = false;
}

void Gnss::update(void* parameter)
{
  Gnss* ref = (Gnss*)parameter;

  // while(ref->initialized)
  {
    if(ref->gnss.getPVT())    // Check if new data is available
    {
      uint32_t t = millis();
      ref->latitude = ref->gnss.getLatitude() / 10000000.0;
      ref->longitude = ref->gnss.getLongitude() / 10000000.0;
      ref->altitude = ref->gnss.getAltitudeMSL() / 1000.0;
      ref->magneticDeclination = ref->gnss.getMagDec();
      ref->sateliteCount = ref->gnss.getSIV();
      ref->fix = ref->gnss.getGnssFixOk();
      ref->fixType = ref->gnss.getFixType();

      // console.log.printf("[GNSS] %d ms\n", millis() - t);
    }

    // threads.delay(1000.0 / UPDATE_RATE);
  }
}
