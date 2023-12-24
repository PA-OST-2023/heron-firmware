#include <Arduino.h>
#include <WS2812Serial.h>
#include <buzzer.h>
#include <console.h>

#include <jinglebells.h>

#define RGB_LED 35  // RGB LED can use any pin
#define NUM_LEDS (17 + 8 * 8)
#define BUZZER_PIN 36

uint8_t drawingMemory[NUM_LEDS * 3];          //  3 bytes per LED
DMAMEM uint8_t displayMemory[NUM_LEDS * 12];  // 12 bytes per LED
WS2812Serial leds(NUM_LEDS, displayMemory, drawingMemory, RGB_LED, WS2812_GRB);

Buzzer buzzer(BUZZER_PIN);

void christmasTree(void);

void setup() {
  console.begin();
  console.log.println("[MAIN] Starting up...");

  leds.begin();
  leds.setBrightness(255);
  leds.clear();
  leds.show();

  for (int i = 0; i < NUM_LEDS; i++) {
    leds.setPixel(i, 0, 50, 0);
  }
  leds.show();

  buzzer.begin();
  buzzer.playMelody(jingleBells, sizeof(jingleBells) / sizeof(Tone));

  // tone(BUZZER_PIN, 440);
  // delay(100);
  // tone(BUZZER_PIN, 880);
  // delay(100);
  // noTone(BUZZER_PIN);

  // delay(500);
  // tone(BUZZER_PIN, 660, 2500);
}

void loop() {
  threads.yield();

  static uint32_t t = 0;
  if (millis() - t > 100) {
    t = millis();
    console.log.printf("[MAIN] Time: %lu\n", t);
  }

  christmasTree();
  threads.delay(1000 / 30);
}

float wavePosition = 0;

void christmasTree() {
  static int colorChangeTimer = 0;  // Static variable for timing color changes
  static int fadeValue = 0;     // For controlling the brightness fade effect
  static bool fadingUp = true;  // Direction of the fade (up or down)

  // Update the fadeValue for the next frame
  if (fadingUp) {
    fadeValue++;
    if (fadeValue >=
        255) {  // If maximum brightness is reached, start fading down
      fadingUp = false;
    }
  } else {
    fadeValue--;
    if (fadeValue <= 0) {  // If minimum brightness is reached, start fading up
      fadingUp = true;
    }
  }

  for (int i = 0; i < leds.numPixels(); i++) {
    // Fading wave pattern with varying intensities of green
    int wave = (sin(i + wavePosition) * 127 + 128) / 255.0 * fadeValue;
    leds.setPixelColor(i, leds.Color(0, wave, 0));

    // Sporadic colorful spots with fading effect
    if (random(100) < 3 &&
        colorChangeTimer % 20 == i % 20) {  // Less frequent appearance
      // Use fadeValue to adjust the brightness
      if (random(2) == 0) {
        leds.setPixelColor(
            i, leds.Color(fadeValue, fadeValue, fadeValue));  // White with fade
      } else {
        leds.setPixelColor(
            i, leds.Color(fadeValue, fadeValue * 0.8,
                          fadeValue * 0.2));  // Soft yellowish with fade
      }
    }
  }

  leds.show();
  colorChangeTimer++;    // Increment the timer
  wavePosition += 0.15;  // Move the wave forward

  // Adjust the delay to make the animation slower
  // delay(100);  // Slow down the animation significantly
}
