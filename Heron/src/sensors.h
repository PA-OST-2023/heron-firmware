/******************************************************************************
* file    sensors.h
*******************************************************************************
* brief   Sensor Utility class
*******************************************************************************
* author  Florian Baumgartner
* version 1.0
* date    2023-12-29
*******************************************************************************
* MIT License
*
* Copyright (c) 2023 ICAI Interdisciplinary Center for Artificial Intelligence
*
* Permission is hereby granted, free of charge, to any person obtaining a copy
* of this software and associated documentation files (the "Software"), to deal
* in the Software without restriction, including without limitation the rights
* to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
* copies of the Software, and to permit persons to whom the Software is
* furnished to do so, subject to the following conditions:
*
* The above copyright notice and this permission notice shall be included in
* all copies or substantial portions of the Software.
*
* THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
* IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
* FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
* AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
* LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
* OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
* SOFTWARE.
******************************************************************************/

// Magnetic declination from https://www.ngdc.noaa.gov/geomag/calculators/magcalc.shtml#declination
// East is positive ( ), west is negative (-)
// mag_decl = ( /-)(deg   min/60   sec/3600)
// Set to 0 to get magnetic heading instead of geo heading

#ifndef SENSORS_H
#define SENSORS_H

#include <AS5600.h>
#include <Adafruit_LIS2MDL.h>
#include <Adafruit_LSM303_Accel.h>
#include <Adafruit_Sensor.h>
#include <Arduino.h>
#include <utils.h>
#include "Adafruit_BMP3XX.h"

#define SENSOR_WIRE Wire    // Wire interface to use

class Sensors
{
 public:
  static constexpr const float UPDATE_RATE = 10.0;                       // Hz
  static constexpr const size_t ACCEL_UPDATE_RATE = 10;                  // [Hz] Update rate for accelerometer
  static constexpr const size_t MAGNETOMETER_UPDATE_RATE = 10;           // [Hz] Update rate for magnetometer
  static constexpr const size_t BAROMETER_UPDATE_RATE = 5;               // [Hz] Update rate for barometer
  static constexpr const size_t ANGLE_SENSOR_UPDATE_RATE = 10;           // [Hz] Update rate for angle sensor
  static constexpr const size_t MAX_SENSOR_READOUT_DELAY = 25;           // [ms] Maximum delay for sensor readout
  static constexpr const double DEGREES_PER_RADIAN = (180.0 / M_PI);     // Degrees per radian for conversion
  static constexpr const float MAGNETIC_DECLINATION = 3.0833;            // Magnetic declination in degrees for Zurich CH
  static constexpr const float HEADING_FILTER_ALPHA = 0.3;               // Filter alpha for heading (0.0 = no change, 1.0 = no filter)
  static constexpr const float PITCH_ROLL_FILTER_ALPHA = 0.5;            // Filter alpha for pitch and roll (0.0 = no change, 1.0 = no filter)
  static constexpr const float CALIBRATION_COVERAGE_THRESHOLD = 97.0;    // [%] Threshold for calibration coverage
  static constexpr const float SEA_LEVEL_PRESSURE_HPA = 1013.25;         // [hPa] Sea level pressure for altitude calculation
  static constexpr const uint8_t ADDR_MAGNETOMETER = 0x1E;               // I2C address of the magnetometer (LIS2MDL)
  static constexpr const uint8_t ADDR_ACCELEROMETER = 0x19;              // I2C address of the accelerometer (LSM303AGR)
  static constexpr const uint8_t ADDR_BAROMETER = 0x76;                  // I2C address of the barometer (BMP388)


  Sensors() {}
  bool begin(Utils& utilsRef);
  float getHeading(void) { return heading; }
  float getPitch(void) { return pitch; }
  float getRoll(void) { return roll; }
  float getTemperature(void) { return temperature; }
  float getPressure(void) { return pressure; }
  float getAltitude(void) { return altitude; }
  float getAngle(void) { return angle; }
  uint16_t getAngleRaw(void) { return angleRaw; }
  bool isMagnetDetected(void) { return magnetDetected; }
  bool isMagnetTooWeak(void) { return magnetTooWeak; }
  bool isMagnetTooStrong(void) { return magnetTooStrong; }
  void startCalibration(void) { calibrationStarted = true; }
  void abortCalibration(void) { calibrationAborted = true; }
  bool isCalibrationDone(void) { return calibrationDone; }
  float getCalibCoverage(void) { return calibCoverage; }
  float getCalibVariance(void) { return calibVariance; }
  float getCalibWobbleError(void) { return calibWobbleError; }
  float getCalibFitError(void) { return calibFitError; }

  static void update(void* parameter);


 private:
  Utils* utils = nullptr;

  Adafruit_LIS2MDL mag = Adafruit_LIS2MDL(12345);
  Adafruit_LSM303_Accel_Unified accel = Adafruit_LSM303_Accel_Unified(54321);
  AS5600 angleSensor = AS5600(&SENSOR_WIRE);
  Adafruit_BMP3XX baro;
  sensors_event_t accel_event, mag_event;

  float heading = 0.0;
  float pitch = 0.0;
  float roll = 0.0;
  float temperature = 0.0;
  float pressure = 0.0;
  float altitude = 0.0;

  float angle = 0.0;
  uint16_t angleRaw = 0;
  bool magnetDetected = false;
  bool magnetTooWeak = false;
  bool magnetTooStrong = false;

  bool calibrationStarted = false;
  bool calibrationAborted = false;
  bool calibrationRunning = false;
  bool calibrationDone = false;

  float calibCoverage = 0.0;
  float calibVariance = 0.0;
  float calibWobbleError = 0.0;
  float calibFitError = 0.0;

  float hardIron[3] = {0.0, 0.0, 0.0};
  float softIron[3][3] = {{1.0, 0.0, 0.0}, {0.0, 1.0, 0.0}, {0.0, 0.0, 1.0}};

  bool magInitialized = false;
  bool accelInitialized = false;
  bool baroInitialized = false;
  bool angleSensorInitialized = false;
  volatile bool initialized = false;

  // static void update(void* parameter);

  float calculatePitch(float x, float y, float z);
  float calculateRoll(float x, float y, float z);
  float calculateHeading(float x, float y, float z);
  float calculateHeadingCompensated(float x, float y, float z, float pitch, float roll);
  void calibrate(float x, float y, float z);
  void calculateCalibrationQuality(void);
  bool updateAndSaveCalibration(void);
};

#endif