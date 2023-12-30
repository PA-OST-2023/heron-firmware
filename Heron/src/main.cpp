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
#include <EthernetUtils.h>
#include <audioUtils.h>
#include <console.h>
#include <gui.h>
#include <hmi.h>
#include <preferences.h>
#include <sensors.h>
#include <utils.h>

#include <ArduinoJson.h>


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
#define LINK_LED   41


static AudioUtils audio;
static Utils utils(SCL_SYS, SDA_SYS, SCL_HMI, SDA_HMI, SCL_GPS, SDA_GPS);
static Gui gui(TFT_SCLK, TFT_MOSI, TFT_CS, TFT_DC, TFT_BL, TCH_IRQ);
static Hmi hmi(RGB_LED, HMI_BUZZER);
static EthernetUtils ethernet(LINK_LED);
static Sensors sensors;


EthernetServer server;

void handleServer(void);
void sendJsonResponse(EthernetClient& client);
void receiveAndHandleJson(EthernetClient& client);

void setup()
{
  console.begin();
  console.log.println("[MAIN] Initialize System...");
  utils.begin();
  audio.begin();
  hmi.begin(utils);
  sensors.begin(utils);
  ethernet.begin(utils, audio);
  gui.begin(utils, hmi, audio, ethernet, sensors);
  hmi.setSystemStatus(Hmi::STATUS_OK);
  // hmi.buzzer.playMelody(MELODIE_POWER_ON);
  // TODO: Add watchdog

  const int port = 6667;
  if(!server.begin(port))
  {
    console.error.printf("[MAIN] Could not start server on port %d\n", port);
  }
  else
  {
    console.ok.printf("[MAIN] Server started on port %d\n", port);
  }
}

void loop()
{
  threads.yield();
  gui.update();
  utils.update();
  ethernet.update();

  handleServer();

  static uint32_t sensorT = 0;
  if(millis() - sensorT > 10)
  {
    sensorT = millis();
    sensors.update(&sensors);    // TODO: Remove and run in thread
  }

  static uint32_t t = 0;
  if(millis() - t > 1000)
  {
    t = millis();
    // console.log.printf("[MAIN] Time: %d\n", t);
    // console.log.printf("[MAIN] Heading: %.1f, Pitch: %.1f, Roll: %.1f\n", sensors.getHeading(), sensors.getPitch(), sensors.getRoll());
  }
}

void handleServer()
{
  EthernetClient client = server.available();

  // Do we have a client?
  if(!client)
    return;

  console.log.println(F("New client"));

  // Check if we have an incoming request
  if(client.available())
  {
    // Read the first line of the request
    String req = client.readStringUntil('\r');
    client.flush();

    // Determine the type of HTTP request
    if(req.indexOf("GET") != -1)
    {
      sendJsonResponse(client);
    }
    else if(req.indexOf("POST") != -1)
    {
      receiveAndHandleJson(client);
    }
  }

  // Disconnect
  client.stop();
}

void sendJsonResponse(EthernetClient& client)
{
  StaticJsonDocument<500> doc;

  // Add millis to json file
  doc["millis"] = millis();

  console.log.print(F("Sending: "));
  serializeJson(doc, console);
  console.log.println();

  // Write response headers
  client.println(F("HTTP/1.1 200 OK"));
  client.println(F("Content-Type: application/json"));
  client.println(F("Connection: close"));
  client.print(F("Content-Length: "));
  client.println(measureJsonPretty(doc));
  client.println();

  // Write JSON document
  serializeJsonPretty(doc, client);
}

void receiveAndHandleJson(EthernetClient& client) {
  // Read the complete HTTP header
  String header = "";
  while (client.available()) {
    char c = client.read();
    header += c;
    if (c == '\n' && header.endsWith("\r\n\r\n")) {
      break;
    }
  }

  // Find the Content-Length header
  int contentLength = 0;
  int index = header.indexOf("Content-Length: ");
  if (index != -1) {
    int start = index + 16; // Length of "Content-Length: "
    int end = header.indexOf("\r", start);
    contentLength = header.substring(start, end).toInt();
  }

  // Read the JSON data
  String json = "";
  while (json.length() < contentLength && client.available()) {
    json += (char)client.read();
  }

  // Deserialize the JSON document
  StaticJsonDocument<500> doc;
  DeserializationError error = deserializeJson(doc, json);

  if (error) {
    console.log.print(F("deserializeJson() failed: "));
    console.log.println(error.c_str());
    return;
  }

  // Handle the JSON document
  if (doc.containsKey("index")) {
    int index = doc["index"];
    console.log.print(F("Received index: "));
    console.log.println(index);
  }

  // Send a simple response
  client.println(F("HTTP/1.1 200 OK"));
  client.println(F("Content-Type: text/plain"));
  client.println(F("Connection: close"));
  client.println();
  client.println(F("JSON received"));
}
