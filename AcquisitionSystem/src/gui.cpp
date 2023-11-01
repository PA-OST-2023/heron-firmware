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
#include <static_malloc.h>
#include <TeensyThreads.h>
#include "Gui/generated/gui_guider.h"

DMAMEM lv_ui guider_ui;
DMAMEM lv_color_t Gui::buf[Gui::SCREEN_WIDTH * Gui::SCREEN_BUFFER_HEIGHT];
EXTMEM uint8_t Gui::extHeap[Gui::EXT_HEAP_SIZE];
Utils* Gui::utils;

Gui::Gui(int sclk, int mosi, int cs, int dc, int rst, int bl, int tch_rst, int tch_irq) : sclk(sclk), mosi(mosi), cs(cs), dc(dc), rst(rst), bl(bl), tch_rst(tch_rst), tch_irq(tch_irq)
{
  static lv_obj_t** swRefs[AUDIO_CHANNEL_COUNT] = {
    &guider_ui.screenRecording_sw_01, &guider_ui.screenRecording_sw_02, &guider_ui.screenRecording_sw_03, &guider_ui.screenRecording_sw_04,
    &guider_ui.screenRecording_sw_05, &guider_ui.screenRecording_sw_06, &guider_ui.screenRecording_sw_07, &guider_ui.screenRecording_sw_08,
    &guider_ui.screenRecording_sw_09, &guider_ui.screenRecording_sw_10, &guider_ui.screenRecording_sw_11, &guider_ui.screenRecording_sw_12,
    &guider_ui.screenRecording_sw_13, &guider_ui.screenRecording_sw_14, &guider_ui.screenRecording_sw_15, &guider_ui.screenRecording_sw_16,
    &guider_ui.screenRecording_sw_17, &guider_ui.screenRecording_sw_18, &guider_ui.screenRecording_sw_19, &guider_ui.screenRecording_sw_20,
    &guider_ui.screenRecording_sw_21, &guider_ui.screenRecording_sw_22, &guider_ui.screenRecording_sw_23, &guider_ui.screenRecording_sw_24,
    &guider_ui.screenRecording_sw_25, &guider_ui.screenRecording_sw_26, &guider_ui.screenRecording_sw_27, &guider_ui.screenRecording_sw_28,
    &guider_ui.screenRecording_sw_29, &guider_ui.screenRecording_sw_30, &guider_ui.screenRecording_sw_31, &guider_ui.screenRecording_sw_32};
  enableSwitches = swRefs;

  static lv_obj_t** mnRefs[AUDIO_CHANNEL_COUNT] = {
    &guider_ui.screenRecording_label_spk_01, &guider_ui.screenRecording_label_spk_02, &guider_ui.screenRecording_label_spk_03, &guider_ui.screenRecording_label_spk_04,
    &guider_ui.screenRecording_label_spk_05, &guider_ui.screenRecording_label_spk_06, &guider_ui.screenRecording_label_spk_07, &guider_ui.screenRecording_label_spk_08,
    &guider_ui.screenRecording_label_spk_09, &guider_ui.screenRecording_label_spk_10, &guider_ui.screenRecording_label_spk_11, &guider_ui.screenRecording_label_spk_12,
    &guider_ui.screenRecording_label_spk_13, &guider_ui.screenRecording_label_spk_14, &guider_ui.screenRecording_label_spk_15, &guider_ui.screenRecording_label_spk_16,
    &guider_ui.screenRecording_label_spk_17, &guider_ui.screenRecording_label_spk_18, &guider_ui.screenRecording_label_spk_19, &guider_ui.screenRecording_label_spk_20,
    &guider_ui.screenRecording_label_spk_21, &guider_ui.screenRecording_label_spk_22, &guider_ui.screenRecording_label_spk_23, &guider_ui.screenRecording_label_spk_24,
    &guider_ui.screenRecording_label_spk_25, &guider_ui.screenRecording_label_spk_26, &guider_ui.screenRecording_label_spk_27, &guider_ui.screenRecording_label_spk_28,
    &guider_ui.screenRecording_label_spk_29, &guider_ui.screenRecording_label_spk_30, &guider_ui.screenRecording_label_spk_31, &guider_ui.screenRecording_label_spk_32};  
  monitorSymbols = mnRefs;

  static lv_obj_t** chRefs[AUDIO_CHANNEL_COUNT] = {
    &guider_ui.screenRecording_label_ch_01, &guider_ui.screenRecording_label_ch_02, &guider_ui.screenRecording_label_ch_03, &guider_ui.screenRecording_label_ch_04,
    &guider_ui.screenRecording_label_ch_05, &guider_ui.screenRecording_label_ch_06, &guider_ui.screenRecording_label_ch_07, &guider_ui.screenRecording_label_ch_08,
    &guider_ui.screenRecording_label_ch_09, &guider_ui.screenRecording_label_ch_10, &guider_ui.screenRecording_label_ch_11, &guider_ui.screenRecording_label_ch_12,
    &guider_ui.screenRecording_label_ch_13, &guider_ui.screenRecording_label_ch_14, &guider_ui.screenRecording_label_ch_15, &guider_ui.screenRecording_label_ch_16,
    &guider_ui.screenRecording_label_ch_17, &guider_ui.screenRecording_label_ch_18, &guider_ui.screenRecording_label_ch_19, &guider_ui.screenRecording_label_ch_20,
    &guider_ui.screenRecording_label_ch_21, &guider_ui.screenRecording_label_ch_22, &guider_ui.screenRecording_label_ch_23, &guider_ui.screenRecording_label_ch_24,
    &guider_ui.screenRecording_label_ch_25, &guider_ui.screenRecording_label_ch_26, &guider_ui.screenRecording_label_ch_27, &guider_ui.screenRecording_label_ch_28,
    &guider_ui.screenRecording_label_ch_29, &guider_ui.screenRecording_label_ch_30, &guider_ui.screenRecording_label_ch_31, &guider_ui.screenRecording_label_ch_32};
  channelIndeces = chRefs;
}

