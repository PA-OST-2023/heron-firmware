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
#include <sensors.h>
#include <utils.h>
#include <EthernetUtils.h>

#include <EEPROM.h>
#include <OSFS.h>


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
static Sensors sensors;
static EthernetUtils ethernet;


uint16_t OSFS::startOfEEPROM = 1;
uint16_t OSFS::endOfEEPROM = 4096;

void OSFS::readNBytes(uint16_t address, unsigned int num, byte* output)
{
  for(uint16_t i = address; i < address + num; i++)
  {
    *output = EEPROM.read(i);
    output++;
  }
}

// 4) How to I write to the medium?
void OSFS::writeNBytes(uint16_t address, unsigned int num, const byte* input)
{
  for(uint16_t i = address; i < address + num; i++)
  {
    EEPROM.update(i, *input);
    input++;
  }
}


void setup()
{
  console.begin();
  console.log.println("[MAIN] Initialize System...");
  utils.begin();
  audio.begin();
  hmi.begin(utils);
  sensors.begin(utils);
  ethernet.begin(utils, audio);
  gui.begin(utils, hmi, audio, sensors);

  if(OSFS::checkLibVersion() != OSFS::result::NO_ERROR)
  {
    console.warning.println("[MAIN] OSFS not formatted, formatting now...");
    OSFS::format();
    console.log.println("[MAIN] OSFS formatted");
  }
  else
  {
    console.ok.println("[MAIN] OSFS initialized");
  }


  int counter = 0;
  if(OSFS::getFile("counter", counter) != OSFS::result::NO_ERROR)
  {
    console.warning.println("[MAIN] Counter not found, creating now...");
    counter = 1;    // default to 1
    OSFS::newFile("counter", counter);
  }
  console.log.printf("Reboot count: %d\n", counter);
  counter++;
  OSFS::newFile("counter", counter, true);    // overwrite existing file

  // console.log.println(F("Storing a string"));
  // char testStr[15] = "this is a test";
  // OSFS::newFile("testStr", testStr, 15);

  // console.log.println(F("Storing a complex data type"));
  // struct complexType {
  // 	int a;
  // 	char b;
  // 	uint32_t c;
  // };

  // complexType testCplx;
  // testCplx.a = 123;
  // testCplx.b = 'a';
  // testCplx.c = 0xABCDEF00;
  // OSFS::newFile("testCplx", testCplx);

  hmi.setSystemStatus(Hmi::STATUS_OK);
}

void loop()
{
  threads.yield();
  gui.update();
  utils.update();
  ethernet.update();

  static uint32_t sensorT = 0;
  if(millis() - sensorT > 10)
  {
    sensorT = millis();
    sensors.update(&sensors);    // TODO: Remove and run in thread
  }

  static bool once = false;
  if(millis() > 10000 && !once)
  {
    once = true;
    ethernet.setIp(192, 168, 40, 80);
  }

  static uint32_t t = 0;
  if(millis() - t > 1000)
  {
    t = millis();
    // console.log.printf("[MAIN] Time: %d\n", t);
    // console.log.printf("[MAIN] Heading: %.1f, Pitch: %.1f, Roll: %.1f\n", sensors.getHeading(), sensors.getPitch(), sensors.getRoll());
  }
}
