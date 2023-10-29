/******************************************************************************
* file    ADAU7118.cpp
*******************************************************************************
* brief   Driver for 8-Channel PDM to I2S/TDM Converter ADAU7118
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

#include "ADAU7118.h"
#include "../../src/console.h"

ADAU7118::ADAU7118(TwoWire& wire, uint8_t addr) : wire(wire), addr(addr)
{
}

bool ADAU7118::begin(bool tdmChannel, decimationRatio_t decimationRatio)
{
  bool res = true;
  if(readVendorId() != 0x41)
  {
    console.error.println("[ADAU7118] Vendor ID is not correct!");
    return false;
  }

  res &= writeRegister(ADAU7118_REG_ENABLES, 0x3F);    // Enable PDM Clock 0 & 1, Enable all channels
  res &= writeRegister(ADAU7118_REG_DEC_RATIO_CLK_MAP, 0xD0 | (uint8_t)decimationRatio);
  res &= setHighPassFilter(FILTER_OFF);
  res &= writeRegister(ADAU7118_REG_SPT_CTRL1, 0x53);  // Enable Tristate, 16 BCLKs per slot, Left-Justified (delay by 0), TDM-Mode
  res &= writeRegister(ADAU7118_REG_SPT_CTRL2, 0x00);  // Frame Clock Polarity: Normal, Capture on rising edge
  for(int i = 0; i < 8; i++)
  {
    uint8_t reg = 0x01 | (i << 4) | (tdmChannel? 0x80 : 0x00);    // Drive slot active, Set TDM-Channel (0 ... 7 or 8 ... 15)
    res &= writeRegister(ADAU7118_REG_SPT_CX(i), reg);
  }
  return res;
}

bool ADAU7118::setHighPassFilter(filter_t filter)
{
  if(filter == FILTER_OFF)
  {
    return writeRegister(ADAU7118_REG_HPF_CONTROL, 0x00);
  }
  else
  {
    return writeRegister(ADAU7118_REG_HPF_CONTROL, 0x01 | ((uint8_t)filter << 4));
  }
}

uint8_t ADAU7118::readRegister(uint8_t reg)
{
  uint8_t data;
  readRegister(reg, &data, 1);
  return data;
}

bool ADAU7118::writeRegister(uint8_t reg, uint8_t value)
{
  return writeRegister(reg, &value, 1);
}

bool ADAU7118::readRegister(uint8_t reg, uint8_t* data, uint32_t length)
{
  wire.beginTransmission(addr);
  wire.write(reg);
  if(wire.endTransmission(true))
  {
    return false;
  }
  wire.requestFrom(addr, length);
  for(uint32_t i = 0; i < length; i++)
  {
    *data++ = wire.read();
  }
  return true;
}

bool ADAU7118::writeRegister(uint8_t reg, const uint8_t* data, uint32_t length)
{
  wire.beginTransmission(addr);
  wire.write(reg);
  for(uint32_t i = 0; i < length; i++)
  {
    wire.write(*data++);
  }
  return wire.endTransmission(true) == 0;
}