bool Gui::begin(Utils& utilsRef)
{
  utils = &utilsRef;
  digitalWrite(bl, LOW);
  pinMode(bl, OUTPUT);

  console.log.println("[GUI] Initializing display... ");
  disp.initB();
  disp.setRotation(3);
  disp.fillScreen(ST77XX_BLACK);

  utils->lockWire(Wire1);
  touch.begin();
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
  disp_drv.user_data = &disp;
  lv_disp_t* dispDrv = lv_disp_drv_register(&disp_drv);
  lv_timer_set_period(dispDrv->refr_timer, 1000.0 / UPDATE_RATE);

  static lv_indev_drv_t indev_drv;
  lv_indev_drv_init(&indev_drv);
  indev_drv.type = LV_INDEV_TYPE_POINTER;
  indev_drv.read_cb = touchpadRead;
  indev_drv.user_data = &touch;
  lv_indev_drv_register(&indev_drv);

  setup_ui(&guider_ui);
  digitalWrite(bl, HIGH);

  console.ok.println("[GUI] Initialization done.");
  initialized = true;
  return true;
}

bool Gui::isMainScreenActive(void)
{
  return (lv_scr_act() == guider_ui.screenRecording);
}

void Gui::setTime(uint8_t hour, uint8_t minute)
{
  char buf[10];
  sprintf(buf, "%02d:%02d", hour, minute);
  lv_label_set_text(guider_ui.screenRecording_btn_current_time_label, buf);
}

void Gui::setTimeDate(uint16_t year, uint8_t month, uint8_t day, uint8_t hour, uint8_t minute, uint8_t second)
{
  setTime(hour, minute);
  lv_roller_set_selected(guider_ui.screenSetTime_rollerDay, day - 1, LV_ANIM_OFF);
  lv_roller_set_selected(guider_ui.screenSetTime_rollerMonth, month - 1, LV_ANIM_OFF);
  lv_roller_set_selected(guider_ui.screenSetTime_rollerYear, year - 2023, LV_ANIM_OFF);
  lv_roller_set_selected(guider_ui.screenSetTime_rollerHour, hour, LV_ANIM_OFF);
  lv_roller_set_selected(guider_ui.screenSetTime_rollerMinute, minute, LV_ANIM_OFF);
  lv_roller_set_selected(guider_ui.screenSetTime_rollerSecond, second, LV_ANIM_OFF);
}

void Gui::getTimeDate(uint16_t& year, uint8_t& month, uint8_t& day, uint8_t& hour, uint8_t& minute, uint8_t& second)
{
  char buf[10];
  lv_roller_get_selected_str(guider_ui.screenSetTime_rollerDay, buf, 10);     day = atoi(buf);
  lv_roller_get_selected_str(guider_ui.screenSetTime_rollerMonth, buf, 10);   month = atoi(buf);
  lv_roller_get_selected_str(guider_ui.screenSetTime_rollerYear, buf, 10);    year = atoi(buf);
  lv_roller_get_selected_str(guider_ui.screenSetTime_rollerHour, buf, 10);    hour = atoi(buf);
  lv_roller_get_selected_str(guider_ui.screenSetTime_rollerMinute, buf, 10);  minute = atoi(buf);
  lv_roller_get_selected_str(guider_ui.screenSetTime_rollerSecond, buf, 10);  second = atoi(buf);  
}

void Gui::setVolume(float volume)
{
  uint8_t percent = constrain((uint8_t)(volume * 100.0 + 0.5), 0, 100);
  char buf[10];
  snprintf(buf, sizeof(buf), "%02d", percent);
  lv_label_set_text(guider_ui.screenRecording_label_volume, buf);
  lv_bar_set_value(guider_ui.screenRecording_bar_volume, percent, LV_ANIM_OFF);
}

