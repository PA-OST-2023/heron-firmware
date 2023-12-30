/******************************************************************************
* file    ethernetUtils.h
*******************************************************************************
* brief   Ethernet class for handling streaming and configuration
*******************************************************************************
* author  Florian Baumgartner
* version 1.0
* date    2023-12-30
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

#ifndef ETHERNET_UTILS_H
#define ETHERNET_UTILS_H

#include <Arduino.h>
#include <QNEthernet.h>
#include <audioUtils.h>
#include <utils.h>

using namespace qindesign::network;

#define ETHERNET_DEFAULT_IP      192, 168, 40, 81    //80
#define ETHERNET_DEFAULT_GATEWAY 192, 168, 40, 1
#define ETHERNET_DEFAULT_SUBNET  255, 255, 255, 0
#define ETHERNET_STREAMING_PORT  6666

class EthernetUtils
{
 public:
  EthernetUtils() {}
  bool begin(Utils& utilsRef, AudioUtils& audioUtilsRef);
  bool setIp(uint8_t ip_0, uint8_t ip_1, uint8_t ip_2, uint8_t ip_3);

  inline void update(void)
  {
    if(initialized)
    {
      Ethernet.loop();
    }
  }

 private:
  Utils* utils = nullptr;
  AudioUtils* audioUtils = nullptr;

  IPAddress ip = IPAddress(ETHERNET_DEFAULT_IP);
  IPAddress gateway = IPAddress(ETHERNET_DEFAULT_GATEWAY);
  IPAddress subnet = IPAddress(ETHERNET_DEFAULT_SUBNET);

  volatile bool initialized = false;
};

#endif