/******************************************************************************
* file    hmi.cpp
*******************************************************************************
* brief   HMI functions to handle LEDs, buttons, etc.
*******************************************************************************
* author  Florian Baumgartner
* version 1.0
* date    2023-10-29
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

#include "hmi.h"
#include <TeensyThreads.h>
#include <console.h>

DMAMEM uint8_t Hmi::drawingMemory[Hmi::LED_COUNT * 3] = {};
DMAMEM uint8_t Hmi::displayMemory[Hmi::LED_COUNT * 12] = {};
uint64_t Hmi::timeNanoUtc = 0;
uint64_t Hmi::timeNanoUtcInitial = 0;
int64_t Hmi::tineNanoUtcOffset = 0;

FLASHMEM bool Hmi::begin(Utils& utilsRef)
{
  utils = &utilsRef;
  bool res = true;

  // Load settings from EEPROM
  ledsEnabled = utils->preferences.getBool("leds_on", ledsEnabled);
  ledsBrightness = utils->preferences.getUChar("leds_brg", ledsBrightness);
  ledsMode = (ledMode_t)utils->preferences.getUChar("leds_mode", (uint8_t)ledsMode);
  buzzerEnabled = utils->preferences.getBool("buzzer_on", buzzerEnabled);

  leds.clear();
  leds.begin();
  leds.setBrightness(ledsBrightness);
  threads.delay(5);    // Avoid flickering by waiting dor DMA to be ready
  leds.show();

  Utils::lockWire(Utils::hmiWire);
  if(!rtc.begin(&Utils::hmiWire))
  {
    console.error.println("[HMI] RTC could not be initialized");
    res = false;
  }
  if(rtc.lostPower())
  {
    console.warning.println("[HMI] RTC is NOT initialized, let's set the time!");
    rtc.adjust(DateTime(F(__DATE__), F(__TIME__)));
  }
  rtc.start();
  Utils::unlockWire(Utils::hmiWire);

  if(!buzzer.begin())
  {
    console.error.println("[HMI] Buzzer could not be initialized");
    res = false;
  }
  buzzer.setEnabled(buzzerEnabled);

  initialized = true;
  threads.addThread(update, (void*)this, 4096);
  console.ok.println("[HMI] Initialized");

  return res;
}

void Hmi::setTimeDate(uint16_t year, uint8_t month, uint8_t day, uint8_t hour, uint8_t minute, uint8_t second)
{
  this->year = year;
  this->month = month;
  this->day = day;
  this->hour = hour;
  this->min = minute;
  this->sec = second;
  DateTime time = DateTime(year, month, day, hour, minute, second);
  rtcUpdatePending = true;
  Utils::lockWire(Utils::hmiWire);
  rtc.adjust(time);
  Utils::unlockWire(Utils::hmiWire);
  rtcUpdatePending = false;
}

void Hmi::setBuzzerEnabled(bool enabled)
{
  buzzerEnabled = enabled;
  utils->preferences.putBool("buzzer_on", buzzerEnabled);
}

void Hmi::setLedsEnabled(bool enabled)
{
  ledsEnabled = enabled;
  utils->preferences.putBool("leds_on", ledsEnabled);
}

void Hmi::setLedsBrightness(uint8_t brightness)
{
  ledsBrightness = brightness;
  ledsBrightnessChanged = true;    // Don't write to EEPROM here, it will be done in the update thread
}

void Hmi::setLedsMode(ledMode_t mode)
{
  ledsMode = mode;
  utils->preferences.putUChar("leds_mode", (uint8_t)ledsMode);
}

void Hmi::update(void* parameter)
{
  Hmi* ref = (Hmi*)parameter;
  while(ref->initialized)
  {
    static uint32_t tSaveBrightness = 0;
    if(millis() - tSaveBrightness > 500)    // Save brightness not more often than every 500ms
    {
      tSaveBrightness = millis();
      if(ref->ledsBrightnessChanged)
      {
        ref->ledsBrightnessChanged = false;
        ref->utils->preferences.putUChar("leds_brg", ref->ledsBrightness);
      }
    }
    uint8_t brightnessMapped = map(ref->ledsBrightness, 0, 255, LEDS_MIN_BRIGHTNESS, LEDS_MAX_BRIGHTNESS);
    ref->leds.setBrightness(ref->ledsEnabled ? brightnessMapped : 0);    // Set LED brightness, turn off if disabled
    ref->leds.clear();
    if(ref->animationRampHandler())    // Switch to regular mode as soon as the ramping is done
    {
      uint32_t t = (uint32_t)(ref->getTimeNanoUtc() / 1000000ULL);
      if(ref->getGnssTimestamp)
      {
        if((ref->getGnssTimestamp() > 0) && ref->systemStatus == STATUS_GPS_FIX)
        {
          t = (uint32_t)(ref->getGnssTimestamp() / 1000000ULL);
        }
      }
      t %= 1000;    // 1s cycle

      bool blink = (t < 100);     // Blink 100ms on every second
      if(ref->streamingStatus)    // Blink a second time between 200ms and 300ms if streaming is active
      {
        blink |= (t >= 200) && (t < 300);
      }
      switch(ref->systemStatus)
      {
        case STATUS_GPS_FIX:
          ref->leds.setPixelColor(0, blink ? Color(0, 255, 0) : Color(0, 0, 0));
          break;
        case STATUS_GPS_NOFIX:
          ref->leds.setPixelColor(0, blink ? Color(255, 255, 255) : Color(0, 0, 0));
          break;
        case STATUS_WARNING:
          ref->leds.setPixelColor(0, (t % 500) < 250 ? Color(255, 255, 0) : Color(0, 0, 0));
          break;
        case STATUS_ERROR:
          ref->leds.setPixelColor(0, (t % 500) < 250 ? Color(255, 0, 0) : Color(0, 0, 0));
          break;
        default:
          break;
      }

      switch(ref->ledsMode)
      {
        case MODE_AUDIO:
          ref->animationAudio();
          break;
        case MODE_OST:
          ref->animationOst(blink);
          break;
        default:
          break;
      }
    }
    else    // Bootup animation
    {
      ref->animationBootup();
    }
    ref->leds.show();

    static uint32_t tRtc = 0;
    if((millis() - tRtc > (1000.0 / RTC_UPDATE_RATE)) && !ref->rtcUpdatePending)
    {
      tRtc = millis();
      Utils::lockWire(Utils::hmiWire);
      DateTime time = ref->rtc.now();
      Utils::unlockWire(Utils::hmiWire);
      if(time.year() >= 2024)    // Sometimes the RTC returns invalid data (can be identified by wrong year -> e.g. 2002)
      {
        ref->year = time.year();
        ref->month = time.month();
        ref->day = time.day();
        ref->hour = time.hour();
        ref->min = time.minute();
        ref->sec = time.second();
        DateTimeFields utc = {.sec = ref->sec,
                              .min = ref->min,
                              .hour = ref->hour,
                              .mday = ref->day,
                              .mon = (uint8_t)((int8_t)ref->month - 1),
                              .year = (uint8_t)(ref->year - 1900)};
        ref->timeNanoUtc = (uint64_t)makeTime(utc) * 1000000000ULL;
        if(ref->timeNanoUtcInitial == 0)    // Set initial time offset, TODO: do again if RTC Time has be set?
        {
          ref->timeNanoUtcInitial = ref->timeNanoUtc;
        }
      }
      else
      {
        console.warning.println("[HMI] Could not read RTC time (I2C-Bus lockup detected, resetting bus)");
        Utils::lockWire(Utils::hmiWire);
        Utils::turnOffWire(Utils::hmiWire);    // Somehow the I2C bus gets locked up after some time, force it to reset after each update
        delayMicroseconds(500);
        Utils::turnOnWire(Utils::hmiWire);
        Utils::unlockWire(Utils::hmiWire);
      }
    }
    ref->runPhaseLockedLoop();

    threads.delay(1000.0 / UPDATE_RATE);
  }
}

uint64_t Hmi::getTimeNanoUtc(void)
{
  return micros() * 1000ULL + timeNanoUtcInitial - tineNanoUtcOffset + 500000000ULL;    // Add 500ms to get ahead of center
}

uint8_t Hmi::calculateWeekDay(uint16_t year, uint8_t month, uint8_t day)
{
  if(month < 3)    // Check if Jan or Feb
  {
    month += 10;
    year -= 1;
  }
  else
  {
    month -= 2;
  }
  uint16_t iModYear = year % 100;
  uint16_t iDivYear = year / 100;
  uint16_t iResult = ((26 * month - 2) / 10 + day + iModYear + (iModYear / 4) + (iDivYear / 4) - 2 * iDivYear) % 7;    // Zellers Algorithm
  if(iResult == 0)
  {
    iResult = 7;
  }
  return iResult;    // 1 = Monday, 2 = Tuesday, ...
}

bool Hmi::isDaylightSavingTime(uint16_t year, uint8_t month, uint8_t day, uint8_t hour)
{
  if(month < 3 || month > 10)
    return false;    // No daylight saving time in Jan, Feb, Nov, Dec
  if(month > 3 && month < 10)
    return true;    // Daylight saving time in Apr, May, Jun, Jul, Aug, Sep
  if(((month == 3) && (hour + 24 * day) >= (1 + 24 * (31 - (5 * year / 4 + 4) % 7))) ||
     ((month == 10) && (hour + 24 * day) < (1 + 24 * (31 - (5 * year / 4 + 1) % 7))))
  {
    return true;
  }
  return false;
}

void Hmi::convertUtcToLocalTime(uint16_t& year, uint8_t& month, uint8_t& day, uint8_t& hour, uint8_t& minute, uint8_t& second, int8_t utcOffsetHour)
{
  month = constrain(month, 1, 12);
  int newHour = hour + utcOffsetHour;    // Adjust the hour with the UTC offset
  if(newHour >= 24)                      // Handle rolling over to the next or previous day
  {
    newHour -= 24;
    day += 1;
  }
  else if(newHour < 0)
  {
    newHour += 24;
    day -= 1;
  }
  hour = newHour;
  const int daysInMonth[] = {31, 28 + (isLeapYear(year) ? 1 : 0), 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};    // Handle month and year rollover
  if(day > daysInMonth[month - 1])                                                                            // Adjust month and day for rollover
  {
    day = 1;
    month += 1;
    if(month > 12)
    {
      month = 1;
      year += 1;
    }
  }
  else if(day < 1)
  {
    month -= 1;
    if(month < 1)
    {
      month = 12;
      year -= 1;
    }
    day = daysInMonth[month - 1];
  }
}

void Hmi::runPhaseLockedLoop(void)
{
  static int64_t errorSum = 0;
  int64_t rtcTime = timeNanoUtc - timeNanoUtcInitial;
  int64_t error = micros() * 1000ULL - (int64_t)(rtcTime + tineNanoUtcOffset);
  errorSum += error;
  tineNanoUtcOffset = PLL_KP * error + PLL_KI * errorSum;
}

bool Hmi::animationRampHandler(void)
{
  static uint8_t startupAnimationState = 0;
  static uint32_t t = millis();
  switch(startupAnimationState)
  {
    case 0:    // Initial ramp up
      brightnessModifier += ((float)millis() - (float)t) / (LEDS_RAMP_TIME * 1000.0);
      if(brightnessModifier >= 1.0)
      {
        brightnessModifier = 1.0;
        startupAnimationState++;
        t = millis();
      }
      break;

    case 1:    // Bootup
      if(systemStatus != STATUS_BOOTUP)
      {
        brightnessModifier = 1.0;
        startupAnimationState++;
        t = millis();
      }
      break;

    case 2:    // Ramping down
      brightnessModifier -= ((float)millis() - (float)t) / (LEDS_RAMP_TIME * 1000.0);
      if(brightnessModifier <= 0.0)
      {
        brightnessModifier = 0.0;
        startupAnimationState++;
        t = millis();
      }
      break;

    case 3:    // Off break
      if(millis() - t > LEDS_OFF_TIME * 1000)
      {
        brightnessModifier = 0.0;
        startupAnimationState++;
        t = millis();
      }
      break;

    case 4:    // Ramping up
      brightnessModifier += ((float)millis() - (float)t) / (LEDS_RAMP_TIME * 1000.0);
      if(brightnessModifier >= 1.0)
      {
        brightnessModifier = 1.0;
        startupAnimationState++;
        t = millis();
      }
      break;
    default:    // Normal operation
      brightnessModifier = 1.0;
      break;
  }
  return startupAnimationState >= 3;
}

void Hmi::animationBootup(void)
{
  static const float PEAK_MAX = 1.0;      // Max brightness at peak
  static const float PEAK_WIDTH = 1.5;    // Width of the parabola
  static const float VALUE_MIN = -1.5;
  static const float VALUE_MAX = 2.5;
  static const float FREQUENCY = 0.33;    // [Hz]
  static const float m = (VALUE_MAX - VALUE_MIN) * FREQUENCY;

  static uint32_t tInit = millis();
  float x = (((float)millis() - (float)tInit) / 1000.0) * m;
  x = fmod(x, VALUE_MAX - VALUE_MIN) + VALUE_MIN;

  for(int i = 0; i < 9; i++)
  {
    float r = RADIUS_DISTANCES[i];
    float value = 1.0 - (1.0 / PEAK_WIDTH) * (r - x) * (r - x);
    value = map(value, 0.0, 1.0, 0.0, PEAK_MAX);

    uint8_t red = 233 * value * brightnessModifier;
    uint8_t green = 30 * value * brightnessModifier;
    uint8_t blue = 99 * value * brightnessModifier;
    setLedColorByRadius(i, red, green, blue);
  }
}

void Hmi::animationAudio(void)
{
  if(getAudioPeak == nullptr)
  {
    return;
  }
  float peakLevels[32];
  for(int i = 0; i < sizeof(peakLevels) / sizeof(float); i++)
  {
    peakLevels[i] = constrain((1.21 / (1 + pow(2.71828, -7 * (getAudioPeak(i) - 0.232)))) - 0.2, 0.0, 1.0);    // Do some magic to get a nice curve
  }

  float innerCircle[16];
  for(int i = 0; i < 16; i++)
  {
    innerCircle[i] = 0.0;
  }

  for(int mic = 0; mic < 4; mic++)
  {
    for(int i = 0; i < 8; i++)
    {
      float volume = peakLevels[i * 4 + mic];
      innerCircle[i * 2] = max(innerCircle[i * 2], volume);
      uint8_t red = constrain((volume - 0.5) * 2.0, 0.0, 1.0) * 255 * brightnessModifier;
      uint8_t green = (1.0 - fabs(1.0 - volume * 2.0)) * 255 * brightnessModifier;
      uint8_t blue = 0 * brightnessModifier;
      int ledIndex = mic * 2 + i * 8 + 18;
      leds.setPixelColor(ledIndex, Color(red, green, blue));
      if(mic == 0)
      {
        leds.setPixelColor(ledIndex - 1, Color(red, green, blue));
      }
      if(mic < 3)
      {
        leds.setPixelColor(ledIndex + 1, Color(red, green, blue));
      }
    }
  }

  for(int i = 0; i < 8; i++)    // Interpolate values between mics on inner circle
  {
    innerCircle[i * 2 + 1] = (innerCircle[i * 2] + innerCircle[(i * 2 + 2) % 16]) / 2.0;
  }
  for(int i = 0; i < 16; i++)
  {
    float volume = innerCircle[i];
    uint8_t red = constrain((volume - 0.5) * 2.0, 0.0, 1.0) * 255 * brightnessModifier;
    uint8_t green = (1.0 - fabs(1.0 - volume * 2.0)) * 255 * brightnessModifier;
    uint8_t blue = 0 * brightnessModifier;
    leds.setPixelColor((i + 15) % 16 + 1, Color(red, green, blue));
  }
}

void Hmi::animationOst(bool blink)
{
  static const float PEAK_MAX = 0.5;
  static const float PEAK_MIN = 0.05;
  static const float PEAK_WIDTH = 0.25;
  static const float FREQUENCY = 0.33;    // [Hz]

  static uint32_t tInit = millis();
  float x = (((float)millis() - (float)tInit) / 1000.0) * FREQUENCY;
  x = fmod(x, 1.0) * 2.0 * PI;

  for(int i = 0; i < 9; i++)
  {
    float r = RADIUS_DISTANCES[i];
    float value = sinf((r * 2.0 * PI / PEAK_WIDTH) - x);
    value = map(value, -1.0, 1.0, PEAK_MIN, PEAK_MAX);

    uint8_t red = 233 * value * brightnessModifier;
    uint8_t green = 30 * value * brightnessModifier;
    uint8_t blue = 99 * value * brightnessModifier;
    setLedColorByRadius(i, red, green, blue);
  }

  if(blink)
  {
    setLedColorByRadius(8, 255 * brightnessModifier, 255 * brightnessModifier, 255 * brightnessModifier);
  }
}

void Hmi::setLedColorByRadius(int r, uint8_t red, uint8_t green, uint8_t blue)
{
  if(r < 0 || r > 8)
  {
    return;
  }
  if(r == 0)    // Check if inner circle
  {
    for(int i = 0; i < 16; i++)
    {
      leds.setPixelColor(i + 1, Color(red, green, blue));
    }
  }
  else
  {
    for(int i = 0; i < 8; i++)
    {
      leds.setPixelColor(i * 8 + r + 16, Color(red, green, blue));
    }
  }
}
