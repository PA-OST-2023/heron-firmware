/******************************************************************************
* file    app.h
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

#ifndef APP_H
#define APP_H

#include <Arduino.h>
#include <audioUtils.h>
#include <ethernetUtils.h>
#include <gnss.h>
#include <gui.h>
#include <hmi.h>
#include <sensors.h>
#include <utils.h>

class App
{
 public:
  static constexpr const float UPDATE_RATE = 10.0;    // Hz

  App() {}
  bool begin(AudioUtils& audio, Utils& utils, Gui& gui, Hmi& hmi, EthernetUtils& ethernet, Gnss& gnss, Sensors& sensors);
  void end(void);

 private:
  Utils* utils = nullptr;
  Gui* gui = nullptr;
  Hmi* hmi = nullptr;
  EthernetUtils* ethernet = nullptr;
  Gnss* gnss = nullptr;
  Sensors* sensors = nullptr;
  AudioUtils* audio = nullptr;

  volatile bool initialized = false;

  static void update(void* parameter);
};

#endif