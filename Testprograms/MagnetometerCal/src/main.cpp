#include <Arduino.h>
#include <console.h>

#include <Adafruit_LIS2MDL.h>
#include <Adafruit_LSM303_Accel.h>
// #include <Adafruit_Sensor.h>

#include "magCal/imuread.h"

// #include <Adafruit_SensorLab.h>
// #include <Adafruit_Sensor_Calibration.h>

static constexpr double DEGREES_PER_RADIAN =
  (180.0 / 3.141592653589793238463);    ///< Degrees per radian for conversion

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
sensors_event_t accel_event, mag_event;

bool calibrated = false;

void updateQuality(void);
float calculateOrientation(float x, float y, float z);

void setup()
{
  pinMode(13, OUTPUT);
  bool res = console.begin();
  digitalWrite(13, res);
  console.log.println("[MAIN] Starting up...");

  if(!mag.begin(0x1E, &Wire))
  {
    console.error.println("Ooops, no LIS2MDL detected");
  }
  else
  {
    console.ok.println("[MAIN] LIS2MDL found!");
  }

  if(!accel.begin(0x19, &Wire))
  {
    console.error.println("Ooops, no LSM303 Accelerometer detected");
  }
  else
  {
    console.ok.println("[MAIN] LSM303 found!");
  }

  // threads.delay(4500);
  console.log.println("[MAIN] Starting MagCal...");
  raw_data_reset();
}

void loop()
{
  threads.yield();

  static uint32_t t = 0;
  if(millis() - t > 250)
  {
    t = millis();
    // console.log.printf("[MAIN] Time: %lu\n", t);
  }

  if(!accel.getEvent(&accel_event))
  {
    return;
  }
  if(!mag.getEvent(&mag_event))
  {
    return;
  }

  if(!calibrated)
  {
    static int16_t ascii_raw_data[9] = {0, 0, 0, 0, 0, 0, 0, 0, 0};
    ascii_raw_data[0] = int16_t(accel_event.acceleration.x * 8192 / 9.8);
    ascii_raw_data[1] = int16_t(accel_event.acceleration.y * 8192 / 9.8);
    ascii_raw_data[2] = int16_t(accel_event.acceleration.z * 8192 / 9.8);
    ascii_raw_data[6] = int16_t(mag_event.magnetic.x * 10.0);
    ascii_raw_data[7] = int16_t(mag_event.magnetic.y * 10.0);
    ascii_raw_data[8] = int16_t(mag_event.magnetic.z * 10.0);
    raw_data(ascii_raw_data);
    updateQuality();

    if(quality_surface_gap_error() < 1.0)
    {
      console.ok.println("[MAIN] Calibration complete!");
      calibrated = true;
    }

    console.log.printf(
      "[MAIN] Offset: %.2f, %.2f, %.2f\t Gaps: %.2f, Variance: %.2f, Wobble: "
      "%.2f, Fit Error: %.2f\n",
      magcal.V[0], magcal.V[1], magcal.V[2], quality_surface_gap_error(), quality_magnitude_variance_error(),
      quality_wobble_error(), quality_spherical_fit_error());
  }
  else
  {
    static const float alpha = 0.1;
    static float heading = -1;
    if(heading < 0)
    {
      heading = calculateOrientation(mag_event.magnetic.x, mag_event.magnetic.y, mag_event.magnetic.z);
    }
    else
    {
      heading = alpha * heading +
                (1 - alpha) * calculateOrientation(mag_event.magnetic.x, mag_event.magnetic.y, mag_event.magnetic.z);
    }
    console.log.printf("[MAIN] Orientation: %.0f\n", heading);
  }
}

void updateQuality(void)
{
  static int invert_q0 = 0;
  static int invert_q1 = 0;
  static int invert_q2 = 0;
  static int invert_q3 = 1;

  int i;
  // float xscale, yscale, zscale;
  // float xoff, yoff, zoff;
  float rotation[9];
  Point_t point, draw;
  Quaternion_t orientation;

  quality_reset();
  // xscale = 0.05;
  // yscale = 0.05;
  // zscale = 0.05;
  // xoff = 0.0;
  // yoff = 0.0;
  // zoff = -7.0;

  memcpy(&orientation, &current_orientation, sizeof(orientation));
  // TODO: this almost but doesn't perfectly seems to get the
  //  real & screen axes in sync....
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

float calculateOrientation(float x, float y, float z)
{
  // Hard-iron calibration settings
  float hard_iron[3] = {magcal.V[0], magcal.V[1], magcal.V[2]};

  // Soft-iron calibration settings
  float soft_iron[3][3] = {{magcal.invW[0][0], magcal.invW[0][1], magcal.invW[0][2]},
                           {magcal.invW[1][0], magcal.invW[1][1], magcal.invW[1][2]},
                           {magcal.invW[2][0], magcal.invW[2][1], magcal.invW[2][2]}};    // Inverse of W

  // Magnetic declination from magnetic-declination.com
  // East is positive ( ), west is negative (-)
  // mag_decl = ( /-)(deg   min/60   sec/3600)
  // Set to 0 to get magnetic heading instead of geo heading
  const float mag_decl = 3.0833;    // https://www.ngdc.noaa.gov/geomag/calculators/magcalc.shtml#declination

  float mag_data[] = {x, y, z};

  static float hi_cal[3];
  static float heading = 0;

  // Apply hard-iron offsets
  for(uint8_t i = 0; i < 3; i++)
  {
    hi_cal[i] = mag_data[i] - hard_iron[i];
  }

  // Apply soft-iron scaling
  for(uint8_t i = 0; i < 3; i++)
  {
    mag_data[i] = (soft_iron[i][0] * hi_cal[0]) + (soft_iron[i][1] * hi_cal[1]) + (soft_iron[i][2] * hi_cal[2]);
  }

  // Calculate angle for heading, assuming board is parallel to
  // the ground and  Y points toward heading.
  heading = -1 * (atan2(mag_data[0], mag_data[1]) * 180) / M_PI;

  heading -= 90.0;    // Ajdusting sensor orientation to match the board

  // Apply magnetic declination to convert magnetic heading
  // to geographic heading
  heading += mag_decl;

  // Convert heading to 0..360 degrees
  if(heading < 0)
  {
    heading += 360;
  }
  return heading;
}