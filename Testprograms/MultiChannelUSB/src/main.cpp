#include <Arduino.h>
#include <SPI.h>
#include <SD.h>
#include <Audio.h>
#include <Wire.h>
#include <SerialFlash.h>

#include "usb_audio.h"


// GUItool: begin automatically generated code
AudioSynthWaveformSine   sine1;
AudioSynthWaveformSine   sine2;
AudioSynthWaveformSine   sine3;
AudioSynthWaveformSine   sine4;
AudioSynthWaveformSine   sine5;
AudioSynthWaveformSine   sine6;
AudioSynthWaveformSine   sine7;
AudioSynthWaveformSine   sine8;
AudioSynthWaveformSine   sine9;
AudioSynthWaveformSine   sine10;
AudioSynthWaveformSine   sine11;
AudioSynthWaveformSine   sine12;
AudioSynthWaveformSine   sine13;
AudioSynthWaveformSine   sine14;
AudioSynthWaveformSine   sine15;
AudioSynthWaveformSine   sine16;
AudioSynthWaveformSine   sine17;
AudioSynthWaveformSine   sine18;
AudioSynthWaveformSine   sine19;
AudioSynthWaveformSine   sine20;
AudioSynthWaveformSine   sine21;
AudioSynthWaveformSine   sine22;
AudioSynthWaveformSine   sine23;
AudioSynthWaveformSine   sine24;
AudioSynthWaveformSine   sine25;
AudioSynthWaveformSine   sine26;
AudioSynthWaveformSine   sine27;
AudioSynthWaveformSine   sine28;
// AudioSynthWaveformSine   sine29;
// AudioSynthWaveformSine   sine30;
// AudioSynthWaveformSine   sine31;
// AudioSynthWaveformSine   sine32;
AudioSynthWaveform       sine29;
AudioSynthWaveform       sine30;
AudioSynthWaveform       sine31;
AudioSynthWaveform       sine32;

// AudioOutputUSB           usb1;
AudioOutputUSBOct        usb1;
// AudioInputUSB16           usb1;

AudioConnection          patchCord1(sine1, 0, usb1, 0);
AudioConnection          patchCord2(sine2, 0, usb1, 1);
AudioConnection          patchCord3(sine3, 0, usb1, 2);
AudioConnection          patchCord4(sine4, 0, usb1, 3);
AudioConnection          patchCord5(sine5, 0, usb1, 4);
AudioConnection          patchCord6(sine6, 0, usb1, 5);
AudioConnection          patchCord7(sine7, 0, usb1, 6);
AudioConnection          patchCord8(sine8, 0, usb1, 7);

AudioConnection          patchCord9(sine8, 0, usb1, 8);
AudioConnection          patchCord10(sine7, 0, usb1, 9);
AudioConnection          patchCord11(sine6, 0, usb1, 10);
AudioConnection          patchCord12(sine5, 0, usb1, 11);
AudioConnection          patchCord13(sine4, 0, usb1, 12);
AudioConnection          patchCord14(sine3, 0, usb1, 13);
AudioConnection          patchCord15(sine2, 0, usb1, 14);
AudioConnection          patchCord16(sine1, 0, usb1, 15);


// GUItool: end automatically generated code



void setup()
{
  Serial.begin(0);
  AudioMemory(60);

  sine1.frequency(261.63);
  sine2.frequency(277.19);
  sine3.frequency(293.67);
  sine4.frequency(311.13);
  sine5.frequency(329.63);
  sine6.frequency(349.23);
  sine7.frequency(369.99);
  sine8.frequency(392.00);
  sine9.frequency(415.30);
  sine10.frequency(440.00);
  sine11.frequency(466.16);
  sine12.frequency(493.88);
  sine13.frequency(523.25);
  sine14.frequency(554.37);
  sine15.frequency(587.33);
  sine16.frequency(622.25);
  sine17.frequency(659.25);
  sine18.frequency(698.46);
  sine19.frequency(739.99);
  sine20.frequency(783.99);
  sine21.frequency(830.61);
  sine22.frequency(880.00);
  sine23.frequency(932.33);
  sine24.frequency(987.77);
  sine25.frequency(1046.50);
  sine26.frequency(1108.73);
  sine27.frequency(1174.66);
  sine28.frequency(1244.51);
  // sine29.frequency(1318.51);
  // sine30.frequency(1396.91);
  // sine31.frequency(1479.98);
  // sine32.frequency(1567.98);

  sine29.begin(1.0, 0.5, WAVEFORM_SAWTOOTH);
  sine30.begin(1.0, 1.0, WAVEFORM_SAWTOOTH);
  sine31.begin(1.0, 5.0, WAVEFORM_SAWTOOTH);
  sine32.begin(1.0, 10.0, WAVEFORM_SAWTOOTH);

  pinMode(LED_BUILTIN,OUTPUT);
}


void loop()
{
  static uint32_t t = 0;
  if(millis() - t > 1000)
  {
    t = millis();
    float cpuLoad = AudioProcessorUsage();
    Serial.print("CPU Load: ");
    Serial.print(cpuLoad, 2);  // Print with 2 decimal places
    Serial.print("%, Current Memory Usage: ");
    Serial.print(AudioMemoryUsage());
    Serial.print(" bytes, Max: ");
    Serial.print(AudioMemoryUsageMax());
    Serial.println(" bytes");
  }

  digitalWriteFast(LED_BUILTIN, millis() % 500 > 250);
}
