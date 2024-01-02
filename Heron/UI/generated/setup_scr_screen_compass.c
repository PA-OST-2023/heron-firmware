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


void setup_scr_screen_compass(lv_ui *ui)
{
	//Write codes screen_compass
	ui->screen_compass = lv_obj_create(NULL);
	lv_obj_set_size(ui->screen_compass, 240, 240);

	//Write style for screen_compass, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_bg_opa(ui->screen_compass, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui->screen_compass, lv_color_hex(0x101418), LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes screen_compass_btn_calib
	ui->screen_compass_btn_calib = lv_btn_create(ui->screen_compass);
	ui->screen_compass_btn_calib_label = lv_label_create(ui->screen_compass_btn_calib);
	lv_label_set_text(ui->screen_compass_btn_calib_label, "");
	lv_label_set_long_mode(ui->screen_compass_btn_calib_label, LV_LABEL_LONG_WRAP);
	lv_obj_align(ui->screen_compass_btn_calib_label, LV_ALIGN_LEFT_MID, 0, 0);
	lv_obj_set_style_pad_all(ui->screen_compass_btn_calib, 0, LV_STATE_DEFAULT);
	lv_obj_set_pos(ui->screen_compass_btn_calib, 0, 200);
	lv_obj_set_size(ui->screen_compass_btn_calib, 240, 40);

	//Write style for screen_compass_btn_calib, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_bg_opa(ui->screen_compass_btn_calib, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui->screen_compass_btn_calib, lv_color_hex(0x292831), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_width(ui->screen_compass_btn_calib, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_opa(ui->screen_compass_btn_calib, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_color(ui->screen_compass_btn_calib, lv_color_hex(0x757478), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_side(ui->screen_compass_btn_calib, LV_BORDER_SIDE_TOP, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->screen_compass_btn_calib, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->screen_compass_btn_calib, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->screen_compass_btn_calib, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->screen_compass_btn_calib, &lv_font_FontAwesome5ProRegular_400_16, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->screen_compass_btn_calib, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes screen_compass_label_calib
	ui->screen_compass_label_calib = lv_label_create(ui->screen_compass);
	lv_label_set_text(ui->screen_compass_label_calib, "Calibration");
	lv_label_set_long_mode(ui->screen_compass_label_calib, LV_LABEL_LONG_WRAP);
	lv_obj_set_pos(ui->screen_compass_label_calib, 60, 210);
	lv_obj_set_size(ui->screen_compass_label_calib, 120, 18);

	//Write style for screen_compass_label_calib, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->screen_compass_label_calib, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->screen_compass_label_calib, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->screen_compass_label_calib, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->screen_compass_label_calib, &lv_font_montserratMedium_16, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->screen_compass_label_calib, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_line_space(ui->screen_compass_label_calib, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->screen_compass_label_calib, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->screen_compass_label_calib, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->screen_compass_label_calib, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->screen_compass_label_calib, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->screen_compass_label_calib, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->screen_compass_label_calib, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->screen_compass_label_calib, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes screen_compass_btn_back
	ui->screen_compass_btn_back = lv_btn_create(ui->screen_compass);
	ui->screen_compass_btn_back_label = lv_label_create(ui->screen_compass_btn_back);
	lv_label_set_text(ui->screen_compass_btn_back_label, "");
	lv_label_set_long_mode(ui->screen_compass_btn_back_label, LV_LABEL_LONG_WRAP);
	lv_obj_align(ui->screen_compass_btn_back_label, LV_ALIGN_LEFT_MID, 0, 0);
	lv_obj_set_style_pad_all(ui->screen_compass_btn_back, 0, LV_STATE_DEFAULT);
	lv_obj_set_pos(ui->screen_compass_btn_back, 0, 0);
	lv_obj_set_size(ui->screen_compass_btn_back, 240, 50);

	//Write style for screen_compass_btn_back, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_bg_opa(ui->screen_compass_btn_back, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui->screen_compass_btn_back, lv_color_hex(0x292831), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_width(ui->screen_compass_btn_back, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_opa(ui->screen_compass_btn_back, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_color(ui->screen_compass_btn_back, lv_color_hex(0xD200AC), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_side(ui->screen_compass_btn_back, LV_BORDER_SIDE_BOTTOM, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->screen_compass_btn_back, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->screen_compass_btn_back, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->screen_compass_btn_back, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->screen_compass_btn_back, &lv_font_FontAwesome5ProRegular_400_16, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->screen_compass_btn_back, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes screen_compass_label_back
	ui->screen_compass_label_back = lv_label_create(ui->screen_compass);
	lv_label_set_text(ui->screen_compass_label_back, "");
	lv_label_set_long_mode(ui->screen_compass_label_back, LV_LABEL_LONG_WRAP);
	lv_obj_set_pos(ui->screen_compass_label_back, 50, 25);
	lv_obj_set_size(ui->screen_compass_label_back, 23, 16);

	//Write style for screen_compass_label_back, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->screen_compass_label_back, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->screen_compass_label_back, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->screen_compass_label_back, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->screen_compass_label_back, &lv_font_FontAwesome5ProRegular_400_16, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->screen_compass_label_back, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_line_space(ui->screen_compass_label_back, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->screen_compass_label_back, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->screen_compass_label_back, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->screen_compass_label_back, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->screen_compass_label_back, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->screen_compass_label_back, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->screen_compass_label_back, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->screen_compass_label_back, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes screen_compass_label_title
	ui->screen_compass_label_title = lv_label_create(ui->screen_compass);
	lv_label_set_text(ui->screen_compass_label_title, "Compass");
	lv_label_set_long_mode(ui->screen_compass_label_title, LV_LABEL_LONG_WRAP);
	lv_obj_set_pos(ui->screen_compass_label_title, 60, 20);
	lv_obj_set_size(ui->screen_compass_label_title, 120, 18);

	//Write style for screen_compass_label_title, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->screen_compass_label_title, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->screen_compass_label_title, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->screen_compass_label_title, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->screen_compass_label_title, &lv_font_montserratMedium_16, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->screen_compass_label_title, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_line_space(ui->screen_compass_label_title, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->screen_compass_label_title, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->screen_compass_label_title, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->screen_compass_label_title, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->screen_compass_label_title, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->screen_compass_label_title, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->screen_compass_label_title, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->screen_compass_label_title, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes screen_compass_label_heading
	ui->screen_compass_label_heading = lv_label_create(ui->screen_compass);
	lv_label_set_text(ui->screen_compass_label_heading, "Heading: 0°");
	lv_label_set_long_mode(ui->screen_compass_label_heading, LV_LABEL_LONG_WRAP);
	lv_obj_set_pos(ui->screen_compass_label_heading, 60, 59);
	lv_obj_set_size(ui->screen_compass_label_heading, 120, 18);

	//Write style for screen_compass_label_heading, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->screen_compass_label_heading, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->screen_compass_label_heading, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->screen_compass_label_heading, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->screen_compass_label_heading, &lv_font_montserratMedium_14, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->screen_compass_label_heading, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_line_space(ui->screen_compass_label_heading, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->screen_compass_label_heading, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->screen_compass_label_heading, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->screen_compass_label_heading, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->screen_compass_label_heading, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->screen_compass_label_heading, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->screen_compass_label_heading, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->screen_compass_label_heading, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes screen_compass_label_pitch
	ui->screen_compass_label_pitch = lv_label_create(ui->screen_compass);
	lv_label_set_text(ui->screen_compass_label_pitch, "Pitch: 0.0°");
	lv_label_set_long_mode(ui->screen_compass_label_pitch, LV_LABEL_LONG_WRAP);
	lv_obj_set_pos(ui->screen_compass_label_pitch, 34, 177);
	lv_obj_set_size(ui->screen_compass_label_pitch, 90, 18);

	//Write style for screen_compass_label_pitch, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->screen_compass_label_pitch, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->screen_compass_label_pitch, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->screen_compass_label_pitch, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->screen_compass_label_pitch, &lv_font_montserratMedium_14, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->screen_compass_label_pitch, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_line_space(ui->screen_compass_label_pitch, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->screen_compass_label_pitch, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->screen_compass_label_pitch, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->screen_compass_label_pitch, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->screen_compass_label_pitch, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->screen_compass_label_pitch, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->screen_compass_label_pitch, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->screen_compass_label_pitch, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes screen_compass_label_roll
	ui->screen_compass_label_roll = lv_label_create(ui->screen_compass);
	lv_label_set_text(ui->screen_compass_label_roll, "Roll: 0.0°");
	lv_label_set_long_mode(ui->screen_compass_label_roll, LV_LABEL_LONG_WRAP);
	lv_obj_set_pos(ui->screen_compass_label_roll, 133, 177);
	lv_obj_set_size(ui->screen_compass_label_roll, 90, 18);

	//Write style for screen_compass_label_roll, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->screen_compass_label_roll, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->screen_compass_label_roll, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->screen_compass_label_roll, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->screen_compass_label_roll, &lv_font_montserratMedium_14, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->screen_compass_label_roll, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_line_space(ui->screen_compass_label_roll, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->screen_compass_label_roll, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->screen_compass_label_roll, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->screen_compass_label_roll, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->screen_compass_label_roll, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->screen_compass_label_roll, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->screen_compass_label_roll, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->screen_compass_label_roll, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes screen_compass_img_compass_background
	ui->screen_compass_img_compass_background = lv_img_create(ui->screen_compass);
	lv_obj_add_flag(ui->screen_compass_img_compass_background, LV_OBJ_FLAG_CLICKABLE);
	lv_img_set_src(ui->screen_compass_img_compass_background, &_compass_background_alpha_82x82);
	lv_img_set_pivot(ui->screen_compass_img_compass_background, 50,50);
	lv_img_set_angle(ui->screen_compass_img_compass_background, 0);
	lv_obj_set_pos(ui->screen_compass_img_compass_background, 79, 86);
	lv_obj_set_size(ui->screen_compass_img_compass_background, 82, 82);

	//Write style for screen_compass_img_compass_background, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_img_opa(ui->screen_compass_img_compass_background, 255, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes screen_compass_cont_dot
	ui->screen_compass_cont_dot = lv_obj_create(ui->screen_compass);
	lv_obj_set_pos(ui->screen_compass_cont_dot, 113, 120);
	lv_obj_set_size(ui->screen_compass_cont_dot, 14, 14);
	lv_obj_set_scrollbar_mode(ui->screen_compass_cont_dot, LV_SCROLLBAR_MODE_OFF);

	//Write style for screen_compass_cont_dot, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->screen_compass_cont_dot, 1, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_opa(ui->screen_compass_cont_dot, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_color(ui->screen_compass_cont_dot, lv_color_hex(0x00C92C), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_side(ui->screen_compass_cont_dot, LV_BORDER_SIDE_FULL, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->screen_compass_cont_dot, 14, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->screen_compass_cont_dot, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui->screen_compass_cont_dot, lv_color_hex(0x00C92C), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->screen_compass_cont_dot, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->screen_compass_cont_dot, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->screen_compass_cont_dot, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->screen_compass_cont_dot, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->screen_compass_cont_dot, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes screen_compass_label_needle
	ui->screen_compass_label_needle = lv_label_create(ui->screen_compass);
	lv_label_set_text(ui->screen_compass_label_needle, "");
	lv_label_set_long_mode(ui->screen_compass_label_needle, LV_LABEL_LONG_WRAP);
	lv_obj_set_pos(ui->screen_compass_label_needle, 112, 78);
	lv_obj_set_size(ui->screen_compass_label_needle, 17, 15);
	lv_obj_add_flag(ui->screen_compass_label_needle, LV_OBJ_FLAG_HIDDEN);

	//Write style for screen_compass_label_needle, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->screen_compass_label_needle, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->screen_compass_label_needle, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->screen_compass_label_needle, lv_color_hex(0xD200AC), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->screen_compass_label_needle, &lv_font_FontAwesome5ProSolid_900_10, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->screen_compass_label_needle, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_line_space(ui->screen_compass_label_needle, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->screen_compass_label_needle, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->screen_compass_label_needle, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->screen_compass_label_needle, 1, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->screen_compass_label_needle, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->screen_compass_label_needle, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->screen_compass_label_needle, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->screen_compass_label_needle, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Update current screen layout.
	lv_obj_update_layout(ui->screen_compass);

	
	//Init events for screen.
	events_init_screen_compass(ui);
}
