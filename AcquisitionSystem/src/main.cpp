#include <Arduino.h>
// #include <Adafruit_GFX.h>
// #include <ST7789_t3.h>
// #include <CST816S.h>
// #include <SPI.h>

// #include <FastLED.h>
// #include <static_malloc.h>
// #include <lvgl.h>
// #include "Gui/generated/gui_guider.h"

#include <console.h>

#include "arduino_freertos.h"
#include "avr/pgmspace.h"

using namespace arduino;

#define TFT_SCLK 13  // SCLK can also use pin 14
#define TFT_MOSI 11  // MOSI can also use pin 7
#define TFT_CS   10  // CS & DC can use pins 2, 6, 9, 10, 15, 20, 21, 22, 23
#define TFT_DC   25  // but certain pairs must NOT be used: 2+10, 6+9, 20+23, 21+22
#define TFT_RST  26  // RST can use any pin
#define TFT_BL   24  // BL can use any pin

#define TCH_RST  27  // RST can use any pin
#define TCH_IRQ  28  // IRQ can use any pin

#define RGB_LED  22  // RGB LED can use any pin
#define NUM_LEDS 66


// constexpr size_t myHeapSize = 1024 * 4096;
// EXTMEM uint8_t myHeap[myHeapSize]; // 4MB memory pool on the external ram chip


// ST7735_t3 disp = ST7735_t3(TFT_CS, TFT_DC, TFT_MOSI, TFT_SCLK, TFT_RST);
// CST816S touch(&Wire1, TCH_RST, TCH_IRQ);	// SDA, SCL, RST, IRQ
// lv_ui guider_ui;
// CRGB leds[NUM_LEDS];

// const int screenWidth = 240;
// const int screenHeight = 240;
// const int screenBufferHeight = 60;
// const int lvglUpdateRate = 60;

// void my_disp_flush(lv_disp_drv_t *dispDrv, const lv_area_t *area, lv_color_t *color_p);
// void touchpad_read(lv_indev_drv_t * drv, lv_indev_data_t* data);
// void my_print(const char* buf);
static void myLoop(void*);

static void task2(void*) 
{
    while (true) {
        // console.log.println("TICK");
        // vTaskDelay(pdMS_TO_TICKS(1000));

        // console.log.println("TOCK");
        // vTaskDelay(pdMS_TO_TICKS(1000));

        console.log.printf("Time: %d\n", millis());

        vTaskDelay(pdMS_TO_TICKS(500));
    }
}

// void rainbow(uint8_t wait);
// CRGB Wheel(byte WheelPos);

FLASHMEM __attribute__((noinline)) void setup()
{
  console.begin();

  if(CrashReport)
  {
    console.log.println(CrashReport);
  }

  console.ok.println("Console Test :)");

  xTaskCreate(task2, "task2", 2048, nullptr, 2, nullptr);
  // xTaskCreate(myLoop, "myLoop", 256, nullptr, 10, nullptr);

  vTaskStartScheduler();
}


void loop()
{
}

// void my_disp_flush(lv_disp_drv_t *dispDrv, const lv_area_t *area, lv_color_t *color_p)
// {
//   ((ST7789_t3*)dispDrv->user_data)->writeRect(area->x1, area->y1, (area->x2 - area->x1 + 1), (area->y2 - area->y1 + 1), (uint16_t *)color_p);
//   ((ST7789_t3*)dispDrv->user_data)->updateScreenAsync();   // DMA the stuff to the screen
//   lv_disp_flush_ready(dispDrv);
// }

// void touchpad_read(lv_indev_drv_t * drv, lv_indev_data_t* data)
// {
//   if (((CST816S*)drv->user_data)->available())
//   {
//     data->state = LV_INDEV_STATE_PR;  // Indicate that the touchpad is pressed
//     data->point.x = ((CST816S*)drv->user_data)->data.x;
//     data->point.y = ((CST816S*)drv->user_data)->data.y;
//   }
//   else
//   {
//     data->state = LV_INDEV_STATE_REL;
//   }
// }


// void my_print(const char* buf)
// {
//     Serial.write(buf);
//     Serial.flush();
// }

// void rainbow(uint8_t wait) {
//   uint16_t i, j;

//   for(j=0; j<256; j++) {
//     for(i=0; i<NUM_LEDS; i++) {
//       leds[i] = Wheel((i+j) & 255);
//     }
//     FastLED.show();
//     delay(wait);
//   }
// }

// CRGB Wheel(byte WheelPos) {
//   WheelPos = 255 - WheelPos;
//   if(WheelPos < 85) {
//     return CRGB(255 - WheelPos * 3, 0, WheelPos * 3);
//   }
//   if(WheelPos < 170) {
//     WheelPos -= 85;
//     return CRGB(0, WheelPos * 3, 255 - WheelPos * 3);
//   }
//   WheelPos -= 170;
//   return CRGB(WheelPos * 3, 255 - WheelPos * 3, 0);
// }

static void myLoop(void*)
{
  // vTaskDelay(pdMS_TO_TICKS(1000));
  // static ST7735_t3 disp = ST7735_t3(TFT_CS, TFT_DC, TFT_MOSI, TFT_SCLK, TFT_RST);
  // static CST816S touch(&Wire1, TCH_RST, TCH_IRQ);	// SDA, SCL, RST, IRQ
  // static lv_ui guider_ui;

  // pinMode(TFT_BL, OUTPUT);
  // digitalWrite(TFT_BL, LOW);
  // disp.initB();
  // disp.setRotation(3);
  // disp.fillScreen(ST77XX_BLACK);

  // touch.begin();

  // sm_set_default_pool(myHeap, myHeapSize, false, nullptr);  // use a memory pool on the external ram
  // lv_log_register_print_cb(my_print);
  // lv_init();
  // static lv_disp_draw_buf_t draw_buf;
  // static lv_color_t buf[screenWidth * screenBufferHeight];
  // lv_disp_draw_buf_init(&draw_buf, buf, NULL, screenWidth * screenBufferHeight);
  // disp.setFrameBuffer((uint16_t*)buf);

  // static lv_disp_drv_t disp_drv;
  // lv_disp_drv_init(&disp_drv);
  // disp_drv.hor_res = screenWidth;
  // disp_drv.ver_res = screenHeight;
  // disp_drv.flush_cb = my_disp_flush;
  // disp_drv.draw_buf = &draw_buf;
  // disp_drv.user_data = &disp;
  // lv_disp_t* dispDrv = lv_disp_drv_register(&disp_drv);
  // lv_timer_set_period(dispDrv->refr_timer, 1000.0 / lvglUpdateRate);

  // static lv_indev_drv_t indev_drv;
  // lv_indev_drv_init(&indev_drv);
  // indev_drv.type = LV_INDEV_TYPE_POINTER;
  // indev_drv.read_cb = touchpad_read;
  // indev_drv.user_data = &touch;
  // lv_indev_drv_register(&indev_drv);

  // setup_ui(&guider_ui);
  // digitalWrite(TFT_BL, HIGH);

  while(true)
  {
    // lv_task_handler();
    vTaskDelay(pdMS_TO_TICKS(10));
  }
}
