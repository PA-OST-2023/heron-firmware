/*
* Copyright 2024 NXP
* NXP Confidential and Proprietary. This software is owned or controlled by NXP and may only be used strictly in
* accordance with the applicable license terms. By expressly accepting such terms or by downloading, installing,
* activating and/or otherwise using the software, you are agreeing that you have read, and that you agree to
* comply with and are bound by, such license terms.  If you do not agree to be bound by the applicable license
* terms, then you may not retain, install, activate or otherwise use the software.
*/


#ifndef EVENTS_INIT_H_
#define EVENTS_INIT_H_
#ifdef __cplusplus
extern "C" {
#endif

#include "gui_guider.h"

void events_init(lv_ui *ui);

void events_init_screen_bootup(lv_ui *ui);
void events_init_screen_home(lv_ui *ui);
void events_init_screen_system(lv_ui *ui);
void events_init_screen_ethernet(lv_ui *ui);
void events_init_screen_ethernet_setup(lv_ui *ui);
void events_init_screen_gnss(lv_ui *ui);
void events_init_screen_gnss_location(lv_ui *ui);
void events_init_screen_compass(lv_ui *ui);
void events_init_screen_compass_calib(lv_ui *ui);
void events_init_screen_arm_angle(lv_ui *ui);
void events_init_screen_arm_angle_calib(lv_ui *ui);
void events_init_screen_ambient(lv_ui *ui);

#ifdef __cplusplus
}
#endif
#endif /* EVENT_CB_H_ */
