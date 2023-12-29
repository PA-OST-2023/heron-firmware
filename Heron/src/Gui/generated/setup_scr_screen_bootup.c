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
	lv_label_set_text(ui->screen_bootup_label_1, "Heron");
	lv_label_set_long_mode(ui->screen_bootup_label_1, LV_LABEL_LONG_WRAP);
	lv_obj_set_pos(ui->screen_bootup_label_1, 75, 27);
	lv_obj_set_size(ui->screen_bootup_label_1, 90, 39);

	//Write style for screen_bootup_label_1, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->screen_bootup_label_1, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_opa(ui->screen_bootup_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_color(ui->screen_bootup_label_1, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_side(ui->screen_bootup_label_1, LV_BORDER_SIDE_FULL, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->screen_bootup_label_1, 5, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->screen_bootup_label_1, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->screen_bootup_label_1, &lv_font_MontserratRegular_20, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->screen_bootup_label_1, 1, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_line_space(ui->screen_bootup_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->screen_bootup_label_1, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->screen_bootup_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->screen_bootup_label_1, 8, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->screen_bootup_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->screen_bootup_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->screen_bootup_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->screen_bootup_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes screen_bootup_img_2
	ui->screen_bootup_img_2 = lv_img_create(ui->screen_bootup);
	lv_obj_add_flag(ui->screen_bootup_img_2, LV_OBJ_FLAG_CLICKABLE);
	lv_img_set_src(ui->screen_bootup_img_2, &_Heron_alpha_100x100);
	lv_img_set_pivot(ui->screen_bootup_img_2, 50,50);
	lv_img_set_angle(ui->screen_bootup_img_2, 0);
	lv_obj_set_pos(ui->screen_bootup_img_2, 70, 81);
	lv_obj_set_size(ui->screen_bootup_img_2, 100, 100);

	//Write style for screen_bootup_img_2, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_img_opa(ui->screen_bootup_img_2, 255, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Update current screen layout.
	lv_obj_update_layout(ui->screen_bootup);

	
	//Init events for screen.
	events_init_screen_bootup(ui);
}
