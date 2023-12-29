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


void setup_scr_screen_ethernet(lv_ui *ui)
{
	//Write codes screen_ethernet
	ui->screen_ethernet = lv_obj_create(NULL);
	lv_obj_set_size(ui->screen_ethernet, 240, 240);

	//Write style for screen_ethernet, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_bg_opa(ui->screen_ethernet, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui->screen_ethernet, lv_color_hex(0x101418), LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes screen_ethernet_btn_setup
	ui->screen_ethernet_btn_setup = lv_btn_create(ui->screen_ethernet);
	ui->screen_ethernet_btn_setup_label = lv_label_create(ui->screen_ethernet_btn_setup);
	lv_label_set_text(ui->screen_ethernet_btn_setup_label, "");
	lv_label_set_long_mode(ui->screen_ethernet_btn_setup_label, LV_LABEL_LONG_WRAP);
	lv_obj_align(ui->screen_ethernet_btn_setup_label, LV_ALIGN_LEFT_MID, 0, 0);
	lv_obj_set_style_pad_all(ui->screen_ethernet_btn_setup, 0, LV_STATE_DEFAULT);
	lv_obj_set_pos(ui->screen_ethernet_btn_setup, 0, 200);
	lv_obj_set_size(ui->screen_ethernet_btn_setup, 240, 40);

	//Write style for screen_ethernet_btn_setup, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_bg_opa(ui->screen_ethernet_btn_setup, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui->screen_ethernet_btn_setup, lv_color_hex(0x292831), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_width(ui->screen_ethernet_btn_setup, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_opa(ui->screen_ethernet_btn_setup, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_color(ui->screen_ethernet_btn_setup, lv_color_hex(0x757478), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_side(ui->screen_ethernet_btn_setup, LV_BORDER_SIDE_TOP, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->screen_ethernet_btn_setup, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->screen_ethernet_btn_setup, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->screen_ethernet_btn_setup, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->screen_ethernet_btn_setup, &lv_font_FontAwesome5ProRegular_400_16, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->screen_ethernet_btn_setup, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes screen_ethernet_label_setup
	ui->screen_ethernet_label_setup = lv_label_create(ui->screen_ethernet);
	lv_label_set_text(ui->screen_ethernet_label_setup, "Setup");
	lv_label_set_long_mode(ui->screen_ethernet_label_setup, LV_LABEL_LONG_WRAP);
	lv_obj_set_pos(ui->screen_ethernet_label_setup, 60, 210);
	lv_obj_set_size(ui->screen_ethernet_label_setup, 120, 18);

	//Write style for screen_ethernet_label_setup, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->screen_ethernet_label_setup, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->screen_ethernet_label_setup, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->screen_ethernet_label_setup, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->screen_ethernet_label_setup, &lv_font_montserratMedium_16, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->screen_ethernet_label_setup, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_line_space(ui->screen_ethernet_label_setup, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->screen_ethernet_label_setup, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->screen_ethernet_label_setup, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->screen_ethernet_label_setup, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->screen_ethernet_label_setup, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->screen_ethernet_label_setup, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->screen_ethernet_label_setup, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->screen_ethernet_label_setup, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes screen_ethernet_btn_back
	ui->screen_ethernet_btn_back = lv_btn_create(ui->screen_ethernet);
	ui->screen_ethernet_btn_back_label = lv_label_create(ui->screen_ethernet_btn_back);
	lv_label_set_text(ui->screen_ethernet_btn_back_label, "");
	lv_label_set_long_mode(ui->screen_ethernet_btn_back_label, LV_LABEL_LONG_WRAP);
	lv_obj_align(ui->screen_ethernet_btn_back_label, LV_ALIGN_LEFT_MID, 0, 0);
	lv_obj_set_style_pad_all(ui->screen_ethernet_btn_back, 0, LV_STATE_DEFAULT);
	lv_obj_set_pos(ui->screen_ethernet_btn_back, 0, 0);
	lv_obj_set_size(ui->screen_ethernet_btn_back, 240, 50);

	//Write style for screen_ethernet_btn_back, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_bg_opa(ui->screen_ethernet_btn_back, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui->screen_ethernet_btn_back, lv_color_hex(0x292831), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_width(ui->screen_ethernet_btn_back, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_opa(ui->screen_ethernet_btn_back, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_color(ui->screen_ethernet_btn_back, lv_color_hex(0xD200AC), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_side(ui->screen_ethernet_btn_back, LV_BORDER_SIDE_BOTTOM, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->screen_ethernet_btn_back, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->screen_ethernet_btn_back, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->screen_ethernet_btn_back, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->screen_ethernet_btn_back, &lv_font_FontAwesome5ProRegular_400_16, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->screen_ethernet_btn_back, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes screen_ethernet_label_back
	ui->screen_ethernet_label_back = lv_label_create(ui->screen_ethernet);
	lv_label_set_text(ui->screen_ethernet_label_back, "");
	lv_label_set_long_mode(ui->screen_ethernet_label_back, LV_LABEL_LONG_WRAP);
	lv_obj_set_pos(ui->screen_ethernet_label_back, 50, 25);
	lv_obj_set_size(ui->screen_ethernet_label_back, 23, 16);

	//Write style for screen_ethernet_label_back, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->screen_ethernet_label_back, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->screen_ethernet_label_back, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->screen_ethernet_label_back, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->screen_ethernet_label_back, &lv_font_FontAwesome5ProRegular_400_16, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->screen_ethernet_label_back, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_line_space(ui->screen_ethernet_label_back, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->screen_ethernet_label_back, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->screen_ethernet_label_back, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->screen_ethernet_label_back, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->screen_ethernet_label_back, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->screen_ethernet_label_back, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->screen_ethernet_label_back, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->screen_ethernet_label_back, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes screen_ethernet_label_title
	ui->screen_ethernet_label_title = lv_label_create(ui->screen_ethernet);
	lv_label_set_text(ui->screen_ethernet_label_title, "Ethernet");
	lv_label_set_long_mode(ui->screen_ethernet_label_title, LV_LABEL_LONG_WRAP);
	lv_obj_set_pos(ui->screen_ethernet_label_title, 60, 20);
	lv_obj_set_size(ui->screen_ethernet_label_title, 120, 18);

	//Write style for screen_ethernet_label_title, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->screen_ethernet_label_title, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->screen_ethernet_label_title, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->screen_ethernet_label_title, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->screen_ethernet_label_title, &lv_font_montserratMedium_16, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->screen_ethernet_label_title, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_line_space(ui->screen_ethernet_label_title, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->screen_ethernet_label_title, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->screen_ethernet_label_title, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->screen_ethernet_label_title, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->screen_ethernet_label_title, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->screen_ethernet_label_title, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->screen_ethernet_label_title, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->screen_ethernet_label_title, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes screen_ethernet_label_buffer
	ui->screen_ethernet_label_buffer = lv_label_create(ui->screen_ethernet);
	lv_label_set_text(ui->screen_ethernet_label_buffer, "100.0 %");
	lv_label_set_long_mode(ui->screen_ethernet_label_buffer, LV_LABEL_LONG_WRAP);
	lv_obj_set_pos(ui->screen_ethernet_label_buffer, 130, 146);
	lv_obj_set_size(ui->screen_ethernet_label_buffer, 85, 15);

	//Write style for screen_ethernet_label_buffer, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->screen_ethernet_label_buffer, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->screen_ethernet_label_buffer, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->screen_ethernet_label_buffer, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->screen_ethernet_label_buffer, &lv_font_montserratMedium_14, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->screen_ethernet_label_buffer, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_line_space(ui->screen_ethernet_label_buffer, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->screen_ethernet_label_buffer, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->screen_ethernet_label_buffer, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->screen_ethernet_label_buffer, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->screen_ethernet_label_buffer, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->screen_ethernet_label_buffer, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->screen_ethernet_label_buffer, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->screen_ethernet_label_buffer, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes screen_ethernet_meter_buffer
	ui->screen_ethernet_meter_buffer = lv_meter_create(ui->screen_ethernet);
	// add scale screen_ethernet_meter_buffer_scale_1
	lv_meter_scale_t *screen_ethernet_meter_buffer_scale_1 = lv_meter_add_scale(ui->screen_ethernet_meter_buffer);
	lv_meter_set_scale_ticks(ui->screen_ethernet_meter_buffer, screen_ethernet_meter_buffer_scale_1, 2, 1, 1, lv_color_hex(0x101418));

	// add arc for screen_ethernet_meter_buffer_scale_1
	lv_meter_indicator_t *screen_ethernet_meter_buffer_scale_1_arc_0;
	screen_ethernet_meter_buffer_scale_1_arc_0 = lv_meter_add_arc(ui->screen_ethernet_meter_buffer, screen_ethernet_meter_buffer_scale_1, 10, lv_color_hex(0x757478), -1);
	lv_meter_set_indicator_start_value(ui->screen_ethernet_meter_buffer, screen_ethernet_meter_buffer_scale_1_arc_0, 0);
	lv_meter_set_indicator_end_value(ui->screen_ethernet_meter_buffer, screen_ethernet_meter_buffer_scale_1_arc_0, 100);

	// add arc for screen_ethernet_meter_buffer_scale_1
	lv_meter_indicator_t *screen_ethernet_meter_buffer_scale_1_arc_1;
	screen_ethernet_meter_buffer_scale_1_arc_1 = lv_meter_add_arc(ui->screen_ethernet_meter_buffer, screen_ethernet_meter_buffer_scale_1, 10, lv_color_hex(0x2195f6), -1);
	lv_meter_set_indicator_start_value(ui->screen_ethernet_meter_buffer, screen_ethernet_meter_buffer_scale_1_arc_1, 0);
	lv_meter_set_indicator_end_value(ui->screen_ethernet_meter_buffer, screen_ethernet_meter_buffer_scale_1_arc_1, 20);
	lv_obj_set_pos(ui->screen_ethernet_meter_buffer, 130, 74);
	lv_obj_set_size(ui->screen_ethernet_meter_buffer, 85, 85);

	//Write style for screen_ethernet_meter_buffer, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_bg_opa(ui->screen_ethernet_meter_buffer, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->screen_ethernet_meter_buffer, 200, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_width(ui->screen_ethernet_meter_buffer, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->screen_ethernet_meter_buffer, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write style for screen_ethernet_meter_buffer, Part: LV_PART_TICKS, State: LV_STATE_DEFAULT.
	lv_obj_set_style_text_color(ui->screen_ethernet_meter_buffer, lv_color_hex(0xffffff), LV_PART_TICKS|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->screen_ethernet_meter_buffer, &lv_font_montserratMedium_14, LV_PART_TICKS|LV_STATE_DEFAULT);

	//Write style for screen_ethernet_meter_buffer, Part: LV_PART_INDICATOR, State: LV_STATE_DEFAULT.
	lv_obj_set_style_bg_opa(ui->screen_ethernet_meter_buffer, 0, LV_PART_INDICATOR|LV_STATE_DEFAULT);

	//Write codes screen_ethernet_label_buffer_title
	ui->screen_ethernet_label_buffer_title = lv_label_create(ui->screen_ethernet);
	lv_label_set_text(ui->screen_ethernet_label_buffer_title, "Buffer");
	lv_label_set_long_mode(ui->screen_ethernet_label_buffer_title, LV_LABEL_LONG_WRAP);
	lv_obj_set_pos(ui->screen_ethernet_label_buffer_title, 130, 64);
	lv_obj_set_size(ui->screen_ethernet_label_buffer_title, 85, 15);

	//Write style for screen_ethernet_label_buffer_title, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->screen_ethernet_label_buffer_title, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->screen_ethernet_label_buffer_title, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->screen_ethernet_label_buffer_title, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->screen_ethernet_label_buffer_title, &lv_font_montserratMedium_14, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->screen_ethernet_label_buffer_title, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_line_space(ui->screen_ethernet_label_buffer_title, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->screen_ethernet_label_buffer_title, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->screen_ethernet_label_buffer_title, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->screen_ethernet_label_buffer_title, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->screen_ethernet_label_buffer_title, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->screen_ethernet_label_buffer_title, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->screen_ethernet_label_buffer_title, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->screen_ethernet_label_buffer_title, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes screen_ethernet_label_speed
	ui->screen_ethernet_label_speed = lv_label_create(ui->screen_ethernet);
	lv_label_set_text(ui->screen_ethernet_label_speed, "00.0 MBit/s");
	lv_label_set_long_mode(ui->screen_ethernet_label_speed, LV_LABEL_LONG_WRAP);
	lv_obj_set_pos(ui->screen_ethernet_label_speed, 25, 146);
	lv_obj_set_size(ui->screen_ethernet_label_speed, 85, 15);

	//Write style for screen_ethernet_label_speed, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->screen_ethernet_label_speed, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->screen_ethernet_label_speed, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->screen_ethernet_label_speed, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->screen_ethernet_label_speed, &lv_font_montserratMedium_14, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->screen_ethernet_label_speed, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_line_space(ui->screen_ethernet_label_speed, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->screen_ethernet_label_speed, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->screen_ethernet_label_speed, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->screen_ethernet_label_speed, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->screen_ethernet_label_speed, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->screen_ethernet_label_speed, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->screen_ethernet_label_speed, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->screen_ethernet_label_speed, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes screen_ethernet_meter_speed
	ui->screen_ethernet_meter_speed = lv_meter_create(ui->screen_ethernet);
	// add scale screen_ethernet_meter_speed_scale_1
	lv_meter_scale_t *screen_ethernet_meter_speed_scale_1 = lv_meter_add_scale(ui->screen_ethernet_meter_speed);
	lv_meter_set_scale_ticks(ui->screen_ethernet_meter_speed, screen_ethernet_meter_speed_scale_1, 2, 1, 1, lv_color_hex(0x101418));

	// add arc for screen_ethernet_meter_speed_scale_1
	lv_meter_indicator_t *screen_ethernet_meter_speed_scale_1_arc_0;
	screen_ethernet_meter_speed_scale_1_arc_0 = lv_meter_add_arc(ui->screen_ethernet_meter_speed, screen_ethernet_meter_speed_scale_1, 10, lv_color_hex(0x757478), -1);
	lv_meter_set_indicator_start_value(ui->screen_ethernet_meter_speed, screen_ethernet_meter_speed_scale_1_arc_0, 0);
	lv_meter_set_indicator_end_value(ui->screen_ethernet_meter_speed, screen_ethernet_meter_speed_scale_1_arc_0, 100);

	// add arc for screen_ethernet_meter_speed_scale_1
	lv_meter_indicator_t *screen_ethernet_meter_speed_scale_1_arc_1;
	screen_ethernet_meter_speed_scale_1_arc_1 = lv_meter_add_arc(ui->screen_ethernet_meter_speed, screen_ethernet_meter_speed_scale_1, 10, lv_color_hex(0xD200AC), -1);
	lv_meter_set_indicator_start_value(ui->screen_ethernet_meter_speed, screen_ethernet_meter_speed_scale_1_arc_1, 0);
	lv_meter_set_indicator_end_value(ui->screen_ethernet_meter_speed, screen_ethernet_meter_speed_scale_1_arc_1, 20);
	lv_obj_set_pos(ui->screen_ethernet_meter_speed, 25, 74);
	lv_obj_set_size(ui->screen_ethernet_meter_speed, 85, 85);

	//Write style for screen_ethernet_meter_speed, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_bg_opa(ui->screen_ethernet_meter_speed, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->screen_ethernet_meter_speed, 200, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_width(ui->screen_ethernet_meter_speed, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->screen_ethernet_meter_speed, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write style for screen_ethernet_meter_speed, Part: LV_PART_TICKS, State: LV_STATE_DEFAULT.
	lv_obj_set_style_text_color(ui->screen_ethernet_meter_speed, lv_color_hex(0xffffff), LV_PART_TICKS|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->screen_ethernet_meter_speed, &lv_font_montserratMedium_14, LV_PART_TICKS|LV_STATE_DEFAULT);

	//Write style for screen_ethernet_meter_speed, Part: LV_PART_INDICATOR, State: LV_STATE_DEFAULT.
	lv_obj_set_style_bg_opa(ui->screen_ethernet_meter_speed, 0, LV_PART_INDICATOR|LV_STATE_DEFAULT);

	//Write codes screen_ethernet_label_speed_title
	ui->screen_ethernet_label_speed_title = lv_label_create(ui->screen_ethernet);
	lv_label_set_text(ui->screen_ethernet_label_speed_title, "Speed");
	lv_label_set_long_mode(ui->screen_ethernet_label_speed_title, LV_LABEL_LONG_WRAP);
	lv_obj_set_pos(ui->screen_ethernet_label_speed_title, 25, 64);
	lv_obj_set_size(ui->screen_ethernet_label_speed_title, 85, 15);

	//Write style for screen_ethernet_label_speed_title, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->screen_ethernet_label_speed_title, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->screen_ethernet_label_speed_title, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->screen_ethernet_label_speed_title, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->screen_ethernet_label_speed_title, &lv_font_montserratMedium_14, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->screen_ethernet_label_speed_title, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_line_space(ui->screen_ethernet_label_speed_title, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->screen_ethernet_label_speed_title, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->screen_ethernet_label_speed_title, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->screen_ethernet_label_speed_title, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->screen_ethernet_label_speed_title, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->screen_ethernet_label_speed_title, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->screen_ethernet_label_speed_title, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->screen_ethernet_label_speed_title, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Update current screen layout.
	lv_obj_update_layout(ui->screen_ethernet);

	
	//Init events for screen.
	events_init_screen_ethernet(ui);
}
