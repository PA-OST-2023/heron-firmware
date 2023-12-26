/******************************************************************************
* file    gui.cpp
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

#include "gui.h"
#include <TeensyThreads.h>
#include <static_malloc.h>
#include "Gui/generated/gui_guider.h"

DMAMEM lv_ui guider_ui;
DMAMEM lv_color_t Gui::buf[Gui::SCREEN_WIDTH * Gui::SCREEN_BUFFER_HEIGHT];
EXTMEM uint8_t Gui::extHeap[Gui::EXT_HEAP_SIZE];
Utils* Gui::utils;

Gui::Gui(int sclk, int mosi, int cs, int dc, int bl, int tch_irq) : sclk(sclk), mosi(mosi), cs(cs), dc(dc), bl(bl), tch_irq(tch_irq) {}

bool Gui::begin(Utils& utilsRef)
{
  bool res = true;
  utils = &utilsRef;
  digitalWrite(bl, LOW);
  pinMode(bl, OUTPUT);

  console.log.println("[GUI] Initializing display... ");
  disp.begin(SPI_FREQUENCY, GC9A01A_SPICLOCK_READ);
  disp.fillScreen(GC9A01A_BLACK);

  utils->lockWire(Wire1);
  if(!touch.begin())
  {
    console.error.println("[GUI] Touch controller could not be initialized");
    res = false;
  }
  utils->unlockWire(Wire1);

  sm_set_default_pool(extHeap, EXT_HEAP_SIZE, false, nullptr);  // use a memory pool on the external ram
  lv_log_register_print_cb(lvglPrint);
  lv_init();

  static lv_disp_draw_buf_t draw_buf;
  lv_disp_draw_buf_init(&draw_buf, buf, NULL, SCREEN_WIDTH * SCREEN_BUFFER_HEIGHT);
  disp.setFrameBuffer((uint16_t*)buf);

  static lv_disp_drv_t disp_drv;
  lv_disp_drv_init(&disp_drv);
  disp_drv.hor_res = SCREEN_WIDTH;
  disp_drv.ver_res = SCREEN_HEIGHT;
  disp_drv.flush_cb = dispflush;
  disp_drv.draw_buf = &draw_buf;
  disp_drv.user_data = this;
  lv_disp_t* dispDrv = lv_disp_drv_register(&disp_drv);
  lv_timer_set_period(dispDrv->refr_timer, 1000.0 / UPDATE_RATE);

  static lv_indev_drv_t indev_drv;
  lv_indev_drv_init(&indev_drv);
  indev_drv.type = LV_INDEV_TYPE_POINTER;
  indev_drv.read_cb = touchpadRead;
  indev_drv.user_data = &touch;
  lv_indev_drv_register(&indev_drv);

  setup_ui(&guider_ui);
  console.ok.println("[GUI] Initialized");
  initialized = true;
  return res;
}

void Gui::setTime(uint8_t hour, uint8_t minute)
{
  if((hour == this->hour) && (minute == this->minute))
    return;
  this->hour = hour;
  this->minute = minute;
  flagTime = true;
  sprintf(bufferTime, "%02d:%02d", hour, minute);
}

void Gui::setTimeDate(uint16_t year, uint8_t month, uint8_t day, uint8_t hour, uint8_t minute, uint8_t second)
{
  if((year == this->year) && (month == this->month) && (day == this->day) && (hour == this->hour) && (minute == this->minute) &&
     (second == this->second))
    return;
  this->year = year;
  this->month = month;
  this->day = day;
  this->hour = hour;
  this->minute = minute;
  this->second = second;
  flagDate = true;
  setTime(hour, minute);
}

void Gui::setSdCardStatus(SdCardStatus_t status)
{
  if(sdCardStatus == status)
    return;
  sdCardStatus = status;
  flagSdCardStatus = true;
}

void Gui::setUsbStatus(UsbStatus_t status)
{
  if(usbStatus == status)
    return;
  usbStatus = status;
  flagUsbStatus = true;
}

void Gui::setEthStatus(EthStatus_t status)
{
  if(ethStatus == status)
    return;
  ethStatus = status;
  flagEthStatus = true;
}

void Gui::setSystemWarning(const char* warning)
{
  if(warning)
  {
    snprintf(warningText, sizeof(warningText), "%s", warning);
    flagWarning = true;
  }
  else
  {
    warningText[0] = '\0';
    flagWarning = true;
  }
}

void Gui::update(void)
{
  if(!initialized)
    return;
  // if(flagTime)
  // {
  //   flagTime = false;
  //   lv_label_set_text(guider_ui.screenRecording_btn_current_time_label, bufferTime);
  // }
  // if(flagDate)
  // {
  //   flagDate = false;
  //   lv_roller_set_selected(guider_ui.screenSetTime_rollerDay, day - 1, LV_ANIM_OFF);
  //   lv_roller_set_selected(guider_ui.screenSetTime_rollerMonth, month - 1, LV_ANIM_OFF);
  //   lv_roller_set_selected(guider_ui.screenSetTime_rollerYear, year - 2023, LV_ANIM_OFF);
  //   lv_roller_set_selected(guider_ui.screenSetTime_rollerHour, hour, LV_ANIM_OFF);
  //   lv_roller_set_selected(guider_ui.screenSetTime_rollerMinute, minute, LV_ANIM_OFF);
  //   lv_roller_set_selected(guider_ui.screenSetTime_rollerSecond, second, LV_ANIM_OFF);
  // }

                  // if(flagSdCardStatus)
  // {
  //   flagSdCardStatus = false;
  //   uint32_t color = 0x00000000;
  //   switch(sdCardStatus)
  //   {
  //     case SD_CARD_MISSING:
  //       color = 0x00292831;
  //       break;
  //     case SD_CARD_ERROR:
  //       color = 0x00FF8F00;
  //       break;
  //     case SD_CARD_OK:
  //       color = 0x00FFFFFF;
  //       break;
  //     default:
  //       break;
  //   }
  //   lv_obj_set_style_text_color(guider_ui.screenRecording_label_sd_card, lv_color_hex(color), LV_PART_MAIN | LV_STATE_DEFAULT);
  // }
  // if(flagUsbStatus)
  // {
  //   flagUsbStatus = false;
  //   uint32_t color = 0x00000000;
  //   switch(usbStatus)
  //   {
  //     case USB_DISCONNECTED:
  //       color = 0x00292831;
  //       break;
  //     case USB_CONNECTED:
  //       color = 0x00FFFFFF;
  //       break;
  //     case USB_ACTIVE:
  //       color = 0x0000FF00;
  //       break;
  //     default:
  //       break;
  //   }
  //   lv_obj_set_style_text_color(guider_ui.screenRecording_label_usb, lv_color_hex(color), LV_PART_MAIN | LV_STATE_DEFAULT);
  // }
  // if(flagEthStatus)
  // {
  //   flagEthStatus = false;
  //   uint32_t color = 0x00000000;
  //   switch(ethStatus)
  //   {
  //     case ETH_DISCONNECTED:
  //       color = 0x00292831;
  //       break;
  //     case ETH_CONNECTED:
  //       color = 0x00FFFFFF;
  //       break;
  //     case ETH_ACTIVE:
  //       color = 0x0000FF00;
  //       break;
  //     default:
  //       break;
  //   }
  //   lv_obj_set_style_text_color(guider_ui.screenRecording_label_ethernet, lv_color_hex(color), LV_PART_MAIN | LV_STATE_DEFAULT);
  // }
  // if(flagWarning)
  // {
  //   flagWarning = false;
  //   if(warningText[0] != '\0')
  //   {
  //     lv_obj_clear_flag(guider_ui.screenRecording_btn_warning, LV_OBJ_FLAG_HIDDEN);
  //     // lv_label_set_text(guider_ui.screenRecording_label_warning, warningText);
  //   }
  //   else
  //   {
  //     lv_obj_add_flag(guider_ui.screenRecording_btn_warning, LV_OBJ_FLAG_HIDDEN);
  //   }
  // }

  lv_task_handler();
}


void Gui::lvglPrint(const char* buf)
{
  console.log.printf("[LVGL] %s", buf);
}

void Gui::dispflush(lv_disp_drv_t* dispDrv, const lv_area_t* area, lv_color_t* color_p)
{
  static bool firstFlush = true;
  Gui* gui = (Gui*)dispDrv->user_data;
  gui->disp.writeRect(area->x1, area->y1, (area->x2 - area->x1 + 1), (area->y2 - area->y1 + 1), (uint16_t*)color_p);
  gui->disp.updateScreenAsync();    // DMA the stuff to the screen
  lv_disp_flush_ready(dispDrv);
  if(firstFlush)                    // Turn on backlight after first flush
  {
    firstFlush = false;
    gui->setBrightness(255);
  }
}

void Gui::touchpadRead(lv_indev_drv_t* drv, lv_indev_data_t* data)
{
  CHSC6413* touch = (CHSC6413*)drv->user_data;
  utils->lockWire(Wire1);
  bool available = touch->available();
  utils->unlockWire(Wire1);
  if(available)
  {
    int x = touch->x;
    int y = touch->y;
    if((x > 0) && (y > 0) && (x < (int)SCREEN_WIDTH) && (y < (int)SCREEN_HEIGHT))
    {
      data->state = LV_INDEV_STATE_PR;    // Indicate that the touchpad is pressed
      data->point.x = (lv_coord_t)x;
      data->point.y = (lv_coord_t)y;
      return;
    }
  }
  data->state = LV_INDEV_STATE_REL;    // Indicate that the touchpad is released
}
