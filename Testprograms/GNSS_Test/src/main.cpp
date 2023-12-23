#include <Arduino.h>
#include <console.h>

#include <SparkFun_u-blox_GNSS_Arduino_Library.h>

SFE_UBLOX_GNSS myGNSS;

void setup()
{
  console.begin();
  console.log.println("[MAIN] Starting up...");

  Wire2.begin();
  Wire2.setClock(400000); // Increase I2C clock speed to 400kHz

  //myGNSS.enableDebugging(); // Uncomment this line to enable helpful debug messages on console.log

  if (myGNSS.begin(Wire2) == false) //Connect to the u-blox module using Wire port
  {
    console.error.println("[MAIN] u-blox GNSS not detected at default I2C address. Please check wiring. Freezing...");
    delay(10000);
  }
  else
  {
    console.ok.println("[MAIN] u-blox GNSS detected.");
  }

  myGNSS.setI2COutput(COM_TYPE_UBX); //Set the I2C port to output UBX only (turn off NMEA noise)
  myGNSS.saveConfigSelective(VAL_CFG_SUBSEC_IOPORT); //Save (only) the communications port settings to flash and BBR
  myGNSS.setNavigationFrequency(5); //Set output to 5 times a second
  byte rate = myGNSS.getNavigationFrequency(); //Get the update rate of this module
  console.log.print("Current update rate: ");
  console.log.println(rate);

  console.log.println(F("Compare Unix Epoch given with reference one from https://www.epochconverter.com/"));
}

void loop()
{
  threads.yield();

  static uint32_t t = 0;
  if(millis() - t > 1000)
  {
    t = millis();
    // console.log.printf("[MAIN] Time: %lu\n", t);

    long latitude = myGNSS.getLatitude();
    console.log.print(F("Lat: "));
    console.log.print(latitude);

    long longitude = myGNSS.getLongitude();
    console.log.print(F(" Long: "));
    console.log.print(longitude);
    console.log.print(F(" (degrees * 10^-7)"));

    long altitude = myGNSS.getAltitude();
    console.log.print(F(" Alt: "));
    console.log.print(altitude);
    console.log.print(F(" (mm)"));

    byte SIV = myGNSS.getSIV();
    console.log.print(F(" SIV: "));
    console.log.print(SIV);

    console.log.print(" ");
    console.log.print(myGNSS.getYear());
    console.log.print("-");
    console.log.print(myGNSS.getMonth());
    console.log.print("-");
    console.log.print(myGNSS.getDay());
    console.log.print(" ");
    console.log.print(myGNSS.getHour());
    console.log.print(":");
    console.log.print(myGNSS.getMinute());
    console.log.print(":");
    console.log.print(myGNSS.getSecond());
    console.log.print(" nanoseconds: ");
    console.log.print(myGNSS.getNanosecond()); // Nanoseconds can be negative

    myGNSS.flushPVT();

    console.log.println();
  }
}
