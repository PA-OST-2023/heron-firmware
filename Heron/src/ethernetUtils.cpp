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

#include "ethernetUtils.h"
#include <console.h>


FLASHMEM bool EthernetUtils::begin(Utils& utilsRef, AudioUtils& audioUtilsRef)
{
  utils = &utilsRef;
  audioUtils = &audioUtilsRef;
  bool res = true;

  uint8_t ip_0 = utils->preferences.getUChar("ip_0", ip[0]);
  uint8_t ip_1 = utils->preferences.getUChar("ip_1", ip[1]);
  uint8_t ip_2 = utils->preferences.getUChar("ip_2", ip[2]);
  uint8_t ip_3 = utils->preferences.getUChar("ip_3", ip[3]);
  setIp(ip_0, ip_1, ip_2, ip_3, false);

  if(!Ethernet.begin(ip, subnet, gateway))
  {
    console.error.println("[ETHERNET] Failed to configure Ethernet using static IP");
  }
  if(!audioUtils->startServer(ETHERNET_STREAMING_PORT))
  {
    console.error.println("[ETHERNET] Failed to start audio server");
  }
  else
  {
    console.ok.println("[ETHERNET] Audio server started");
  }

  initialized = true;
  console.ok.println("[ETHERNET] Initialized");

  return res;
}

bool EthernetUtils::setIp(uint8_t ip_0, uint8_t ip_1, uint8_t ip_2, uint8_t ip_3, bool save)
{
  ip = IPAddress(ip_0, ip_1, ip_2, ip_3);
  gateway = IPAddress(ip_0, ip_1, ip_2, 1);
  console.log.printf("[ETHERNET] Setting IP to %d.%d.%d.%d\n", ip_0, ip_1, ip_2, ip_3);

  Ethernet.setLocalIP(ip);
  Ethernet.setGatewayIP(gateway);

  if(save)
  {
    bool res = true;
    res &= utils->preferences.putUChar("ip_0", ip_0);
    res &= utils->preferences.putUChar("ip_1", ip_1);
    res &= utils->preferences.putUChar("ip_2", ip_2);
    res &= utils->preferences.putUChar("ip_3", ip_3);
    if(!res)
    {
      console.error.println("[ETHERNET] Failed to save IP to preferences");
      return false;
    }
  }
  return true;
}
