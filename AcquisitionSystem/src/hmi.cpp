/******************************************************************************
* file    hmi.cpp
*******************************************************************************
* brief   HMI functions to handle LEDs, buttons, etc.
*******************************************************************************
* author  Florian Baumgartner
* version 1.0
* date    2023-10-29
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

#include "hmi.h"
#include <console.h>
#include <TeensyThreads.h>

Hmi::Hmi(int rgbLed, int btnRec, int btnSel, int potVol) : rgbLed(rgbLed), btnRec(btnRec), btnSel(btnSel), potVol(potVol)
{
  for(int i = 0; i < AUDIO_CHANNEL_COUNT; i++)
  {
    ledVolume[i] = 0.0;
  }
}

bool Hmi::begin(void)
{
  pinMode(btnRec, INPUT_PULLUP);
  pinMode(btnSel, INPUT_PULLUP);
  pinMode(potVol, INPUT);

  leds.begin();
  leds.setBrightness(255);
  leds.clear();
  leds.show();

  initialized = true;
  threads.addThread(update, (void*)this);
  console.ok.println("[HMI] Initialized");
  return true;
}


void Hmi::update(void* parameter)
{
  Hmi* ref = (Hmi*)parameter;
  while(ref->initialized)
  {
    ref->leds.setPixelColor(1, (millis() % 1000) < 500 ? Adafruit_NeoPixel::Color(0, 255, 0) : Adafruit_NeoPixel::Color(0, 0, 0));
    ref->leds.show();

    threads.delay(1000.0 / UPDATE_RATE);
  }
}
