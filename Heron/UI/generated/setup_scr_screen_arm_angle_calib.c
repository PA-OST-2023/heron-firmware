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


void setup_scr_screen_arm_angle_calib(lv_ui *ui)
{
	//Write codes screen_arm_angle_calib
	ui->screen_arm_angle_calib = lv_obj_create(NULL);
	lv_obj_set_size(ui->screen_arm_angle_calib, 240, 240);

	//Write style for screen_arm_angle_calib, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_bg_opa(ui->screen_arm_angle_calib, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui->screen_arm_angle_calib, lv_color_hex(0x101418), LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes screen_arm_angle_calib_btn_confirm
	ui->screen_arm_angle_calib_btn_confirm = lv_btn_create(ui->screen_arm_angle_calib);
	ui->screen_arm_angle_calib_btn_confirm_label = lv_label_create(ui->screen_arm_angle_calib_btn_confirm);
	lv_label_set_text(ui->screen_arm_angle_calib_btn_confirm_label, "");
	lv_label_set_long_mode(ui->screen_arm_angle_calib_btn_confirm_label, LV_LABEL_LONG_WRAP);
	lv_obj_align(ui->screen_arm_angle_calib_btn_confirm_label, LV_ALIGN_LEFT_MID, 0, 0);
	lv_obj_set_style_pad_all(ui->screen_arm_angle_calib_btn_confirm, 0, LV_STATE_DEFAULT);
	lv_obj_set_pos(ui->screen_arm_angle_calib_btn_confirm, 0, 200);
	lv_obj_set_size(ui->screen_arm_angle_calib_btn_confirm, 240, 40);

	//Write style for screen_arm_angle_calib_btn_confirm, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_bg_opa(ui->screen_arm_angle_calib_btn_confirm, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui->screen_arm_angle_calib_btn_confirm, lv_color_hex(0x292831), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_width(ui->screen_arm_angle_calib_btn_confirm, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_opa(ui->screen_arm_angle_calib_btn_confirm, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_color(ui->screen_arm_angle_calib_btn_confirm, lv_color_hex(0x00c92c), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_side(ui->screen_arm_angle_calib_btn_confirm, LV_BORDER_SIDE_TOP, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->screen_arm_angle_calib_btn_confirm, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->screen_arm_angle_calib_btn_confirm, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->screen_arm_angle_calib_btn_confirm, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->screen_arm_angle_calib_btn_confirm, &lv_font_FontAwesome5ProRegular_400_16, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->screen_arm_angle_calib_btn_confirm, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes screen_arm_angle_calib_label_confirm
	ui->screen_arm_angle_calib_label_confirm = lv_label_create(ui->screen_arm_angle_calib);
	lv_label_set_text(ui->screen_arm_angle_calib_label_confirm, "Confirm");
	lv_label_set_long_mode(ui->screen_arm_angle_calib_label_confirm, LV_LABEL_LONG_WRAP);
	lv_obj_set_pos(ui->screen_arm_angle_calib_label_confirm, 60, 210);
	lv_obj_set_size(ui->screen_arm_angle_calib_label_confirm, 120, 18);

	//Write style for screen_arm_angle_calib_label_confirm, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->screen_arm_angle_calib_label_confirm, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->screen_arm_angle_calib_label_confirm, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->screen_arm_angle_calib_label_confirm, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->screen_arm_angle_calib_label_confirm, &lv_font_montserratMedium_16, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->screen_arm_angle_calib_label_confirm, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_line_space(ui->screen_arm_angle_calib_label_confirm, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->screen_arm_angle_calib_label_confirm, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->screen_arm_angle_calib_label_confirm, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->screen_arm_angle_calib_label_confirm, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->screen_arm_angle_calib_label_confirm, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->screen_arm_angle_calib_label_confirm, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->screen_arm_angle_calib_label_confirm, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->screen_arm_angle_calib_label_confirm, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes screen_arm_angle_calib_btn_back
	ui->screen_arm_angle_calib_btn_back = lv_btn_create(ui->screen_arm_angle_calib);
	ui->screen_arm_angle_calib_btn_back_label = lv_label_create(ui->screen_arm_angle_calib_btn_back);
	lv_label_set_text(ui->screen_arm_angle_calib_btn_back_label, "");
	lv_label_set_long_mode(ui->screen_arm_angle_calib_btn_back_label, LV_LABEL_LONG_WRAP);
	lv_obj_align(ui->screen_arm_angle_calib_btn_back_label, LV_ALIGN_LEFT_MID, 0, 0);
	lv_obj_set_style_pad_all(ui->screen_arm_angle_calib_btn_back, 0, LV_STATE_DEFAULT);
	lv_obj_set_pos(ui->screen_arm_angle_calib_btn_back, 0, 0);
	lv_obj_set_size(ui->screen_arm_angle_calib_btn_back, 240, 50);

	//Write style for screen_arm_angle_calib_btn_back, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_bg_opa(ui->screen_arm_angle_calib_btn_back, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui->screen_arm_angle_calib_btn_back, lv_color_hex(0x292831), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_width(ui->screen_arm_angle_calib_btn_back, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_opa(ui->screen_arm_angle_calib_btn_back, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_color(ui->screen_arm_angle_calib_btn_back, lv_color_hex(0xD200AC), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_side(ui->screen_arm_angle_calib_btn_back, LV_BORDER_SIDE_BOTTOM, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->screen_arm_angle_calib_btn_back, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->screen_arm_angle_calib_btn_back, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->screen_arm_angle_calib_btn_back, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->screen_arm_angle_calib_btn_back, &lv_font_FontAwesome5ProRegular_400_16, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->screen_arm_angle_calib_btn_back, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes screen_arm_angle_calib_label_back
	ui->screen_arm_angle_calib_label_back = lv_label_create(ui->screen_arm_angle_calib);
	lv_label_set_text(ui->screen_arm_angle_calib_label_back, "");
	lv_label_set_long_mode(ui->screen_arm_angle_calib_label_back, LV_LABEL_LONG_WRAP);
	lv_obj_set_pos(ui->screen_arm_angle_calib_label_back, 50, 25);
	lv_obj_set_size(ui->screen_arm_angle_calib_label_back, 23, 16);

	//Write style for screen_arm_angle_calib_label_back, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->screen_arm_angle_calib_label_back, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->screen_arm_angle_calib_label_back, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->screen_arm_angle_calib_label_back, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->screen_arm_angle_calib_label_back, &lv_font_FontAwesome5ProRegular_400_16, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->screen_arm_angle_calib_label_back, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_line_space(ui->screen_arm_angle_calib_label_back, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->screen_arm_angle_calib_label_back, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->screen_arm_angle_calib_label_back, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->screen_arm_angle_calib_label_back, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->screen_arm_angle_calib_label_back, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->screen_arm_angle_calib_label_back, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->screen_arm_angle_calib_label_back, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->screen_arm_angle_calib_label_back, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes screen_arm_angle_calib_label_title
	ui->screen_arm_angle_calib_label_title = lv_label_create(ui->screen_arm_angle_calib);
	lv_label_set_text(ui->screen_arm_angle_calib_label_title, "Calibration");
	lv_label_set_long_mode(ui->screen_arm_angle_calib_label_title, LV_LABEL_LONG_WRAP);
	lv_obj_set_pos(ui->screen_arm_angle_calib_label_title, 60, 20);
	lv_obj_set_size(ui->screen_arm_angle_calib_label_title, 120, 18);

	//Write style for screen_arm_angle_calib_label_title, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->screen_arm_angle_calib_label_title, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->screen_arm_angle_calib_label_title, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->screen_arm_angle_calib_label_title, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->screen_arm_angle_calib_label_title, &lv_font_montserratMedium_16, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->screen_arm_angle_calib_label_title, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_line_space(ui->screen_arm_angle_calib_label_title, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->screen_arm_angle_calib_label_title, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->screen_arm_angle_calib_label_title, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->screen_arm_angle_calib_label_title, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->screen_arm_angle_calib_label_title, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->screen_arm_angle_calib_label_title, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->screen_arm_angle_calib_label_title, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->screen_arm_angle_calib_label_title, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes screen_arm_angle_calib_label_raw_value
	ui->screen_arm_angle_calib_label_raw_value = lv_label_create(ui->screen_arm_angle_calib);
	lv_label_set_text(ui->screen_arm_angle_calib_label_raw_value, "Raw Value: 0");
	lv_label_set_long_mode(ui->screen_arm_angle_calib_label_raw_value, LV_LABEL_LONG_WRAP);
	lv_obj_set_pos(ui->screen_arm_angle_calib_label_raw_value, 45, 177);
	lv_obj_set_size(ui->screen_arm_angle_calib_label_raw_value, 150, 15);

	//Write style for screen_arm_angle_calib_label_raw_value, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->screen_arm_angle_calib_label_raw_value, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->screen_arm_angle_calib_label_raw_value, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->screen_arm_angle_calib_label_raw_value, lv_color_hex(0x8a8a8a), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->screen_arm_angle_calib_label_raw_value, &lv_font_montserratMedium_14, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->screen_arm_angle_calib_label_raw_value, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_line_space(ui->screen_arm_angle_calib_label_raw_value, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->screen_arm_angle_calib_label_raw_value, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->screen_arm_angle_calib_label_raw_value, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->screen_arm_angle_calib_label_raw_value, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->screen_arm_angle_calib_label_raw_value, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->screen_arm_angle_calib_label_raw_value, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->screen_arm_angle_calib_label_raw_value, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->screen_arm_angle_calib_label_raw_value, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes screen_arm_angle_calib_btn_calibrate_0
	ui->screen_arm_angle_calib_btn_calibrate_0 = lv_btn_create(ui->screen_arm_angle_calib);
	ui->screen_arm_angle_calib_btn_calibrate_0_label = lv_label_create(ui->screen_arm_angle_calib_btn_calibrate_0);
	lv_label_set_text(ui->screen_arm_angle_calib_btn_calibrate_0_label, "Calibrate 0° (unfolded)");
	lv_label_set_long_mode(ui->screen_arm_angle_calib_btn_calibrate_0_label, LV_LABEL_LONG_WRAP);
	lv_obj_align(ui->screen_arm_angle_calib_btn_calibrate_0_label, LV_ALIGN_CENTER, 0, 0);
	lv_obj_set_style_pad_all(ui->screen_arm_angle_calib_btn_calibrate_0, 0, LV_STATE_DEFAULT);
	lv_obj_set_pos(ui->screen_arm_angle_calib_btn_calibrate_0, 17, 75);
	lv_obj_set_size(ui->screen_arm_angle_calib_btn_calibrate_0, 206, 40);

	//Write style for screen_arm_angle_calib_btn_calibrate_0, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_bg_opa(ui->screen_arm_angle_calib_btn_calibrate_0, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui->screen_arm_angle_calib_btn_calibrate_0, lv_color_hex(0x292831), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_width(ui->screen_arm_angle_calib_btn_calibrate_0, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_opa(ui->screen_arm_angle_calib_btn_calibrate_0, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_color(ui->screen_arm_angle_calib_btn_calibrate_0, lv_color_hex(0x757478), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_side(ui->screen_arm_angle_calib_btn_calibrate_0, LV_BORDER_SIDE_FULL, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->screen_arm_angle_calib_btn_calibrate_0, 5, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->screen_arm_angle_calib_btn_calibrate_0, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->screen_arm_angle_calib_btn_calibrate_0, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->screen_arm_angle_calib_btn_calibrate_0, &lv_font_montserratMedium_16, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->screen_arm_angle_calib_btn_calibrate_0, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes screen_arm_angle_calib_btn_calibrate_90
	ui->screen_arm_angle_calib_btn_calibrate_90 = lv_btn_create(ui->screen_arm_angle_calib);
	ui->screen_arm_angle_calib_btn_calibrate_90_label = lv_label_create(ui->screen_arm_angle_calib_btn_calibrate_90);
	lv_label_set_text(ui->screen_arm_angle_calib_btn_calibrate_90_label, "Calibrate 90° (folded)");
	lv_label_set_long_mode(ui->screen_arm_angle_calib_btn_calibrate_90_label, LV_LABEL_LONG_WRAP);
	lv_obj_align(ui->screen_arm_angle_calib_btn_calibrate_90_label, LV_ALIGN_CENTER, 0, 0);
	lv_obj_set_style_pad_all(ui->screen_arm_angle_calib_btn_calibrate_90, 0, LV_STATE_DEFAULT);
	lv_obj_set_pos(ui->screen_arm_angle_calib_btn_calibrate_90, 17, 126);
	lv_obj_set_size(ui->screen_arm_angle_calib_btn_calibrate_90, 206, 40);

	//Write style for screen_arm_angle_calib_btn_calibrate_90, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_bg_opa(ui->screen_arm_angle_calib_btn_calibrate_90, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui->screen_arm_angle_calib_btn_calibrate_90, lv_color_hex(0x292831), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_width(ui->screen_arm_angle_calib_btn_calibrate_90, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_opa(ui->screen_arm_angle_calib_btn_calibrate_90, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_color(ui->screen_arm_angle_calib_btn_calibrate_90, lv_color_hex(0x757478), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_side(ui->screen_arm_angle_calib_btn_calibrate_90, LV_BORDER_SIDE_FULL, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->screen_arm_angle_calib_btn_calibrate_90, 5, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->screen_arm_angle_calib_btn_calibrate_90, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->screen_arm_angle_calib_btn_calibrate_90, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->screen_arm_angle_calib_btn_calibrate_90, &lv_font_montserratMedium_16, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->screen_arm_angle_calib_btn_calibrate_90, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes screen_arm_angle_calib_cont_confirmed_background
	ui->screen_arm_angle_calib_cont_confirmed_background = lv_obj_create(ui->screen_arm_angle_calib);
	lv_obj_set_pos(ui->screen_arm_angle_calib_cont_confirmed_background, 0, 0);
	lv_obj_set_size(ui->screen_arm_angle_calib_cont_confirmed_background, 240, 240);
	lv_obj_set_scrollbar_mode(ui->screen_arm_angle_calib_cont_confirmed_background, LV_SCROLLBAR_MODE_OFF);
	lv_obj_add_flag(ui->screen_arm_angle_calib_cont_confirmed_background, LV_OBJ_FLAG_HIDDEN);

	//Write style for screen_arm_angle_calib_cont_confirmed_background, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->screen_arm_angle_calib_cont_confirmed_background, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->screen_arm_angle_calib_cont_confirmed_background, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->screen_arm_angle_calib_cont_confirmed_background, 108, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui->screen_arm_angle_calib_cont_confirmed_background, lv_color_hex(0x828282), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->screen_arm_angle_calib_cont_confirmed_background, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->screen_arm_angle_calib_cont_confirmed_background, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->screen_arm_angle_calib_cont_confirmed_background, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->screen_arm_angle_calib_cont_confirmed_background, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->screen_arm_angle_calib_cont_confirmed_background, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes screen_arm_angle_calib_cont_confirmed
	ui->screen_arm_angle_calib_cont_confirmed = lv_obj_create(ui->screen_arm_angle_calib);
	lv_obj_set_pos(ui->screen_arm_angle_calib_cont_confirmed, 25, 80.5);
	lv_obj_set_size(ui->screen_arm_angle_calib_cont_confirmed, 190, 79);
	lv_obj_set_scrollbar_mode(ui->screen_arm_angle_calib_cont_confirmed, LV_SCROLLBAR_MODE_OFF);
	lv_obj_add_flag(ui->screen_arm_angle_calib_cont_confirmed, LV_OBJ_FLAG_HIDDEN);

	//Write style for screen_arm_angle_calib_cont_confirmed, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->screen_arm_angle_calib_cont_confirmed, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_opa(ui->screen_arm_angle_calib_cont_confirmed, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_color(ui->screen_arm_angle_calib_cont_confirmed, lv_color_hex(0x00c92c), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_side(ui->screen_arm_angle_calib_cont_confirmed, LV_BORDER_SIDE_FULL, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->screen_arm_angle_calib_cont_confirmed, 10, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->screen_arm_angle_calib_cont_confirmed, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui->screen_arm_angle_calib_cont_confirmed, lv_color_hex(0x292831), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->screen_arm_angle_calib_cont_confirmed, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->screen_arm_angle_calib_cont_confirmed, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->screen_arm_angle_calib_cont_confirmed, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->screen_arm_angle_calib_cont_confirmed, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->screen_arm_angle_calib_cont_confirmed, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes screen_arm_angle_calib_label_confirmed
	ui->screen_arm_angle_calib_label_confirmed = lv_label_create(ui->screen_arm_angle_calib_cont_confirmed);
	lv_label_set_text(ui->screen_arm_angle_calib_label_confirmed, "Calibration Successful");
	lv_label_set_long_mode(ui->screen_arm_angle_calib_label_confirmed, LV_LABEL_LONG_WRAP);
	lv_obj_set_pos(ui->screen_arm_angle_calib_label_confirmed, 0, 30);
	lv_obj_set_size(ui->screen_arm_angle_calib_label_confirmed, 190, 15);

	//Write style for screen_arm_angle_calib_label_confirmed, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->screen_arm_angle_calib_label_confirmed, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->screen_arm_angle_calib_label_confirmed, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->screen_arm_angle_calib_label_confirmed, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->screen_arm_angle_calib_label_confirmed, &lv_font_montserratMedium_14, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->screen_arm_angle_calib_label_confirmed, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_line_space(ui->screen_arm_angle_calib_label_confirmed, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->screen_arm_angle_calib_label_confirmed, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->screen_arm_angle_calib_label_confirmed, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->screen_arm_angle_calib_label_confirmed, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->screen_arm_angle_calib_label_confirmed, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->screen_arm_angle_calib_label_confirmed, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->screen_arm_angle_calib_label_confirmed, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->screen_arm_angle_calib_label_confirmed, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Update current screen layout.
	lv_obj_update_layout(ui->screen_arm_angle_calib);

	
	//Init events for screen.
	events_init_screen_arm_angle_calib(ui);
}
