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

	//Write codes screen_compass_canvas_compass
	ui->screen_compass_canvas_compass = lv_canvas_create(ui->screen_compass);
	static lv_color_t buf_screen_compass_canvas_compass[82*82*4];
	lv_canvas_set_buffer(ui->screen_compass_canvas_compass, buf_screen_compass_canvas_compass, 82, 82, LV_IMG_CF_TRUE_COLOR_ALPHA);
	lv_canvas_fill_bg(ui->screen_compass_canvas_compass, lv_color_hex(0xffffff), 0);
	//Canvas draw arc
	lv_draw_arc_dsc_t arc_dsc_0;
	lv_draw_arc_dsc_init(&arc_dsc_0);
	arc_dsc_0.color = lv_color_hex(0x757478);
	arc_dsc_0.opa = 255;
	arc_dsc_0.width = 2;
	lv_canvas_draw_arc(ui->screen_compass_canvas_compass, 41, 41, 12, 0, 360, &arc_dsc_0);

	//Canvas draw line
	static lv_point_t points_array_1[] ={{1, 41},{31, 41},};
	lv_draw_line_dsc_t line_dsc_1;
	lv_draw_line_dsc_init(&line_dsc_1);
	line_dsc_1.color = lv_color_hex(0x757478);
	line_dsc_1.opa = 255;
	line_dsc_1.width = 2;
	line_dsc_1.round_start = false;
	line_dsc_1.round_end = false;
	lv_canvas_draw_line(ui->screen_compass_canvas_compass, points_array_1, 2, &line_dsc_1);

	//Canvas draw line
	static lv_point_t points_array_2[] ={{51, 41},{81, 41},};
	lv_draw_line_dsc_t line_dsc_2;
	lv_draw_line_dsc_init(&line_dsc_2);
	line_dsc_2.color = lv_color_hex(0x757478);
	line_dsc_2.opa = 255;
	line_dsc_2.width = 2;
	line_dsc_2.round_start = false;
	line_dsc_2.round_end = false;
	lv_canvas_draw_line(ui->screen_compass_canvas_compass, points_array_2, 2, &line_dsc_2);

	//Canvas draw line
	static lv_point_t points_array_3[] ={{41, 1},{41, 31},};
	lv_draw_line_dsc_t line_dsc_3;
	lv_draw_line_dsc_init(&line_dsc_3);
	line_dsc_3.color = lv_color_hex(0x757478);
	line_dsc_3.opa = 255;
	line_dsc_3.width = 2;
	line_dsc_3.round_start = false;
	line_dsc_3.round_end = false;
	lv_canvas_draw_line(ui->screen_compass_canvas_compass, points_array_3, 2, &line_dsc_3);

	//Canvas draw line
	static lv_point_t points_array_4[] ={{41, 51},{41, 81},};
	lv_draw_line_dsc_t line_dsc_4;
	lv_draw_line_dsc_init(&line_dsc_4);
	line_dsc_4.color = lv_color_hex(0x757478);
	line_dsc_4.opa = 255;
	line_dsc_4.width = 2;
	line_dsc_4.round_start = false;
	line_dsc_4.round_end = false;
	lv_canvas_draw_line(ui->screen_compass_canvas_compass, points_array_4, 2, &line_dsc_4);

	//Canvas draw arc
	lv_draw_arc_dsc_t arc_dsc_5;
	lv_draw_arc_dsc_init(&arc_dsc_5);
	arc_dsc_5.color = lv_color_hex(0x757478);
	arc_dsc_5.opa = 255;
	arc_dsc_5.width = 2;
	lv_canvas_draw_arc(ui->screen_compass_canvas_compass, 41, 41, 40, 0, 360, &arc_dsc_5);

	//Canvas draw rectangle
	lv_draw_rect_dsc_t rect_dsc_6;
	lv_draw_rect_dsc_init(&rect_dsc_6);
	rect_dsc_6.radius = 18;
	rect_dsc_6.bg_opa = 255;
	rect_dsc_6.bg_color = lv_color_hex(0x00c92c);
	rect_dsc_6.bg_grad.dir = LV_GRAD_DIR_NONE;
	rect_dsc_6.border_width = 3;
	rect_dsc_6.border_opa = 255;
	rect_dsc_6.border_color = lv_color_hex(0x00c92c);
	lv_canvas_draw_rect(ui->screen_compass_canvas_compass, 34, 34, 14, 14, &rect_dsc_6);

	lv_obj_set_pos(ui->screen_compass_canvas_compass, 79, 86);
	lv_obj_set_size(ui->screen_compass_canvas_compass, 82, 82);
	lv_obj_set_scrollbar_mode(ui->screen_compass_canvas_compass, LV_SCROLLBAR_MODE_OFF);

	//Write codes screen_compass_label_heading
	ui->screen_compass_label_heading = lv_label_create(ui->screen_compass);
	lv_label_set_text(ui->screen_compass_label_heading, "Heading: 23.5°");
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
	lv_label_set_text(ui->screen_compass_label_pitch, "Pitch: 10.5°");
	lv_label_set_long_mode(ui->screen_compass_label_pitch, LV_LABEL_LONG_WRAP);
	lv_obj_set_pos(ui->screen_compass_label_pitch, 34, 177);
	lv_obj_set_size(ui->screen_compass_label_pitch, 80, 18);

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
	lv_label_set_text(ui->screen_compass_label_roll, "Roll: 10.5°");
	lv_label_set_long_mode(ui->screen_compass_label_roll, LV_LABEL_LONG_WRAP);
	lv_obj_set_pos(ui->screen_compass_label_roll, 136, 177);
	lv_obj_set_size(ui->screen_compass_label_roll, 80, 18);

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

	//Write codes screen_compass_label_east
	ui->screen_compass_label_east = lv_label_create(ui->screen_compass);
	lv_label_set_text(ui->screen_compass_label_east, "E");
	lv_label_set_long_mode(ui->screen_compass_label_east, LV_LABEL_LONG_WRAP);
	lv_obj_set_pos(ui->screen_compass_label_east, 165, 120);
	lv_obj_set_size(ui->screen_compass_label_east, 20, 18);

	//Write style for screen_compass_label_east, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->screen_compass_label_east, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->screen_compass_label_east, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->screen_compass_label_east, lv_color_hex(0x757478), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->screen_compass_label_east, &lv_font_montserratMedium_14, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->screen_compass_label_east, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_line_space(ui->screen_compass_label_east, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->screen_compass_label_east, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->screen_compass_label_east, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->screen_compass_label_east, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->screen_compass_label_east, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->screen_compass_label_east, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->screen_compass_label_east, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->screen_compass_label_east, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes screen_compass_label_west
	ui->screen_compass_label_west = lv_label_create(ui->screen_compass);
	lv_label_set_text(ui->screen_compass_label_west, "W");
	lv_label_set_long_mode(ui->screen_compass_label_west, LV_LABEL_LONG_WRAP);
	lv_obj_set_pos(ui->screen_compass_label_west, 53, 120);
	lv_obj_set_size(ui->screen_compass_label_west, 20, 18);

	//Write style for screen_compass_label_west, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->screen_compass_label_west, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->screen_compass_label_west, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->screen_compass_label_west, lv_color_hex(0x757478), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->screen_compass_label_west, &lv_font_montserratMedium_14, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->screen_compass_label_west, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_line_space(ui->screen_compass_label_west, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->screen_compass_label_west, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->screen_compass_label_west, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->screen_compass_label_west, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->screen_compass_label_west, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->screen_compass_label_west, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->screen_compass_label_west, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->screen_compass_label_west, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes screen_compass_label_needle
	ui->screen_compass_label_needle = lv_label_create(ui->screen_compass);
	lv_label_set_text(ui->screen_compass_label_needle, "");
	lv_label_set_long_mode(ui->screen_compass_label_needle, LV_LABEL_LONG_WRAP);
	lv_obj_set_pos(ui->screen_compass_label_needle, 112, 78);
	lv_obj_set_size(ui->screen_compass_label_needle, 17, 15);

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
