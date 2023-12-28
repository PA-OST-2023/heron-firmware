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
#include <audioUtils.h>
#include <console.h>
#include <gui.h>
#include <hmi.h>
#include <utils.h>

#include <QNEthernet.h>
using namespace qindesign::network;


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


static AudioUtils audio;
static Utils utils(SCL_SYS, SDA_SYS, SCL_HMI, SDA_HMI, SCL_GPS, SDA_GPS);
static Gui gui(TFT_SCLK, TFT_MOSI, TFT_CS, TFT_DC, TFT_BL, TCH_IRQ);
static Hmi hmi(RGB_LED, HMI_BUZZER);


void setup()
{
  console.begin();
  console.log.println("[MAIN] Initialize System...");

  if (CrashReport)
  {
    util::StdioPrint p{stdout};
    p.println();
    p.println(CrashReport);
    p.println();
    CrashReport.clear();
  }

  utils.begin();
  audio.begin();
  hmi.begin(utils);
  gui.begin(utils);

  IPAddress ip(192, 168, 40, 80);
  IPAddress subnet(255, 255, 255, 0);
  IPAddress gateway(192, 168, 40, 1);

  if(!Ethernet.begin(ip, subnet, gateway))
  {
    console.error.println("[MAIN] Failed to configure Ethernet using static IP");
  }
  if(!audio.startServer(6666))
  {
    console.error.println("[MAIN] Failed to start audio server");
  }
  else
  {
    console.ok.println("[MAIN] Audio server started");
  }

  hmi.setSystemStatus(Hmi::STATUS_OK);
}

void loop()
{
  threads.yield();
  gui.update();
  utils.update();
  Ethernet.loop();

  static uint32_t t = 0;
  if(millis() - t > 1000)
  {
    t = millis();
    console.log.printf("[MAIN] Time: %d\n", t);
  }
}
