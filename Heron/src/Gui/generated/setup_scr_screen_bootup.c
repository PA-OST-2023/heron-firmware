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


FLASHMEM void setup_scr_screen_bootup(lv_ui *ui)
{
	//Write codes screen_bootup
	ui->screen_bootup = lv_obj_create(NULL);
	lv_obj_set_size(ui->screen_bootup, 240, 240);

	//Write style for screen_bootup, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_bg_opa(ui->screen_bootup, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui->screen_bootup, lv_color_hex(0x101418), LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes screen_bootup_label_1
	ui->screen_bootup_label_1 = lv_label_create(ui->screen_bootup);
	lv_label_set_text(ui->screen_bootup_label_1, "Project");
	lv_label_set_long_mode(ui->screen_bootup_label_1, LV_LABEL_LONG_WRAP);
	lv_obj_set_pos(ui->screen_bootup_label_1, 100, 77);
	lv_obj_set_size(ui->screen_bootup_label_1, 115, 33);

	//Write style for screen_bootup_label_1, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->screen_bootup_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->screen_bootup_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->screen_bootup_label_1, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->screen_bootup_label_1, &lv_font_MontserratRegular_28, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->screen_bootup_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_line_space(ui->screen_bootup_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->screen_bootup_label_1, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->screen_bootup_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->screen_bootup_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->screen_bootup_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->screen_bootup_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->screen_bootup_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->screen_bootup_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes screen_bootup_img_2
	ui->screen_bootup_img_2 = lv_img_create(ui->screen_bootup);
	lv_obj_add_flag(ui->screen_bootup_img_2, LV_OBJ_FLAG_CLICKABLE);
	lv_img_set_src(ui->screen_bootup_img_2, &_Heron_alpha_80x80);
	lv_img_set_pivot(ui->screen_bootup_img_2, 50,50);
	lv_img_set_angle(ui->screen_bootup_img_2, 0);
	lv_obj_set_pos(ui->screen_bootup_img_2, 20, 80);
	lv_obj_set_size(ui->screen_bootup_img_2, 80, 80);

	//Write style for screen_bootup_img_2, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_img_opa(ui->screen_bootup_img_2, 255, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes screen_bootup_label_2
	ui->screen_bootup_label_2 = lv_label_create(ui->screen_bootup);
	lv_label_set_text(ui->screen_bootup_label_2, "Vx.x-yymmdd");
	lv_label_set_long_mode(ui->screen_bootup_label_2, LV_LABEL_LONG_WRAP);
	lv_obj_set_pos(ui->screen_bootup_label_2, 70, 215);
	lv_obj_set_size(ui->screen_bootup_label_2, 100, 15);

	//Write style for screen_bootup_label_2, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->screen_bootup_label_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->screen_bootup_label_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->screen_bootup_label_2, lv_color_hex(0x8a8a8a), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->screen_bootup_label_2, &lv_font_montserratMedium_12, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->screen_bootup_label_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_line_space(ui->screen_bootup_label_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->screen_bootup_label_2, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->screen_bootup_label_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->screen_bootup_label_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->screen_bootup_label_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->screen_bootup_label_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->screen_bootup_label_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->screen_bootup_label_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes screen_bootup_img_3
	ui->screen_bootup_img_3 = lv_img_create(ui->screen_bootup);
	lv_obj_add_flag(ui->screen_bootup_img_3, LV_OBJ_FLAG_CLICKABLE);
	lv_img_set_src(ui->screen_bootup_img_3, &_icai_inverted_small_alpha_101x40);
	lv_img_set_pivot(ui->screen_bootup_img_3, 50,50);
	lv_img_set_angle(ui->screen_bootup_img_3, 0);
	lv_obj_set_pos(ui->screen_bootup_img_3, 70, 18);
	lv_obj_set_size(ui->screen_bootup_img_3, 101, 40);

	//Write style for screen_bootup_img_3, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_img_opa(ui->screen_bootup_img_3, 255, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes screen_bootup_label_3
	ui->screen_bootup_label_3 = lv_label_create(ui->screen_bootup);
	lv_label_set_text(ui->screen_bootup_label_3, "Florian Baumgartner\nAlain Keller");
	lv_label_set_long_mode(ui->screen_bootup_label_3, LV_LABEL_LONG_WRAP);
	lv_obj_set_pos(ui->screen_bootup_label_3, 45, 180);
	lv_obj_set_size(ui->screen_bootup_label_3, 150, 32);

	//Write style for screen_bootup_label_3, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->screen_bootup_label_3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->screen_bootup_label_3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->screen_bootup_label_3, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->screen_bootup_label_3, &lv_font_montserratMedium_12, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->screen_bootup_label_3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_line_space(ui->screen_bootup_label_3, 6, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->screen_bootup_label_3, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->screen_bootup_label_3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->screen_bootup_label_3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->screen_bootup_label_3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->screen_bootup_label_3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->screen_bootup_label_3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->screen_bootup_label_3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes screen_bootup_label_4
	ui->screen_bootup_label_4 = lv_label_create(ui->screen_bootup);
	lv_label_set_text(ui->screen_bootup_label_4, "2023 - 2024\n");
	lv_label_set_long_mode(ui->screen_bootup_label_4, LV_LABEL_LONG_WRAP);
	lv_obj_set_pos(ui->screen_bootup_label_4, 103, 145);
	lv_obj_set_size(ui->screen_bootup_label_4, 70, 14);

	//Write style for screen_bootup_label_4, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->screen_bootup_label_4, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->screen_bootup_label_4, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->screen_bootup_label_4, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->screen_bootup_label_4, &lv_font_montserratMedium_12, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->screen_bootup_label_4, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_line_space(ui->screen_bootup_label_4, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->screen_bootup_label_4, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->screen_bootup_label_4, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->screen_bootup_label_4, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->screen_bootup_label_4, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->screen_bootup_label_4, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->screen_bootup_label_4, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->screen_bootup_label_4, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes screen_bootup_label_5
	ui->screen_bootup_label_5 = lv_label_create(ui->screen_bootup);
	lv_label_set_text(ui->screen_bootup_label_5, "Heron");
	lv_label_set_long_mode(ui->screen_bootup_label_5, LV_LABEL_LONG_WRAP);
	lv_obj_set_pos(ui->screen_bootup_label_5, 100, 108);
	lv_obj_set_size(ui->screen_bootup_label_5, 109, 34);

	//Write style for screen_bootup_label_5, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->screen_bootup_label_5, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_opa(ui->screen_bootup_label_5, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_color(ui->screen_bootup_label_5, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_side(ui->screen_bootup_label_5, LV_BORDER_SIDE_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->screen_bootup_label_5, 5, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->screen_bootup_label_5, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->screen_bootup_label_5, &lv_font_MontserratRegular_28, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->screen_bootup_label_5, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_line_space(ui->screen_bootup_label_5, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->screen_bootup_label_5, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->screen_bootup_label_5, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->screen_bootup_label_5, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->screen_bootup_label_5, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->screen_bootup_label_5, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->screen_bootup_label_5, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->screen_bootup_label_5, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Update current screen layout.
	lv_obj_update_layout(ui->screen_bootup);

	
	//Init events for screen.
	events_init_screen_bootup(ui);
}
