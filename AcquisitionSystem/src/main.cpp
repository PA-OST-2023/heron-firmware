#include <Arduino.h>
#include <TeensyThreads.h>

// #include <Audio.h>

// #include "Audio/record_wav_buffered.h"
// #include "SdCard/SdioTeensy.cpp"

// #include <FastLED.h>

#include <console.h>
#include <utils.h>
#include <audioUtils.h>
#include <gui.h>

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

#define SCL_HMI  16
#define SDA_HMI  17
#define SCL_SYS  19
#define SDA_SYS  18

#define BTN_REC  30
#define BTN_SEL  31

// CRGB leds[NUM_LEDS];
// void rainbow(uint8_t wait);
// CRGB Wheel(byte WheelPos);


static AudioUtils audio;
static Utils utils(SCL_SYS, SDA_SYS, SCL_HMI, SDA_HMI);
static Gui gui(TFT_SCLK, TFT_MOSI, TFT_CS, TFT_DC, TFT_RST, TFT_BL, TCH_RST, TCH_IRQ);

static void task2(void*) 
{
  char fileName[20];
  int fileNumber = 0;

  while (true)
  {
    static bool recording = false;
    static bool btnRecOld, btnRec;
    // static bool btnSelOld, btnSel;
    btnRecOld = btnRec;
    // btnSelOld = btnSel;
    btnRec = !digitalRead(BTN_REC);
    // btnSel = !digitalRead(BTN_SEL);

    if(btnRec && !btnRecOld)
    {
      if(!recording)
      {
        console.log.println("[MAIN] Button REC pressed");
        sprintf(fileName, "test_%d.wav", fileNumber++);
        audio.startRecording(fileName);
        recording = true;
      }
      else
      {
        console.log.println("[MAIN] Button REC pressed");
        audio.stopRecording();
        recording = false;
      } 
    }

    static uint32_t t = 0;
    if(millis() - t > 1000)
    {
      t = millis();
      console.log.printf("[MAIN] Time: %d\n", millis());
    }
    threads.delay(50);
  }
}

void setup()
{
  pinMode(BTN_REC, INPUT_PULLUP);
  pinMode(BTN_SEL, INPUT_PULLUP);

  console.begin();
  utils.begin();
  gui.begin();
  audio.begin();
  
  // Wire1.setSCL(16);
  // Wire1.setSDA(17);

  // utils.scanWire(Wire);
  // utils.scanWire(Wire1);

  threads.addThread(task2, nullptr, 2048);

}

void loop()
{
  gui.update();
  utils.update();
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
