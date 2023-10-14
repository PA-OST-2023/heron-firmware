#define TFT_SCLK 13  // SCLK can also use pin 14
#define TFT_MOSI 11  // MOSI can also use pin 7
#define TFT_CS   10  // CS & DC can use pins 2, 6, 9, 10, 15, 20, 21, 22, 23
#define TFT_DC   25  // but certain pairs must NOT be used: 2+10, 6+9, 20+23, 21+22
#define TFT_RST  26  // RST can use any pin
#define TFT_BL   24  // BL can use any pin

#include <Arduino.h>
#include <Adafruit_GFX.h>
#include <ST7789_t3.h>
#include <SPI.h>

#include <lvgl.h>
#include "Gui/ui.h"

ST7789_t3 disp = ST7789_t3(TFT_CS, TFT_DC, TFT_MOSI, TFT_SCLK, TFT_RST);

const int screenWidth = 240;
const int screenHeight = 240;
const int screenBufferHeight = 240;
const int lvglUpdateRate = 60;

void my_disp_flush(lv_disp_drv_t *dispDrv, const lv_area_t *area, lv_color_t *color_p);

void setup()
{
  Serial.begin(0);

  pinMode(TFT_BL, OUTPUT);
  digitalWrite(TFT_BL, LOW);
  disp.init(240, 240);
  disp.setAddrWindow(0, 0, 240, 240);
  disp.setRotation(2);
  
  lv_init();
  static lv_disp_draw_buf_t draw_buf;
  static lv_color_t buf[screenWidth * screenBufferHeight];
  lv_disp_draw_buf_init(&draw_buf, buf, NULL, screenWidth * screenBufferHeight);
  disp.setFrameBuffer((uint16_t*)buf);

  static lv_disp_drv_t disp_drv;
  lv_disp_drv_init(&disp_drv);
  disp_drv.hor_res = screenWidth;
  disp_drv.ver_res = screenHeight;
  disp_drv.flush_cb = my_disp_flush;
  disp_drv.draw_buf = &draw_buf;
  disp_drv.user_data = &disp;
  lv_disp_t* dispDrv = lv_disp_drv_register(&disp_drv);
  lv_timer_set_period(dispDrv->refr_timer, 1000.0 / lvglUpdateRate);

  ui_init();

  // lv_disp_load_scr(ui_ScreenSetTime);
  lv_disp_load_scr(ui_ScreenRecording);

  digitalWrite(TFT_BL, HIGH);
}


void loop()
{
  lv_task_handler();
  delay(5);
}

void my_disp_flush(lv_disp_drv_t *dispDrv, const lv_area_t *area, lv_color_t *color_p)
{
  ((ST7789_t3*)dispDrv->user_data)->writeRect(area->x1, area->y1, (area->x2 - area->x1 + 1), (area->y2 - area->y1 + 1), (uint16_t *)color_p);
  ((ST7789_t3*)dispDrv->user_data)->updateScreenAsync();   // DMA the stuff to the screen
  lv_disp_flush_ready(dispDrv);
}
