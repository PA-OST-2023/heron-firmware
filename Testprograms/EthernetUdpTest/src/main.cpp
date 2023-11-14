#include <Arduino.h>
#include <NativeEthernet.h>
#include <NativeEthernetUdp.h>
#include <console.h>


void teensyMAC(uint8_t *mac)
{
  for(uint8_t by=0; by<2; by++) mac[by]=(HW_OCOTP_MAC1 >> ((1-by)*8)) & 0xFF;
  for(uint8_t by=0; by<4; by++) mac[by+2]=(HW_OCOTP_MAC0 >> ((3-by)*8)) & 0xFF;
}

IPAddress ip(192, 168, 33, 10);
IPAddress remoteIp(192, 168, 33, 30);
EthernetUDP Udp;

unsigned int localPort = 8888;
char packetBuffer[UDP_TX_PACKET_MAX_SIZE];  // buffer to hold incoming packet

void setup()
{
  console.begin();

  uint8_t mac[6];
  teensyMAC(mac);
  console.log.printf("MAC: %02X:%02X:%02X:%02X:%02X:%02X\n", mac[0], mac[1], mac[2], mac[3], mac[4], mac[5]);
  Ethernet.begin(mac, ip);

  if(Ethernet.hardwareStatus() == EthernetNoHardware)
  {
    console.error.println("Ethernet shield was not found.  Sorry, can't run without hardware. :(");
  }
  else if(Ethernet.linkStatus() == LinkOFF)
  {
    console.warning.println("Ethernet cable is not connected.");
  }
  else
  {
    console.ok.println("Ethernet initialized.");
  }

  Udp.begin(localPort);
  console.ok.println("UDP initialized.");
}

void loop()
{
  const char* message = "Hello World";
  Udp.beginPacket(remoteIp, localPort);
  Udp.write(message);
  Udp.endPacket();

  delay(1000);
  console.log.println("Sent message");
}

