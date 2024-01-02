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
#include <pgmspace.h>


FLASHMEM void setup_scr_screen_ambient(lv_ui *ui)
{
	//Write codes screen_ambient
	ui->screen_ambient = lv_obj_create(NULL);
	lv_obj_set_size(ui->screen_ambient, 240, 240);

	//Write style for screen_ambient, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_bg_opa(ui->screen_ambient, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui->screen_ambient, lv_color_hex(0x101418), LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes screen_ambient_btn_back
	ui->screen_ambient_btn_back = lv_btn_create(ui->screen_ambient);
	ui->screen_ambient_btn_back_label = lv_label_create(ui->screen_ambient_btn_back);
	lv_label_set_text(ui->screen_ambient_btn_back_label, "");
	lv_label_set_long_mode(ui->screen_ambient_btn_back_label, LV_LABEL_LONG_WRAP);
	lv_obj_align(ui->screen_ambient_btn_back_label, LV_ALIGN_LEFT_MID, 0, 0);
	lv_obj_set_style_pad_all(ui->screen_ambient_btn_back, 0, LV_STATE_DEFAULT);
	lv_obj_set_pos(ui->screen_ambient_btn_back, 0, 0);
	lv_obj_set_size(ui->screen_ambient_btn_back, 240, 50);

	//Write style for screen_ambient_btn_back, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_bg_opa(ui->screen_ambient_btn_back, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui->screen_ambient_btn_back, lv_color_hex(0x292831), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_width(ui->screen_ambient_btn_back, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_opa(ui->screen_ambient_btn_back, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_color(ui->screen_ambient_btn_back, lv_color_hex(0xD200AC), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_side(ui->screen_ambient_btn_back, LV_BORDER_SIDE_BOTTOM, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->screen_ambient_btn_back, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->screen_ambient_btn_back, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->screen_ambient_btn_back, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->screen_ambient_btn_back, &lv_font_FontAwesome5ProRegular_400_16, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->screen_ambient_btn_back, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes screen_ambient_label_back
	ui->screen_ambient_label_back = lv_label_create(ui->screen_ambient);
	lv_label_set_text(ui->screen_ambient_label_back, "");
	lv_label_set_long_mode(ui->screen_ambient_label_back, LV_LABEL_LONG_WRAP);
	lv_obj_set_pos(ui->screen_ambient_label_back, 50, 25);
	lv_obj_set_size(ui->screen_ambient_label_back, 23, 16);

	//Write style for screen_ambient_label_back, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->screen_ambient_label_back, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->screen_ambient_label_back, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->screen_ambient_label_back, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->screen_ambient_label_back, &lv_font_FontAwesome5ProRegular_400_16, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->screen_ambient_label_back, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_line_space(ui->screen_ambient_label_back, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->screen_ambient_label_back, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->screen_ambient_label_back, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->screen_ambient_label_back, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->screen_ambient_label_back, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->screen_ambient_label_back, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->screen_ambient_label_back, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->screen_ambient_label_back, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes screen_ambient_label_title
	ui->screen_ambient_label_title = lv_label_create(ui->screen_ambient);
	lv_label_set_text(ui->screen_ambient_label_title, "Ambient\nSensor");
	lv_label_set_long_mode(ui->screen_ambient_label_title, LV_LABEL_LONG_WRAP);
	lv_obj_set_pos(ui->screen_ambient_label_title, 60, 12);
	lv_obj_set_size(ui->screen_ambient_label_title, 120, 35);

	//Write style for screen_ambient_label_title, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->screen_ambient_label_title, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->screen_ambient_label_title, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->screen_ambient_label_title, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->screen_ambient_label_title, &lv_font_montserratMedium_16, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->screen_ambient_label_title, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_line_space(ui->screen_ambient_label_title, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->screen_ambient_label_title, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->screen_ambient_label_title, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->screen_ambient_label_title, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->screen_ambient_label_title, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->screen_ambient_label_title, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->screen_ambient_label_title, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->screen_ambient_label_title, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes screen_ambient_meter_temperature
	ui->screen_ambient_meter_temperature = lv_meter_create(ui->screen_ambient);
	// add scale screen_ambient_meter_temperature_scale_1
	lv_meter_scale_t *screen_ambient_meter_temperature_scale_1 = lv_meter_add_scale(ui->screen_ambient_meter_temperature);
	lv_meter_set_scale_ticks(ui->screen_ambient_meter_temperature, screen_ambient_meter_temperature_scale_1, 2, 1, 1, lv_color_hex(0x101418));

	// add arc for screen_ambient_meter_temperature_scale_1
	ui->screen_ambient_meter_temperature_scale_1_arc_0 = lv_meter_add_arc(ui->screen_ambient_meter_temperature, screen_ambient_meter_temperature_scale_1, 10, lv_color_hex(0x757478), -1);
	lv_meter_set_indicator_start_value(ui->screen_ambient_meter_temperature, ui->screen_ambient_meter_temperature_scale_1_arc_0, 0);
	lv_meter_set_indicator_end_value(ui->screen_ambient_meter_temperature, ui->screen_ambient_meter_temperature_scale_1_arc_0, 100);

	// add arc for screen_ambient_meter_temperature_scale_1
	ui->screen_ambient_meter_temperature_scale_1_arc_1 = lv_meter_add_arc(ui->screen_ambient_meter_temperature, screen_ambient_meter_temperature_scale_1, 10, lv_color_hex(0x00ff16), -1);
	lv_meter_set_indicator_start_value(ui->screen_ambient_meter_temperature, ui->screen_ambient_meter_temperature_scale_1_arc_1, 0);
	lv_meter_set_indicator_end_value(ui->screen_ambient_meter_temperature, ui->screen_ambient_meter_temperature_scale_1_arc_1, 0);
	lv_obj_set_pos(ui->screen_ambient_meter_temperature, 25, 80);
	lv_obj_set_size(ui->screen_ambient_meter_temperature, 90, 90);

	//Write style for screen_ambient_meter_temperature, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_bg_opa(ui->screen_ambient_meter_temperature, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->screen_ambient_meter_temperature, 200, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_width(ui->screen_ambient_meter_temperature, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->screen_ambient_meter_temperature, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write style for screen_ambient_meter_temperature, Part: LV_PART_TICKS, State: LV_STATE_DEFAULT.
	lv_obj_set_style_text_color(ui->screen_ambient_meter_temperature, lv_color_hex(0xffffff), LV_PART_TICKS|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->screen_ambient_meter_temperature, &lv_font_montserratMedium_14, LV_PART_TICKS|LV_STATE_DEFAULT);

	//Write style for screen_ambient_meter_temperature, Part: LV_PART_INDICATOR, State: LV_STATE_DEFAULT.
	lv_obj_set_style_bg_opa(ui->screen_ambient_meter_temperature, 0, LV_PART_INDICATOR|LV_STATE_DEFAULT);

	//Write codes screen_ambient_label_temperature_title
	ui->screen_ambient_label_temperature_title = lv_label_create(ui->screen_ambient);
	lv_label_set_text(ui->screen_ambient_label_temperature_title, "Temperature");
	lv_label_set_long_mode(ui->screen_ambient_label_temperature_title, LV_LABEL_LONG_WRAP);
	lv_obj_set_pos(ui->screen_ambient_label_temperature_title, 20, 70);
	lv_obj_set_size(ui->screen_ambient_label_temperature_title, 100, 15);

	//Write style for screen_ambient_label_temperature_title, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->screen_ambient_label_temperature_title, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->screen_ambient_label_temperature_title, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->screen_ambient_label_temperature_title, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->screen_ambient_label_temperature_title, &lv_font_montserratMedium_14, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->screen_ambient_label_temperature_title, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_line_space(ui->screen_ambient_label_temperature_title, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->screen_ambient_label_temperature_title, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->screen_ambient_label_temperature_title, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->screen_ambient_label_temperature_title, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->screen_ambient_label_temperature_title, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->screen_ambient_label_temperature_title, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->screen_ambient_label_temperature_title, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->screen_ambient_label_temperature_title, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes screen_ambient_meter_pressure
	ui->screen_ambient_meter_pressure = lv_meter_create(ui->screen_ambient);
	// add scale screen_ambient_meter_pressure_scale_1
	lv_meter_scale_t *screen_ambient_meter_pressure_scale_1 = lv_meter_add_scale(ui->screen_ambient_meter_pressure);
	lv_meter_set_scale_ticks(ui->screen_ambient_meter_pressure, screen_ambient_meter_pressure_scale_1, 2, 1, 1, lv_color_hex(0x101418));

	// add arc for screen_ambient_meter_pressure_scale_1
	ui->screen_ambient_meter_pressure_scale_1_arc_0 = lv_meter_add_arc(ui->screen_ambient_meter_pressure, screen_ambient_meter_pressure_scale_1, 10, lv_color_hex(0x757478), -1);
	lv_meter_set_indicator_start_value(ui->screen_ambient_meter_pressure, ui->screen_ambient_meter_pressure_scale_1_arc_0, 0);
	lv_meter_set_indicator_end_value(ui->screen_ambient_meter_pressure, ui->screen_ambient_meter_pressure_scale_1_arc_0, 100);

	// add arc for screen_ambient_meter_pressure_scale_1
	ui->screen_ambient_meter_pressure_scale_1_arc_1 = lv_meter_add_arc(ui->screen_ambient_meter_pressure, screen_ambient_meter_pressure_scale_1, 10, lv_color_hex(0x2195f6), -1);
	lv_meter_set_indicator_start_value(ui->screen_ambient_meter_pressure, ui->screen_ambient_meter_pressure_scale_1_arc_1, 0);
	lv_meter_set_indicator_end_value(ui->screen_ambient_meter_pressure, ui->screen_ambient_meter_pressure_scale_1_arc_1, 0);
	lv_obj_set_pos(ui->screen_ambient_meter_pressure, 125, 80);
	lv_obj_set_size(ui->screen_ambient_meter_pressure, 90, 90);

	//Write style for screen_ambient_meter_pressure, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_bg_opa(ui->screen_ambient_meter_pressure, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->screen_ambient_meter_pressure, 200, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_width(ui->screen_ambient_meter_pressure, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->screen_ambient_meter_pressure, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write style for screen_ambient_meter_pressure, Part: LV_PART_TICKS, State: LV_STATE_DEFAULT.
	lv_obj_set_style_text_color(ui->screen_ambient_meter_pressure, lv_color_hex(0xffffff), LV_PART_TICKS|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->screen_ambient_meter_pressure, &lv_font_montserratMedium_14, LV_PART_TICKS|LV_STATE_DEFAULT);

	//Write style for screen_ambient_meter_pressure, Part: LV_PART_INDICATOR, State: LV_STATE_DEFAULT.
	lv_obj_set_style_bg_opa(ui->screen_ambient_meter_pressure, 0, LV_PART_INDICATOR|LV_STATE_DEFAULT);

	//Write codes screen_ambient_label_pressure_title
	ui->screen_ambient_label_pressure_title = lv_label_create(ui->screen_ambient);
	lv_label_set_text(ui->screen_ambient_label_pressure_title, "Pressure");
	lv_label_set_long_mode(ui->screen_ambient_label_pressure_title, LV_LABEL_LONG_WRAP);
	lv_obj_set_pos(ui->screen_ambient_label_pressure_title, 125, 70);
	lv_obj_set_size(ui->screen_ambient_label_pressure_title, 90, 15);

	//Write style for screen_ambient_label_pressure_title, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->screen_ambient_label_pressure_title, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->screen_ambient_label_pressure_title, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->screen_ambient_label_pressure_title, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->screen_ambient_label_pressure_title, &lv_font_montserratMedium_14, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->screen_ambient_label_pressure_title, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_line_space(ui->screen_ambient_label_pressure_title, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->screen_ambient_label_pressure_title, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->screen_ambient_label_pressure_title, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->screen_ambient_label_pressure_title, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->screen_ambient_label_pressure_title, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->screen_ambient_label_pressure_title, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->screen_ambient_label_pressure_title, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->screen_ambient_label_pressure_title, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes screen_ambient_label_temperature
	ui->screen_ambient_label_temperature = lv_label_create(ui->screen_ambient);
	lv_label_set_text(ui->screen_ambient_label_temperature, "0.0 °C");
	lv_label_set_long_mode(ui->screen_ambient_label_temperature, LV_LABEL_LONG_WRAP);
	lv_obj_set_pos(ui->screen_ambient_label_temperature, 25, 155);
	lv_obj_set_size(ui->screen_ambient_label_temperature, 90, 15);

	//Write style for screen_ambient_label_temperature, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->screen_ambient_label_temperature, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->screen_ambient_label_temperature, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->screen_ambient_label_temperature, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->screen_ambient_label_temperature, &lv_font_montserratMedium_14, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->screen_ambient_label_temperature, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_line_space(ui->screen_ambient_label_temperature, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->screen_ambient_label_temperature, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->screen_ambient_label_temperature, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->screen_ambient_label_temperature, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->screen_ambient_label_temperature, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->screen_ambient_label_temperature, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->screen_ambient_label_temperature, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->screen_ambient_label_temperature, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes screen_ambient_label_pressure
	ui->screen_ambient_label_pressure = lv_label_create(ui->screen_ambient);
	lv_label_set_text(ui->screen_ambient_label_pressure, "0 hPa");
	lv_label_set_long_mode(ui->screen_ambient_label_pressure, LV_LABEL_LONG_WRAP);
	lv_obj_set_pos(ui->screen_ambient_label_pressure, 125, 155);
	lv_obj_set_size(ui->screen_ambient_label_pressure, 90, 15);

	//Write style for screen_ambient_label_pressure, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->screen_ambient_label_pressure, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->screen_ambient_label_pressure, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->screen_ambient_label_pressure, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->screen_ambient_label_pressure, &lv_font_montserratMedium_14, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->screen_ambient_label_pressure, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_line_space(ui->screen_ambient_label_pressure, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->screen_ambient_label_pressure, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->screen_ambient_label_pressure, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->screen_ambient_label_pressure, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->screen_ambient_label_pressure, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->screen_ambient_label_pressure, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->screen_ambient_label_pressure, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->screen_ambient_label_pressure, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes screen_ambient_label_altitude_title
	ui->screen_ambient_label_altitude_title = lv_label_create(ui->screen_ambient);
	lv_label_set_text(ui->screen_ambient_label_altitude_title, "Altitude:");
	lv_label_set_long_mode(ui->screen_ambient_label_altitude_title, LV_LABEL_LONG_WRAP);
	lv_obj_set_pos(ui->screen_ambient_label_altitude_title, 75, 182);
	lv_obj_set_size(ui->screen_ambient_label_altitude_title, 90, 15);

	//Write style for screen_ambient_label_altitude_title, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->screen_ambient_label_altitude_title, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->screen_ambient_label_altitude_title, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->screen_ambient_label_altitude_title, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->screen_ambient_label_altitude_title, &lv_font_montserratMedium_14, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->screen_ambient_label_altitude_title, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_line_space(ui->screen_ambient_label_altitude_title, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->screen_ambient_label_altitude_title, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->screen_ambient_label_altitude_title, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->screen_ambient_label_altitude_title, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->screen_ambient_label_altitude_title, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->screen_ambient_label_altitude_title, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->screen_ambient_label_altitude_title, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->screen_ambient_label_altitude_title, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes screen_ambient_label_altitude
	ui->screen_ambient_label_altitude = lv_label_create(ui->screen_ambient);
	lv_label_set_text(ui->screen_ambient_label_altitude, "0 m");
	lv_label_set_long_mode(ui->screen_ambient_label_altitude, LV_LABEL_LONG_WRAP);
	lv_obj_set_pos(ui->screen_ambient_label_altitude, 70, 203);
	lv_obj_set_size(ui->screen_ambient_label_altitude, 100, 18);

	//Write style for screen_ambient_label_altitude, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->screen_ambient_label_altitude, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->screen_ambient_label_altitude, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->screen_ambient_label_altitude, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->screen_ambient_label_altitude, &lv_font_montserratMedium_20, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->screen_ambient_label_altitude, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_line_space(ui->screen_ambient_label_altitude, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->screen_ambient_label_altitude, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->screen_ambient_label_altitude, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->screen_ambient_label_altitude, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->screen_ambient_label_altitude, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->screen_ambient_label_altitude, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->screen_ambient_label_altitude, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->screen_ambient_label_altitude, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Update current screen layout.
	lv_obj_update_layout(ui->screen_ambient);

	
	//Init events for screen.
	events_init_screen_ambient(ui);
}
