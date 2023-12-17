#include <Arduino.h>
// #include <console.h>
// #include <Audio.h>
// #include "Audio/transmit_wav_buffered.h"

#include <QNEthernet.h>
using namespace qindesign::network;

EthernetServer server(6666); // Port number for the server

void tcpThread(void* pvParameter);

size_t writeFully(EthernetClient &c, const uint8_t *buf, size_t size, uint32_t timeout) {
  uint32_t startT = millis();
  return qindesign::network::util::writeFully(c, buf, size, [&c, startT, timeout]()
  {
    return !static_cast<bool>(c) || (millis() - startT) >= timeout;
  });
}

// AudioSynthWaveformSine   sine1;
// AudioSynthWaveformSine   sine2;
// AudioSynthWaveformSine   sine3;
// AudioSynthWaveformSine   sine4;
// AudioSynthWaveformSine   sine5;
// AudioSynthWaveformSine   sine6;
// AudioSynthWaveformSine   sine7;
// AudioSynthWaveformSine   sine8;
// AudioSynthWaveformSine   sine9;
// AudioSynthWaveformSine   sine10;
// AudioSynthWaveformSine   sine11;
// AudioSynthWaveformSine   sine12;
// AudioSynthWaveformSine   sine13;
// AudioSynthWaveformSine   sine14;
// AudioSynthWaveformSine   sine15;
// AudioSynthWaveformSine   sine16;
// AudioSynthWaveformSine   sine17;
// AudioSynthWaveformSine   sine18;
// AudioSynthWaveformSine   sine19;
// AudioSynthWaveformSine   sine20;
// AudioSynthWaveformSine   sine21;
// AudioSynthWaveformSine   sine22;
// AudioSynthWaveformSine   sine23;
// AudioSynthWaveformSine   sine24;
// AudioSynthWaveformSine   sine25;
// AudioSynthWaveformSine   sine26;
// AudioSynthWaveformSine   sine27;
// AudioSynthWaveformSine   sine28;
// AudioSynthWaveformSine   sine29;
// AudioSynthWaveformSine   sine30;
// AudioSynthWaveformSine   sine31;
// AudioSynthWaveformSine   sine32;

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
  Serial.begin(0);
  // console.begin();
  // AudioMemory(120);

  IPAddress ip(192, 168, 40, 80);
  IPAddress subnet(255, 255, 255, 0);
  IPAddress gateway(192, 168, 40, 1);

  Ethernet.setLocalIP(ip);
  Ethernet.setSubnetMask(subnet);
  Ethernet.setGatewayIP(gateway);

  if(!Ethernet.begin(ip, subnet, gateway))
  {
    // console.println("Failed to configure Ethernet using static IP");
    // No point in proceeding, loop forever:
    while (true) {
      delay(1);
    }
  }
  server.begin();

  // console.print("Server is at ");
  // console.println(Ethernet.localIP());
  // console.println("Server started, waiting for clients...");

  // threads.addThread(tcpThread, nullptr, 2048);
}

void loop()
{
  // Ethernet.loop();
  tcpThread(nullptr);
}

void tcpThread(void* pvParameter)
{
  static uint8_t buffer[1024] = "Hello, server!";
  static uint32_t bytesSent = 0;

  while(true)
  {
    EthernetClient client = server.available();
    if (client) {
      // console.println("Client Connected");
      while(client.connected()) {
        // Send data as fast as possible
        // client.println("Hello from Teensy");
        // client.write(buffer, sizeof(buffer));

        static uint32_t millisLast = 0;
        uint32_t currentMillis = millis();
        if(millisLast != currentMillis)
        {
          millisLast = currentMillis;
          for(int i = 0; i < 5; i++)
          {
            uint32_t sent = writeFully(client, buffer, sizeof(buffer), 1000);
            // uint32_t sent = client.write(buffer, sizeof(buffer));
            // if(sent != sizeof(buffer))
            // {
            //   console.warning.printf("Failed to send all data: %d\n", sent);
            // }
            bytesSent += sent;
          }
        }

        // Optional: implement a small delay to control the data rate
        
        Ethernet.loop();
        // threads.yield();

        static uint32_t t = 0;
        if(millis() - t > 1000)
        {
          t = millis();
          Serial.printf("Sent: %f MBit/s\n", bytesSent * 8.0 / 1000000.0);
          bytesSent = 0;
        }
      }
      client.stop();
      // console.println("Client Disconnected");
    }
  }
}

