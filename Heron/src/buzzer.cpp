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


bool Buzzer::begin()
{
  if(buzzerPin == -1)
  {
    console.error.println("[BUZZER] No pin defined");
    return false;
  }
  pinMode(buzzerPin, OUTPUT);
  initialized = true;
  threads.addThread(update, this, 2048);
  return true;
}

void Buzzer::end(void)
{
  initialized = false;
}

void Buzzer::playMelody(const Tone* melody)
{
  this->melody = melody;
  playing = true;
}

void Buzzer::stop()
{
  playing = false;
  this->melody = nullptr;
}

void Buzzer::update(void* parameter)
{
  Buzzer* ref = (Buzzer*)parameter;
  bool playing = false;
  int melodyIndex = 0;
  int melodyPlayTime = 0;
  int melodyStartTime = 0;
  int freq = 0, freqOld = 0;

  while(ref->initialized)
  {
    if(ref->playing && !playing)
    {
      melodyStartTime = millis();
      if(ref->melody == nullptr)
      {
        console.error.println("[BUZZER] Melody is nullptr");
      }
      else
      {
        melodyPlayTime = ref->melody[0].length;
      }
    }
    else if(!ref->playing)
    {
      melodyStartTime = millis();
      melodyPlayTime = 0;
      melodyIndex = 0;
      freqOld = -1;
      ref->melody = nullptr;
      noTone(ref->buzzerPin);
    }
    if(ref->melody)
    {
      freq = ref->melody[melodyIndex].freq;
      int length = ref->melody[melodyIndex].length;
      if(freq == END_OF_MELODY.freq && length == END_OF_MELODY.length)
      {
        ref->playing = false;
        ref->melody = nullptr;
        noTone(ref->buzzerPin);
      }
      else
      {
        if(millis() - melodyStartTime >= melodyPlayTime)
        {
          melodyPlayTime += length;
          melodyIndex++;
        }
        if(freq != freqOld)
        {
          freqOld = freq;
          if(freq == 0)
            noTone(ref->buzzerPin);
          else
            tone(ref->buzzerPin, freq);
        }
      }
    }
    playing = ref->playing;
    threads.delay(1000.0 / UPDATE_RATE);
  }
  noTone(ref->buzzerPin);
}
