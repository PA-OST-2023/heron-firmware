/******************************************************************************
* file    utils.h
*******************************************************************************
* brief   Utility functions like USB (Mass Storage, Serial, etc.), SD Card
*******************************************************************************
* author  Florian Baumgartner
* version 1.0
* date    2023-10-26
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

#ifndef UTILS_H
#define UTILS_H

#include <Arduino.h>
#include <TeensyThreads.h>
#include <MTP_Teensy.h>
#include <Wire.h>
#include <SD.h>

class Utils
{
  public:
    Utils(int scl_sys, int sda_sys, int scl_hmi, int sda_hmi);
    bool begin(const char* storageName = "SD Card");
    void update(void);
    int scanWire(TwoWire& wire);
    int lockWire(TwoWire& wire, int timeout = 0);
    int unlockWire(TwoWire& wire);

  private:
    const int scl_sys, sda_sys, scl_hmi, sda_hmi;
    Threads::Mutex wireMutex[2];
};

#endif