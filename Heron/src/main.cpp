/******************************************************************************
* file    main.cpp
*******************************************************************************
* brief   Main application
*******************************************************************************
* author  Florian Baumgartner
* version 1.0
* date    2023-12-26
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

#include <Arduino.h>
#include <EthernetUtils.h>
#include <app.h>
#include <audioUtils.h>
#include <console.h>
#include <gnss.h>
#include <gui.h>
#include <hmi.h>
#include <preferences.h>
#include <sensors.h>
#include <utils.h>


#define TFT_SCLK   13
#define TFT_MOSI   11
#define TFT_CS     10
#define TFT_DC     30
#define TFT_BL     29
#define TCH_IRQ    28
#define RGB_LED    35
#define SCL_HMI    16
#define SDA_HMI    17
#define SCL_SYS    19
#define SDA_SYS    18
#define SCL_GPS    24
#define SDA_GPS    25
#define HMI_BUZZER 36
#define GPS_RST    31
#define LINK_LED   41


static AudioUtils audio;
static EthernetUtils ethernet(LINK_LED);
static Utils utils(SCL_SYS, SDA_SYS, SCL_HMI, SDA_HMI, SCL_GPS, SDA_GPS);
static Gui gui(TFT_SCLK, TFT_MOSI, TFT_CS, TFT_DC, TFT_BL, TCH_IRQ);
static Hmi hmi(RGB_LED, HMI_BUZZER);
static Gnss gnss(GPS_RST);
static Sensors sensors;
static App app;


void setup()
{
  console.begin();
  utils.begin();
  audio.begin();
  gnss.begin(utils);
  hmi.begin(utils);
  sensors.begin(utils);
  ethernet.begin(utils, audio);
  gui.begin(utils, hmi, audio, ethernet, sensors);
  hmi.setSystemStatus(Hmi::STATUS_OK);
  app.begin(audio, utils, gui, hmi, ethernet, gnss, sensors);
  hmi.buzzer.playMelody(MELODIE_POWER_ON);
  // TODO: Add watchdog
}

void loop()
{
  threads.yield();
  sensors.update();
  gnss.update();
  gui.update();
  ethernet.update();


  // static uint32_t gnssT = 0;
  // if(millis() - gnssT > 1000)
  // {
  //   gnssT = millis();
  //   console.log.printf("[GNSS] Lat: %f, Lon: %f, Alt: %f, MagDec: %f, Sats: %d, Fix: %d, FixType: %d\n", gnss.getLatitude(), gnss.getLongitude(),
  //                      gnss.getAltitude(), gnss.getMagneticDeclination(), gnss.getSateliteCount(), gnss.getFix(), gnss.getFixType());
  // }


  static uint32_t t = 0;
  if(millis() - t > 1000)
  {
    t = millis();
    // console.log.printf("[MAIN] Time: %d\n", t);
    // console.log.printf("[MAIN] Temperture: %.1f, Pressure: %.1f\n", sensors.getTemperature(), sensors.getPressure());
    // console.log.printf("[MAIN] AS5600: %.1f, detected: %d, tooWeek: %d, tooStrong: %d\n", sensors.getAngle(), sensors.isMagnetDetected(), sensors.isMagnetTooWeak(), sensors.isMagnetTooStrong());
  }
}