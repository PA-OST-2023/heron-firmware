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
#include "SdCard/SdioTeensy.cpp"

EXTMEM FileContainer Utils::fileContainer[Utils::MAX_FILE_COUNT];

Utils::Utils(int scl_sys, int sda_sys, int scl_hmi, int sda_hmi) : scl_sys(scl_sys), sda_sys(sda_sys), scl_hmi(scl_hmi), sda_hmi(sda_hmi)
{
  for(int i = 0; i < MAX_FILE_COUNT; i++)
  {
    fileContainer[i].fileName[0] = '\0';
    fileContainer[i].fileSize = 0;
    fileContainer[i].isDirectory = false;
    fileContainer[i].uniqueId = 0;
  }
}

bool Utils::begin(const char* storageName)
{
  bool res = true;
  MTP.begin();
  if(SD.begin(BUILTIN_SDCARD))
  {
    sdCardPresent = true;
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
  
  Wire.begin();
  Wire.setClock(400000);
  Wire.setSCL(scl_sys);
  Wire.setSDA(sda_sys);
  unlockWire(Wire);

  Wire1.begin();
  Wire1.setClock(400000);
  Wire1.setSCL(scl_hmi);
  Wire1.setSDA(sda_hmi);
  unlockWire(Wire1);

  return res;
}

int Utils::scanWire(TwoWire& wire)
{
  uint8_t error, address;
  int deviceCount = 0;

  console.log.println("[UTILS] Scanning I2C bus...");
  for (address = 1; address < 127; address++)
  {
    wire.beginTransmission(address);
    error = wire.endTransmission();
    if (error == 0)
    {
      console.log.printf("[UTILS] I2C device found at address 0x%02X\n", address);
      deviceCount++;
    }
    else if (error == 4)
    {
      console.warning.printf("[UTILS] Unknown error at address 0x%02X\n", address);
    }
  }
  if (deviceCount == 0)
  {
    console.error.printf("[UTILS] No I2C devices found\n");
  }
  else
  {
    console.log.printf("[UTILS] Scan complete (%d devices found)\n", deviceCount);
  }
  return deviceCount;
}

int Utils::lockWire(TwoWire& wire, int timeout)
{
  if(&wire == &Wire)
  {
    return wireMutex[0].lock(timeout);
  }
  else if(&wire == &Wire1)
  {
    return wireMutex[1].lock(timeout);
  }
  else
  {
    return -1;
  }
}

int Utils::unlockWire(TwoWire& wire)
{
  if(&wire == &Wire)
  {
    return wireMutex[0].unlock();
  }
  else if(&wire == &Wire1)
  {
    return wireMutex[1].unlock();
  }
  else
  {
    return -1;
  }
}

void Utils::update(void)     // Make sure this function is non-blocking!
{
  if(tryLockSdCardAccess())
  {
    MTP.loop();
    unlockSdCardAccess();
  }

  static uint32_t t = 0; 
  if(millis() - t > 1000 / UPDATE_RATE)
  {
    t = millis();
    if(tryLockSdCardAccess())
    {
      if(SD.mediaPresent())
      {
        if(!sdCardPresent)
        {
          sdCardPresent = true;
          console.log.println("[UTILS] SD Card inserted");
          if(!SD.begin(BUILTIN_SDCARD))
          {
            console.error.println("[UTILS] Failed to initialize SD Card");
          }
        }

        uint64_t totalSize = SD.totalSize();
        uint64_t usedSize = SD.usedSize();
        if(totalSize != sdCardTotalSize || usedSize != sdCardUsedSize)
        {
          sdCardTotalSize = totalSize;
          sdCardUsedSize = usedSize;
          console.log.printf("[UTILS] SD Card: %.2f MB total, %.2f MB used\n", getSdCardTotalSizeMb(), getSdCardUsedSizeMb());
        }
        fileCount = scanDirectory("/");   // Scan the root directory
      }
      else
      {
        if(sdCardPresent)
        {
          console.log.println("[UTILS] SD Card removed");
        }
        sdCardPresent = false;
        sdCardTotalSize = 0;
        sdCardUsedSize = 0;
        sdCardError = false;
      }
      unlockSdCardAccess();
    }
  }
}

int Utils::scanDirectory(const char* path, bool verbose)
{
  File root = SD.open(path);
  if(!root)
  {
    console.error.println("[UTILS] Failed to open directory");
    return 0;
  }
  if(!root.isDirectory())
  {
    console.error.println("[UTILS] Not a directory");
    root.close();
    return 0;
  }

  int count = getFileCount(path, true);
  if(verbose)
  {
    console.log.printf("[UTILS] Found %d files and directories in %s\n", count, path);
  }

  File entry = root.openNextFile();
  int index = 0;
  while(entry)
  {
    if(index >= count)
    {
      console.error.println("[UTILS] More entries than expected");
      break;
    }
    if(index > MAX_FILE_COUNT)
    {
      console.warning.printf("[UTILS] Too many entries (max %d)\n", MAX_FILE_COUNT);
      break;
    }
    strncpy(fileContainer[index].fileName, entry.name(), sizeof(fileContainer[index].fileName) - 1);      // Copy the file name
    fileContainer[index].fileName[sizeof(fileContainer[index].fileName) - 1] = '\0';                      // Ensure null termination
    fileContainer[index].fileSize = entry.size();                                                         // Set the file size
    fileContainer[index].isDirectory = entry.isDirectory();                                               // Set the directory flag
    fileContainer[index].uniqueId = generateUniqueId(fileContainer[index].fileName);                      // Generate a unique ID for the file
    if(verbose)
    {
      console.log.printf("[UTILS] Found %s: %s\n", fileContainer[index].isDirectory ? "directory" : "file", fileContainer[index].fileName);
    }
    index++;
    entry.close();
    entry = root.openNextFile();
  }

  root.close();
  if(index != count)
  {
    console.log.printf("[UTILS] Warning: Expected %d entries, but found %d entries.\n", count, index);
  }
  return index;     // Return the number of entries added to the files array
}

int Utils::getFileCount(const char* path, bool includeDirectories)
{
  File dir = SD.open(path);
  if(!dir)
  {
    console.error.println("[UTILS] Failed to open directory");
    return -1;
  }

  if(!dir.isDirectory())
  {
    console.error.println("[UTILS] Path is not a directory");
    dir.close();
    return -1;
  }

  int count = 0;
  File entry = dir.openNextFile();
  while(entry)
  {
    if (entry.isDirectory() && includeDirectories)
    {
      count++;
    }
    else if(!entry.isDirectory())
    {
      count++;
    }
    entry.close();      // Close the file to free up memory
    entry = dir.openNextFile();
  }

  dir.close();          // Make sure to close the directory to free up resources
  return count;
}

uint32_t Utils::generateUniqueId(const char* fileName)
{
  uint32_t hash = 5381;               // Starting value for djb2 algorithm
  int c;
  while((c = *fileName++))
  {
    hash = ((hash << 5) + hash) + c;  // hash * 33 + c
  }
  return hash;
}
