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
#include <TeensyThreads.h>
#include <console.h>
#include <utils.h>

CHSC6413* CHSC6413::ref = nullptr;

CHSC6413::CHSC6413(I2CDriverWire* wire, int irq)
{
  _wire = wire;
  _irq = irq;
  ref = this;
}

/*!
    @brief  read touch data
*/
CHSC6413::TouchEvent CHSC6413::read_touch()
{
  for(int i = 0; i < RETRY_COUNT; i++)
  {
    uint8_t raw[CHSC6X_READ_POINT_LEN] = {0xFF, 0xFF, 0xFF, 0xFF, 0xFF};
    uint8_t readLen = _wire->requestFrom(CHSC6X_ADDRESS, CHSC6X_READ_POINT_LEN);
    _wire->readBytes(raw, readLen);
    if(readLen == CHSC6X_READ_POINT_LEN)
    {
      if(raw[0] == 0x01)
      {
        if(raw[2] < WIDTH && raw[4] < HEIGHT)
        {
          x = raw[2];
          y = raw[4];
          return TouchEvent::TOUCH_DETECTED;
        }
      }
    }
    if(raw[0] == 0x00)
    {
      return TouchEvent::TOUCH_RELEASED;    // Data is available (does not mean that a touch is detected)
    }
    delayMicroseconds(RETRY_DELAY);
  }
  return TouchEvent::TOUCH_UNKNOWN;
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
  // Utils::turnOnWire(*_wire);

  if(_irq >= 0)
  {
    pinMode(_irq, INPUT_PULLUP);
    attachInterrupt(_irq, handleISR, _interruptType);
  }

  _interruptType = interrupt;
  return true;
}

/*!
    @brief  end the touch screen
*/
void CHSC6413::end()
{
  if(_irq >= 0)
  {
    detachInterrupt(_irq);
  }
  Utils::turnOffWire(*_wire);
}

/*!
    @brief  check for a touch event
*/
CHSC6413::TouchEvent CHSC6413::available()
{
  static TouchEvent event = TouchEvent::TOUCH_UNKNOWN;
  if(_event_available || _irq == -1 || _continuous_mode)
  {
    event = read_touch();
    _event_available = false;
    return event;
  }
  return event;
}
