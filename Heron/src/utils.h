/******************************************************************************
* file    utils.h
*******************************************************************************
* brief   Utility functions like USB (Mass Storage, Serial, etc.), SD Card
*******************************************************************************
* author  Florian Baumgartner
* version 1.0
* date    2023-10-26
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

#ifndef UTILS_H
#define UTILS_H

#include <Arduino.h>
#include <TeensyThreads.h>
#include <Watchdog_t4.h>
#include <console.h>
#include <i2c_driver.h>
#include <i2c_driver_wire.h>
#include <imx_rt1060_i2c_driver.h>
#include <preferences.h>
#include <rtclib.h>

extern unsigned long _heap_start;
extern unsigned long _heap_end;
extern char* __brkval;

class Utils
{
 public:
  static constexpr const float UPDATE_RATE = 10.0;    // Hz
  static constexpr const uint32_t EEPROM_ADDR_CHANNEL_ENABLED = 0;
  static constexpr const uint32_t EEPROM_ADDR_CHANNEL_NUMBER = 4;
  static constexpr const size_t SYS_WIRE_FREQENCY = 100000;    // [Hz] Max: (ADAU1718 = 1000kHz, AS5600 = 1000kHz, BMP388 = 3400kHz, LSM303 = 3400kHz)
  static constexpr const size_t HMI_WIRE_FREQENCY = 400000;    // [Hz] Max: (RTC = 400kHz, Touch = Unknown)
  static constexpr const size_t GPS_WIRE_FREQENCY = 400000;    // [Hz] Max: (GPS = 400kHz)
  static constexpr const size_t OP_TIME_UPDATE_INTERVAL = 60;    // [s]
  static constexpr const size_t WATCHDOG_TIMEOUT = 10;           // [s]

  static const char* WIRE_NAMES[];

  typedef enum
  {
    USB_DISCONNECTED,
    USB_CONNECTED,
    USB_ACTIVE
  } UsbStatus_t;

  Utils() {}
  bool begin(void);
  static void feedWatchdog(void) { wdt.feed(); }

  UsbStatus_t getUsbStatus(void) { return !usbConnected() ? USB_DISCONNECTED : console ? USB_ACTIVE : USB_CONNECTED; }
  uint32_t getOperationTime(void) { return operationTime; }

  static bool turnOnWire(I2CDriverWire& wire, bool busReset = true);
  static bool turnOffWire(I2CDriverWire& wire);
  static int scanWire(I2CDriverWire& wire);
  static int lockWire(I2CDriverWire& wire, int timeout = 0);
  static int unlockWire(I2CDriverWire& wire);
  static void setWireIdleCallback(void (*callback)())    // Don't enable idle callback for HMI I2C-Bus as it is used in a threaded cotext
  {
    sysWire.setHousekeepingCallback(callback);
    gpsWire.setHousekeepingCallback(callback);
  }

  static float getCpuTemperature(void);
  static int getCpuFrequency(void) { return F_CPU; }
  static const char* getBuildDate(void)
  {
    DateTime date = DateTime(F(__DATE__), F(__TIME__));
    static char buffer[9];
    snprintf(buffer, sizeof(buffer), "%02d%02d%02d", date.year() % 100, date.month(), date.day());
    return buffer;
  }
  static uint32_t getFreeRam() { return (char*)&_heap_end - __brkval; }

  WDT_timings_t wdtConfig = {.trigger = WATCHDOG_TIMEOUT, .timeout = WATCHDOG_TIMEOUT};
  Preferences preferences;

  static I2CDriverWire sysWire;
  static I2CDriverWire hmiWire;
  static I2CDriverWire gpsWire;

 private:
  static Threads::Mutex wireMutex[3];
  static WDT_T4<WDT1> wdt;

  volatile bool initialized = false;
  uint32_t operationTime = 0;

  static void update(void* parameter);
  static bool usbConnected(void) { return !bitRead(USB1_PORTSC1, 7); }
  static void busHardReset(I2CDriverWire& wire);
};

#endif