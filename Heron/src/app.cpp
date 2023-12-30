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

    threads.delay(1000.0 / UPDATE_RATE);
  }
}
