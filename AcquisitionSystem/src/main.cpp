#include <Arduino.h>
// #include <FastLED.h>

#include <console.h>
#include <gui.h>

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

// CRGB leds[NUM_LEDS];
// void rainbow(uint8_t wait);
// CRGB Wheel(byte WheelPos);

static void task2(void*) 
{
  while (true)
  {
    console.log.printf("[MAIN] Time: %d\n", millis());
    vTaskDelay(pdMS_TO_TICKS(500));
  }
}

FLASHMEM __attribute__((noinline)) void setup()
{
  static Gui gui(TFT_SCLK, TFT_MOSI, TFT_CS, TFT_DC, TFT_RST, TFT_BL, TCH_RST, TCH_IRQ);

  console.begin();
  if(CrashReport)
  {
    console.log.printf("[MAIN] Crash-Report:\n%s", CrashReport);
  }
  console.log.println("[MAIN] Starting...");
  gui.begin();

  xTaskCreate(task2, "task2", 2048, nullptr, 2, nullptr);

  vTaskStartScheduler();
}

void loop()
{
}

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
