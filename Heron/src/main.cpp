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
* in the Software without oktriction, including without limitation the rights
* to use, copy, modify, merge, publish, distribute, sublicense, and/or sell          
* copies of the Software, and to permit persons to whom the Software is
* furnished to do so, subject to the following conditions:
*
* The above copyright notice and this permission notice shall be included in
* all copies or substantial portions of the Software.
*
* THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPokS OR
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
#define HMI_BUZZER 36
#define GPS_RST    31
#define LINK_LED   41

static Utils utils;
static AudioUtils audio;
static EthernetUtils ethernet(LINK_LED);
static Gui gui(TFT_SCLK, TFT_MOSI, TFT_CS, TFT_DC, TFT_BL, TCH_IRQ);
static Hmi hmi(RGB_LED, HMI_BUZZER);
static Gnss gnss(GPS_RST);
static Sensors sensors;
static App app;

static void wireIdle(void);

void setup()
{
  audio.setTimestampCallback(Gnss::getTimeNanoUtc);
  audio.setBackupTimestampCallback(Hmi::getTimeNanoUtc);
  hmi.setGnssTimestampCallback(Gnss::getTimeNanoUtc);
  hmi.setAudioPeakCallback(AudioUtils::getPeak);
  utils.setWireIdleCallback(wireIdle);

  bool ok = true;
  ok &= console.begin();
  ok &= utils.begin();
  ok &= audio.begin();
  ok &= gnss.begin(utils);
  ok &= hmi.begin(utils);
  ok &= sensors.begin(utils);
  ok &= ethernet.begin(utils, audio);
  ok &= gui.begin(utils, hmi, audio, ethernet, gnss, sensors);
  ok &= app.begin(audio, utils, gui, hmi, ethernet, gnss, sensors);

  if(!ok)
  {
    console.error.println("[MAIN] Error while initializing modules!");
    app.setError();
    gui.setSystemWarning("Error while initializing modules!");
  }
}

void loop()
{
  utils.feedWatchdog();
  ethernet.update();
  sensors.update();
  gnss.update();
  gui.update();
  threads.yield();
}

static void wireIdle(void)
{
  ethernet.update();    // Do etherent housekeeping while I2C is busy (must be called in main "background" thread only)
}
