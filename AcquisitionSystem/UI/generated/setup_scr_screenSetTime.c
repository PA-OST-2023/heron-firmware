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


void setup_scr_screenSetTime(lv_ui *ui)
{
	//Write codes screenSetTime
	ui->screenSetTime = lv_obj_create(NULL);
	lv_obj_set_size(ui->screenSetTime, 240, 240);

	//Write style for screenSetTime, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_bg_opa(ui->screenSetTime, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui->screenSetTime, lv_color_hex(0x101418), LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes screenSetTime_cont_2
	ui->screenSetTime_cont_2 = lv_obj_create(ui->screenSetTime);
	lv_obj_set_pos(ui->screenSetTime_cont_2, 0, 0);
	lv_obj_set_size(ui->screenSetTime_cont_2, 240, 40);
	lv_obj_set_scrollbar_mode(ui->screenSetTime_cont_2, LV_SCROLLBAR_MODE_OFF);

	//Write style for screenSetTime_cont_2, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->screenSetTime_cont_2, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_opa(ui->screenSetTime_cont_2, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_color(ui->screenSetTime_cont_2, lv_color_hex(0xD200AC), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_side(ui->screenSetTime_cont_2, LV_BORDER_SIDE_BOTTOM, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->screenSetTime_cont_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->screenSetTime_cont_2, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui->screenSetTime_cont_2, lv_color_hex(0x292831), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->screenSetTime_cont_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->screenSetTime_cont_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->screenSetTime_cont_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->screenSetTime_cont_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->screenSetTime_cont_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes screenSetTime_label_4
	ui->screenSetTime_label_4 = lv_label_create(ui->screenSetTime);
	lv_label_set_text(ui->screenSetTime_label_4, "Set RTC Time");
	lv_label_set_long_mode(ui->screenSetTime_label_4, LV_LABEL_LONG_WRAP);
	lv_obj_set_pos(ui->screenSetTime_label_4, 0, 5);
	lv_obj_set_size(ui->screenSetTime_label_4, 240, 28);

	//Write style for screenSetTime_label_4, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->screenSetTime_label_4, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->screenSetTime_label_4, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->screenSetTime_label_4, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->screenSetTime_label_4, &lv_font_montserratMedium_16, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->screenSetTime_label_4, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_line_space(ui->screenSetTime_label_4, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->screenSetTime_label_4, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->screenSetTime_label_4, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->screenSetTime_label_4, 8, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->screenSetTime_label_4, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->screenSetTime_label_4, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->screenSetTime_label_4, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->screenSetTime_label_4, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes screenSetTime_btn_1
	ui->screenSetTime_btn_1 = lv_btn_create(ui->screenSetTime);
	ui->screenSetTime_btn_1_label = lv_label_create(ui->screenSetTime_btn_1);
	lv_label_set_text(ui->screenSetTime_btn_1_label, " ");
	lv_label_set_long_mode(ui->screenSetTime_btn_1_label, LV_LABEL_LONG_WRAP);
	lv_obj_align(ui->screenSetTime_btn_1_label, LV_ALIGN_LEFT_MID, 0, 0);
	lv_obj_set_style_pad_all(ui->screenSetTime_btn_1, 0, LV_STATE_DEFAULT);
	lv_obj_set_pos(ui->screenSetTime_btn_1, 7, 6);
	lv_obj_set_size(ui->screenSetTime_btn_1, 60, 28);

	//Write style for screenSetTime_btn_1, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_bg_opa(ui->screenSetTime_btn_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_width(ui->screenSetTime_btn_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->screenSetTime_btn_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->screenSetTime_btn_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->screenSetTime_btn_1, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->screenSetTime_btn_1, &lv_font_FontAwesome5ProRegular_400_16, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->screenSetTime_btn_1, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes screenSetTime_btnUpdateTime
	ui->screenSetTime_btnUpdateTime = lv_btn_create(ui->screenSetTime);
	ui->screenSetTime_btnUpdateTime_label = lv_label_create(ui->screenSetTime_btnUpdateTime);
	lv_label_set_text(ui->screenSetTime_btnUpdateTime_label, "Update");
	lv_label_set_long_mode(ui->screenSetTime_btnUpdateTime_label, LV_LABEL_LONG_WRAP);
	lv_obj_align(ui->screenSetTime_btnUpdateTime_label, LV_ALIGN_CENTER, 0, 0);
	lv_obj_set_style_pad_all(ui->screenSetTime_btnUpdateTime, 0, LV_STATE_DEFAULT);
	lv_obj_set_pos(ui->screenSetTime_btnUpdateTime, 10, 184);
	lv_obj_set_size(ui->screenSetTime_btnUpdateTime, 220, 45);

	//Write style for screenSetTime_btnUpdateTime, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_bg_opa(ui->screenSetTime_btnUpdateTime, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui->screenSetTime_btnUpdateTime, lv_color_hex(0x292831), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_width(ui->screenSetTime_btnUpdateTime, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_opa(ui->screenSetTime_btnUpdateTime, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_color(ui->screenSetTime_btnUpdateTime, lv_color_hex(0xD200AC), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_side(ui->screenSetTime_btnUpdateTime, LV_BORDER_SIDE_FULL, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->screenSetTime_btnUpdateTime, 5, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->screenSetTime_btnUpdateTime, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->screenSetTime_btnUpdateTime, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->screenSetTime_btnUpdateTime, &lv_font_montserratMedium_16, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->screenSetTime_btnUpdateTime, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes screenSetTime_label_8
	ui->screenSetTime_label_8 = lv_label_create(ui->screenSetTime);
	lv_label_set_text(ui->screenSetTime_label_8, ":");
	lv_label_set_long_mode(ui->screenSetTime_label_8, LV_LABEL_LONG_WRAP);
	lv_obj_set_pos(ui->screenSetTime_label_8, 149, 123);
	lv_obj_set_size(ui->screenSetTime_label_8, 12, 24);

	//Write style for screenSetTime_label_8, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->screenSetTime_label_8, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->screenSetTime_label_8, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->screenSetTime_label_8, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->screenSetTime_label_8, &lv_font_montserratMedium_16, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->screenSetTime_label_8, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_line_space(ui->screenSetTime_label_8, 1, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->screenSetTime_label_8, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->screenSetTime_label_8, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->screenSetTime_label_8, 6, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->screenSetTime_label_8, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->screenSetTime_label_8, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->screenSetTime_label_8, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->screenSetTime_label_8, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes screenSetTime_label_7
	ui->screenSetTime_label_7 = lv_label_create(ui->screenSetTime);
	lv_label_set_text(ui->screenSetTime_label_7, ":");
	lv_label_set_long_mode(ui->screenSetTime_label_7, LV_LABEL_LONG_WRAP);
	lv_obj_set_pos(ui->screenSetTime_label_7, 79, 123);
	lv_obj_set_size(ui->screenSetTime_label_7, 12, 24);

	//Write style for screenSetTime_label_7, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->screenSetTime_label_7, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->screenSetTime_label_7, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->screenSetTime_label_7, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->screenSetTime_label_7, &lv_font_montserratMedium_16, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->screenSetTime_label_7, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_line_space(ui->screenSetTime_label_7, 1, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->screenSetTime_label_7, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->screenSetTime_label_7, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->screenSetTime_label_7, 6, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->screenSetTime_label_7, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->screenSetTime_label_7, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->screenSetTime_label_7, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->screenSetTime_label_7, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes screenSetTime_label_6
	ui->screenSetTime_label_6 = lv_label_create(ui->screenSetTime);
	lv_label_set_text(ui->screenSetTime_label_6, ".");
	lv_label_set_long_mode(ui->screenSetTime_label_6, LV_LABEL_LONG_WRAP);
	lv_obj_set_pos(ui->screenSetTime_label_6, 153, 69);
	lv_obj_set_size(ui->screenSetTime_label_6, 12, 24);

	//Write style for screenSetTime_label_6, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->screenSetTime_label_6, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->screenSetTime_label_6, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->screenSetTime_label_6, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->screenSetTime_label_6, &lv_font_montserratMedium_16, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->screenSetTime_label_6, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_line_space(ui->screenSetTime_label_6, 1, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->screenSetTime_label_6, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->screenSetTime_label_6, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->screenSetTime_label_6, 6, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->screenSetTime_label_6, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->screenSetTime_label_6, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->screenSetTime_label_6, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->screenSetTime_label_6, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes screenSetTime_label_5
	ui->screenSetTime_label_5 = lv_label_create(ui->screenSetTime);
	lv_label_set_text(ui->screenSetTime_label_5, ".");
	lv_label_set_long_mode(ui->screenSetTime_label_5, LV_LABEL_LONG_WRAP);
	lv_obj_set_pos(ui->screenSetTime_label_5, 75, 69);
	lv_obj_set_size(ui->screenSetTime_label_5, 12, 24);

	//Write style for screenSetTime_label_5, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->screenSetTime_label_5, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->screenSetTime_label_5, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->screenSetTime_label_5, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->screenSetTime_label_5, &lv_font_montserratMedium_16, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->screenSetTime_label_5, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_line_space(ui->screenSetTime_label_5, 1, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->screenSetTime_label_5, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->screenSetTime_label_5, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->screenSetTime_label_5, 6, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->screenSetTime_label_5, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->screenSetTime_label_5, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->screenSetTime_label_5, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->screenSetTime_label_5, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes screenSetTime_rollerSecond
	ui->screenSetTime_rollerSecond = lv_roller_create(ui->screenSetTime);
	lv_roller_set_options(ui->screenSetTime_rollerSecond, "00\n01\n02\n03\n04\n05\n06\n07\n08\n09\n10\n11\n12\n13\n14\n15\n16\n17\n18\n19\n20\n21\n22\n23\n24\n25\n26\n27\n28\n29\n30\n31\n32\n33\n34\n35\n36\n37\n38\n39\n40\n41\n42\n43\n44\n45\n46\n47\n48\n49\n50\n51\n52\n53\n54\n55\n56\n57\n58\n59", LV_ROLLER_MODE_NORMAL);
	lv_roller_set_visible_row_count(ui->screenSetTime_rollerSecond, 1);
	lv_obj_set_pos(ui->screenSetTime_rollerSecond, 162, 120);
	lv_obj_set_width(ui->screenSetTime_rollerSecond, 56);

	//Write style for screenSetTime_rollerSecond, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_radius(ui->screenSetTime_rollerSecond, 5, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->screenSetTime_rollerSecond, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui->screenSetTime_rollerSecond, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->screenSetTime_rollerSecond, lv_color_hex(0x333333), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->screenSetTime_rollerSecond, &lv_font_montserratMedium_16, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->screenSetTime_rollerSecond, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_width(ui->screenSetTime_rollerSecond, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_opa(ui->screenSetTime_rollerSecond, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_color(ui->screenSetTime_rollerSecond, lv_color_hex(0x293031), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_side(ui->screenSetTime_rollerSecond, LV_BORDER_SIDE_FULL, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->screenSetTime_rollerSecond, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write style for screenSetTime_rollerSecond, Part: LV_PART_SELECTED, State: LV_STATE_DEFAULT.
	lv_obj_set_style_bg_opa(ui->screenSetTime_rollerSecond, 255, LV_PART_SELECTED|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui->screenSetTime_rollerSecond, lv_color_hex(0x292831), LV_PART_SELECTED|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->screenSetTime_rollerSecond, lv_color_hex(0xFFFFFF), LV_PART_SELECTED|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->screenSetTime_rollerSecond, &lv_font_montserratMedium_16, LV_PART_SELECTED|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->screenSetTime_rollerSecond, LV_TEXT_ALIGN_CENTER, LV_PART_SELECTED|LV_STATE_DEFAULT);

	//Write codes screenSetTime_rollerMinute
	ui->screenSetTime_rollerMinute = lv_roller_create(ui->screenSetTime);
	lv_roller_set_options(ui->screenSetTime_rollerMinute, "00\n01\n02\n03\n04\n05\n06\n07\n08\n09\n10\n11\n12\n13\n14\n15\n16\n17\n18\n19\n20\n21\n22\n23\n24\n25\n26\n27\n28\n29\n30\n31\n32\n33\n34\n35\n36\n37\n38\n39\n40\n41\n42\n43\n44\n45\n46\n47\n48\n49\n50\n51\n52\n53\n54\n55\n56\n57\n58\n59", LV_ROLLER_MODE_NORMAL);
	lv_roller_set_visible_row_count(ui->screenSetTime_rollerMinute, 1);
	lv_obj_set_pos(ui->screenSetTime_rollerMinute, 92, 120);
	lv_obj_set_width(ui->screenSetTime_rollerMinute, 56);

	//Write style for screenSetTime_rollerMinute, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_radius(ui->screenSetTime_rollerMinute, 5, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->screenSetTime_rollerMinute, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui->screenSetTime_rollerMinute, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->screenSetTime_rollerMinute, lv_color_hex(0x333333), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->screenSetTime_rollerMinute, &lv_font_montserratMedium_16, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->screenSetTime_rollerMinute, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_width(ui->screenSetTime_rollerMinute, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_opa(ui->screenSetTime_rollerMinute, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_color(ui->screenSetTime_rollerMinute, lv_color_hex(0x293031), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_side(ui->screenSetTime_rollerMinute, LV_BORDER_SIDE_FULL, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->screenSetTime_rollerMinute, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write style for screenSetTime_rollerMinute, Part: LV_PART_SELECTED, State: LV_STATE_DEFAULT.
	lv_obj_set_style_bg_opa(ui->screenSetTime_rollerMinute, 255, LV_PART_SELECTED|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui->screenSetTime_rollerMinute, lv_color_hex(0x292831), LV_PART_SELECTED|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->screenSetTime_rollerMinute, lv_color_hex(0xFFFFFF), LV_PART_SELECTED|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->screenSetTime_rollerMinute, &lv_font_montserratMedium_16, LV_PART_SELECTED|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->screenSetTime_rollerMinute, LV_TEXT_ALIGN_CENTER, LV_PART_SELECTED|LV_STATE_DEFAULT);

	//Write codes screenSetTime_rollerHour
	ui->screenSetTime_rollerHour = lv_roller_create(ui->screenSetTime);
	lv_roller_set_options(ui->screenSetTime_rollerHour, "00\n01\n02\n03\n04\n05\n06\n07\n08\n09\n10\n11\n12\n13\n14\n15\n16\n17\n18\n19\n20\n21\n22\n23", LV_ROLLER_MODE_NORMAL);
	lv_roller_set_visible_row_count(ui->screenSetTime_rollerHour, 1);
	lv_obj_set_pos(ui->screenSetTime_rollerHour, 22, 120);
	lv_obj_set_width(ui->screenSetTime_rollerHour, 56);

	//Write style for screenSetTime_rollerHour, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_radius(ui->screenSetTime_rollerHour, 5, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->screenSetTime_rollerHour, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui->screenSetTime_rollerHour, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->screenSetTime_rollerHour, lv_color_hex(0x333333), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->screenSetTime_rollerHour, &lv_font_montserratMedium_16, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->screenSetTime_rollerHour, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_width(ui->screenSetTime_rollerHour, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_opa(ui->screenSetTime_rollerHour, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_color(ui->screenSetTime_rollerHour, lv_color_hex(0x293031), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_side(ui->screenSetTime_rollerHour, LV_BORDER_SIDE_FULL, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->screenSetTime_rollerHour, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write style for screenSetTime_rollerHour, Part: LV_PART_SELECTED, State: LV_STATE_DEFAULT.
	lv_obj_set_style_bg_opa(ui->screenSetTime_rollerHour, 255, LV_PART_SELECTED|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui->screenSetTime_rollerHour, lv_color_hex(0x292831), LV_PART_SELECTED|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->screenSetTime_rollerHour, lv_color_hex(0xFFFFFF), LV_PART_SELECTED|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->screenSetTime_rollerHour, &lv_font_montserratMedium_16, LV_PART_SELECTED|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->screenSetTime_rollerHour, LV_TEXT_ALIGN_CENTER, LV_PART_SELECTED|LV_STATE_DEFAULT);

	//Write codes screenSetTime_rollerYear
	ui->screenSetTime_rollerYear = lv_roller_create(ui->screenSetTime);
	lv_roller_set_options(ui->screenSetTime_rollerYear, "2023\n2024\n2025\n2026\n2027\n2028\n2029\n2030", LV_ROLLER_MODE_NORMAL);
	lv_roller_set_visible_row_count(ui->screenSetTime_rollerYear, 1);
	lv_obj_set_pos(ui->screenSetTime_rollerYear, 166, 60);
	lv_obj_set_width(ui->screenSetTime_rollerYear, 64);

	//Write style for screenSetTime_rollerYear, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_radius(ui->screenSetTime_rollerYear, 5, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->screenSetTime_rollerYear, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui->screenSetTime_rollerYear, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->screenSetTime_rollerYear, lv_color_hex(0x333333), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->screenSetTime_rollerYear, &lv_font_montserratMedium_16, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->screenSetTime_rollerYear, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_width(ui->screenSetTime_rollerYear, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_opa(ui->screenSetTime_rollerYear, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_color(ui->screenSetTime_rollerYear, lv_color_hex(0x293031), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_side(ui->screenSetTime_rollerYear, LV_BORDER_SIDE_FULL, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->screenSetTime_rollerYear, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write style for screenSetTime_rollerYear, Part: LV_PART_SELECTED, State: LV_STATE_DEFAULT.
	lv_obj_set_style_bg_opa(ui->screenSetTime_rollerYear, 255, LV_PART_SELECTED|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui->screenSetTime_rollerYear, lv_color_hex(0x292831), LV_PART_SELECTED|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->screenSetTime_rollerYear, lv_color_hex(0xFFFFFF), LV_PART_SELECTED|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->screenSetTime_rollerYear, &lv_font_montserratMedium_16, LV_PART_SELECTED|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->screenSetTime_rollerYear, LV_TEXT_ALIGN_CENTER, LV_PART_SELECTED|LV_STATE_DEFAULT);

	//Write codes screenSetTime_rollerMonth
	ui->screenSetTime_rollerMonth = lv_roller_create(ui->screenSetTime);
	lv_roller_set_options(ui->screenSetTime_rollerMonth, "01\n02\n03\n04\n05\n06\n07\n08\n09\n10\n11\n12", LV_ROLLER_MODE_NORMAL);
	lv_roller_set_visible_row_count(ui->screenSetTime_rollerMonth, 1);
	lv_obj_set_pos(ui->screenSetTime_rollerMonth, 88, 60);
	lv_obj_set_width(ui->screenSetTime_rollerMonth, 64);

	//Write style for screenSetTime_rollerMonth, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_radius(ui->screenSetTime_rollerMonth, 5, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->screenSetTime_rollerMonth, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui->screenSetTime_rollerMonth, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->screenSetTime_rollerMonth, lv_color_hex(0x333333), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->screenSetTime_rollerMonth, &lv_font_montserratMedium_16, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->screenSetTime_rollerMonth, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_width(ui->screenSetTime_rollerMonth, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_opa(ui->screenSetTime_rollerMonth, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_color(ui->screenSetTime_rollerMonth, lv_color_hex(0x293031), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_side(ui->screenSetTime_rollerMonth, LV_BORDER_SIDE_FULL, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->screenSetTime_rollerMonth, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write style for screenSetTime_rollerMonth, Part: LV_PART_SELECTED, State: LV_STATE_DEFAULT.
	lv_obj_set_style_bg_opa(ui->screenSetTime_rollerMonth, 255, LV_PART_SELECTED|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui->screenSetTime_rollerMonth, lv_color_hex(0x292831), LV_PART_SELECTED|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->screenSetTime_rollerMonth, lv_color_hex(0xFFFFFF), LV_PART_SELECTED|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->screenSetTime_rollerMonth, &lv_font_montserratMedium_16, LV_PART_SELECTED|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->screenSetTime_rollerMonth, LV_TEXT_ALIGN_CENTER, LV_PART_SELECTED|LV_STATE_DEFAULT);

	//Write codes screenSetTime_rollerDay
	ui->screenSetTime_rollerDay = lv_roller_create(ui->screenSetTime);
	lv_roller_set_options(ui->screenSetTime_rollerDay, "01\n02\n03\n04\n05\n06\n07\n08\n09\n10\n11\n12\n13\n14\n15\n16\n17\n18\n19\n20\n21\n22\n23\n24\n25\n26\n27\n28\n29\n30\n31", LV_ROLLER_MODE_NORMAL);
	lv_roller_set_visible_row_count(ui->screenSetTime_rollerDay, 1);
	lv_obj_set_pos(ui->screenSetTime_rollerDay, 10, 60);
	lv_obj_set_width(ui->screenSetTime_rollerDay, 64);

	//Write style for screenSetTime_rollerDay, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_radius(ui->screenSetTime_rollerDay, 5, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->screenSetTime_rollerDay, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui->screenSetTime_rollerDay, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->screenSetTime_rollerDay, lv_color_hex(0x333333), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->screenSetTime_rollerDay, &lv_font_montserratMedium_16, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->screenSetTime_rollerDay, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_width(ui->screenSetTime_rollerDay, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_opa(ui->screenSetTime_rollerDay, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_color(ui->screenSetTime_rollerDay, lv_color_hex(0x293031), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_side(ui->screenSetTime_rollerDay, LV_BORDER_SIDE_FULL, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->screenSetTime_rollerDay, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write style for screenSetTime_rollerDay, Part: LV_PART_SELECTED, State: LV_STATE_DEFAULT.
	lv_obj_set_style_bg_opa(ui->screenSetTime_rollerDay, 255, LV_PART_SELECTED|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui->screenSetTime_rollerDay, lv_color_hex(0x292831), LV_PART_SELECTED|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->screenSetTime_rollerDay, lv_color_hex(0xFFFFFF), LV_PART_SELECTED|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->screenSetTime_rollerDay, &lv_font_montserratMedium_16, LV_PART_SELECTED|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->screenSetTime_rollerDay, LV_TEXT_ALIGN_CENTER, LV_PART_SELECTED|LV_STATE_DEFAULT);

	//Update current screen layout.
	lv_obj_update_layout(ui->screenSetTime);

	
	//Init events for screen.
	events_init_screenSetTime(ui);
}
