/******************************************************************************
* file    app.cpp
*******************************************************************************
* brief   Main application
*******************************************************************************
* author  Florian Baumgartner
* version 1.0
* date    2023-12-30
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

#include "app.h"
#include <TeensyThreads.h>
#include <console.h>


bool App::begin(AudioUtils& audio, Utils& utils, Gui& gui, Hmi& hmi, EthernetUtils& ethernet, Gnss& gnss, Sensors& sensors)
{
  this->utils = &utils;
  this->gui = &gui;
  this->hmi = &hmi;
  this->ethernet = &ethernet;
  this->gnss = &gnss;
  this->sensors = &sensors;

  initialized = true;
  threads.addThread(update, this, 4096);
  return true;
}

void App::end(void)
{
  initialized = false;
}

void App::update(void* parameter)
{
  App* ref = (App*)parameter;

  while(ref->initialized)
  {
    // Update device data
    ref->updateDeviceData(ref->ethernet->deviceData());    // Update device data
    if(ref->ethernet->commandJsonAvailable())              // Check if any commands have been received
    {
      if(!ref->handleIncommingCommands(ref->ethernet->commandData()))
      {
        console.error.println("[APP] Error while handling incomming commands");
      }
    }

    if((ref->warning || ref->error) && ref->gui->isSystemWarningCleared())    // Check if warnings are cleared
    {
      ref->error = false;
      ref->warning = false;
      ref->bootup = false;
    }

    // Check if there are any warnings
    if(ref->audio->getBufferOverflowDetected() && ref->audio->getConnectionStatus())
    {
      console.warning.println("[APP] Audio buffer overflow detected");
      ref->gui->setSystemWarning("Audio buffer overflow detected");
      ref->warning = true;
    }

    // Check if there are any errors
    // There are currently no runtime error

    if(ref->bootup && ref->gui->isBootupFinished() && !ref->error && !ref->warning)    // Check if bootup is finished
    {
      ref->bootup = false;
      ref->hmi->buzzer.playMelody(MELODIE_POWER_ON);
    }

    ref->hmi->setStreamingStatus(ref->audio->getConnectionStatus());    // Set Streaming Status in HMI to influece blink pattern

    // Set HMI LED Status based on warnings, errors and connection status and GNSS Fix
    static Hmi::systemStatus_t systemStatus = Hmi::systemStatus_t::STATUS_BOOTUP;
    Hmi::systemStatus_t status = Hmi::systemStatus_t::STATUS_GPS_NOFIX;
    if(ref->error)
    {
      status = Hmi::systemStatus_t::STATUS_ERROR;
    }
    else if(ref->warning)
    {
      status = Hmi::systemStatus_t::STATUS_WARNING;
    }
    else if(ref->bootup)
    {
      status = Hmi::systemStatus_t::STATUS_BOOTUP;
    }
    else if(ref->gnss->getFix() && ref->gnss->getTimeValid())
    {
      status = Hmi::systemStatus_t::STATUS_GPS_FIX;
    }

    if(status != systemStatus)
    {
      systemStatus = status;
      ref->hmi->setSystemStatus(systemStatus);
      switch(systemStatus)
      {
        case Hmi::systemStatus_t::STATUS_BOOTUP:
          console.log.println("[APP] System Status changed to \"Bootup\"");
          break;

        case Hmi::systemStatus_t::STATUS_GPS_NOFIX:
          console.log.println("[APP] System Status changed to \"GPS No Fix\"");
          break;

        case Hmi::systemStatus_t::STATUS_GPS_FIX:
          console.log.println("[APP] System Status changed to \"GPS Fix\"");
          break;

        case Hmi::systemStatus_t::STATUS_WARNING:
          ref->hmi->buzzer.playMelody(MELODIE_WARNING);
          console.log.println("[APP] System Status changed to \"Warning\"");
          break;

        case Hmi::systemStatus_t::STATUS_ERROR:
          ref->hmi->buzzer.playMelody(MELODIE_ERROR);
          console.log.println("[APP] System Status changed to \"Error\"");
          break;

        default:
          console.log.println("[APP] System Status changed to \"Unknown\"");
          break;
      }
    }

    static uint32_t gnssTimeOld = 0, rtcTimeOld = 0;
    if(ref->gnss->getFix() && ref->gnss->getTimeValid())    // Update RTC Time if GNSS is fix
    {
      uint32_t gnssTime = ref->gnss->getTimeUtc();
      uint32_t rtcTime = ref->hmi->getTimeUtc();
      int32_t timeDiff = gnssTime - rtcTime;
      if((abs(timeDiff) > 1) && (gnssTime != gnssTimeOld) && (rtcTime != rtcTimeOld))    // Update RTC Time if GNSS Time is different
      {
        gnssTimeOld = gnssTime;
        rtcTimeOld = rtcTime;
        DateTimeFields rtcTimeField, gnssTimeField;
        breakTime(rtcTime, rtcTimeField);
        breakTime(gnssTime, gnssTimeField);
        ref->hmi->setTimeDate(gnssTimeField.year + 1900, gnssTimeField.mon + 1, gnssTimeField.mday, gnssTimeField.hour, gnssTimeField.min,
                              gnssTimeField.sec);
        console.log.printf("[APP] Updated Time UTC+0: [RTC] %02d.%02d.%04d %02d:%02d:%02d [GNSS] %02d.%02d.%04d %02d:%02d:%02d [DIFF] %d\n",
                           rtcTimeField.mday, rtcTimeField.mon + 1, rtcTimeField.year + 1900, rtcTimeField.hour, rtcTimeField.min, rtcTimeField.sec,
                           gnssTimeField.mday, gnssTimeField.mon + 1, gnssTimeField.year + 1900, gnssTimeField.hour, gnssTimeField.min,
                           gnssTimeField.sec, timeDiff);
      }

      float gnssMagneticDeclination = ref->gnss->getMagneticDeclination();
      float sensorsMagneticDeclination = ref->sensors->getMagneticDeclination();
      if((gnssMagneticDeclination != sensorsMagneticDeclination) && (gnssMagneticDeclination != 0.0))
      {
        ref->sensors->setMagneticDeclination(gnssMagneticDeclination);
        console.log.printf("[APP] Updated magnetic declination: %.2f°\n", gnssMagneticDeclination);
      }
    }

    threads.delay(1000.0 / UPDATE_RATE);
  }
}

FLASHMEM void App::updateDeviceData(StaticJsonDocument<EthernetUtils::DEVICE_DATA_JSON_SIZE>& doc)
{
  static bool firstRun = true;

  // Device Data
  if(firstRun)
  {
    doc["device_firmware_version"] = FIRMWARE_VERSION;
    doc["device_firmware_build"] = utils->getBuildDate();
    doc["device_cpu_frequency"] = utils->getCpuFrequency();
  }
  doc["device_cpu_temperature"] = utils->getCpuTemperature();
  doc["device_operating_time"] = utils->getOperationTime();
  doc["device_system_warning"] = gui->getSystemWarning();

  // Ethernet Stats
  if(firstRun)
  {
    uint8_t mac[6];
    memcpy(mac, EthernetUtils::getMacAddress(), 6);
    char macStr[18];
    snprintf(macStr, sizeof(macStr), "%02X:%02X:%02X:%02X:%02X:%02X", mac[0], mac[1], mac[2], mac[3], mac[4], mac[5]);
    doc["ethernet_mac"] = macStr;
  }
  uint8_t ip_0, ip_1, ip_2, ip_3;
  ethernet->getIp(ip_0, ip_1, ip_2, ip_3);
  doc["ethernet_ip"] = String(ip_0) + "." + String(ip_1) + "." + String(ip_2) + "." + String(ip_3);

  // Audio Streaming Stats
  doc["streaming_state"] = ethernet->getStreamingState();
  doc["streaming_speed"] = audio->getDataRateMBit();
  doc["streaming_buffer"] = audio->getBufferFillLevelPercent();

  // Sensor Data
  doc["sensor_heading"] = sensors->getHeading();
  doc["sensor_pitch"] = sensors->getPitch();
  doc["sensor_roll"] = sensors->getRoll();
  doc["sensor_temperature"] = sensors->getTemperature();
  doc["sensor_pressure"] = sensors->getPressure();
  doc["sensor_altitude"] = sensors->getAltitude();
  doc["sensor_angle"] = sensors->getAngle();
  doc["sensor_magnet_detected"] = sensors->isMagnetDetected();
  doc["sensor_magnet_too_weak"] = sensors->isMagnetTooWeak();
  doc["sensor_magnet_too_strong"] = sensors->isMagnetTooStrong();

  // GNSS Data
  doc["gnss_latitude"] = gnss->getLatitude();
  doc["gnss_longitude"] = gnss->getLongitude();
  doc["gnss_altitude"] = gnss->getAltitude();
  doc["gnss_magnetic_declination"] = gnss->getMagneticDeclination();
  doc["gnss_satelite_count"] = gnss->getSateliteCount();
  doc["gnss_fix"] = gnss->getFix();
  doc["gnss_fix_type"] = (uint8_t)gnss->getFixType();
  doc["gnss_time_valid"] = gnss->getTimeValid();

  firstRun = false;
}

FLASHMEM bool App::handleIncommingCommands(StaticJsonDocument<EthernetUtils::COMMAND_JSON_SIZE>& doc)
{
  // if(doc.containsKey("index"))    // TODO: Replace with actual commands
  // {
  //   int index = doc["index"];
  //   console.log.printf("[APP] Received index: %d\n", index);
  // }

  if(doc.containsKey("clear_warning"))
  {
    console.log.println("[APP] Received command: clear_warning");
    warning = false;
  }
  // TODO: Handle RTK commands
  return true;
}
