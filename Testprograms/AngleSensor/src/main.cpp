#include <Arduino.h>
#include <console.h>

// #include <Wire.h>
#include <AS5600.h>

AS5600 angleSensor(&Wire);

// [MAIN] I2C device found at address 0x14
// [MAIN] I2C device found at address 0x15
// [MAIN] I2C device found at address 0x16
// [MAIN] I2C device found at address 0x17
// [MAIN] I2C device found at address 0x19
// [MAIN] I2C device found at address 0x1e
// [MAIN] I2C device found at address 0x36
// [MAIN] I2C device found at address 0x76

void setup()
{
  console.begin();
  console.log.println("[MAIN] Starting up...");

  // Scan for I2C devices
  console.log.println("[MAIN] Scanning I2C bus...");
  byte error, address;
  int nDevices;

  Wire.begin();
  nDevices = 0;
  for(address = 1; address < 127; address++ )
  {
    Wire.beginTransmission(address);
    error = Wire.endTransmission();
    if (error == 0)
    {
      console.log.printf("[MAIN] I2C device found at address 0x%x\n", address);
      nDevices++;
    }
    else if (error==4)
    {
      console.log.printf("[MAIN] Unknown error at address 0x%x\n", address);
    }
  }

  angleSensor.begin();
  angleSensor.setDirection(AS5600_CLOCK_WISE);
  angleSensor.setOutputMode(AS5600_OUTMODE_PWM);
  if(!angleSensor.isConnected())
  {
    console.error.println("[MAIN] AS5600 not found!");
  }
  else
  {
    console.log.println("[MAIN] AS5600 found!");
  }
}

void loop()
{
  threads.yield();

  static uint32_t t = 0;
  if(millis() - t > 100)
  {
    t = millis();
    // console.log.printf("[MAIN] Time: %lu\n", t);

    console.log.printf("[MAIN] AS5600: %4d, detected: %d, tooWeek: %d, tooStrong: %d\n", 
      angleSensor.readAngle(), 
      angleSensor.detectMagnet(),
      angleSensor.magnetTooWeak(),
      angleSensor.magnetTooStrong());
  }
}
