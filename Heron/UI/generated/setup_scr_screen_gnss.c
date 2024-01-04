/*
* Copyright 2024 NXP
* NXP Confidential and Proprietary. This software is owned or controlled by NXP and may only be used strictly in
* accordance with the applicable license terms. By expressly accepting such terms or by downloading, installing,
* activating and/or otherwise using the software, you are agreeing that you have read, and that you agree to
* comply with and are bound by, such license terms.  If you do not agree to be bound by the applicable license
* terms, then you may not retain, install, activate or otherwise use the software.
*/

#include "lvgl.h"
#include <stdio.h>
#include "gui_guider.h"
#include "events_init.h"
#include "widgets_init.h"
#include "custom.h"


void setup_scr_screen_gnss(lv_ui *ui)
{
	//Write codes screen_gnss
	ui->screen_gnss = lv_obj_create(NULL);
	lv_obj_set_size(ui->screen_gnss, 240, 240);

	//Write style for screen_gnss, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_bg_opa(ui->screen_gnss, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui->screen_gnss, lv_color_hex(0x101418), LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes screen_gnss_btn_location
	ui->screen_gnss_btn_location = lv_btn_create(ui->screen_gnss);
	ui->screen_gnss_btn_location_label = lv_label_create(ui->screen_gnss_btn_location);
	lv_label_set_text(ui->screen_gnss_btn_location_label, "");
	lv_label_set_long_mode(ui->screen_gnss_btn_location_label, LV_LABEL_LONG_WRAP);
	lv_obj_align(ui->screen_gnss_btn_location_label, LV_ALIGN_LEFT_MID, 0, 0);
	lv_obj_set_style_pad_all(ui->screen_gnss_btn_location, 0, LV_STATE_DEFAULT);
	lv_obj_set_pos(ui->screen_gnss_btn_location, 0, 200);
	lv_obj_set_size(ui->screen_gnss_btn_location, 240, 40);

	//Write style for screen_gnss_btn_location, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_bg_opa(ui->screen_gnss_btn_location, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui->screen_gnss_btn_location, lv_color_hex(0x292831), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_width(ui->screen_gnss_btn_location, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_opa(ui->screen_gnss_btn_location, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_color(ui->screen_gnss_btn_location, lv_color_hex(0x757478), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_side(ui->screen_gnss_btn_location, LV_BORDER_SIDE_TOP, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->screen_gnss_btn_location, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->screen_gnss_btn_location, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->screen_gnss_btn_location, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->screen_gnss_btn_location, &lv_font_FontAwesome5ProRegular_400_16, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->screen_gnss_btn_location, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes screen_gnss_label_location
	ui->screen_gnss_label_location = lv_label_create(ui->screen_gnss);
	lv_label_set_text(ui->screen_gnss_label_location, "QR-Code");
	lv_label_set_long_mode(ui->screen_gnss_label_location, LV_LABEL_LONG_WRAP);
	lv_obj_set_pos(ui->screen_gnss_label_location, 60, 210);
	lv_obj_set_size(ui->screen_gnss_label_location, 120, 18);

	//Write style for screen_gnss_label_location, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->screen_gnss_label_location, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->screen_gnss_label_location, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->screen_gnss_label_location, lv_color_hex(0x757478), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->screen_gnss_label_location, &lv_font_montserratMedium_16, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->screen_gnss_label_location, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_line_space(ui->screen_gnss_label_location, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->screen_gnss_label_location, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->screen_gnss_label_location, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->screen_gnss_label_location, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->screen_gnss_label_location, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->screen_gnss_label_location, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->screen_gnss_label_location, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->screen_gnss_label_location, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes screen_gnss_btn_back
	ui->screen_gnss_btn_back = lv_btn_create(ui->screen_gnss);
	ui->screen_gnss_btn_back_label = lv_label_create(ui->screen_gnss_btn_back);
	lv_label_set_text(ui->screen_gnss_btn_back_label, "");
	lv_label_set_long_mode(ui->screen_gnss_btn_back_label, LV_LABEL_LONG_WRAP);
	lv_obj_align(ui->screen_gnss_btn_back_label, LV_ALIGN_LEFT_MID, 0, 0);
	lv_obj_set_style_pad_all(ui->screen_gnss_btn_back, 0, LV_STATE_DEFAULT);
	lv_obj_set_pos(ui->screen_gnss_btn_back, 0, 0);
	lv_obj_set_size(ui->screen_gnss_btn_back, 240, 50);

	//Write style for screen_gnss_btn_back, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_bg_opa(ui->screen_gnss_btn_back, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui->screen_gnss_btn_back, lv_color_hex(0x292831), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_width(ui->screen_gnss_btn_back, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_opa(ui->screen_gnss_btn_back, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_color(ui->screen_gnss_btn_back, lv_color_hex(0xD200AC), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_side(ui->screen_gnss_btn_back, LV_BORDER_SIDE_BOTTOM, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->screen_gnss_btn_back, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->screen_gnss_btn_back, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->screen_gnss_btn_back, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->screen_gnss_btn_back, &lv_font_FontAwesome5ProRegular_400_16, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->screen_gnss_btn_back, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes screen_gnss_label_back
	ui->screen_gnss_label_back = lv_label_create(ui->screen_gnss);
	lv_label_set_text(ui->screen_gnss_label_back, "");
	lv_label_set_long_mode(ui->screen_gnss_label_back, LV_LABEL_LONG_WRAP);
	lv_obj_set_pos(ui->screen_gnss_label_back, 50, 25);
	lv_obj_set_size(ui->screen_gnss_label_back, 23, 16);

	//Write style for screen_gnss_label_back, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->screen_gnss_label_back, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->screen_gnss_label_back, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->screen_gnss_label_back, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->screen_gnss_label_back, &lv_font_FontAwesome5ProRegular_400_16, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->screen_gnss_label_back, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_line_space(ui->screen_gnss_label_back, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->screen_gnss_label_back, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->screen_gnss_label_back, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->screen_gnss_label_back, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->screen_gnss_label_back, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->screen_gnss_label_back, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->screen_gnss_label_back, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->screen_gnss_label_back, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes screen_gnss_label_title
	ui->screen_gnss_label_title = lv_label_create(ui->screen_gnss);
	lv_label_set_text(ui->screen_gnss_label_title, "GNSS");
	lv_label_set_long_mode(ui->screen_gnss_label_title, LV_LABEL_LONG_WRAP);
	lv_obj_set_pos(ui->screen_gnss_label_title, 60, 20);
	lv_obj_set_size(ui->screen_gnss_label_title, 120, 18);

	//Write style for screen_gnss_label_title, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->screen_gnss_label_title, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->screen_gnss_label_title, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->screen_gnss_label_title, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->screen_gnss_label_title, &lv_font_montserratMedium_16, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->screen_gnss_label_title, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_line_space(ui->screen_gnss_label_title, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->screen_gnss_label_title, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->screen_gnss_label_title, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->screen_gnss_label_title, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->screen_gnss_label_title, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->screen_gnss_label_title, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->screen_gnss_label_title, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->screen_gnss_label_title, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes screen_gnss_label_latitude
	ui->screen_gnss_label_latitude = lv_label_create(ui->screen_gnss);
	lv_label_set_text(ui->screen_gnss_label_latitude, "Latitude:");
	lv_label_set_long_mode(ui->screen_gnss_label_latitude, LV_LABEL_LONG_WRAP);
	lv_obj_set_pos(ui->screen_gnss_label_latitude, 27, 125);
	lv_obj_set_size(ui->screen_gnss_label_latitude, 195, 18);

	//Write style for screen_gnss_label_latitude, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->screen_gnss_label_latitude, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->screen_gnss_label_latitude, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->screen_gnss_label_latitude, lv_color_hex(0x8a8a8a), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->screen_gnss_label_latitude, &lv_font_montserratMedium_14, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->screen_gnss_label_latitude, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_line_space(ui->screen_gnss_label_latitude, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->screen_gnss_label_latitude, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->screen_gnss_label_latitude, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->screen_gnss_label_latitude, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->screen_gnss_label_latitude, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->screen_gnss_label_latitude, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->screen_gnss_label_latitude, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->screen_gnss_label_latitude, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes screen_gnss_label_longitude
	ui->screen_gnss_label_longitude = lv_label_create(ui->screen_gnss);
	lv_label_set_text(ui->screen_gnss_label_longitude, "Longitude:");
	lv_label_set_long_mode(ui->screen_gnss_label_longitude, LV_LABEL_LONG_WRAP);
	lv_obj_set_pos(ui->screen_gnss_label_longitude, 27, 145);
	lv_obj_set_size(ui->screen_gnss_label_longitude, 195, 18);

	//Write style for screen_gnss_label_longitude, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->screen_gnss_label_longitude, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->screen_gnss_label_longitude, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->screen_gnss_label_longitude, lv_color_hex(0x8a8a8a), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->screen_gnss_label_longitude, &lv_font_montserratMedium_14, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->screen_gnss_label_longitude, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_line_space(ui->screen_gnss_label_longitude, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->screen_gnss_label_longitude, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->screen_gnss_label_longitude, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->screen_gnss_label_longitude, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->screen_gnss_label_longitude, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->screen_gnss_label_longitude, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->screen_gnss_label_longitude, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->screen_gnss_label_longitude, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes screen_gnss_label_altitude
	ui->screen_gnss_label_altitude = lv_label_create(ui->screen_gnss);
	lv_label_set_text(ui->screen_gnss_label_altitude, "Altitude (MSL):");
	lv_label_set_long_mode(ui->screen_gnss_label_altitude, LV_LABEL_LONG_WRAP);
	lv_obj_set_pos(ui->screen_gnss_label_altitude, 27, 165);
	lv_obj_set_size(ui->screen_gnss_label_altitude, 195, 18);

	//Write style for screen_gnss_label_altitude, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->screen_gnss_label_altitude, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->screen_gnss_label_altitude, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->screen_gnss_label_altitude, lv_color_hex(0x8a8a8a), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->screen_gnss_label_altitude, &lv_font_montserratMedium_14, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->screen_gnss_label_altitude, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_line_space(ui->screen_gnss_label_altitude, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->screen_gnss_label_altitude, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->screen_gnss_label_altitude, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->screen_gnss_label_altitude, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->screen_gnss_label_altitude, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->screen_gnss_label_altitude, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->screen_gnss_label_altitude, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->screen_gnss_label_altitude, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes screen_gnss_label_time
	ui->screen_gnss_label_time = lv_label_create(ui->screen_gnss);
	lv_label_set_text(ui->screen_gnss_label_time, "Time: ");
	lv_label_set_long_mode(ui->screen_gnss_label_time, LV_LABEL_LONG_WRAP);
	lv_obj_set_pos(ui->screen_gnss_label_time, 27, 105);
	lv_obj_set_size(ui->screen_gnss_label_time, 195, 18);

	//Write style for screen_gnss_label_time, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->screen_gnss_label_time, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->screen_gnss_label_time, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->screen_gnss_label_time, lv_color_hex(0x8a8a8a), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->screen_gnss_label_time, &lv_font_montserratMedium_14, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->screen_gnss_label_time, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_line_space(ui->screen_gnss_label_time, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->screen_gnss_label_time, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->screen_gnss_label_time, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->screen_gnss_label_time, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->screen_gnss_label_time, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->screen_gnss_label_time, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->screen_gnss_label_time, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->screen_gnss_label_time, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes screen_gnss_label_satelite_count
	ui->screen_gnss_label_satelite_count = lv_label_create(ui->screen_gnss);
	lv_label_set_text(ui->screen_gnss_label_satelite_count, "Satelite Count:");
	lv_label_set_long_mode(ui->screen_gnss_label_satelite_count, LV_LABEL_LONG_WRAP);
	lv_obj_set_pos(ui->screen_gnss_label_satelite_count, 27, 85);
	lv_obj_set_size(ui->screen_gnss_label_satelite_count, 195, 18);

	//Write style for screen_gnss_label_satelite_count, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->screen_gnss_label_satelite_count, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->screen_gnss_label_satelite_count, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->screen_gnss_label_satelite_count, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->screen_gnss_label_satelite_count, &lv_font_montserratMedium_14, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->screen_gnss_label_satelite_count, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_line_space(ui->screen_gnss_label_satelite_count, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->screen_gnss_label_satelite_count, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->screen_gnss_label_satelite_count, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->screen_gnss_label_satelite_count, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->screen_gnss_label_satelite_count, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->screen_gnss_label_satelite_count, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->screen_gnss_label_satelite_count, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->screen_gnss_label_satelite_count, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes screen_gnss_label_fix_status
	ui->screen_gnss_label_fix_status = lv_label_create(ui->screen_gnss);
	lv_label_set_text(ui->screen_gnss_label_fix_status, "Fix Status: ");
	lv_label_set_long_mode(ui->screen_gnss_label_fix_status, LV_LABEL_LONG_WRAP);
	lv_obj_set_pos(ui->screen_gnss_label_fix_status, 27, 65);
	lv_obj_set_size(ui->screen_gnss_label_fix_status, 195, 18);

	//Write style for screen_gnss_label_fix_status, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->screen_gnss_label_fix_status, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->screen_gnss_label_fix_status, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->screen_gnss_label_fix_status, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->screen_gnss_label_fix_status, &lv_font_montserratMedium_14, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->screen_gnss_label_fix_status, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_line_space(ui->screen_gnss_label_fix_status, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->screen_gnss_label_fix_status, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->screen_gnss_label_fix_status, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->screen_gnss_label_fix_status, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->screen_gnss_label_fix_status, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->screen_gnss_label_fix_status, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->screen_gnss_label_fix_status, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->screen_gnss_label_fix_status, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Update current screen layout.
	lv_obj_update_layout(ui->screen_gnss);

	
	//Init events for screen.
	events_init_screen_gnss(ui);
}
