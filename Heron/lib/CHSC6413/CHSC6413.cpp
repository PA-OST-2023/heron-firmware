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

#include "CHSC6413.h"
#include "Arduino.h"

CHSC6413* CHSC6413::ref = nullptr;

CHSC6413::CHSC6413(TwoWire* wire, int irq)
{
  _wire = wire;
  _irq = irq;
  ref = this;
}


/*!
    @brief  read touch data
*/
bool CHSC6413::read_touch()
{
  uint8_t raw[CHSC6X_READ_POINT_LEN];
  uint8_t readLen = _wire->requestFrom(CHSC6X_ADDRESS, CHSC6X_READ_POINT_LEN);
  if(readLen == CHSC6X_READ_POINT_LEN)
  {
    _wire->readBytes(raw, readLen);
    if(raw[0] == 0x01)
    {
      x = raw[2];
      y = raw[4];
    }
    return true;    // Data is available (does not mean that a touch is detected)
  }
  return false;
}

/*!
    @brief  handle interrupts
*/
void CHSC6413::handleISR(void)
{
  ref->_event_available = true;
}

/*!
    @brief  initialize the touch screen
	@param	interrupt
			type of interrupt FALLING, RISING..
*/
bool CHSC6413::begin(int interrupt)
{
  _wire->begin();
  _wire->setClock(400000);

  bool chipAvailable = false;
  for(int i = 0; i < 8; i++)    // Try multiple times (somehow 1 of 8 times, the chip does not respond)
  {
    chipAvailable |= read_touch();
    if(chipAvailable)
    {
      break;
    }
    delay(5);
  }
  if(!chipAvailable)
  {
    return false;
  }

  pinMode(_irq, INPUT_PULLUP);
  attachInterrupt(_irq, handleISR, interrupt);
  return true;
}

/*!
    @brief  check for a touch event
*/
bool CHSC6413::available()
{
  if(_event_available)
  {
    read_touch();
    _event_available = false;
    return true;
  }
  return false;
}
