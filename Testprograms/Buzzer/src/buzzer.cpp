/******************************************************************************
* file    buzzer.cpp
*******************************************************************************
* brief   Audio-Driver for the buzzer (plying melodies)
*******************************************************************************
* author  Florian Baumgartner
* version 1.0
* date    2023-12-24
*******************************************************************************
* MIT License
*
* Copyright (c) 2022 Crelin - Florian Baumgartner
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

#include "buzzer.h"
#include <TeensyThreads.h>
#include <console.h>

Buzzer::Buzzer(uint8_t pin) {
  buzzerPin = pin;
  pinMode(buzzerPin, OUTPUT);
}

void Buzzer::begin(void) {
  initialized = true;
  threads.addThread(update, this, 2048);
}

void Buzzer::end(void) {
  initialized = false;
}

void Buzzer::playMelody(Tone* melody, uint32_t length) {
  this->melody = melody;
  this->melodyLength = length;
  playing = true;
}

void Buzzer::stop() {
  playing = false;
  this->melody = nullptr;
  this->melodyLength = 0;
}

void Buzzer::update(void* parameter) {
  Buzzer* ref = (Buzzer*)parameter;
  bool playing = false;
  int32_t buzzerTimer = -1;

  while (ref->initialized) {
    if (ref->playing && !playing) {
      buzzerTimer = millis();
    }
    if (!ref->playing) {
      buzzerTimer = -1;
      noTone(ref->buzzerPin);
    }
    if (buzzerTimer != -1) {
      static int freq = 0, freqOld = 0;
      if (ref->melody != nullptr) {
        int i = 0, t = 0;
        for (i = 0; i < ref->melodyLength; i++) {
          if (t >= millis() - buzzerTimer)
            break;
          t += ref->melody[i].length;
          freq = ref->melody[i].freq;
        }
        if ((i == ref->melodyLength) && (millis() - buzzerTimer > t)) {
          ref->playing = false;
        } else if (freq != freqOld) {
          freqOld = freq;
          if (freq == 0)
            noTone(ref->buzzerPin);
          else
            tone(ref->buzzerPin, freq);
        }
      }
    }
    playing = ref->playing;

    threads.delay(1000.0 / UPDATE_RATE);
  }
}