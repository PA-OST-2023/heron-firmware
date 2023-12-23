/******************************************************************************
* file    CHSC6413.cpp
*******************************************************************************
* brief   Driver for capactive touch controller CHSC6413
*******************************************************************************
* author  Florian Baumgartner
* version 1.0
* date    2023-12-23
*******************************************************************************
* MIT License
*
* Copyright (c) 2023 Crelin - Florian Baumgartner
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

#include "Arduino.h"
#include "CHSC6413.h"

CHSC6413* CHSC6413::ref = nullptr;

CHSC6413::CHSC6413(TwoWire* wire, int irq) {
  _wire = wire;
  _irq = irq;
  ref = this;
}


/*!
    @brief  read touch data
*/
void CHSC6413::read_touch() {
  uint8_t raw[CHSC6X_READ_POINT_LEN] = {0};
  // i2c_read(CHSC6X_ADDRESS, 0x00, raw, CHSC6X_READ_POINT_LEN);
  // if (raw[0] == 0x01)
  // {
  //   data.x = raw[2];
  //   data.y = raw[4];
  // }
}

/*!
    @brief  handle interrupts
*/
void CHSC6413::handleISR(void) {
  ref->_event_available = true;

}

/*!
    @brief  initialize the touch screen
	@param	interrupt
			type of interrupt FALLING, RISING..
*/
bool CHSC6413::begin(int interrupt) {
  _wire->begin();
  _wire->setClock(400000);

  pinMode(_irq, INPUT_PULLUP);

  uint8_t raw[16];
  i2c_read(CHSC6X_ADDRESS, 0x00, raw, 16);
  // print raw data
  for (int i = 0; i < 16; i++)
  {
    Serial.printf("%02X ", raw[i]);
  }

  // i2c_read(CHSC6X_ADDRESS, 0x15, &data.version, 1);
  // delay(5);
  // i2c_read(CHSC6X_ADDRESS, 0xA7, data.versionInfo, 3);

  attachInterrupt(_irq, handleISR, interrupt);
  return true;
}

/*!
    @brief  check for a touch event
*/
bool CHSC6413::available() {
  if (_event_available) {
    read_touch();
    _event_available = false;
    return true;
  }
  return false;
}

/*!
    @brief  read data from i2c
	@param	addr
			i2c device address
	@param	reg_addr
			device register address
	@param	reg_data
			array to copy the read data
	@param	length
			length of data
*/
uint8_t CHSC6413::i2c_read(uint16_t addr, uint8_t reg_addr, uint8_t *reg_data, uint32_t length)
{
  _wire->beginTransmission(addr);
  _wire->write(reg_addr);
  if (_wire->endTransmission(true))return -1;
  _wire->requestFrom(addr, length);
  for (uint32_t i = 0; i < length; i++) {
    *reg_data++ = _wire->read();
  }
  return 0;
}

/*!
    @brief  write data to i2c
	@brief  read data from i2c
	@param	addr
			i2c device address
	@param	reg_addr
			device register address
	@param	reg_data
			data to be sent
	@param	length
			length of data
*/
uint8_t CHSC6413::i2c_write(uint8_t addr, uint8_t reg_addr, const uint8_t *reg_data, uint32_t length)
{
  _wire->beginTransmission(addr);
  _wire->write(reg_addr);
  for (uint32_t i = 0; i < length; i++) {
    _wire->write(*reg_data++);
  }
  if (_wire->endTransmission(true))return -1;
  return 0;
}