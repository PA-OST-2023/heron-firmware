/******************************************************************************
* file    melodies.h
*******************************************************************************
* brief   Array of melodies
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

#ifndef MELODIES_H
#define MELODIES_H

#include <Arduino.h>
#include <buzzer.h>

constexpr static const Tone MELODIE_POWER_ON[] = {{NOTE_D5, 120}, {0, 25}, {NOTE_A5, 120}, {0, 200}, END_OF_MELODY};

constexpr static const Tone MELODIE_CALIB_STARTED[] = {{NOTE_A5, 120}, END_OF_MELODY};

constexpr static const Tone MELODIE_CALIB_DONE[] = {{NOTE_G5, 150}, {NOTE_B5, 150}, {NOTE_D6, 150}, {NOTE_G6, 150}, END_OF_MELODY};

constexpr static const Tone MELODIE_WARNING[] = {{NOTE_B5, 120}, {0, 25},        {NOTE_B5, 120}, {0, 25},      {NOTE_B5, 120},
                                                 {0, 25},        {NOTE_B5, 120}, {0, 25},        END_OF_MELODY};

constexpr static const Tone MELODIE_WARNING_ACKNOWLAGED[] = {{NOTE_A5, 120}, END_OF_MELODY};

constexpr static const Tone MELODIE_ERROR[] = {{NOTE_B5, 200}, {0, 25}, {NOTE_G5, 200}, {0, 25}, {NOTE_B5, 200}, {0, 25},
                                               {NOTE_G5, 200}, {0, 25}, {NOTE_B5, 200}, {0, 25}, {NOTE_G5, 200}, {0, 25},
                                               {NOTE_B5, 200}, {0, 25}, {NOTE_G5, 200}, {0, 25}, END_OF_MELODY};


#endif
