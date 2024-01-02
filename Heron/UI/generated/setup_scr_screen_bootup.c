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


void setup_scr_screen_bootup(lv_ui *ui)
{
	//Write codes screen_bootup
	ui->screen_bootup = lv_obj_create(NULL);
	lv_obj_set_size(ui->screen_bootup, 240, 240);

	//Write style for screen_bootup, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_bg_opa(ui->screen_bootup, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui->screen_bootup, lv_color_hex(0x101418), LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes screen_bootup_label_project
	ui->screen_bootup_label_project = lv_label_create(ui->screen_bootup);
	lv_label_set_text(ui->screen_bootup_label_project, "Project");
	lv_label_set_long_mode(ui->screen_bootup_label_project, LV_LABEL_LONG_WRAP);
	lv_obj_set_pos(ui->screen_bootup_label_project, 100, 77);
	lv_obj_set_size(ui->screen_bootup_label_project, 115, 33);

	//Write style for screen_bootup_label_project, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->screen_bootup_label_project, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->screen_bootup_label_project, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->screen_bootup_label_project, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->screen_bootup_label_project, &lv_font_MontserratRegular_28, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->screen_bootup_label_project, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_line_space(ui->screen_bootup_label_project, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->screen_bootup_label_project, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->screen_bootup_label_project, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->screen_bootup_label_project, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->screen_bootup_label_project, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->screen_bootup_label_project, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->screen_bootup_label_project, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->screen_bootup_label_project, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes screen_bootup_img_heron
	ui->screen_bootup_img_heron = lv_img_create(ui->screen_bootup);
	lv_obj_add_flag(ui->screen_bootup_img_heron, LV_OBJ_FLAG_CLICKABLE);
	lv_img_set_src(ui->screen_bootup_img_heron, &_Heron_alpha_80x80);
	lv_img_set_pivot(ui->screen_bootup_img_heron, 50,50);
	lv_img_set_angle(ui->screen_bootup_img_heron, 0);
	lv_obj_set_pos(ui->screen_bootup_img_heron, 20, 80);
	lv_obj_set_size(ui->screen_bootup_img_heron, 80, 80);

	//Write style for screen_bootup_img_heron, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_img_opa(ui->screen_bootup_img_heron, 255, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes screen_bootup_label_version
	ui->screen_bootup_label_version = lv_label_create(ui->screen_bootup);
	lv_label_set_text(ui->screen_bootup_label_version, "Vx.x-yymmdd");
	lv_label_set_long_mode(ui->screen_bootup_label_version, LV_LABEL_LONG_WRAP);
	lv_obj_set_pos(ui->screen_bootup_label_version, 70, 217);
	lv_obj_set_size(ui->screen_bootup_label_version, 100, 15);

	//Write style for screen_bootup_label_version, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->screen_bootup_label_version, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->screen_bootup_label_version, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->screen_bootup_label_version, lv_color_hex(0x8a8a8a), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->screen_bootup_label_version, &lv_font_montserratMedium_12, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->screen_bootup_label_version, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_line_space(ui->screen_bootup_label_version, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->screen_bootup_label_version, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->screen_bootup_label_version, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->screen_bootup_label_version, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->screen_bootup_label_version, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->screen_bootup_label_version, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->screen_bootup_label_version, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->screen_bootup_label_version, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes screen_bootup_img_icai
	ui->screen_bootup_img_icai = lv_img_create(ui->screen_bootup);
	lv_obj_add_flag(ui->screen_bootup_img_icai, LV_OBJ_FLAG_CLICKABLE);
	lv_img_set_src(ui->screen_bootup_img_icai, &_icai_inverted_small_alpha_101x40);
	lv_img_set_pivot(ui->screen_bootup_img_icai, 50,50);
	lv_img_set_angle(ui->screen_bootup_img_icai, 0);
	lv_obj_set_pos(ui->screen_bootup_img_icai, 70, 18);
	lv_obj_set_size(ui->screen_bootup_img_icai, 101, 40);

	//Write style for screen_bootup_img_icai, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_img_opa(ui->screen_bootup_img_icai, 255, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes screen_bootup_label_names
	ui->screen_bootup_label_names = lv_label_create(ui->screen_bootup);
	lv_label_set_text(ui->screen_bootup_label_names, "Florian Baumgartner\nAlain Keller");
	lv_label_set_long_mode(ui->screen_bootup_label_names, LV_LABEL_LONG_WRAP);
	lv_obj_set_pos(ui->screen_bootup_label_names, 45, 180);
	lv_obj_set_size(ui->screen_bootup_label_names, 150, 32);

	//Write style for screen_bootup_label_names, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->screen_bootup_label_names, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->screen_bootup_label_names, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->screen_bootup_label_names, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->screen_bootup_label_names, &lv_font_montserratMedium_12, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->screen_bootup_label_names, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_line_space(ui->screen_bootup_label_names, 5, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->screen_bootup_label_names, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->screen_bootup_label_names, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->screen_bootup_label_names, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->screen_bootup_label_names, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->screen_bootup_label_names, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->screen_bootup_label_names, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->screen_bootup_label_names, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes screen_bootup_label_year
	ui->screen_bootup_label_year = lv_label_create(ui->screen_bootup);
	lv_label_set_text(ui->screen_bootup_label_year, "2023 - 2024\n");
	lv_label_set_long_mode(ui->screen_bootup_label_year, LV_LABEL_LONG_WRAP);
	lv_obj_set_pos(ui->screen_bootup_label_year, 103, 145);
	lv_obj_set_size(ui->screen_bootup_label_year, 70, 14);

	//Write style for screen_bootup_label_year, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->screen_bootup_label_year, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->screen_bootup_label_year, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->screen_bootup_label_year, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->screen_bootup_label_year, &lv_font_montserratMedium_12, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->screen_bootup_label_year, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_line_space(ui->screen_bootup_label_year, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->screen_bootup_label_year, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->screen_bootup_label_year, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->screen_bootup_label_year, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->screen_bootup_label_year, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->screen_bootup_label_year, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->screen_bootup_label_year, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->screen_bootup_label_year, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes screen_bootup_label_heron
	ui->screen_bootup_label_heron = lv_label_create(ui->screen_bootup);
	lv_label_set_text(ui->screen_bootup_label_heron, "Heron");
	lv_label_set_long_mode(ui->screen_bootup_label_heron, LV_LABEL_LONG_WRAP);
	lv_obj_set_pos(ui->screen_bootup_label_heron, 100, 108);
	lv_obj_set_size(ui->screen_bootup_label_heron, 109, 34);

	//Write style for screen_bootup_label_heron, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->screen_bootup_label_heron, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_opa(ui->screen_bootup_label_heron, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_color(ui->screen_bootup_label_heron, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_side(ui->screen_bootup_label_heron, LV_BORDER_SIDE_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->screen_bootup_label_heron, 5, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->screen_bootup_label_heron, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->screen_bootup_label_heron, &lv_font_MontserratRegular_28, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->screen_bootup_label_heron, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_line_space(ui->screen_bootup_label_heron, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->screen_bootup_label_heron, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->screen_bootup_label_heron, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->screen_bootup_label_heron, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->screen_bootup_label_heron, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->screen_bootup_label_heron, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->screen_bootup_label_heron, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->screen_bootup_label_heron, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Update current screen layout.
	lv_obj_update_layout(ui->screen_bootup);

	
	//Init events for screen.
	events_init_screen_bootup(ui);
}
