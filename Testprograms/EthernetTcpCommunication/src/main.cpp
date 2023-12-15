#include <Arduino.h>
#include <NativeEthernet.h>
#include <NativeEthernetUdp.h>
#include <console.h>

#include <Audio.h>
// #include "Audio/transmit_wav_buffered.h"


void teensyMAC(uint8_t *mac)
{
  for(uint8_t by=0; by<2; by++) mac[by]=(HW_OCOTP_MAC1 >> ((1-by)*8)) & 0xFF;
  for(uint8_t by=0; by<4; by++) mac[by+2]=(HW_OCOTP_MAC0 >> ((3-by)*8)) & 0xFF;
}

IPAddress ip(192, 168, 33, 10);
IPAddress remoteIp(192, 168, 33, 30);
// EthernetUDP Udp;
unsigned int audioPort = 6666;

EthernetClient client;


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
AudioSynthWaveformSine   sine29;
AudioSynthWaveformSine   sine30;
AudioSynthWaveformSine   sine31;
AudioSynthWaveformSine   sine32;

// AudioTransmitWAV32       transmitWav1;

// AudioConnection          patchCord2(sine1, 0, transmitWav1, 0);
// AudioConnection          patchCord3(sine2, 0, transmitWav1, 1);
// AudioConnection          patchCord4(sine3, 0, transmitWav1, 2);
// AudioConnection          patchCord5(sine4, 0, transmitWav1, 3);
// AudioConnection          patchCord6(sine5, 0, transmitWav1, 4);
// AudioConnection          patchCord7(sine6, 0, transmitWav1, 5);
// AudioConnection          patchCord8(sine7, 0, transmitWav1, 6);
// AudioConnection          patchCord9(sine8, 0, transmitWav1, 7);
// AudioConnection          patchCord10(sine9, 0, transmitWav1, 8);
// AudioConnection          patchCord11(sine10, 0, transmitWav1, 9);
// AudioConnection          patchCord12(sine11, 0, transmitWav1, 10);
// AudioConnection          patchCord13(sine12, 0, transmitWav1, 11);
// AudioConnection          patchCord14(sine13, 0, transmitWav1, 12);
// AudioConnection          patchCord15(sine14, 0, transmitWav1, 13);
// AudioConnection          patchCord16(sine15, 0, transmitWav1, 14);
// AudioConnection          patchCord17(sine16, 0, transmitWav1, 15);
// AudioConnection          patchCord18(sine17, 0, transmitWav1, 16);
// AudioConnection          patchCord19(sine18, 0, transmitWav1, 17);
// AudioConnection          patchCord20(sine19, 0, transmitWav1, 18);
// AudioConnection          patchCord21(sine20, 0, transmitWav1, 19);
// AudioConnection          patchCord22(sine21, 0, transmitWav1, 20);
// AudioConnection          patchCord23(sine22, 0, transmitWav1, 21);
// AudioConnection          patchCord24(sine23, 0, transmitWav1, 22);
// AudioConnection          patchCord25(sine24, 0, transmitWav1, 23);
// AudioConnection          patchCord26(sine25, 0, transmitWav1, 24);
// AudioConnection          patchCord27(sine26, 0, transmitWav1, 25);
// AudioConnection          patchCord28(sine27, 0, transmitWav1, 26);
// AudioConnection          patchCord29(sine28, 0, transmitWav1, 27);
// AudioConnection          patchCord30(sine29, 0, transmitWav1, 28);
// AudioConnection          patchCord31(sine30, 0, transmitWav1, 29);
// AudioConnection          patchCord32(sine31, 0, transmitWav1, 30);
// AudioConnection          patchCord33(sine32, 0, transmitWav1, 31);


void setup()
{
  console.begin();
  AudioMemory(120);

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
  sine29.frequency(1318.51);
  sine30.frequency(1396.91);
  sine31.frequency(1479.98);
  sine32.frequency(1567.98);

  uint8_t mac[6];
  teensyMAC(mac);
  console.log.printf("MAC: %02X:%02X:%02X:%02X:%02X:%02X\n", mac[0], mac[1], mac[2], mac[3], mac[4], mac[5]);
  Ethernet.begin(mac, ip);
  delay(1000);

  console.log.println("Connecting to server...");
  if(client.connect(remoteIp, audioPort))
  {
    console.ok.println("Connected");
  }
  else
  {
    console.error.println("Connection failed");
  }



  // if(Ethernet.hardwareStatus() == EthernetNoHardware)
  // {
  //   console.error.println("Ethernet shield was not found.  Sorry, can't run without hardware. :(");
  // }
  // else if(Ethernet.linkStatus() == LinkOFF)
  // {
  //   console.warning.println("Ethernet cable is not connected.");
  // }
  // else
  // {
  //   console.ok.println("Ethernet initialized.");
  // }

  // const size_t sz = 65536 * 8;
  // const AudioBuffer::bufType bufMem = AudioBuffer::inExt;
  // if(transmitWav1.createBuffer(sz, bufMem))
  // {
  //   while(1)
  //   {
  //     Serial.println("Failed to create buffer");
  //     delay(500);
  //   }
  // }

  // if(!transmitWav1.begin(&Udp, remoteIp, audioPort))
  // {
  //   console.error.println("Transmit WAV buffered could not be initialized.");
  // }
  // else
  // {
  //   console.ok.println("Transmit WAV buffered initialized.");
  // }
}

static uint8_t buffer[1460] = "Hello, server!";

uint32_t bytesSent = 0;

void loop()
{
  

  // static float dataRateAvr = 0;
  // if(millis() < 10000)
  // {
  //   dataRateAvr = transmitWav1.getDataRate();
  // }
  // else
  // {
  //   dataRateAvr = dataRateAvr * 0.9 + transmitWav1.getDataRate() * 0.1;
  // }


  if(client.connected())
  {
    // client.println("Hello, server!"); // Send a packet
    if(client.write(buffer, sizeof(buffer)) != sizeof(buffer))
    {
      console.error.println("Failed to send packet");
    }
    else
    {
      console.log.println("Packet sent");
      bytesSent += sizeof(buffer);
    }
  }
  else
  {
    console.warning.println("Disconnected from server");
  }

  static int32_t t = 0;
  if(millis() - t > 1000)
  {
    t = millis();
    console.log.printf("Data rate: %f kbps\n", bytesSent * 8.0 / 1000.0);
    bytesSent = 0;
  }

  // delay(1000); // Wait for a second
}

