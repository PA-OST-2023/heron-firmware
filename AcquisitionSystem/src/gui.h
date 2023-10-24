/******************************************************************************
* file    gui.h
*******************************************************************************
* brief   Wrapper for GUI interface (lvgl, touch, display, etc.)
*******************************************************************************
* author  Florian Baumgartner
* version 1.0
* date    2023-10-23
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

#ifndef GUI_H
#define GUI_H

#include <Arduino.h>
#include <console.h>

using namespace arduino;

#include <Adafruit_GFX.h>
#include <ST7789_t3.h>
#include <CST816S.h>
#include <SPI.h>
#include <lvgl.h>

class Gui
{
  public:
    static constexpr const uint32_t SCREEN_WIDTH          = 240;
    static constexpr const uint32_t SCREEN_HEIGHT         = 240;
    static constexpr const uint32_t SCREEN_BUFFER_HEIGHT  = 60;
    static constexpr const float    UPDATE_RATE           = 30.0;           // Hz
    static constexpr size_t EXT_HEAP_SIZE                 = 1024 * 4096;    // 4MB memory pool on the external ram chip

    Gui(int sclk, int mosi, int cs, int dc, int rst, int bl, int tch_rst, int tch_irq);
    bool begin(void);

  private:
    const int sclk, mosi, cs, dc, rst, bl, tch_rst, tch_irq;
    ST7735_t3 disp = ST7735_t3(cs, dc, mosi, sclk, rst);
    CST816S touch = CST816S(&Wire1, tch_rst, tch_irq);

    static lv_color_t buf[SCREEN_WIDTH * SCREEN_BUFFER_HEIGHT];

    volatile bool initialized = false;
    
    static void update(void* pvParameter);
    static void lvglPrint(const char* buf);
    static void dispflush(lv_disp_drv_t* dispDrv, const lv_area_t* area, lv_color_t* color_p);
    static void touchpadRead(lv_indev_drv_t* drv, lv_indev_data_t* data);
};

#endif