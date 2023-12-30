/******************************************************************************
* file    preferences.h
*******************************************************************************
* brief   Enebles saving and loading of preferences in EEPROM
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

#include "preferences.h"
#include <console.h>

bool Preferences::begin(void)
{
  if(OSFS::checkLibVersion() != OSFS::result::NO_ERROR)
  {
    console.warning.println("[PREFERENCES] OSFS not formatted, formatting now...");
    OSFS::format();
    console.log.println("[PREFERENCES] OSFS formatted");
    return false;
  }

  console.ok.println("[PREFERENCES] OSFS initialized");
  return true;
}

void Preferences::format(void)
{
  OSFS::format();
  console.log.println("[PREFERENCES] OSFS formatted");
}

bool Preferences::isKey(const char* key)
{
  uint16_t add, size;
  return OSFS::getFileInfo(key, add, size) == OSFS::result::NO_ERROR;
}


// Data type get functions
int8_t Preferences::getChar(const char* key, int8_t defaultValue)
{
  int8_t value;
  if(OSFS::getFile(key, value) == OSFS::result::NO_ERROR)
    return value;
  return defaultValue;
}

uint8_t Preferences::getUChar(const char* key, uint8_t defaultValue)
{
  uint8_t value;
  if(OSFS::getFile(key, value) == OSFS::result::NO_ERROR)
    return value;
  return defaultValue;
}

int16_t Preferences::getShort(const char* key, int16_t defaultValue)
{
  int16_t value;
  if(OSFS::getFile(key, value) == OSFS::result::NO_ERROR)
    return value;
  return defaultValue;
}

uint16_t Preferences::getUShort(const char* key, uint16_t defaultValue)
{
  uint16_t value;
  if(OSFS::getFile(key, value) == OSFS::result::NO_ERROR)
    return value;
  return defaultValue;
}

int32_t Preferences::getInt(const char* key, int32_t defaultValue)
{
  int32_t value;
  if(OSFS::getFile(key, value) == OSFS::result::NO_ERROR)
    return value;
  return defaultValue;
}

uint32_t Preferences::getUInt(const char* key, uint32_t defaultValue)
{
  uint32_t value;
  if(OSFS::getFile(key, value) == OSFS::result::NO_ERROR)
    return value;
  return defaultValue;
}

int32_t Preferences::getLong(const char* key, int32_t defaultValue)
{
  int32_t value;
  if(OSFS::getFile(key, value) == OSFS::result::NO_ERROR)
    return value;
  return defaultValue;
}

uint32_t Preferences::getULong(const char* key, uint32_t defaultValue)
{
  uint32_t value;
  if(OSFS::getFile(key, value) == OSFS::result::NO_ERROR)
    return value;
  return defaultValue;
}

int64_t Preferences::getLong64(const char* key, int64_t defaultValue)
{
  int64_t value;
  if(OSFS::getFile(key, value) == OSFS::result::NO_ERROR)
    return value;
  return defaultValue;
}

uint64_t Preferences::getULong64(const char* key, uint64_t defaultValue)
{
  uint64_t value;
  if(OSFS::getFile(key, value) == OSFS::result::NO_ERROR)
    return value;
  return defaultValue;
}

float_t Preferences::getFloat(const char* key, float_t defaultValue)
{
  float_t value;
  if(OSFS::getFile(key, value) == OSFS::result::NO_ERROR)
    return value;
  return defaultValue;
}

double_t Preferences::getDouble(const char* key, double_t defaultValue)
{
  double_t value;
  if(OSFS::getFile(key, value) == OSFS::result::NO_ERROR)
    return value;
  return defaultValue;
}

bool Preferences::getBool(const char* key, bool defaultValue)
{
  bool value;
  if(OSFS::getFile(key, value) == OSFS::result::NO_ERROR)
    return value;
  return defaultValue;
}

// size_t Preferences::getString(const char* key, char* value, size_t maxLen)
// {
//   return OSFS::getFile(key, value, maxLen);
// }

String Preferences::getString(const char* key, String defaultValue)
{
  String value;
  if(OSFS::getFile(key, value) == OSFS::result::NO_ERROR)
    return value;
  return defaultValue;
}


// Internal OSFS class

uint16_t OSFS::startOfEEPROM = Preferences::EEPROM_START;
uint16_t OSFS::endOfEEPROM = Preferences::EEPROM_END;

void OSFS::readNBytes(uint16_t address, unsigned int num, byte* output)
{
  for(uint16_t i = address; i < address + num; i++)
  {
    *output = EEPROM.read(i);
    output++;
  }
}

void OSFS::writeNBytes(uint16_t address, unsigned int num, const byte* input)
{
  for(uint16_t i = address; i < address + num; i++)
  {
    EEPROM.update(i, *input);
    input++;
  }
}
