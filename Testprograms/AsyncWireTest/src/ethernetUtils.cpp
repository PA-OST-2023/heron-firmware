/******************************************************************************
* file    ethernetUtils.cpp
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

DMAMEM StaticJsonDocument<EthernetUtils::DEVICE_DATA_JSON_SIZE> EthernetUtils::deviceDataJson;
DMAMEM StaticJsonDocument<EthernetUtils::COMMAND_JSON_SIZE> EthernetUtils::commandJson;

FLASHMEM bool EthernetUtils::begin(Utils& utilsRef, AudioUtils& audioUtilsRef)
{
  utils = &utilsRef;
  audioUtils = &audioUtilsRef;
  bool res = true;

  pinMode(linkLed, OUTPUT);
  digitalWrite(linkLed, LOW);

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

  if(!configServer.begin(ETHERNET_CONFIG_PORT))
  {
    console.error.printf("[ETHERNET] Could not start server on port %d\n", ETHERNET_CONFIG_PORT);
  }
  else
  {
    console.ok.printf("[ETHERNET] Server started on port %d\n", ETHERNET_CONFIG_PORT);
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

bool EthernetUtils::getLinkStatus(void)
{
  return Ethernet.linkStatus() == LinkON;
}

bool EthernetUtils::getStreamingConnectionStatus(void)
{
  return audioUtils->getConnectionStatus() && getLinkStatus();
}

bool EthernetUtils::getConfigurationConnectionStatus(void)
{
  if(!configClient || !getLinkStatus())
  {
    return false;
  }
  return configClient.connected();
}

bool EthernetUtils::getStreamingState(void)
{
  return audioUtils->getDataRateMBit() > 0;
}

void EthernetUtils::update(void)
{
  if(!initialized)
  {
    return;
  }
  Ethernet.loop();

  static uint32_t t = 0;
  if(millis() - t > (1000.0 / CONFIG_SERVER_UPDATE_RATE))
  {
    t = millis();
    handleConfigServer();
    digitalWrite(linkLed, getLinkStatus());
  }
}

void EthernetUtils::handleConfigServer(bool verbose)
{
  bool connected = false;
  if(!configClient)
  {                                             // If there's no existing client...
    configClient = configServer.available();    // Check for a new client
  }
  if(configClient && configClient.connected())
  {
    connected = true;
    if(configClient.available())    // Check if the client has sent any data
    {
      String req = configClient.readStringUntil('\r');    // Read the first line of the request
      configClient.flush();
      if(req.indexOf("GET") != -1)
      {
        if(!sendJsonResponse(configClient))
        {
          console.error.println("[ETHERNET] Failed to send JSON response");
        }
      }
      else if(req.indexOf("POST") != -1)
      {
        if(!receiveAndHandleJson(configClient))
        {
          console.error.println("[ETHERNET] Failed to receive and handle JSON");
        }
      }
    }
  }
  else if(configClient)    // If the client was previously connected but is now disconnected
  {
    configClient.stop();
    configClient = EthernetClient();    // Reset the global client object
  }

  static bool clientConnected = false;
  if((clientConnected != connected) && verbose)
  {
    console.log.printf("[ETHERNET] Configuration Client %s\n", clientConnected ? "connected" : "disconnected");
  }
  clientConnected = connected;
}

bool EthernetUtils::sendJsonResponse(EthernetClient& client, bool verbose)
{
  if(verbose)
  {
    console.log.println("[ETHERNET] Sending JSON response");
    serializeJson(deviceDataJson, console);
    console.log.println();
  }
  client.println(F("HTTP/1.1 200 OK"));
  client.println(F("Content-Type: application/json"));
  client.println(F("Connection: close"));
  client.print(F("Content-Length: "));
  client.println(measureJsonPretty(deviceDataJson));
  client.println();
  serializeJsonPretty(deviceDataJson, client);    // Write JSON document
  return true;
}

bool EthernetUtils::receiveAndHandleJson(EthernetClient& client)
{
  String header = "";    // Read the complete HTTP header
  while(client.available())
  {
    char c = client.read();
    header += c;
    if(c == '\n' && header.endsWith("\r\n\r\n"))
    {
      break;
    }
  }

  int contentLength = 0;
  int index = header.indexOf("Content-Length: ");
  if(index != -1)    // Find the Content-Length header
  {
    int start = index + 16;    // Length of "Content-Length: "
    int end = header.indexOf("\r", start);
    contentLength = header.substring(start, end).toInt();
  }

  String json = "";    // Allocate a buffer to store the HTTP body
  while(json.length() < contentLength && client.available())
  {
    json += (char)client.read();
  }
  DeserializationError error = deserializeJson(commandJson, json);    // Deserialize the JSON document
  if(error)
  {
    console.error.printf("[ETHERNET] deserializeJson() failed: %s\n", error.c_str());
    return false;
  }
  commandJsonReceived = true;

  client.println(F("HTTP/1.1 200 OK"));    // Send a simple response
  client.println(F("Content-Type: text/plain"));
  client.println(F("Connection: close"));
  client.println();
  client.println(F("JSON received"));
  return true;
}
