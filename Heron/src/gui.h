/******************************************************************************
* file    gui.h
*******************************************************************************
* brief   Wrapper for GUI interface (lvgl, touch, display, etc.)
*******************************************************************************
* author  Florian Baumgartner
* version 1.0
* date    2023-10-23
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

#ifndef GUI_H
#define GUI_H

#include <Adafruit_GFX.h>
#include <Arduino.h>
#include <CHSC6413.h>
#include <GC9A01A_t3n.h>
#include <SPI.h>
#include <console.h>
#include <lvgl.h>
#include <utils.h>
#include <ethernetUtils.h>

#include <audioUtils.h>
#include <sensors.h>
#include <gnss.h>
#include <hmi.h>


#define GUI_WIRE Wire1                                              // Wire interface to use

class Gui
{
 public:
  static constexpr const uint32_t SCREEN_WIDTH = 240;
  static constexpr const uint32_t SCREEN_HEIGHT = 240;
  static constexpr const uint32_t SCREEN_BUFFER_HEIGHT = 120;
  static constexpr const uint32_t AUDIO_CHANNEL_COUNT = 32;
  static constexpr const float DISPLAY_REFRESH_RATE = 24.0;         // Hz
  static constexpr const float WIDGET_UPDATE_RATE = 10.0;           // Hz
  static constexpr const size_t SPI_FREQUENCY = 60000000;           // [Hz] SPI clock

  Gui(int sclk, int mosi, int cs, int dc, int bl, int tch_irq);
  bool begin(Utils& utilsRef, Hmi& hmiRef, AudioUtils& audioUtilsRef, EthernetUtils& ethernetUtilsRef, Gnss& gnssRef, Sensors& sensorsRef);
  void update(void);
  bool isReady(void) { return initialized; }
  void setBrightness(int brightness) { analogWrite(bl, constrain(brightness, 0, 255)); }

  void setSystemWarning(const char* warning = nullptr);

  // Screen callback functions
  static void callbackScreenHomeShowWarning(void);

  static void callbackScreenEthernetSetupLoaded(void);
  static void callbackScreenEthernetSetupConfirmed(void);

  static void callbackScreenCompassCalibrationStart(void);
  static void callbackScreenCompassCalibrationAbort(void);

  static void callbackScreenArmAngleCalibration0(void);
  static void callbackScreenArmAngleCalibration90(void);
  static void callbackScreenArmAngleCalibrationStart(void);
  static void callbackScreenArmAngleCalibrationAbort(void);
  static void callbackScreenArmAngleCalibrationConfirmed(void);

 private:
  const int sclk, mosi, cs, dc, bl, tch_irq;
  GC9A01A_t3n disp = GC9A01A_t3n(cs, dc, -1, mosi, sclk);
  CHSC6413 touch = CHSC6413(&GUI_WIRE, tch_irq);

  static lv_color_t buf[SCREEN_WIDTH * SCREEN_BUFFER_HEIGHT];
  volatile bool initialized = false;

  // Warning
  char warningText[50];
  bool flagWarning = false;

  // Screen update functions
  bool updateScreenBootup(void);
  bool updateScreenHome(void);
  bool updateScreenSystem(void);
  bool updateScreenEthernet(void);
  bool updateScreenEthernetSetup(void);
  bool updateScreenGnss(void);
  bool updateScreenGnssLocation(void);
  bool updateScreenCompass(void);
  bool updateScreenCompassCalibrate(void);
  bool updateScreenArmAngle(void);
  bool updateScreenArmAngleCalibrate(void);
  bool updateScreenAmbient(void);

  // Helper functions
  static void screenArmAngleCalibrationCheckValid(bool angle0 = false, bool angle90 = false);

  static Utils* utils;
  static Hmi* hmi;
  static AudioUtils* audioUtils;
  static EthernetUtils* ethernetUtils;
  static Gnss* gnss;
  static Sensors* sensors;
  static void lvglPrint(const char* buf);
  static void dispflush(lv_disp_drv_t* dispDrv, const lv_area_t* area, lv_color_t* color_p);
  static void touchpadRead(lv_indev_drv_t* drv, lv_indev_data_t* data);
};

#endif