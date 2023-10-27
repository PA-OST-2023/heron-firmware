/******************************************************************************
* file    utils.cpp
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

#include "utils.h"
#include <console.h>
#include <TeensyThreads.h>
#include "SdCard/SdioTeensy.cpp"


Utils::Utils()
{
}

bool Utils::begin(const char* storageName)
{
  bool res = true;
  MTP.begin();
  if(SD.begin(BUILTIN_SDCARD))
  {
    MTP.addFilesystem(SD, storageName);
    console.ok.println("[UTILS] SD Card initialized");
  }
  else
  {
    console.warning.println("[UTILS] No SD Card");
    res = false;
  }
  
  setSdclk(100000);
  console.log.printf("[UTILS] Set SDDIO Frequency to %d kHz\n", ((SdioCard*)SD.sdfs.card())->kHzSdClk());
  // threads.addThread(update, this, 1024);
  return res;
}

void Utils::update(void)
{
  MTP.loop();
  // while(true)
  // {
  //   // MTP.loop();
  //   threads.delay(5);
  // }
}
