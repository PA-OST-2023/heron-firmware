/******************************************************************************
* file    ADAU7118.h
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

#ifndef ADAU7118_H
#define ADAU7118_H

#include <Arduino.h>
#include <i2c_driver_wire.h>

#define ADAU7118_REG_VENDOR_ID		        0x00
#define ADAU7118_REG_DEVICE_ID1		        0x01
#define ADAU7118_REG_DEVICE_ID2		        0x02
#define ADAU7118_REG_REVISION_ID	        0x03
#define ADAU7118_REG_ENABLES		          0x04
#define ADAU7118_REG_DEC_RATIO_CLK_MAP	  0x05
#define ADAU7118_REG_HPF_CONTROL	        0x06
#define ADAU7118_REG_SPT_CTRL1		        0x07
#define ADAU7118_REG_SPT_CTRL2		        0x08
#define ADAU7118_REG_SPT_CX(num)	        (0x09 + (num))
#define ADAU7118_REG_DRIVE_STRENGTH	      0x11
#define ADAU7118_REG_RESET		            0x12

class ADAU7118
{
  public:
    typedef enum {DECIMATION_RATIO_64 = 0x00, DECIMATION_RATIO_32 = 0x01, DECIMATION_RATIO_16 = 0x02} decimationRatio_t;
    typedef enum {FILTER_OFF = 0x00,
                  FILTER_222_705HZ = 0x05,
                  FILTER_111_691HZ = 0x06,
                  FILTER_55_125HZ = 0x07,
                  FILTER_27_474HZ = 0x08,
                  FILTER_13_715HZ = 0x09,
                  FILTER_6_836HZ = 0x0A,
                  FILTER_3_427HZ = 0x0B,
                  FILTER_1_716HZ = 0x0C,
                  FILTER_0_856HZ = 0x0D,
                  FILTER_0_428HZ = 0x0E,
                  FILTER_0_214HZ = 0x0F} filter_t;    // High Pass Filter Cuttoff Frequency for 44.1 kHz Sampling Rate
                  
    ADAU7118(I2CDriverWire& wire, uint8_t addr = 0x14);
    bool begin(bool tdmChannel, decimationRatio_t decimationRatio = DECIMATION_RATIO_64);
    uint8_t readVendorId(void) {return readRegister(ADAU7118_REG_VENDOR_ID);}
    uint16_t readDeviceId(void) {return (readRegister(ADAU7118_REG_DEVICE_ID1) << 8) | readRegister(ADAU7118_REG_DEVICE_ID2);}
    uint8_t readRevisionId(void) {return readRegister(ADAU7118_REG_REVISION_ID);}
    bool setHighPassFilter(filter_t filter);
    bool setSlotsEnabled(uint8_t slots);

  private:
    I2CDriverWire& wire;
    const uint8_t addr;
    bool tdmChannel;

    uint8_t readRegister(uint8_t reg);
    bool readRegister(uint8_t reg, uint8_t* data, uint32_t length);
    bool writeRegister(uint8_t reg, uint8_t value);
    bool writeRegister(uint8_t reg, const uint8_t* data, uint32_t length);

};

#endif
