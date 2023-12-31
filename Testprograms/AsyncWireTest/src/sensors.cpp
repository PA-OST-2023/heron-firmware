/******************************************************************************
* file    sensors.cpp
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

#include "sensors.h"
#include <TeensyThreads.h>
#include <console.h>
#include "magCal/imuread.h"

FLASHMEM bool Sensors::begin(Utils& utilsRef)
{
  utils = &utilsRef;
  bool res = true;

  Utils::lockWire(SENSOR_WIRE);
  if(!mag.begin(ADDR_MAGNETOMETER, &SENSOR_WIRE))
  {
    console.error.println("[SENSORS] Magnetometer could not be initialized");
    res = false;
  }
  mag.setDataRate(lis2mdl_rate_t::LIS2MDL_RATE_20_HZ);
  if(!accel.begin(ADDR_ACCELEROMETER, &SENSOR_WIRE))
  {
    console.error.println("[SENSORS] Accelerometer could not be initialized");
    res = false;
  }
  accel.setRange(lsm303_accel_range_t::LSM303_RANGE_2G);
  accel.setMode(lsm303_accel_mode_t::LSM303_MODE_HIGH_RESOLUTION);
  Utils::unlockWire(SENSOR_WIRE);

  raw_data_reset();    // Reset calibration stack

  // Load calibration data from Preferences (set to default values if not available)
  hardIron[0] = utils->preferences.getFloat("mag_h0", hardIron[0]);
  hardIron[1] = utils->preferences.getFloat("mag_h1", hardIron[1]);
  hardIron[2] = utils->preferences.getFloat("mag_h2", hardIron[2]);

  softIron[0][0] = utils->preferences.getFloat("mag_s00", softIron[0][0]);
  softIron[0][1] = utils->preferences.getFloat("mag_s01", softIron[0][1]);
  softIron[0][2] = utils->preferences.getFloat("mag_s02", softIron[0][2]);
  softIron[1][0] = utils->preferences.getFloat("mag_s10", softIron[1][0]);
  softIron[1][1] = utils->preferences.getFloat("mag_s11", softIron[1][1]);
  softIron[1][2] = utils->preferences.getFloat("mag_s12", softIron[1][2]);
  softIron[2][0] = utils->preferences.getFloat("mag_s20", softIron[2][0]);
  softIron[2][1] = utils->preferences.getFloat("mag_s21", softIron[2][1]);
  softIron[2][2] = utils->preferences.getFloat("mag_s22", softIron[2][2]);

  initialized = true;
  // threads.addThread(update, (void*)this, 4096);
  console.ok.println("[SENORS] Initialized");

  return res;
}

void Sensors::update(void* parameter)
{
  Sensors* ref = (Sensors*)parameter;
  //while(ref->initialized)
  {
    if(ref->calibrationAborted)
    {
      ref->calibrationDone = false;
      ref->calibrationStarted = false;
      ref->calibrationRunning = false;
      ref->calibrationAborted = false;
      console.warning.println("[SENSORS] Magnetometer calibration aborted");
    }
    if(ref->calibrationStarted)
    {
      ref->calibrationDone = false;
      ref->calibrationStarted = false;
      ref->calibrationRunning = true;
      ref->calibCoverage = 0.0;
      ref->calibVariance = 0.0;
      ref->calibWobbleError = 0.0;
      ref->calibFitError = 0.0;
      raw_data_reset();    // Reset calibration stack
      console.log.println("[SENSORS] Starting magnetometer calibration...");
    }

    // Utils::lockWire(SENSOR_WIRE);

    static uint32_t tAcc = 0;
    if(millis() - tAcc > (1000.0 / ACCEL_UPDATE_RATE))
    {
      tAcc = millis();
      if(ref->accel.getEvent(&ref->accel_event))    // Check if accelerometer has new data
      {
        float pitch = ref->calculatePitch(ref->accel_event.acceleration.x, ref->accel_event.acceleration.y, ref->accel_event.acceleration.z);
        ref->pitch = (ref->PITCH_ROLL_FILTER_ALPHA * pitch) + ((1.0 - ref->PITCH_ROLL_FILTER_ALPHA) * ref->pitch);
        float roll = ref->calculateRoll(ref->accel_event.acceleration.x, ref->accel_event.acceleration.y, ref->accel_event.acceleration.z);
        ref->roll = (ref->PITCH_ROLL_FILTER_ALPHA * roll) + ((1.0 - ref->PITCH_ROLL_FILTER_ALPHA) * ref->roll);
        console.log.printf("[SENSORS] Time: %d -> Pitch: %f, Roll: %f\n", millis() - tAcc, ref->pitch, ref->roll);
      }
    }

    static uint32_t tMag = 0;
    if(!ref->calibrationRunning)    // Normal operation
    {
      if(millis() - tMag > (1000.0 / HEADING_UPDATE_RATE))
      {
        tMag = millis();
        if(ref->mag.getEvent(&ref->mag_event))    // Check if magnetometer has new data
        {
          float newHeading =
            ref->calculateHeadingCompensated(ref->mag_event.magnetic.x, ref->mag_event.magnetic.y, ref->mag_event.magnetic.z, ref->pitch, ref->roll);
          float diff = newHeading - ref->heading;    // Compute the difference in heading, adjusting for the 360 degree wrap-around
          if(diff > 180.0f)
          {
            diff -= 360.0f;
          }
          else if(diff < -180.0f)
          {
            diff += 360.0f;
          }
          ref->heading += ref->HEADING_FILTER_ALPHA * diff;    // Apply the alpha coefficient to the difference
          if(ref->heading < 0.0f)                              // Ensure the heading is within 0 to 360 degrees
          {
            ref->heading += 360.0f;
          }
          else if(ref->heading >= 360.0f)
          {
            ref->heading -= 360.0f;
          }
          console.log.printf("[SENSORS] Time: %d -> Heading: %f\n", millis() - tMag, ref->heading);
        }
      }
    }
    else if(millis() - tMag > (1000 / CALIBRATION_UPDATE_RATE))    // Calibration mode
    {
      tMag = millis();
      if(ref->mag.getEvent(&ref->mag_event))    // Check if magnetometer has new data
      {
        ref->calibrate(ref->mag_event.magnetic.x, ref->mag_event.magnetic.y, ref->mag_event.magnetic.z);
        float coverage = 100.0 - quality_surface_gap_error();
        ref->calibCoverage = constrain(map(coverage, 0.0, CALIBRATION_COVERAGE_THRESHOLD, 0.0, 100.0), 0.0, 100.0);
        ref->calibFitError = constrain(quality_spherical_fit_error(), 0.0, 100.0);
        ref->calibWobbleError = constrain(quality_wobble_error(), 0.0, 100.0);
        ref->calibVariance = quality_magnitude_variance_error();

        if(coverage >= CALIBRATION_COVERAGE_THRESHOLD)    // Check if calibration is done
        {
          console.ok.println("[SENSORS] Calibration completed!");
          ref->calibrationDone = true;
          ref->calibrationRunning = false;
          if(!ref->updateAndSaveCalibration())
          {
            console.error.println("[SENSORS] Calibration could not be saved");
          }
          else
          {
            console.ok.println("[SENSORS] Calibration saved");
          }
        }
      }
    }
    // Utils::unlockWire(SENSOR_WIRE);

    // threads.delay(1000.0 / UPDATE_RATE);
  }
}

float Sensors::calculatePitch(float x, float y, float z)
{
  float p = -atan2f(x, sqrtf(y * y + z * z)) * 180.0 / M_PI;
  return constrain(p, -90.0, 90.0);
}

float Sensors::calculateRoll(float x, float y, float z)
{
  float r = -atan2f(y, sqrtf(x * x + z * z)) * 180.0 / M_PI;
  return constrain(r, -90.0, 90.0);
}

float Sensors::calculateHeading(float x, float y, float z)
{
  float mag_data[] = {x, y, z};
  static float hi_cal[3];

  for(uint8_t i = 0; i < 3; i++)    // Apply hard-iron offsets
  {
    hi_cal[i] = mag_data[i] - hardIron[i];
  }
  for(uint8_t i = 0; i < 3; i++)    // Apply soft-iron scaling
  {
    mag_data[i] = (softIron[i][0] * hi_cal[0]) + (softIron[i][1] * hi_cal[1]) + (softIron[i][2] * hi_cal[2]);
  }
  float heading = -1 * (atan2f(mag_data[0], mag_data[1]) * 180) / M_PI;
  heading -= 90.0;                    // Ajdusting sensor orientation to match the board
  heading += MAGNETIC_DECLINATION;    // Adjust for magnetic declination
  if(heading < 0)                     // Convert heading to 0..360 degrees
  {
    heading += 360;
  }
  return heading;
}

float Sensors::calculateHeadingCompensated(float x, float y, float z, float pitch, float roll)
{
  float mag_data[3] = {x, y, z};
  float hi_cal[3];

  for(uint8_t i = 0; i < 3; i++)    // Apply hard-iron offsets
  {
    hi_cal[i] = mag_data[i] - hardIron[i];
  }
  for(uint8_t i = 0; i < 3; i++)    // Apply soft-iron scaling
  {
    mag_data[i] = (softIron[i][0] * hi_cal[0]) + (softIron[i][1] * hi_cal[1]) + (softIron[i][2] * hi_cal[2]);
  }
  float pitchRad = pitch * M_PI / 180.0;    // Convert pitch and roll to radians
  float rollRad = roll * M_PI / 180.0;
  float xh = mag_data[0] * cosf(pitchRad) + mag_data[2] * sinf(pitchRad);    // Adjust the magnetic field vector for pitch and roll
  float yh = mag_data[0] * sinf(rollRad) * sinf(pitchRad) + mag_data[1] * cosf(rollRad) - mag_data[2] * sinf(rollRad) * cosf(pitchRad);

  float heading = -1 * atan2f(xh, yh) * 180.0 / M_PI;    // Calculate the heading
  heading -= 90.0;                                       // Adjusting for sensor orientation, if needed
  heading += MAGNETIC_DECLINATION;                       // Adjust for magnetic declination
  if(heading < 0)                                        // Convert heading to 0..360 degrees
  {
    heading += 360;
  }
  else if(heading > 360)
  {
    heading -= 360;
  }
  return heading;
}


void Sensors::calibrate(float x, float y, float z)
{
  static int16_t ascii_raw_data[9] = {0, 0, 0, 0, 0, 0, 0, 0, 0};
  ascii_raw_data[6] = int16_t(x * 10.0);
  ascii_raw_data[7] = int16_t(y * 10.0);
  ascii_raw_data[8] = int16_t(z * 10.0);
  raw_data(ascii_raw_data);
  calculateCalibrationQuality();
}

void Sensors::calculateCalibrationQuality(void)
{
  static int invert_q0 = 0;
  static int invert_q1 = 0;
  static int invert_q2 = 0;
  static int invert_q3 = 1;
  int i;
  float rotation[9];
  Point_t point, draw;
  Quaternion_t orientation;
  quality_reset();
  memcpy(&orientation, &current_orientation, sizeof(orientation));
  if(invert_q0)
    orientation.q0 *= -1.0f;
  if(invert_q1)
    orientation.q1 *= -1.0f;
  if(invert_q2)
    orientation.q2 *= -1.0f;
  if(invert_q3)
    orientation.q3 *= -1.0f;
  quad_to_rotation(&orientation, rotation);
  for(i = 0; i < MAGBUFFSIZE; i++)
  {
    if(magcal.valid[i])
    {
      apply_calibration(magcal.BpFast[0][i], magcal.BpFast[1][i], magcal.BpFast[2][i], &point);
      quality_update(&point);
      rotate(&point, &draw, rotation);
    }
  }
}

bool Sensors::updateAndSaveCalibration(void)
{
  hardIron[0] = magcal.V[0];
  hardIron[1] = magcal.V[1];
  hardIron[2] = magcal.V[2];

  softIron[0][0] = magcal.invW[0][0];
  softIron[0][1] = magcal.invW[0][1];
  softIron[0][2] = magcal.invW[0][2];
  softIron[1][0] = magcal.invW[1][0];
  softIron[1][1] = magcal.invW[1][1];
  softIron[1][2] = magcal.invW[1][2];
  softIron[2][0] = magcal.invW[2][0];
  softIron[2][1] = magcal.invW[2][1];
  softIron[2][2] = magcal.invW[2][2];

  bool res = true;
  res &= utils->preferences.putFloat("mag_h0", hardIron[0]);
  res &= utils->preferences.putFloat("mag_h1", hardIron[1]);
  res &= utils->preferences.putFloat("mag_h2", hardIron[2]);

  res &= utils->preferences.putFloat("mag_s00", softIron[0][0]);
  res &= utils->preferences.putFloat("mag_s01", softIron[0][1]);
  res &= utils->preferences.putFloat("mag_s02", softIron[0][2]);
  res &= utils->preferences.putFloat("mag_s10", softIron[1][0]);
  res &= utils->preferences.putFloat("mag_s11", softIron[1][1]);
  res &= utils->preferences.putFloat("mag_s12", softIron[1][2]);
  res &= utils->preferences.putFloat("mag_s20", softIron[2][0]);
  res &= utils->preferences.putFloat("mag_s21", softIron[2][1]);
  res &= utils->preferences.putFloat("mag_s22", softIron[2][2]);

  return res;
}
