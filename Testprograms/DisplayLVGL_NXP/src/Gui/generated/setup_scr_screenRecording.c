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


void setup_scr_screenRecording(lv_ui *ui)
{
	//Write codes screenRecording
	ui->screenRecording = lv_obj_create(NULL);
	lv_obj_set_size(ui->screenRecording, 240, 240);

	//Write style for screenRecording, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_bg_opa(ui->screenRecording, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui->screenRecording, lv_color_hex(0x101418), LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes screenRecording_cont_1
	ui->screenRecording_cont_1 = lv_obj_create(ui->screenRecording);
	lv_obj_set_pos(ui->screenRecording_cont_1, 0, 0);
	lv_obj_set_size(ui->screenRecording_cont_1, 240, 40);
	lv_obj_set_scrollbar_mode(ui->screenRecording_cont_1, LV_SCROLLBAR_MODE_OFF);

	//Write style for screenRecording_cont_1, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->screenRecording_cont_1, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_opa(ui->screenRecording_cont_1, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_color(ui->screenRecording_cont_1, lv_color_hex(0xD200AC), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_side(ui->screenRecording_cont_1, LV_BORDER_SIDE_BOTTOM, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->screenRecording_cont_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->screenRecording_cont_1, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui->screenRecording_cont_1, lv_color_hex(0x292831), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->screenRecording_cont_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->screenRecording_cont_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->screenRecording_cont_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->screenRecording_cont_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->screenRecording_cont_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes screenRecording_label_1
	ui->screenRecording_label_1 = lv_label_create(ui->screenRecording_cont_1);
	lv_label_set_text(ui->screenRecording_label_1, "");
	lv_label_set_long_mode(ui->screenRecording_label_1, LV_LABEL_LONG_WRAP);
	lv_obj_set_pos(ui->screenRecording_label_1, 96, 5);
	lv_obj_set_size(ui->screenRecording_label_1, 60, 28);

	//Write style for screenRecording_label_1, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->screenRecording_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->screenRecording_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->screenRecording_label_1, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->screenRecording_label_1, &lv_font_FontAwesome5ProRegular_400_16, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->screenRecording_label_1, 5, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_line_space(ui->screenRecording_label_1, 1, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->screenRecording_label_1, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->screenRecording_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->screenRecording_label_1, 6, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->screenRecording_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->screenRecording_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->screenRecording_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->screenRecording_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes screenRecording_btnCurrentTime
	ui->screenRecording_btnCurrentTime = lv_btn_create(ui->screenRecording_cont_1);
	ui->screenRecording_btnCurrentTime_label = lv_label_create(ui->screenRecording_btnCurrentTime);
	lv_label_set_text(ui->screenRecording_btnCurrentTime_label, "00:00");
	lv_label_set_long_mode(ui->screenRecording_btnCurrentTime_label, LV_LABEL_LONG_WRAP);
	lv_obj_align(ui->screenRecording_btnCurrentTime_label, LV_ALIGN_CENTER, 0, 0);
	lv_obj_set_style_pad_all(ui->screenRecording_btnCurrentTime, 0, LV_STATE_DEFAULT);
	lv_obj_set_pos(ui->screenRecording_btnCurrentTime, 7, 6);
	lv_obj_set_size(ui->screenRecording_btnCurrentTime, 60, 28);

	//Write style for screenRecording_btnCurrentTime, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_bg_opa(ui->screenRecording_btnCurrentTime, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_width(ui->screenRecording_btnCurrentTime, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->screenRecording_btnCurrentTime, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->screenRecording_btnCurrentTime, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->screenRecording_btnCurrentTime, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->screenRecording_btnCurrentTime, &lv_font_montserratMedium_16, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->screenRecording_btnCurrentTime, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes screenRecording_label_2
	ui->screenRecording_label_2 = lv_label_create(ui->screenRecording_cont_1);
	lv_label_set_text(ui->screenRecording_label_2, "");
	lv_label_set_long_mode(ui->screenRecording_label_2, LV_LABEL_LONG_WRAP);
	lv_obj_set_pos(ui->screenRecording_label_2, 128, 70);
	lv_obj_set_size(ui->screenRecording_label_2, 34, 18);

	//Write style for screenRecording_label_2, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->screenRecording_label_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->screenRecording_label_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->screenRecording_label_2, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->screenRecording_label_2, &lv_font_FontAwesome5_16, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->screenRecording_label_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_line_space(ui->screenRecording_label_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->screenRecording_label_2, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->screenRecording_label_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->screenRecording_label_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->screenRecording_label_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->screenRecording_label_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->screenRecording_label_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->screenRecording_label_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Update current screen layout.
	lv_obj_update_layout(ui->screenRecording);

	
}
