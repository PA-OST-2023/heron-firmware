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
    channelEnabled[i] = true;
  }
}

bool Hmi::begin(void)
{
  pinMode(btnRec, INPUT_PULLUP);
  pinMode(btnSel, INPUT_PULLUP);
  pinMode(potVol, INPUT);
  volume = 1.0 - (analogRead(potVol) / 1023.0);

  leds.begin();
  leds.setBrightness(255);
  leds.clear();
  leds.show();

  initialized = true;
  threads.addThread(update, (void*)this, 4096);
  console.ok.println("[HMI] Initialized");
  return true;
}


void Hmi::update(void* parameter)
{
  Hmi* ref = (Hmi*)parameter;
  while(ref->initialized)
  {
    ref->volume = 0.5 * ref->volume + 0.5 * (1.0 - (analogRead(ref->potVol) / 1023.0));

    ref->leds.clear();
    for(int i = 0; i < AUDIO_CHANNEL_COUNT; i++)
    {
      if(ref->channelEnabled[i])
      {
        float volume = constrain((1.1 / (1 + pow(2.71828, -7 * (ref->ledVolume[i] - 0.5)))) - 0.05, 0.0, 1.0);     // Random function, copilot helped me with this (no, it was our math idea)
        uint8_t r = constrain((volume - 0.5) * 2.0, 0.0, 1.0) * 255;
        uint8_t g = (1.0 - fabs(1.0 - volume * 2.0)) * 255;
        int pos = (i * 2) + 3;
        if(i >= 16) pos--;
        ref->leds.setPixelColor(pos, Adafruit_NeoPixel::Color(r, g, 0));
      }
    }
    // ref->leds.setPixelColor()


    ref->leds.setPixelColor(1, (millis() % 1000) < 500 ? Adafruit_NeoPixel::Color(0, 255, 0) : Adafruit_NeoPixel::Color(0, 0, 0));
    ref->leds.show();

    threads.delay(1000.0 / UPDATE_RATE);
  }
}
