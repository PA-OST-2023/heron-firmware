/******************************************************************************
 * file    CHSC6413.h
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

#ifndef CHSC6413_H
#define CHSC6413_H

#include <Arduino.h>
#include <i2c_driver_wire.h>

#define CHSC6X_ADDRESS        0x2E
#define CHSC6X_MAX_POINTS_NUM 1
#define CHSC6X_READ_POINT_LEN 5

#define CHSC6X_VF_FLA         0xC0    // VF flag for Full Link Address
#define CHSC6X_RS_CHPID       0x04    // 4 in RS field indicates CHPID

class CHSC6413
{
 public:
  enum class TouchEvent : uint8_t
  {
    TOUCH_DETECTED,
    TOUCH_RELEASED,
    TOUCH_UNKNOWN
  }; 

  constexpr static const int WIDTH = 240;
  constexpr static const int HEIGHT = 240;
  constexpr static const int RETRY_COUNT = 4;
  constexpr static const int RETRY_DELAY = 500;    // us

  CHSC6413(I2CDriverWire* wire, int irq = -1);
  bool begin(int interrupt = RISING);     // Don't mess with the interrupt type, it must be RISING
  void end();
  TouchEvent available();
  void setContinuousMode(bool enable) { _continuous_mode = enable; }
  volatile int x;
  volatile int y;

 private:
  I2CDriverWire* _wire = nullptr;
  volatile int _irq = -1;
  volatile bool _event_available = false;
  volatile bool _continuous_mode = false;
  int _interruptType = RISING;    // Don't mess with the interrupt type, it must be RISING

  static void handleISR();
  static CHSC6413* ref;

  TouchEvent read_touch();
};

#endif