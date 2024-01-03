/******************************************************************************
* file    gui.cpp
*******************************************************************************
* brief   Wrapper for GUI interface (lvgl, touch, display, etc.)
*******************************************************************************
* author  Florian Baumgartner
* version 1.0
* date    2023-10-23
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

#include "gui.h"
#include <TeensyThreads.h>
#include <static_malloc.h>
#include "Gui/generated/gui_guider.h"

DMAMEM lv_ui guider_ui;
DMAMEM lv_color_t Gui::buf[Gui::SCREEN_WIDTH * Gui::SCREEN_BUFFER_HEIGHT];
Utils* Gui::utils;
Hmi* Gui::hmi;
AudioUtils* Gui::audioUtils;
Sensors* Gui::sensors;
EthernetUtils* Gui::ethernetUtils;

Gui::Gui(int sclk, int mosi, int cs, int dc, int bl, int tch_irq) : sclk(sclk), mosi(mosi), cs(cs), dc(dc), bl(bl), tch_irq(tch_irq) {}

FLASHMEM bool Gui::begin(Utils& utilsRef, Hmi& hmiRef, AudioUtils& audioUtilsRef, EthernetUtils& ethernetUtilsRef, Sensors& sensorsRef)
{
  bool res = true;
  utils = &utilsRef;
  hmi = &hmiRef;
  audioUtils = &audioUtilsRef;
  ethernetUtils = &ethernetUtilsRef;
  sensors = &sensorsRef;

  digitalWrite(bl, LOW);
  pinMode(bl, OUTPUT);

  console.log.println("[GUI] Initializing display... ");
  disp.begin(SPI_FREQUENCY, GC9A01A_SPICLOCK_READ);
  disp.fillScreen(GC9A01A_BLACK);

  Utils::lockWire(GUI_WIRE);
  if(!touch.begin())
  {
    console.error.println("[GUI] Touch controller could not be initialized");
    res = false;
  }
  Utils::unlockWire(GUI_WIRE);

  lv_log_register_print_cb(lvglPrint);
  lv_init();

  static lv_disp_draw_buf_t draw_buf;
  lv_disp_draw_buf_init(&draw_buf, buf, NULL, SCREEN_WIDTH * SCREEN_BUFFER_HEIGHT);
  disp.setFrameBuffer((uint16_t*)buf);

  static lv_disp_drv_t disp_drv;
  lv_disp_drv_init(&disp_drv);
  disp_drv.hor_res = SCREEN_WIDTH;
  disp_drv.ver_res = SCREEN_HEIGHT;
  disp_drv.flush_cb = dispflush;
  disp_drv.draw_buf = &draw_buf;
  disp_drv.user_data = this;
  lv_disp_t* dispDrv = lv_disp_drv_register(&disp_drv);
  lv_timer_set_period(dispDrv->refr_timer, 1000.0 / DISPLAY_REFRESH_RATE);

  static lv_indev_drv_t indev_drv;
  lv_indev_drv_init(&indev_drv);
  indev_drv.type = LV_INDEV_TYPE_POINTER;
  indev_drv.read_cb = touchpadRead;
  indev_drv.user_data = &touch;
  lv_indev_drv_register(&indev_drv);

  setup_ui(&guider_ui);
  updateScreenBootup();
  console.ok.println("[GUI] Initialized");
  initialized = true;
  return res;
}

void Gui::setSystemWarning(const char* warning)
{
  if(warning)
  {
    snprintf(warningText, sizeof(warningText), "%s", warning);
    flagWarning = true;
  }
  else
  {
    warningText[0] = '\0';
    flagWarning = true;
  }
}

void Gui::update(void)
{
  if(!initialized)
    return;

  static uint32_t t = 0;
  if(millis() - t > WIDGET_UPDATE_RATE)
  {
    t = millis();

    bool screenLoaded = false;
    screenLoaded |= updateScreenHome();
    screenLoaded |= updateScreenSystem();
    screenLoaded |= updateScreenEthernet();
    screenLoaded |= updateScreenEthernetSetup();
    screenLoaded |= updateScreenGnss();
    screenLoaded |= updateScreenGnssLocation();
    screenLoaded |= updateScreenCompass();
    screenLoaded |= updateScreenCompassCalibrate();
    screenLoaded |= updateScreenArmAngle();
    screenLoaded |= updateScreenArmAngleCalibrate();
    screenLoaded |= updateScreenAmbient();
    if(screenLoaded)
    {
      console.log.println("[GUI] New screen loaded");
    }
  }
  lv_task_handler();
}

// Screen update functions

FLASHMEM bool Gui::updateScreenBootup(void)
{
  if(lv_scr_act() != guider_ui.screen_bootup)
  {
    return false;
  }
  static char buffer[20];
  snprintf(buffer, sizeof(buffer), "V%s-%s", FIRMWARE_VERSION, utils->getBuildDate());
  lv_label_set_text_static(guider_ui.screen_bootup_label_version, buffer);
  return true;
}

FLASHMEM bool Gui::updateScreenHome(void)
{
  static bool screenFreshlyLoaded = true;
  if(lv_scr_act() != guider_ui.screen_home)
  {
    screenFreshlyLoaded = true;
    return false;
  }

  static uint32_t rtcTimer = 0;
  if(millis() - rtcTimer > 1000 || screenFreshlyLoaded)    // Update time every second
  {
    rtcTimer = millis();
    uint8_t hour, minute, second;
    hmi->getTime(hour, minute, second);
    static char buffer[10];
    snprintf(buffer, sizeof(buffer), "%02d:%02d", hour, minute);
    lv_label_set_text_static(guider_ui.screen_home_label_current_time, buffer);
    lv_obj_invalidate(guider_ui.screen_home_label_current_time);
  }

  static bool linkState = false;
  static bool streamingState = false;
  if(linkState != ethernetUtils->getLinkStatus() || streamingState != ethernetUtils->getStreamingState() || screenFreshlyLoaded)
  {
    linkState = ethernetUtils->getLinkStatus();
    streamingState = ethernetUtils->getStreamingState();
    lv_color_t color = lv_color_hex(0x444447);    // Gray if disconnected
    if(linkState)
    {
      color = (streamingState) ? lv_color_hex(0x00FF00)
                               : lv_color_hex(0xFFFFFF);    // Green if connected and streaming, white if connected but not streaming
    }
    lv_obj_set_style_text_color(guider_ui.screen_home_label_ethernet_status, color, LV_PART_MAIN | LV_STATE_DEFAULT);
  }

  static Utils::UsbStatus_t usbStatus = (Utils::UsbStatus_t)-1;
  if(usbStatus != utils->getUsbStatus() || screenFreshlyLoaded)
  {
    usbStatus = utils->getUsbStatus();
    lv_color_t color = lv_color_hex(0x000000);
    switch(usbStatus)
    {
      case Utils::USB_DISCONNECTED:
        color = lv_color_hex(0x444447);
        break;
      case Utils::USB_CONNECTED:
        color = lv_color_hex(0xFFFFFF);
        break;
      case Utils::USB_ACTIVE:
        color = lv_color_hex(0x00FF00);
        break;
      default:
        break;
    }
    lv_obj_set_style_text_color(guider_ui.screen_home_label_usb_status, color, LV_PART_MAIN | LV_STATE_DEFAULT);
  }

  // TODO: Implement GNSS Status

  // TODO: Implement warning screen

  bool loaded = screenFreshlyLoaded;
  screenFreshlyLoaded = false;
  return loaded;
}

FLASHMEM bool Gui::updateScreenSystem(void)
{
  static bool screenFreshlyLoaded = true;
  if(lv_scr_act() != guider_ui.screen_system)
  {
    screenFreshlyLoaded = true;
    return false;
  }

  if(screenFreshlyLoaded)
  {
    static char bufferFirmwareVersion[30];
    snprintf(bufferFirmwareVersion, sizeof(bufferFirmwareVersion), "Firmware-Version: V%s", FIRMWARE_VERSION);
    lv_label_set_text_static(guider_ui.screen_system_label_firmware_version, bufferFirmwareVersion);
    static char bufferFirmwareBuild[30];
    snprintf(bufferFirmwareBuild, sizeof(bufferFirmwareBuild), "Firmware-Build: %s", utils->getBuildDate());
    lv_label_set_text_static(guider_ui.screen_system_label_firmware_build, bufferFirmwareBuild);
    static char bufferCpuFrequency[30];
    snprintf(bufferCpuFrequency, sizeof(bufferCpuFrequency), "CPU-Frequency: %.1f MHz", ((float)utils->getCpuFrequency() / 1000000.0));
    lv_label_set_text_static(guider_ui.screen_system_label_cpu_frequency, bufferCpuFrequency);
    static char bufferMac[40];
    uint8_t mac[6];
    memcpy(mac, EthernetUtils::getMacAddress(), 6);
    snprintf(bufferMac, sizeof(bufferMac), "MAC-Address: %02X:%02X:%02X:%02X:%02X:%02X", mac[0], mac[1], mac[2], mac[3], mac[4], mac[5]);
    lv_label_set_text_static(guider_ui.screen_system_label_mac_address, bufferMac);
  }

  static float cpuTemp = 0.0;
  if(cpuTemp != utils->getCpuTemperature() || screenFreshlyLoaded)
  {
    cpuTemp = utils->getCpuTemperature();
    static char buffer[30];
    snprintf(buffer, sizeof(buffer), "CPU-Temperature: %.1f °C", cpuTemp);
    lv_label_set_text_static(guider_ui.screen_system_label_cpu_temperature, buffer);
  }

  static uint32_t opTime = 0;
  if(opTime != utils->getOperationTime() || screenFreshlyLoaded)
  {
    opTime = utils->getOperationTime();
    static char buffer[30];
    snprintf(buffer, sizeof(buffer), "Operating Time: %dh%02d'", (int)utils->getOperationTime() / 3600, (int)(utils->getOperationTime() / 60) % 60);
    lv_label_set_text_static(guider_ui.screen_system_label_operating_time, buffer);
  }

  bool loaded = screenFreshlyLoaded;
  screenFreshlyLoaded = false;
  return loaded;
}

FLASHMEM bool Gui::updateScreenEthernet(void)
{
  static bool screenFreshlyLoaded = true;
  if(lv_scr_act() != guider_ui.screen_ethernet)
  {
    screenFreshlyLoaded = true;
    return false;
  }

  static float updateRate = 0.0;
  static float bufferSize = 0.0;
  if(updateRate != audioUtils->getDataRateMBit() || screenFreshlyLoaded)
  {
    updateRate = audioUtils->getDataRateMBit();
    static char buffer[14];
    snprintf(buffer, sizeof(buffer), "%2.1f MBit/s", updateRate);
    lv_label_set_text_static(guider_ui.screen_ethernet_label_speed, buffer);
    lv_meter_set_indicator_end_value(guider_ui.screen_ethernet_meter_speed, guider_ui.screen_ethernet_meter_speed_scale_1_arc_1,
                                     (int)map(constrain(updateRate, 0.0, 70.0), 0.0, 70.0, 0, 100));
  }
  if(bufferSize != audioUtils->getBufferFillLevelPercent() || screenFreshlyLoaded)
  {
    bufferSize = audioUtils->getBufferFillLevelPercent();
    static char buffer[14];
    snprintf(buffer, sizeof(buffer), "%.0f %%", bufferSize);
    lv_label_set_text_static(guider_ui.screen_ethernet_label_buffer, buffer);
    lv_meter_set_indicator_end_value(guider_ui.screen_ethernet_meter_buffer, guider_ui.screen_ethernet_meter_buffer_scale_1_arc_1,
                                     (int)map(constrain(bufferSize, 0.0, 100.0), 0.0, 100.0, 0, 100));
  }

  static bool streamingPortConnectionState = false;
  if(streamingPortConnectionState != ethernetUtils->getStreamingConnectionStatus() || screenFreshlyLoaded)
  {
    streamingPortConnectionState = ethernetUtils->getStreamingConnectionStatus();
    lv_color_t color = (streamingPortConnectionState) ? lv_color_hex(0x00FF00) : lv_color_hex(0x757478);
    uint8_t shadow = (streamingPortConnectionState) ? 69 : 0;    // Shadow only if connected
    lv_obj_set_style_border_color(guider_ui.screen_ethernet_cont_streaming_port, color, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(guider_ui.screen_ethernet_cont_streaming_port, color, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_color(guider_ui.screen_ethernet_cont_streaming_port, color, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_opa(guider_ui.screen_ethernet_cont_streaming_port, shadow, LV_PART_MAIN | LV_STATE_DEFAULT);
  }

  static bool configurationPortConnectionState = false;
  if(configurationPortConnectionState != ethernetUtils->getConfigurationConnectionStatus() || screenFreshlyLoaded)
  {
    configurationPortConnectionState = ethernetUtils->getConfigurationConnectionStatus();
    lv_color_t color = (configurationPortConnectionState) ? lv_color_hex(0x00FF00) : lv_color_hex(0x757478);
    uint8_t shadow = (configurationPortConnectionState) ? 69 : 0;    // Shadow only if connected
    lv_obj_set_style_border_color(guider_ui.screen_ethernet_cont_configuration_port, color, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(guider_ui.screen_ethernet_cont_configuration_port, color, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_color(guider_ui.screen_ethernet_cont_configuration_port, color, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_opa(guider_ui.screen_ethernet_cont_configuration_port, shadow, LV_PART_MAIN | LV_STATE_DEFAULT);
  }

  bool loaded = screenFreshlyLoaded;
  screenFreshlyLoaded = false;
  return loaded;
}

FLASHMEM bool Gui::updateScreenEthernetSetup(void)
{
  static bool screenFreshlyLoaded = true;
  if(lv_scr_act() != guider_ui.screen_ethernet_setup)
  {
    screenFreshlyLoaded = true;
    return false;
  }

  bool loaded = screenFreshlyLoaded;
  screenFreshlyLoaded = false;
  return loaded;
}

FLASHMEM bool Gui::updateScreenGnss(void)
{
  static bool screenFreshlyLoaded = true;
  if(lv_scr_act() != guider_ui.screen_gnss)
  {
    screenFreshlyLoaded = true;
    return false;
  }

  bool loaded = screenFreshlyLoaded;
  screenFreshlyLoaded = false;
  return loaded;
}

FLASHMEM bool Gui::updateScreenGnssLocation(void)
{
  static bool screenFreshlyLoaded = true;
  if(lv_scr_act() != guider_ui.screen_gnss_location)
  {
    screenFreshlyLoaded = true;
    return false;
  }

  bool loaded = screenFreshlyLoaded;
  screenFreshlyLoaded = false;
  return loaded;
}

FLASHMEM bool Gui::updateScreenCompass(void)
{
  static bool screenFreshlyLoaded = true;
  if(lv_scr_act() != guider_ui.screen_compass)
  {
    screenFreshlyLoaded = true;
    return false;
  }

  static float heading = 0.0;
  static float pitch = 0.0;
  static float roll = 0.0;
  static const int dotXOffset = 113, dotYOffset = 120;
  static const float dotScale = 2.0;    // Pixels per degree

  float headingInverted = 360.0 - sensors->getHeading();
  if(heading != headingInverted || screenFreshlyLoaded)
  {
    heading = headingInverted;
    static char buffer[20];
    snprintf(buffer, sizeof(buffer), "Heading: %.1f°", 360.0 - heading);
    lv_label_set_text_static(guider_ui.screen_compass_label_heading, buffer);
    lv_obj_set_style_transform_angle(guider_ui.screen_compass_label_needle, (int)(heading * 10.0), 0);
    lv_obj_invalidate(guider_ui.screen_compass_img_compass_background);    // Invalidate compass backrgound
    lv_color_t color = (heading > 3.0 && heading < 357.0) ? lv_color_hex(0xD200AC) : lv_color_hex(0x00C92C);
    lv_obj_set_style_text_color(guider_ui.screen_compass_label_needle, color, LV_PART_MAIN | LV_STATE_DEFAULT);
  }
  if(pitch != sensors->getPitch() || roll != sensors->getRoll() || screenFreshlyLoaded)
  {
    pitch = sensors->getPitch();
    roll = sensors->getRoll();

    static char bufferPitch[20];
    snprintf(bufferPitch, sizeof(bufferPitch), "Pitch: %.1f°", pitch);
    lv_label_set_text_static(guider_ui.screen_compass_label_pitch, bufferPitch);

    static char bufferRoll[20];
    snprintf(bufferRoll, sizeof(bufferRoll), "Roll: %.1f°", roll);
    lv_label_set_text_static(guider_ui.screen_compass_label_roll, bufferRoll);

    int newX = dotXOffset - (int)(roll * dotScale);
    int newY = dotYOffset - (int)(pitch * dotScale);
    int dist = sqrt((newX - dotXOffset) * (newX - dotXOffset) + (newY - dotYOffset) * (newY - dotYOffset));

    const int maxDist = 31;
    if(dist > maxDist)    // If the distance is greater than 30 pixels, scale the x and y positions accordingly
    {
      newX = dotXOffset + (newX - dotXOffset) * maxDist / dist;
      newY = dotYOffset + (newY - dotYOffset) * maxDist / dist;
    }
    lv_color_t color = (dist >= 4) ? lv_color_hex(0xFF0000) : lv_color_hex(0x00C92C);    // Green if inside small circle, red otherwise
    lv_obj_set_style_border_color(guider_ui.screen_compass_cont_dot, color, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(guider_ui.screen_compass_cont_dot, color, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_pos(guider_ui.screen_compass_cont_dot, newX, newY);
  }

  bool loaded = screenFreshlyLoaded;
  screenFreshlyLoaded = false;
  return loaded;
}

FLASHMEM bool Gui::updateScreenCompassCalibrate(void)
{
  static bool screenFreshlyLoaded = true;
  if(lv_scr_act() != guider_ui.screen_compass_calib)
  {
    screenFreshlyLoaded = true;
    return false;
  }

  static float calibCoverage = 0.0;
  static float calibVariance = 0.0;
  static float calibWobbleError = 0.0;
  static float calibFitError = 0.0;
  static bool calibDone = false;

  if(calibCoverage != sensors->getCalibCoverage() || screenFreshlyLoaded)
  {
    calibCoverage = sensors->getCalibCoverage();
    static char buffer[10];
    snprintf(buffer, sizeof(buffer), "%.0f %%", calibCoverage);
    lv_label_set_text_static(guider_ui.screen_compass_calib_label_coverage, buffer);
    lv_meter_set_indicator_end_value(guider_ui.screen_compass_calib_meter_coverage, guider_ui.screen_compass_calib_meter_coverage_scale_1_arc_1,
                                     (int)map(constrain(calibCoverage, 0.0, 100.0), 0.0, 100.0, 100, 0));
  }
  if(calibWobbleError != sensors->getCalibWobbleError() || screenFreshlyLoaded)
  {
    calibWobbleError = sensors->getCalibWobbleError();
    static char buffer[25];
    snprintf(buffer, sizeof(buffer), "Wobble Error: %.1f %%", calibWobbleError);
    lv_label_set_text_static(guider_ui.screen_compass_calib_label_wobble_error, buffer);
  }
  if(calibFitError != sensors->getCalibFitError() || screenFreshlyLoaded)
  {
    calibFitError = sensors->getCalibFitError();
    static char buffer[25];
    snprintf(buffer, sizeof(buffer), "Fit Error: %.1f %%", calibFitError);
    lv_label_set_text_static(guider_ui.screen_compass_calib_label_fit_error, buffer);
  }
  if(calibVariance != sensors->getCalibVariance() || screenFreshlyLoaded)
  {
    calibVariance = sensors->getCalibVariance();
    static char buffer[20];
    snprintf(buffer, sizeof(buffer), "Variance: %.1f", calibVariance);
    lv_label_set_text_static(guider_ui.screen_compass_calib_label_variance, buffer);
  }

  if(!calibDone && sensors->isCalibrationDone())
  {
    console.log.println("[GUI] Calibration done");
    hmi->buzzer.playMelody(MELODIE_CALIB_DONE);
    lv_obj_t* act_scr = lv_scr_act();
    lv_disp_t* d = lv_obj_get_disp(act_scr);
    if(d->prev_scr == nullptr && (d->scr_to_load == nullptr || d->scr_to_load == act_scr))
    {
      if(guider_ui.screen_compass_del == true)
      {
        setup_scr_screen_compass(&guider_ui);
      }
      lv_scr_load_anim(guider_ui.screen_compass, LV_SCR_LOAD_ANIM_FADE_ON, 200, 3500, true);
      guider_ui.screen_compass_calib_del = true;
    }
    lv_obj_clear_flag(guider_ui.screen_compass_calib_cont_successful, LV_OBJ_FLAG_HIDDEN);
    lv_obj_clear_flag(guider_ui.screen_compass_calib_cont_successful_background, LV_OBJ_FLAG_HIDDEN);
  }
  calibDone = sensors->isCalibrationDone();

  bool loaded = screenFreshlyLoaded;
  screenFreshlyLoaded = false;
  return loaded;
}

FLASHMEM bool Gui::updateScreenArmAngle(void)
{
  static bool screenFreshlyLoaded = true;
  if(lv_scr_act() != guider_ui.screen_arm_angle)
  {
    screenFreshlyLoaded = true;
    return false;
  }

  static float angle = 0.0;
  if(angle != sensors->getAngle() || screenFreshlyLoaded)
  {
    angle = sensors->getAngle();
    static char buffer[20];
    snprintf(buffer, sizeof(buffer), "%.1f°", angle);
    lv_label_set_text_static(guider_ui.screen_arm_angle_label_angle, buffer);
    lv_meter_set_indicator_end_value(guider_ui.screen_arm_angle_meter_angle, guider_ui.screen_arm_angle_meter_angle_scale_1_arc_1,
                                     (int)map(angle, 0.0, 90.0, 100.0, 0.0));
  }

  static bool magnetDetected = false;
  if(magnetDetected != sensors->isMagnetDetected() || screenFreshlyLoaded)
  {
    magnetDetected = sensors->isMagnetDetected();
    lv_color_t color = (magnetDetected) ? lv_color_hex(0x00FF00) : lv_color_hex(0x757478);
    uint8_t shadow = (magnetDetected) ? 69 : 0;    // Shadow only if connected
    lv_obj_set_style_border_color(guider_ui.screen_arm_angle_cont_magnet_detected, color, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(guider_ui.screen_arm_angle_cont_magnet_detected, color, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_color(guider_ui.screen_arm_angle_cont_magnet_detected, color, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_opa(guider_ui.screen_arm_angle_cont_magnet_detected, shadow, LV_PART_MAIN | LV_STATE_DEFAULT);
  }

  static bool magnetTooWeak = false;
  if(magnetTooWeak != sensors->isMagnetTooWeak() || screenFreshlyLoaded)
  {
    magnetTooWeak = sensors->isMagnetTooWeak();
    lv_color_t color = (magnetTooWeak) ? lv_color_hex(0xFFB300) : lv_color_hex(0x757478);
    uint8_t shadow = (magnetTooWeak) ? 69 : 0;    // Shadow only if connected
    lv_obj_set_style_border_color(guider_ui.screen_arm_angle_cont_magnet_too_weak, color, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(guider_ui.screen_arm_angle_cont_magnet_too_weak, color, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_color(guider_ui.screen_arm_angle_cont_magnet_too_weak, color, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_opa(guider_ui.screen_arm_angle_cont_magnet_too_weak, shadow, LV_PART_MAIN | LV_STATE_DEFAULT);
  }

  static bool magnetTooStrong = false;
  if(magnetTooStrong != sensors->isMagnetTooStrong() || screenFreshlyLoaded)
  {
    magnetTooStrong = sensors->isMagnetTooStrong();
    lv_color_t color = (magnetTooStrong) ? lv_color_hex(0xFFB300) : lv_color_hex(0x757478);
    uint8_t shadow = (magnetTooStrong) ? 69 : 0;    // Shadow only if connected
    lv_obj_set_style_border_color(guider_ui.screen_arm_angle_cont_magnet_too_strong, color, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(guider_ui.screen_arm_angle_cont_magnet_too_strong, color, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_color(guider_ui.screen_arm_angle_cont_magnet_too_strong, color, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_opa(guider_ui.screen_arm_angle_cont_magnet_too_strong, shadow, LV_PART_MAIN | LV_STATE_DEFAULT);
  }

  bool loaded = screenFreshlyLoaded;
  screenFreshlyLoaded = false;
  return loaded;
}

FLASHMEM bool Gui::updateScreenArmAngleCalibrate(void)
{
  static bool screenFreshlyLoaded = true;
  if(lv_scr_act() != guider_ui.screen_arm_angle_calib)
  {
    screenFreshlyLoaded = true;
    return false;
  }

  static uint16_t angleRaw = 0;
  if(angleRaw != sensors->getAngleRaw() || screenFreshlyLoaded)
  {
    angleRaw = sensors->getAngleRaw();
    static char buffer[20];
    snprintf(buffer, sizeof(buffer), "Raw Value: %d", angleRaw);
    lv_label_set_text_static(guider_ui.screen_arm_angle_calib_label_raw_value, buffer);
  }

  bool loaded = screenFreshlyLoaded;
  screenFreshlyLoaded = false;
  return loaded;
}

FLASHMEM bool Gui::updateScreenAmbient(void)
{
  static bool screenFreshlyLoaded = true;
  if(lv_scr_act() != guider_ui.screen_ambient)
  {
    screenFreshlyLoaded = true;
    return false;
  }

  bool loaded = screenFreshlyLoaded;
  screenFreshlyLoaded = false;
  return loaded;
}


// Screen callback functions

void Gui::callbackScreenHomeShowWarning(void)
{
  console.log.println("[GUI] [CALLBACK] Home screen show warning");
  // TODO: Implement warning screen
}

void Gui::callbackScreenEthernetSetupLoaded(void)
{
  console.log.println("[GUI] [CALLBACK] Ethernet Setup screen loaded");
  uint8_t ip_0, ip_1, ip_2, ip_3;
  ethernetUtils->getIp(ip_0, ip_1, ip_2, ip_3);
  lv_roller_set_selected(guider_ui.screen_ethernet_setup_roller_ip_0, ip_0, LV_ANIM_OFF);
  lv_roller_set_selected(guider_ui.screen_ethernet_setup_roller_ip_1, ip_1, LV_ANIM_OFF);
  lv_roller_set_selected(guider_ui.screen_ethernet_setup_roller_ip_2, ip_2, LV_ANIM_OFF);
  lv_roller_set_selected(guider_ui.screen_ethernet_setup_roller_ip_3, ip_3, LV_ANIM_OFF);

  static char bufferStreamingPort[30];
  snprintf(bufferStreamingPort, sizeof(bufferStreamingPort), "Streaming Port: %d", ethernetUtils->getStreamingPort());
  lv_label_set_text_static(guider_ui.screen_ethernet_setup_label_streaming_port, bufferStreamingPort);

  static char bufferConfigPort[30];
  snprintf(bufferConfigPort, sizeof(bufferConfigPort), "Configuration Port: %d", ethernetUtils->getConfigPort());
  lv_label_set_text_static(guider_ui.screen_ethernet_setup_label_configuration_port, bufferConfigPort);
}

void Gui::callbackScreenEthernetSetupConfirmed(void)
{
  console.log.println("[GUI] [CALLBACK] Ethernet Setup confirmed");
  uint8_t ip_0, ip_1, ip_2, ip_3;
  char buffer[6];
  lv_roller_get_selected_str(guider_ui.screen_ethernet_setup_roller_ip_0, buffer, sizeof(buffer));
  ip_0 = atoi(buffer);
  lv_roller_get_selected_str(guider_ui.screen_ethernet_setup_roller_ip_1, buffer, sizeof(buffer));
  ip_1 = atoi(buffer);
  lv_roller_get_selected_str(guider_ui.screen_ethernet_setup_roller_ip_2, buffer, sizeof(buffer));
  ip_2 = atoi(buffer);
  lv_roller_get_selected_str(guider_ui.screen_ethernet_setup_roller_ip_3, buffer, sizeof(buffer));
  ip_3 = atoi(buffer);
  ethernetUtils->setIp(ip_0, ip_1, ip_2, ip_3);
}

void Gui::callbackScreenCompassCalibrationStart(void)
{
  console.log.println("[GUI] [CALLBACK] Starting calibration");
  sensors->startCalibration();
  hmi->buzzer.playMelody(MELODIE_CALIB_STARTED);
}

void Gui::callbackScreenCompassCalibrationAbort(void)
{
  console.log.println("[GUI] [CALLBACK] Aborting calibration");
  sensors->abortCalibration();
}

void Gui::callbackScreenArmAngleCalibration0(void)
{
  console.log.println("[GUI] [CALLBACK] Arm angle calibration 0°");
  sensors->calibrateAngle0();
  hmi->buzzer.playMelody(MELODIE_CALIB_STARTED);
  lv_obj_set_style_border_color(guider_ui.screen_arm_angle_calib_btn_calibrate_0, lv_color_hex(0x00c92c), LV_PART_MAIN | LV_STATE_DEFAULT);
  screenArmAngleCalibrationCheckValid(true, false);
}

void Gui::callbackScreenArmAngleCalibration90(void)
{
  console.log.println("[GUI] [CALLBACK] Arm angle calibration 90°");
  sensors->calibrateAngle90();
  hmi->buzzer.playMelody(MELODIE_CALIB_STARTED);
  lv_obj_set_style_border_color(guider_ui.screen_arm_angle_calib_btn_calibrate_90, lv_color_hex(0x00c92c), LV_PART_MAIN | LV_STATE_DEFAULT);
  screenArmAngleCalibrationCheckValid(false, true);
}

void Gui::callbackScreenArmAngleCalibrationStart(void)
{
  console.log.println("[GUI] [CALLBACK] Starting arm angle calibration");
  sensors->calibrateAngleStart();
  screenArmAngleCalibrationCheckValid();
}

void Gui::callbackScreenArmAngleCalibrationAbort(void)
{
  console.log.println("[GUI] [CALLBACK] Aborting arm angle calibration");
  sensors->calibrateAngleAbort();
  screenArmAngleCalibrationCheckValid();
}

void Gui::callbackScreenArmAngleCalibrationConfirmed(void)
{
  console.log.println("[GUI] [CALLBACK] Arm angle calibration confirmed");
  sensors->calibrateAngleConfirm();
  hmi->buzzer.playMelody(MELODIE_CALIB_DONE);
}


// Helper functions
void Gui::screenArmAngleCalibrationCheckValid(bool angle0, bool angle90)
{
  static bool _valid0 = false;
  static bool _valid90 = false;
  if(!angle0 && !angle90)
  {
    _valid0 = _valid90 = false;
    return;
  }
  _valid0 |= angle0;
  _valid90 |= angle90;
  if(_valid0 && _valid90)
  {
    lv_obj_set_style_border_color(guider_ui.screen_arm_angle_calib_btn_confirm, lv_color_hex(0x00c92c), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_add_flag(guider_ui.screen_arm_angle_calib_btn_confirm, LV_OBJ_FLAG_CLICKABLE);
    lv_obj_set_style_text_color(guider_ui.screen_arm_angle_calib_label_confirm, lv_color_hex(0xffffff), LV_PART_MAIN | LV_STATE_DEFAULT);
  }
}


// Internal functions

void Gui::lvglPrint(const char* buf)
{
  console.log.printf("[LVGL] %s", buf);
}

void Gui::dispflush(lv_disp_drv_t* dispDrv, const lv_area_t* area, lv_color_t* color_p)
{
  static bool firstFlush = true;
  Gui* gui = (Gui*)dispDrv->user_data;
  gui->disp.writeRect(area->x1, area->y1, (area->x2 - area->x1 + 1), (area->y2 - area->y1 + 1), (uint16_t*)color_p);
  gui->disp.updateScreenAsync();    // DMA the stuff to the screen
  lv_disp_flush_ready(dispDrv);
  if(firstFlush)    // Turn on backlight after first flush
  {
    firstFlush = false;
    gui->setBrightness(255);
  }
}

void Gui::touchpadRead(lv_indev_drv_t* drv, lv_indev_data_t* data)
{
  CHSC6413* touch = (CHSC6413*)drv->user_data;
  Utils::lockWire(GUI_WIRE);
  bool available = touch->available();
  Utils::turnOffWire(GUI_WIRE);    // Somehow the touch controller locks up the I2C-Bus, so we have to turn it off and on again
  delayMicroseconds(100);
  Utils::turnOnWire(GUI_WIRE);
  Utils::unlockWire(GUI_WIRE);
  if(available)
  {
    int x = touch->x;
    int y = touch->y;
    if((x > 0) && (y > 0) && (x < (int)SCREEN_WIDTH) && (y < (int)SCREEN_HEIGHT))
    {
      data->state = LV_INDEV_STATE_PR;    // Indicate that the touchpad is pressed
      data->point.x = (lv_coord_t)x;
      data->point.y = (lv_coord_t)y;
      return;
    }
  }
  data->state = LV_INDEV_STATE_REL;    // Indicate that the touchpad is released
}
