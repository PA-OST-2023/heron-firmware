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

#ifndef PREFERENCES_H
#define PREFERENCES_H

#include <Arduino.h>
#include <OSFS.h>

class Preferences
{
 public:
  static constexpr const size_t EEPROM_START = 0;
  static constexpr const size_t EEPROM_END = 4095;

  Preferences() {}
  bool begin(void);
  void format(void);
  bool isKey(const char* key);

  size_t putChar(const char* key, int8_t value) { return OSFS::newFile(key, value, true) == OSFS::result::NO_ERROR; }
  size_t putUChar(const char* key, uint8_t value) { return OSFS::newFile(key, value, true) == OSFS::result::NO_ERROR; }
  size_t putShort(const char* key, int16_t value) { return OSFS::newFile(key, value, true) == OSFS::result::NO_ERROR; }
  size_t putUShort(const char* key, uint16_t value) { return OSFS::newFile(key, value, true) == OSFS::result::NO_ERROR; }
  size_t putInt(const char* key, int32_t value) { return OSFS::newFile(key, value, true) == OSFS::result::NO_ERROR; }
  size_t putUInt(const char* key, uint32_t value) { return OSFS::newFile(key, value, true) == OSFS::result::NO_ERROR; }
  size_t putLong(const char* key, int32_t value) { return OSFS::newFile(key, value, true) == OSFS::result::NO_ERROR; }
  size_t putULong(const char* key, uint32_t value) { return OSFS::newFile(key, value, true) == OSFS::result::NO_ERROR; }
  size_t putLong64(const char* key, int64_t value) { return OSFS::newFile(key, value, true) == OSFS::result::NO_ERROR; }
  size_t putULong64(const char* key, uint64_t value) { return OSFS::newFile(key, value, true) == OSFS::result::NO_ERROR; }
  size_t putFloat(const char* key, float_t value) { return OSFS::newFile(key, value, true) == OSFS::result::NO_ERROR; }
  size_t putDouble(const char* key, double_t value) { return OSFS::newFile(key, value, true) == OSFS::result::NO_ERROR; }
  size_t putBool(const char* key, bool value) { return OSFS::newFile(key, value, true) == OSFS::result::NO_ERROR; }
  // size_t putString(const char* key, const char* value) { return OSFS::newFile(key, value, true) == OSFS::result::NO_ERROR; }
  size_t putString(const char* key, String value) { return OSFS::newFile(key, value, true) == OSFS::result::NO_ERROR; }
  // size_t putBytes(const char* key, const void* buf, size_t len) { return OSFS::newFile(key, buf, len, true) == OSFS::result::NO_ERROR; }   // Maybe use complex type?


  int8_t getChar(const char* key, int8_t defaultValue = 0);
  uint8_t getUChar(const char* key, uint8_t defaultValue = 0);
  int16_t getShort(const char* key, int16_t defaultValue = 0);
  uint16_t getUShort(const char* key, uint16_t defaultValue = 0);
  int32_t getInt(const char* key, int32_t defaultValue = 0);
  uint32_t getUInt(const char* key, uint32_t defaultValue = 0);
  int32_t getLong(const char* key, int32_t defaultValue = 0);
  uint32_t getULong(const char* key, uint32_t defaultValue = 0);
  int64_t getLong64(const char* key, int64_t defaultValue = 0);
  uint64_t getULong64(const char* key, uint64_t defaultValue = 0);
  float_t getFloat(const char* key, float_t defaultValue = NAN);
  double_t getDouble(const char* key, double_t defaultValue = NAN);
  bool getBool(const char* key, bool defaultValue = false);
  size_t getString(const char* key, char* value, size_t maxLen);
  String getString(const char* key, String defaultValue = String());
  // size_t getBytesLength(const char* key);
  // size_t getBytes(const char* key, void* buf, size_t maxLen);

 private:
};

#endif