void Gui::setChannelEnabled(const bool* enabled, uint32_t count)
{
  char buf[20];
  int channelCount = 0;
  for(int i = 0; i < count; i++)
  {
    if(*enableSwitches[i])
    {
      if(enabled[i])
      {
        lv_obj_add_state(*enableSwitches[i], LV_STATE_CHECKED);
      }
      else
      {
        lv_obj_clear_state(*enableSwitches[i], LV_STATE_CHECKED);
      }
    }
    if(*channelIndeces[i])
    {
      if(enabled[i])
      {
        snprintf(buf, sizeof(buf), "CH: %2d", channelCount++);
        lv_label_set_text(*channelIndeces[i], buf);
        lv_obj_clear_flag(*channelIndeces[i], LV_OBJ_FLAG_HIDDEN);
      }
      else
      {
        lv_obj_add_flag(*channelIndeces[i], LV_OBJ_FLAG_HIDDEN);
      }
    }
  }
}

void Gui::getChannelEnabled(bool* enabled, uint32_t count)
{
  for(int i = 0; i < count; i++)
  {
    enabled[i] = lv_obj_has_state(*enableSwitches[i], LV_STATE_CHECKED);
  }
}

void Gui::setChannelMonitor(int channel)
{
  for(int i = 0; i < AUDIO_CHANNEL_COUNT; i++)
  {
    if(*monitorSymbols[i])
    {
      uint32_t color = (i == channel) ? 0x00FF00 : 0x0041485A;
      lv_obj_set_style_text_color(*monitorSymbols[i], lv_color_hex(color), LV_PART_MAIN|LV_STATE_DEFAULT);
    }
  }

}

void Gui::setSdCardStatus(SdCardStatus_t status)
{

}

void Gui::setUsbStatus(UsbStatus_t status)
{

}

void Gui::setEthStatus(EthStatus_t status)
{

}

void Gui::setSystemWarning(const char* warning)
{

}

void Gui::setFileContainer(FileContainer* fileContainer, uint32_t count)
{

}

void Gui::setDiskUsage(uint32_t used, uint32_t total)
{

}

void Gui::setRecordingState(bool state)
{
  if(state)
  {
    lv_obj_clear_flag(guider_ui.screenRecording_cont_recording, LV_OBJ_FLAG_HIDDEN);
    // lv_obj_add_flag(guider_ui.screenRecording_tileview, LV_OBJ_FLAG_HIDDEN);
    // lv_obj_add_flag(guider_ui.screenRecording_cont_top_bar, LV_OBJ_FLAG_HIDDEN);
    lv_obj_add_state(guider_ui.screenRecording_tileview, LV_STATE_DISABLED);
    lv_obj_add_state(guider_ui.screenRecording_cont_top_bar, LV_STATE_DISABLED);
  }
  else
  {
    lv_obj_add_flag(guider_ui.screenRecording_cont_recording, LV_OBJ_FLAG_HIDDEN);
    // lv_obj_clear_flag(guider_ui.screenRecording_tileview, LV_OBJ_FLAG_HIDDEN);
    // lv_obj_clear_flag(guider_ui.screenRecording_cont_top_bar, LV_OBJ_FLAG_HIDDEN);
    lv_obj_clear_state(guider_ui.screenRecording_tileview, LV_STATE_DISABLED);
    lv_obj_clear_state(guider_ui.screenRecording_cont_top_bar, LV_STATE_DISABLED);
  }
}

void Gui::setRecordingTime(float time)
{
  char buf[20];
  snprintf(buf, sizeof(buf), "%02d:%02d.%02d", (int)time / 60, (int)time % 60, (int)(time * 100.0) % 100);
  lv_label_set_text(guider_ui.screenRecording_label_recording_time, buf);
}

void Gui::setRemainingRecordingTime(float time)
{

}


void Gui::update(void)
{
  lv_task_handler();
}

void Gui::lvglPrint(const char* buf)
{
  console.log.printf("[LVGL] %s", buf);
}

void Gui::dispflush(lv_disp_drv_t* dispDrv, const lv_area_t* area, lv_color_t* color_p)
{
  ST7735_t3* disp = (ST7735_t3*)dispDrv->user_data;
  disp->writeRect(area->x1, area->y1, (area->x2 - area->x1 + 1), (area->y2 - area->y1 + 1), (uint16_t *)color_p);
  disp->updateScreenAsync();          // DMA the stuff to the screen
  lv_disp_flush_ready(dispDrv);
}

void Gui::touchpadRead(lv_indev_drv_t* drv, lv_indev_data_t* data)
{
  CST816S* touch = (CST816S*)drv->user_data;
  utils->lockWire(Wire1);
  bool available = touch->available();
  utils->unlockWire(Wire1);
  if(available)
  {
    int x = touch->data.x;
    int y = touch->data.y;
    if((x > 0) && (y > 0) && (x < (int)SCREEN_WIDTH) && (y < (int)SCREEN_HEIGHT))
    {
      data->state = LV_INDEV_STATE_PR;  // Indicate that the touchpad is pressed
      data->point.x = (lv_coord_t)x;
      data->point.y = (lv_coord_t)y;
      return;
    }
  }
  data->state = LV_INDEV_STATE_REL;     // Indicate that the touchpad is released
}
