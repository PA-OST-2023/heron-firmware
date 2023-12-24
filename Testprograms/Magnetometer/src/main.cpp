#include <Arduino.h>
#include <console.h>

#include <Adafruit_LIS2MDL.h>
#include <Adafruit_LSM303_Accel.h>
#include <Adafruit_Sensor.h>

// [MAIN] I2C device found at address 0x14    -> PDM-TDM Converter 0
// [MAIN] I2C device found at address 0x15    -> PDM-TDM Converter 1
// [MAIN] I2C device found at address 0x16    -> PDM-TDM Converter 2
// [MAIN] I2C device found at address 0x17    -> PDM-TDM Converter 3
// [MAIN] I2C device found at address 0x19
// [MAIN] I2C device found at address 0x1e
// [MAIN] I2C device found at address 0x36    -> Angle sensor
// [MAIN] I2C device found at address 0x76    -> Ambient pressure & temperature sensor

Adafruit_LIS2MDL mag = Adafruit_LIS2MDL(12345);
Adafruit_LSM303_Accel_Unified accel = Adafruit_LSM303_Accel_Unified(54321);

void setup() {
  console.begin();
  console.log.println("[MAIN] Starting up...");

  if (!mag.begin(0x1E, &Wire)) {
    console.error.println("Ooops, no LIS2MDL detected ... Check your wiring!");
  } else {
    console.ok.println("[MAIN] LIS2MDL found!");
  }

  if (!accel.begin(0x19, &Wire)) {
    console.error.println(
        "Ooops, no LSM303 Accelerometer detected ... Check your wiring!");
  } else {
    console.ok.println("[MAIN] LSM303 found!");
  }

  mag.printSensorDetails();
}

void loop() {
  threads.yield();

  static uint32_t t = 0;
  if (millis() - t > 100) {
    t = millis();
    // console.log.printf("[MAIN] Time: %lu\n", t);

    sensors_event_t event;
    mag.getEvent(&event);

    float Pi = 3.14159;

    // Calculate the angle of the vector y,x
    float heading = (atan2(event.magnetic.y, event.magnetic.x) * 180) / Pi;

    // Normalize to 0-360
    if (heading < 0) {
      heading = 360 + heading;
    }
    if (heading > 360) {
      heading = heading - 360;
    }
    // console.log.print("Compass Heading: ");
    Serial.println(heading);

    // sensors_event_t a, m;
    // accel.getEvent(&a);
    // mag.getEvent(&m);

    // Serial.print("Accelerometer ");
    // Serial.print("X: "); Serial.print(a.acceleration.x, 1); Serial.print(" m/s^2, ");
    // Serial.print("Y: "); Serial.print(a.acceleration.y, 1); Serial.print(" m/s^2, ");
    // Serial.print("Z: "); Serial.print(a.acceleration.z, 1); Serial.println(" m/s^2");

    // console.log.printf("%f;%f;%f;%f;%f;%f\n", t, a.acceleration.x, a.acceleration.y, a.acceleration.z, m.magnetic.x, m.magnetic.y, m.magnetic.z);
  }
}
