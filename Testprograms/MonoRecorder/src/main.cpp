#include <Arduino.h>
#include <SPI.h>
#include <SD.h>
#include <Audio.h>
#include <Wire.h>
#include <SerialFlash.h>

//write wav
unsigned long ChunkSize = 0L;
unsigned long Subchunk1Size = 16;
unsigned int AudioFormat = 1;
unsigned int numChannels = 1;
unsigned long sampleRate = 44100;
unsigned int bitsPerSample = 16;
unsigned long byteRate = sampleRate*numChannels*(bitsPerSample/8);// samplerate x channels x (bitspersample / 8)
unsigned int blockAlign = numChannels*bitsPerSample/8;
unsigned long Subchunk2Size = 0L;
unsigned long recByteSaved = 0L;
unsigned long NumSamples = 0L;
byte byte1, byte2, byte3, byte4;

// GUItool: begin automatically generated code
AudioSynthWaveformSine   sine1;          //xy=337.0909080505371,500.8181381225586
AudioSynthWaveformSine   sine2;          //xy=339.0909118652344,554.8181762695312
AudioOutputUSB           usb1;           //xy=557.0909652709961,504.8181686401367
AudioRecordQueue         queue1;         //xy=588.0909118652344,582.8181762695312
AudioConnection          patchCord1(sine1, 0, usb1, 0);
AudioConnection          patchCord2(sine1, queue1);
AudioConnection          patchCord3(sine2, 0, usb1, 1);
// GUItool: end automatically generated code


int mode = 0;  // 0=stopped, 1=recording
File file;

void startRecording();
void continueRecording();
void stopRecording();
void writeOutHeader();

void setup() {
  Serial.begin(9600);
  AudioMemory(60);

  sine1.frequency(440);
  sine1.amplitude(0.5);
  sine2.frequency(880);
  sine2.amplitude(0.5);

  if(!SD.begin(BUILTIN_SDCARD))
  {
    while (1)
    {
      Serial.println("Unable to access the SD card");
      delay(500);
    }
  }
  Serial.println("Press 1 to start recording, 2 to stop");
}


void loop()
{
  if (Serial.available() > 0)
  {
    byte incomingByte = Serial.read();
    if (incomingByte == '1')
    {
      Serial.println("Record Button Press");
      if (mode == 0) startRecording();
    }
    if(incomingByte == '2')
    {
      Serial.println("Stop Button Press");
      if (mode == 1) stopRecording();
    }
  }
  if(mode == 1)
  {
    continueRecording();
  }
}

void startRecording()
{
  Serial.println("startRecording");
  if
  (SD.exists("RECORD.WAV"))
  {
    SD.remove("RECORD.WAV");
  }
  file = SD.open("RECORD.WAV", FILE_WRITE);
  if(file)
  {
    queue1.begin();
    mode = 1;
    recByteSaved = 0L;
  }
}

void continueRecording()
{
  if (queue1.available() >= 2)
  {
    byte buffer[512];
    memcpy(buffer, queue1.readBuffer(), 256);
    queue1.freeBuffer();
    memcpy(buffer + 256, queue1.readBuffer(), 256);
    queue1.freeBuffer();
    // write all 512 bytes to the SD card
    file.write(buffer, 512);
    recByteSaved += 512;
//    elapsedMicros usec = 0;
//    Serial.print("SD write, us=");
//    Serial.println(usec);
  }
}

void stopRecording()
{
  Serial.println("stopRecording");
  queue1.end();
  if(mode == 1)
  {
    while(queue1.available() > 0)
    {
      file.write((byte*)queue1.readBuffer(), 256);
      queue1.freeBuffer();
      recByteSaved += 256;
    }
    writeOutHeader();
    file.close();
  }
  mode = 0;
}

void writeOutHeader()
{
  // Update WAV header with final filesize/datasize
  // NumSamples = (recByteSaved*8)/bitsPerSample/numChannels;
  // Subchunk2Size = NumSamples*numChannels*bitsPerSample/8;
  // number of samples x number of channels x number of bytes per sample
  Subchunk2Size = recByteSaved;
  ChunkSize = Subchunk2Size + 36;
  file.seek(0);
  file.write("RIFF");
  byte1 = ChunkSize & 0xff;
  byte2 = (ChunkSize >> 8) & 0xff;
  byte3 = (ChunkSize >> 16) & 0xff;
  byte4 = (ChunkSize >> 24) & 0xff;  
  file.write(byte1);  file.write(byte2);  file.write(byte3);  file.write(byte4);
  file.write("WAVE");
  file.write("fmt ");
  byte1 = Subchunk1Size & 0xff;
  byte2 = (Subchunk1Size >> 8) & 0xff;
  byte3 = (Subchunk1Size >> 16) & 0xff;
  byte4 = (Subchunk1Size >> 24) & 0xff;  
  file.write(byte1);  file.write(byte2);  file.write(byte3);  file.write(byte4);
  byte1 = AudioFormat & 0xff;
  byte2 = (AudioFormat >> 8) & 0xff;
  file.write(byte1);  file.write(byte2); 
  byte1 = numChannels & 0xff;
  byte2 = (numChannels >> 8) & 0xff;
  file.write(byte1);  file.write(byte2); 
  byte1 = sampleRate & 0xff;
  byte2 = (sampleRate >> 8) & 0xff;
  byte3 = (sampleRate >> 16) & 0xff;
  byte4 = (sampleRate >> 24) & 0xff;  
  file.write(byte1);  file.write(byte2);  file.write(byte3);  file.write(byte4);
  byte1 = byteRate & 0xff;
  byte2 = (byteRate >> 8) & 0xff;
  byte3 = (byteRate >> 16) & 0xff;
  byte4 = (byteRate >> 24) & 0xff;  
  file.write(byte1);  file.write(byte2);  file.write(byte3);  file.write(byte4);
  byte1 = blockAlign & 0xff;
  byte2 = (blockAlign >> 8) & 0xff;
  file.write(byte1);  file.write(byte2); 
  byte1 = bitsPerSample & 0xff;
  byte2 = (bitsPerSample >> 8) & 0xff;
  file.write(byte1);  file.write(byte2); 
  file.write("data");
  byte1 = Subchunk2Size & 0xff;
  byte2 = (Subchunk2Size >> 8) & 0xff;
  byte3 = (Subchunk2Size >> 16) & 0xff;
  byte4 = (Subchunk2Size >> 24) & 0xff;  
  file.write(byte1);  file.write(byte2);  file.write(byte3);  file.write(byte4);
  file.close();
  Serial.println("header written"); 
  Serial.print("Subchunk2: "); 
  Serial.println(Subchunk2Size); 
}