/******************************************************************************
* file    hmi.h
*******************************************************************************
* brief   HMI functions to handle LEDs, buttons, etc.
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

#ifndef HMI_H
#define HMI_H

#include <Arduino.h>
#include <PCF8523.h>
#include <Adafruit_NeoPixel.h>

class Hmi
{
  public:
    static constexpr const uint32_t LED_COUNT             = 66;
    static constexpr const uint32_t AUDIO_CHANNEL_COUNT   = 32;
    static constexpr const float    UPDATE_RATE           = 30.0;           // Hz

    typedef enum {STATUS_BOOTUP, STATUS_OK, STATUS_WARNING, STATUS_ERROR} systemStatus_t;

    Hmi(int rgbLed, int btnRec, int btnSel, int potVol);
    bool begin(void);
    void setSystemStatus(systemStatus_t status) {systemStatus = status;}
    inline void setLedVolume(int channel, float volume) {ledVolume[constrain(channel, 0, AUDIO_CHANNEL_COUNT - 1)] = volume;}
    inline void setChannelEnabled(int channel, bool enabled) {channelEnabled[constrain(channel, 0, AUDIO_CHANNEL_COUNT - 1)] = enabled;}

  private:
    const int rgbLed, btnRec, btnSel, potVol;
    Adafruit_NeoPixel leds = Adafruit_NeoPixel(LED_COUNT, rgbLed, NEO_GRB + NEO_KHZ800);
    systemStatus_t systemStatus = STATUS_OK;
    float ledVolume[AUDIO_CHANNEL_COUNT];
    bool channelEnabled[AUDIO_CHANNEL_COUNT];
    int selectedChannel = 0;

    volatile bool initialized = false;
    float volume = 0.0;

    static void update(void* parameter);

};

#endif