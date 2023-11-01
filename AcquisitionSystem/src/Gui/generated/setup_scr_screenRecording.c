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

	//Write codes screenRecording_cont_top_bar
	ui->screenRecording_cont_top_bar = lv_obj_create(ui->screenRecording);
	lv_obj_set_pos(ui->screenRecording_cont_top_bar, 0, 0);
	lv_obj_set_size(ui->screenRecording_cont_top_bar, 240, 40);
	lv_obj_set_scrollbar_mode(ui->screenRecording_cont_top_bar, LV_SCROLLBAR_MODE_OFF);

	//Write style for screenRecording_cont_top_bar, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->screenRecording_cont_top_bar, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_opa(ui->screenRecording_cont_top_bar, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_color(ui->screenRecording_cont_top_bar, lv_color_hex(0xD200AC), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_side(ui->screenRecording_cont_top_bar, LV_BORDER_SIDE_BOTTOM, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->screenRecording_cont_top_bar, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->screenRecording_cont_top_bar, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui->screenRecording_cont_top_bar, lv_color_hex(0x292831), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->screenRecording_cont_top_bar, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->screenRecording_cont_top_bar, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->screenRecording_cont_top_bar, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->screenRecording_cont_top_bar, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->screenRecording_cont_top_bar, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes screenRecording_btn_warning
	ui->screenRecording_btn_warning = lv_btn_create(ui->screenRecording_cont_top_bar);
	ui->screenRecording_btn_warning_label = lv_label_create(ui->screenRecording_btn_warning);
	lv_label_set_text(ui->screenRecording_btn_warning_label, "");
	lv_label_set_long_mode(ui->screenRecording_btn_warning_label, LV_LABEL_LONG_WRAP);
	lv_obj_align(ui->screenRecording_btn_warning_label, LV_ALIGN_CENTER, 0, 0);
	lv_obj_set_style_pad_all(ui->screenRecording_btn_warning, 0, LV_STATE_DEFAULT);
	lv_obj_set_pos(ui->screenRecording_btn_warning, 71, 6);
	lv_obj_set_size(ui->screenRecording_btn_warning, 30, 28);

	//Write style for screenRecording_btn_warning, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_bg_opa(ui->screenRecording_btn_warning, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_width(ui->screenRecording_btn_warning, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->screenRecording_btn_warning, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->screenRecording_btn_warning, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->screenRecording_btn_warning, lv_color_hex(0xff8f00), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->screenRecording_btn_warning, &lv_font_FontAwesome5ProSolid_900_16, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->screenRecording_btn_warning, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes screenRecording_label_ethernet
	ui->screenRecording_label_ethernet = lv_label_create(ui->screenRecording_cont_top_bar);
	lv_label_set_text(ui->screenRecording_label_ethernet, "");
	lv_label_set_long_mode(ui->screenRecording_label_ethernet, LV_LABEL_LONG_WRAP);
	lv_obj_set_pos(ui->screenRecording_label_ethernet, 107, 6);
	lv_obj_set_size(ui->screenRecording_label_ethernet, 20, 28);

	//Write style for screenRecording_label_ethernet, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->screenRecording_label_ethernet, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->screenRecording_label_ethernet, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->screenRecording_label_ethernet, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->screenRecording_label_ethernet, &lv_font_FontAwesome5ProRegular_400_16, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->screenRecording_label_ethernet, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_line_space(ui->screenRecording_label_ethernet, 1, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->screenRecording_label_ethernet, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->screenRecording_label_ethernet, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->screenRecording_label_ethernet, 6, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->screenRecording_label_ethernet, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->screenRecording_label_ethernet, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->screenRecording_label_ethernet, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->screenRecording_label_ethernet, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes screenRecording_label_headphones
	ui->screenRecording_label_headphones = lv_label_create(ui->screenRecording_cont_top_bar);
	lv_label_set_text(ui->screenRecording_label_headphones, "");
	lv_label_set_long_mode(ui->screenRecording_label_headphones, LV_LABEL_LONG_WRAP);
	lv_obj_set_pos(ui->screenRecording_label_headphones, 178, 6);
	lv_obj_set_size(ui->screenRecording_label_headphones, 30, 28);

	//Write style for screenRecording_label_headphones, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->screenRecording_label_headphones, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->screenRecording_label_headphones, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->screenRecording_label_headphones, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->screenRecording_label_headphones, &lv_font_FontAwesome5ProRegular_400_16, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->screenRecording_label_headphones, 5, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_line_space(ui->screenRecording_label_headphones, 1, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->screenRecording_label_headphones, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->screenRecording_label_headphones, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->screenRecording_label_headphones, 6, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->screenRecording_label_headphones, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->screenRecording_label_headphones, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->screenRecording_label_headphones, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->screenRecording_label_headphones, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes screenRecording_btn_current_time
	ui->screenRecording_btn_current_time = lv_btn_create(ui->screenRecording_cont_top_bar);
	ui->screenRecording_btn_current_time_label = lv_label_create(ui->screenRecording_btn_current_time);
	lv_label_set_text(ui->screenRecording_btn_current_time_label, "00:00");
	lv_label_set_long_mode(ui->screenRecording_btn_current_time_label, LV_LABEL_LONG_WRAP);
	lv_obj_align(ui->screenRecording_btn_current_time_label, LV_ALIGN_CENTER, 0, 0);
	lv_obj_set_style_pad_all(ui->screenRecording_btn_current_time, 0, LV_STATE_DEFAULT);
	lv_obj_set_pos(ui->screenRecording_btn_current_time, 7, 6);
	lv_obj_set_size(ui->screenRecording_btn_current_time, 60, 28);

	//Write style for screenRecording_btn_current_time, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_bg_opa(ui->screenRecording_btn_current_time, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_width(ui->screenRecording_btn_current_time, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->screenRecording_btn_current_time, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->screenRecording_btn_current_time, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->screenRecording_btn_current_time, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->screenRecording_btn_current_time, &lv_font_montserratMedium_16, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->screenRecording_btn_current_time, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes screenRecording_bar_volume
	ui->screenRecording_bar_volume = lv_bar_create(ui->screenRecording_cont_top_bar);
	lv_obj_set_style_anim_time(ui->screenRecording_bar_volume, 1000, 0);
	lv_bar_set_mode(ui->screenRecording_bar_volume, LV_BAR_MODE_NORMAL);
	lv_bar_set_value(ui->screenRecording_bar_volume, 100, LV_ANIM_OFF);
	lv_obj_set_pos(ui->screenRecording_bar_volume, 207, 25);
	lv_obj_set_size(ui->screenRecording_bar_volume, 28, 3);

	//Write style for screenRecording_bar_volume, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_bg_opa(ui->screenRecording_bar_volume, 60, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui->screenRecording_bar_volume, lv_color_hex(0x2195f6), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->screenRecording_bar_volume, 10, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->screenRecording_bar_volume, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write style for screenRecording_bar_volume, Part: LV_PART_INDICATOR, State: LV_STATE_DEFAULT.
	lv_obj_set_style_bg_opa(ui->screenRecording_bar_volume, 255, LV_PART_INDICATOR|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui->screenRecording_bar_volume, lv_color_hex(0xffffff), LV_PART_INDICATOR|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->screenRecording_bar_volume, 10, LV_PART_INDICATOR|LV_STATE_DEFAULT);

	//Write codes screenRecording_label_volume
	ui->screenRecording_label_volume = lv_label_create(ui->screenRecording_cont_top_bar);
	lv_label_set_text(ui->screenRecording_label_volume, "100");
	lv_label_set_long_mode(ui->screenRecording_label_volume, LV_LABEL_LONG_WRAP);
	lv_obj_set_pos(ui->screenRecording_label_volume, 206, 9);
	lv_obj_set_size(ui->screenRecording_label_volume, 30, 11);

	//Write style for screenRecording_label_volume, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->screenRecording_label_volume, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->screenRecording_label_volume, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->screenRecording_label_volume, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->screenRecording_label_volume, &lv_font_montserratMedium_12, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->screenRecording_label_volume, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_line_space(ui->screenRecording_label_volume, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->screenRecording_label_volume, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->screenRecording_label_volume, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->screenRecording_label_volume, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->screenRecording_label_volume, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->screenRecording_label_volume, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->screenRecording_label_volume, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->screenRecording_label_volume, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes screenRecording_label_usb
	ui->screenRecording_label_usb = lv_label_create(ui->screenRecording_cont_top_bar);
	lv_label_set_text(ui->screenRecording_label_usb, "");
	lv_label_set_long_mode(ui->screenRecording_label_usb, LV_LABEL_LONG_WRAP);
	lv_obj_set_pos(ui->screenRecording_label_usb, 129, 6);
	lv_obj_set_size(ui->screenRecording_label_usb, 28, 28);

	//Write style for screenRecording_label_usb, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->screenRecording_label_usb, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->screenRecording_label_usb, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->screenRecording_label_usb, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->screenRecording_label_usb, &lv_font_FontAwesome5_16, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->screenRecording_label_usb, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_line_space(ui->screenRecording_label_usb, 1, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->screenRecording_label_usb, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->screenRecording_label_usb, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->screenRecording_label_usb, 6, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->screenRecording_label_usb, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->screenRecording_label_usb, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->screenRecording_label_usb, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->screenRecording_label_usb, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes screenRecording_label_sd_card
	ui->screenRecording_label_sd_card = lv_label_create(ui->screenRecording_cont_top_bar);
	lv_label_set_text(ui->screenRecording_label_sd_card, "");
	lv_label_set_long_mode(ui->screenRecording_label_sd_card, LV_LABEL_LONG_WRAP);
	lv_obj_set_pos(ui->screenRecording_label_sd_card, 157, 6);
	lv_obj_set_size(ui->screenRecording_label_sd_card, 20, 28);

	//Write style for screenRecording_label_sd_card, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->screenRecording_label_sd_card, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->screenRecording_label_sd_card, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->screenRecording_label_sd_card, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->screenRecording_label_sd_card, &lv_font_FontAwesome5ProSolid_900_16, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->screenRecording_label_sd_card, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_line_space(ui->screenRecording_label_sd_card, 1, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->screenRecording_label_sd_card, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->screenRecording_label_sd_card, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->screenRecording_label_sd_card, 6, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->screenRecording_label_sd_card, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->screenRecording_label_sd_card, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->screenRecording_label_sd_card, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->screenRecording_label_sd_card, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes screenRecording_tileview
	ui->screenRecording_tileview = lv_tileview_create(ui->screenRecording);
	ui->screenRecording_tileview_tile_files = lv_tileview_add_tile(ui->screenRecording_tileview, 0, 0, LV_DIR_RIGHT);
	ui->screenRecording_tileview_tile_channels = lv_tileview_add_tile(ui->screenRecording_tileview, 1, 0, LV_DIR_LEFT);
	lv_obj_set_pos(ui->screenRecording_tileview, 0, 45);
	lv_obj_set_size(ui->screenRecording_tileview, 240, 195);
	lv_obj_set_scrollbar_mode(ui->screenRecording_tileview, LV_SCROLLBAR_MODE_OFF);

	//Write style for screenRecording_tileview, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_bg_opa(ui->screenRecording_tileview, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui->screenRecording_tileview, lv_color_hex(0x101418), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->screenRecording_tileview, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->screenRecording_tileview, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write style for screenRecording_tileview, Part: LV_PART_SCROLLBAR, State: LV_STATE_DEFAULT.
	lv_obj_set_style_bg_opa(ui->screenRecording_tileview, 84, LV_PART_SCROLLBAR|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui->screenRecording_tileview, lv_color_hex(0xffffff), LV_PART_SCROLLBAR|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->screenRecording_tileview, 0, LV_PART_SCROLLBAR|LV_STATE_DEFAULT);



	//Write codes screenRecording_cont_disk_storage
	ui->screenRecording_cont_disk_storage = lv_obj_create(ui->screenRecording_tileview_tile_files);
	lv_obj_set_pos(ui->screenRecording_cont_disk_storage, 0, 170);
	lv_obj_set_size(ui->screenRecording_cont_disk_storage, 240, 25);
	lv_obj_set_scrollbar_mode(ui->screenRecording_cont_disk_storage, LV_SCROLLBAR_MODE_OFF);

	//Write style for screenRecording_cont_disk_storage, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->screenRecording_cont_disk_storage, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_opa(ui->screenRecording_cont_disk_storage, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_color(ui->screenRecording_cont_disk_storage, lv_color_hex(0xD200AC), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_side(ui->screenRecording_cont_disk_storage, LV_BORDER_SIDE_TOP, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->screenRecording_cont_disk_storage, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->screenRecording_cont_disk_storage, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui->screenRecording_cont_disk_storage, lv_color_hex(0x292831), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->screenRecording_cont_disk_storage, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->screenRecording_cont_disk_storage, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->screenRecording_cont_disk_storage, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->screenRecording_cont_disk_storage, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->screenRecording_cont_disk_storage, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes screenRecording_bar_disk_storage
	ui->screenRecording_bar_disk_storage = lv_bar_create(ui->screenRecording_cont_disk_storage);
	lv_obj_set_style_anim_time(ui->screenRecording_bar_disk_storage, 1000, 0);
	lv_bar_set_mode(ui->screenRecording_bar_disk_storage, LV_BAR_MODE_NORMAL);
	lv_bar_set_value(ui->screenRecording_bar_disk_storage, 0, LV_ANIM_OFF);
	lv_obj_set_pos(ui->screenRecording_bar_disk_storage, 40, 8);
	lv_obj_set_size(ui->screenRecording_bar_disk_storage, 90, 7);

	//Write style for screenRecording_bar_disk_storage, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_bg_opa(ui->screenRecording_bar_disk_storage, 60, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui->screenRecording_bar_disk_storage, lv_color_hex(0x2195f6), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->screenRecording_bar_disk_storage, 10, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->screenRecording_bar_disk_storage, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write style for screenRecording_bar_disk_storage, Part: LV_PART_INDICATOR, State: LV_STATE_DEFAULT.
	lv_obj_set_style_bg_opa(ui->screenRecording_bar_disk_storage, 255, LV_PART_INDICATOR|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui->screenRecording_bar_disk_storage, lv_color_hex(0xffffff), LV_PART_INDICATOR|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->screenRecording_bar_disk_storage, 10, LV_PART_INDICATOR|LV_STATE_DEFAULT);

	//Write codes screenRecording_label_121
	ui->screenRecording_label_121 = lv_label_create(ui->screenRecording_cont_disk_storage);
	lv_label_set_text(ui->screenRecording_label_121, "");
	lv_label_set_long_mode(ui->screenRecording_label_121, LV_LABEL_LONG_WRAP);
	lv_obj_set_pos(ui->screenRecording_label_121, 4, 4);
	lv_obj_set_size(ui->screenRecording_label_121, 29, 14);

	//Write style for screenRecording_label_121, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->screenRecording_label_121, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->screenRecording_label_121, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->screenRecording_label_121, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->screenRecording_label_121, &lv_font_FontAwesome5_16, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->screenRecording_label_121, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_line_space(ui->screenRecording_label_121, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->screenRecording_label_121, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->screenRecording_label_121, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->screenRecording_label_121, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->screenRecording_label_121, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->screenRecording_label_121, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->screenRecording_label_121, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->screenRecording_label_121, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes screenRecording_label_disk_storage
	ui->screenRecording_label_disk_storage = lv_label_create(ui->screenRecording_cont_disk_storage);
	lv_label_set_text(ui->screenRecording_label_disk_storage, "0.0 / 0.0 GB");
	lv_label_set_long_mode(ui->screenRecording_label_disk_storage, LV_LABEL_LONG_WRAP);
	lv_obj_set_pos(ui->screenRecording_label_disk_storage, 134, 5);
	lv_obj_set_size(ui->screenRecording_label_disk_storage, 99, 14);

	//Write style for screenRecording_label_disk_storage, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->screenRecording_label_disk_storage, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->screenRecording_label_disk_storage, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->screenRecording_label_disk_storage, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->screenRecording_label_disk_storage, &lv_font_montserratMedium_14, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->screenRecording_label_disk_storage, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_line_space(ui->screenRecording_label_disk_storage, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->screenRecording_label_disk_storage, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->screenRecording_label_disk_storage, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->screenRecording_label_disk_storage, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->screenRecording_label_disk_storage, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->screenRecording_label_disk_storage, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->screenRecording_label_disk_storage, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->screenRecording_label_disk_storage, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes screenRecording_list_1
	ui->screenRecording_list_1 = lv_list_create(ui->screenRecording_tileview_tile_files);
	ui->screenRecording_list_1_item0 = lv_list_add_btn(ui->screenRecording_list_1, LV_SYMBOL_DIRECTORY, "settings");
	ui->screenRecording_list_1_item1 = lv_list_add_btn(ui->screenRecording_list_1, LV_SYMBOL_FILE, "231019_110608_32_FFFFFFFF.wav");
	ui->screenRecording_list_1_item2 = lv_list_add_btn(ui->screenRecording_list_1, LV_SYMBOL_FILE, "231019_115502_32_FFFFFFFF.wav");
	ui->screenRecording_list_1_item3 = lv_list_add_btn(ui->screenRecording_list_1, LV_SYMBOL_FILE, "231020_080728_16_FFFF0000.wav");
	ui->screenRecording_list_1_item4 = lv_list_add_btn(ui->screenRecording_list_1, LV_SYMBOL_FILE, "231020_1001020_16_FFFF0000.wav");
	lv_obj_set_pos(ui->screenRecording_list_1, -2, 2);
	lv_obj_set_size(ui->screenRecording_list_1, 240, 161);
	lv_obj_set_scrollbar_mode(ui->screenRecording_list_1, LV_SCROLLBAR_MODE_OFF);
	lv_obj_add_flag(ui->screenRecording_list_1, LV_OBJ_FLAG_CLICKABLE);

	//Write style state: LV_STATE_DEFAULT for &style_screenRecording_list_1_main_main_default
	static lv_style_t style_screenRecording_list_1_main_main_default;
	ui_init_style(&style_screenRecording_list_1_main_main_default);
	
	lv_style_set_pad_top(&style_screenRecording_list_1_main_main_default, 0);
	lv_style_set_pad_left(&style_screenRecording_list_1_main_main_default, 5);
	lv_style_set_pad_right(&style_screenRecording_list_1_main_main_default, 5);
	lv_style_set_pad_bottom(&style_screenRecording_list_1_main_main_default, 5);
	lv_style_set_bg_opa(&style_screenRecording_list_1_main_main_default, 255);
	lv_style_set_bg_color(&style_screenRecording_list_1_main_main_default, lv_color_hex(0x101418));
	lv_style_set_border_width(&style_screenRecording_list_1_main_main_default, 0);
	lv_style_set_radius(&style_screenRecording_list_1_main_main_default, 3);
	lv_style_set_shadow_width(&style_screenRecording_list_1_main_main_default, 0);
	lv_obj_add_style(ui->screenRecording_list_1, &style_screenRecording_list_1_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write style state: LV_STATE_DEFAULT for &style_screenRecording_list_1_main_scrollbar_default
	static lv_style_t style_screenRecording_list_1_main_scrollbar_default;
	ui_init_style(&style_screenRecording_list_1_main_scrollbar_default);
	
	lv_style_set_radius(&style_screenRecording_list_1_main_scrollbar_default, 3);
	lv_style_set_bg_opa(&style_screenRecording_list_1_main_scrollbar_default, 255);
	lv_style_set_bg_color(&style_screenRecording_list_1_main_scrollbar_default, lv_color_hex(0xffffff));
	lv_obj_add_style(ui->screenRecording_list_1, &style_screenRecording_list_1_main_scrollbar_default, LV_PART_SCROLLBAR|LV_STATE_DEFAULT);

	//Write style state: LV_STATE_DEFAULT for &style_screenRecording_list_1_extra_btns_main_default
	static lv_style_t style_screenRecording_list_1_extra_btns_main_default;
	ui_init_style(&style_screenRecording_list_1_extra_btns_main_default);
	
	lv_style_set_pad_top(&style_screenRecording_list_1_extra_btns_main_default, 5);
	lv_style_set_pad_left(&style_screenRecording_list_1_extra_btns_main_default, 5);
	lv_style_set_pad_right(&style_screenRecording_list_1_extra_btns_main_default, 0);
	lv_style_set_pad_bottom(&style_screenRecording_list_1_extra_btns_main_default, 5);
	lv_style_set_border_width(&style_screenRecording_list_1_extra_btns_main_default, 2);
	lv_style_set_border_opa(&style_screenRecording_list_1_extra_btns_main_default, 255);
	lv_style_set_border_color(&style_screenRecording_list_1_extra_btns_main_default, lv_color_hex(0x101418));
	lv_style_set_border_side(&style_screenRecording_list_1_extra_btns_main_default, LV_BORDER_SIDE_BOTTOM);
	lv_style_set_text_color(&style_screenRecording_list_1_extra_btns_main_default, lv_color_hex(0xffffff));
	lv_style_set_text_font(&style_screenRecording_list_1_extra_btns_main_default, &lv_font_montserratMedium_13);
	lv_style_set_radius(&style_screenRecording_list_1_extra_btns_main_default, 1);
	lv_style_set_bg_opa(&style_screenRecording_list_1_extra_btns_main_default, 255);
	lv_style_set_bg_color(&style_screenRecording_list_1_extra_btns_main_default, lv_color_hex(0x292831));
	lv_obj_add_style(ui->screenRecording_list_1_item4, &style_screenRecording_list_1_extra_btns_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_add_style(ui->screenRecording_list_1_item3, &style_screenRecording_list_1_extra_btns_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_add_style(ui->screenRecording_list_1_item2, &style_screenRecording_list_1_extra_btns_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_add_style(ui->screenRecording_list_1_item1, &style_screenRecording_list_1_extra_btns_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_add_style(ui->screenRecording_list_1_item0, &style_screenRecording_list_1_extra_btns_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write style state: LV_STATE_DEFAULT for &style_screenRecording_list_1_extra_texts_main_default
	static lv_style_t style_screenRecording_list_1_extra_texts_main_default;
	ui_init_style(&style_screenRecording_list_1_extra_texts_main_default);
	
	lv_style_set_pad_top(&style_screenRecording_list_1_extra_texts_main_default, 5);
	lv_style_set_pad_left(&style_screenRecording_list_1_extra_texts_main_default, 0);
	lv_style_set_pad_right(&style_screenRecording_list_1_extra_texts_main_default, 0);
	lv_style_set_pad_bottom(&style_screenRecording_list_1_extra_texts_main_default, 5);
	lv_style_set_border_width(&style_screenRecording_list_1_extra_texts_main_default, 0);
	lv_style_set_text_color(&style_screenRecording_list_1_extra_texts_main_default, lv_color_hex(0x0D3055));
	lv_style_set_text_font(&style_screenRecording_list_1_extra_texts_main_default, &lv_font_FontAwesome5ProRegular_400_11);
	lv_style_set_radius(&style_screenRecording_list_1_extra_texts_main_default, 3);
	lv_style_set_bg_opa(&style_screenRecording_list_1_extra_texts_main_default, 255);
	lv_style_set_bg_color(&style_screenRecording_list_1_extra_texts_main_default, lv_color_hex(0xffffff));



	//Write codes screenRecording_cont_10
	ui->screenRecording_cont_10 = lv_obj_create(ui->screenRecording_tileview_tile_channels);
	lv_obj_set_pos(ui->screenRecording_cont_10, 0, 0);
	lv_obj_set_size(ui->screenRecording_cont_10, 240, 1602);
	lv_obj_set_scrollbar_mode(ui->screenRecording_cont_10, LV_SCROLLBAR_MODE_OFF);

	//Write style for screenRecording_cont_10, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->screenRecording_cont_10, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->screenRecording_cont_10, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->screenRecording_cont_10, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->screenRecording_cont_10, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->screenRecording_cont_10, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->screenRecording_cont_10, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->screenRecording_cont_10, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->screenRecording_cont_10, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes screenRecording_cont_ch01
	ui->screenRecording_cont_ch01 = lv_obj_create(ui->screenRecording_cont_10);
	lv_obj_set_pos(ui->screenRecording_cont_ch01, 13, 5);
	lv_obj_set_size(ui->screenRecording_cont_ch01, 210, 46);
	lv_obj_set_scrollbar_mode(ui->screenRecording_cont_ch01, LV_SCROLLBAR_MODE_OFF);

	//Write style for screenRecording_cont_ch01, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->screenRecording_cont_ch01, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_opa(ui->screenRecording_cont_ch01, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_color(ui->screenRecording_cont_ch01, lv_color_hex(0x2195f6), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_side(ui->screenRecording_cont_ch01, LV_BORDER_SIDE_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->screenRecording_cont_ch01, 4, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->screenRecording_cont_ch01, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui->screenRecording_cont_ch01, lv_color_hex(0x292831), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->screenRecording_cont_ch01, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->screenRecording_cont_ch01, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->screenRecording_cont_ch01, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->screenRecording_cont_ch01, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->screenRecording_cont_ch01, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes screenRecording_label_ch_01
	ui->screenRecording_label_ch_01 = lv_label_create(ui->screenRecording_cont_ch01);
	lv_label_set_text(ui->screenRecording_label_ch_01, "CH: 31");
	lv_label_set_long_mode(ui->screenRecording_label_ch_01, LV_LABEL_LONG_WRAP);
	lv_obj_set_pos(ui->screenRecording_label_ch_01, 137, 5);
	lv_obj_set_size(ui->screenRecording_label_ch_01, 66, 32);

	//Write style for screenRecording_label_ch_01, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->screenRecording_label_ch_01, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->screenRecording_label_ch_01, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->screenRecording_label_ch_01, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->screenRecording_label_ch_01, &lv_font_MontserratRegular_20, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->screenRecording_label_ch_01, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_line_space(ui->screenRecording_label_ch_01, 1, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->screenRecording_label_ch_01, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->screenRecording_label_ch_01, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->screenRecording_label_ch_01, 7, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->screenRecording_label_ch_01, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->screenRecording_label_ch_01, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->screenRecording_label_ch_01, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->screenRecording_label_ch_01, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes screenRecording_label_spk_01
	ui->screenRecording_label_spk_01 = lv_label_create(ui->screenRecording_cont_ch01);
	lv_label_set_text(ui->screenRecording_label_spk_01, "");
	lv_label_set_long_mode(ui->screenRecording_label_spk_01, LV_LABEL_LONG_WRAP);
	lv_obj_set_pos(ui->screenRecording_label_spk_01, 100, 4);
	lv_obj_set_size(ui->screenRecording_label_spk_01, 25, 32);

	//Write style for screenRecording_label_spk_01, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->screenRecording_label_spk_01, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->screenRecording_label_spk_01, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->screenRecording_label_spk_01, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->screenRecording_label_spk_01, &lv_font_FontAwesome5ProRegular_400_22, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->screenRecording_label_spk_01, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_line_space(ui->screenRecording_label_spk_01, 1, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->screenRecording_label_spk_01, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->screenRecording_label_spk_01, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->screenRecording_label_spk_01, 6, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->screenRecording_label_spk_01, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->screenRecording_label_spk_01, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->screenRecording_label_spk_01, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->screenRecording_label_spk_01, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes screenRecording_sw_01
	ui->screenRecording_sw_01 = lv_switch_create(ui->screenRecording_cont_ch01);
	lv_obj_set_pos(ui->screenRecording_sw_01, 46, 12);
	lv_obj_set_size(ui->screenRecording_sw_01, 40, 20);

	//Write style for screenRecording_sw_01, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_bg_opa(ui->screenRecording_sw_01, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui->screenRecording_sw_01, lv_color_hex(0x41485a), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_width(ui->screenRecording_sw_01, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->screenRecording_sw_01, 10, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->screenRecording_sw_01, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write style for screenRecording_sw_01, Part: LV_PART_INDICATOR, State: LV_STATE_CHECKED.
	lv_obj_set_style_bg_opa(ui->screenRecording_sw_01, 255, LV_PART_INDICATOR|LV_STATE_CHECKED);
	lv_obj_set_style_bg_color(ui->screenRecording_sw_01, lv_color_hex(0x2195f6), LV_PART_INDICATOR|LV_STATE_CHECKED);
	lv_obj_set_style_border_width(ui->screenRecording_sw_01, 0, LV_PART_INDICATOR|LV_STATE_CHECKED);

	//Write style for screenRecording_sw_01, Part: LV_PART_KNOB, State: LV_STATE_DEFAULT.
	lv_obj_set_style_bg_opa(ui->screenRecording_sw_01, 255, LV_PART_KNOB|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui->screenRecording_sw_01, lv_color_hex(0x292831), LV_PART_KNOB|LV_STATE_DEFAULT);
	lv_obj_set_style_border_width(ui->screenRecording_sw_01, 0, LV_PART_KNOB|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->screenRecording_sw_01, 10, LV_PART_KNOB|LV_STATE_DEFAULT);

	//Write codes screenRecording_label_13
	ui->screenRecording_label_13 = lv_label_create(ui->screenRecording_cont_ch01);
	lv_label_set_text(ui->screenRecording_label_13, "01");
	lv_label_set_long_mode(ui->screenRecording_label_13, LV_LABEL_LONG_WRAP);
	lv_obj_set_pos(ui->screenRecording_label_13, 4, 5);
	lv_obj_set_size(ui->screenRecording_label_13, 35, 32);

	//Write style for screenRecording_label_13, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->screenRecording_label_13, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->screenRecording_label_13, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->screenRecording_label_13, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->screenRecording_label_13, &lv_font_montserratMedium_24, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->screenRecording_label_13, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_line_space(ui->screenRecording_label_13, 1, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->screenRecording_label_13, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->screenRecording_label_13, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->screenRecording_label_13, 5, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->screenRecording_label_13, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->screenRecording_label_13, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->screenRecording_label_13, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->screenRecording_label_13, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes screenRecording_cont_ch02
	ui->screenRecording_cont_ch02 = lv_obj_create(ui->screenRecording_cont_10);
	lv_obj_set_pos(ui->screenRecording_cont_ch02, 13, 55);
	lv_obj_set_size(ui->screenRecording_cont_ch02, 210, 46);
	lv_obj_set_scrollbar_mode(ui->screenRecording_cont_ch02, LV_SCROLLBAR_MODE_OFF);

	//Write style for screenRecording_cont_ch02, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->screenRecording_cont_ch02, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_opa(ui->screenRecording_cont_ch02, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_color(ui->screenRecording_cont_ch02, lv_color_hex(0x2195f6), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_side(ui->screenRecording_cont_ch02, LV_BORDER_SIDE_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->screenRecording_cont_ch02, 4, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->screenRecording_cont_ch02, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui->screenRecording_cont_ch02, lv_color_hex(0x292831), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->screenRecording_cont_ch02, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->screenRecording_cont_ch02, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->screenRecording_cont_ch02, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->screenRecording_cont_ch02, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->screenRecording_cont_ch02, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes screenRecording_label_ch_02
	ui->screenRecording_label_ch_02 = lv_label_create(ui->screenRecording_cont_ch02);
	lv_label_set_text(ui->screenRecording_label_ch_02, "CH: 31");
	lv_label_set_long_mode(ui->screenRecording_label_ch_02, LV_LABEL_LONG_WRAP);
	lv_obj_set_pos(ui->screenRecording_label_ch_02, 137, 5);
	lv_obj_set_size(ui->screenRecording_label_ch_02, 66, 32);

	//Write style for screenRecording_label_ch_02, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->screenRecording_label_ch_02, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->screenRecording_label_ch_02, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->screenRecording_label_ch_02, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->screenRecording_label_ch_02, &lv_font_MontserratRegular_20, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->screenRecording_label_ch_02, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_line_space(ui->screenRecording_label_ch_02, 1, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->screenRecording_label_ch_02, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->screenRecording_label_ch_02, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->screenRecording_label_ch_02, 7, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->screenRecording_label_ch_02, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->screenRecording_label_ch_02, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->screenRecording_label_ch_02, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->screenRecording_label_ch_02, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes screenRecording_label_spk_02
	ui->screenRecording_label_spk_02 = lv_label_create(ui->screenRecording_cont_ch02);
	lv_label_set_text(ui->screenRecording_label_spk_02, "");
	lv_label_set_long_mode(ui->screenRecording_label_spk_02, LV_LABEL_LONG_WRAP);
	lv_obj_set_pos(ui->screenRecording_label_spk_02, 100, 4);
	lv_obj_set_size(ui->screenRecording_label_spk_02, 25, 32);

	//Write style for screenRecording_label_spk_02, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->screenRecording_label_spk_02, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->screenRecording_label_spk_02, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->screenRecording_label_spk_02, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->screenRecording_label_spk_02, &lv_font_FontAwesome5ProRegular_400_22, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->screenRecording_label_spk_02, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_line_space(ui->screenRecording_label_spk_02, 1, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->screenRecording_label_spk_02, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->screenRecording_label_spk_02, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->screenRecording_label_spk_02, 6, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->screenRecording_label_spk_02, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->screenRecording_label_spk_02, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->screenRecording_label_spk_02, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->screenRecording_label_spk_02, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes screenRecording_sw_02
	ui->screenRecording_sw_02 = lv_switch_create(ui->screenRecording_cont_ch02);
	lv_obj_set_pos(ui->screenRecording_sw_02, 46, 12);
	lv_obj_set_size(ui->screenRecording_sw_02, 40, 20);

	//Write style for screenRecording_sw_02, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_bg_opa(ui->screenRecording_sw_02, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui->screenRecording_sw_02, lv_color_hex(0x41485a), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_width(ui->screenRecording_sw_02, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->screenRecording_sw_02, 10, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->screenRecording_sw_02, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write style for screenRecording_sw_02, Part: LV_PART_INDICATOR, State: LV_STATE_CHECKED.
	lv_obj_set_style_bg_opa(ui->screenRecording_sw_02, 255, LV_PART_INDICATOR|LV_STATE_CHECKED);
	lv_obj_set_style_bg_color(ui->screenRecording_sw_02, lv_color_hex(0x2195f6), LV_PART_INDICATOR|LV_STATE_CHECKED);
	lv_obj_set_style_border_width(ui->screenRecording_sw_02, 0, LV_PART_INDICATOR|LV_STATE_CHECKED);

	//Write style for screenRecording_sw_02, Part: LV_PART_KNOB, State: LV_STATE_DEFAULT.
	lv_obj_set_style_bg_opa(ui->screenRecording_sw_02, 255, LV_PART_KNOB|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui->screenRecording_sw_02, lv_color_hex(0x292831), LV_PART_KNOB|LV_STATE_DEFAULT);
	lv_obj_set_style_border_width(ui->screenRecording_sw_02, 0, LV_PART_KNOB|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->screenRecording_sw_02, 10, LV_PART_KNOB|LV_STATE_DEFAULT);

	//Write codes screenRecording_label_28
	ui->screenRecording_label_28 = lv_label_create(ui->screenRecording_cont_ch02);
	lv_label_set_text(ui->screenRecording_label_28, "02");
	lv_label_set_long_mode(ui->screenRecording_label_28, LV_LABEL_LONG_WRAP);
	lv_obj_set_pos(ui->screenRecording_label_28, 4, 5);
	lv_obj_set_size(ui->screenRecording_label_28, 35, 32);

	//Write style for screenRecording_label_28, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->screenRecording_label_28, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->screenRecording_label_28, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->screenRecording_label_28, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->screenRecording_label_28, &lv_font_montserratMedium_24, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->screenRecording_label_28, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_line_space(ui->screenRecording_label_28, 1, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->screenRecording_label_28, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->screenRecording_label_28, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->screenRecording_label_28, 5, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->screenRecording_label_28, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->screenRecording_label_28, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->screenRecording_label_28, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->screenRecording_label_28, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes screenRecording_cont_ch03
	ui->screenRecording_cont_ch03 = lv_obj_create(ui->screenRecording_cont_10);
	lv_obj_set_pos(ui->screenRecording_cont_ch03, 13, 105);
	lv_obj_set_size(ui->screenRecording_cont_ch03, 210, 46);
	lv_obj_set_scrollbar_mode(ui->screenRecording_cont_ch03, LV_SCROLLBAR_MODE_OFF);

	//Write style for screenRecording_cont_ch03, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->screenRecording_cont_ch03, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_opa(ui->screenRecording_cont_ch03, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_color(ui->screenRecording_cont_ch03, lv_color_hex(0x2195f6), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_side(ui->screenRecording_cont_ch03, LV_BORDER_SIDE_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->screenRecording_cont_ch03, 4, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->screenRecording_cont_ch03, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui->screenRecording_cont_ch03, lv_color_hex(0x292831), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->screenRecording_cont_ch03, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->screenRecording_cont_ch03, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->screenRecording_cont_ch03, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->screenRecording_cont_ch03, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->screenRecording_cont_ch03, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes screenRecording_label_ch_03
	ui->screenRecording_label_ch_03 = lv_label_create(ui->screenRecording_cont_ch03);
	lv_label_set_text(ui->screenRecording_label_ch_03, "CH: 31");
	lv_label_set_long_mode(ui->screenRecording_label_ch_03, LV_LABEL_LONG_WRAP);
	lv_obj_set_pos(ui->screenRecording_label_ch_03, 137, 5);
	lv_obj_set_size(ui->screenRecording_label_ch_03, 66, 32);

	//Write style for screenRecording_label_ch_03, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->screenRecording_label_ch_03, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->screenRecording_label_ch_03, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->screenRecording_label_ch_03, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->screenRecording_label_ch_03, &lv_font_MontserratRegular_20, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->screenRecording_label_ch_03, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_line_space(ui->screenRecording_label_ch_03, 1, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->screenRecording_label_ch_03, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->screenRecording_label_ch_03, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->screenRecording_label_ch_03, 7, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->screenRecording_label_ch_03, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->screenRecording_label_ch_03, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->screenRecording_label_ch_03, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->screenRecording_label_ch_03, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes screenRecording_label_spk_03
	ui->screenRecording_label_spk_03 = lv_label_create(ui->screenRecording_cont_ch03);
	lv_label_set_text(ui->screenRecording_label_spk_03, "");
	lv_label_set_long_mode(ui->screenRecording_label_spk_03, LV_LABEL_LONG_WRAP);
	lv_obj_set_pos(ui->screenRecording_label_spk_03, 100, 4);
	lv_obj_set_size(ui->screenRecording_label_spk_03, 25, 32);

	//Write style for screenRecording_label_spk_03, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->screenRecording_label_spk_03, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->screenRecording_label_spk_03, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->screenRecording_label_spk_03, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->screenRecording_label_spk_03, &lv_font_FontAwesome5ProRegular_400_22, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->screenRecording_label_spk_03, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_line_space(ui->screenRecording_label_spk_03, 1, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->screenRecording_label_spk_03, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->screenRecording_label_spk_03, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->screenRecording_label_spk_03, 6, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->screenRecording_label_spk_03, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->screenRecording_label_spk_03, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->screenRecording_label_spk_03, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->screenRecording_label_spk_03, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes screenRecording_sw_03
	ui->screenRecording_sw_03 = lv_switch_create(ui->screenRecording_cont_ch03);
	lv_obj_set_pos(ui->screenRecording_sw_03, 46, 12);
	lv_obj_set_size(ui->screenRecording_sw_03, 40, 20);

	//Write style for screenRecording_sw_03, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_bg_opa(ui->screenRecording_sw_03, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui->screenRecording_sw_03, lv_color_hex(0x41485a), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_width(ui->screenRecording_sw_03, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->screenRecording_sw_03, 10, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->screenRecording_sw_03, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write style for screenRecording_sw_03, Part: LV_PART_INDICATOR, State: LV_STATE_CHECKED.
	lv_obj_set_style_bg_opa(ui->screenRecording_sw_03, 255, LV_PART_INDICATOR|LV_STATE_CHECKED);
	lv_obj_set_style_bg_color(ui->screenRecording_sw_03, lv_color_hex(0x2195f6), LV_PART_INDICATOR|LV_STATE_CHECKED);
	lv_obj_set_style_border_width(ui->screenRecording_sw_03, 0, LV_PART_INDICATOR|LV_STATE_CHECKED);

	//Write style for screenRecording_sw_03, Part: LV_PART_KNOB, State: LV_STATE_DEFAULT.
	lv_obj_set_style_bg_opa(ui->screenRecording_sw_03, 255, LV_PART_KNOB|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui->screenRecording_sw_03, lv_color_hex(0x292831), LV_PART_KNOB|LV_STATE_DEFAULT);
	lv_obj_set_style_border_width(ui->screenRecording_sw_03, 0, LV_PART_KNOB|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->screenRecording_sw_03, 10, LV_PART_KNOB|LV_STATE_DEFAULT);

	//Write codes screenRecording_label_31
	ui->screenRecording_label_31 = lv_label_create(ui->screenRecording_cont_ch03);
	lv_label_set_text(ui->screenRecording_label_31, "03");
	lv_label_set_long_mode(ui->screenRecording_label_31, LV_LABEL_LONG_WRAP);
	lv_obj_set_pos(ui->screenRecording_label_31, 4, 5);
	lv_obj_set_size(ui->screenRecording_label_31, 35, 32);

	//Write style for screenRecording_label_31, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->screenRecording_label_31, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->screenRecording_label_31, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->screenRecording_label_31, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->screenRecording_label_31, &lv_font_montserratMedium_24, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->screenRecording_label_31, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_line_space(ui->screenRecording_label_31, 1, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->screenRecording_label_31, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->screenRecording_label_31, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->screenRecording_label_31, 5, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->screenRecording_label_31, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->screenRecording_label_31, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->screenRecording_label_31, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->screenRecording_label_31, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes screenRecording_cont_ch04
	ui->screenRecording_cont_ch04 = lv_obj_create(ui->screenRecording_cont_10);
	lv_obj_set_pos(ui->screenRecording_cont_ch04, 13, 155);
	lv_obj_set_size(ui->screenRecording_cont_ch04, 210, 46);
	lv_obj_set_scrollbar_mode(ui->screenRecording_cont_ch04, LV_SCROLLBAR_MODE_OFF);

	//Write style for screenRecording_cont_ch04, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->screenRecording_cont_ch04, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_opa(ui->screenRecording_cont_ch04, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_color(ui->screenRecording_cont_ch04, lv_color_hex(0x2195f6), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_side(ui->screenRecording_cont_ch04, LV_BORDER_SIDE_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->screenRecording_cont_ch04, 4, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->screenRecording_cont_ch04, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui->screenRecording_cont_ch04, lv_color_hex(0x292831), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->screenRecording_cont_ch04, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->screenRecording_cont_ch04, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->screenRecording_cont_ch04, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->screenRecording_cont_ch04, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->screenRecording_cont_ch04, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes screenRecording_label_ch_04
	ui->screenRecording_label_ch_04 = lv_label_create(ui->screenRecording_cont_ch04);
	lv_label_set_text(ui->screenRecording_label_ch_04, "CH: 31");
	lv_label_set_long_mode(ui->screenRecording_label_ch_04, LV_LABEL_LONG_WRAP);
	lv_obj_set_pos(ui->screenRecording_label_ch_04, 137, 5);
	lv_obj_set_size(ui->screenRecording_label_ch_04, 66, 32);

	//Write style for screenRecording_label_ch_04, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->screenRecording_label_ch_04, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->screenRecording_label_ch_04, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->screenRecording_label_ch_04, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->screenRecording_label_ch_04, &lv_font_MontserratRegular_20, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->screenRecording_label_ch_04, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_line_space(ui->screenRecording_label_ch_04, 1, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->screenRecording_label_ch_04, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->screenRecording_label_ch_04, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->screenRecording_label_ch_04, 7, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->screenRecording_label_ch_04, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->screenRecording_label_ch_04, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->screenRecording_label_ch_04, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->screenRecording_label_ch_04, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes screenRecording_label_spk_04
	ui->screenRecording_label_spk_04 = lv_label_create(ui->screenRecording_cont_ch04);
	lv_label_set_text(ui->screenRecording_label_spk_04, "");
	lv_label_set_long_mode(ui->screenRecording_label_spk_04, LV_LABEL_LONG_WRAP);
	lv_obj_set_pos(ui->screenRecording_label_spk_04, 100, 4);
	lv_obj_set_size(ui->screenRecording_label_spk_04, 25, 32);

	//Write style for screenRecording_label_spk_04, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->screenRecording_label_spk_04, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->screenRecording_label_spk_04, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->screenRecording_label_spk_04, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->screenRecording_label_spk_04, &lv_font_FontAwesome5ProRegular_400_22, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->screenRecording_label_spk_04, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_line_space(ui->screenRecording_label_spk_04, 1, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->screenRecording_label_spk_04, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->screenRecording_label_spk_04, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->screenRecording_label_spk_04, 6, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->screenRecording_label_spk_04, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->screenRecording_label_spk_04, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->screenRecording_label_spk_04, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->screenRecording_label_spk_04, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes screenRecording_sw_04
	ui->screenRecording_sw_04 = lv_switch_create(ui->screenRecording_cont_ch04);
	lv_obj_set_pos(ui->screenRecording_sw_04, 46, 12);
	lv_obj_set_size(ui->screenRecording_sw_04, 40, 20);

	//Write style for screenRecording_sw_04, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_bg_opa(ui->screenRecording_sw_04, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui->screenRecording_sw_04, lv_color_hex(0x41485a), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_width(ui->screenRecording_sw_04, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->screenRecording_sw_04, 10, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->screenRecording_sw_04, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write style for screenRecording_sw_04, Part: LV_PART_INDICATOR, State: LV_STATE_CHECKED.
	lv_obj_set_style_bg_opa(ui->screenRecording_sw_04, 255, LV_PART_INDICATOR|LV_STATE_CHECKED);
	lv_obj_set_style_bg_color(ui->screenRecording_sw_04, lv_color_hex(0x2195f6), LV_PART_INDICATOR|LV_STATE_CHECKED);
	lv_obj_set_style_border_width(ui->screenRecording_sw_04, 0, LV_PART_INDICATOR|LV_STATE_CHECKED);

	//Write style for screenRecording_sw_04, Part: LV_PART_KNOB, State: LV_STATE_DEFAULT.
	lv_obj_set_style_bg_opa(ui->screenRecording_sw_04, 255, LV_PART_KNOB|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui->screenRecording_sw_04, lv_color_hex(0x292831), LV_PART_KNOB|LV_STATE_DEFAULT);
	lv_obj_set_style_border_width(ui->screenRecording_sw_04, 0, LV_PART_KNOB|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->screenRecording_sw_04, 10, LV_PART_KNOB|LV_STATE_DEFAULT);

	//Write codes screenRecording_label_34
	ui->screenRecording_label_34 = lv_label_create(ui->screenRecording_cont_ch04);
	lv_label_set_text(ui->screenRecording_label_34, "04");
	lv_label_set_long_mode(ui->screenRecording_label_34, LV_LABEL_LONG_WRAP);
	lv_obj_set_pos(ui->screenRecording_label_34, 4, 5);
	lv_obj_set_size(ui->screenRecording_label_34, 35, 32);

	//Write style for screenRecording_label_34, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->screenRecording_label_34, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->screenRecording_label_34, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->screenRecording_label_34, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->screenRecording_label_34, &lv_font_montserratMedium_24, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->screenRecording_label_34, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_line_space(ui->screenRecording_label_34, 1, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->screenRecording_label_34, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->screenRecording_label_34, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->screenRecording_label_34, 5, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->screenRecording_label_34, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->screenRecording_label_34, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->screenRecording_label_34, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->screenRecording_label_34, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes screenRecording_cont_ch05
	ui->screenRecording_cont_ch05 = lv_obj_create(ui->screenRecording_cont_10);
	lv_obj_set_pos(ui->screenRecording_cont_ch05, 13, 205);
	lv_obj_set_size(ui->screenRecording_cont_ch05, 210, 46);
	lv_obj_set_scrollbar_mode(ui->screenRecording_cont_ch05, LV_SCROLLBAR_MODE_OFF);

	//Write style for screenRecording_cont_ch05, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->screenRecording_cont_ch05, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_opa(ui->screenRecording_cont_ch05, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_color(ui->screenRecording_cont_ch05, lv_color_hex(0x2195f6), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_side(ui->screenRecording_cont_ch05, LV_BORDER_SIDE_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->screenRecording_cont_ch05, 4, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->screenRecording_cont_ch05, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui->screenRecording_cont_ch05, lv_color_hex(0x292831), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->screenRecording_cont_ch05, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->screenRecording_cont_ch05, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->screenRecording_cont_ch05, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->screenRecording_cont_ch05, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->screenRecording_cont_ch05, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes screenRecording_label_ch_05
	ui->screenRecording_label_ch_05 = lv_label_create(ui->screenRecording_cont_ch05);
	lv_label_set_text(ui->screenRecording_label_ch_05, "CH: 31");
	lv_label_set_long_mode(ui->screenRecording_label_ch_05, LV_LABEL_LONG_WRAP);
	lv_obj_set_pos(ui->screenRecording_label_ch_05, 137, 5);
	lv_obj_set_size(ui->screenRecording_label_ch_05, 66, 32);

	//Write style for screenRecording_label_ch_05, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->screenRecording_label_ch_05, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->screenRecording_label_ch_05, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->screenRecording_label_ch_05, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->screenRecording_label_ch_05, &lv_font_MontserratRegular_20, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->screenRecording_label_ch_05, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_line_space(ui->screenRecording_label_ch_05, 1, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->screenRecording_label_ch_05, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->screenRecording_label_ch_05, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->screenRecording_label_ch_05, 7, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->screenRecording_label_ch_05, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->screenRecording_label_ch_05, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->screenRecording_label_ch_05, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->screenRecording_label_ch_05, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes screenRecording_label_spk_05
	ui->screenRecording_label_spk_05 = lv_label_create(ui->screenRecording_cont_ch05);
	lv_label_set_text(ui->screenRecording_label_spk_05, "");
	lv_label_set_long_mode(ui->screenRecording_label_spk_05, LV_LABEL_LONG_WRAP);
	lv_obj_set_pos(ui->screenRecording_label_spk_05, 100, 4);
	lv_obj_set_size(ui->screenRecording_label_spk_05, 25, 32);

	//Write style for screenRecording_label_spk_05, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->screenRecording_label_spk_05, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->screenRecording_label_spk_05, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->screenRecording_label_spk_05, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->screenRecording_label_spk_05, &lv_font_FontAwesome5ProRegular_400_22, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->screenRecording_label_spk_05, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_line_space(ui->screenRecording_label_spk_05, 1, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->screenRecording_label_spk_05, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->screenRecording_label_spk_05, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->screenRecording_label_spk_05, 6, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->screenRecording_label_spk_05, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->screenRecording_label_spk_05, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->screenRecording_label_spk_05, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->screenRecording_label_spk_05, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes screenRecording_sw_05
	ui->screenRecording_sw_05 = lv_switch_create(ui->screenRecording_cont_ch05);
	lv_obj_set_pos(ui->screenRecording_sw_05, 46, 12);
	lv_obj_set_size(ui->screenRecording_sw_05, 40, 20);

	//Write style for screenRecording_sw_05, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_bg_opa(ui->screenRecording_sw_05, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui->screenRecording_sw_05, lv_color_hex(0x41485a), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_width(ui->screenRecording_sw_05, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->screenRecording_sw_05, 10, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->screenRecording_sw_05, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write style for screenRecording_sw_05, Part: LV_PART_INDICATOR, State: LV_STATE_CHECKED.
	lv_obj_set_style_bg_opa(ui->screenRecording_sw_05, 255, LV_PART_INDICATOR|LV_STATE_CHECKED);
	lv_obj_set_style_bg_color(ui->screenRecording_sw_05, lv_color_hex(0x2195f6), LV_PART_INDICATOR|LV_STATE_CHECKED);
	lv_obj_set_style_border_width(ui->screenRecording_sw_05, 0, LV_PART_INDICATOR|LV_STATE_CHECKED);

	//Write style for screenRecording_sw_05, Part: LV_PART_KNOB, State: LV_STATE_DEFAULT.
	lv_obj_set_style_bg_opa(ui->screenRecording_sw_05, 255, LV_PART_KNOB|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui->screenRecording_sw_05, lv_color_hex(0x292831), LV_PART_KNOB|LV_STATE_DEFAULT);
	lv_obj_set_style_border_width(ui->screenRecording_sw_05, 0, LV_PART_KNOB|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->screenRecording_sw_05, 10, LV_PART_KNOB|LV_STATE_DEFAULT);

	//Write codes screenRecording_label_37
	ui->screenRecording_label_37 = lv_label_create(ui->screenRecording_cont_ch05);
	lv_label_set_text(ui->screenRecording_label_37, "05");
	lv_label_set_long_mode(ui->screenRecording_label_37, LV_LABEL_LONG_WRAP);
	lv_obj_set_pos(ui->screenRecording_label_37, 4, 5);
	lv_obj_set_size(ui->screenRecording_label_37, 35, 32);

	//Write style for screenRecording_label_37, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->screenRecording_label_37, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->screenRecording_label_37, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->screenRecording_label_37, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->screenRecording_label_37, &lv_font_montserratMedium_24, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->screenRecording_label_37, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_line_space(ui->screenRecording_label_37, 1, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->screenRecording_label_37, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->screenRecording_label_37, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->screenRecording_label_37, 5, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->screenRecording_label_37, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->screenRecording_label_37, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->screenRecording_label_37, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->screenRecording_label_37, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes screenRecording_cont_ch06
	ui->screenRecording_cont_ch06 = lv_obj_create(ui->screenRecording_cont_10);
	lv_obj_set_pos(ui->screenRecording_cont_ch06, 13, 255);
	lv_obj_set_size(ui->screenRecording_cont_ch06, 210, 46);
	lv_obj_set_scrollbar_mode(ui->screenRecording_cont_ch06, LV_SCROLLBAR_MODE_OFF);

	//Write style for screenRecording_cont_ch06, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->screenRecording_cont_ch06, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_opa(ui->screenRecording_cont_ch06, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_color(ui->screenRecording_cont_ch06, lv_color_hex(0x2195f6), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_side(ui->screenRecording_cont_ch06, LV_BORDER_SIDE_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->screenRecording_cont_ch06, 4, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->screenRecording_cont_ch06, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui->screenRecording_cont_ch06, lv_color_hex(0x292831), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->screenRecording_cont_ch06, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->screenRecording_cont_ch06, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->screenRecording_cont_ch06, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->screenRecording_cont_ch06, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->screenRecording_cont_ch06, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes screenRecording_label_ch_06
	ui->screenRecording_label_ch_06 = lv_label_create(ui->screenRecording_cont_ch06);
	lv_label_set_text(ui->screenRecording_label_ch_06, "CH: 31");
	lv_label_set_long_mode(ui->screenRecording_label_ch_06, LV_LABEL_LONG_WRAP);
	lv_obj_set_pos(ui->screenRecording_label_ch_06, 137, 5);
	lv_obj_set_size(ui->screenRecording_label_ch_06, 66, 32);

	//Write style for screenRecording_label_ch_06, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->screenRecording_label_ch_06, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->screenRecording_label_ch_06, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->screenRecording_label_ch_06, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->screenRecording_label_ch_06, &lv_font_MontserratRegular_20, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->screenRecording_label_ch_06, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_line_space(ui->screenRecording_label_ch_06, 1, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->screenRecording_label_ch_06, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->screenRecording_label_ch_06, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->screenRecording_label_ch_06, 7, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->screenRecording_label_ch_06, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->screenRecording_label_ch_06, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->screenRecording_label_ch_06, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->screenRecording_label_ch_06, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes screenRecording_label_spk_06
	ui->screenRecording_label_spk_06 = lv_label_create(ui->screenRecording_cont_ch06);
	lv_label_set_text(ui->screenRecording_label_spk_06, "");
	lv_label_set_long_mode(ui->screenRecording_label_spk_06, LV_LABEL_LONG_WRAP);
	lv_obj_set_pos(ui->screenRecording_label_spk_06, 100, 4);
	lv_obj_set_size(ui->screenRecording_label_spk_06, 25, 32);

	//Write style for screenRecording_label_spk_06, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->screenRecording_label_spk_06, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->screenRecording_label_spk_06, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->screenRecording_label_spk_06, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->screenRecording_label_spk_06, &lv_font_FontAwesome5ProRegular_400_22, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->screenRecording_label_spk_06, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_line_space(ui->screenRecording_label_spk_06, 1, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->screenRecording_label_spk_06, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->screenRecording_label_spk_06, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->screenRecording_label_spk_06, 6, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->screenRecording_label_spk_06, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->screenRecording_label_spk_06, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->screenRecording_label_spk_06, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->screenRecording_label_spk_06, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes screenRecording_sw_06
	ui->screenRecording_sw_06 = lv_switch_create(ui->screenRecording_cont_ch06);
	lv_obj_set_pos(ui->screenRecording_sw_06, 46, 12);
	lv_obj_set_size(ui->screenRecording_sw_06, 40, 20);

	//Write style for screenRecording_sw_06, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_bg_opa(ui->screenRecording_sw_06, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui->screenRecording_sw_06, lv_color_hex(0x41485a), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_width(ui->screenRecording_sw_06, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->screenRecording_sw_06, 10, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->screenRecording_sw_06, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write style for screenRecording_sw_06, Part: LV_PART_INDICATOR, State: LV_STATE_CHECKED.
	lv_obj_set_style_bg_opa(ui->screenRecording_sw_06, 255, LV_PART_INDICATOR|LV_STATE_CHECKED);
	lv_obj_set_style_bg_color(ui->screenRecording_sw_06, lv_color_hex(0x2195f6), LV_PART_INDICATOR|LV_STATE_CHECKED);
	lv_obj_set_style_border_width(ui->screenRecording_sw_06, 0, LV_PART_INDICATOR|LV_STATE_CHECKED);

	//Write style for screenRecording_sw_06, Part: LV_PART_KNOB, State: LV_STATE_DEFAULT.
	lv_obj_set_style_bg_opa(ui->screenRecording_sw_06, 255, LV_PART_KNOB|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui->screenRecording_sw_06, lv_color_hex(0x292831), LV_PART_KNOB|LV_STATE_DEFAULT);
	lv_obj_set_style_border_width(ui->screenRecording_sw_06, 0, LV_PART_KNOB|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->screenRecording_sw_06, 10, LV_PART_KNOB|LV_STATE_DEFAULT);

	//Write codes screenRecording_label_40
	ui->screenRecording_label_40 = lv_label_create(ui->screenRecording_cont_ch06);
	lv_label_set_text(ui->screenRecording_label_40, "06");
	lv_label_set_long_mode(ui->screenRecording_label_40, LV_LABEL_LONG_WRAP);
	lv_obj_set_pos(ui->screenRecording_label_40, 4, 5);
	lv_obj_set_size(ui->screenRecording_label_40, 35, 32);

	//Write style for screenRecording_label_40, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->screenRecording_label_40, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->screenRecording_label_40, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->screenRecording_label_40, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->screenRecording_label_40, &lv_font_montserratMedium_24, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->screenRecording_label_40, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_line_space(ui->screenRecording_label_40, 1, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->screenRecording_label_40, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->screenRecording_label_40, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->screenRecording_label_40, 5, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->screenRecording_label_40, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->screenRecording_label_40, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->screenRecording_label_40, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->screenRecording_label_40, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes screenRecording_cont_ch07
	ui->screenRecording_cont_ch07 = lv_obj_create(ui->screenRecording_cont_10);
	lv_obj_set_pos(ui->screenRecording_cont_ch07, 13, 305);
	lv_obj_set_size(ui->screenRecording_cont_ch07, 210, 46);
	lv_obj_set_scrollbar_mode(ui->screenRecording_cont_ch07, LV_SCROLLBAR_MODE_OFF);

	//Write style for screenRecording_cont_ch07, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->screenRecording_cont_ch07, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_opa(ui->screenRecording_cont_ch07, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_color(ui->screenRecording_cont_ch07, lv_color_hex(0x2195f6), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_side(ui->screenRecording_cont_ch07, LV_BORDER_SIDE_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->screenRecording_cont_ch07, 4, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->screenRecording_cont_ch07, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui->screenRecording_cont_ch07, lv_color_hex(0x292831), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->screenRecording_cont_ch07, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->screenRecording_cont_ch07, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->screenRecording_cont_ch07, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->screenRecording_cont_ch07, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->screenRecording_cont_ch07, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes screenRecording_label_ch_07
	ui->screenRecording_label_ch_07 = lv_label_create(ui->screenRecording_cont_ch07);
	lv_label_set_text(ui->screenRecording_label_ch_07, "CH: 31");
	lv_label_set_long_mode(ui->screenRecording_label_ch_07, LV_LABEL_LONG_WRAP);
	lv_obj_set_pos(ui->screenRecording_label_ch_07, 137, 5);
	lv_obj_set_size(ui->screenRecording_label_ch_07, 66, 32);

	//Write style for screenRecording_label_ch_07, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->screenRecording_label_ch_07, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->screenRecording_label_ch_07, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->screenRecording_label_ch_07, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->screenRecording_label_ch_07, &lv_font_MontserratRegular_20, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->screenRecording_label_ch_07, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_line_space(ui->screenRecording_label_ch_07, 1, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->screenRecording_label_ch_07, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->screenRecording_label_ch_07, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->screenRecording_label_ch_07, 7, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->screenRecording_label_ch_07, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->screenRecording_label_ch_07, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->screenRecording_label_ch_07, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->screenRecording_label_ch_07, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes screenRecording_label_spk_07
	ui->screenRecording_label_spk_07 = lv_label_create(ui->screenRecording_cont_ch07);
	lv_label_set_text(ui->screenRecording_label_spk_07, "");
	lv_label_set_long_mode(ui->screenRecording_label_spk_07, LV_LABEL_LONG_WRAP);
	lv_obj_set_pos(ui->screenRecording_label_spk_07, 100, 4);
	lv_obj_set_size(ui->screenRecording_label_spk_07, 25, 32);

	//Write style for screenRecording_label_spk_07, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->screenRecording_label_spk_07, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->screenRecording_label_spk_07, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->screenRecording_label_spk_07, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->screenRecording_label_spk_07, &lv_font_FontAwesome5ProRegular_400_22, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->screenRecording_label_spk_07, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_line_space(ui->screenRecording_label_spk_07, 1, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->screenRecording_label_spk_07, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->screenRecording_label_spk_07, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->screenRecording_label_spk_07, 6, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->screenRecording_label_spk_07, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->screenRecording_label_spk_07, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->screenRecording_label_spk_07, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->screenRecording_label_spk_07, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes screenRecording_sw_07
	ui->screenRecording_sw_07 = lv_switch_create(ui->screenRecording_cont_ch07);
	lv_obj_set_pos(ui->screenRecording_sw_07, 46, 12);
	lv_obj_set_size(ui->screenRecording_sw_07, 40, 20);

	//Write style for screenRecording_sw_07, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_bg_opa(ui->screenRecording_sw_07, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui->screenRecording_sw_07, lv_color_hex(0x41485a), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_width(ui->screenRecording_sw_07, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->screenRecording_sw_07, 10, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->screenRecording_sw_07, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write style for screenRecording_sw_07, Part: LV_PART_INDICATOR, State: LV_STATE_CHECKED.
	lv_obj_set_style_bg_opa(ui->screenRecording_sw_07, 255, LV_PART_INDICATOR|LV_STATE_CHECKED);
	lv_obj_set_style_bg_color(ui->screenRecording_sw_07, lv_color_hex(0x2195f6), LV_PART_INDICATOR|LV_STATE_CHECKED);
	lv_obj_set_style_border_width(ui->screenRecording_sw_07, 0, LV_PART_INDICATOR|LV_STATE_CHECKED);

	//Write style for screenRecording_sw_07, Part: LV_PART_KNOB, State: LV_STATE_DEFAULT.
	lv_obj_set_style_bg_opa(ui->screenRecording_sw_07, 255, LV_PART_KNOB|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui->screenRecording_sw_07, lv_color_hex(0x292831), LV_PART_KNOB|LV_STATE_DEFAULT);
	lv_obj_set_style_border_width(ui->screenRecording_sw_07, 0, LV_PART_KNOB|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->screenRecording_sw_07, 10, LV_PART_KNOB|LV_STATE_DEFAULT);

	//Write codes screenRecording_label_43
	ui->screenRecording_label_43 = lv_label_create(ui->screenRecording_cont_ch07);
	lv_label_set_text(ui->screenRecording_label_43, "07");
	lv_label_set_long_mode(ui->screenRecording_label_43, LV_LABEL_LONG_WRAP);
	lv_obj_set_pos(ui->screenRecording_label_43, 4, 5);
	lv_obj_set_size(ui->screenRecording_label_43, 35, 32);

	//Write style for screenRecording_label_43, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->screenRecording_label_43, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->screenRecording_label_43, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->screenRecording_label_43, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->screenRecording_label_43, &lv_font_montserratMedium_24, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->screenRecording_label_43, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_line_space(ui->screenRecording_label_43, 1, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->screenRecording_label_43, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->screenRecording_label_43, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->screenRecording_label_43, 5, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->screenRecording_label_43, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->screenRecording_label_43, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->screenRecording_label_43, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->screenRecording_label_43, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes screenRecording_cont_ch08
	ui->screenRecording_cont_ch08 = lv_obj_create(ui->screenRecording_cont_10);
	lv_obj_set_pos(ui->screenRecording_cont_ch08, 13, 355);
	lv_obj_set_size(ui->screenRecording_cont_ch08, 210, 46);
	lv_obj_set_scrollbar_mode(ui->screenRecording_cont_ch08, LV_SCROLLBAR_MODE_OFF);

	//Write style for screenRecording_cont_ch08, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->screenRecording_cont_ch08, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_opa(ui->screenRecording_cont_ch08, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_color(ui->screenRecording_cont_ch08, lv_color_hex(0x2195f6), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_side(ui->screenRecording_cont_ch08, LV_BORDER_SIDE_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->screenRecording_cont_ch08, 4, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->screenRecording_cont_ch08, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui->screenRecording_cont_ch08, lv_color_hex(0x292831), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->screenRecording_cont_ch08, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->screenRecording_cont_ch08, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->screenRecording_cont_ch08, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->screenRecording_cont_ch08, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->screenRecording_cont_ch08, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes screenRecording_label_ch_08
	ui->screenRecording_label_ch_08 = lv_label_create(ui->screenRecording_cont_ch08);
	lv_label_set_text(ui->screenRecording_label_ch_08, "CH: 31");
	lv_label_set_long_mode(ui->screenRecording_label_ch_08, LV_LABEL_LONG_WRAP);
	lv_obj_set_pos(ui->screenRecording_label_ch_08, 137, 5);
	lv_obj_set_size(ui->screenRecording_label_ch_08, 66, 32);

	//Write style for screenRecording_label_ch_08, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->screenRecording_label_ch_08, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->screenRecording_label_ch_08, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->screenRecording_label_ch_08, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->screenRecording_label_ch_08, &lv_font_MontserratRegular_20, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->screenRecording_label_ch_08, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_line_space(ui->screenRecording_label_ch_08, 1, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->screenRecording_label_ch_08, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->screenRecording_label_ch_08, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->screenRecording_label_ch_08, 7, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->screenRecording_label_ch_08, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->screenRecording_label_ch_08, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->screenRecording_label_ch_08, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->screenRecording_label_ch_08, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes screenRecording_label_spk_08
	ui->screenRecording_label_spk_08 = lv_label_create(ui->screenRecording_cont_ch08);
	lv_label_set_text(ui->screenRecording_label_spk_08, "");
	lv_label_set_long_mode(ui->screenRecording_label_spk_08, LV_LABEL_LONG_WRAP);
	lv_obj_set_pos(ui->screenRecording_label_spk_08, 100, 4);
	lv_obj_set_size(ui->screenRecording_label_spk_08, 25, 32);

	//Write style for screenRecording_label_spk_08, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->screenRecording_label_spk_08, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->screenRecording_label_spk_08, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->screenRecording_label_spk_08, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->screenRecording_label_spk_08, &lv_font_FontAwesome5ProRegular_400_22, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->screenRecording_label_spk_08, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_line_space(ui->screenRecording_label_spk_08, 1, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->screenRecording_label_spk_08, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->screenRecording_label_spk_08, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->screenRecording_label_spk_08, 6, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->screenRecording_label_spk_08, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->screenRecording_label_spk_08, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->screenRecording_label_spk_08, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->screenRecording_label_spk_08, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes screenRecording_sw_08
	ui->screenRecording_sw_08 = lv_switch_create(ui->screenRecording_cont_ch08);
	lv_obj_set_pos(ui->screenRecording_sw_08, 46, 12);
	lv_obj_set_size(ui->screenRecording_sw_08, 40, 20);

	//Write style for screenRecording_sw_08, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_bg_opa(ui->screenRecording_sw_08, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui->screenRecording_sw_08, lv_color_hex(0x41485a), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_width(ui->screenRecording_sw_08, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->screenRecording_sw_08, 10, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->screenRecording_sw_08, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write style for screenRecording_sw_08, Part: LV_PART_INDICATOR, State: LV_STATE_CHECKED.
	lv_obj_set_style_bg_opa(ui->screenRecording_sw_08, 255, LV_PART_INDICATOR|LV_STATE_CHECKED);
	lv_obj_set_style_bg_color(ui->screenRecording_sw_08, lv_color_hex(0x2195f6), LV_PART_INDICATOR|LV_STATE_CHECKED);
	lv_obj_set_style_border_width(ui->screenRecording_sw_08, 0, LV_PART_INDICATOR|LV_STATE_CHECKED);

	//Write style for screenRecording_sw_08, Part: LV_PART_KNOB, State: LV_STATE_DEFAULT.
	lv_obj_set_style_bg_opa(ui->screenRecording_sw_08, 255, LV_PART_KNOB|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui->screenRecording_sw_08, lv_color_hex(0x292831), LV_PART_KNOB|LV_STATE_DEFAULT);
	lv_obj_set_style_border_width(ui->screenRecording_sw_08, 0, LV_PART_KNOB|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->screenRecording_sw_08, 10, LV_PART_KNOB|LV_STATE_DEFAULT);

	//Write codes screenRecording_label_46
	ui->screenRecording_label_46 = lv_label_create(ui->screenRecording_cont_ch08);
	lv_label_set_text(ui->screenRecording_label_46, "08");
	lv_label_set_long_mode(ui->screenRecording_label_46, LV_LABEL_LONG_WRAP);
	lv_obj_set_pos(ui->screenRecording_label_46, 4, 5);
	lv_obj_set_size(ui->screenRecording_label_46, 35, 32);

	//Write style for screenRecording_label_46, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->screenRecording_label_46, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->screenRecording_label_46, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->screenRecording_label_46, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->screenRecording_label_46, &lv_font_montserratMedium_24, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->screenRecording_label_46, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_line_space(ui->screenRecording_label_46, 1, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->screenRecording_label_46, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->screenRecording_label_46, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->screenRecording_label_46, 5, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->screenRecording_label_46, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->screenRecording_label_46, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->screenRecording_label_46, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->screenRecording_label_46, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes screenRecording_cont_ch09
	ui->screenRecording_cont_ch09 = lv_obj_create(ui->screenRecording_cont_10);
	lv_obj_set_pos(ui->screenRecording_cont_ch09, 13, 405);
	lv_obj_set_size(ui->screenRecording_cont_ch09, 210, 46);
	lv_obj_set_scrollbar_mode(ui->screenRecording_cont_ch09, LV_SCROLLBAR_MODE_OFF);

	//Write style for screenRecording_cont_ch09, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->screenRecording_cont_ch09, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_opa(ui->screenRecording_cont_ch09, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_color(ui->screenRecording_cont_ch09, lv_color_hex(0x2195f6), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_side(ui->screenRecording_cont_ch09, LV_BORDER_SIDE_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->screenRecording_cont_ch09, 4, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->screenRecording_cont_ch09, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui->screenRecording_cont_ch09, lv_color_hex(0x292831), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->screenRecording_cont_ch09, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->screenRecording_cont_ch09, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->screenRecording_cont_ch09, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->screenRecording_cont_ch09, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->screenRecording_cont_ch09, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes screenRecording_label_ch_09
	ui->screenRecording_label_ch_09 = lv_label_create(ui->screenRecording_cont_ch09);
	lv_label_set_text(ui->screenRecording_label_ch_09, "CH: 31");
	lv_label_set_long_mode(ui->screenRecording_label_ch_09, LV_LABEL_LONG_WRAP);
	lv_obj_set_pos(ui->screenRecording_label_ch_09, 137, 5);
	lv_obj_set_size(ui->screenRecording_label_ch_09, 66, 32);

	//Write style for screenRecording_label_ch_09, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->screenRecording_label_ch_09, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->screenRecording_label_ch_09, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->screenRecording_label_ch_09, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->screenRecording_label_ch_09, &lv_font_MontserratRegular_20, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->screenRecording_label_ch_09, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_line_space(ui->screenRecording_label_ch_09, 1, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->screenRecording_label_ch_09, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->screenRecording_label_ch_09, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->screenRecording_label_ch_09, 7, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->screenRecording_label_ch_09, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->screenRecording_label_ch_09, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->screenRecording_label_ch_09, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->screenRecording_label_ch_09, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes screenRecording_label_spk_09
	ui->screenRecording_label_spk_09 = lv_label_create(ui->screenRecording_cont_ch09);
	lv_label_set_text(ui->screenRecording_label_spk_09, "");
	lv_label_set_long_mode(ui->screenRecording_label_spk_09, LV_LABEL_LONG_WRAP);
	lv_obj_set_pos(ui->screenRecording_label_spk_09, 100, 4);
	lv_obj_set_size(ui->screenRecording_label_spk_09, 25, 32);

	//Write style for screenRecording_label_spk_09, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->screenRecording_label_spk_09, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->screenRecording_label_spk_09, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->screenRecording_label_spk_09, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->screenRecording_label_spk_09, &lv_font_FontAwesome5ProRegular_400_22, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->screenRecording_label_spk_09, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_line_space(ui->screenRecording_label_spk_09, 1, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->screenRecording_label_spk_09, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->screenRecording_label_spk_09, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->screenRecording_label_spk_09, 6, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->screenRecording_label_spk_09, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->screenRecording_label_spk_09, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->screenRecording_label_spk_09, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->screenRecording_label_spk_09, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes screenRecording_sw_09
	ui->screenRecording_sw_09 = lv_switch_create(ui->screenRecording_cont_ch09);
	lv_obj_set_pos(ui->screenRecording_sw_09, 46, 12);
	lv_obj_set_size(ui->screenRecording_sw_09, 40, 20);

	//Write style for screenRecording_sw_09, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_bg_opa(ui->screenRecording_sw_09, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui->screenRecording_sw_09, lv_color_hex(0x41485a), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_width(ui->screenRecording_sw_09, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->screenRecording_sw_09, 10, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->screenRecording_sw_09, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write style for screenRecording_sw_09, Part: LV_PART_INDICATOR, State: LV_STATE_CHECKED.
	lv_obj_set_style_bg_opa(ui->screenRecording_sw_09, 255, LV_PART_INDICATOR|LV_STATE_CHECKED);
	lv_obj_set_style_bg_color(ui->screenRecording_sw_09, lv_color_hex(0x2195f6), LV_PART_INDICATOR|LV_STATE_CHECKED);
	lv_obj_set_style_border_width(ui->screenRecording_sw_09, 0, LV_PART_INDICATOR|LV_STATE_CHECKED);

	//Write style for screenRecording_sw_09, Part: LV_PART_KNOB, State: LV_STATE_DEFAULT.
	lv_obj_set_style_bg_opa(ui->screenRecording_sw_09, 255, LV_PART_KNOB|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui->screenRecording_sw_09, lv_color_hex(0x292831), LV_PART_KNOB|LV_STATE_DEFAULT);
	lv_obj_set_style_border_width(ui->screenRecording_sw_09, 0, LV_PART_KNOB|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->screenRecording_sw_09, 10, LV_PART_KNOB|LV_STATE_DEFAULT);

	//Write codes screenRecording_label_49
	ui->screenRecording_label_49 = lv_label_create(ui->screenRecording_cont_ch09);
	lv_label_set_text(ui->screenRecording_label_49, "09");
	lv_label_set_long_mode(ui->screenRecording_label_49, LV_LABEL_LONG_WRAP);
	lv_obj_set_pos(ui->screenRecording_label_49, 4, 5);
	lv_obj_set_size(ui->screenRecording_label_49, 35, 32);

	//Write style for screenRecording_label_49, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->screenRecording_label_49, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->screenRecording_label_49, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->screenRecording_label_49, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->screenRecording_label_49, &lv_font_montserratMedium_24, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->screenRecording_label_49, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_line_space(ui->screenRecording_label_49, 1, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->screenRecording_label_49, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->screenRecording_label_49, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->screenRecording_label_49, 5, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->screenRecording_label_49, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->screenRecording_label_49, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->screenRecording_label_49, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->screenRecording_label_49, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes screenRecording_cont_ch10
	ui->screenRecording_cont_ch10 = lv_obj_create(ui->screenRecording_cont_10);
	lv_obj_set_pos(ui->screenRecording_cont_ch10, 13, 455);
	lv_obj_set_size(ui->screenRecording_cont_ch10, 210, 46);
	lv_obj_set_scrollbar_mode(ui->screenRecording_cont_ch10, LV_SCROLLBAR_MODE_OFF);

	//Write style for screenRecording_cont_ch10, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->screenRecording_cont_ch10, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_opa(ui->screenRecording_cont_ch10, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_color(ui->screenRecording_cont_ch10, lv_color_hex(0x2195f6), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_side(ui->screenRecording_cont_ch10, LV_BORDER_SIDE_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->screenRecording_cont_ch10, 4, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->screenRecording_cont_ch10, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui->screenRecording_cont_ch10, lv_color_hex(0x292831), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->screenRecording_cont_ch10, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->screenRecording_cont_ch10, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->screenRecording_cont_ch10, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->screenRecording_cont_ch10, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->screenRecording_cont_ch10, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes screenRecording_label_ch_10
	ui->screenRecording_label_ch_10 = lv_label_create(ui->screenRecording_cont_ch10);
	lv_label_set_text(ui->screenRecording_label_ch_10, "CH: 31");
	lv_label_set_long_mode(ui->screenRecording_label_ch_10, LV_LABEL_LONG_WRAP);
	lv_obj_set_pos(ui->screenRecording_label_ch_10, 137, 5);
	lv_obj_set_size(ui->screenRecording_label_ch_10, 66, 32);

	//Write style for screenRecording_label_ch_10, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->screenRecording_label_ch_10, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->screenRecording_label_ch_10, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->screenRecording_label_ch_10, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->screenRecording_label_ch_10, &lv_font_MontserratRegular_20, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->screenRecording_label_ch_10, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_line_space(ui->screenRecording_label_ch_10, 1, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->screenRecording_label_ch_10, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->screenRecording_label_ch_10, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->screenRecording_label_ch_10, 7, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->screenRecording_label_ch_10, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->screenRecording_label_ch_10, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->screenRecording_label_ch_10, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->screenRecording_label_ch_10, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes screenRecording_label_spk_10
	ui->screenRecording_label_spk_10 = lv_label_create(ui->screenRecording_cont_ch10);
	lv_label_set_text(ui->screenRecording_label_spk_10, "");
	lv_label_set_long_mode(ui->screenRecording_label_spk_10, LV_LABEL_LONG_WRAP);
	lv_obj_set_pos(ui->screenRecording_label_spk_10, 100, 4);
	lv_obj_set_size(ui->screenRecording_label_spk_10, 25, 32);

	//Write style for screenRecording_label_spk_10, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->screenRecording_label_spk_10, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->screenRecording_label_spk_10, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->screenRecording_label_spk_10, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->screenRecording_label_spk_10, &lv_font_FontAwesome5ProRegular_400_22, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->screenRecording_label_spk_10, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_line_space(ui->screenRecording_label_spk_10, 1, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->screenRecording_label_spk_10, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->screenRecording_label_spk_10, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->screenRecording_label_spk_10, 6, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->screenRecording_label_spk_10, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->screenRecording_label_spk_10, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->screenRecording_label_spk_10, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->screenRecording_label_spk_10, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes screenRecording_sw_10
	ui->screenRecording_sw_10 = lv_switch_create(ui->screenRecording_cont_ch10);
	lv_obj_set_pos(ui->screenRecording_sw_10, 46, 12);
	lv_obj_set_size(ui->screenRecording_sw_10, 40, 20);

	//Write style for screenRecording_sw_10, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_bg_opa(ui->screenRecording_sw_10, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui->screenRecording_sw_10, lv_color_hex(0x41485a), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_width(ui->screenRecording_sw_10, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->screenRecording_sw_10, 10, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->screenRecording_sw_10, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write style for screenRecording_sw_10, Part: LV_PART_INDICATOR, State: LV_STATE_CHECKED.
	lv_obj_set_style_bg_opa(ui->screenRecording_sw_10, 255, LV_PART_INDICATOR|LV_STATE_CHECKED);
	lv_obj_set_style_bg_color(ui->screenRecording_sw_10, lv_color_hex(0x2195f6), LV_PART_INDICATOR|LV_STATE_CHECKED);
	lv_obj_set_style_border_width(ui->screenRecording_sw_10, 0, LV_PART_INDICATOR|LV_STATE_CHECKED);

	//Write style for screenRecording_sw_10, Part: LV_PART_KNOB, State: LV_STATE_DEFAULT.
	lv_obj_set_style_bg_opa(ui->screenRecording_sw_10, 255, LV_PART_KNOB|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui->screenRecording_sw_10, lv_color_hex(0x292831), LV_PART_KNOB|LV_STATE_DEFAULT);
	lv_obj_set_style_border_width(ui->screenRecording_sw_10, 0, LV_PART_KNOB|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->screenRecording_sw_10, 10, LV_PART_KNOB|LV_STATE_DEFAULT);

	//Write codes screenRecording_label_52
	ui->screenRecording_label_52 = lv_label_create(ui->screenRecording_cont_ch10);
	lv_label_set_text(ui->screenRecording_label_52, "10");
	lv_label_set_long_mode(ui->screenRecording_label_52, LV_LABEL_LONG_WRAP);
	lv_obj_set_pos(ui->screenRecording_label_52, 4, 5);
	lv_obj_set_size(ui->screenRecording_label_52, 35, 32);

	//Write style for screenRecording_label_52, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->screenRecording_label_52, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->screenRecording_label_52, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->screenRecording_label_52, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->screenRecording_label_52, &lv_font_montserratMedium_24, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->screenRecording_label_52, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_line_space(ui->screenRecording_label_52, 1, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->screenRecording_label_52, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->screenRecording_label_52, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->screenRecording_label_52, 5, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->screenRecording_label_52, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->screenRecording_label_52, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->screenRecording_label_52, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->screenRecording_label_52, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes screenRecording_cont_ch11
	ui->screenRecording_cont_ch11 = lv_obj_create(ui->screenRecording_cont_10);
	lv_obj_set_pos(ui->screenRecording_cont_ch11, 13, 505);
	lv_obj_set_size(ui->screenRecording_cont_ch11, 210, 46);
	lv_obj_set_scrollbar_mode(ui->screenRecording_cont_ch11, LV_SCROLLBAR_MODE_OFF);

	//Write style for screenRecording_cont_ch11, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->screenRecording_cont_ch11, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_opa(ui->screenRecording_cont_ch11, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_color(ui->screenRecording_cont_ch11, lv_color_hex(0x2195f6), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_side(ui->screenRecording_cont_ch11, LV_BORDER_SIDE_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->screenRecording_cont_ch11, 4, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->screenRecording_cont_ch11, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui->screenRecording_cont_ch11, lv_color_hex(0x292831), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->screenRecording_cont_ch11, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->screenRecording_cont_ch11, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->screenRecording_cont_ch11, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->screenRecording_cont_ch11, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->screenRecording_cont_ch11, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes screenRecording_label_ch_11
	ui->screenRecording_label_ch_11 = lv_label_create(ui->screenRecording_cont_ch11);
	lv_label_set_text(ui->screenRecording_label_ch_11, "CH: 31");
	lv_label_set_long_mode(ui->screenRecording_label_ch_11, LV_LABEL_LONG_WRAP);
	lv_obj_set_pos(ui->screenRecording_label_ch_11, 137, 5);
	lv_obj_set_size(ui->screenRecording_label_ch_11, 66, 32);

	//Write style for screenRecording_label_ch_11, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->screenRecording_label_ch_11, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->screenRecording_label_ch_11, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->screenRecording_label_ch_11, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->screenRecording_label_ch_11, &lv_font_MontserratRegular_20, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->screenRecording_label_ch_11, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_line_space(ui->screenRecording_label_ch_11, 1, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->screenRecording_label_ch_11, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->screenRecording_label_ch_11, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->screenRecording_label_ch_11, 7, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->screenRecording_label_ch_11, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->screenRecording_label_ch_11, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->screenRecording_label_ch_11, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->screenRecording_label_ch_11, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes screenRecording_label_spk_11
	ui->screenRecording_label_spk_11 = lv_label_create(ui->screenRecording_cont_ch11);
	lv_label_set_text(ui->screenRecording_label_spk_11, "");
	lv_label_set_long_mode(ui->screenRecording_label_spk_11, LV_LABEL_LONG_WRAP);
	lv_obj_set_pos(ui->screenRecording_label_spk_11, 100, 4);
	lv_obj_set_size(ui->screenRecording_label_spk_11, 25, 32);

	//Write style for screenRecording_label_spk_11, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->screenRecording_label_spk_11, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->screenRecording_label_spk_11, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->screenRecording_label_spk_11, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->screenRecording_label_spk_11, &lv_font_FontAwesome5ProRegular_400_22, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->screenRecording_label_spk_11, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_line_space(ui->screenRecording_label_spk_11, 1, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->screenRecording_label_spk_11, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->screenRecording_label_spk_11, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->screenRecording_label_spk_11, 6, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->screenRecording_label_spk_11, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->screenRecording_label_spk_11, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->screenRecording_label_spk_11, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->screenRecording_label_spk_11, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes screenRecording_sw_11
	ui->screenRecording_sw_11 = lv_switch_create(ui->screenRecording_cont_ch11);
	lv_obj_set_pos(ui->screenRecording_sw_11, 46, 12);
	lv_obj_set_size(ui->screenRecording_sw_11, 40, 20);

	//Write style for screenRecording_sw_11, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_bg_opa(ui->screenRecording_sw_11, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui->screenRecording_sw_11, lv_color_hex(0x41485a), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_width(ui->screenRecording_sw_11, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->screenRecording_sw_11, 10, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->screenRecording_sw_11, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write style for screenRecording_sw_11, Part: LV_PART_INDICATOR, State: LV_STATE_CHECKED.
	lv_obj_set_style_bg_opa(ui->screenRecording_sw_11, 255, LV_PART_INDICATOR|LV_STATE_CHECKED);
	lv_obj_set_style_bg_color(ui->screenRecording_sw_11, lv_color_hex(0x2195f6), LV_PART_INDICATOR|LV_STATE_CHECKED);
	lv_obj_set_style_border_width(ui->screenRecording_sw_11, 0, LV_PART_INDICATOR|LV_STATE_CHECKED);

	//Write style for screenRecording_sw_11, Part: LV_PART_KNOB, State: LV_STATE_DEFAULT.
	lv_obj_set_style_bg_opa(ui->screenRecording_sw_11, 255, LV_PART_KNOB|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui->screenRecording_sw_11, lv_color_hex(0x292831), LV_PART_KNOB|LV_STATE_DEFAULT);
	lv_obj_set_style_border_width(ui->screenRecording_sw_11, 0, LV_PART_KNOB|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->screenRecording_sw_11, 10, LV_PART_KNOB|LV_STATE_DEFAULT);

	//Write codes screenRecording_label_55
	ui->screenRecording_label_55 = lv_label_create(ui->screenRecording_cont_ch11);
	lv_label_set_text(ui->screenRecording_label_55, "11");
	lv_label_set_long_mode(ui->screenRecording_label_55, LV_LABEL_LONG_WRAP);
	lv_obj_set_pos(ui->screenRecording_label_55, 4, 5);
	lv_obj_set_size(ui->screenRecording_label_55, 35, 32);

	//Write style for screenRecording_label_55, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->screenRecording_label_55, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->screenRecording_label_55, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->screenRecording_label_55, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->screenRecording_label_55, &lv_font_montserratMedium_24, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->screenRecording_label_55, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_line_space(ui->screenRecording_label_55, 1, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->screenRecording_label_55, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->screenRecording_label_55, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->screenRecording_label_55, 5, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->screenRecording_label_55, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->screenRecording_label_55, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->screenRecording_label_55, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->screenRecording_label_55, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes screenRecording_cont_ch12
	ui->screenRecording_cont_ch12 = lv_obj_create(ui->screenRecording_cont_10);
	lv_obj_set_pos(ui->screenRecording_cont_ch12, 13, 555);
	lv_obj_set_size(ui->screenRecording_cont_ch12, 210, 46);
	lv_obj_set_scrollbar_mode(ui->screenRecording_cont_ch12, LV_SCROLLBAR_MODE_OFF);

	//Write style for screenRecording_cont_ch12, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->screenRecording_cont_ch12, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_opa(ui->screenRecording_cont_ch12, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_color(ui->screenRecording_cont_ch12, lv_color_hex(0x2195f6), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_side(ui->screenRecording_cont_ch12, LV_BORDER_SIDE_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->screenRecording_cont_ch12, 4, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->screenRecording_cont_ch12, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui->screenRecording_cont_ch12, lv_color_hex(0x292831), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->screenRecording_cont_ch12, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->screenRecording_cont_ch12, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->screenRecording_cont_ch12, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->screenRecording_cont_ch12, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->screenRecording_cont_ch12, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes screenRecording_label_ch_12
	ui->screenRecording_label_ch_12 = lv_label_create(ui->screenRecording_cont_ch12);
	lv_label_set_text(ui->screenRecording_label_ch_12, "CH: 31");
	lv_label_set_long_mode(ui->screenRecording_label_ch_12, LV_LABEL_LONG_WRAP);
	lv_obj_set_pos(ui->screenRecording_label_ch_12, 137, 5);
	lv_obj_set_size(ui->screenRecording_label_ch_12, 66, 32);

	//Write style for screenRecording_label_ch_12, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->screenRecording_label_ch_12, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->screenRecording_label_ch_12, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->screenRecording_label_ch_12, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->screenRecording_label_ch_12, &lv_font_MontserratRegular_20, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->screenRecording_label_ch_12, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_line_space(ui->screenRecording_label_ch_12, 1, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->screenRecording_label_ch_12, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->screenRecording_label_ch_12, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->screenRecording_label_ch_12, 7, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->screenRecording_label_ch_12, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->screenRecording_label_ch_12, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->screenRecording_label_ch_12, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->screenRecording_label_ch_12, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes screenRecording_label_spk_12
	ui->screenRecording_label_spk_12 = lv_label_create(ui->screenRecording_cont_ch12);
	lv_label_set_text(ui->screenRecording_label_spk_12, "");
	lv_label_set_long_mode(ui->screenRecording_label_spk_12, LV_LABEL_LONG_WRAP);
	lv_obj_set_pos(ui->screenRecording_label_spk_12, 100, 4);
	lv_obj_set_size(ui->screenRecording_label_spk_12, 25, 32);

	//Write style for screenRecording_label_spk_12, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->screenRecording_label_spk_12, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->screenRecording_label_spk_12, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->screenRecording_label_spk_12, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->screenRecording_label_spk_12, &lv_font_FontAwesome5ProRegular_400_22, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->screenRecording_label_spk_12, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_line_space(ui->screenRecording_label_spk_12, 1, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->screenRecording_label_spk_12, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->screenRecording_label_spk_12, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->screenRecording_label_spk_12, 6, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->screenRecording_label_spk_12, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->screenRecording_label_spk_12, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->screenRecording_label_spk_12, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->screenRecording_label_spk_12, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes screenRecording_sw_12
	ui->screenRecording_sw_12 = lv_switch_create(ui->screenRecording_cont_ch12);
	lv_obj_set_pos(ui->screenRecording_sw_12, 46, 12);
	lv_obj_set_size(ui->screenRecording_sw_12, 40, 20);

	//Write style for screenRecording_sw_12, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_bg_opa(ui->screenRecording_sw_12, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui->screenRecording_sw_12, lv_color_hex(0x41485a), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_width(ui->screenRecording_sw_12, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->screenRecording_sw_12, 10, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->screenRecording_sw_12, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write style for screenRecording_sw_12, Part: LV_PART_INDICATOR, State: LV_STATE_CHECKED.
	lv_obj_set_style_bg_opa(ui->screenRecording_sw_12, 255, LV_PART_INDICATOR|LV_STATE_CHECKED);
	lv_obj_set_style_bg_color(ui->screenRecording_sw_12, lv_color_hex(0x2195f6), LV_PART_INDICATOR|LV_STATE_CHECKED);
	lv_obj_set_style_border_width(ui->screenRecording_sw_12, 0, LV_PART_INDICATOR|LV_STATE_CHECKED);

	//Write style for screenRecording_sw_12, Part: LV_PART_KNOB, State: LV_STATE_DEFAULT.
	lv_obj_set_style_bg_opa(ui->screenRecording_sw_12, 255, LV_PART_KNOB|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui->screenRecording_sw_12, lv_color_hex(0x292831), LV_PART_KNOB|LV_STATE_DEFAULT);
	lv_obj_set_style_border_width(ui->screenRecording_sw_12, 0, LV_PART_KNOB|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->screenRecording_sw_12, 10, LV_PART_KNOB|LV_STATE_DEFAULT);

	//Write codes screenRecording_label_58
	ui->screenRecording_label_58 = lv_label_create(ui->screenRecording_cont_ch12);
	lv_label_set_text(ui->screenRecording_label_58, "12");
	lv_label_set_long_mode(ui->screenRecording_label_58, LV_LABEL_LONG_WRAP);
	lv_obj_set_pos(ui->screenRecording_label_58, 4, 5);
	lv_obj_set_size(ui->screenRecording_label_58, 35, 32);

	//Write style for screenRecording_label_58, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->screenRecording_label_58, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->screenRecording_label_58, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->screenRecording_label_58, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->screenRecording_label_58, &lv_font_montserratMedium_24, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->screenRecording_label_58, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_line_space(ui->screenRecording_label_58, 1, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->screenRecording_label_58, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->screenRecording_label_58, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->screenRecording_label_58, 5, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->screenRecording_label_58, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->screenRecording_label_58, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->screenRecording_label_58, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->screenRecording_label_58, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes screenRecording_cont_ch13
	ui->screenRecording_cont_ch13 = lv_obj_create(ui->screenRecording_cont_10);
	lv_obj_set_pos(ui->screenRecording_cont_ch13, 13, 605);
	lv_obj_set_size(ui->screenRecording_cont_ch13, 210, 46);
	lv_obj_set_scrollbar_mode(ui->screenRecording_cont_ch13, LV_SCROLLBAR_MODE_OFF);

	//Write style for screenRecording_cont_ch13, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->screenRecording_cont_ch13, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_opa(ui->screenRecording_cont_ch13, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_color(ui->screenRecording_cont_ch13, lv_color_hex(0x2195f6), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_side(ui->screenRecording_cont_ch13, LV_BORDER_SIDE_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->screenRecording_cont_ch13, 4, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->screenRecording_cont_ch13, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui->screenRecording_cont_ch13, lv_color_hex(0x292831), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->screenRecording_cont_ch13, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->screenRecording_cont_ch13, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->screenRecording_cont_ch13, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->screenRecording_cont_ch13, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->screenRecording_cont_ch13, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes screenRecording_label_ch_13
	ui->screenRecording_label_ch_13 = lv_label_create(ui->screenRecording_cont_ch13);
	lv_label_set_text(ui->screenRecording_label_ch_13, "CH: 31");
	lv_label_set_long_mode(ui->screenRecording_label_ch_13, LV_LABEL_LONG_WRAP);
	lv_obj_set_pos(ui->screenRecording_label_ch_13, 137, 5);
	lv_obj_set_size(ui->screenRecording_label_ch_13, 66, 32);

	//Write style for screenRecording_label_ch_13, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->screenRecording_label_ch_13, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->screenRecording_label_ch_13, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->screenRecording_label_ch_13, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->screenRecording_label_ch_13, &lv_font_MontserratRegular_20, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->screenRecording_label_ch_13, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_line_space(ui->screenRecording_label_ch_13, 1, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->screenRecording_label_ch_13, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->screenRecording_label_ch_13, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->screenRecording_label_ch_13, 7, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->screenRecording_label_ch_13, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->screenRecording_label_ch_13, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->screenRecording_label_ch_13, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->screenRecording_label_ch_13, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes screenRecording_label_spk_13
	ui->screenRecording_label_spk_13 = lv_label_create(ui->screenRecording_cont_ch13);
	lv_label_set_text(ui->screenRecording_label_spk_13, "");
	lv_label_set_long_mode(ui->screenRecording_label_spk_13, LV_LABEL_LONG_WRAP);
	lv_obj_set_pos(ui->screenRecording_label_spk_13, 100, 4);
	lv_obj_set_size(ui->screenRecording_label_spk_13, 25, 32);

	//Write style for screenRecording_label_spk_13, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->screenRecording_label_spk_13, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->screenRecording_label_spk_13, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->screenRecording_label_spk_13, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->screenRecording_label_spk_13, &lv_font_FontAwesome5ProRegular_400_22, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->screenRecording_label_spk_13, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_line_space(ui->screenRecording_label_spk_13, 1, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->screenRecording_label_spk_13, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->screenRecording_label_spk_13, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->screenRecording_label_spk_13, 6, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->screenRecording_label_spk_13, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->screenRecording_label_spk_13, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->screenRecording_label_spk_13, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->screenRecording_label_spk_13, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes screenRecording_sw_13
	ui->screenRecording_sw_13 = lv_switch_create(ui->screenRecording_cont_ch13);
	lv_obj_set_pos(ui->screenRecording_sw_13, 46, 12);
	lv_obj_set_size(ui->screenRecording_sw_13, 40, 20);

	//Write style for screenRecording_sw_13, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_bg_opa(ui->screenRecording_sw_13, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui->screenRecording_sw_13, lv_color_hex(0x41485a), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_width(ui->screenRecording_sw_13, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->screenRecording_sw_13, 10, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->screenRecording_sw_13, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write style for screenRecording_sw_13, Part: LV_PART_INDICATOR, State: LV_STATE_CHECKED.
	lv_obj_set_style_bg_opa(ui->screenRecording_sw_13, 255, LV_PART_INDICATOR|LV_STATE_CHECKED);
	lv_obj_set_style_bg_color(ui->screenRecording_sw_13, lv_color_hex(0x2195f6), LV_PART_INDICATOR|LV_STATE_CHECKED);
	lv_obj_set_style_border_width(ui->screenRecording_sw_13, 0, LV_PART_INDICATOR|LV_STATE_CHECKED);

	//Write style for screenRecording_sw_13, Part: LV_PART_KNOB, State: LV_STATE_DEFAULT.
	lv_obj_set_style_bg_opa(ui->screenRecording_sw_13, 255, LV_PART_KNOB|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui->screenRecording_sw_13, lv_color_hex(0x292831), LV_PART_KNOB|LV_STATE_DEFAULT);
	lv_obj_set_style_border_width(ui->screenRecording_sw_13, 0, LV_PART_KNOB|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->screenRecording_sw_13, 10, LV_PART_KNOB|LV_STATE_DEFAULT);

	//Write codes screenRecording_label_61
	ui->screenRecording_label_61 = lv_label_create(ui->screenRecording_cont_ch13);
	lv_label_set_text(ui->screenRecording_label_61, "13");
	lv_label_set_long_mode(ui->screenRecording_label_61, LV_LABEL_LONG_WRAP);
	lv_obj_set_pos(ui->screenRecording_label_61, 4, 5);
	lv_obj_set_size(ui->screenRecording_label_61, 35, 32);

	//Write style for screenRecording_label_61, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->screenRecording_label_61, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->screenRecording_label_61, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->screenRecording_label_61, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->screenRecording_label_61, &lv_font_montserratMedium_24, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->screenRecording_label_61, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_line_space(ui->screenRecording_label_61, 1, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->screenRecording_label_61, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->screenRecording_label_61, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->screenRecording_label_61, 5, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->screenRecording_label_61, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->screenRecording_label_61, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->screenRecording_label_61, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->screenRecording_label_61, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes screenRecording_cont_ch14
	ui->screenRecording_cont_ch14 = lv_obj_create(ui->screenRecording_cont_10);
	lv_obj_set_pos(ui->screenRecording_cont_ch14, 13, 655);
	lv_obj_set_size(ui->screenRecording_cont_ch14, 210, 46);
	lv_obj_set_scrollbar_mode(ui->screenRecording_cont_ch14, LV_SCROLLBAR_MODE_OFF);

	//Write style for screenRecording_cont_ch14, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->screenRecording_cont_ch14, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_opa(ui->screenRecording_cont_ch14, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_color(ui->screenRecording_cont_ch14, lv_color_hex(0x2195f6), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_side(ui->screenRecording_cont_ch14, LV_BORDER_SIDE_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->screenRecording_cont_ch14, 4, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->screenRecording_cont_ch14, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui->screenRecording_cont_ch14, lv_color_hex(0x292831), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->screenRecording_cont_ch14, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->screenRecording_cont_ch14, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->screenRecording_cont_ch14, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->screenRecording_cont_ch14, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->screenRecording_cont_ch14, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes screenRecording_label_ch_14
	ui->screenRecording_label_ch_14 = lv_label_create(ui->screenRecording_cont_ch14);
	lv_label_set_text(ui->screenRecording_label_ch_14, "CH: 31");
	lv_label_set_long_mode(ui->screenRecording_label_ch_14, LV_LABEL_LONG_WRAP);
	lv_obj_set_pos(ui->screenRecording_label_ch_14, 137, 5);
	lv_obj_set_size(ui->screenRecording_label_ch_14, 66, 32);

	//Write style for screenRecording_label_ch_14, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->screenRecording_label_ch_14, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->screenRecording_label_ch_14, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->screenRecording_label_ch_14, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->screenRecording_label_ch_14, &lv_font_MontserratRegular_20, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->screenRecording_label_ch_14, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_line_space(ui->screenRecording_label_ch_14, 1, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->screenRecording_label_ch_14, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->screenRecording_label_ch_14, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->screenRecording_label_ch_14, 7, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->screenRecording_label_ch_14, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->screenRecording_label_ch_14, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->screenRecording_label_ch_14, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->screenRecording_label_ch_14, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes screenRecording_label_spk_14
	ui->screenRecording_label_spk_14 = lv_label_create(ui->screenRecording_cont_ch14);
	lv_label_set_text(ui->screenRecording_label_spk_14, "");
	lv_label_set_long_mode(ui->screenRecording_label_spk_14, LV_LABEL_LONG_WRAP);
	lv_obj_set_pos(ui->screenRecording_label_spk_14, 100, 4);
	lv_obj_set_size(ui->screenRecording_label_spk_14, 25, 32);

	//Write style for screenRecording_label_spk_14, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->screenRecording_label_spk_14, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->screenRecording_label_spk_14, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->screenRecording_label_spk_14, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->screenRecording_label_spk_14, &lv_font_FontAwesome5ProRegular_400_22, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->screenRecording_label_spk_14, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_line_space(ui->screenRecording_label_spk_14, 1, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->screenRecording_label_spk_14, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->screenRecording_label_spk_14, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->screenRecording_label_spk_14, 6, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->screenRecording_label_spk_14, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->screenRecording_label_spk_14, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->screenRecording_label_spk_14, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->screenRecording_label_spk_14, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes screenRecording_sw_14
	ui->screenRecording_sw_14 = lv_switch_create(ui->screenRecording_cont_ch14);
	lv_obj_set_pos(ui->screenRecording_sw_14, 46, 12);
	lv_obj_set_size(ui->screenRecording_sw_14, 40, 20);

	//Write style for screenRecording_sw_14, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_bg_opa(ui->screenRecording_sw_14, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui->screenRecording_sw_14, lv_color_hex(0x41485a), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_width(ui->screenRecording_sw_14, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->screenRecording_sw_14, 10, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->screenRecording_sw_14, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write style for screenRecording_sw_14, Part: LV_PART_INDICATOR, State: LV_STATE_CHECKED.
	lv_obj_set_style_bg_opa(ui->screenRecording_sw_14, 255, LV_PART_INDICATOR|LV_STATE_CHECKED);
	lv_obj_set_style_bg_color(ui->screenRecording_sw_14, lv_color_hex(0x2195f6), LV_PART_INDICATOR|LV_STATE_CHECKED);
	lv_obj_set_style_border_width(ui->screenRecording_sw_14, 0, LV_PART_INDICATOR|LV_STATE_CHECKED);

	//Write style for screenRecording_sw_14, Part: LV_PART_KNOB, State: LV_STATE_DEFAULT.
	lv_obj_set_style_bg_opa(ui->screenRecording_sw_14, 255, LV_PART_KNOB|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui->screenRecording_sw_14, lv_color_hex(0x292831), LV_PART_KNOB|LV_STATE_DEFAULT);
	lv_obj_set_style_border_width(ui->screenRecording_sw_14, 0, LV_PART_KNOB|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->screenRecording_sw_14, 10, LV_PART_KNOB|LV_STATE_DEFAULT);

	//Write codes screenRecording_label_64
	ui->screenRecording_label_64 = lv_label_create(ui->screenRecording_cont_ch14);
	lv_label_set_text(ui->screenRecording_label_64, "14");
	lv_label_set_long_mode(ui->screenRecording_label_64, LV_LABEL_LONG_WRAP);
	lv_obj_set_pos(ui->screenRecording_label_64, 4, 5);
	lv_obj_set_size(ui->screenRecording_label_64, 35, 32);

	//Write style for screenRecording_label_64, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->screenRecording_label_64, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->screenRecording_label_64, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->screenRecording_label_64, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->screenRecording_label_64, &lv_font_montserratMedium_24, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->screenRecording_label_64, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_line_space(ui->screenRecording_label_64, 1, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->screenRecording_label_64, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->screenRecording_label_64, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->screenRecording_label_64, 5, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->screenRecording_label_64, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->screenRecording_label_64, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->screenRecording_label_64, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->screenRecording_label_64, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes screenRecording_cont_ch15
	ui->screenRecording_cont_ch15 = lv_obj_create(ui->screenRecording_cont_10);
	lv_obj_set_pos(ui->screenRecording_cont_ch15, 13, 705);
	lv_obj_set_size(ui->screenRecording_cont_ch15, 210, 46);
	lv_obj_set_scrollbar_mode(ui->screenRecording_cont_ch15, LV_SCROLLBAR_MODE_OFF);

	//Write style for screenRecording_cont_ch15, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->screenRecording_cont_ch15, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_opa(ui->screenRecording_cont_ch15, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_color(ui->screenRecording_cont_ch15, lv_color_hex(0x2195f6), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_side(ui->screenRecording_cont_ch15, LV_BORDER_SIDE_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->screenRecording_cont_ch15, 4, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->screenRecording_cont_ch15, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui->screenRecording_cont_ch15, lv_color_hex(0x292831), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->screenRecording_cont_ch15, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->screenRecording_cont_ch15, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->screenRecording_cont_ch15, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->screenRecording_cont_ch15, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->screenRecording_cont_ch15, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes screenRecording_label_ch_15
	ui->screenRecording_label_ch_15 = lv_label_create(ui->screenRecording_cont_ch15);
	lv_label_set_text(ui->screenRecording_label_ch_15, "CH: 31");
	lv_label_set_long_mode(ui->screenRecording_label_ch_15, LV_LABEL_LONG_WRAP);
	lv_obj_set_pos(ui->screenRecording_label_ch_15, 137, 5);
	lv_obj_set_size(ui->screenRecording_label_ch_15, 66, 32);

	//Write style for screenRecording_label_ch_15, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->screenRecording_label_ch_15, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->screenRecording_label_ch_15, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->screenRecording_label_ch_15, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->screenRecording_label_ch_15, &lv_font_MontserratRegular_20, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->screenRecording_label_ch_15, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_line_space(ui->screenRecording_label_ch_15, 1, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->screenRecording_label_ch_15, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->screenRecording_label_ch_15, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->screenRecording_label_ch_15, 7, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->screenRecording_label_ch_15, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->screenRecording_label_ch_15, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->screenRecording_label_ch_15, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->screenRecording_label_ch_15, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes screenRecording_label_spk_15
	ui->screenRecording_label_spk_15 = lv_label_create(ui->screenRecording_cont_ch15);
	lv_label_set_text(ui->screenRecording_label_spk_15, "");
	lv_label_set_long_mode(ui->screenRecording_label_spk_15, LV_LABEL_LONG_WRAP);
	lv_obj_set_pos(ui->screenRecording_label_spk_15, 100, 4);
	lv_obj_set_size(ui->screenRecording_label_spk_15, 25, 32);

	//Write style for screenRecording_label_spk_15, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->screenRecording_label_spk_15, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->screenRecording_label_spk_15, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->screenRecording_label_spk_15, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->screenRecording_label_spk_15, &lv_font_FontAwesome5ProRegular_400_22, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->screenRecording_label_spk_15, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_line_space(ui->screenRecording_label_spk_15, 1, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->screenRecording_label_spk_15, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->screenRecording_label_spk_15, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->screenRecording_label_spk_15, 6, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->screenRecording_label_spk_15, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->screenRecording_label_spk_15, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->screenRecording_label_spk_15, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->screenRecording_label_spk_15, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes screenRecording_sw_15
	ui->screenRecording_sw_15 = lv_switch_create(ui->screenRecording_cont_ch15);
	lv_obj_set_pos(ui->screenRecording_sw_15, 46, 12);
	lv_obj_set_size(ui->screenRecording_sw_15, 40, 20);

	//Write style for screenRecording_sw_15, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_bg_opa(ui->screenRecording_sw_15, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui->screenRecording_sw_15, lv_color_hex(0x41485a), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_width(ui->screenRecording_sw_15, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->screenRecording_sw_15, 10, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->screenRecording_sw_15, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write style for screenRecording_sw_15, Part: LV_PART_INDICATOR, State: LV_STATE_CHECKED.
	lv_obj_set_style_bg_opa(ui->screenRecording_sw_15, 255, LV_PART_INDICATOR|LV_STATE_CHECKED);
	lv_obj_set_style_bg_color(ui->screenRecording_sw_15, lv_color_hex(0x2195f6), LV_PART_INDICATOR|LV_STATE_CHECKED);
	lv_obj_set_style_border_width(ui->screenRecording_sw_15, 0, LV_PART_INDICATOR|LV_STATE_CHECKED);

	//Write style for screenRecording_sw_15, Part: LV_PART_KNOB, State: LV_STATE_DEFAULT.
	lv_obj_set_style_bg_opa(ui->screenRecording_sw_15, 255, LV_PART_KNOB|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui->screenRecording_sw_15, lv_color_hex(0x292831), LV_PART_KNOB|LV_STATE_DEFAULT);
	lv_obj_set_style_border_width(ui->screenRecording_sw_15, 0, LV_PART_KNOB|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->screenRecording_sw_15, 10, LV_PART_KNOB|LV_STATE_DEFAULT);

	//Write codes screenRecording_label_67
	ui->screenRecording_label_67 = lv_label_create(ui->screenRecording_cont_ch15);
	lv_label_set_text(ui->screenRecording_label_67, "15");
	lv_label_set_long_mode(ui->screenRecording_label_67, LV_LABEL_LONG_WRAP);
	lv_obj_set_pos(ui->screenRecording_label_67, 4, 5);
	lv_obj_set_size(ui->screenRecording_label_67, 35, 32);

	//Write style for screenRecording_label_67, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->screenRecording_label_67, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->screenRecording_label_67, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->screenRecording_label_67, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->screenRecording_label_67, &lv_font_montserratMedium_24, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->screenRecording_label_67, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_line_space(ui->screenRecording_label_67, 1, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->screenRecording_label_67, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->screenRecording_label_67, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->screenRecording_label_67, 5, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->screenRecording_label_67, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->screenRecording_label_67, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->screenRecording_label_67, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->screenRecording_label_67, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes screenRecording_cont_ch16
	ui->screenRecording_cont_ch16 = lv_obj_create(ui->screenRecording_cont_10);
	lv_obj_set_pos(ui->screenRecording_cont_ch16, 13, 755);
	lv_obj_set_size(ui->screenRecording_cont_ch16, 210, 46);
	lv_obj_set_scrollbar_mode(ui->screenRecording_cont_ch16, LV_SCROLLBAR_MODE_OFF);

	//Write style for screenRecording_cont_ch16, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->screenRecording_cont_ch16, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_opa(ui->screenRecording_cont_ch16, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_color(ui->screenRecording_cont_ch16, lv_color_hex(0x2195f6), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_side(ui->screenRecording_cont_ch16, LV_BORDER_SIDE_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->screenRecording_cont_ch16, 4, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->screenRecording_cont_ch16, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui->screenRecording_cont_ch16, lv_color_hex(0x292831), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->screenRecording_cont_ch16, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->screenRecording_cont_ch16, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->screenRecording_cont_ch16, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->screenRecording_cont_ch16, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->screenRecording_cont_ch16, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes screenRecording_label_ch_16
	ui->screenRecording_label_ch_16 = lv_label_create(ui->screenRecording_cont_ch16);
	lv_label_set_text(ui->screenRecording_label_ch_16, "CH: 31");
	lv_label_set_long_mode(ui->screenRecording_label_ch_16, LV_LABEL_LONG_WRAP);
	lv_obj_set_pos(ui->screenRecording_label_ch_16, 137, 5);
	lv_obj_set_size(ui->screenRecording_label_ch_16, 66, 32);

	//Write style for screenRecording_label_ch_16, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->screenRecording_label_ch_16, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->screenRecording_label_ch_16, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->screenRecording_label_ch_16, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->screenRecording_label_ch_16, &lv_font_MontserratRegular_20, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->screenRecording_label_ch_16, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_line_space(ui->screenRecording_label_ch_16, 1, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->screenRecording_label_ch_16, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->screenRecording_label_ch_16, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->screenRecording_label_ch_16, 7, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->screenRecording_label_ch_16, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->screenRecording_label_ch_16, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->screenRecording_label_ch_16, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->screenRecording_label_ch_16, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes screenRecording_label_spk_16
	ui->screenRecording_label_spk_16 = lv_label_create(ui->screenRecording_cont_ch16);
	lv_label_set_text(ui->screenRecording_label_spk_16, "");
	lv_label_set_long_mode(ui->screenRecording_label_spk_16, LV_LABEL_LONG_WRAP);
	lv_obj_set_pos(ui->screenRecording_label_spk_16, 100, 4);
	lv_obj_set_size(ui->screenRecording_label_spk_16, 25, 32);

	//Write style for screenRecording_label_spk_16, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->screenRecording_label_spk_16, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->screenRecording_label_spk_16, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->screenRecording_label_spk_16, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->screenRecording_label_spk_16, &lv_font_FontAwesome5ProRegular_400_22, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->screenRecording_label_spk_16, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_line_space(ui->screenRecording_label_spk_16, 1, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->screenRecording_label_spk_16, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->screenRecording_label_spk_16, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->screenRecording_label_spk_16, 6, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->screenRecording_label_spk_16, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->screenRecording_label_spk_16, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->screenRecording_label_spk_16, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->screenRecording_label_spk_16, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes screenRecording_sw_16
	ui->screenRecording_sw_16 = lv_switch_create(ui->screenRecording_cont_ch16);
	lv_obj_set_pos(ui->screenRecording_sw_16, 46, 12);
	lv_obj_set_size(ui->screenRecording_sw_16, 40, 20);

	//Write style for screenRecording_sw_16, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_bg_opa(ui->screenRecording_sw_16, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui->screenRecording_sw_16, lv_color_hex(0x41485a), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_width(ui->screenRecording_sw_16, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->screenRecording_sw_16, 10, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->screenRecording_sw_16, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write style for screenRecording_sw_16, Part: LV_PART_INDICATOR, State: LV_STATE_CHECKED.
	lv_obj_set_style_bg_opa(ui->screenRecording_sw_16, 255, LV_PART_INDICATOR|LV_STATE_CHECKED);
	lv_obj_set_style_bg_color(ui->screenRecording_sw_16, lv_color_hex(0x2195f6), LV_PART_INDICATOR|LV_STATE_CHECKED);
	lv_obj_set_style_border_width(ui->screenRecording_sw_16, 0, LV_PART_INDICATOR|LV_STATE_CHECKED);

	//Write style for screenRecording_sw_16, Part: LV_PART_KNOB, State: LV_STATE_DEFAULT.
	lv_obj_set_style_bg_opa(ui->screenRecording_sw_16, 255, LV_PART_KNOB|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui->screenRecording_sw_16, lv_color_hex(0x292831), LV_PART_KNOB|LV_STATE_DEFAULT);
	lv_obj_set_style_border_width(ui->screenRecording_sw_16, 0, LV_PART_KNOB|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->screenRecording_sw_16, 10, LV_PART_KNOB|LV_STATE_DEFAULT);

	//Write codes screenRecording_label_70
	ui->screenRecording_label_70 = lv_label_create(ui->screenRecording_cont_ch16);
	lv_label_set_text(ui->screenRecording_label_70, "16\n");
	lv_label_set_long_mode(ui->screenRecording_label_70, LV_LABEL_LONG_WRAP);
	lv_obj_set_pos(ui->screenRecording_label_70, 4, 5);
	lv_obj_set_size(ui->screenRecording_label_70, 35, 32);

	//Write style for screenRecording_label_70, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->screenRecording_label_70, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->screenRecording_label_70, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->screenRecording_label_70, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->screenRecording_label_70, &lv_font_montserratMedium_24, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->screenRecording_label_70, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_line_space(ui->screenRecording_label_70, 1, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->screenRecording_label_70, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->screenRecording_label_70, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->screenRecording_label_70, 5, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->screenRecording_label_70, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->screenRecording_label_70, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->screenRecording_label_70, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->screenRecording_label_70, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes screenRecording_cont_ch17
	ui->screenRecording_cont_ch17 = lv_obj_create(ui->screenRecording_cont_10);
	lv_obj_set_pos(ui->screenRecording_cont_ch17, 13, 805);
	lv_obj_set_size(ui->screenRecording_cont_ch17, 210, 46);
	lv_obj_set_scrollbar_mode(ui->screenRecording_cont_ch17, LV_SCROLLBAR_MODE_OFF);

	//Write style for screenRecording_cont_ch17, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->screenRecording_cont_ch17, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_opa(ui->screenRecording_cont_ch17, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_color(ui->screenRecording_cont_ch17, lv_color_hex(0x2195f6), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_side(ui->screenRecording_cont_ch17, LV_BORDER_SIDE_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->screenRecording_cont_ch17, 4, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->screenRecording_cont_ch17, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui->screenRecording_cont_ch17, lv_color_hex(0x292831), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->screenRecording_cont_ch17, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->screenRecording_cont_ch17, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->screenRecording_cont_ch17, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->screenRecording_cont_ch17, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->screenRecording_cont_ch17, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes screenRecording_label_ch_17
	ui->screenRecording_label_ch_17 = lv_label_create(ui->screenRecording_cont_ch17);
	lv_label_set_text(ui->screenRecording_label_ch_17, "CH: 31");
	lv_label_set_long_mode(ui->screenRecording_label_ch_17, LV_LABEL_LONG_WRAP);
	lv_obj_set_pos(ui->screenRecording_label_ch_17, 137, 5);
	lv_obj_set_size(ui->screenRecording_label_ch_17, 66, 32);

	//Write style for screenRecording_label_ch_17, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->screenRecording_label_ch_17, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->screenRecording_label_ch_17, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->screenRecording_label_ch_17, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->screenRecording_label_ch_17, &lv_font_MontserratRegular_20, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->screenRecording_label_ch_17, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_line_space(ui->screenRecording_label_ch_17, 1, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->screenRecording_label_ch_17, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->screenRecording_label_ch_17, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->screenRecording_label_ch_17, 7, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->screenRecording_label_ch_17, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->screenRecording_label_ch_17, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->screenRecording_label_ch_17, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->screenRecording_label_ch_17, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes screenRecording_label_spk_17
	ui->screenRecording_label_spk_17 = lv_label_create(ui->screenRecording_cont_ch17);
	lv_label_set_text(ui->screenRecording_label_spk_17, "");
	lv_label_set_long_mode(ui->screenRecording_label_spk_17, LV_LABEL_LONG_WRAP);
	lv_obj_set_pos(ui->screenRecording_label_spk_17, 100, 4);
	lv_obj_set_size(ui->screenRecording_label_spk_17, 25, 32);

	//Write style for screenRecording_label_spk_17, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->screenRecording_label_spk_17, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->screenRecording_label_spk_17, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->screenRecording_label_spk_17, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->screenRecording_label_spk_17, &lv_font_FontAwesome5ProRegular_400_22, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->screenRecording_label_spk_17, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_line_space(ui->screenRecording_label_spk_17, 1, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->screenRecording_label_spk_17, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->screenRecording_label_spk_17, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->screenRecording_label_spk_17, 6, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->screenRecording_label_spk_17, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->screenRecording_label_spk_17, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->screenRecording_label_spk_17, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->screenRecording_label_spk_17, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes screenRecording_sw_17
	ui->screenRecording_sw_17 = lv_switch_create(ui->screenRecording_cont_ch17);
	lv_obj_set_pos(ui->screenRecording_sw_17, 46, 12);
	lv_obj_set_size(ui->screenRecording_sw_17, 40, 20);

	//Write style for screenRecording_sw_17, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_bg_opa(ui->screenRecording_sw_17, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui->screenRecording_sw_17, lv_color_hex(0x41485a), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_width(ui->screenRecording_sw_17, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->screenRecording_sw_17, 10, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->screenRecording_sw_17, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write style for screenRecording_sw_17, Part: LV_PART_INDICATOR, State: LV_STATE_CHECKED.
	lv_obj_set_style_bg_opa(ui->screenRecording_sw_17, 255, LV_PART_INDICATOR|LV_STATE_CHECKED);
	lv_obj_set_style_bg_color(ui->screenRecording_sw_17, lv_color_hex(0x2195f6), LV_PART_INDICATOR|LV_STATE_CHECKED);
	lv_obj_set_style_border_width(ui->screenRecording_sw_17, 0, LV_PART_INDICATOR|LV_STATE_CHECKED);

	//Write style for screenRecording_sw_17, Part: LV_PART_KNOB, State: LV_STATE_DEFAULT.
	lv_obj_set_style_bg_opa(ui->screenRecording_sw_17, 255, LV_PART_KNOB|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui->screenRecording_sw_17, lv_color_hex(0x292831), LV_PART_KNOB|LV_STATE_DEFAULT);
	lv_obj_set_style_border_width(ui->screenRecording_sw_17, 0, LV_PART_KNOB|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->screenRecording_sw_17, 10, LV_PART_KNOB|LV_STATE_DEFAULT);

	//Write codes screenRecording_label_73
	ui->screenRecording_label_73 = lv_label_create(ui->screenRecording_cont_ch17);
	lv_label_set_text(ui->screenRecording_label_73, "17\n");
	lv_label_set_long_mode(ui->screenRecording_label_73, LV_LABEL_LONG_WRAP);
	lv_obj_set_pos(ui->screenRecording_label_73, 4, 5);
	lv_obj_set_size(ui->screenRecording_label_73, 35, 32);

	//Write style for screenRecording_label_73, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->screenRecording_label_73, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->screenRecording_label_73, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->screenRecording_label_73, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->screenRecording_label_73, &lv_font_montserratMedium_24, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->screenRecording_label_73, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_line_space(ui->screenRecording_label_73, 1, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->screenRecording_label_73, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->screenRecording_label_73, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->screenRecording_label_73, 5, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->screenRecording_label_73, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->screenRecording_label_73, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->screenRecording_label_73, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->screenRecording_label_73, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes screenRecording_cont_ch18
	ui->screenRecording_cont_ch18 = lv_obj_create(ui->screenRecording_cont_10);
	lv_obj_set_pos(ui->screenRecording_cont_ch18, 13, 855);
	lv_obj_set_size(ui->screenRecording_cont_ch18, 210, 46);
	lv_obj_set_scrollbar_mode(ui->screenRecording_cont_ch18, LV_SCROLLBAR_MODE_OFF);

	//Write style for screenRecording_cont_ch18, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->screenRecording_cont_ch18, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_opa(ui->screenRecording_cont_ch18, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_color(ui->screenRecording_cont_ch18, lv_color_hex(0x2195f6), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_side(ui->screenRecording_cont_ch18, LV_BORDER_SIDE_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->screenRecording_cont_ch18, 4, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->screenRecording_cont_ch18, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui->screenRecording_cont_ch18, lv_color_hex(0x292831), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->screenRecording_cont_ch18, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->screenRecording_cont_ch18, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->screenRecording_cont_ch18, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->screenRecording_cont_ch18, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->screenRecording_cont_ch18, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes screenRecording_label_ch_18
	ui->screenRecording_label_ch_18 = lv_label_create(ui->screenRecording_cont_ch18);
	lv_label_set_text(ui->screenRecording_label_ch_18, "CH: 31");
	lv_label_set_long_mode(ui->screenRecording_label_ch_18, LV_LABEL_LONG_WRAP);
	lv_obj_set_pos(ui->screenRecording_label_ch_18, 137, 5);
	lv_obj_set_size(ui->screenRecording_label_ch_18, 66, 32);

	//Write style for screenRecording_label_ch_18, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->screenRecording_label_ch_18, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->screenRecording_label_ch_18, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->screenRecording_label_ch_18, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->screenRecording_label_ch_18, &lv_font_MontserratRegular_20, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->screenRecording_label_ch_18, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_line_space(ui->screenRecording_label_ch_18, 1, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->screenRecording_label_ch_18, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->screenRecording_label_ch_18, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->screenRecording_label_ch_18, 7, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->screenRecording_label_ch_18, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->screenRecording_label_ch_18, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->screenRecording_label_ch_18, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->screenRecording_label_ch_18, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes screenRecording_label_spk_18
	ui->screenRecording_label_spk_18 = lv_label_create(ui->screenRecording_cont_ch18);
	lv_label_set_text(ui->screenRecording_label_spk_18, "");
	lv_label_set_long_mode(ui->screenRecording_label_spk_18, LV_LABEL_LONG_WRAP);
	lv_obj_set_pos(ui->screenRecording_label_spk_18, 100, 4);
	lv_obj_set_size(ui->screenRecording_label_spk_18, 25, 32);

	//Write style for screenRecording_label_spk_18, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->screenRecording_label_spk_18, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->screenRecording_label_spk_18, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->screenRecording_label_spk_18, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->screenRecording_label_spk_18, &lv_font_FontAwesome5ProRegular_400_22, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->screenRecording_label_spk_18, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_line_space(ui->screenRecording_label_spk_18, 1, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->screenRecording_label_spk_18, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->screenRecording_label_spk_18, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->screenRecording_label_spk_18, 6, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->screenRecording_label_spk_18, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->screenRecording_label_spk_18, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->screenRecording_label_spk_18, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->screenRecording_label_spk_18, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes screenRecording_sw_18
	ui->screenRecording_sw_18 = lv_switch_create(ui->screenRecording_cont_ch18);
	lv_obj_set_pos(ui->screenRecording_sw_18, 46, 12);
	lv_obj_set_size(ui->screenRecording_sw_18, 40, 20);

	//Write style for screenRecording_sw_18, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_bg_opa(ui->screenRecording_sw_18, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui->screenRecording_sw_18, lv_color_hex(0x41485a), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_width(ui->screenRecording_sw_18, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->screenRecording_sw_18, 10, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->screenRecording_sw_18, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write style for screenRecording_sw_18, Part: LV_PART_INDICATOR, State: LV_STATE_CHECKED.
	lv_obj_set_style_bg_opa(ui->screenRecording_sw_18, 255, LV_PART_INDICATOR|LV_STATE_CHECKED);
	lv_obj_set_style_bg_color(ui->screenRecording_sw_18, lv_color_hex(0x2195f6), LV_PART_INDICATOR|LV_STATE_CHECKED);
	lv_obj_set_style_border_width(ui->screenRecording_sw_18, 0, LV_PART_INDICATOR|LV_STATE_CHECKED);

	//Write style for screenRecording_sw_18, Part: LV_PART_KNOB, State: LV_STATE_DEFAULT.
	lv_obj_set_style_bg_opa(ui->screenRecording_sw_18, 255, LV_PART_KNOB|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui->screenRecording_sw_18, lv_color_hex(0x292831), LV_PART_KNOB|LV_STATE_DEFAULT);
	lv_obj_set_style_border_width(ui->screenRecording_sw_18, 0, LV_PART_KNOB|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->screenRecording_sw_18, 10, LV_PART_KNOB|LV_STATE_DEFAULT);

	//Write codes screenRecording_label_76
	ui->screenRecording_label_76 = lv_label_create(ui->screenRecording_cont_ch18);
	lv_label_set_text(ui->screenRecording_label_76, "18\n");
	lv_label_set_long_mode(ui->screenRecording_label_76, LV_LABEL_LONG_WRAP);
	lv_obj_set_pos(ui->screenRecording_label_76, 4, 5);
	lv_obj_set_size(ui->screenRecording_label_76, 35, 32);

	//Write style for screenRecording_label_76, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->screenRecording_label_76, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->screenRecording_label_76, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->screenRecording_label_76, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->screenRecording_label_76, &lv_font_montserratMedium_24, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->screenRecording_label_76, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_line_space(ui->screenRecording_label_76, 1, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->screenRecording_label_76, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->screenRecording_label_76, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->screenRecording_label_76, 5, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->screenRecording_label_76, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->screenRecording_label_76, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->screenRecording_label_76, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->screenRecording_label_76, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes screenRecording_cont_ch19
	ui->screenRecording_cont_ch19 = lv_obj_create(ui->screenRecording_cont_10);
	lv_obj_set_pos(ui->screenRecording_cont_ch19, 13, 905);
	lv_obj_set_size(ui->screenRecording_cont_ch19, 210, 46);
	lv_obj_set_scrollbar_mode(ui->screenRecording_cont_ch19, LV_SCROLLBAR_MODE_OFF);

	//Write style for screenRecording_cont_ch19, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->screenRecording_cont_ch19, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_opa(ui->screenRecording_cont_ch19, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_color(ui->screenRecording_cont_ch19, lv_color_hex(0x2195f6), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_side(ui->screenRecording_cont_ch19, LV_BORDER_SIDE_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->screenRecording_cont_ch19, 4, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->screenRecording_cont_ch19, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui->screenRecording_cont_ch19, lv_color_hex(0x292831), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->screenRecording_cont_ch19, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->screenRecording_cont_ch19, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->screenRecording_cont_ch19, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->screenRecording_cont_ch19, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->screenRecording_cont_ch19, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes screenRecording_label_ch_19
	ui->screenRecording_label_ch_19 = lv_label_create(ui->screenRecording_cont_ch19);
	lv_label_set_text(ui->screenRecording_label_ch_19, "CH: 31");
	lv_label_set_long_mode(ui->screenRecording_label_ch_19, LV_LABEL_LONG_WRAP);
	lv_obj_set_pos(ui->screenRecording_label_ch_19, 137, 5);
	lv_obj_set_size(ui->screenRecording_label_ch_19, 66, 32);

	//Write style for screenRecording_label_ch_19, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->screenRecording_label_ch_19, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->screenRecording_label_ch_19, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->screenRecording_label_ch_19, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->screenRecording_label_ch_19, &lv_font_MontserratRegular_20, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->screenRecording_label_ch_19, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_line_space(ui->screenRecording_label_ch_19, 1, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->screenRecording_label_ch_19, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->screenRecording_label_ch_19, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->screenRecording_label_ch_19, 7, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->screenRecording_label_ch_19, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->screenRecording_label_ch_19, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->screenRecording_label_ch_19, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->screenRecording_label_ch_19, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes screenRecording_label_spk_19
	ui->screenRecording_label_spk_19 = lv_label_create(ui->screenRecording_cont_ch19);
	lv_label_set_text(ui->screenRecording_label_spk_19, "");
	lv_label_set_long_mode(ui->screenRecording_label_spk_19, LV_LABEL_LONG_WRAP);
	lv_obj_set_pos(ui->screenRecording_label_spk_19, 100, 4);
	lv_obj_set_size(ui->screenRecording_label_spk_19, 25, 32);

	//Write style for screenRecording_label_spk_19, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->screenRecording_label_spk_19, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->screenRecording_label_spk_19, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->screenRecording_label_spk_19, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->screenRecording_label_spk_19, &lv_font_FontAwesome5ProRegular_400_22, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->screenRecording_label_spk_19, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_line_space(ui->screenRecording_label_spk_19, 1, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->screenRecording_label_spk_19, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->screenRecording_label_spk_19, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->screenRecording_label_spk_19, 6, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->screenRecording_label_spk_19, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->screenRecording_label_spk_19, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->screenRecording_label_spk_19, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->screenRecording_label_spk_19, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes screenRecording_sw_19
	ui->screenRecording_sw_19 = lv_switch_create(ui->screenRecording_cont_ch19);
	lv_obj_set_pos(ui->screenRecording_sw_19, 46, 12);
	lv_obj_set_size(ui->screenRecording_sw_19, 40, 20);

	//Write style for screenRecording_sw_19, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_bg_opa(ui->screenRecording_sw_19, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui->screenRecording_sw_19, lv_color_hex(0x41485a), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_width(ui->screenRecording_sw_19, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->screenRecording_sw_19, 10, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->screenRecording_sw_19, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write style for screenRecording_sw_19, Part: LV_PART_INDICATOR, State: LV_STATE_CHECKED.
	lv_obj_set_style_bg_opa(ui->screenRecording_sw_19, 255, LV_PART_INDICATOR|LV_STATE_CHECKED);
	lv_obj_set_style_bg_color(ui->screenRecording_sw_19, lv_color_hex(0x2195f6), LV_PART_INDICATOR|LV_STATE_CHECKED);
	lv_obj_set_style_border_width(ui->screenRecording_sw_19, 0, LV_PART_INDICATOR|LV_STATE_CHECKED);

	//Write style for screenRecording_sw_19, Part: LV_PART_KNOB, State: LV_STATE_DEFAULT.
	lv_obj_set_style_bg_opa(ui->screenRecording_sw_19, 255, LV_PART_KNOB|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui->screenRecording_sw_19, lv_color_hex(0x292831), LV_PART_KNOB|LV_STATE_DEFAULT);
	lv_obj_set_style_border_width(ui->screenRecording_sw_19, 0, LV_PART_KNOB|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->screenRecording_sw_19, 10, LV_PART_KNOB|LV_STATE_DEFAULT);

	//Write codes screenRecording_label_79
	ui->screenRecording_label_79 = lv_label_create(ui->screenRecording_cont_ch19);
	lv_label_set_text(ui->screenRecording_label_79, "19\n");
	lv_label_set_long_mode(ui->screenRecording_label_79, LV_LABEL_LONG_WRAP);
	lv_obj_set_pos(ui->screenRecording_label_79, 4, 5);
	lv_obj_set_size(ui->screenRecording_label_79, 35, 32);

	//Write style for screenRecording_label_79, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->screenRecording_label_79, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->screenRecording_label_79, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->screenRecording_label_79, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->screenRecording_label_79, &lv_font_montserratMedium_24, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->screenRecording_label_79, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_line_space(ui->screenRecording_label_79, 1, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->screenRecording_label_79, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->screenRecording_label_79, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->screenRecording_label_79, 5, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->screenRecording_label_79, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->screenRecording_label_79, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->screenRecording_label_79, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->screenRecording_label_79, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes screenRecording_cont_ch20
	ui->screenRecording_cont_ch20 = lv_obj_create(ui->screenRecording_cont_10);
	lv_obj_set_pos(ui->screenRecording_cont_ch20, 13, 955);
	lv_obj_set_size(ui->screenRecording_cont_ch20, 210, 46);
	lv_obj_set_scrollbar_mode(ui->screenRecording_cont_ch20, LV_SCROLLBAR_MODE_OFF);

	//Write style for screenRecording_cont_ch20, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->screenRecording_cont_ch20, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_opa(ui->screenRecording_cont_ch20, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_color(ui->screenRecording_cont_ch20, lv_color_hex(0x2195f6), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_side(ui->screenRecording_cont_ch20, LV_BORDER_SIDE_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->screenRecording_cont_ch20, 4, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->screenRecording_cont_ch20, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui->screenRecording_cont_ch20, lv_color_hex(0x292831), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->screenRecording_cont_ch20, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->screenRecording_cont_ch20, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->screenRecording_cont_ch20, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->screenRecording_cont_ch20, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->screenRecording_cont_ch20, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes screenRecording_label_ch_20
	ui->screenRecording_label_ch_20 = lv_label_create(ui->screenRecording_cont_ch20);
	lv_label_set_text(ui->screenRecording_label_ch_20, "CH: 31");
	lv_label_set_long_mode(ui->screenRecording_label_ch_20, LV_LABEL_LONG_WRAP);
	lv_obj_set_pos(ui->screenRecording_label_ch_20, 137, 5);
	lv_obj_set_size(ui->screenRecording_label_ch_20, 66, 32);

	//Write style for screenRecording_label_ch_20, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->screenRecording_label_ch_20, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->screenRecording_label_ch_20, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->screenRecording_label_ch_20, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->screenRecording_label_ch_20, &lv_font_MontserratRegular_20, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->screenRecording_label_ch_20, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_line_space(ui->screenRecording_label_ch_20, 1, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->screenRecording_label_ch_20, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->screenRecording_label_ch_20, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->screenRecording_label_ch_20, 7, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->screenRecording_label_ch_20, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->screenRecording_label_ch_20, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->screenRecording_label_ch_20, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->screenRecording_label_ch_20, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes screenRecording_label_spk_20
	ui->screenRecording_label_spk_20 = lv_label_create(ui->screenRecording_cont_ch20);
	lv_label_set_text(ui->screenRecording_label_spk_20, "");
	lv_label_set_long_mode(ui->screenRecording_label_spk_20, LV_LABEL_LONG_WRAP);
	lv_obj_set_pos(ui->screenRecording_label_spk_20, 100, 4);
	lv_obj_set_size(ui->screenRecording_label_spk_20, 25, 32);

	//Write style for screenRecording_label_spk_20, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->screenRecording_label_spk_20, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->screenRecording_label_spk_20, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->screenRecording_label_spk_20, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->screenRecording_label_spk_20, &lv_font_FontAwesome5ProRegular_400_22, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->screenRecording_label_spk_20, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_line_space(ui->screenRecording_label_spk_20, 1, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->screenRecording_label_spk_20, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->screenRecording_label_spk_20, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->screenRecording_label_spk_20, 6, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->screenRecording_label_spk_20, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->screenRecording_label_spk_20, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->screenRecording_label_spk_20, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->screenRecording_label_spk_20, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes screenRecording_sw_20
	ui->screenRecording_sw_20 = lv_switch_create(ui->screenRecording_cont_ch20);
	lv_obj_set_pos(ui->screenRecording_sw_20, 46, 12);
	lv_obj_set_size(ui->screenRecording_sw_20, 40, 20);

	//Write style for screenRecording_sw_20, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_bg_opa(ui->screenRecording_sw_20, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui->screenRecording_sw_20, lv_color_hex(0x41485a), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_width(ui->screenRecording_sw_20, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->screenRecording_sw_20, 10, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->screenRecording_sw_20, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write style for screenRecording_sw_20, Part: LV_PART_INDICATOR, State: LV_STATE_CHECKED.
	lv_obj_set_style_bg_opa(ui->screenRecording_sw_20, 255, LV_PART_INDICATOR|LV_STATE_CHECKED);
	lv_obj_set_style_bg_color(ui->screenRecording_sw_20, lv_color_hex(0x2195f6), LV_PART_INDICATOR|LV_STATE_CHECKED);
	lv_obj_set_style_border_width(ui->screenRecording_sw_20, 0, LV_PART_INDICATOR|LV_STATE_CHECKED);

	//Write style for screenRecording_sw_20, Part: LV_PART_KNOB, State: LV_STATE_DEFAULT.
	lv_obj_set_style_bg_opa(ui->screenRecording_sw_20, 255, LV_PART_KNOB|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui->screenRecording_sw_20, lv_color_hex(0x292831), LV_PART_KNOB|LV_STATE_DEFAULT);
	lv_obj_set_style_border_width(ui->screenRecording_sw_20, 0, LV_PART_KNOB|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->screenRecording_sw_20, 10, LV_PART_KNOB|LV_STATE_DEFAULT);

	//Write codes screenRecording_label_82
	ui->screenRecording_label_82 = lv_label_create(ui->screenRecording_cont_ch20);
	lv_label_set_text(ui->screenRecording_label_82, "20");
	lv_label_set_long_mode(ui->screenRecording_label_82, LV_LABEL_LONG_WRAP);
	lv_obj_set_pos(ui->screenRecording_label_82, 4, 5);
	lv_obj_set_size(ui->screenRecording_label_82, 35, 32);

	//Write style for screenRecording_label_82, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->screenRecording_label_82, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->screenRecording_label_82, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->screenRecording_label_82, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->screenRecording_label_82, &lv_font_montserratMedium_24, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->screenRecording_label_82, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_line_space(ui->screenRecording_label_82, 1, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->screenRecording_label_82, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->screenRecording_label_82, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->screenRecording_label_82, 5, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->screenRecording_label_82, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->screenRecording_label_82, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->screenRecording_label_82, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->screenRecording_label_82, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes screenRecording_cont_ch21
	ui->screenRecording_cont_ch21 = lv_obj_create(ui->screenRecording_cont_10);
	lv_obj_set_pos(ui->screenRecording_cont_ch21, 13, 1005);
	lv_obj_set_size(ui->screenRecording_cont_ch21, 210, 46);
	lv_obj_set_scrollbar_mode(ui->screenRecording_cont_ch21, LV_SCROLLBAR_MODE_OFF);

	//Write style for screenRecording_cont_ch21, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->screenRecording_cont_ch21, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_opa(ui->screenRecording_cont_ch21, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_color(ui->screenRecording_cont_ch21, lv_color_hex(0x2195f6), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_side(ui->screenRecording_cont_ch21, LV_BORDER_SIDE_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->screenRecording_cont_ch21, 4, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->screenRecording_cont_ch21, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui->screenRecording_cont_ch21, lv_color_hex(0x292831), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->screenRecording_cont_ch21, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->screenRecording_cont_ch21, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->screenRecording_cont_ch21, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->screenRecording_cont_ch21, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->screenRecording_cont_ch21, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes screenRecording_label_ch_21
	ui->screenRecording_label_ch_21 = lv_label_create(ui->screenRecording_cont_ch21);
	lv_label_set_text(ui->screenRecording_label_ch_21, "CH: 31");
	lv_label_set_long_mode(ui->screenRecording_label_ch_21, LV_LABEL_LONG_WRAP);
	lv_obj_set_pos(ui->screenRecording_label_ch_21, 137, 5);
	lv_obj_set_size(ui->screenRecording_label_ch_21, 66, 32);

	//Write style for screenRecording_label_ch_21, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->screenRecording_label_ch_21, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->screenRecording_label_ch_21, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->screenRecording_label_ch_21, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->screenRecording_label_ch_21, &lv_font_MontserratRegular_20, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->screenRecording_label_ch_21, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_line_space(ui->screenRecording_label_ch_21, 1, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->screenRecording_label_ch_21, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->screenRecording_label_ch_21, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->screenRecording_label_ch_21, 7, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->screenRecording_label_ch_21, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->screenRecording_label_ch_21, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->screenRecording_label_ch_21, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->screenRecording_label_ch_21, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes screenRecording_label_spk_21
	ui->screenRecording_label_spk_21 = lv_label_create(ui->screenRecording_cont_ch21);
	lv_label_set_text(ui->screenRecording_label_spk_21, "");
	lv_label_set_long_mode(ui->screenRecording_label_spk_21, LV_LABEL_LONG_WRAP);
	lv_obj_set_pos(ui->screenRecording_label_spk_21, 100, 4);
	lv_obj_set_size(ui->screenRecording_label_spk_21, 25, 32);

	//Write style for screenRecording_label_spk_21, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->screenRecording_label_spk_21, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->screenRecording_label_spk_21, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->screenRecording_label_spk_21, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->screenRecording_label_spk_21, &lv_font_FontAwesome5ProRegular_400_22, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->screenRecording_label_spk_21, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_line_space(ui->screenRecording_label_spk_21, 1, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->screenRecording_label_spk_21, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->screenRecording_label_spk_21, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->screenRecording_label_spk_21, 6, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->screenRecording_label_spk_21, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->screenRecording_label_spk_21, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->screenRecording_label_spk_21, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->screenRecording_label_spk_21, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes screenRecording_sw_21
	ui->screenRecording_sw_21 = lv_switch_create(ui->screenRecording_cont_ch21);
	lv_obj_set_pos(ui->screenRecording_sw_21, 46, 12);
	lv_obj_set_size(ui->screenRecording_sw_21, 40, 20);

	//Write style for screenRecording_sw_21, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_bg_opa(ui->screenRecording_sw_21, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui->screenRecording_sw_21, lv_color_hex(0x41485a), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_width(ui->screenRecording_sw_21, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->screenRecording_sw_21, 10, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->screenRecording_sw_21, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write style for screenRecording_sw_21, Part: LV_PART_INDICATOR, State: LV_STATE_CHECKED.
	lv_obj_set_style_bg_opa(ui->screenRecording_sw_21, 255, LV_PART_INDICATOR|LV_STATE_CHECKED);
	lv_obj_set_style_bg_color(ui->screenRecording_sw_21, lv_color_hex(0x2195f6), LV_PART_INDICATOR|LV_STATE_CHECKED);
	lv_obj_set_style_border_width(ui->screenRecording_sw_21, 0, LV_PART_INDICATOR|LV_STATE_CHECKED);

	//Write style for screenRecording_sw_21, Part: LV_PART_KNOB, State: LV_STATE_DEFAULT.
	lv_obj_set_style_bg_opa(ui->screenRecording_sw_21, 255, LV_PART_KNOB|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui->screenRecording_sw_21, lv_color_hex(0x292831), LV_PART_KNOB|LV_STATE_DEFAULT);
	lv_obj_set_style_border_width(ui->screenRecording_sw_21, 0, LV_PART_KNOB|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->screenRecording_sw_21, 10, LV_PART_KNOB|LV_STATE_DEFAULT);

	//Write codes screenRecording_label_85
	ui->screenRecording_label_85 = lv_label_create(ui->screenRecording_cont_ch21);
	lv_label_set_text(ui->screenRecording_label_85, "21");
	lv_label_set_long_mode(ui->screenRecording_label_85, LV_LABEL_LONG_WRAP);
	lv_obj_set_pos(ui->screenRecording_label_85, 4, 5);
	lv_obj_set_size(ui->screenRecording_label_85, 35, 32);

	//Write style for screenRecording_label_85, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->screenRecording_label_85, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->screenRecording_label_85, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->screenRecording_label_85, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->screenRecording_label_85, &lv_font_montserratMedium_24, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->screenRecording_label_85, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_line_space(ui->screenRecording_label_85, 1, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->screenRecording_label_85, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->screenRecording_label_85, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->screenRecording_label_85, 5, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->screenRecording_label_85, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->screenRecording_label_85, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->screenRecording_label_85, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->screenRecording_label_85, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes screenRecording_cont_ch22
	ui->screenRecording_cont_ch22 = lv_obj_create(ui->screenRecording_cont_10);
	lv_obj_set_pos(ui->screenRecording_cont_ch22, 13, 1055);
	lv_obj_set_size(ui->screenRecording_cont_ch22, 210, 46);
	lv_obj_set_scrollbar_mode(ui->screenRecording_cont_ch22, LV_SCROLLBAR_MODE_OFF);

	//Write style for screenRecording_cont_ch22, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->screenRecording_cont_ch22, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_opa(ui->screenRecording_cont_ch22, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_color(ui->screenRecording_cont_ch22, lv_color_hex(0x2195f6), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_side(ui->screenRecording_cont_ch22, LV_BORDER_SIDE_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->screenRecording_cont_ch22, 4, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->screenRecording_cont_ch22, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui->screenRecording_cont_ch22, lv_color_hex(0x292831), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->screenRecording_cont_ch22, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->screenRecording_cont_ch22, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->screenRecording_cont_ch22, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->screenRecording_cont_ch22, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->screenRecording_cont_ch22, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes screenRecording_label_ch_22
	ui->screenRecording_label_ch_22 = lv_label_create(ui->screenRecording_cont_ch22);
	lv_label_set_text(ui->screenRecording_label_ch_22, "CH: 31");
	lv_label_set_long_mode(ui->screenRecording_label_ch_22, LV_LABEL_LONG_WRAP);
	lv_obj_set_pos(ui->screenRecording_label_ch_22, 137, 5);
	lv_obj_set_size(ui->screenRecording_label_ch_22, 66, 32);

	//Write style for screenRecording_label_ch_22, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->screenRecording_label_ch_22, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->screenRecording_label_ch_22, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->screenRecording_label_ch_22, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->screenRecording_label_ch_22, &lv_font_MontserratRegular_20, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->screenRecording_label_ch_22, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_line_space(ui->screenRecording_label_ch_22, 1, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->screenRecording_label_ch_22, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->screenRecording_label_ch_22, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->screenRecording_label_ch_22, 7, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->screenRecording_label_ch_22, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->screenRecording_label_ch_22, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->screenRecording_label_ch_22, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->screenRecording_label_ch_22, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes screenRecording_label_spk_22
	ui->screenRecording_label_spk_22 = lv_label_create(ui->screenRecording_cont_ch22);
	lv_label_set_text(ui->screenRecording_label_spk_22, "");
	lv_label_set_long_mode(ui->screenRecording_label_spk_22, LV_LABEL_LONG_WRAP);
	lv_obj_set_pos(ui->screenRecording_label_spk_22, 100, 4);
	lv_obj_set_size(ui->screenRecording_label_spk_22, 25, 32);

	//Write style for screenRecording_label_spk_22, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->screenRecording_label_spk_22, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->screenRecording_label_spk_22, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->screenRecording_label_spk_22, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->screenRecording_label_spk_22, &lv_font_FontAwesome5ProRegular_400_22, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->screenRecording_label_spk_22, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_line_space(ui->screenRecording_label_spk_22, 1, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->screenRecording_label_spk_22, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->screenRecording_label_spk_22, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->screenRecording_label_spk_22, 6, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->screenRecording_label_spk_22, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->screenRecording_label_spk_22, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->screenRecording_label_spk_22, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->screenRecording_label_spk_22, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes screenRecording_sw_22
	ui->screenRecording_sw_22 = lv_switch_create(ui->screenRecording_cont_ch22);
	lv_obj_set_pos(ui->screenRecording_sw_22, 46, 12);
	lv_obj_set_size(ui->screenRecording_sw_22, 40, 20);

	//Write style for screenRecording_sw_22, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_bg_opa(ui->screenRecording_sw_22, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui->screenRecording_sw_22, lv_color_hex(0x41485a), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_width(ui->screenRecording_sw_22, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->screenRecording_sw_22, 10, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->screenRecording_sw_22, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write style for screenRecording_sw_22, Part: LV_PART_INDICATOR, State: LV_STATE_CHECKED.
	lv_obj_set_style_bg_opa(ui->screenRecording_sw_22, 255, LV_PART_INDICATOR|LV_STATE_CHECKED);
	lv_obj_set_style_bg_color(ui->screenRecording_sw_22, lv_color_hex(0x2195f6), LV_PART_INDICATOR|LV_STATE_CHECKED);
	lv_obj_set_style_border_width(ui->screenRecording_sw_22, 0, LV_PART_INDICATOR|LV_STATE_CHECKED);

	//Write style for screenRecording_sw_22, Part: LV_PART_KNOB, State: LV_STATE_DEFAULT.
	lv_obj_set_style_bg_opa(ui->screenRecording_sw_22, 255, LV_PART_KNOB|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui->screenRecording_sw_22, lv_color_hex(0x292831), LV_PART_KNOB|LV_STATE_DEFAULT);
	lv_obj_set_style_border_width(ui->screenRecording_sw_22, 0, LV_PART_KNOB|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->screenRecording_sw_22, 10, LV_PART_KNOB|LV_STATE_DEFAULT);

	//Write codes screenRecording_label_88
	ui->screenRecording_label_88 = lv_label_create(ui->screenRecording_cont_ch22);
	lv_label_set_text(ui->screenRecording_label_88, "22");
	lv_label_set_long_mode(ui->screenRecording_label_88, LV_LABEL_LONG_WRAP);
	lv_obj_set_pos(ui->screenRecording_label_88, 4, 5);
	lv_obj_set_size(ui->screenRecording_label_88, 35, 32);

	//Write style for screenRecording_label_88, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->screenRecording_label_88, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->screenRecording_label_88, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->screenRecording_label_88, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->screenRecording_label_88, &lv_font_montserratMedium_24, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->screenRecording_label_88, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_line_space(ui->screenRecording_label_88, 1, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->screenRecording_label_88, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->screenRecording_label_88, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->screenRecording_label_88, 5, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->screenRecording_label_88, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->screenRecording_label_88, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->screenRecording_label_88, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->screenRecording_label_88, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes screenRecording_cont_ch23
	ui->screenRecording_cont_ch23 = lv_obj_create(ui->screenRecording_cont_10);
	lv_obj_set_pos(ui->screenRecording_cont_ch23, 13, 1105);
	lv_obj_set_size(ui->screenRecording_cont_ch23, 210, 46);
	lv_obj_set_scrollbar_mode(ui->screenRecording_cont_ch23, LV_SCROLLBAR_MODE_OFF);

	//Write style for screenRecording_cont_ch23, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->screenRecording_cont_ch23, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_opa(ui->screenRecording_cont_ch23, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_color(ui->screenRecording_cont_ch23, lv_color_hex(0x2195f6), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_side(ui->screenRecording_cont_ch23, LV_BORDER_SIDE_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->screenRecording_cont_ch23, 4, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->screenRecording_cont_ch23, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui->screenRecording_cont_ch23, lv_color_hex(0x292831), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->screenRecording_cont_ch23, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->screenRecording_cont_ch23, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->screenRecording_cont_ch23, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->screenRecording_cont_ch23, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->screenRecording_cont_ch23, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes screenRecording_label_ch_23
	ui->screenRecording_label_ch_23 = lv_label_create(ui->screenRecording_cont_ch23);
	lv_label_set_text(ui->screenRecording_label_ch_23, "CH: 31");
	lv_label_set_long_mode(ui->screenRecording_label_ch_23, LV_LABEL_LONG_WRAP);
	lv_obj_set_pos(ui->screenRecording_label_ch_23, 137, 5);
	lv_obj_set_size(ui->screenRecording_label_ch_23, 66, 32);

	//Write style for screenRecording_label_ch_23, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->screenRecording_label_ch_23, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->screenRecording_label_ch_23, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->screenRecording_label_ch_23, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->screenRecording_label_ch_23, &lv_font_MontserratRegular_20, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->screenRecording_label_ch_23, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_line_space(ui->screenRecording_label_ch_23, 1, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->screenRecording_label_ch_23, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->screenRecording_label_ch_23, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->screenRecording_label_ch_23, 7, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->screenRecording_label_ch_23, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->screenRecording_label_ch_23, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->screenRecording_label_ch_23, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->screenRecording_label_ch_23, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes screenRecording_label_spk_23
	ui->screenRecording_label_spk_23 = lv_label_create(ui->screenRecording_cont_ch23);
	lv_label_set_text(ui->screenRecording_label_spk_23, "");
	lv_label_set_long_mode(ui->screenRecording_label_spk_23, LV_LABEL_LONG_WRAP);
	lv_obj_set_pos(ui->screenRecording_label_spk_23, 100, 4);
	lv_obj_set_size(ui->screenRecording_label_spk_23, 25, 32);

	//Write style for screenRecording_label_spk_23, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->screenRecording_label_spk_23, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->screenRecording_label_spk_23, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->screenRecording_label_spk_23, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->screenRecording_label_spk_23, &lv_font_FontAwesome5ProRegular_400_22, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->screenRecording_label_spk_23, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_line_space(ui->screenRecording_label_spk_23, 1, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->screenRecording_label_spk_23, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->screenRecording_label_spk_23, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->screenRecording_label_spk_23, 6, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->screenRecording_label_spk_23, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->screenRecording_label_spk_23, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->screenRecording_label_spk_23, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->screenRecording_label_spk_23, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes screenRecording_sw_23
	ui->screenRecording_sw_23 = lv_switch_create(ui->screenRecording_cont_ch23);
	lv_obj_set_pos(ui->screenRecording_sw_23, 46, 12);
	lv_obj_set_size(ui->screenRecording_sw_23, 40, 20);

	//Write style for screenRecording_sw_23, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_bg_opa(ui->screenRecording_sw_23, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui->screenRecording_sw_23, lv_color_hex(0x41485a), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_width(ui->screenRecording_sw_23, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->screenRecording_sw_23, 10, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->screenRecording_sw_23, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write style for screenRecording_sw_23, Part: LV_PART_INDICATOR, State: LV_STATE_CHECKED.
	lv_obj_set_style_bg_opa(ui->screenRecording_sw_23, 255, LV_PART_INDICATOR|LV_STATE_CHECKED);
	lv_obj_set_style_bg_color(ui->screenRecording_sw_23, lv_color_hex(0x2195f6), LV_PART_INDICATOR|LV_STATE_CHECKED);
	lv_obj_set_style_border_width(ui->screenRecording_sw_23, 0, LV_PART_INDICATOR|LV_STATE_CHECKED);

	//Write style for screenRecording_sw_23, Part: LV_PART_KNOB, State: LV_STATE_DEFAULT.
	lv_obj_set_style_bg_opa(ui->screenRecording_sw_23, 255, LV_PART_KNOB|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui->screenRecording_sw_23, lv_color_hex(0x292831), LV_PART_KNOB|LV_STATE_DEFAULT);
	lv_obj_set_style_border_width(ui->screenRecording_sw_23, 0, LV_PART_KNOB|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->screenRecording_sw_23, 10, LV_PART_KNOB|LV_STATE_DEFAULT);

	//Write codes screenRecording_label_91
	ui->screenRecording_label_91 = lv_label_create(ui->screenRecording_cont_ch23);
	lv_label_set_text(ui->screenRecording_label_91, "23");
	lv_label_set_long_mode(ui->screenRecording_label_91, LV_LABEL_LONG_WRAP);
	lv_obj_set_pos(ui->screenRecording_label_91, 4, 5);
	lv_obj_set_size(ui->screenRecording_label_91, 35, 32);

	//Write style for screenRecording_label_91, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->screenRecording_label_91, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->screenRecording_label_91, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->screenRecording_label_91, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->screenRecording_label_91, &lv_font_montserratMedium_24, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->screenRecording_label_91, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_line_space(ui->screenRecording_label_91, 1, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->screenRecording_label_91, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->screenRecording_label_91, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->screenRecording_label_91, 5, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->screenRecording_label_91, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->screenRecording_label_91, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->screenRecording_label_91, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->screenRecording_label_91, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes screenRecording_cont_ch24
	ui->screenRecording_cont_ch24 = lv_obj_create(ui->screenRecording_cont_10);
	lv_obj_set_pos(ui->screenRecording_cont_ch24, 13, 1155);
	lv_obj_set_size(ui->screenRecording_cont_ch24, 210, 46);
	lv_obj_set_scrollbar_mode(ui->screenRecording_cont_ch24, LV_SCROLLBAR_MODE_OFF);

	//Write style for screenRecording_cont_ch24, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->screenRecording_cont_ch24, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_opa(ui->screenRecording_cont_ch24, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_color(ui->screenRecording_cont_ch24, lv_color_hex(0x2195f6), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_side(ui->screenRecording_cont_ch24, LV_BORDER_SIDE_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->screenRecording_cont_ch24, 4, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->screenRecording_cont_ch24, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui->screenRecording_cont_ch24, lv_color_hex(0x292831), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->screenRecording_cont_ch24, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->screenRecording_cont_ch24, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->screenRecording_cont_ch24, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->screenRecording_cont_ch24, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->screenRecording_cont_ch24, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes screenRecording_label_ch_24
	ui->screenRecording_label_ch_24 = lv_label_create(ui->screenRecording_cont_ch24);
	lv_label_set_text(ui->screenRecording_label_ch_24, "CH: 31");
	lv_label_set_long_mode(ui->screenRecording_label_ch_24, LV_LABEL_LONG_WRAP);
	lv_obj_set_pos(ui->screenRecording_label_ch_24, 137, 5);
	lv_obj_set_size(ui->screenRecording_label_ch_24, 66, 32);

	//Write style for screenRecording_label_ch_24, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->screenRecording_label_ch_24, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->screenRecording_label_ch_24, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->screenRecording_label_ch_24, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->screenRecording_label_ch_24, &lv_font_MontserratRegular_20, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->screenRecording_label_ch_24, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_line_space(ui->screenRecording_label_ch_24, 1, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->screenRecording_label_ch_24, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->screenRecording_label_ch_24, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->screenRecording_label_ch_24, 7, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->screenRecording_label_ch_24, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->screenRecording_label_ch_24, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->screenRecording_label_ch_24, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->screenRecording_label_ch_24, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes screenRecording_label_spk_24
	ui->screenRecording_label_spk_24 = lv_label_create(ui->screenRecording_cont_ch24);
	lv_label_set_text(ui->screenRecording_label_spk_24, "");
	lv_label_set_long_mode(ui->screenRecording_label_spk_24, LV_LABEL_LONG_WRAP);
	lv_obj_set_pos(ui->screenRecording_label_spk_24, 100, 4);
	lv_obj_set_size(ui->screenRecording_label_spk_24, 25, 32);

	//Write style for screenRecording_label_spk_24, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->screenRecording_label_spk_24, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->screenRecording_label_spk_24, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->screenRecording_label_spk_24, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->screenRecording_label_spk_24, &lv_font_FontAwesome5ProRegular_400_22, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->screenRecording_label_spk_24, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_line_space(ui->screenRecording_label_spk_24, 1, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->screenRecording_label_spk_24, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->screenRecording_label_spk_24, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->screenRecording_label_spk_24, 6, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->screenRecording_label_spk_24, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->screenRecording_label_spk_24, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->screenRecording_label_spk_24, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->screenRecording_label_spk_24, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes screenRecording_sw_24
	ui->screenRecording_sw_24 = lv_switch_create(ui->screenRecording_cont_ch24);
	lv_obj_set_pos(ui->screenRecording_sw_24, 46, 12);
	lv_obj_set_size(ui->screenRecording_sw_24, 40, 20);

	//Write style for screenRecording_sw_24, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_bg_opa(ui->screenRecording_sw_24, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui->screenRecording_sw_24, lv_color_hex(0x41485a), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_width(ui->screenRecording_sw_24, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->screenRecording_sw_24, 10, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->screenRecording_sw_24, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write style for screenRecording_sw_24, Part: LV_PART_INDICATOR, State: LV_STATE_CHECKED.
	lv_obj_set_style_bg_opa(ui->screenRecording_sw_24, 255, LV_PART_INDICATOR|LV_STATE_CHECKED);
	lv_obj_set_style_bg_color(ui->screenRecording_sw_24, lv_color_hex(0x2195f6), LV_PART_INDICATOR|LV_STATE_CHECKED);
	lv_obj_set_style_border_width(ui->screenRecording_sw_24, 0, LV_PART_INDICATOR|LV_STATE_CHECKED);

	//Write style for screenRecording_sw_24, Part: LV_PART_KNOB, State: LV_STATE_DEFAULT.
	lv_obj_set_style_bg_opa(ui->screenRecording_sw_24, 255, LV_PART_KNOB|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui->screenRecording_sw_24, lv_color_hex(0x292831), LV_PART_KNOB|LV_STATE_DEFAULT);
	lv_obj_set_style_border_width(ui->screenRecording_sw_24, 0, LV_PART_KNOB|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->screenRecording_sw_24, 10, LV_PART_KNOB|LV_STATE_DEFAULT);

	//Write codes screenRecording_label_94
	ui->screenRecording_label_94 = lv_label_create(ui->screenRecording_cont_ch24);
	lv_label_set_text(ui->screenRecording_label_94, "24");
	lv_label_set_long_mode(ui->screenRecording_label_94, LV_LABEL_LONG_WRAP);
	lv_obj_set_pos(ui->screenRecording_label_94, 4, 5);
	lv_obj_set_size(ui->screenRecording_label_94, 35, 32);

	//Write style for screenRecording_label_94, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->screenRecording_label_94, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->screenRecording_label_94, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->screenRecording_label_94, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->screenRecording_label_94, &lv_font_montserratMedium_24, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->screenRecording_label_94, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_line_space(ui->screenRecording_label_94, 1, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->screenRecording_label_94, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->screenRecording_label_94, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->screenRecording_label_94, 5, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->screenRecording_label_94, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->screenRecording_label_94, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->screenRecording_label_94, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->screenRecording_label_94, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes screenRecording_cont_ch25
	ui->screenRecording_cont_ch25 = lv_obj_create(ui->screenRecording_cont_10);
	lv_obj_set_pos(ui->screenRecording_cont_ch25, 13, 1205);
	lv_obj_set_size(ui->screenRecording_cont_ch25, 210, 46);
	lv_obj_set_scrollbar_mode(ui->screenRecording_cont_ch25, LV_SCROLLBAR_MODE_OFF);

	//Write style for screenRecording_cont_ch25, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->screenRecording_cont_ch25, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_opa(ui->screenRecording_cont_ch25, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_color(ui->screenRecording_cont_ch25, lv_color_hex(0x2195f6), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_side(ui->screenRecording_cont_ch25, LV_BORDER_SIDE_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->screenRecording_cont_ch25, 4, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->screenRecording_cont_ch25, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui->screenRecording_cont_ch25, lv_color_hex(0x292831), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->screenRecording_cont_ch25, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->screenRecording_cont_ch25, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->screenRecording_cont_ch25, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->screenRecording_cont_ch25, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->screenRecording_cont_ch25, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes screenRecording_label_ch_25
	ui->screenRecording_label_ch_25 = lv_label_create(ui->screenRecording_cont_ch25);
	lv_label_set_text(ui->screenRecording_label_ch_25, "CH: 31");
	lv_label_set_long_mode(ui->screenRecording_label_ch_25, LV_LABEL_LONG_WRAP);
	lv_obj_set_pos(ui->screenRecording_label_ch_25, 137, 5);
	lv_obj_set_size(ui->screenRecording_label_ch_25, 66, 32);

	//Write style for screenRecording_label_ch_25, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->screenRecording_label_ch_25, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->screenRecording_label_ch_25, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->screenRecording_label_ch_25, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->screenRecording_label_ch_25, &lv_font_MontserratRegular_20, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->screenRecording_label_ch_25, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_line_space(ui->screenRecording_label_ch_25, 1, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->screenRecording_label_ch_25, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->screenRecording_label_ch_25, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->screenRecording_label_ch_25, 7, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->screenRecording_label_ch_25, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->screenRecording_label_ch_25, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->screenRecording_label_ch_25, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->screenRecording_label_ch_25, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes screenRecording_label_spk_25
	ui->screenRecording_label_spk_25 = lv_label_create(ui->screenRecording_cont_ch25);
	lv_label_set_text(ui->screenRecording_label_spk_25, "");
	lv_label_set_long_mode(ui->screenRecording_label_spk_25, LV_LABEL_LONG_WRAP);
	lv_obj_set_pos(ui->screenRecording_label_spk_25, 100, 4);
	lv_obj_set_size(ui->screenRecording_label_spk_25, 25, 32);

	//Write style for screenRecording_label_spk_25, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->screenRecording_label_spk_25, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->screenRecording_label_spk_25, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->screenRecording_label_spk_25, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->screenRecording_label_spk_25, &lv_font_FontAwesome5ProRegular_400_22, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->screenRecording_label_spk_25, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_line_space(ui->screenRecording_label_spk_25, 1, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->screenRecording_label_spk_25, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->screenRecording_label_spk_25, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->screenRecording_label_spk_25, 6, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->screenRecording_label_spk_25, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->screenRecording_label_spk_25, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->screenRecording_label_spk_25, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->screenRecording_label_spk_25, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes screenRecording_sw_25
	ui->screenRecording_sw_25 = lv_switch_create(ui->screenRecording_cont_ch25);
	lv_obj_set_pos(ui->screenRecording_sw_25, 46, 12);
	lv_obj_set_size(ui->screenRecording_sw_25, 40, 20);

	//Write style for screenRecording_sw_25, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_bg_opa(ui->screenRecording_sw_25, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui->screenRecording_sw_25, lv_color_hex(0x41485a), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_width(ui->screenRecording_sw_25, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->screenRecording_sw_25, 10, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->screenRecording_sw_25, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write style for screenRecording_sw_25, Part: LV_PART_INDICATOR, State: LV_STATE_CHECKED.
	lv_obj_set_style_bg_opa(ui->screenRecording_sw_25, 255, LV_PART_INDICATOR|LV_STATE_CHECKED);
	lv_obj_set_style_bg_color(ui->screenRecording_sw_25, lv_color_hex(0x2195f6), LV_PART_INDICATOR|LV_STATE_CHECKED);
	lv_obj_set_style_border_width(ui->screenRecording_sw_25, 0, LV_PART_INDICATOR|LV_STATE_CHECKED);

	//Write style for screenRecording_sw_25, Part: LV_PART_KNOB, State: LV_STATE_DEFAULT.
	lv_obj_set_style_bg_opa(ui->screenRecording_sw_25, 255, LV_PART_KNOB|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui->screenRecording_sw_25, lv_color_hex(0x292831), LV_PART_KNOB|LV_STATE_DEFAULT);
	lv_obj_set_style_border_width(ui->screenRecording_sw_25, 0, LV_PART_KNOB|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->screenRecording_sw_25, 10, LV_PART_KNOB|LV_STATE_DEFAULT);

	//Write codes screenRecording_label_97
	ui->screenRecording_label_97 = lv_label_create(ui->screenRecording_cont_ch25);
	lv_label_set_text(ui->screenRecording_label_97, "25");
	lv_label_set_long_mode(ui->screenRecording_label_97, LV_LABEL_LONG_WRAP);
	lv_obj_set_pos(ui->screenRecording_label_97, 4, 5);
	lv_obj_set_size(ui->screenRecording_label_97, 35, 32);

	//Write style for screenRecording_label_97, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->screenRecording_label_97, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->screenRecording_label_97, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->screenRecording_label_97, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->screenRecording_label_97, &lv_font_montserratMedium_24, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->screenRecording_label_97, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_line_space(ui->screenRecording_label_97, 1, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->screenRecording_label_97, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->screenRecording_label_97, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->screenRecording_label_97, 5, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->screenRecording_label_97, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->screenRecording_label_97, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->screenRecording_label_97, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->screenRecording_label_97, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes screenRecording_cont_ch26
	ui->screenRecording_cont_ch26 = lv_obj_create(ui->screenRecording_cont_10);
	lv_obj_set_pos(ui->screenRecording_cont_ch26, 13, 1255);
	lv_obj_set_size(ui->screenRecording_cont_ch26, 210, 46);
	lv_obj_set_scrollbar_mode(ui->screenRecording_cont_ch26, LV_SCROLLBAR_MODE_OFF);

	//Write style for screenRecording_cont_ch26, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->screenRecording_cont_ch26, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_opa(ui->screenRecording_cont_ch26, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_color(ui->screenRecording_cont_ch26, lv_color_hex(0x2195f6), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_side(ui->screenRecording_cont_ch26, LV_BORDER_SIDE_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->screenRecording_cont_ch26, 4, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->screenRecording_cont_ch26, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui->screenRecording_cont_ch26, lv_color_hex(0x292831), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->screenRecording_cont_ch26, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->screenRecording_cont_ch26, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->screenRecording_cont_ch26, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->screenRecording_cont_ch26, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->screenRecording_cont_ch26, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes screenRecording_label_ch_26
	ui->screenRecording_label_ch_26 = lv_label_create(ui->screenRecording_cont_ch26);
	lv_label_set_text(ui->screenRecording_label_ch_26, "CH: 31");
	lv_label_set_long_mode(ui->screenRecording_label_ch_26, LV_LABEL_LONG_WRAP);
	lv_obj_set_pos(ui->screenRecording_label_ch_26, 137, 5);
	lv_obj_set_size(ui->screenRecording_label_ch_26, 66, 32);

	//Write style for screenRecording_label_ch_26, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->screenRecording_label_ch_26, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->screenRecording_label_ch_26, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->screenRecording_label_ch_26, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->screenRecording_label_ch_26, &lv_font_MontserratRegular_20, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->screenRecording_label_ch_26, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_line_space(ui->screenRecording_label_ch_26, 1, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->screenRecording_label_ch_26, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->screenRecording_label_ch_26, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->screenRecording_label_ch_26, 7, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->screenRecording_label_ch_26, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->screenRecording_label_ch_26, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->screenRecording_label_ch_26, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->screenRecording_label_ch_26, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes screenRecording_label_spk_26
	ui->screenRecording_label_spk_26 = lv_label_create(ui->screenRecording_cont_ch26);
	lv_label_set_text(ui->screenRecording_label_spk_26, "");
	lv_label_set_long_mode(ui->screenRecording_label_spk_26, LV_LABEL_LONG_WRAP);
	lv_obj_set_pos(ui->screenRecording_label_spk_26, 100, 4);
	lv_obj_set_size(ui->screenRecording_label_spk_26, 25, 32);

	//Write style for screenRecording_label_spk_26, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->screenRecording_label_spk_26, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->screenRecording_label_spk_26, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->screenRecording_label_spk_26, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->screenRecording_label_spk_26, &lv_font_FontAwesome5ProRegular_400_22, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->screenRecording_label_spk_26, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_line_space(ui->screenRecording_label_spk_26, 1, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->screenRecording_label_spk_26, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->screenRecording_label_spk_26, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->screenRecording_label_spk_26, 6, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->screenRecording_label_spk_26, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->screenRecording_label_spk_26, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->screenRecording_label_spk_26, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->screenRecording_label_spk_26, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes screenRecording_sw_26
	ui->screenRecording_sw_26 = lv_switch_create(ui->screenRecording_cont_ch26);
	lv_obj_set_pos(ui->screenRecording_sw_26, 46, 12);
	lv_obj_set_size(ui->screenRecording_sw_26, 40, 20);

	//Write style for screenRecording_sw_26, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_bg_opa(ui->screenRecording_sw_26, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui->screenRecording_sw_26, lv_color_hex(0x41485a), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_width(ui->screenRecording_sw_26, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->screenRecording_sw_26, 10, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->screenRecording_sw_26, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write style for screenRecording_sw_26, Part: LV_PART_INDICATOR, State: LV_STATE_CHECKED.
	lv_obj_set_style_bg_opa(ui->screenRecording_sw_26, 255, LV_PART_INDICATOR|LV_STATE_CHECKED);
	lv_obj_set_style_bg_color(ui->screenRecording_sw_26, lv_color_hex(0x2195f6), LV_PART_INDICATOR|LV_STATE_CHECKED);
	lv_obj_set_style_border_width(ui->screenRecording_sw_26, 0, LV_PART_INDICATOR|LV_STATE_CHECKED);

	//Write style for screenRecording_sw_26, Part: LV_PART_KNOB, State: LV_STATE_DEFAULT.
	lv_obj_set_style_bg_opa(ui->screenRecording_sw_26, 255, LV_PART_KNOB|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui->screenRecording_sw_26, lv_color_hex(0x292831), LV_PART_KNOB|LV_STATE_DEFAULT);
	lv_obj_set_style_border_width(ui->screenRecording_sw_26, 0, LV_PART_KNOB|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->screenRecording_sw_26, 10, LV_PART_KNOB|LV_STATE_DEFAULT);

	//Write codes screenRecording_label_100
	ui->screenRecording_label_100 = lv_label_create(ui->screenRecording_cont_ch26);
	lv_label_set_text(ui->screenRecording_label_100, "26");
	lv_label_set_long_mode(ui->screenRecording_label_100, LV_LABEL_LONG_WRAP);
	lv_obj_set_pos(ui->screenRecording_label_100, 4, 5);
	lv_obj_set_size(ui->screenRecording_label_100, 35, 32);

	//Write style for screenRecording_label_100, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->screenRecording_label_100, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->screenRecording_label_100, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->screenRecording_label_100, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->screenRecording_label_100, &lv_font_montserratMedium_24, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->screenRecording_label_100, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_line_space(ui->screenRecording_label_100, 1, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->screenRecording_label_100, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->screenRecording_label_100, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->screenRecording_label_100, 5, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->screenRecording_label_100, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->screenRecording_label_100, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->screenRecording_label_100, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->screenRecording_label_100, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes screenRecording_cont_ch27
	ui->screenRecording_cont_ch27 = lv_obj_create(ui->screenRecording_cont_10);
	lv_obj_set_pos(ui->screenRecording_cont_ch27, 13, 1305);
	lv_obj_set_size(ui->screenRecording_cont_ch27, 210, 46);
	lv_obj_set_scrollbar_mode(ui->screenRecording_cont_ch27, LV_SCROLLBAR_MODE_OFF);

	//Write style for screenRecording_cont_ch27, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->screenRecording_cont_ch27, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_opa(ui->screenRecording_cont_ch27, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_color(ui->screenRecording_cont_ch27, lv_color_hex(0x2195f6), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_side(ui->screenRecording_cont_ch27, LV_BORDER_SIDE_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->screenRecording_cont_ch27, 4, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->screenRecording_cont_ch27, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui->screenRecording_cont_ch27, lv_color_hex(0x292831), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->screenRecording_cont_ch27, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->screenRecording_cont_ch27, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->screenRecording_cont_ch27, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->screenRecording_cont_ch27, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->screenRecording_cont_ch27, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes screenRecording_label_ch_27
	ui->screenRecording_label_ch_27 = lv_label_create(ui->screenRecording_cont_ch27);
	lv_label_set_text(ui->screenRecording_label_ch_27, "CH: 31");
	lv_label_set_long_mode(ui->screenRecording_label_ch_27, LV_LABEL_LONG_WRAP);
	lv_obj_set_pos(ui->screenRecording_label_ch_27, 137, 5);
	lv_obj_set_size(ui->screenRecording_label_ch_27, 66, 32);

	//Write style for screenRecording_label_ch_27, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->screenRecording_label_ch_27, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->screenRecording_label_ch_27, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->screenRecording_label_ch_27, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->screenRecording_label_ch_27, &lv_font_MontserratRegular_20, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->screenRecording_label_ch_27, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_line_space(ui->screenRecording_label_ch_27, 1, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->screenRecording_label_ch_27, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->screenRecording_label_ch_27, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->screenRecording_label_ch_27, 7, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->screenRecording_label_ch_27, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->screenRecording_label_ch_27, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->screenRecording_label_ch_27, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->screenRecording_label_ch_27, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes screenRecording_label_spk_27
	ui->screenRecording_label_spk_27 = lv_label_create(ui->screenRecording_cont_ch27);
	lv_label_set_text(ui->screenRecording_label_spk_27, "");
	lv_label_set_long_mode(ui->screenRecording_label_spk_27, LV_LABEL_LONG_WRAP);
	lv_obj_set_pos(ui->screenRecording_label_spk_27, 100, 4);
	lv_obj_set_size(ui->screenRecording_label_spk_27, 25, 32);

	//Write style for screenRecording_label_spk_27, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->screenRecording_label_spk_27, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->screenRecording_label_spk_27, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->screenRecording_label_spk_27, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->screenRecording_label_spk_27, &lv_font_FontAwesome5ProRegular_400_22, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->screenRecording_label_spk_27, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_line_space(ui->screenRecording_label_spk_27, 1, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->screenRecording_label_spk_27, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->screenRecording_label_spk_27, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->screenRecording_label_spk_27, 6, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->screenRecording_label_spk_27, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->screenRecording_label_spk_27, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->screenRecording_label_spk_27, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->screenRecording_label_spk_27, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes screenRecording_sw_27
	ui->screenRecording_sw_27 = lv_switch_create(ui->screenRecording_cont_ch27);
	lv_obj_set_pos(ui->screenRecording_sw_27, 46, 12);
	lv_obj_set_size(ui->screenRecording_sw_27, 40, 20);

	//Write style for screenRecording_sw_27, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_bg_opa(ui->screenRecording_sw_27, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui->screenRecording_sw_27, lv_color_hex(0x41485a), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_width(ui->screenRecording_sw_27, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->screenRecording_sw_27, 10, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->screenRecording_sw_27, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write style for screenRecording_sw_27, Part: LV_PART_INDICATOR, State: LV_STATE_CHECKED.
	lv_obj_set_style_bg_opa(ui->screenRecording_sw_27, 255, LV_PART_INDICATOR|LV_STATE_CHECKED);
	lv_obj_set_style_bg_color(ui->screenRecording_sw_27, lv_color_hex(0x2195f6), LV_PART_INDICATOR|LV_STATE_CHECKED);
	lv_obj_set_style_border_width(ui->screenRecording_sw_27, 0, LV_PART_INDICATOR|LV_STATE_CHECKED);

	//Write style for screenRecording_sw_27, Part: LV_PART_KNOB, State: LV_STATE_DEFAULT.
	lv_obj_set_style_bg_opa(ui->screenRecording_sw_27, 255, LV_PART_KNOB|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui->screenRecording_sw_27, lv_color_hex(0x292831), LV_PART_KNOB|LV_STATE_DEFAULT);
	lv_obj_set_style_border_width(ui->screenRecording_sw_27, 0, LV_PART_KNOB|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->screenRecording_sw_27, 10, LV_PART_KNOB|LV_STATE_DEFAULT);

	//Write codes screenRecording_label_103
	ui->screenRecording_label_103 = lv_label_create(ui->screenRecording_cont_ch27);
	lv_label_set_text(ui->screenRecording_label_103, "27");
	lv_label_set_long_mode(ui->screenRecording_label_103, LV_LABEL_LONG_WRAP);
	lv_obj_set_pos(ui->screenRecording_label_103, 4, 5);
	lv_obj_set_size(ui->screenRecording_label_103, 35, 32);

	//Write style for screenRecording_label_103, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->screenRecording_label_103, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->screenRecording_label_103, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->screenRecording_label_103, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->screenRecording_label_103, &lv_font_montserratMedium_24, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->screenRecording_label_103, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_line_space(ui->screenRecording_label_103, 1, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->screenRecording_label_103, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->screenRecording_label_103, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->screenRecording_label_103, 5, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->screenRecording_label_103, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->screenRecording_label_103, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->screenRecording_label_103, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->screenRecording_label_103, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes screenRecording_cont_ch28
	ui->screenRecording_cont_ch28 = lv_obj_create(ui->screenRecording_cont_10);
	lv_obj_set_pos(ui->screenRecording_cont_ch28, 13, 1355);
	lv_obj_set_size(ui->screenRecording_cont_ch28, 210, 46);
	lv_obj_set_scrollbar_mode(ui->screenRecording_cont_ch28, LV_SCROLLBAR_MODE_OFF);

	//Write style for screenRecording_cont_ch28, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->screenRecording_cont_ch28, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_opa(ui->screenRecording_cont_ch28, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_color(ui->screenRecording_cont_ch28, lv_color_hex(0x2195f6), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_side(ui->screenRecording_cont_ch28, LV_BORDER_SIDE_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->screenRecording_cont_ch28, 4, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->screenRecording_cont_ch28, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui->screenRecording_cont_ch28, lv_color_hex(0x292831), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->screenRecording_cont_ch28, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->screenRecording_cont_ch28, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->screenRecording_cont_ch28, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->screenRecording_cont_ch28, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->screenRecording_cont_ch28, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes screenRecording_label_ch_28
	ui->screenRecording_label_ch_28 = lv_label_create(ui->screenRecording_cont_ch28);
	lv_label_set_text(ui->screenRecording_label_ch_28, "CH: 31");
	lv_label_set_long_mode(ui->screenRecording_label_ch_28, LV_LABEL_LONG_WRAP);
	lv_obj_set_pos(ui->screenRecording_label_ch_28, 137, 5);
	lv_obj_set_size(ui->screenRecording_label_ch_28, 66, 32);

	//Write style for screenRecording_label_ch_28, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->screenRecording_label_ch_28, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->screenRecording_label_ch_28, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->screenRecording_label_ch_28, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->screenRecording_label_ch_28, &lv_font_MontserratRegular_20, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->screenRecording_label_ch_28, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_line_space(ui->screenRecording_label_ch_28, 1, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->screenRecording_label_ch_28, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->screenRecording_label_ch_28, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->screenRecording_label_ch_28, 7, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->screenRecording_label_ch_28, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->screenRecording_label_ch_28, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->screenRecording_label_ch_28, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->screenRecording_label_ch_28, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes screenRecording_label_spk_28
	ui->screenRecording_label_spk_28 = lv_label_create(ui->screenRecording_cont_ch28);
	lv_label_set_text(ui->screenRecording_label_spk_28, "");
	lv_label_set_long_mode(ui->screenRecording_label_spk_28, LV_LABEL_LONG_WRAP);
	lv_obj_set_pos(ui->screenRecording_label_spk_28, 100, 4);
	lv_obj_set_size(ui->screenRecording_label_spk_28, 25, 32);

	//Write style for screenRecording_label_spk_28, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->screenRecording_label_spk_28, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->screenRecording_label_spk_28, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->screenRecording_label_spk_28, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->screenRecording_label_spk_28, &lv_font_FontAwesome5ProRegular_400_22, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->screenRecording_label_spk_28, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_line_space(ui->screenRecording_label_spk_28, 1, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->screenRecording_label_spk_28, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->screenRecording_label_spk_28, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->screenRecording_label_spk_28, 6, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->screenRecording_label_spk_28, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->screenRecording_label_spk_28, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->screenRecording_label_spk_28, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->screenRecording_label_spk_28, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes screenRecording_sw_28
	ui->screenRecording_sw_28 = lv_switch_create(ui->screenRecording_cont_ch28);
	lv_obj_set_pos(ui->screenRecording_sw_28, 46, 12);
	lv_obj_set_size(ui->screenRecording_sw_28, 40, 20);

	//Write style for screenRecording_sw_28, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_bg_opa(ui->screenRecording_sw_28, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui->screenRecording_sw_28, lv_color_hex(0x41485a), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_width(ui->screenRecording_sw_28, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->screenRecording_sw_28, 10, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->screenRecording_sw_28, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write style for screenRecording_sw_28, Part: LV_PART_INDICATOR, State: LV_STATE_CHECKED.
	lv_obj_set_style_bg_opa(ui->screenRecording_sw_28, 255, LV_PART_INDICATOR|LV_STATE_CHECKED);
	lv_obj_set_style_bg_color(ui->screenRecording_sw_28, lv_color_hex(0x2195f6), LV_PART_INDICATOR|LV_STATE_CHECKED);
	lv_obj_set_style_border_width(ui->screenRecording_sw_28, 0, LV_PART_INDICATOR|LV_STATE_CHECKED);

	//Write style for screenRecording_sw_28, Part: LV_PART_KNOB, State: LV_STATE_DEFAULT.
	lv_obj_set_style_bg_opa(ui->screenRecording_sw_28, 255, LV_PART_KNOB|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui->screenRecording_sw_28, lv_color_hex(0x292831), LV_PART_KNOB|LV_STATE_DEFAULT);
	lv_obj_set_style_border_width(ui->screenRecording_sw_28, 0, LV_PART_KNOB|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->screenRecording_sw_28, 10, LV_PART_KNOB|LV_STATE_DEFAULT);

	//Write codes screenRecording_label_106
	ui->screenRecording_label_106 = lv_label_create(ui->screenRecording_cont_ch28);
	lv_label_set_text(ui->screenRecording_label_106, "28");
	lv_label_set_long_mode(ui->screenRecording_label_106, LV_LABEL_LONG_WRAP);
	lv_obj_set_pos(ui->screenRecording_label_106, 4, 5);
	lv_obj_set_size(ui->screenRecording_label_106, 35, 32);

	//Write style for screenRecording_label_106, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->screenRecording_label_106, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->screenRecording_label_106, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->screenRecording_label_106, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->screenRecording_label_106, &lv_font_montserratMedium_24, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->screenRecording_label_106, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_line_space(ui->screenRecording_label_106, 1, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->screenRecording_label_106, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->screenRecording_label_106, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->screenRecording_label_106, 5, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->screenRecording_label_106, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->screenRecording_label_106, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->screenRecording_label_106, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->screenRecording_label_106, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes screenRecording_cont_ch29
	ui->screenRecording_cont_ch29 = lv_obj_create(ui->screenRecording_cont_10);
	lv_obj_set_pos(ui->screenRecording_cont_ch29, 13, 1405);
	lv_obj_set_size(ui->screenRecording_cont_ch29, 210, 46);
	lv_obj_set_scrollbar_mode(ui->screenRecording_cont_ch29, LV_SCROLLBAR_MODE_OFF);

	//Write style for screenRecording_cont_ch29, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->screenRecording_cont_ch29, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_opa(ui->screenRecording_cont_ch29, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_color(ui->screenRecording_cont_ch29, lv_color_hex(0x2195f6), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_side(ui->screenRecording_cont_ch29, LV_BORDER_SIDE_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->screenRecording_cont_ch29, 4, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->screenRecording_cont_ch29, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui->screenRecording_cont_ch29, lv_color_hex(0x292831), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->screenRecording_cont_ch29, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->screenRecording_cont_ch29, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->screenRecording_cont_ch29, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->screenRecording_cont_ch29, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->screenRecording_cont_ch29, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes screenRecording_label_ch_29
	ui->screenRecording_label_ch_29 = lv_label_create(ui->screenRecording_cont_ch29);
	lv_label_set_text(ui->screenRecording_label_ch_29, "CH: 31");
	lv_label_set_long_mode(ui->screenRecording_label_ch_29, LV_LABEL_LONG_WRAP);
	lv_obj_set_pos(ui->screenRecording_label_ch_29, 137, 5);
	lv_obj_set_size(ui->screenRecording_label_ch_29, 66, 32);

	//Write style for screenRecording_label_ch_29, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->screenRecording_label_ch_29, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->screenRecording_label_ch_29, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->screenRecording_label_ch_29, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->screenRecording_label_ch_29, &lv_font_MontserratRegular_20, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->screenRecording_label_ch_29, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_line_space(ui->screenRecording_label_ch_29, 1, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->screenRecording_label_ch_29, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->screenRecording_label_ch_29, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->screenRecording_label_ch_29, 7, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->screenRecording_label_ch_29, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->screenRecording_label_ch_29, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->screenRecording_label_ch_29, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->screenRecording_label_ch_29, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes screenRecording_label_spk_29
	ui->screenRecording_label_spk_29 = lv_label_create(ui->screenRecording_cont_ch29);
	lv_label_set_text(ui->screenRecording_label_spk_29, "");
	lv_label_set_long_mode(ui->screenRecording_label_spk_29, LV_LABEL_LONG_WRAP);
	lv_obj_set_pos(ui->screenRecording_label_spk_29, 100, 4);
	lv_obj_set_size(ui->screenRecording_label_spk_29, 25, 32);

	//Write style for screenRecording_label_spk_29, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->screenRecording_label_spk_29, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->screenRecording_label_spk_29, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->screenRecording_label_spk_29, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->screenRecording_label_spk_29, &lv_font_FontAwesome5ProRegular_400_22, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->screenRecording_label_spk_29, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_line_space(ui->screenRecording_label_spk_29, 1, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->screenRecording_label_spk_29, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->screenRecording_label_spk_29, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->screenRecording_label_spk_29, 6, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->screenRecording_label_spk_29, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->screenRecording_label_spk_29, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->screenRecording_label_spk_29, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->screenRecording_label_spk_29, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes screenRecording_sw_29
	ui->screenRecording_sw_29 = lv_switch_create(ui->screenRecording_cont_ch29);
	lv_obj_set_pos(ui->screenRecording_sw_29, 46, 12);
	lv_obj_set_size(ui->screenRecording_sw_29, 40, 20);

	//Write style for screenRecording_sw_29, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_bg_opa(ui->screenRecording_sw_29, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui->screenRecording_sw_29, lv_color_hex(0x41485a), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_width(ui->screenRecording_sw_29, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->screenRecording_sw_29, 10, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->screenRecording_sw_29, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write style for screenRecording_sw_29, Part: LV_PART_INDICATOR, State: LV_STATE_CHECKED.
	lv_obj_set_style_bg_opa(ui->screenRecording_sw_29, 255, LV_PART_INDICATOR|LV_STATE_CHECKED);
	lv_obj_set_style_bg_color(ui->screenRecording_sw_29, lv_color_hex(0x2195f6), LV_PART_INDICATOR|LV_STATE_CHECKED);
	lv_obj_set_style_border_width(ui->screenRecording_sw_29, 0, LV_PART_INDICATOR|LV_STATE_CHECKED);

	//Write style for screenRecording_sw_29, Part: LV_PART_KNOB, State: LV_STATE_DEFAULT.
	lv_obj_set_style_bg_opa(ui->screenRecording_sw_29, 255, LV_PART_KNOB|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui->screenRecording_sw_29, lv_color_hex(0x292831), LV_PART_KNOB|LV_STATE_DEFAULT);
	lv_obj_set_style_border_width(ui->screenRecording_sw_29, 0, LV_PART_KNOB|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->screenRecording_sw_29, 10, LV_PART_KNOB|LV_STATE_DEFAULT);

	//Write codes screenRecording_label_109
	ui->screenRecording_label_109 = lv_label_create(ui->screenRecording_cont_ch29);
	lv_label_set_text(ui->screenRecording_label_109, "29");
	lv_label_set_long_mode(ui->screenRecording_label_109, LV_LABEL_LONG_WRAP);
	lv_obj_set_pos(ui->screenRecording_label_109, 4, 5);
	lv_obj_set_size(ui->screenRecording_label_109, 35, 32);

	//Write style for screenRecording_label_109, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->screenRecording_label_109, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->screenRecording_label_109, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->screenRecording_label_109, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->screenRecording_label_109, &lv_font_montserratMedium_24, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->screenRecording_label_109, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_line_space(ui->screenRecording_label_109, 1, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->screenRecording_label_109, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->screenRecording_label_109, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->screenRecording_label_109, 5, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->screenRecording_label_109, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->screenRecording_label_109, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->screenRecording_label_109, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->screenRecording_label_109, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes screenRecording_cont_ch30
	ui->screenRecording_cont_ch30 = lv_obj_create(ui->screenRecording_cont_10);
	lv_obj_set_pos(ui->screenRecording_cont_ch30, 13, 1455);
	lv_obj_set_size(ui->screenRecording_cont_ch30, 210, 46);
	lv_obj_set_scrollbar_mode(ui->screenRecording_cont_ch30, LV_SCROLLBAR_MODE_OFF);

	//Write style for screenRecording_cont_ch30, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->screenRecording_cont_ch30, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_opa(ui->screenRecording_cont_ch30, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_color(ui->screenRecording_cont_ch30, lv_color_hex(0x2195f6), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_side(ui->screenRecording_cont_ch30, LV_BORDER_SIDE_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->screenRecording_cont_ch30, 4, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->screenRecording_cont_ch30, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui->screenRecording_cont_ch30, lv_color_hex(0x292831), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->screenRecording_cont_ch30, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->screenRecording_cont_ch30, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->screenRecording_cont_ch30, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->screenRecording_cont_ch30, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->screenRecording_cont_ch30, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes screenRecording_label_ch_30
	ui->screenRecording_label_ch_30 = lv_label_create(ui->screenRecording_cont_ch30);
	lv_label_set_text(ui->screenRecording_label_ch_30, "CH: 31");
	lv_label_set_long_mode(ui->screenRecording_label_ch_30, LV_LABEL_LONG_WRAP);
	lv_obj_set_pos(ui->screenRecording_label_ch_30, 137, 5);
	lv_obj_set_size(ui->screenRecording_label_ch_30, 66, 32);

	//Write style for screenRecording_label_ch_30, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->screenRecording_label_ch_30, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->screenRecording_label_ch_30, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->screenRecording_label_ch_30, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->screenRecording_label_ch_30, &lv_font_MontserratRegular_20, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->screenRecording_label_ch_30, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_line_space(ui->screenRecording_label_ch_30, 1, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->screenRecording_label_ch_30, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->screenRecording_label_ch_30, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->screenRecording_label_ch_30, 7, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->screenRecording_label_ch_30, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->screenRecording_label_ch_30, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->screenRecording_label_ch_30, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->screenRecording_label_ch_30, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes screenRecording_label_spk_30
	ui->screenRecording_label_spk_30 = lv_label_create(ui->screenRecording_cont_ch30);
	lv_label_set_text(ui->screenRecording_label_spk_30, "");
	lv_label_set_long_mode(ui->screenRecording_label_spk_30, LV_LABEL_LONG_WRAP);
	lv_obj_set_pos(ui->screenRecording_label_spk_30, 100, 4);
	lv_obj_set_size(ui->screenRecording_label_spk_30, 25, 32);

	//Write style for screenRecording_label_spk_30, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->screenRecording_label_spk_30, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->screenRecording_label_spk_30, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->screenRecording_label_spk_30, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->screenRecording_label_spk_30, &lv_font_FontAwesome5ProRegular_400_22, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->screenRecording_label_spk_30, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_line_space(ui->screenRecording_label_spk_30, 1, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->screenRecording_label_spk_30, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->screenRecording_label_spk_30, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->screenRecording_label_spk_30, 6, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->screenRecording_label_spk_30, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->screenRecording_label_spk_30, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->screenRecording_label_spk_30, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->screenRecording_label_spk_30, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes screenRecording_sw_30
	ui->screenRecording_sw_30 = lv_switch_create(ui->screenRecording_cont_ch30);
	lv_obj_set_pos(ui->screenRecording_sw_30, 46, 12);
	lv_obj_set_size(ui->screenRecording_sw_30, 40, 20);

	//Write style for screenRecording_sw_30, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_bg_opa(ui->screenRecording_sw_30, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui->screenRecording_sw_30, lv_color_hex(0x41485a), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_width(ui->screenRecording_sw_30, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->screenRecording_sw_30, 10, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->screenRecording_sw_30, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write style for screenRecording_sw_30, Part: LV_PART_INDICATOR, State: LV_STATE_CHECKED.
	lv_obj_set_style_bg_opa(ui->screenRecording_sw_30, 255, LV_PART_INDICATOR|LV_STATE_CHECKED);
	lv_obj_set_style_bg_color(ui->screenRecording_sw_30, lv_color_hex(0x2195f6), LV_PART_INDICATOR|LV_STATE_CHECKED);
	lv_obj_set_style_border_width(ui->screenRecording_sw_30, 0, LV_PART_INDICATOR|LV_STATE_CHECKED);

	//Write style for screenRecording_sw_30, Part: LV_PART_KNOB, State: LV_STATE_DEFAULT.
	lv_obj_set_style_bg_opa(ui->screenRecording_sw_30, 255, LV_PART_KNOB|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui->screenRecording_sw_30, lv_color_hex(0x292831), LV_PART_KNOB|LV_STATE_DEFAULT);
	lv_obj_set_style_border_width(ui->screenRecording_sw_30, 0, LV_PART_KNOB|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->screenRecording_sw_30, 10, LV_PART_KNOB|LV_STATE_DEFAULT);

	//Write codes screenRecording_label_112
	ui->screenRecording_label_112 = lv_label_create(ui->screenRecording_cont_ch30);
	lv_label_set_text(ui->screenRecording_label_112, "30");
	lv_label_set_long_mode(ui->screenRecording_label_112, LV_LABEL_LONG_WRAP);
	lv_obj_set_pos(ui->screenRecording_label_112, 4, 5);
	lv_obj_set_size(ui->screenRecording_label_112, 35, 32);

	//Write style for screenRecording_label_112, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->screenRecording_label_112, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->screenRecording_label_112, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->screenRecording_label_112, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->screenRecording_label_112, &lv_font_montserratMedium_24, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->screenRecording_label_112, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_line_space(ui->screenRecording_label_112, 1, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->screenRecording_label_112, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->screenRecording_label_112, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->screenRecording_label_112, 5, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->screenRecording_label_112, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->screenRecording_label_112, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->screenRecording_label_112, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->screenRecording_label_112, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes screenRecording_cont_ch31
	ui->screenRecording_cont_ch31 = lv_obj_create(ui->screenRecording_cont_10);
	lv_obj_set_pos(ui->screenRecording_cont_ch31, 13, 1505);
	lv_obj_set_size(ui->screenRecording_cont_ch31, 210, 46);
	lv_obj_set_scrollbar_mode(ui->screenRecording_cont_ch31, LV_SCROLLBAR_MODE_OFF);

	//Write style for screenRecording_cont_ch31, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->screenRecording_cont_ch31, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_opa(ui->screenRecording_cont_ch31, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_color(ui->screenRecording_cont_ch31, lv_color_hex(0x2195f6), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_side(ui->screenRecording_cont_ch31, LV_BORDER_SIDE_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->screenRecording_cont_ch31, 4, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->screenRecording_cont_ch31, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui->screenRecording_cont_ch31, lv_color_hex(0x292831), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->screenRecording_cont_ch31, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->screenRecording_cont_ch31, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->screenRecording_cont_ch31, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->screenRecording_cont_ch31, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->screenRecording_cont_ch31, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes screenRecording_label_ch_31
	ui->screenRecording_label_ch_31 = lv_label_create(ui->screenRecording_cont_ch31);
	lv_label_set_text(ui->screenRecording_label_ch_31, "CH: 31");
	lv_label_set_long_mode(ui->screenRecording_label_ch_31, LV_LABEL_LONG_WRAP);
	lv_obj_set_pos(ui->screenRecording_label_ch_31, 137, 5);
	lv_obj_set_size(ui->screenRecording_label_ch_31, 66, 32);

	//Write style for screenRecording_label_ch_31, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->screenRecording_label_ch_31, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->screenRecording_label_ch_31, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->screenRecording_label_ch_31, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->screenRecording_label_ch_31, &lv_font_MontserratRegular_20, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->screenRecording_label_ch_31, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_line_space(ui->screenRecording_label_ch_31, 1, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->screenRecording_label_ch_31, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->screenRecording_label_ch_31, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->screenRecording_label_ch_31, 7, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->screenRecording_label_ch_31, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->screenRecording_label_ch_31, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->screenRecording_label_ch_31, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->screenRecording_label_ch_31, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes screenRecording_label_spk_31
	ui->screenRecording_label_spk_31 = lv_label_create(ui->screenRecording_cont_ch31);
	lv_label_set_text(ui->screenRecording_label_spk_31, "");
	lv_label_set_long_mode(ui->screenRecording_label_spk_31, LV_LABEL_LONG_WRAP);
	lv_obj_set_pos(ui->screenRecording_label_spk_31, 100, 4);
	lv_obj_set_size(ui->screenRecording_label_spk_31, 25, 32);

	//Write style for screenRecording_label_spk_31, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->screenRecording_label_spk_31, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->screenRecording_label_spk_31, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->screenRecording_label_spk_31, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->screenRecording_label_spk_31, &lv_font_FontAwesome5ProRegular_400_22, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->screenRecording_label_spk_31, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_line_space(ui->screenRecording_label_spk_31, 1, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->screenRecording_label_spk_31, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->screenRecording_label_spk_31, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->screenRecording_label_spk_31, 6, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->screenRecording_label_spk_31, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->screenRecording_label_spk_31, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->screenRecording_label_spk_31, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->screenRecording_label_spk_31, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes screenRecording_sw_31
	ui->screenRecording_sw_31 = lv_switch_create(ui->screenRecording_cont_ch31);
	lv_obj_set_pos(ui->screenRecording_sw_31, 46, 12);
	lv_obj_set_size(ui->screenRecording_sw_31, 40, 20);

	//Write style for screenRecording_sw_31, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_bg_opa(ui->screenRecording_sw_31, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui->screenRecording_sw_31, lv_color_hex(0x41485a), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_width(ui->screenRecording_sw_31, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->screenRecording_sw_31, 10, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->screenRecording_sw_31, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write style for screenRecording_sw_31, Part: LV_PART_INDICATOR, State: LV_STATE_CHECKED.
	lv_obj_set_style_bg_opa(ui->screenRecording_sw_31, 255, LV_PART_INDICATOR|LV_STATE_CHECKED);
	lv_obj_set_style_bg_color(ui->screenRecording_sw_31, lv_color_hex(0x2195f6), LV_PART_INDICATOR|LV_STATE_CHECKED);
	lv_obj_set_style_border_width(ui->screenRecording_sw_31, 0, LV_PART_INDICATOR|LV_STATE_CHECKED);

	//Write style for screenRecording_sw_31, Part: LV_PART_KNOB, State: LV_STATE_DEFAULT.
	lv_obj_set_style_bg_opa(ui->screenRecording_sw_31, 255, LV_PART_KNOB|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui->screenRecording_sw_31, lv_color_hex(0x292831), LV_PART_KNOB|LV_STATE_DEFAULT);
	lv_obj_set_style_border_width(ui->screenRecording_sw_31, 0, LV_PART_KNOB|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->screenRecording_sw_31, 10, LV_PART_KNOB|LV_STATE_DEFAULT);

	//Write codes screenRecording_label_115
	ui->screenRecording_label_115 = lv_label_create(ui->screenRecording_cont_ch31);
	lv_label_set_text(ui->screenRecording_label_115, "31");
	lv_label_set_long_mode(ui->screenRecording_label_115, LV_LABEL_LONG_WRAP);
	lv_obj_set_pos(ui->screenRecording_label_115, 4, 5);
	lv_obj_set_size(ui->screenRecording_label_115, 35, 32);

	//Write style for screenRecording_label_115, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->screenRecording_label_115, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->screenRecording_label_115, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->screenRecording_label_115, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->screenRecording_label_115, &lv_font_montserratMedium_24, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->screenRecording_label_115, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_line_space(ui->screenRecording_label_115, 1, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->screenRecording_label_115, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->screenRecording_label_115, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->screenRecording_label_115, 5, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->screenRecording_label_115, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->screenRecording_label_115, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->screenRecording_label_115, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->screenRecording_label_115, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes screenRecording_cont_ch32
	ui->screenRecording_cont_ch32 = lv_obj_create(ui->screenRecording_cont_10);
	lv_obj_set_pos(ui->screenRecording_cont_ch32, 13, 1555);
	lv_obj_set_size(ui->screenRecording_cont_ch32, 210, 46);
	lv_obj_set_scrollbar_mode(ui->screenRecording_cont_ch32, LV_SCROLLBAR_MODE_OFF);

	//Write style for screenRecording_cont_ch32, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->screenRecording_cont_ch32, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_opa(ui->screenRecording_cont_ch32, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_color(ui->screenRecording_cont_ch32, lv_color_hex(0x2195f6), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_side(ui->screenRecording_cont_ch32, LV_BORDER_SIDE_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->screenRecording_cont_ch32, 4, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->screenRecording_cont_ch32, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui->screenRecording_cont_ch32, lv_color_hex(0x292831), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->screenRecording_cont_ch32, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->screenRecording_cont_ch32, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->screenRecording_cont_ch32, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->screenRecording_cont_ch32, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->screenRecording_cont_ch32, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes screenRecording_label_ch_32
	ui->screenRecording_label_ch_32 = lv_label_create(ui->screenRecording_cont_ch32);
	lv_label_set_text(ui->screenRecording_label_ch_32, "CH: 31");
	lv_label_set_long_mode(ui->screenRecording_label_ch_32, LV_LABEL_LONG_WRAP);
	lv_obj_set_pos(ui->screenRecording_label_ch_32, 137, 5);
	lv_obj_set_size(ui->screenRecording_label_ch_32, 66, 32);

	//Write style for screenRecording_label_ch_32, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->screenRecording_label_ch_32, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->screenRecording_label_ch_32, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->screenRecording_label_ch_32, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->screenRecording_label_ch_32, &lv_font_MontserratRegular_20, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->screenRecording_label_ch_32, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_line_space(ui->screenRecording_label_ch_32, 1, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->screenRecording_label_ch_32, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->screenRecording_label_ch_32, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->screenRecording_label_ch_32, 7, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->screenRecording_label_ch_32, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->screenRecording_label_ch_32, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->screenRecording_label_ch_32, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->screenRecording_label_ch_32, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes screenRecording_label_spk_32
	ui->screenRecording_label_spk_32 = lv_label_create(ui->screenRecording_cont_ch32);
	lv_label_set_text(ui->screenRecording_label_spk_32, "");
	lv_label_set_long_mode(ui->screenRecording_label_spk_32, LV_LABEL_LONG_WRAP);
	lv_obj_set_pos(ui->screenRecording_label_spk_32, 100, 4);
	lv_obj_set_size(ui->screenRecording_label_spk_32, 25, 32);

	//Write style for screenRecording_label_spk_32, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->screenRecording_label_spk_32, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->screenRecording_label_spk_32, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->screenRecording_label_spk_32, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->screenRecording_label_spk_32, &lv_font_FontAwesome5ProRegular_400_22, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->screenRecording_label_spk_32, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_line_space(ui->screenRecording_label_spk_32, 1, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->screenRecording_label_spk_32, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->screenRecording_label_spk_32, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->screenRecording_label_spk_32, 6, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->screenRecording_label_spk_32, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->screenRecording_label_spk_32, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->screenRecording_label_spk_32, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->screenRecording_label_spk_32, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes screenRecording_sw_32
	ui->screenRecording_sw_32 = lv_switch_create(ui->screenRecording_cont_ch32);
	lv_obj_set_pos(ui->screenRecording_sw_32, 46, 12);
	lv_obj_set_size(ui->screenRecording_sw_32, 40, 20);

	//Write style for screenRecording_sw_32, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_bg_opa(ui->screenRecording_sw_32, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui->screenRecording_sw_32, lv_color_hex(0x41485a), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_width(ui->screenRecording_sw_32, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->screenRecording_sw_32, 10, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->screenRecording_sw_32, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write style for screenRecording_sw_32, Part: LV_PART_INDICATOR, State: LV_STATE_CHECKED.
	lv_obj_set_style_bg_opa(ui->screenRecording_sw_32, 255, LV_PART_INDICATOR|LV_STATE_CHECKED);
	lv_obj_set_style_bg_color(ui->screenRecording_sw_32, lv_color_hex(0x2195f6), LV_PART_INDICATOR|LV_STATE_CHECKED);
	lv_obj_set_style_border_width(ui->screenRecording_sw_32, 0, LV_PART_INDICATOR|LV_STATE_CHECKED);

	//Write style for screenRecording_sw_32, Part: LV_PART_KNOB, State: LV_STATE_DEFAULT.
	lv_obj_set_style_bg_opa(ui->screenRecording_sw_32, 255, LV_PART_KNOB|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui->screenRecording_sw_32, lv_color_hex(0x292831), LV_PART_KNOB|LV_STATE_DEFAULT);
	lv_obj_set_style_border_width(ui->screenRecording_sw_32, 0, LV_PART_KNOB|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->screenRecording_sw_32, 10, LV_PART_KNOB|LV_STATE_DEFAULT);

	//Write codes screenRecording_label_118
	ui->screenRecording_label_118 = lv_label_create(ui->screenRecording_cont_ch32);
	lv_label_set_text(ui->screenRecording_label_118, "32");
	lv_label_set_long_mode(ui->screenRecording_label_118, LV_LABEL_LONG_WRAP);
	lv_obj_set_pos(ui->screenRecording_label_118, 4, 5);
	lv_obj_set_size(ui->screenRecording_label_118, 35, 32);

	//Write style for screenRecording_label_118, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->screenRecording_label_118, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->screenRecording_label_118, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->screenRecording_label_118, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->screenRecording_label_118, &lv_font_montserratMedium_24, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->screenRecording_label_118, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_line_space(ui->screenRecording_label_118, 1, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->screenRecording_label_118, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->screenRecording_label_118, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->screenRecording_label_118, 5, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->screenRecording_label_118, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->screenRecording_label_118, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->screenRecording_label_118, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->screenRecording_label_118, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes screenRecording_cont_background_opaque
	ui->screenRecording_cont_background_opaque = lv_obj_create(ui->screenRecording);
	lv_obj_set_pos(ui->screenRecording_cont_background_opaque, 0, 0);
	lv_obj_set_size(ui->screenRecording_cont_background_opaque, 240, 240);
	lv_obj_set_scrollbar_mode(ui->screenRecording_cont_background_opaque, LV_SCROLLBAR_MODE_OFF);
	lv_obj_add_flag(ui->screenRecording_cont_background_opaque, LV_OBJ_FLAG_HIDDEN);
	lv_obj_add_flag(ui->screenRecording_cont_background_opaque, LV_OBJ_FLAG_HIDDEN);

	//Write style for screenRecording_cont_background_opaque, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->screenRecording_cont_background_opaque, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->screenRecording_cont_background_opaque, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->screenRecording_cont_background_opaque, 103, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui->screenRecording_cont_background_opaque, lv_color_hex(0x828282), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->screenRecording_cont_background_opaque, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->screenRecording_cont_background_opaque, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->screenRecording_cont_background_opaque, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->screenRecording_cont_background_opaque, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->screenRecording_cont_background_opaque, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes screenRecording_cont_recording
	ui->screenRecording_cont_recording = lv_obj_create(ui->screenRecording);
	lv_obj_set_pos(ui->screenRecording_cont_recording, 14, 59);
	lv_obj_set_size(ui->screenRecording_cont_recording, 212, 122);
	lv_obj_set_scrollbar_mode(ui->screenRecording_cont_recording, LV_SCROLLBAR_MODE_OFF);

	//Write style for screenRecording_cont_recording, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->screenRecording_cont_recording, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_opa(ui->screenRecording_cont_recording, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_color(ui->screenRecording_cont_recording, lv_color_hex(0xff0000), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_side(ui->screenRecording_cont_recording, LV_BORDER_SIDE_FULL, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->screenRecording_cont_recording, 10, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->screenRecording_cont_recording, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui->screenRecording_cont_recording, lv_color_hex(0x292831), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->screenRecording_cont_recording, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->screenRecording_cont_recording, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->screenRecording_cont_recording, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->screenRecording_cont_recording, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->screenRecording_cont_recording, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes screenRecording_label_recording_time
	ui->screenRecording_label_recording_time = lv_label_create(ui->screenRecording_cont_recording);
	lv_label_set_text(ui->screenRecording_label_recording_time, "00:00.00");
	lv_label_set_long_mode(ui->screenRecording_label_recording_time, LV_LABEL_LONG_WRAP);
	lv_obj_set_pos(ui->screenRecording_label_recording_time, 4, 37);
	lv_obj_set_size(ui->screenRecording_label_recording_time, 200, 48);

	//Write style for screenRecording_label_recording_time, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->screenRecording_label_recording_time, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->screenRecording_label_recording_time, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->screenRecording_label_recording_time, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->screenRecording_label_recording_time, &lv_font_digital7mono_46, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->screenRecording_label_recording_time, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_line_space(ui->screenRecording_label_recording_time, 1, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->screenRecording_label_recording_time, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->screenRecording_label_recording_time, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->screenRecording_label_recording_time, 1, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->screenRecording_label_recording_time, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->screenRecording_label_recording_time, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->screenRecording_label_recording_time, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->screenRecording_label_recording_time, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes screenRecording_label_6
	ui->screenRecording_label_6 = lv_label_create(ui->screenRecording_cont_recording);
	lv_label_set_text(ui->screenRecording_label_6, "Recording");
	lv_label_set_long_mode(ui->screenRecording_label_6, LV_LABEL_LONG_WRAP);
	lv_obj_set_pos(ui->screenRecording_label_6, 4, 8);
	lv_obj_set_size(ui->screenRecording_label_6, 200, 28);

	//Write style for screenRecording_label_6, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->screenRecording_label_6, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->screenRecording_label_6, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->screenRecording_label_6, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->screenRecording_label_6, &lv_font_montserratMedium_16, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->screenRecording_label_6, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_line_space(ui->screenRecording_label_6, 1, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->screenRecording_label_6, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->screenRecording_label_6, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->screenRecording_label_6, 6, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->screenRecording_label_6, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->screenRecording_label_6, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->screenRecording_label_6, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->screenRecording_label_6, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes screenRecording_label_recording_remaining
	ui->screenRecording_label_recording_remaining = lv_label_create(ui->screenRecording_cont_recording);
	lv_label_set_text(ui->screenRecording_label_recording_remaining, "Remaining: 00:00:00");
	lv_label_set_long_mode(ui->screenRecording_label_recording_remaining, LV_LABEL_LONG_WRAP);
	lv_obj_set_pos(ui->screenRecording_label_recording_remaining, 4, 84);
	lv_obj_set_size(ui->screenRecording_label_recording_remaining, 200, 28);

	//Write style for screenRecording_label_recording_remaining, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->screenRecording_label_recording_remaining, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->screenRecording_label_recording_remaining, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->screenRecording_label_recording_remaining, lv_color_hex(0xa4a4a4), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->screenRecording_label_recording_remaining, &lv_font_montserratMedium_16, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->screenRecording_label_recording_remaining, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_line_space(ui->screenRecording_label_recording_remaining, 1, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->screenRecording_label_recording_remaining, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->screenRecording_label_recording_remaining, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->screenRecording_label_recording_remaining, 6, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->screenRecording_label_recording_remaining, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->screenRecording_label_recording_remaining, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->screenRecording_label_recording_remaining, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->screenRecording_label_recording_remaining, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Update current screen layout.
	lv_obj_update_layout(ui->screenRecording);

	
	//Init events for screen.
	events_init_screenRecording(ui);
}
