#include <Arduino.h>
#include <SPI.h>
#include <SD.h>
#include <Audio.h>
#include <Wire.h>
#include <SerialFlash.h>

#include "Audio/record_wav_buffered.h"

#include "SdCard/SdioTeensy.cpp"


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

AudioOutputUSB           usb1;
AudioRecordWAV32         recordWAV1;

AudioConnection          patchCord2(sine1, 0, recordWAV1, 0);
AudioConnection          patchCord3(sine2, 0, recordWAV1, 1);
AudioConnection          patchCord4(sine3, 0, recordWAV1, 2);
AudioConnection          patchCord5(sine4, 0, recordWAV1, 3);
AudioConnection          patchCord6(sine5, 0, recordWAV1, 4);
AudioConnection          patchCord7(sine6, 0, recordWAV1, 5);
AudioConnection          patchCord8(sine7, 0, recordWAV1, 6);
AudioConnection          patchCord9(sine8, 0, recordWAV1, 7);
AudioConnection          patchCord10(sine9, 0, recordWAV1, 8);
AudioConnection          patchCord11(sine10, 0, recordWAV1, 9);
AudioConnection          patchCord12(sine11, 0, recordWAV1, 10);
AudioConnection          patchCord13(sine12, 0, recordWAV1, 11);
AudioConnection          patchCord14(sine13, 0, recordWAV1, 12);
AudioConnection          patchCord15(sine14, 0, recordWAV1, 13);
AudioConnection          patchCord16(sine15, 0, recordWAV1, 14);
AudioConnection          patchCord17(sine16, 0, recordWAV1, 15);
AudioConnection          patchCord18(sine17, 0, recordWAV1, 16);
AudioConnection          patchCord19(sine18, 0, recordWAV1, 17);
AudioConnection          patchCord20(sine19, 0, recordWAV1, 18);
AudioConnection          patchCord21(sine20, 0, recordWAV1, 19);
AudioConnection          patchCord22(sine21, 0, recordWAV1, 20);
AudioConnection          patchCord23(sine22, 0, recordWAV1, 21);
AudioConnection          patchCord24(sine23, 0, recordWAV1, 22);
AudioConnection          patchCord25(sine24, 0, recordWAV1, 23);
AudioConnection          patchCord26(sine25, 0, recordWAV1, 24);
AudioConnection          patchCord27(sine26, 0, recordWAV1, 25);
AudioConnection          patchCord28(sine27, 0, recordWAV1, 26);
AudioConnection          patchCord29(sine28, 0, recordWAV1, 27);
AudioConnection          patchCord30(sine29, 0, recordWAV1, 28);
AudioConnection          patchCord31(sine30, 0, recordWAV1, 29);
AudioConnection          patchCord32(sine31, 0, recordWAV1, 30);
AudioConnection          patchCord33(sine32, 0, recordWAV1, 31);

AudioConnection          patchCord34(sine1, 0, usb1, 0);
AudioConnection          patchCord35(sine2, 0, usb1, 1);
// GUItool: end automatically generated code

#define SDCARD_CS_PIN    BUILTIN_SDCARD.
const char* fileName = "32_Channels_60s.wav";


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

  const size_t sz = 65536 * 64;
  const AudioBuffer::bufType bufMem = AudioBuffer::inExt;
  if(recordWAV1.createBuffer(sz, bufMem))
  {
    while(1)
    {
      Serial.println("Failed to create buffer");
      delay(500);
    }
  }

  // const size_t sz = 65536 * 6;    // TODO: Why -> Tell me why (I don't like Mondays)
  // const AudioBuffer::bufType bufMem = AudioBuffer::inHeap;
  // recordWAV1.createBuffer(sz, bufMem);

  if(!SD.begin(BUILTIN_SDCARD))
  {
    while (1)
    {
      Serial.println("Unable to access the SD card");
      delay(500);
    }
  }
  Serial.println("Type any character to start");
  while (!Serial.available())
  {
    yield();
  }

  setSdclk(100000);
  Serial.printf("SDDIO Speed: %d\n", ((SdioCard*)SD.sdfs.card())->kHzSdClk());
}


void loop()
{
  static uint32_t recordStartTime = 0;
  static bool recording = false;
  if(!recording)
  {
    recording = true;
    Serial.println("startRecording");
    recordWAV1.recordSD(fileName);
    recordStartTime = millis();
  }

  static bool once = true;
  if(recordStartTime + 60000 < millis() && once)
  {
    once = false;
    Serial.println("stopRecording");
    recordWAV1.stop();  
  }

  // static uint32_t t = 0;
  // if(millis() - t > 1000)
  // {
  //   t = millis();
  //   float cpuLoad = AudioProcessorUsage();
  //   Serial.print("CPU Load: ");
  //   Serial.print(cpuLoad, 2);  // Print with 2 decimal places
  //   Serial.print("%, Current Memory Usage: ");
  //   Serial.print(AudioMemoryUsage());
  //   Serial.print(" bytes, Max: ");
  //   Serial.print(AudioMemoryUsageMax());
  //   Serial.println(" bytes");
  // }
}
