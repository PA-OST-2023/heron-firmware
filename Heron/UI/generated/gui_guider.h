/*
* Copyright 2023 NXP
* NXP Confidential and Proprietary. This software is owned or controlled by NXP and may only be used strictly in
* accordance with the applicable license terms. By expressly accepting such terms or by downloading, installing,
* activating and/or otherwise using the software, you are agreeing that you have read, and that you agree to
* comply with and are bound by, such license terms.  If you do not agree to be bound by the applicable license
* terms, then you may not retain, install, activate or otherwise use the software.
*/

#ifndef GUI_GUIDER_H
#define GUI_GUIDER_H
#ifdef __cplusplus
extern "C" {
#endif

#include "lvgl.h"

typedef struct
{
  
	lv_obj_t *screen_bootup;
	bool screen_bootup_del;
	lv_obj_t *screen_bootup_label_1;
	lv_obj_t *screen_bootup_img_2;
	lv_obj_t *screen_home;
	bool screen_home_del;
	lv_obj_t *screen_home_tileview_menu;
	lv_obj_t *screen_home_tileview_menu_tile_system;
	lv_obj_t *screen_home_tileview_menu_tile_ethernet;
	lv_obj_t *screen_home_tileview_menu_tile_gnss;
	lv_obj_t *screen_home_tileview_menu_tile_compass;
	lv_obj_t *screen_home_label_system;
	lv_obj_t *screen_home_btn_system;
	lv_obj_t *screen_home_btn_system_label;
	lv_obj_t *screen_home_label_ethernet;
	lv_obj_t *screen_home_btn_ethernet;
	lv_obj_t *screen_home_btn_ethernet_label;
	lv_obj_t *screen_home_label_gnss;
	lv_obj_t *screen_home_btn_gnss;
	lv_obj_t *screen_home_btn_gnss_label;
	lv_obj_t *screen_home_label_compass;
	lv_obj_t *screen_home_btn_compass;
	lv_obj_t *screen_home_btn_compass_label;
	lv_obj_t *screen_home_cont_top_bar;
	lv_obj_t *screen_home_label_warning;
	lv_obj_t *screen_home_label_usb_status;
	lv_obj_t *screen_home_label_ethernet_status;
	lv_obj_t *screen_home_label_gnss_status;
	lv_obj_t *screen_home_label_current_time;
	lv_obj_t *screen_home_btn_warning;
	lv_obj_t *screen_home_btn_warning_label;
	lv_obj_t *screen_ethernet;
	bool screen_ethernet_del;
	lv_obj_t *screen_ethernet_btn_setup;
	lv_obj_t *screen_ethernet_btn_setup_label;
	lv_obj_t *screen_ethernet_label_setup;
	lv_obj_t *screen_ethernet_btn_back;
	lv_obj_t *screen_ethernet_btn_back_label;
	lv_obj_t *screen_ethernet_label_back;
	lv_obj_t *screen_ethernet_label_title;
	lv_obj_t *screen_ethernet_label_buffer;
	lv_obj_t *screen_ethernet_meter_buffer;
	lv_obj_t *screen_ethernet_label_buffer_title;
	lv_obj_t *screen_ethernet_label_speed;
	lv_obj_t *screen_ethernet_meter_speed;
	lv_obj_t *screen_ethernet_label_speed_title;
	lv_obj_t *screen_ethernet_setup;
	bool screen_ethernet_setup_del;
	lv_obj_t *screen_ethernet_setup_label_dot_2;
	lv_obj_t *screen_ethernet_setup_label_dot_1;
	lv_obj_t *screen_ethernet_setup_label_dot_0;
	lv_obj_t *screen_ethernet_setup_btn_confirm;
	lv_obj_t *screen_ethernet_setup_btn_confirm_label;
	lv_obj_t *screen_ethernet_setup_label_confirm;
	lv_obj_t *screen_ethernet_setup_btn_back;
	lv_obj_t *screen_ethernet_setup_btn_back_label;
	lv_obj_t *screen_ethernet_setup_label_back;
	lv_obj_t *screen_ethernet_setup_label_title;
	lv_obj_t *screen_ethernet_setup_roller_ip_3;
	lv_obj_t *screen_ethernet_setup_roller_ip_2;
	lv_obj_t *screen_ethernet_setup_roller_ip_1;
	lv_obj_t *screen_ethernet_setup_roller_ip_0;
	lv_obj_t *screen_ethernet_setup_label_ip_address;
	lv_obj_t *screen_ethernet_setup_label_configuration_port;
	lv_obj_t *screen_ethernet_setup_label_streaming_port;
	lv_obj_t *screen_ethernet_setup_cont_confirmed_background;
	lv_obj_t *screen_ethernet_setup_cont_confirmed;
	lv_obj_t *screen_ethernet_setup_label_confirmed;
	lv_obj_t *screen_compass;
	bool screen_compass_del;
	lv_obj_t *screen_compass_btn_calib;
	lv_obj_t *screen_compass_btn_calib_label;
	lv_obj_t *screen_compass_label_calib;
	lv_obj_t *screen_compass_btn_back;
	lv_obj_t *screen_compass_btn_back_label;
	lv_obj_t *screen_compass_label_back;
	lv_obj_t *screen_compass_label_title;
	lv_obj_t *screen_compass_label_heading;
	lv_obj_t *screen_compass_label_pitch;
	lv_obj_t *screen_compass_label_roll;
	lv_obj_t *screen_compass_img_compass_background;
	lv_obj_t *screen_compass_cont_dot;
	lv_obj_t *screen_compass_label_needle;
	lv_obj_t *screen_compass_calib;
	bool screen_compass_calib_del;
	lv_obj_t *screen_compass_calib_btn_back;
	lv_obj_t *screen_compass_calib_btn_back_label;
	lv_obj_t *screen_compass_calib_label_back;
	lv_obj_t *screen_compass_calib_label_title;
	lv_obj_t *screen_compass_calib_meter_coverage;
	lv_obj_t *screen_compass_calib_label_coverage_title;
	lv_obj_t *screen_compass_calib_label_coverage;
	lv_obj_t *screen_compass_calib_label_variance;
	lv_obj_t *screen_compass_calib_label_fit_error;
	lv_obj_t *screen_compass_calib_label_wobble_error;
	lv_obj_t *screen_compass_calib_cont_successful_background;
	lv_obj_t *screen_compass_calib_cont_successful;
	lv_obj_t *screen_compass_calib_label_successful;
}lv_ui;

void ui_init_style(lv_style_t * style);
void init_scr_del_flag(lv_ui *ui);
void setup_ui(lv_ui *ui);
extern lv_ui guider_ui;

void setup_scr_screen_bootup(lv_ui *ui);
void setup_scr_screen_home(lv_ui *ui);
void setup_scr_screen_ethernet(lv_ui *ui);
void setup_scr_screen_ethernet_setup(lv_ui *ui);
void setup_scr_screen_compass(lv_ui *ui);
void setup_scr_screen_compass_calib(lv_ui *ui);
LV_IMG_DECLARE(_Heron_alpha_100x100);
LV_IMG_DECLARE(_compass_background_alpha_82x82);

LV_FONT_DECLARE(lv_font_MontserratRegular_20)
LV_FONT_DECLARE(lv_font_montserratMedium_16)
LV_FONT_DECLARE(lv_font_FontAwesome6ProLight_300_50)
LV_FONT_DECLARE(lv_font_montserratMedium_12)
LV_FONT_DECLARE(lv_font_FontAwesome5ProLight_300_40)
LV_FONT_DECLARE(lv_font_FontAwesome6SharpLight_300_50)
LV_FONT_DECLARE(lv_font_FontAwesome5ProSolid_900_16)
LV_FONT_DECLARE(lv_font_FontAwesome5_15)
LV_FONT_DECLARE(lv_font_FontAwesome5ProRegular_400_16)
LV_FONT_DECLARE(lv_font_montserratMedium_14)
LV_FONT_DECLARE(lv_font_FontAwesome5ProSolid_900_10)
LV_FONT_DECLARE(lv_font_montserratMedium_20)


#ifdef __cplusplus
}
#endif
#endif
