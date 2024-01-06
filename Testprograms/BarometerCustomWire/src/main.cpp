#include <Arduino.h>
#include <console.h>

#include <Adafruit_Sensor.h>
#include "Adafruit_BMP3XX.h"

#include <i2c_driver.h>
#include <i2c_driver_wire.h>

// [MAIN] I2C device found at address 0x14    -> PDM-TDM Converter 0
// [MAIN] I2C device found at address 0x15    -> PDM-TDM Converter 1
// [MAIN] I2C device found at address 0x16    -> PDM-TDM Converter 2
// [MAIN] I2C device found at address 0x17    -> PDM-TDM Converter 3
// [MAIN] I2C device found at address 0x19    -> Magnetometer
// [MAIN] I2C device found at address 0x1E    -> Accelerometer
// [MAIN] I2C device found at address 0x36    -> Angle sensor
// [MAIN] I2C device found at address 0x76    -> Ambient pressure & temperature sensor

Adafruit_BMP3XX bmp;


static I2CDriverWire customWire(Master, Slave);

void housekeeping(void);


#define SEALEVELPRESSURE_HPA (1013.25)

void setup() {
  console.begin();
  console.log.println("[MAIN] Starting up...");

  customWire.setHousekeepingCallback(housekeeping);

  if (!bmp.begin_I2C(0x76, &customWire)) {
    console.error.println("Could not find a valid BMP3 sensor, check wiring!");
  } else {
    console.ok.println("[MAIN] BMP3 sensor found!");
  }

  bmp.setTemperatureOversampling(BMP3_OVERSAMPLING_8X);
  bmp.setPressureOversampling(BMP3_OVERSAMPLING_4X);
  bmp.setIIRFilterCoeff(BMP3_IIR_FILTER_COEFF_3);
  bmp.setOutputDataRate(BMP3_ODR_50_HZ);
}

void loop() {
  threads.yield();

  static uint32_t t = 0;
  if (millis() - t > 100) {
    t = millis();
    // console.log.printf("[MAIN] Time: %lu\n", t);

    if (!bmp.performReading()) {
      console.error.println("Failed to perform reading :(");
      return;
    }

    console.log.printf(
        "[MAIN] Temperature = %5.2f *C, Pressure = %5.2f hPa, Altitude = %5.2f "
        "m\n",
        (float)bmp.temperature, (float)bmp.pressure / 100.0,
        (float)bmp.readAltitude(SEALEVELPRESSURE_HPA));
  }
}

void housekeeping(void)
{
  // console.log.println("[MAIN] Housekeeping...");
  threads.yield();
  // threads.delay(1);
}
