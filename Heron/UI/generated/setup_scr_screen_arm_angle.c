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


void setup_scr_screen_arm_angle(lv_ui *ui)
{
	//Write codes screen_arm_angle
	ui->screen_arm_angle = lv_obj_create(NULL);
	lv_obj_set_size(ui->screen_arm_angle, 240, 240);

	//Write style for screen_arm_angle, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_bg_opa(ui->screen_arm_angle, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui->screen_arm_angle, lv_color_hex(0x101418), LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes screen_arm_angle_btn_calib
	ui->screen_arm_angle_btn_calib = lv_btn_create(ui->screen_arm_angle);
	ui->screen_arm_angle_btn_calib_label = lv_label_create(ui->screen_arm_angle_btn_calib);
	lv_label_set_text(ui->screen_arm_angle_btn_calib_label, "");
	lv_label_set_long_mode(ui->screen_arm_angle_btn_calib_label, LV_LABEL_LONG_WRAP);
	lv_obj_align(ui->screen_arm_angle_btn_calib_label, LV_ALIGN_LEFT_MID, 0, 0);
	lv_obj_set_style_pad_all(ui->screen_arm_angle_btn_calib, 0, LV_STATE_DEFAULT);
	lv_obj_set_pos(ui->screen_arm_angle_btn_calib, 0, 200);
	lv_obj_set_size(ui->screen_arm_angle_btn_calib, 240, 40);

	//Write style for screen_arm_angle_btn_calib, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_bg_opa(ui->screen_arm_angle_btn_calib, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui->screen_arm_angle_btn_calib, lv_color_hex(0x292831), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_width(ui->screen_arm_angle_btn_calib, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_opa(ui->screen_arm_angle_btn_calib, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_color(ui->screen_arm_angle_btn_calib, lv_color_hex(0x757478), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_side(ui->screen_arm_angle_btn_calib, LV_BORDER_SIDE_TOP, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->screen_arm_angle_btn_calib, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->screen_arm_angle_btn_calib, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->screen_arm_angle_btn_calib, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->screen_arm_angle_btn_calib, &lv_font_FontAwesome5ProRegular_400_16, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->screen_arm_angle_btn_calib, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes screen_arm_angle_meter_angle
	ui->screen_arm_angle_meter_angle = lv_meter_create(ui->screen_arm_angle);
	// add scale screen_arm_angle_meter_angle_scale_1
	lv_meter_scale_t *screen_arm_angle_meter_angle_scale_1 = lv_meter_add_scale(ui->screen_arm_angle_meter_angle);
	lv_meter_set_scale_ticks(ui->screen_arm_angle_meter_angle, screen_arm_angle_meter_angle_scale_1, 2, 1, 1, lv_color_hex(0x101418));
	lv_meter_set_scale_range(ui->screen_arm_angle_meter_angle, screen_arm_angle_meter_angle_scale_1, 0, 90, 90, 90);

	// add arc for screen_arm_angle_meter_angle_scale_1
	lv_meter_indicator_t *screen_arm_angle_meter_angle_scale_1_arc_0;
	screen_arm_angle_meter_angle_scale_1_arc_0 = lv_meter_add_arc(ui->screen_arm_angle_meter_angle, screen_arm_angle_meter_angle_scale_1, 14, lv_color_hex(0x757478), -1);
	lv_meter_set_indicator_start_value(ui->screen_arm_angle_meter_angle, screen_arm_angle_meter_angle_scale_1_arc_0, 0);
	lv_meter_set_indicator_end_value(ui->screen_arm_angle_meter_angle, screen_arm_angle_meter_angle_scale_1_arc_0, 90);

	// add arc for screen_arm_angle_meter_angle_scale_1
	lv_meter_indicator_t *screen_arm_angle_meter_angle_scale_1_arc_1;
	screen_arm_angle_meter_angle_scale_1_arc_1 = lv_meter_add_arc(ui->screen_arm_angle_meter_angle, screen_arm_angle_meter_angle_scale_1, 14, lv_color_hex(0xD200AC), -1);
	lv_meter_set_indicator_start_value(ui->screen_arm_angle_meter_angle, screen_arm_angle_meter_angle_scale_1_arc_1, 0);
	lv_meter_set_indicator_end_value(ui->screen_arm_angle_meter_angle, screen_arm_angle_meter_angle_scale_1_arc_1, 0);
	lv_obj_set_pos(ui->screen_arm_angle_meter_angle, 45, -10);
	lv_obj_set_size(ui->screen_arm_angle_meter_angle, 150, 150);

	//Write style for screen_arm_angle_meter_angle, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_bg_opa(ui->screen_arm_angle_meter_angle, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->screen_arm_angle_meter_angle, 200, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_width(ui->screen_arm_angle_meter_angle, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->screen_arm_angle_meter_angle, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write style for screen_arm_angle_meter_angle, Part: LV_PART_TICKS, State: LV_STATE_DEFAULT.
	lv_obj_set_style_text_color(ui->screen_arm_angle_meter_angle, lv_color_hex(0xffffff), LV_PART_TICKS|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->screen_arm_angle_meter_angle, &lv_font_montserratMedium_14, LV_PART_TICKS|LV_STATE_DEFAULT);

	//Write style for screen_arm_angle_meter_angle, Part: LV_PART_INDICATOR, State: LV_STATE_DEFAULT.
	lv_obj_set_style_bg_opa(ui->screen_arm_angle_meter_angle, 0, LV_PART_INDICATOR|LV_STATE_DEFAULT);

	//Write codes screen_arm_angle_label_angle
	ui->screen_arm_angle_label_angle = lv_label_create(ui->screen_arm_angle);
	lv_label_set_text(ui->screen_arm_angle_label_angle, "0.0°");
	lv_label_set_long_mode(ui->screen_arm_angle_label_angle, LV_LABEL_LONG_WRAP);
	lv_obj_set_pos(ui->screen_arm_angle_label_angle, 98, 74);
	lv_obj_set_size(ui->screen_arm_angle_label_angle, 72, 22);

	//Write style for screen_arm_angle_label_angle, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->screen_arm_angle_label_angle, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->screen_arm_angle_label_angle, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->screen_arm_angle_label_angle, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->screen_arm_angle_label_angle, &lv_font_montserratMedium_20, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->screen_arm_angle_label_angle, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_line_space(ui->screen_arm_angle_label_angle, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->screen_arm_angle_label_angle, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->screen_arm_angle_label_angle, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->screen_arm_angle_label_angle, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->screen_arm_angle_label_angle, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->screen_arm_angle_label_angle, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->screen_arm_angle_label_angle, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->screen_arm_angle_label_angle, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes screen_arm_angle_label_magnet_too_strong
	ui->screen_arm_angle_label_magnet_too_strong = lv_label_create(ui->screen_arm_angle);
	lv_label_set_text(ui->screen_arm_angle_label_magnet_too_strong, "Magnet Too Strong:");
	lv_label_set_long_mode(ui->screen_arm_angle_label_magnet_too_strong, LV_LABEL_LONG_WRAP);
	lv_obj_set_pos(ui->screen_arm_angle_label_magnet_too_strong, 33, 175);
	lv_obj_set_size(ui->screen_arm_angle_label_magnet_too_strong, 150, 15);

	//Write style for screen_arm_angle_label_magnet_too_strong, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->screen_arm_angle_label_magnet_too_strong, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->screen_arm_angle_label_magnet_too_strong, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->screen_arm_angle_label_magnet_too_strong, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->screen_arm_angle_label_magnet_too_strong, &lv_font_montserratMedium_14, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->screen_arm_angle_label_magnet_too_strong, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_line_space(ui->screen_arm_angle_label_magnet_too_strong, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->screen_arm_angle_label_magnet_too_strong, LV_TEXT_ALIGN_RIGHT, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->screen_arm_angle_label_magnet_too_strong, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->screen_arm_angle_label_magnet_too_strong, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->screen_arm_angle_label_magnet_too_strong, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->screen_arm_angle_label_magnet_too_strong, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->screen_arm_angle_label_magnet_too_strong, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->screen_arm_angle_label_magnet_too_strong, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes screen_arm_angle_label_magnet_too_weak
	ui->screen_arm_angle_label_magnet_too_weak = lv_label_create(ui->screen_arm_angle);
	lv_label_set_text(ui->screen_arm_angle_label_magnet_too_weak, "Magnet Too Weak:");
	lv_label_set_long_mode(ui->screen_arm_angle_label_magnet_too_weak, LV_LABEL_LONG_WRAP);
	lv_obj_set_pos(ui->screen_arm_angle_label_magnet_too_weak, 33, 155);
	lv_obj_set_size(ui->screen_arm_angle_label_magnet_too_weak, 150, 15);

	//Write style for screen_arm_angle_label_magnet_too_weak, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->screen_arm_angle_label_magnet_too_weak, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->screen_arm_angle_label_magnet_too_weak, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->screen_arm_angle_label_magnet_too_weak, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->screen_arm_angle_label_magnet_too_weak, &lv_font_montserratMedium_14, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->screen_arm_angle_label_magnet_too_weak, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_line_space(ui->screen_arm_angle_label_magnet_too_weak, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->screen_arm_angle_label_magnet_too_weak, LV_TEXT_ALIGN_RIGHT, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->screen_arm_angle_label_magnet_too_weak, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->screen_arm_angle_label_magnet_too_weak, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->screen_arm_angle_label_magnet_too_weak, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->screen_arm_angle_label_magnet_too_weak, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->screen_arm_angle_label_magnet_too_weak, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->screen_arm_angle_label_magnet_too_weak, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes screen_arm_angle_label_magnet_detected
	ui->screen_arm_angle_label_magnet_detected = lv_label_create(ui->screen_arm_angle);
	lv_label_set_text(ui->screen_arm_angle_label_magnet_detected, "Magnet Detected:");
	lv_label_set_long_mode(ui->screen_arm_angle_label_magnet_detected, LV_LABEL_LONG_WRAP);
	lv_obj_set_pos(ui->screen_arm_angle_label_magnet_detected, 33, 135);
	lv_obj_set_size(ui->screen_arm_angle_label_magnet_detected, 150, 15);

	//Write style for screen_arm_angle_label_magnet_detected, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->screen_arm_angle_label_magnet_detected, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->screen_arm_angle_label_magnet_detected, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->screen_arm_angle_label_magnet_detected, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->screen_arm_angle_label_magnet_detected, &lv_font_montserratMedium_14, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->screen_arm_angle_label_magnet_detected, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_line_space(ui->screen_arm_angle_label_magnet_detected, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->screen_arm_angle_label_magnet_detected, LV_TEXT_ALIGN_RIGHT, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->screen_arm_angle_label_magnet_detected, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->screen_arm_angle_label_magnet_detected, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->screen_arm_angle_label_magnet_detected, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->screen_arm_angle_label_magnet_detected, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->screen_arm_angle_label_magnet_detected, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->screen_arm_angle_label_magnet_detected, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes screen_arm_angle_cont_magnet_too_strong
	ui->screen_arm_angle_cont_magnet_too_strong = lv_obj_create(ui->screen_arm_angle);
	lv_obj_set_pos(ui->screen_arm_angle_cont_magnet_too_strong, 190, 178);
	lv_obj_set_size(ui->screen_arm_angle_cont_magnet_too_strong, 10, 10);
	lv_obj_set_scrollbar_mode(ui->screen_arm_angle_cont_magnet_too_strong, LV_SCROLLBAR_MODE_OFF);

	//Write style for screen_arm_angle_cont_magnet_too_strong, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->screen_arm_angle_cont_magnet_too_strong, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_opa(ui->screen_arm_angle_cont_magnet_too_strong, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_color(ui->screen_arm_angle_cont_magnet_too_strong, lv_color_hex(0x757478), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_side(ui->screen_arm_angle_cont_magnet_too_strong, LV_BORDER_SIDE_FULL, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->screen_arm_angle_cont_magnet_too_strong, 5, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->screen_arm_angle_cont_magnet_too_strong, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui->screen_arm_angle_cont_magnet_too_strong, lv_color_hex(0x757478), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->screen_arm_angle_cont_magnet_too_strong, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->screen_arm_angle_cont_magnet_too_strong, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->screen_arm_angle_cont_magnet_too_strong, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->screen_arm_angle_cont_magnet_too_strong, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->screen_arm_angle_cont_magnet_too_strong, 4, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_color(ui->screen_arm_angle_cont_magnet_too_strong, lv_color_hex(0x757478), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_opa(ui->screen_arm_angle_cont_magnet_too_strong, 69, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_spread(ui->screen_arm_angle_cont_magnet_too_strong, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_ofs_x(ui->screen_arm_angle_cont_magnet_too_strong, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_ofs_y(ui->screen_arm_angle_cont_magnet_too_strong, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes screen_arm_angle_cont_magnet_too_weak
	ui->screen_arm_angle_cont_magnet_too_weak = lv_obj_create(ui->screen_arm_angle);
	lv_obj_set_pos(ui->screen_arm_angle_cont_magnet_too_weak, 190, 158);
	lv_obj_set_size(ui->screen_arm_angle_cont_magnet_too_weak, 10, 10);
	lv_obj_set_scrollbar_mode(ui->screen_arm_angle_cont_magnet_too_weak, LV_SCROLLBAR_MODE_OFF);

	//Write style for screen_arm_angle_cont_magnet_too_weak, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->screen_arm_angle_cont_magnet_too_weak, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_opa(ui->screen_arm_angle_cont_magnet_too_weak, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_color(ui->screen_arm_angle_cont_magnet_too_weak, lv_color_hex(0x757478), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_side(ui->screen_arm_angle_cont_magnet_too_weak, LV_BORDER_SIDE_FULL, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->screen_arm_angle_cont_magnet_too_weak, 5, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->screen_arm_angle_cont_magnet_too_weak, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui->screen_arm_angle_cont_magnet_too_weak, lv_color_hex(0x757478), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->screen_arm_angle_cont_magnet_too_weak, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->screen_arm_angle_cont_magnet_too_weak, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->screen_arm_angle_cont_magnet_too_weak, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->screen_arm_angle_cont_magnet_too_weak, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->screen_arm_angle_cont_magnet_too_weak, 4, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_color(ui->screen_arm_angle_cont_magnet_too_weak, lv_color_hex(0x757478), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_opa(ui->screen_arm_angle_cont_magnet_too_weak, 69, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_spread(ui->screen_arm_angle_cont_magnet_too_weak, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_ofs_x(ui->screen_arm_angle_cont_magnet_too_weak, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_ofs_y(ui->screen_arm_angle_cont_magnet_too_weak, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes screen_arm_angle_cont_magnet_detected
	ui->screen_arm_angle_cont_magnet_detected = lv_obj_create(ui->screen_arm_angle);
	lv_obj_set_pos(ui->screen_arm_angle_cont_magnet_detected, 190, 138);
	lv_obj_set_size(ui->screen_arm_angle_cont_magnet_detected, 10, 10);
	lv_obj_set_scrollbar_mode(ui->screen_arm_angle_cont_magnet_detected, LV_SCROLLBAR_MODE_OFF);

	//Write style for screen_arm_angle_cont_magnet_detected, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->screen_arm_angle_cont_magnet_detected, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_opa(ui->screen_arm_angle_cont_magnet_detected, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_color(ui->screen_arm_angle_cont_magnet_detected, lv_color_hex(0x757478), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_side(ui->screen_arm_angle_cont_magnet_detected, LV_BORDER_SIDE_FULL, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->screen_arm_angle_cont_magnet_detected, 5, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->screen_arm_angle_cont_magnet_detected, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui->screen_arm_angle_cont_magnet_detected, lv_color_hex(0x757478), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->screen_arm_angle_cont_magnet_detected, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->screen_arm_angle_cont_magnet_detected, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->screen_arm_angle_cont_magnet_detected, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->screen_arm_angle_cont_magnet_detected, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->screen_arm_angle_cont_magnet_detected, 4, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_color(ui->screen_arm_angle_cont_magnet_detected, lv_color_hex(0x757478), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_opa(ui->screen_arm_angle_cont_magnet_detected, 69, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_spread(ui->screen_arm_angle_cont_magnet_detected, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_ofs_x(ui->screen_arm_angle_cont_magnet_detected, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_ofs_y(ui->screen_arm_angle_cont_magnet_detected, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes screen_arm_angle_btn_back
	ui->screen_arm_angle_btn_back = lv_btn_create(ui->screen_arm_angle);
	ui->screen_arm_angle_btn_back_label = lv_label_create(ui->screen_arm_angle_btn_back);
	lv_label_set_text(ui->screen_arm_angle_btn_back_label, "");
	lv_label_set_long_mode(ui->screen_arm_angle_btn_back_label, LV_LABEL_LONG_WRAP);
	lv_obj_align(ui->screen_arm_angle_btn_back_label, LV_ALIGN_LEFT_MID, 0, 0);
	lv_obj_set_style_pad_all(ui->screen_arm_angle_btn_back, 0, LV_STATE_DEFAULT);
	lv_obj_set_pos(ui->screen_arm_angle_btn_back, 0, 0);
	lv_obj_set_size(ui->screen_arm_angle_btn_back, 240, 50);

	//Write style for screen_arm_angle_btn_back, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_bg_opa(ui->screen_arm_angle_btn_back, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui->screen_arm_angle_btn_back, lv_color_hex(0x292831), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_width(ui->screen_arm_angle_btn_back, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_opa(ui->screen_arm_angle_btn_back, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_color(ui->screen_arm_angle_btn_back, lv_color_hex(0xD200AC), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_side(ui->screen_arm_angle_btn_back, LV_BORDER_SIDE_BOTTOM, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->screen_arm_angle_btn_back, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->screen_arm_angle_btn_back, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->screen_arm_angle_btn_back, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->screen_arm_angle_btn_back, &lv_font_FontAwesome5ProRegular_400_16, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->screen_arm_angle_btn_back, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes screen_arm_angle_label_calib
	ui->screen_arm_angle_label_calib = lv_label_create(ui->screen_arm_angle);
	lv_label_set_text(ui->screen_arm_angle_label_calib, "Calibration");
	lv_label_set_long_mode(ui->screen_arm_angle_label_calib, LV_LABEL_LONG_WRAP);
	lv_obj_set_pos(ui->screen_arm_angle_label_calib, 60, 210);
	lv_obj_set_size(ui->screen_arm_angle_label_calib, 120, 18);

	//Write style for screen_arm_angle_label_calib, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->screen_arm_angle_label_calib, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->screen_arm_angle_label_calib, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->screen_arm_angle_label_calib, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->screen_arm_angle_label_calib, &lv_font_montserratMedium_16, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->screen_arm_angle_label_calib, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_line_space(ui->screen_arm_angle_label_calib, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->screen_arm_angle_label_calib, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->screen_arm_angle_label_calib, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->screen_arm_angle_label_calib, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->screen_arm_angle_label_calib, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->screen_arm_angle_label_calib, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->screen_arm_angle_label_calib, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->screen_arm_angle_label_calib, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes screen_arm_angle_label_back
	ui->screen_arm_angle_label_back = lv_label_create(ui->screen_arm_angle);
	lv_label_set_text(ui->screen_arm_angle_label_back, "");
	lv_label_set_long_mode(ui->screen_arm_angle_label_back, LV_LABEL_LONG_WRAP);
	lv_obj_set_pos(ui->screen_arm_angle_label_back, 50, 25);
	lv_obj_set_size(ui->screen_arm_angle_label_back, 23, 16);

	//Write style for screen_arm_angle_label_back, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->screen_arm_angle_label_back, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->screen_arm_angle_label_back, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->screen_arm_angle_label_back, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->screen_arm_angle_label_back, &lv_font_FontAwesome5ProRegular_400_16, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->screen_arm_angle_label_back, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_line_space(ui->screen_arm_angle_label_back, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->screen_arm_angle_label_back, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->screen_arm_angle_label_back, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->screen_arm_angle_label_back, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->screen_arm_angle_label_back, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->screen_arm_angle_label_back, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->screen_arm_angle_label_back, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->screen_arm_angle_label_back, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes screen_arm_angle_label_title
	ui->screen_arm_angle_label_title = lv_label_create(ui->screen_arm_angle);
	lv_label_set_text(ui->screen_arm_angle_label_title, "Arm Angle");
	lv_label_set_long_mode(ui->screen_arm_angle_label_title, LV_LABEL_LONG_WRAP);
	lv_obj_set_pos(ui->screen_arm_angle_label_title, 60, 20);
	lv_obj_set_size(ui->screen_arm_angle_label_title, 120, 18);

	//Write style for screen_arm_angle_label_title, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->screen_arm_angle_label_title, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->screen_arm_angle_label_title, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->screen_arm_angle_label_title, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->screen_arm_angle_label_title, &lv_font_montserratMedium_16, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->screen_arm_angle_label_title, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_line_space(ui->screen_arm_angle_label_title, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->screen_arm_angle_label_title, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->screen_arm_angle_label_title, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->screen_arm_angle_label_title, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->screen_arm_angle_label_title, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->screen_arm_angle_label_title, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->screen_arm_angle_label_title, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->screen_arm_angle_label_title, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Update current screen layout.
	lv_obj_update_layout(ui->screen_arm_angle);

	
	//Init events for screen.
	events_init_screen_arm_angle(ui);
}
