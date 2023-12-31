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
    ref->updateDeviceData(ref->ethernet->deviceData());    // Update device data
    if(ref->ethernet->commandJsonAvailable())              // Check if any commands have been received
    {
      if(!ref->handleIncommingCommands(ref->ethernet->commandData()))
      {
        console.error.println("[APP] Error while handling incomming commands");
      }
    }

    // TODO: Update RTC Time if GNSS is available

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
    doc["device_firmware_build"] = getBuildDate();
    doc["device_cpu_frequency"] = utils->getCpuFrequency();
  }
  doc["device_cpu_temperature"] = utils->getCpuTemperature();


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


  // Sensor Data
  doc["sensor_heading"] = sensors->getHeading();
  doc["sensor_pitch"] = sensors->getPitch();
  doc["sensor_roll"] = sensors->getRoll();
  // Temperature
  // Pressure
  // Angle

  // GNSS Data

  firstRun = false;
}

FLASHMEM bool App::handleIncommingCommands(StaticJsonDocument<EthernetUtils::COMMAND_JSON_SIZE>& doc)
{
  if(doc.containsKey("index"))    // TODO: Replace with actual commands
  {
    int index = doc["index"];
    console.log.printf("[APP] Received index: %d\n", index);
  }
  return true;
}