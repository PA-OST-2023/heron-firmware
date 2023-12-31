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


void setup_scr_screenBootup(lv_ui *ui)
{
	//Write codes screenBootup
	ui->screenBootup = lv_obj_create(NULL);
	lv_obj_set_size(ui->screenBootup, 240, 240);

	//Write style for screenBootup, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_bg_opa(ui->screenBootup, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui->screenBootup, lv_color_hex(0x101418), LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes screenBootup_label_1
	ui->screenBootup_label_1 = lv_label_create(ui->screenBootup);
	lv_label_set_text(ui->screenBootup_label_1, "HERON");
	lv_label_set_long_mode(ui->screenBootup_label_1, LV_LABEL_LONG_WRAP);
	lv_obj_set_pos(ui->screenBootup_label_1, 78, 13);
	lv_obj_set_size(ui->screenBootup_label_1, 84, 32);

	//Write style for screenBootup_label_1, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->screenBootup_label_1, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_opa(ui->screenBootup_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_color(ui->screenBootup_label_1, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_side(ui->screenBootup_label_1, LV_BORDER_SIDE_FULL, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->screenBootup_label_1, 5, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->screenBootup_label_1, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->screenBootup_label_1, &lv_font_montserratMedium_16, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->screenBootup_label_1, 1, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_line_space(ui->screenBootup_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->screenBootup_label_1, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->screenBootup_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->screenBootup_label_1, 8, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->screenBootup_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->screenBootup_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->screenBootup_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->screenBootup_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes screenBootup_img_2
	ui->screenBootup_img_2 = lv_img_create(ui->screenBootup);
	lv_obj_add_flag(ui->screenBootup_img_2, LV_OBJ_FLAG_CLICKABLE);
	lv_img_set_src(ui->screenBootup_img_2, &_Heron_alpha_100x100);
	lv_img_set_pivot(ui->screenBootup_img_2, 50,50);
	lv_img_set_angle(ui->screenBootup_img_2, 0);
	lv_obj_set_pos(ui->screenBootup_img_2, 70, 110);
	lv_obj_set_size(ui->screenBootup_img_2, 100, 100);

	//Write style for screenBootup_img_2, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_img_opa(ui->screenBootup_img_2, 255, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes screenBootup_spinner_1
	ui->screenBootup_spinner_1 = lv_spinner_create(ui->screenBootup, 1000, 60);
	lv_obj_set_pos(ui->screenBootup_spinner_1, 154, 136);
	lv_obj_set_size(ui->screenBootup_spinner_1, 47, 49);

	//Write style for screenBootup_spinner_1, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_pad_top(ui->screenBootup_spinner_1, 5, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->screenBootup_spinner_1, 5, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->screenBootup_spinner_1, 5, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->screenBootup_spinner_1, 5, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->screenBootup_spinner_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_arc_width(ui->screenBootup_spinner_1, 12, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_arc_opa(ui->screenBootup_spinner_1, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_arc_color(ui->screenBootup_spinner_1, lv_color_hex(0xd5d6de), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->screenBootup_spinner_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write style for screenBootup_spinner_1, Part: LV_PART_INDICATOR, State: LV_STATE_DEFAULT.
	lv_obj_set_style_arc_width(ui->screenBootup_spinner_1, 12, LV_PART_INDICATOR|LV_STATE_DEFAULT);
	lv_obj_set_style_arc_opa(ui->screenBootup_spinner_1, 255, LV_PART_INDICATOR|LV_STATE_DEFAULT);
	lv_obj_set_style_arc_color(ui->screenBootup_spinner_1, lv_color_hex(0x2195f6), LV_PART_INDICATOR|LV_STATE_DEFAULT);

	//Write codes screenBootup_slider_1
	ui->screenBootup_slider_1 = lv_slider_create(ui->screenBootup);
	lv_slider_set_range(ui->screenBootup_slider_1, 0, 100);
	lv_slider_set_mode(ui->screenBootup_slider_1, LV_SLIDER_MODE_NORMAL);
	lv_slider_set_value(ui->screenBootup_slider_1, 50, LV_ANIM_OFF);
	lv_obj_set_pos(ui->screenBootup_slider_1, 40, 86);
	lv_obj_set_size(ui->screenBootup_slider_1, 160, 10);

	//Write style for screenBootup_slider_1, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_bg_opa(ui->screenBootup_slider_1, 60, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui->screenBootup_slider_1, lv_color_hex(0x2195f6), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->screenBootup_slider_1, 50, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_outline_width(ui->screenBootup_slider_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->screenBootup_slider_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write style for screenBootup_slider_1, Part: LV_PART_INDICATOR, State: LV_STATE_DEFAULT.
	lv_obj_set_style_bg_opa(ui->screenBootup_slider_1, 255, LV_PART_INDICATOR|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui->screenBootup_slider_1, lv_color_hex(0x2195f6), LV_PART_INDICATOR|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->screenBootup_slider_1, 50, LV_PART_INDICATOR|LV_STATE_DEFAULT);

	//Write style for screenBootup_slider_1, Part: LV_PART_KNOB, State: LV_STATE_DEFAULT.
	lv_obj_set_style_bg_opa(ui->screenBootup_slider_1, 255, LV_PART_KNOB|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui->screenBootup_slider_1, lv_color_hex(0x2195f6), LV_PART_KNOB|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->screenBootup_slider_1, 50, LV_PART_KNOB|LV_STATE_DEFAULT);

	//Update current screen layout.
	lv_obj_update_layout(ui->screenBootup);

	
	//Init events for screen.
	events_init_screenBootup(ui);
}
