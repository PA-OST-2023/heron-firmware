/******************************************************************************
* file    app.app
*******************************************************************************
* brief   Main application class, handles state machine
*******************************************************************************
* author  Florian Baumgartner
* version 1.0
* date    2023-10-31
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

#include "app.h"
#include <console.h>
#include <TeensyThreads.h>

App* App::ref = nullptr;

App::App(AudioUtils& audio, Hmi& hmi, Gui& gui, Utils& utils) : audio(audio), hmi(hmi), gui(gui), utils(utils)
{
  ref = this;
}

bool App::begin(void)
{  
  threads.addThread(update, (void*)this, 4096);
  console.ok.println("[APP] Initialized");
  return true;
}

void App::callbackUpdateTime(void)
{
  uint8_t day, month, hour, minute, second;
  uint16_t year;
  ref->gui.getTimeDate(year, month, day, hour, minute, second);
  ref->hmi.setTimeDate(year, month, day, hour, minute, second);
  console.log.printf("[APP] Updated RTC-Time: %02d.%02d.%04d %02d:%02d:%02d\n", day, month, year, hour, minute, second);
}

void App::callbackSetRollerTime(void)
{
  uint8_t day, month, hour, minute, second;
  uint16_t year;
  ref->hmi.getTimeDate(year, month, day, hour, minute, second);
  ref->gui.setTimeDate(year, month, day, hour, minute, second);
}

void App::update(void* parameter)
{
  App* app = (App*)parameter;
  while(true)
  {
    static uint32_t tRtc = 0;
    if(millis() - tRtc > 1000)
    {
      tRtc = millis();
      uint8_t hour, minute, second;
      app->hmi.getTime(hour, minute, second);
      app->gui.setTime(hour, minute);
    }

    static uint32_t tHmi = 0;
    if(millis() - tHmi > 100)
    {
      tHmi = millis();
      ref->gui.setVolume(ref->hmi.getVolume());
    }

    threads.delay(1000.0 / UPDATE_RATE);
  }
}
