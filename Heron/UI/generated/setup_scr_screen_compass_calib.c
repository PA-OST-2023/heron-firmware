/*
* Copyright 2023 NXP
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


void setup_scr_screen_compass_calib(lv_ui *ui)
{
	//Write codes screen_compass_calib
	ui->screen_compass_calib = lv_obj_create(NULL);
	lv_obj_set_size(ui->screen_compass_calib, 240, 240);

	//Write style for screen_compass_calib, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_bg_opa(ui->screen_compass_calib, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui->screen_compass_calib, lv_color_hex(0x101418), LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes screen_compass_calib_btn_back
	ui->screen_compass_calib_btn_back = lv_btn_create(ui->screen_compass_calib);
	ui->screen_compass_calib_btn_back_label = lv_label_create(ui->screen_compass_calib_btn_back);
	lv_label_set_text(ui->screen_compass_calib_btn_back_label, "");
	lv_label_set_long_mode(ui->screen_compass_calib_btn_back_label, LV_LABEL_LONG_WRAP);
	lv_obj_align(ui->screen_compass_calib_btn_back_label, LV_ALIGN_LEFT_MID, 0, 0);
	lv_obj_set_style_pad_all(ui->screen_compass_calib_btn_back, 0, LV_STATE_DEFAULT);
	lv_obj_set_pos(ui->screen_compass_calib_btn_back, 0, 0);
	lv_obj_set_size(ui->screen_compass_calib_btn_back, 240, 50);

	//Write style for screen_compass_calib_btn_back, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_bg_opa(ui->screen_compass_calib_btn_back, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui->screen_compass_calib_btn_back, lv_color_hex(0x292831), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_width(ui->screen_compass_calib_btn_back, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_opa(ui->screen_compass_calib_btn_back, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_color(ui->screen_compass_calib_btn_back, lv_color_hex(0xD200AC), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_side(ui->screen_compass_calib_btn_back, LV_BORDER_SIDE_BOTTOM, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->screen_compass_calib_btn_back, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->screen_compass_calib_btn_back, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->screen_compass_calib_btn_back, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->screen_compass_calib_btn_back, &lv_font_FontAwesome5ProRegular_400_16, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->screen_compass_calib_btn_back, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes screen_compass_calib_label_back
	ui->screen_compass_calib_label_back = lv_label_create(ui->screen_compass_calib);
	lv_label_set_text(ui->screen_compass_calib_label_back, "");
	lv_label_set_long_mode(ui->screen_compass_calib_label_back, LV_LABEL_LONG_WRAP);
	lv_obj_set_pos(ui->screen_compass_calib_label_back, 50, 25);
	lv_obj_set_size(ui->screen_compass_calib_label_back, 23, 16);

	//Write style for screen_compass_calib_label_back, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->screen_compass_calib_label_back, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->screen_compass_calib_label_back, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->screen_compass_calib_label_back, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->screen_compass_calib_label_back, &lv_font_FontAwesome5ProRegular_400_16, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->screen_compass_calib_label_back, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_line_space(ui->screen_compass_calib_label_back, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->screen_compass_calib_label_back, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->screen_compass_calib_label_back, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->screen_compass_calib_label_back, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->screen_compass_calib_label_back, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->screen_compass_calib_label_back, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->screen_compass_calib_label_back, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->screen_compass_calib_label_back, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes screen_compass_calib_label_title
	ui->screen_compass_calib_label_title = lv_label_create(ui->screen_compass_calib);
	lv_label_set_text(ui->screen_compass_calib_label_title, "Calibration");
	lv_label_set_long_mode(ui->screen_compass_calib_label_title, LV_LABEL_LONG_WRAP);
	lv_obj_set_pos(ui->screen_compass_calib_label_title, 60, 20);
	lv_obj_set_size(ui->screen_compass_calib_label_title, 120, 18);

	//Write style for screen_compass_calib_label_title, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->screen_compass_calib_label_title, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->screen_compass_calib_label_title, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->screen_compass_calib_label_title, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->screen_compass_calib_label_title, &lv_font_montserratMedium_16, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->screen_compass_calib_label_title, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_line_space(ui->screen_compass_calib_label_title, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->screen_compass_calib_label_title, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->screen_compass_calib_label_title, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->screen_compass_calib_label_title, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->screen_compass_calib_label_title, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->screen_compass_calib_label_title, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->screen_compass_calib_label_title, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->screen_compass_calib_label_title, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes screen_compass_calib_meter_coverage
	ui->screen_compass_calib_meter_coverage = lv_meter_create(ui->screen_compass_calib);
	// add scale screen_compass_calib_meter_coverage_scale_1
	lv_meter_scale_t *screen_compass_calib_meter_coverage_scale_1 = lv_meter_add_scale(ui->screen_compass_calib_meter_coverage);
	lv_meter_set_scale_ticks(ui->screen_compass_calib_meter_coverage, screen_compass_calib_meter_coverage_scale_1, 2, 1, 1, lv_color_hex(0x101418));

	// add arc for screen_compass_calib_meter_coverage_scale_1
	lv_meter_indicator_t *screen_compass_calib_meter_coverage_scale_1_arc_0;
	screen_compass_calib_meter_coverage_scale_1_arc_0 = lv_meter_add_arc(ui->screen_compass_calib_meter_coverage, screen_compass_calib_meter_coverage_scale_1, 10, lv_color_hex(0x757478), -1);
	lv_meter_set_indicator_start_value(ui->screen_compass_calib_meter_coverage, screen_compass_calib_meter_coverage_scale_1_arc_0, 0);
	lv_meter_set_indicator_end_value(ui->screen_compass_calib_meter_coverage, screen_compass_calib_meter_coverage_scale_1_arc_0, 100);

	// add arc for screen_compass_calib_meter_coverage_scale_1
	lv_meter_indicator_t *screen_compass_calib_meter_coverage_scale_1_arc_1;
	screen_compass_calib_meter_coverage_scale_1_arc_1 = lv_meter_add_arc(ui->screen_compass_calib_meter_coverage, screen_compass_calib_meter_coverage_scale_1, 10, lv_color_hex(0xD200AC), -1);
	lv_meter_set_indicator_start_value(ui->screen_compass_calib_meter_coverage, screen_compass_calib_meter_coverage_scale_1_arc_1, 0);
	lv_meter_set_indicator_end_value(ui->screen_compass_calib_meter_coverage, screen_compass_calib_meter_coverage_scale_1_arc_1, 20);
	lv_obj_set_pos(ui->screen_compass_calib_meter_coverage, 53, 72);
	lv_obj_set_size(ui->screen_compass_calib_meter_coverage, 132, 132);

	//Write style for screen_compass_calib_meter_coverage, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_bg_opa(ui->screen_compass_calib_meter_coverage, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->screen_compass_calib_meter_coverage, 200, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_width(ui->screen_compass_calib_meter_coverage, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->screen_compass_calib_meter_coverage, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write style for screen_compass_calib_meter_coverage, Part: LV_PART_TICKS, State: LV_STATE_DEFAULT.
	lv_obj_set_style_text_color(ui->screen_compass_calib_meter_coverage, lv_color_hex(0xffffff), LV_PART_TICKS|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->screen_compass_calib_meter_coverage, &lv_font_montserratMedium_14, LV_PART_TICKS|LV_STATE_DEFAULT);

	//Write style for screen_compass_calib_meter_coverage, Part: LV_PART_INDICATOR, State: LV_STATE_DEFAULT.
	lv_obj_set_style_bg_opa(ui->screen_compass_calib_meter_coverage, 0, LV_PART_INDICATOR|LV_STATE_DEFAULT);

	//Write codes screen_compass_calib_label_coverage_title
	ui->screen_compass_calib_label_coverage_title = lv_label_create(ui->screen_compass_calib);
	lv_label_set_text(ui->screen_compass_calib_label_coverage_title, "Sphere Coverage");
	lv_label_set_long_mode(ui->screen_compass_calib_label_coverage_title, LV_LABEL_LONG_WRAP);
	lv_obj_set_pos(ui->screen_compass_calib_label_coverage_title, 50, 62);
	lv_obj_set_size(ui->screen_compass_calib_label_coverage_title, 140, 18);

	//Write style for screen_compass_calib_label_coverage_title, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->screen_compass_calib_label_coverage_title, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->screen_compass_calib_label_coverage_title, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->screen_compass_calib_label_coverage_title, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->screen_compass_calib_label_coverage_title, &lv_font_montserratMedium_14, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->screen_compass_calib_label_coverage_title, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_line_space(ui->screen_compass_calib_label_coverage_title, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->screen_compass_calib_label_coverage_title, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->screen_compass_calib_label_coverage_title, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->screen_compass_calib_label_coverage_title, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->screen_compass_calib_label_coverage_title, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->screen_compass_calib_label_coverage_title, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->screen_compass_calib_label_coverage_title, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->screen_compass_calib_label_coverage_title, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes screen_compass_calib_label_coverage
	ui->screen_compass_calib_label_coverage = lv_label_create(ui->screen_compass_calib);
	lv_label_set_text(ui->screen_compass_calib_label_coverage, "0 %");
	lv_label_set_long_mode(ui->screen_compass_calib_label_coverage, LV_LABEL_LONG_WRAP);
	lv_obj_set_pos(ui->screen_compass_calib_label_coverage, 80, 126);
	lv_obj_set_size(ui->screen_compass_calib_label_coverage, 80, 18);

	//Write style for screen_compass_calib_label_coverage, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->screen_compass_calib_label_coverage, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->screen_compass_calib_label_coverage, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->screen_compass_calib_label_coverage, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->screen_compass_calib_label_coverage, &lv_font_montserratMedium_20, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->screen_compass_calib_label_coverage, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_line_space(ui->screen_compass_calib_label_coverage, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->screen_compass_calib_label_coverage, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->screen_compass_calib_label_coverage, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->screen_compass_calib_label_coverage, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->screen_compass_calib_label_coverage, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->screen_compass_calib_label_coverage, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->screen_compass_calib_label_coverage, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->screen_compass_calib_label_coverage, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes screen_compass_calib_label_variance
	ui->screen_compass_calib_label_variance = lv_label_create(ui->screen_compass_calib);
	lv_label_set_text(ui->screen_compass_calib_label_variance, "Variance: 0.0");
	lv_label_set_long_mode(ui->screen_compass_calib_label_variance, LV_LABEL_LONG_WRAP);
	lv_obj_set_pos(ui->screen_compass_calib_label_variance, 50, 212);
	lv_obj_set_size(ui->screen_compass_calib_label_variance, 140, 18);

	//Write style for screen_compass_calib_label_variance, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->screen_compass_calib_label_variance, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->screen_compass_calib_label_variance, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->screen_compass_calib_label_variance, lv_color_hex(0x8a8a8a), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->screen_compass_calib_label_variance, &lv_font_montserratMedium_12, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->screen_compass_calib_label_variance, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_line_space(ui->screen_compass_calib_label_variance, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->screen_compass_calib_label_variance, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->screen_compass_calib_label_variance, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->screen_compass_calib_label_variance, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->screen_compass_calib_label_variance, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->screen_compass_calib_label_variance, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->screen_compass_calib_label_variance, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->screen_compass_calib_label_variance, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes screen_compass_calib_label_fit_error
	ui->screen_compass_calib_label_fit_error = lv_label_create(ui->screen_compass_calib);
	lv_label_set_text(ui->screen_compass_calib_label_fit_error, "Fit Error: 0.0 %");
	lv_label_set_long_mode(ui->screen_compass_calib_label_fit_error, LV_LABEL_LONG_WRAP);
	lv_obj_set_pos(ui->screen_compass_calib_label_fit_error, 50, 198);
	lv_obj_set_size(ui->screen_compass_calib_label_fit_error, 140, 18);

	//Write style for screen_compass_calib_label_fit_error, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->screen_compass_calib_label_fit_error, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->screen_compass_calib_label_fit_error, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->screen_compass_calib_label_fit_error, lv_color_hex(0x8a8a8a), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->screen_compass_calib_label_fit_error, &lv_font_montserratMedium_12, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->screen_compass_calib_label_fit_error, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_line_space(ui->screen_compass_calib_label_fit_error, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->screen_compass_calib_label_fit_error, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->screen_compass_calib_label_fit_error, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->screen_compass_calib_label_fit_error, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->screen_compass_calib_label_fit_error, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->screen_compass_calib_label_fit_error, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->screen_compass_calib_label_fit_error, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->screen_compass_calib_label_fit_error, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes screen_compass_calib_label_wobble_error
	ui->screen_compass_calib_label_wobble_error = lv_label_create(ui->screen_compass_calib);
	lv_label_set_text(ui->screen_compass_calib_label_wobble_error, "Wobble Error: 0.0 %");
	lv_label_set_long_mode(ui->screen_compass_calib_label_wobble_error, LV_LABEL_LONG_WRAP);
	lv_obj_set_pos(ui->screen_compass_calib_label_wobble_error, 50, 184);
	lv_obj_set_size(ui->screen_compass_calib_label_wobble_error, 140, 18);

	//Write style for screen_compass_calib_label_wobble_error, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->screen_compass_calib_label_wobble_error, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->screen_compass_calib_label_wobble_error, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->screen_compass_calib_label_wobble_error, lv_color_hex(0x8a8a8a), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->screen_compass_calib_label_wobble_error, &lv_font_montserratMedium_12, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->screen_compass_calib_label_wobble_error, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_line_space(ui->screen_compass_calib_label_wobble_error, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->screen_compass_calib_label_wobble_error, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->screen_compass_calib_label_wobble_error, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->screen_compass_calib_label_wobble_error, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->screen_compass_calib_label_wobble_error, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->screen_compass_calib_label_wobble_error, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->screen_compass_calib_label_wobble_error, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->screen_compass_calib_label_wobble_error, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Update current screen layout.
	lv_obj_update_layout(ui->screen_compass_calib);

	
	//Init events for screen.
	events_init_screen_compass_calib(ui);
}
