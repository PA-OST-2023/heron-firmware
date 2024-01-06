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
bool CHSC6413::read_touch()
{
  uint8_t raw[CHSC6X_READ_POINT_LEN] = {0x00, 0x00, 0x00, 0x00, 0x00};
  uint8_t readLen = _wire->requestFrom(CHSC6X_ADDRESS, CHSC6X_READ_POINT_LEN);
  if(_invalidCount > MAX_INVALID_COUNT)
  {
    _invalidCount = 0;
    console.warning.printf("[CHSC6413] Too many invalid reads, resetting...\n");
    Utils::turnOffWire(*_wire);
    threads.delay(BUS_RESTART_DELAY);
    if(!begin(_interruptType))
    {
      console.error.printf("[CHSC6413] Failed to reset\n");
    }
    else
    {
      console.ok.printf("[CHSC6413] Reset successful\n");
    }
    return false;
  }
  if(readLen == CHSC6X_READ_POINT_LEN)
  {
    _wire->readBytes(raw, readLen);
    if(raw[0] == 0x01)
    {
      if(raw[2] > WIDTH || raw[4] > HEIGHT)
      {
        return false;
      }
      x = raw[2];
      y = raw[4];
    }
    _invalidCount = 0;
    return true;    // Data is available (does not mean that a touch is detected)
  }
  _invalidCount++;
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
  Utils::turnOnWire(*_wire);

  if(_irq >= 0)
  {
    pinMode(_irq, INPUT_PULLUP);
    attachInterrupt(_irq, handleISR, _interruptType);
  }

  _interruptType = interrupt;
  _invalidCount = 0;
  // bool chipAvailable = false;
  // for(int i = 0; i < INIT_RETRY_COUNT; i++)
  // {
  //   chipAvailable |= read_touch();
  //   if(chipAvailable)
  //   {
  //     break;
  //   }
  //   threads.delay(INIT_RETRY_DELAY);
  // }
  // return chipAvailable;    // Sometimes the chip is not recogined until a first touch is detected
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
bool CHSC6413::available()
{
  if(_event_available || _irq == -1 || _continuous_mode)
  {
    read_touch();
    _event_available = false;
    return true;
  }
  return false;
}
