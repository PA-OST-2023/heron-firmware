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
	lv_obj_set_pos(ui->screenRecording_label_ethernet, 135, 6);
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
	lv_bar_set_value(ui->screenRecording_bar_volume, 50, LV_ANIM_OFF);
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
	lv_obj_set_pos(ui->screenRecording_label_usb, 108, 6);
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
	lv_obj_set_pos(ui->screenRecording_label_sd_card, 159, 6);
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
	lv_bar_set_value(ui->screenRecording_bar_disk_storage, 50, LV_ANIM_OFF);
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
	lv_label_set_text(ui->screenRecording_label_disk_storage, "3.4 / 31.8 GB");
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

	//Write codes screenRecording_label_15
	ui->screenRecording_label_15 = lv_label_create(ui->screenRecording_cont_ch01);
	lv_label_set_text(ui->screenRecording_label_15, "CH: 31");
	lv_label_set_long_mode(ui->screenRecording_label_15, LV_LABEL_LONG_WRAP);
	lv_obj_set_pos(ui->screenRecording_label_15, 137, 5);
	lv_obj_set_size(ui->screenRecording_label_15, 66, 32);

	//Write style for screenRecording_label_15, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->screenRecording_label_15, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->screenRecording_label_15, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->screenRecording_label_15, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->screenRecording_label_15, &lv_font_MontserratRegular_20, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->screenRecording_label_15, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_line_space(ui->screenRecording_label_15, 1, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->screenRecording_label_15, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->screenRecording_label_15, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->screenRecording_label_15, 7, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->screenRecording_label_15, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->screenRecording_label_15, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->screenRecording_label_15, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->screenRecording_label_15, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes screenRecording_label_14
	ui->screenRecording_label_14 = lv_label_create(ui->screenRecording_cont_ch01);
	lv_label_set_text(ui->screenRecording_label_14, "");
	lv_label_set_long_mode(ui->screenRecording_label_14, LV_LABEL_LONG_WRAP);
	lv_obj_set_pos(ui->screenRecording_label_14, 100, 4);
	lv_obj_set_size(ui->screenRecording_label_14, 25, 32);

	//Write style for screenRecording_label_14, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->screenRecording_label_14, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->screenRecording_label_14, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->screenRecording_label_14, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->screenRecording_label_14, &lv_font_FontAwesome5ProRegular_400_22, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->screenRecording_label_14, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_line_space(ui->screenRecording_label_14, 1, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->screenRecording_label_14, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->screenRecording_label_14, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->screenRecording_label_14, 6, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->screenRecording_label_14, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->screenRecording_label_14, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->screenRecording_label_14, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->screenRecording_label_14, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes screenRecording_sw_2
	ui->screenRecording_sw_2 = lv_switch_create(ui->screenRecording_cont_ch01);
	lv_obj_set_pos(ui->screenRecording_sw_2, 46, 12);
	lv_obj_set_size(ui->screenRecording_sw_2, 40, 20);

	//Write style for screenRecording_sw_2, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_bg_opa(ui->screenRecording_sw_2, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui->screenRecording_sw_2, lv_color_hex(0x41485a), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_width(ui->screenRecording_sw_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->screenRecording_sw_2, 10, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->screenRecording_sw_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write style for screenRecording_sw_2, Part: LV_PART_INDICATOR, State: LV_STATE_CHECKED.
	lv_obj_set_style_bg_opa(ui->screenRecording_sw_2, 255, LV_PART_INDICATOR|LV_STATE_CHECKED);
	lv_obj_set_style_bg_color(ui->screenRecording_sw_2, lv_color_hex(0x2195f6), LV_PART_INDICATOR|LV_STATE_CHECKED);
	lv_obj_set_style_border_width(ui->screenRecording_sw_2, 0, LV_PART_INDICATOR|LV_STATE_CHECKED);

	//Write style for screenRecording_sw_2, Part: LV_PART_KNOB, State: LV_STATE_DEFAULT.
	lv_obj_set_style_bg_opa(ui->screenRecording_sw_2, 255, LV_PART_KNOB|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui->screenRecording_sw_2, lv_color_hex(0x292831), LV_PART_KNOB|LV_STATE_DEFAULT);
	lv_obj_set_style_border_width(ui->screenRecording_sw_2, 0, LV_PART_KNOB|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->screenRecording_sw_2, 10, LV_PART_KNOB|LV_STATE_DEFAULT);

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

	//Write codes screenRecording_label_30
	ui->screenRecording_label_30 = lv_label_create(ui->screenRecording_cont_ch02);
	lv_label_set_text(ui->screenRecording_label_30, "CH: 31");
	lv_label_set_long_mode(ui->screenRecording_label_30, LV_LABEL_LONG_WRAP);
	lv_obj_set_pos(ui->screenRecording_label_30, 137, 5);
	lv_obj_set_size(ui->screenRecording_label_30, 66, 32);

	//Write style for screenRecording_label_30, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->screenRecording_label_30, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->screenRecording_label_30, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->screenRecording_label_30, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->screenRecording_label_30, &lv_font_MontserratRegular_20, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->screenRecording_label_30, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_line_space(ui->screenRecording_label_30, 1, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->screenRecording_label_30, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->screenRecording_label_30, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->screenRecording_label_30, 7, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->screenRecording_label_30, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->screenRecording_label_30, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->screenRecording_label_30, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->screenRecording_label_30, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes screenRecording_label_29
	ui->screenRecording_label_29 = lv_label_create(ui->screenRecording_cont_ch02);
	lv_label_set_text(ui->screenRecording_label_29, "");
	lv_label_set_long_mode(ui->screenRecording_label_29, LV_LABEL_LONG_WRAP);
	lv_obj_set_pos(ui->screenRecording_label_29, 100, 4);
	lv_obj_set_size(ui->screenRecording_label_29, 25, 32);

	//Write style for screenRecording_label_29, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->screenRecording_label_29, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->screenRecording_label_29, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->screenRecording_label_29, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->screenRecording_label_29, &lv_font_FontAwesome5ProRegular_400_22, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->screenRecording_label_29, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_line_space(ui->screenRecording_label_29, 1, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->screenRecording_label_29, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->screenRecording_label_29, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->screenRecording_label_29, 6, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->screenRecording_label_29, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->screenRecording_label_29, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->screenRecording_label_29, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->screenRecording_label_29, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes screenRecording_sw_7
	ui->screenRecording_sw_7 = lv_switch_create(ui->screenRecording_cont_ch02);
	lv_obj_set_pos(ui->screenRecording_sw_7, 46, 12);
	lv_obj_set_size(ui->screenRecording_sw_7, 40, 20);

	//Write style for screenRecording_sw_7, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_bg_opa(ui->screenRecording_sw_7, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui->screenRecording_sw_7, lv_color_hex(0x41485a), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_width(ui->screenRecording_sw_7, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->screenRecording_sw_7, 10, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->screenRecording_sw_7, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write style for screenRecording_sw_7, Part: LV_PART_INDICATOR, State: LV_STATE_CHECKED.
	lv_obj_set_style_bg_opa(ui->screenRecording_sw_7, 255, LV_PART_INDICATOR|LV_STATE_CHECKED);
	lv_obj_set_style_bg_color(ui->screenRecording_sw_7, lv_color_hex(0x2195f6), LV_PART_INDICATOR|LV_STATE_CHECKED);
	lv_obj_set_style_border_width(ui->screenRecording_sw_7, 0, LV_PART_INDICATOR|LV_STATE_CHECKED);

	//Write style for screenRecording_sw_7, Part: LV_PART_KNOB, State: LV_STATE_DEFAULT.
	lv_obj_set_style_bg_opa(ui->screenRecording_sw_7, 255, LV_PART_KNOB|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui->screenRecording_sw_7, lv_color_hex(0x292831), LV_PART_KNOB|LV_STATE_DEFAULT);
	lv_obj_set_style_border_width(ui->screenRecording_sw_7, 0, LV_PART_KNOB|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->screenRecording_sw_7, 10, LV_PART_KNOB|LV_STATE_DEFAULT);

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

	//Write codes screenRecording_label_33
	ui->screenRecording_label_33 = lv_label_create(ui->screenRecording_cont_ch03);
	lv_label_set_text(ui->screenRecording_label_33, "CH: 31");
	lv_label_set_long_mode(ui->screenRecording_label_33, LV_LABEL_LONG_WRAP);
	lv_obj_set_pos(ui->screenRecording_label_33, 137, 5);
	lv_obj_set_size(ui->screenRecording_label_33, 66, 32);

	//Write style for screenRecording_label_33, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->screenRecording_label_33, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->screenRecording_label_33, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->screenRecording_label_33, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->screenRecording_label_33, &lv_font_MontserratRegular_20, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->screenRecording_label_33, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_line_space(ui->screenRecording_label_33, 1, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->screenRecording_label_33, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->screenRecording_label_33, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->screenRecording_label_33, 7, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->screenRecording_label_33, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->screenRecording_label_33, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->screenRecording_label_33, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->screenRecording_label_33, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes screenRecording_label_32
	ui->screenRecording_label_32 = lv_label_create(ui->screenRecording_cont_ch03);
	lv_label_set_text(ui->screenRecording_label_32, "");
	lv_label_set_long_mode(ui->screenRecording_label_32, LV_LABEL_LONG_WRAP);
	lv_obj_set_pos(ui->screenRecording_label_32, 100, 4);
	lv_obj_set_size(ui->screenRecording_label_32, 25, 32);

	//Write style for screenRecording_label_32, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->screenRecording_label_32, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->screenRecording_label_32, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->screenRecording_label_32, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->screenRecording_label_32, &lv_font_FontAwesome5ProRegular_400_22, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->screenRecording_label_32, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_line_space(ui->screenRecording_label_32, 1, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->screenRecording_label_32, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->screenRecording_label_32, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->screenRecording_label_32, 6, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->screenRecording_label_32, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->screenRecording_label_32, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->screenRecording_label_32, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->screenRecording_label_32, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes screenRecording_sw_8
	ui->screenRecording_sw_8 = lv_switch_create(ui->screenRecording_cont_ch03);
	lv_obj_set_pos(ui->screenRecording_sw_8, 46, 12);
	lv_obj_set_size(ui->screenRecording_sw_8, 40, 20);

	//Write style for screenRecording_sw_8, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_bg_opa(ui->screenRecording_sw_8, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui->screenRecording_sw_8, lv_color_hex(0x41485a), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_width(ui->screenRecording_sw_8, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->screenRecording_sw_8, 10, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->screenRecording_sw_8, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write style for screenRecording_sw_8, Part: LV_PART_INDICATOR, State: LV_STATE_CHECKED.
	lv_obj_set_style_bg_opa(ui->screenRecording_sw_8, 255, LV_PART_INDICATOR|LV_STATE_CHECKED);
	lv_obj_set_style_bg_color(ui->screenRecording_sw_8, lv_color_hex(0x2195f6), LV_PART_INDICATOR|LV_STATE_CHECKED);
	lv_obj_set_style_border_width(ui->screenRecording_sw_8, 0, LV_PART_INDICATOR|LV_STATE_CHECKED);

	//Write style for screenRecording_sw_8, Part: LV_PART_KNOB, State: LV_STATE_DEFAULT.
	lv_obj_set_style_bg_opa(ui->screenRecording_sw_8, 255, LV_PART_KNOB|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui->screenRecording_sw_8, lv_color_hex(0x292831), LV_PART_KNOB|LV_STATE_DEFAULT);
	lv_obj_set_style_border_width(ui->screenRecording_sw_8, 0, LV_PART_KNOB|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->screenRecording_sw_8, 10, LV_PART_KNOB|LV_STATE_DEFAULT);

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

	//Write codes screenRecording_label_36
	ui->screenRecording_label_36 = lv_label_create(ui->screenRecording_cont_ch04);
	lv_label_set_text(ui->screenRecording_label_36, "CH: 31");
	lv_label_set_long_mode(ui->screenRecording_label_36, LV_LABEL_LONG_WRAP);
	lv_obj_set_pos(ui->screenRecording_label_36, 137, 5);
	lv_obj_set_size(ui->screenRecording_label_36, 66, 32);

	//Write style for screenRecording_label_36, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->screenRecording_label_36, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->screenRecording_label_36, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->screenRecording_label_36, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->screenRecording_label_36, &lv_font_MontserratRegular_20, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->screenRecording_label_36, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_line_space(ui->screenRecording_label_36, 1, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->screenRecording_label_36, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->screenRecording_label_36, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->screenRecording_label_36, 7, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->screenRecording_label_36, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->screenRecording_label_36, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->screenRecording_label_36, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->screenRecording_label_36, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes screenRecording_label_35
	ui->screenRecording_label_35 = lv_label_create(ui->screenRecording_cont_ch04);
	lv_label_set_text(ui->screenRecording_label_35, "");
	lv_label_set_long_mode(ui->screenRecording_label_35, LV_LABEL_LONG_WRAP);
	lv_obj_set_pos(ui->screenRecording_label_35, 100, 4);
	lv_obj_set_size(ui->screenRecording_label_35, 25, 32);

	//Write style for screenRecording_label_35, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->screenRecording_label_35, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->screenRecording_label_35, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->screenRecording_label_35, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->screenRecording_label_35, &lv_font_FontAwesome5ProRegular_400_22, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->screenRecording_label_35, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_line_space(ui->screenRecording_label_35, 1, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->screenRecording_label_35, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->screenRecording_label_35, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->screenRecording_label_35, 6, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->screenRecording_label_35, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->screenRecording_label_35, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->screenRecording_label_35, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->screenRecording_label_35, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes screenRecording_sw_9
	ui->screenRecording_sw_9 = lv_switch_create(ui->screenRecording_cont_ch04);
	lv_obj_set_pos(ui->screenRecording_sw_9, 46, 12);
	lv_obj_set_size(ui->screenRecording_sw_9, 40, 20);

	//Write style for screenRecording_sw_9, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_bg_opa(ui->screenRecording_sw_9, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui->screenRecording_sw_9, lv_color_hex(0x41485a), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_width(ui->screenRecording_sw_9, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->screenRecording_sw_9, 10, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->screenRecording_sw_9, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write style for screenRecording_sw_9, Part: LV_PART_INDICATOR, State: LV_STATE_CHECKED.
	lv_obj_set_style_bg_opa(ui->screenRecording_sw_9, 255, LV_PART_INDICATOR|LV_STATE_CHECKED);
	lv_obj_set_style_bg_color(ui->screenRecording_sw_9, lv_color_hex(0x2195f6), LV_PART_INDICATOR|LV_STATE_CHECKED);
	lv_obj_set_style_border_width(ui->screenRecording_sw_9, 0, LV_PART_INDICATOR|LV_STATE_CHECKED);

	//Write style for screenRecording_sw_9, Part: LV_PART_KNOB, State: LV_STATE_DEFAULT.
	lv_obj_set_style_bg_opa(ui->screenRecording_sw_9, 255, LV_PART_KNOB|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui->screenRecording_sw_9, lv_color_hex(0x292831), LV_PART_KNOB|LV_STATE_DEFAULT);
	lv_obj_set_style_border_width(ui->screenRecording_sw_9, 0, LV_PART_KNOB|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->screenRecording_sw_9, 10, LV_PART_KNOB|LV_STATE_DEFAULT);

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

	//Write codes screenRecording_label_39
	ui->screenRecording_label_39 = lv_label_create(ui->screenRecording_cont_ch05);
	lv_label_set_text(ui->screenRecording_label_39, "CH: 31");
	lv_label_set_long_mode(ui->screenRecording_label_39, LV_LABEL_LONG_WRAP);
	lv_obj_set_pos(ui->screenRecording_label_39, 137, 5);
	lv_obj_set_size(ui->screenRecording_label_39, 66, 32);

	//Write style for screenRecording_label_39, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->screenRecording_label_39, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->screenRecording_label_39, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->screenRecording_label_39, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->screenRecording_label_39, &lv_font_MontserratRegular_20, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->screenRecording_label_39, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_line_space(ui->screenRecording_label_39, 1, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->screenRecording_label_39, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->screenRecording_label_39, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->screenRecording_label_39, 7, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->screenRecording_label_39, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->screenRecording_label_39, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->screenRecording_label_39, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->screenRecording_label_39, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes screenRecording_label_38
	ui->screenRecording_label_38 = lv_label_create(ui->screenRecording_cont_ch05);
	lv_label_set_text(ui->screenRecording_label_38, "");
	lv_label_set_long_mode(ui->screenRecording_label_38, LV_LABEL_LONG_WRAP);
	lv_obj_set_pos(ui->screenRecording_label_38, 100, 4);
	lv_obj_set_size(ui->screenRecording_label_38, 25, 32);

	//Write style for screenRecording_label_38, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->screenRecording_label_38, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->screenRecording_label_38, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->screenRecording_label_38, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->screenRecording_label_38, &lv_font_FontAwesome5ProRegular_400_22, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->screenRecording_label_38, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_line_space(ui->screenRecording_label_38, 1, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->screenRecording_label_38, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->screenRecording_label_38, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->screenRecording_label_38, 6, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->screenRecording_label_38, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->screenRecording_label_38, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->screenRecording_label_38, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->screenRecording_label_38, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes screenRecording_sw_10
	ui->screenRecording_sw_10 = lv_switch_create(ui->screenRecording_cont_ch05);
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

	//Write codes screenRecording_label_42
	ui->screenRecording_label_42 = lv_label_create(ui->screenRecording_cont_ch06);
	lv_label_set_text(ui->screenRecording_label_42, "CH: 31");
	lv_label_set_long_mode(ui->screenRecording_label_42, LV_LABEL_LONG_WRAP);
	lv_obj_set_pos(ui->screenRecording_label_42, 137, 5);
	lv_obj_set_size(ui->screenRecording_label_42, 66, 32);

	//Write style for screenRecording_label_42, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->screenRecording_label_42, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->screenRecording_label_42, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->screenRecording_label_42, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->screenRecording_label_42, &lv_font_MontserratRegular_20, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->screenRecording_label_42, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_line_space(ui->screenRecording_label_42, 1, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->screenRecording_label_42, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->screenRecording_label_42, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->screenRecording_label_42, 7, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->screenRecording_label_42, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->screenRecording_label_42, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->screenRecording_label_42, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->screenRecording_label_42, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes screenRecording_label_41
	ui->screenRecording_label_41 = lv_label_create(ui->screenRecording_cont_ch06);
	lv_label_set_text(ui->screenRecording_label_41, "");
	lv_label_set_long_mode(ui->screenRecording_label_41, LV_LABEL_LONG_WRAP);
	lv_obj_set_pos(ui->screenRecording_label_41, 100, 4);
	lv_obj_set_size(ui->screenRecording_label_41, 25, 32);

	//Write style for screenRecording_label_41, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->screenRecording_label_41, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->screenRecording_label_41, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->screenRecording_label_41, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->screenRecording_label_41, &lv_font_FontAwesome5ProRegular_400_22, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->screenRecording_label_41, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_line_space(ui->screenRecording_label_41, 1, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->screenRecording_label_41, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->screenRecording_label_41, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->screenRecording_label_41, 6, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->screenRecording_label_41, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->screenRecording_label_41, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->screenRecording_label_41, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->screenRecording_label_41, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes screenRecording_sw_11
	ui->screenRecording_sw_11 = lv_switch_create(ui->screenRecording_cont_ch06);
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

	//Write codes screenRecording_label_45
	ui->screenRecording_label_45 = lv_label_create(ui->screenRecording_cont_ch07);
	lv_label_set_text(ui->screenRecording_label_45, "CH: 31");
	lv_label_set_long_mode(ui->screenRecording_label_45, LV_LABEL_LONG_WRAP);
	lv_obj_set_pos(ui->screenRecording_label_45, 137, 5);
	lv_obj_set_size(ui->screenRecording_label_45, 66, 32);

	//Write style for screenRecording_label_45, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->screenRecording_label_45, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->screenRecording_label_45, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->screenRecording_label_45, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->screenRecording_label_45, &lv_font_MontserratRegular_20, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->screenRecording_label_45, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_line_space(ui->screenRecording_label_45, 1, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->screenRecording_label_45, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->screenRecording_label_45, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->screenRecording_label_45, 7, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->screenRecording_label_45, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->screenRecording_label_45, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->screenRecording_label_45, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->screenRecording_label_45, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes screenRecording_label_44
	ui->screenRecording_label_44 = lv_label_create(ui->screenRecording_cont_ch07);
	lv_label_set_text(ui->screenRecording_label_44, "");
	lv_label_set_long_mode(ui->screenRecording_label_44, LV_LABEL_LONG_WRAP);
	lv_obj_set_pos(ui->screenRecording_label_44, 100, 4);
	lv_obj_set_size(ui->screenRecording_label_44, 25, 32);

	//Write style for screenRecording_label_44, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->screenRecording_label_44, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->screenRecording_label_44, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->screenRecording_label_44, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->screenRecording_label_44, &lv_font_FontAwesome5ProRegular_400_22, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->screenRecording_label_44, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_line_space(ui->screenRecording_label_44, 1, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->screenRecording_label_44, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->screenRecording_label_44, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->screenRecording_label_44, 6, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->screenRecording_label_44, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->screenRecording_label_44, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->screenRecording_label_44, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->screenRecording_label_44, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes screenRecording_sw_12
	ui->screenRecording_sw_12 = lv_switch_create(ui->screenRecording_cont_ch07);
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

	//Write codes screenRecording_label_48
	ui->screenRecording_label_48 = lv_label_create(ui->screenRecording_cont_ch08);
	lv_label_set_text(ui->screenRecording_label_48, "CH: 31");
	lv_label_set_long_mode(ui->screenRecording_label_48, LV_LABEL_LONG_WRAP);
	lv_obj_set_pos(ui->screenRecording_label_48, 137, 5);
	lv_obj_set_size(ui->screenRecording_label_48, 66, 32);

	//Write style for screenRecording_label_48, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->screenRecording_label_48, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->screenRecording_label_48, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->screenRecording_label_48, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->screenRecording_label_48, &lv_font_MontserratRegular_20, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->screenRecording_label_48, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_line_space(ui->screenRecording_label_48, 1, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->screenRecording_label_48, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->screenRecording_label_48, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->screenRecording_label_48, 7, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->screenRecording_label_48, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->screenRecording_label_48, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->screenRecording_label_48, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->screenRecording_label_48, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes screenRecording_label_47
	ui->screenRecording_label_47 = lv_label_create(ui->screenRecording_cont_ch08);
	lv_label_set_text(ui->screenRecording_label_47, "");
	lv_label_set_long_mode(ui->screenRecording_label_47, LV_LABEL_LONG_WRAP);
	lv_obj_set_pos(ui->screenRecording_label_47, 100, 4);
	lv_obj_set_size(ui->screenRecording_label_47, 25, 32);

	//Write style for screenRecording_label_47, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->screenRecording_label_47, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->screenRecording_label_47, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->screenRecording_label_47, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->screenRecording_label_47, &lv_font_FontAwesome5ProRegular_400_22, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->screenRecording_label_47, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_line_space(ui->screenRecording_label_47, 1, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->screenRecording_label_47, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->screenRecording_label_47, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->screenRecording_label_47, 6, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->screenRecording_label_47, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->screenRecording_label_47, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->screenRecording_label_47, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->screenRecording_label_47, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes screenRecording_sw_13
	ui->screenRecording_sw_13 = lv_switch_create(ui->screenRecording_cont_ch08);
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

	//Write codes screenRecording_label_51
	ui->screenRecording_label_51 = lv_label_create(ui->screenRecording_cont_ch09);
	lv_label_set_text(ui->screenRecording_label_51, "CH: 31");
	lv_label_set_long_mode(ui->screenRecording_label_51, LV_LABEL_LONG_WRAP);
	lv_obj_set_pos(ui->screenRecording_label_51, 137, 5);
	lv_obj_set_size(ui->screenRecording_label_51, 66, 32);

	//Write style for screenRecording_label_51, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->screenRecording_label_51, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->screenRecording_label_51, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->screenRecording_label_51, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->screenRecording_label_51, &lv_font_MontserratRegular_20, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->screenRecording_label_51, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_line_space(ui->screenRecording_label_51, 1, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->screenRecording_label_51, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->screenRecording_label_51, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->screenRecording_label_51, 7, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->screenRecording_label_51, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->screenRecording_label_51, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->screenRecording_label_51, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->screenRecording_label_51, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes screenRecording_label_50
	ui->screenRecording_label_50 = lv_label_create(ui->screenRecording_cont_ch09);
	lv_label_set_text(ui->screenRecording_label_50, "");
	lv_label_set_long_mode(ui->screenRecording_label_50, LV_LABEL_LONG_WRAP);
	lv_obj_set_pos(ui->screenRecording_label_50, 100, 4);
	lv_obj_set_size(ui->screenRecording_label_50, 25, 32);

	//Write style for screenRecording_label_50, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->screenRecording_label_50, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->screenRecording_label_50, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->screenRecording_label_50, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->screenRecording_label_50, &lv_font_FontAwesome5ProRegular_400_22, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->screenRecording_label_50, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_line_space(ui->screenRecording_label_50, 1, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->screenRecording_label_50, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->screenRecording_label_50, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->screenRecording_label_50, 6, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->screenRecording_label_50, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->screenRecording_label_50, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->screenRecording_label_50, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->screenRecording_label_50, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes screenRecording_sw_14
	ui->screenRecording_sw_14 = lv_switch_create(ui->screenRecording_cont_ch09);
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

	//Write codes screenRecording_label_54
	ui->screenRecording_label_54 = lv_label_create(ui->screenRecording_cont_ch10);
	lv_label_set_text(ui->screenRecording_label_54, "CH: 31");
	lv_label_set_long_mode(ui->screenRecording_label_54, LV_LABEL_LONG_WRAP);
	lv_obj_set_pos(ui->screenRecording_label_54, 137, 5);
	lv_obj_set_size(ui->screenRecording_label_54, 66, 32);

	//Write style for screenRecording_label_54, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->screenRecording_label_54, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->screenRecording_label_54, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->screenRecording_label_54, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->screenRecording_label_54, &lv_font_MontserratRegular_20, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->screenRecording_label_54, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_line_space(ui->screenRecording_label_54, 1, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->screenRecording_label_54, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->screenRecording_label_54, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->screenRecording_label_54, 7, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->screenRecording_label_54, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->screenRecording_label_54, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->screenRecording_label_54, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->screenRecording_label_54, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes screenRecording_label_53
	ui->screenRecording_label_53 = lv_label_create(ui->screenRecording_cont_ch10);
	lv_label_set_text(ui->screenRecording_label_53, "");
	lv_label_set_long_mode(ui->screenRecording_label_53, LV_LABEL_LONG_WRAP);
	lv_obj_set_pos(ui->screenRecording_label_53, 100, 4);
	lv_obj_set_size(ui->screenRecording_label_53, 25, 32);

	//Write style for screenRecording_label_53, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->screenRecording_label_53, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->screenRecording_label_53, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->screenRecording_label_53, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->screenRecording_label_53, &lv_font_FontAwesome5ProRegular_400_22, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->screenRecording_label_53, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_line_space(ui->screenRecording_label_53, 1, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->screenRecording_label_53, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->screenRecording_label_53, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->screenRecording_label_53, 6, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->screenRecording_label_53, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->screenRecording_label_53, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->screenRecording_label_53, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->screenRecording_label_53, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes screenRecording_sw_15
	ui->screenRecording_sw_15 = lv_switch_create(ui->screenRecording_cont_ch10);
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

	//Write codes screenRecording_label_57
	ui->screenRecording_label_57 = lv_label_create(ui->screenRecording_cont_ch11);
	lv_label_set_text(ui->screenRecording_label_57, "CH: 31");
	lv_label_set_long_mode(ui->screenRecording_label_57, LV_LABEL_LONG_WRAP);
	lv_obj_set_pos(ui->screenRecording_label_57, 137, 5);
	lv_obj_set_size(ui->screenRecording_label_57, 66, 32);

	//Write style for screenRecording_label_57, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->screenRecording_label_57, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->screenRecording_label_57, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->screenRecording_label_57, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->screenRecording_label_57, &lv_font_MontserratRegular_20, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->screenRecording_label_57, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_line_space(ui->screenRecording_label_57, 1, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->screenRecording_label_57, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->screenRecording_label_57, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->screenRecording_label_57, 7, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->screenRecording_label_57, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->screenRecording_label_57, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->screenRecording_label_57, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->screenRecording_label_57, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes screenRecording_label_56
	ui->screenRecording_label_56 = lv_label_create(ui->screenRecording_cont_ch11);
	lv_label_set_text(ui->screenRecording_label_56, "");
	lv_label_set_long_mode(ui->screenRecording_label_56, LV_LABEL_LONG_WRAP);
	lv_obj_set_pos(ui->screenRecording_label_56, 100, 4);
	lv_obj_set_size(ui->screenRecording_label_56, 25, 32);

	//Write style for screenRecording_label_56, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->screenRecording_label_56, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->screenRecording_label_56, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->screenRecording_label_56, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->screenRecording_label_56, &lv_font_FontAwesome5ProRegular_400_22, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->screenRecording_label_56, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_line_space(ui->screenRecording_label_56, 1, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->screenRecording_label_56, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->screenRecording_label_56, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->screenRecording_label_56, 6, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->screenRecording_label_56, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->screenRecording_label_56, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->screenRecording_label_56, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->screenRecording_label_56, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes screenRecording_sw_16
	ui->screenRecording_sw_16 = lv_switch_create(ui->screenRecording_cont_ch11);
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

	//Write codes screenRecording_label_60
	ui->screenRecording_label_60 = lv_label_create(ui->screenRecording_cont_ch12);
	lv_label_set_text(ui->screenRecording_label_60, "CH: 31");
	lv_label_set_long_mode(ui->screenRecording_label_60, LV_LABEL_LONG_WRAP);
	lv_obj_set_pos(ui->screenRecording_label_60, 137, 5);
	lv_obj_set_size(ui->screenRecording_label_60, 66, 32);

	//Write style for screenRecording_label_60, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->screenRecording_label_60, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->screenRecording_label_60, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->screenRecording_label_60, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->screenRecording_label_60, &lv_font_MontserratRegular_20, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->screenRecording_label_60, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_line_space(ui->screenRecording_label_60, 1, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->screenRecording_label_60, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->screenRecording_label_60, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->screenRecording_label_60, 7, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->screenRecording_label_60, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->screenRecording_label_60, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->screenRecording_label_60, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->screenRecording_label_60, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes screenRecording_label_59
	ui->screenRecording_label_59 = lv_label_create(ui->screenRecording_cont_ch12);
	lv_label_set_text(ui->screenRecording_label_59, "");
	lv_label_set_long_mode(ui->screenRecording_label_59, LV_LABEL_LONG_WRAP);
	lv_obj_set_pos(ui->screenRecording_label_59, 100, 4);
	lv_obj_set_size(ui->screenRecording_label_59, 25, 32);

	//Write style for screenRecording_label_59, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->screenRecording_label_59, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->screenRecording_label_59, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->screenRecording_label_59, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->screenRecording_label_59, &lv_font_FontAwesome5ProRegular_400_22, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->screenRecording_label_59, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_line_space(ui->screenRecording_label_59, 1, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->screenRecording_label_59, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->screenRecording_label_59, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->screenRecording_label_59, 6, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->screenRecording_label_59, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->screenRecording_label_59, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->screenRecording_label_59, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->screenRecording_label_59, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes screenRecording_sw_17
	ui->screenRecording_sw_17 = lv_switch_create(ui->screenRecording_cont_ch12);
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

	//Write codes screenRecording_label_63
	ui->screenRecording_label_63 = lv_label_create(ui->screenRecording_cont_ch13);
	lv_label_set_text(ui->screenRecording_label_63, "CH: 31");
	lv_label_set_long_mode(ui->screenRecording_label_63, LV_LABEL_LONG_WRAP);
	lv_obj_set_pos(ui->screenRecording_label_63, 137, 5);
	lv_obj_set_size(ui->screenRecording_label_63, 66, 32);

	//Write style for screenRecording_label_63, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->screenRecording_label_63, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->screenRecording_label_63, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->screenRecording_label_63, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->screenRecording_label_63, &lv_font_MontserratRegular_20, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->screenRecording_label_63, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_line_space(ui->screenRecording_label_63, 1, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->screenRecording_label_63, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->screenRecording_label_63, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->screenRecording_label_63, 7, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->screenRecording_label_63, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->screenRecording_label_63, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->screenRecording_label_63, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->screenRecording_label_63, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes screenRecording_label_62
	ui->screenRecording_label_62 = lv_label_create(ui->screenRecording_cont_ch13);
	lv_label_set_text(ui->screenRecording_label_62, "");
	lv_label_set_long_mode(ui->screenRecording_label_62, LV_LABEL_LONG_WRAP);
	lv_obj_set_pos(ui->screenRecording_label_62, 100, 4);
	lv_obj_set_size(ui->screenRecording_label_62, 25, 32);

	//Write style for screenRecording_label_62, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->screenRecording_label_62, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->screenRecording_label_62, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->screenRecording_label_62, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->screenRecording_label_62, &lv_font_FontAwesome5ProRegular_400_22, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->screenRecording_label_62, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_line_space(ui->screenRecording_label_62, 1, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->screenRecording_label_62, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->screenRecording_label_62, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->screenRecording_label_62, 6, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->screenRecording_label_62, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->screenRecording_label_62, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->screenRecording_label_62, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->screenRecording_label_62, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes screenRecording_sw_18
	ui->screenRecording_sw_18 = lv_switch_create(ui->screenRecording_cont_ch13);
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

	//Write codes screenRecording_label_66
	ui->screenRecording_label_66 = lv_label_create(ui->screenRecording_cont_ch14);
	lv_label_set_text(ui->screenRecording_label_66, "CH: 31");
	lv_label_set_long_mode(ui->screenRecording_label_66, LV_LABEL_LONG_WRAP);
	lv_obj_set_pos(ui->screenRecording_label_66, 137, 5);
	lv_obj_set_size(ui->screenRecording_label_66, 66, 32);

	//Write style for screenRecording_label_66, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->screenRecording_label_66, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->screenRecording_label_66, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->screenRecording_label_66, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->screenRecording_label_66, &lv_font_MontserratRegular_20, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->screenRecording_label_66, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_line_space(ui->screenRecording_label_66, 1, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->screenRecording_label_66, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->screenRecording_label_66, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->screenRecording_label_66, 7, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->screenRecording_label_66, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->screenRecording_label_66, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->screenRecording_label_66, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->screenRecording_label_66, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes screenRecording_label_65
	ui->screenRecording_label_65 = lv_label_create(ui->screenRecording_cont_ch14);
	lv_label_set_text(ui->screenRecording_label_65, "");
	lv_label_set_long_mode(ui->screenRecording_label_65, LV_LABEL_LONG_WRAP);
	lv_obj_set_pos(ui->screenRecording_label_65, 100, 4);
	lv_obj_set_size(ui->screenRecording_label_65, 25, 32);

	//Write style for screenRecording_label_65, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->screenRecording_label_65, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->screenRecording_label_65, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->screenRecording_label_65, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->screenRecording_label_65, &lv_font_FontAwesome5ProRegular_400_22, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->screenRecording_label_65, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_line_space(ui->screenRecording_label_65, 1, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->screenRecording_label_65, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->screenRecording_label_65, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->screenRecording_label_65, 6, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->screenRecording_label_65, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->screenRecording_label_65, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->screenRecording_label_65, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->screenRecording_label_65, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes screenRecording_sw_19
	ui->screenRecording_sw_19 = lv_switch_create(ui->screenRecording_cont_ch14);
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

	//Write codes screenRecording_label_69
	ui->screenRecording_label_69 = lv_label_create(ui->screenRecording_cont_ch15);
	lv_label_set_text(ui->screenRecording_label_69, "CH: 31");
	lv_label_set_long_mode(ui->screenRecording_label_69, LV_LABEL_LONG_WRAP);
	lv_obj_set_pos(ui->screenRecording_label_69, 137, 5);
	lv_obj_set_size(ui->screenRecording_label_69, 66, 32);

	//Write style for screenRecording_label_69, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->screenRecording_label_69, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->screenRecording_label_69, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->screenRecording_label_69, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->screenRecording_label_69, &lv_font_MontserratRegular_20, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->screenRecording_label_69, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_line_space(ui->screenRecording_label_69, 1, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->screenRecording_label_69, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->screenRecording_label_69, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->screenRecording_label_69, 7, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->screenRecording_label_69, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->screenRecording_label_69, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->screenRecording_label_69, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->screenRecording_label_69, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes screenRecording_label_68
	ui->screenRecording_label_68 = lv_label_create(ui->screenRecording_cont_ch15);
	lv_label_set_text(ui->screenRecording_label_68, "");
	lv_label_set_long_mode(ui->screenRecording_label_68, LV_LABEL_LONG_WRAP);
	lv_obj_set_pos(ui->screenRecording_label_68, 100, 4);
	lv_obj_set_size(ui->screenRecording_label_68, 25, 32);

	//Write style for screenRecording_label_68, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->screenRecording_label_68, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->screenRecording_label_68, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->screenRecording_label_68, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->screenRecording_label_68, &lv_font_FontAwesome5ProRegular_400_22, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->screenRecording_label_68, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_line_space(ui->screenRecording_label_68, 1, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->screenRecording_label_68, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->screenRecording_label_68, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->screenRecording_label_68, 6, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->screenRecording_label_68, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->screenRecording_label_68, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->screenRecording_label_68, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->screenRecording_label_68, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes screenRecording_sw_20
	ui->screenRecording_sw_20 = lv_switch_create(ui->screenRecording_cont_ch15);
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

	//Write codes screenRecording_label_72
	ui->screenRecording_label_72 = lv_label_create(ui->screenRecording_cont_ch16);
	lv_label_set_text(ui->screenRecording_label_72, "CH: 31");
	lv_label_set_long_mode(ui->screenRecording_label_72, LV_LABEL_LONG_WRAP);
	lv_obj_set_pos(ui->screenRecording_label_72, 137, 5);
	lv_obj_set_size(ui->screenRecording_label_72, 66, 32);

	//Write style for screenRecording_label_72, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->screenRecording_label_72, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->screenRecording_label_72, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->screenRecording_label_72, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->screenRecording_label_72, &lv_font_MontserratRegular_20, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->screenRecording_label_72, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_line_space(ui->screenRecording_label_72, 1, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->screenRecording_label_72, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->screenRecording_label_72, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->screenRecording_label_72, 7, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->screenRecording_label_72, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->screenRecording_label_72, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->screenRecording_label_72, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->screenRecording_label_72, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes screenRecording_label_71
	ui->screenRecording_label_71 = lv_label_create(ui->screenRecording_cont_ch16);
	lv_label_set_text(ui->screenRecording_label_71, "");
	lv_label_set_long_mode(ui->screenRecording_label_71, LV_LABEL_LONG_WRAP);
	lv_obj_set_pos(ui->screenRecording_label_71, 100, 4);
	lv_obj_set_size(ui->screenRecording_label_71, 25, 32);

	//Write style for screenRecording_label_71, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->screenRecording_label_71, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->screenRecording_label_71, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->screenRecording_label_71, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->screenRecording_label_71, &lv_font_FontAwesome5ProRegular_400_22, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->screenRecording_label_71, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_line_space(ui->screenRecording_label_71, 1, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->screenRecording_label_71, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->screenRecording_label_71, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->screenRecording_label_71, 6, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->screenRecording_label_71, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->screenRecording_label_71, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->screenRecording_label_71, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->screenRecording_label_71, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes screenRecording_sw_21
	ui->screenRecording_sw_21 = lv_switch_create(ui->screenRecording_cont_ch16);
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

	//Write codes screenRecording_label_75
	ui->screenRecording_label_75 = lv_label_create(ui->screenRecording_cont_ch17);
	lv_label_set_text(ui->screenRecording_label_75, "CH: 31");
	lv_label_set_long_mode(ui->screenRecording_label_75, LV_LABEL_LONG_WRAP);
	lv_obj_set_pos(ui->screenRecording_label_75, 137, 5);
	lv_obj_set_size(ui->screenRecording_label_75, 66, 32);

	//Write style for screenRecording_label_75, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->screenRecording_label_75, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->screenRecording_label_75, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->screenRecording_label_75, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->screenRecording_label_75, &lv_font_MontserratRegular_20, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->screenRecording_label_75, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_line_space(ui->screenRecording_label_75, 1, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->screenRecording_label_75, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->screenRecording_label_75, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->screenRecording_label_75, 7, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->screenRecording_label_75, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->screenRecording_label_75, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->screenRecording_label_75, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->screenRecording_label_75, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes screenRecording_label_74
	ui->screenRecording_label_74 = lv_label_create(ui->screenRecording_cont_ch17);
	lv_label_set_text(ui->screenRecording_label_74, "");
	lv_label_set_long_mode(ui->screenRecording_label_74, LV_LABEL_LONG_WRAP);
	lv_obj_set_pos(ui->screenRecording_label_74, 100, 4);
	lv_obj_set_size(ui->screenRecording_label_74, 25, 32);

	//Write style for screenRecording_label_74, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->screenRecording_label_74, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->screenRecording_label_74, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->screenRecording_label_74, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->screenRecording_label_74, &lv_font_FontAwesome5ProRegular_400_22, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->screenRecording_label_74, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_line_space(ui->screenRecording_label_74, 1, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->screenRecording_label_74, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->screenRecording_label_74, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->screenRecording_label_74, 6, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->screenRecording_label_74, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->screenRecording_label_74, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->screenRecording_label_74, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->screenRecording_label_74, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes screenRecording_sw_22
	ui->screenRecording_sw_22 = lv_switch_create(ui->screenRecording_cont_ch17);
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

	//Write codes screenRecording_label_78
	ui->screenRecording_label_78 = lv_label_create(ui->screenRecording_cont_ch18);
	lv_label_set_text(ui->screenRecording_label_78, "CH: 31");
	lv_label_set_long_mode(ui->screenRecording_label_78, LV_LABEL_LONG_WRAP);
	lv_obj_set_pos(ui->screenRecording_label_78, 137, 5);
	lv_obj_set_size(ui->screenRecording_label_78, 66, 32);

	//Write style for screenRecording_label_78, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->screenRecording_label_78, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->screenRecording_label_78, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->screenRecording_label_78, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->screenRecording_label_78, &lv_font_MontserratRegular_20, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->screenRecording_label_78, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_line_space(ui->screenRecording_label_78, 1, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->screenRecording_label_78, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->screenRecording_label_78, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->screenRecording_label_78, 7, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->screenRecording_label_78, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->screenRecording_label_78, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->screenRecording_label_78, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->screenRecording_label_78, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes screenRecording_label_77
	ui->screenRecording_label_77 = lv_label_create(ui->screenRecording_cont_ch18);
	lv_label_set_text(ui->screenRecording_label_77, "");
	lv_label_set_long_mode(ui->screenRecording_label_77, LV_LABEL_LONG_WRAP);
	lv_obj_set_pos(ui->screenRecording_label_77, 100, 4);
	lv_obj_set_size(ui->screenRecording_label_77, 25, 32);

	//Write style for screenRecording_label_77, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->screenRecording_label_77, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->screenRecording_label_77, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->screenRecording_label_77, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->screenRecording_label_77, &lv_font_FontAwesome5ProRegular_400_22, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->screenRecording_label_77, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_line_space(ui->screenRecording_label_77, 1, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->screenRecording_label_77, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->screenRecording_label_77, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->screenRecording_label_77, 6, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->screenRecording_label_77, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->screenRecording_label_77, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->screenRecording_label_77, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->screenRecording_label_77, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes screenRecording_sw_23
	ui->screenRecording_sw_23 = lv_switch_create(ui->screenRecording_cont_ch18);
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

	//Write codes screenRecording_label_81
	ui->screenRecording_label_81 = lv_label_create(ui->screenRecording_cont_ch19);
	lv_label_set_text(ui->screenRecording_label_81, "CH: 31");
	lv_label_set_long_mode(ui->screenRecording_label_81, LV_LABEL_LONG_WRAP);
	lv_obj_set_pos(ui->screenRecording_label_81, 137, 5);
	lv_obj_set_size(ui->screenRecording_label_81, 66, 32);

	//Write style for screenRecording_label_81, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->screenRecording_label_81, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->screenRecording_label_81, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->screenRecording_label_81, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->screenRecording_label_81, &lv_font_MontserratRegular_20, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->screenRecording_label_81, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_line_space(ui->screenRecording_label_81, 1, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->screenRecording_label_81, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->screenRecording_label_81, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->screenRecording_label_81, 7, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->screenRecording_label_81, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->screenRecording_label_81, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->screenRecording_label_81, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->screenRecording_label_81, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes screenRecording_label_80
	ui->screenRecording_label_80 = lv_label_create(ui->screenRecording_cont_ch19);
	lv_label_set_text(ui->screenRecording_label_80, "");
	lv_label_set_long_mode(ui->screenRecording_label_80, LV_LABEL_LONG_WRAP);
	lv_obj_set_pos(ui->screenRecording_label_80, 100, 4);
	lv_obj_set_size(ui->screenRecording_label_80, 25, 32);

	//Write style for screenRecording_label_80, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->screenRecording_label_80, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->screenRecording_label_80, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->screenRecording_label_80, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->screenRecording_label_80, &lv_font_FontAwesome5ProRegular_400_22, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->screenRecording_label_80, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_line_space(ui->screenRecording_label_80, 1, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->screenRecording_label_80, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->screenRecording_label_80, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->screenRecording_label_80, 6, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->screenRecording_label_80, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->screenRecording_label_80, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->screenRecording_label_80, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->screenRecording_label_80, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes screenRecording_sw_24
	ui->screenRecording_sw_24 = lv_switch_create(ui->screenRecording_cont_ch19);
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

	//Write codes screenRecording_label_84
	ui->screenRecording_label_84 = lv_label_create(ui->screenRecording_cont_ch20);
	lv_label_set_text(ui->screenRecording_label_84, "CH: 31");
	lv_label_set_long_mode(ui->screenRecording_label_84, LV_LABEL_LONG_WRAP);
	lv_obj_set_pos(ui->screenRecording_label_84, 137, 5);
	lv_obj_set_size(ui->screenRecording_label_84, 66, 32);

	//Write style for screenRecording_label_84, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->screenRecording_label_84, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->screenRecording_label_84, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->screenRecording_label_84, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->screenRecording_label_84, &lv_font_MontserratRegular_20, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->screenRecording_label_84, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_line_space(ui->screenRecording_label_84, 1, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->screenRecording_label_84, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->screenRecording_label_84, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->screenRecording_label_84, 7, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->screenRecording_label_84, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->screenRecording_label_84, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->screenRecording_label_84, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->screenRecording_label_84, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes screenRecording_label_83
	ui->screenRecording_label_83 = lv_label_create(ui->screenRecording_cont_ch20);
	lv_label_set_text(ui->screenRecording_label_83, "");
	lv_label_set_long_mode(ui->screenRecording_label_83, LV_LABEL_LONG_WRAP);
	lv_obj_set_pos(ui->screenRecording_label_83, 100, 4);
	lv_obj_set_size(ui->screenRecording_label_83, 25, 32);

	//Write style for screenRecording_label_83, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->screenRecording_label_83, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->screenRecording_label_83, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->screenRecording_label_83, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->screenRecording_label_83, &lv_font_FontAwesome5ProRegular_400_22, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->screenRecording_label_83, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_line_space(ui->screenRecording_label_83, 1, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->screenRecording_label_83, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->screenRecording_label_83, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->screenRecording_label_83, 6, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->screenRecording_label_83, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->screenRecording_label_83, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->screenRecording_label_83, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->screenRecording_label_83, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes screenRecording_sw_25
	ui->screenRecording_sw_25 = lv_switch_create(ui->screenRecording_cont_ch20);
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

	//Write codes screenRecording_label_87
	ui->screenRecording_label_87 = lv_label_create(ui->screenRecording_cont_ch21);
	lv_label_set_text(ui->screenRecording_label_87, "CH: 31");
	lv_label_set_long_mode(ui->screenRecording_label_87, LV_LABEL_LONG_WRAP);
	lv_obj_set_pos(ui->screenRecording_label_87, 137, 5);
	lv_obj_set_size(ui->screenRecording_label_87, 66, 32);

	//Write style for screenRecording_label_87, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->screenRecording_label_87, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->screenRecording_label_87, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->screenRecording_label_87, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->screenRecording_label_87, &lv_font_MontserratRegular_20, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->screenRecording_label_87, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_line_space(ui->screenRecording_label_87, 1, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->screenRecording_label_87, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->screenRecording_label_87, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->screenRecording_label_87, 7, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->screenRecording_label_87, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->screenRecording_label_87, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->screenRecording_label_87, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->screenRecording_label_87, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes screenRecording_label_86
	ui->screenRecording_label_86 = lv_label_create(ui->screenRecording_cont_ch21);
	lv_label_set_text(ui->screenRecording_label_86, "");
	lv_label_set_long_mode(ui->screenRecording_label_86, LV_LABEL_LONG_WRAP);
	lv_obj_set_pos(ui->screenRecording_label_86, 100, 4);
	lv_obj_set_size(ui->screenRecording_label_86, 25, 32);

	//Write style for screenRecording_label_86, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->screenRecording_label_86, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->screenRecording_label_86, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->screenRecording_label_86, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->screenRecording_label_86, &lv_font_FontAwesome5ProRegular_400_22, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->screenRecording_label_86, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_line_space(ui->screenRecording_label_86, 1, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->screenRecording_label_86, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->screenRecording_label_86, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->screenRecording_label_86, 6, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->screenRecording_label_86, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->screenRecording_label_86, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->screenRecording_label_86, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->screenRecording_label_86, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes screenRecording_sw_26
	ui->screenRecording_sw_26 = lv_switch_create(ui->screenRecording_cont_ch21);
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

	//Write codes screenRecording_label_90
	ui->screenRecording_label_90 = lv_label_create(ui->screenRecording_cont_ch22);
	lv_label_set_text(ui->screenRecording_label_90, "CH: 31");
	lv_label_set_long_mode(ui->screenRecording_label_90, LV_LABEL_LONG_WRAP);
	lv_obj_set_pos(ui->screenRecording_label_90, 137, 5);
	lv_obj_set_size(ui->screenRecording_label_90, 66, 32);

	//Write style for screenRecording_label_90, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->screenRecording_label_90, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->screenRecording_label_90, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->screenRecording_label_90, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->screenRecording_label_90, &lv_font_MontserratRegular_20, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->screenRecording_label_90, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_line_space(ui->screenRecording_label_90, 1, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->screenRecording_label_90, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->screenRecording_label_90, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->screenRecording_label_90, 7, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->screenRecording_label_90, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->screenRecording_label_90, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->screenRecording_label_90, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->screenRecording_label_90, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes screenRecording_label_89
	ui->screenRecording_label_89 = lv_label_create(ui->screenRecording_cont_ch22);
	lv_label_set_text(ui->screenRecording_label_89, "");
	lv_label_set_long_mode(ui->screenRecording_label_89, LV_LABEL_LONG_WRAP);
	lv_obj_set_pos(ui->screenRecording_label_89, 100, 4);
	lv_obj_set_size(ui->screenRecording_label_89, 25, 32);

	//Write style for screenRecording_label_89, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->screenRecording_label_89, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->screenRecording_label_89, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->screenRecording_label_89, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->screenRecording_label_89, &lv_font_FontAwesome5ProRegular_400_22, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->screenRecording_label_89, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_line_space(ui->screenRecording_label_89, 1, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->screenRecording_label_89, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->screenRecording_label_89, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->screenRecording_label_89, 6, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->screenRecording_label_89, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->screenRecording_label_89, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->screenRecording_label_89, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->screenRecording_label_89, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes screenRecording_sw_27
	ui->screenRecording_sw_27 = lv_switch_create(ui->screenRecording_cont_ch22);
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

	//Write codes screenRecording_label_93
	ui->screenRecording_label_93 = lv_label_create(ui->screenRecording_cont_ch23);
	lv_label_set_text(ui->screenRecording_label_93, "CH: 31");
	lv_label_set_long_mode(ui->screenRecording_label_93, LV_LABEL_LONG_WRAP);
	lv_obj_set_pos(ui->screenRecording_label_93, 137, 5);
	lv_obj_set_size(ui->screenRecording_label_93, 66, 32);

	//Write style for screenRecording_label_93, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->screenRecording_label_93, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->screenRecording_label_93, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->screenRecording_label_93, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->screenRecording_label_93, &lv_font_MontserratRegular_20, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->screenRecording_label_93, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_line_space(ui->screenRecording_label_93, 1, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->screenRecording_label_93, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->screenRecording_label_93, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->screenRecording_label_93, 7, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->screenRecording_label_93, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->screenRecording_label_93, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->screenRecording_label_93, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->screenRecording_label_93, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes screenRecording_label_92
	ui->screenRecording_label_92 = lv_label_create(ui->screenRecording_cont_ch23);
	lv_label_set_text(ui->screenRecording_label_92, "");
	lv_label_set_long_mode(ui->screenRecording_label_92, LV_LABEL_LONG_WRAP);
	lv_obj_set_pos(ui->screenRecording_label_92, 100, 4);
	lv_obj_set_size(ui->screenRecording_label_92, 25, 32);

	//Write style for screenRecording_label_92, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->screenRecording_label_92, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->screenRecording_label_92, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->screenRecording_label_92, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->screenRecording_label_92, &lv_font_FontAwesome5ProRegular_400_22, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->screenRecording_label_92, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_line_space(ui->screenRecording_label_92, 1, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->screenRecording_label_92, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->screenRecording_label_92, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->screenRecording_label_92, 6, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->screenRecording_label_92, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->screenRecording_label_92, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->screenRecording_label_92, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->screenRecording_label_92, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes screenRecording_sw_28
	ui->screenRecording_sw_28 = lv_switch_create(ui->screenRecording_cont_ch23);
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

	//Write codes screenRecording_label_96
	ui->screenRecording_label_96 = lv_label_create(ui->screenRecording_cont_ch24);
	lv_label_set_text(ui->screenRecording_label_96, "CH: 31");
	lv_label_set_long_mode(ui->screenRecording_label_96, LV_LABEL_LONG_WRAP);
	lv_obj_set_pos(ui->screenRecording_label_96, 137, 5);
	lv_obj_set_size(ui->screenRecording_label_96, 66, 32);

	//Write style for screenRecording_label_96, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->screenRecording_label_96, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->screenRecording_label_96, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->screenRecording_label_96, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->screenRecording_label_96, &lv_font_MontserratRegular_20, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->screenRecording_label_96, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_line_space(ui->screenRecording_label_96, 1, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->screenRecording_label_96, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->screenRecording_label_96, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->screenRecording_label_96, 7, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->screenRecording_label_96, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->screenRecording_label_96, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->screenRecording_label_96, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->screenRecording_label_96, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes screenRecording_label_95
	ui->screenRecording_label_95 = lv_label_create(ui->screenRecording_cont_ch24);
	lv_label_set_text(ui->screenRecording_label_95, "");
	lv_label_set_long_mode(ui->screenRecording_label_95, LV_LABEL_LONG_WRAP);
	lv_obj_set_pos(ui->screenRecording_label_95, 100, 4);
	lv_obj_set_size(ui->screenRecording_label_95, 25, 32);

	//Write style for screenRecording_label_95, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->screenRecording_label_95, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->screenRecording_label_95, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->screenRecording_label_95, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->screenRecording_label_95, &lv_font_FontAwesome5ProRegular_400_22, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->screenRecording_label_95, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_line_space(ui->screenRecording_label_95, 1, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->screenRecording_label_95, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->screenRecording_label_95, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->screenRecording_label_95, 6, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->screenRecording_label_95, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->screenRecording_label_95, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->screenRecording_label_95, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->screenRecording_label_95, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes screenRecording_sw_29
	ui->screenRecording_sw_29 = lv_switch_create(ui->screenRecording_cont_ch24);
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

	//Write codes screenRecording_label_99
	ui->screenRecording_label_99 = lv_label_create(ui->screenRecording_cont_ch25);
	lv_label_set_text(ui->screenRecording_label_99, "CH: 31");
	lv_label_set_long_mode(ui->screenRecording_label_99, LV_LABEL_LONG_WRAP);
	lv_obj_set_pos(ui->screenRecording_label_99, 137, 5);
	lv_obj_set_size(ui->screenRecording_label_99, 66, 32);

	//Write style for screenRecording_label_99, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->screenRecording_label_99, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->screenRecording_label_99, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->screenRecording_label_99, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->screenRecording_label_99, &lv_font_MontserratRegular_20, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->screenRecording_label_99, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_line_space(ui->screenRecording_label_99, 1, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->screenRecording_label_99, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->screenRecording_label_99, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->screenRecording_label_99, 7, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->screenRecording_label_99, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->screenRecording_label_99, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->screenRecording_label_99, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->screenRecording_label_99, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes screenRecording_label_98
	ui->screenRecording_label_98 = lv_label_create(ui->screenRecording_cont_ch25);
	lv_label_set_text(ui->screenRecording_label_98, "");
	lv_label_set_long_mode(ui->screenRecording_label_98, LV_LABEL_LONG_WRAP);
	lv_obj_set_pos(ui->screenRecording_label_98, 100, 4);
	lv_obj_set_size(ui->screenRecording_label_98, 25, 32);

	//Write style for screenRecording_label_98, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->screenRecording_label_98, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->screenRecording_label_98, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->screenRecording_label_98, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->screenRecording_label_98, &lv_font_FontAwesome5ProRegular_400_22, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->screenRecording_label_98, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_line_space(ui->screenRecording_label_98, 1, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->screenRecording_label_98, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->screenRecording_label_98, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->screenRecording_label_98, 6, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->screenRecording_label_98, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->screenRecording_label_98, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->screenRecording_label_98, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->screenRecording_label_98, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes screenRecording_sw_30
	ui->screenRecording_sw_30 = lv_switch_create(ui->screenRecording_cont_ch25);
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

	//Write codes screenRecording_label_102
	ui->screenRecording_label_102 = lv_label_create(ui->screenRecording_cont_ch26);
	lv_label_set_text(ui->screenRecording_label_102, "CH: 31");
	lv_label_set_long_mode(ui->screenRecording_label_102, LV_LABEL_LONG_WRAP);
	lv_obj_set_pos(ui->screenRecording_label_102, 137, 5);
	lv_obj_set_size(ui->screenRecording_label_102, 66, 32);

	//Write style for screenRecording_label_102, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->screenRecording_label_102, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->screenRecording_label_102, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->screenRecording_label_102, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->screenRecording_label_102, &lv_font_MontserratRegular_20, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->screenRecording_label_102, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_line_space(ui->screenRecording_label_102, 1, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->screenRecording_label_102, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->screenRecording_label_102, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->screenRecording_label_102, 7, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->screenRecording_label_102, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->screenRecording_label_102, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->screenRecording_label_102, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->screenRecording_label_102, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes screenRecording_label_101
	ui->screenRecording_label_101 = lv_label_create(ui->screenRecording_cont_ch26);
	lv_label_set_text(ui->screenRecording_label_101, "");
	lv_label_set_long_mode(ui->screenRecording_label_101, LV_LABEL_LONG_WRAP);
	lv_obj_set_pos(ui->screenRecording_label_101, 100, 4);
	lv_obj_set_size(ui->screenRecording_label_101, 25, 32);

	//Write style for screenRecording_label_101, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->screenRecording_label_101, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->screenRecording_label_101, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->screenRecording_label_101, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->screenRecording_label_101, &lv_font_FontAwesome5ProRegular_400_22, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->screenRecording_label_101, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_line_space(ui->screenRecording_label_101, 1, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->screenRecording_label_101, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->screenRecording_label_101, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->screenRecording_label_101, 6, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->screenRecording_label_101, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->screenRecording_label_101, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->screenRecording_label_101, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->screenRecording_label_101, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes screenRecording_sw_31
	ui->screenRecording_sw_31 = lv_switch_create(ui->screenRecording_cont_ch26);
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

	//Write codes screenRecording_label_105
	ui->screenRecording_label_105 = lv_label_create(ui->screenRecording_cont_ch27);
	lv_label_set_text(ui->screenRecording_label_105, "CH: 31");
	lv_label_set_long_mode(ui->screenRecording_label_105, LV_LABEL_LONG_WRAP);
	lv_obj_set_pos(ui->screenRecording_label_105, 137, 5);
	lv_obj_set_size(ui->screenRecording_label_105, 66, 32);

	//Write style for screenRecording_label_105, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->screenRecording_label_105, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->screenRecording_label_105, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->screenRecording_label_105, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->screenRecording_label_105, &lv_font_MontserratRegular_20, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->screenRecording_label_105, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_line_space(ui->screenRecording_label_105, 1, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->screenRecording_label_105, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->screenRecording_label_105, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->screenRecording_label_105, 7, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->screenRecording_label_105, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->screenRecording_label_105, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->screenRecording_label_105, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->screenRecording_label_105, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes screenRecording_label_104
	ui->screenRecording_label_104 = lv_label_create(ui->screenRecording_cont_ch27);
	lv_label_set_text(ui->screenRecording_label_104, "");
	lv_label_set_long_mode(ui->screenRecording_label_104, LV_LABEL_LONG_WRAP);
	lv_obj_set_pos(ui->screenRecording_label_104, 100, 4);
	lv_obj_set_size(ui->screenRecording_label_104, 25, 32);

	//Write style for screenRecording_label_104, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->screenRecording_label_104, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->screenRecording_label_104, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->screenRecording_label_104, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->screenRecording_label_104, &lv_font_FontAwesome5ProRegular_400_22, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->screenRecording_label_104, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_line_space(ui->screenRecording_label_104, 1, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->screenRecording_label_104, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->screenRecording_label_104, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->screenRecording_label_104, 6, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->screenRecording_label_104, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->screenRecording_label_104, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->screenRecording_label_104, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->screenRecording_label_104, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes screenRecording_sw_32
	ui->screenRecording_sw_32 = lv_switch_create(ui->screenRecording_cont_ch27);
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

	//Write codes screenRecording_label_108
	ui->screenRecording_label_108 = lv_label_create(ui->screenRecording_cont_ch28);
	lv_label_set_text(ui->screenRecording_label_108, "CH: 31");
	lv_label_set_long_mode(ui->screenRecording_label_108, LV_LABEL_LONG_WRAP);
	lv_obj_set_pos(ui->screenRecording_label_108, 137, 5);
	lv_obj_set_size(ui->screenRecording_label_108, 66, 32);

	//Write style for screenRecording_label_108, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->screenRecording_label_108, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->screenRecording_label_108, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->screenRecording_label_108, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->screenRecording_label_108, &lv_font_MontserratRegular_20, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->screenRecording_label_108, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_line_space(ui->screenRecording_label_108, 1, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->screenRecording_label_108, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->screenRecording_label_108, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->screenRecording_label_108, 7, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->screenRecording_label_108, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->screenRecording_label_108, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->screenRecording_label_108, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->screenRecording_label_108, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes screenRecording_label_107
	ui->screenRecording_label_107 = lv_label_create(ui->screenRecording_cont_ch28);
	lv_label_set_text(ui->screenRecording_label_107, "");
	lv_label_set_long_mode(ui->screenRecording_label_107, LV_LABEL_LONG_WRAP);
	lv_obj_set_pos(ui->screenRecording_label_107, 100, 4);
	lv_obj_set_size(ui->screenRecording_label_107, 25, 32);

	//Write style for screenRecording_label_107, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->screenRecording_label_107, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->screenRecording_label_107, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->screenRecording_label_107, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->screenRecording_label_107, &lv_font_FontAwesome5ProRegular_400_22, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->screenRecording_label_107, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_line_space(ui->screenRecording_label_107, 1, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->screenRecording_label_107, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->screenRecording_label_107, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->screenRecording_label_107, 6, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->screenRecording_label_107, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->screenRecording_label_107, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->screenRecording_label_107, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->screenRecording_label_107, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes screenRecording_sw_33
	ui->screenRecording_sw_33 = lv_switch_create(ui->screenRecording_cont_ch28);
	lv_obj_set_pos(ui->screenRecording_sw_33, 46, 12);
	lv_obj_set_size(ui->screenRecording_sw_33, 40, 20);

	//Write style for screenRecording_sw_33, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_bg_opa(ui->screenRecording_sw_33, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui->screenRecording_sw_33, lv_color_hex(0x41485a), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_width(ui->screenRecording_sw_33, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->screenRecording_sw_33, 10, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->screenRecording_sw_33, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write style for screenRecording_sw_33, Part: LV_PART_INDICATOR, State: LV_STATE_CHECKED.
	lv_obj_set_style_bg_opa(ui->screenRecording_sw_33, 255, LV_PART_INDICATOR|LV_STATE_CHECKED);
	lv_obj_set_style_bg_color(ui->screenRecording_sw_33, lv_color_hex(0x2195f6), LV_PART_INDICATOR|LV_STATE_CHECKED);
	lv_obj_set_style_border_width(ui->screenRecording_sw_33, 0, LV_PART_INDICATOR|LV_STATE_CHECKED);

	//Write style for screenRecording_sw_33, Part: LV_PART_KNOB, State: LV_STATE_DEFAULT.
	lv_obj_set_style_bg_opa(ui->screenRecording_sw_33, 255, LV_PART_KNOB|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui->screenRecording_sw_33, lv_color_hex(0x292831), LV_PART_KNOB|LV_STATE_DEFAULT);
	lv_obj_set_style_border_width(ui->screenRecording_sw_33, 0, LV_PART_KNOB|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->screenRecording_sw_33, 10, LV_PART_KNOB|LV_STATE_DEFAULT);

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

	//Write codes screenRecording_label_111
	ui->screenRecording_label_111 = lv_label_create(ui->screenRecording_cont_ch29);
	lv_label_set_text(ui->screenRecording_label_111, "CH: 31");
	lv_label_set_long_mode(ui->screenRecording_label_111, LV_LABEL_LONG_WRAP);
	lv_obj_set_pos(ui->screenRecording_label_111, 137, 5);
	lv_obj_set_size(ui->screenRecording_label_111, 66, 32);

	//Write style for screenRecording_label_111, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->screenRecording_label_111, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->screenRecording_label_111, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->screenRecording_label_111, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->screenRecording_label_111, &lv_font_MontserratRegular_20, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->screenRecording_label_111, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_line_space(ui->screenRecording_label_111, 1, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->screenRecording_label_111, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->screenRecording_label_111, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->screenRecording_label_111, 7, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->screenRecording_label_111, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->screenRecording_label_111, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->screenRecording_label_111, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->screenRecording_label_111, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes screenRecording_label_110
	ui->screenRecording_label_110 = lv_label_create(ui->screenRecording_cont_ch29);
	lv_label_set_text(ui->screenRecording_label_110, "");
	lv_label_set_long_mode(ui->screenRecording_label_110, LV_LABEL_LONG_WRAP);
	lv_obj_set_pos(ui->screenRecording_label_110, 100, 4);
	lv_obj_set_size(ui->screenRecording_label_110, 25, 32);

	//Write style for screenRecording_label_110, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->screenRecording_label_110, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->screenRecording_label_110, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->screenRecording_label_110, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->screenRecording_label_110, &lv_font_FontAwesome5ProRegular_400_22, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->screenRecording_label_110, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_line_space(ui->screenRecording_label_110, 1, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->screenRecording_label_110, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->screenRecording_label_110, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->screenRecording_label_110, 6, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->screenRecording_label_110, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->screenRecording_label_110, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->screenRecording_label_110, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->screenRecording_label_110, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes screenRecording_sw_34
	ui->screenRecording_sw_34 = lv_switch_create(ui->screenRecording_cont_ch29);
	lv_obj_set_pos(ui->screenRecording_sw_34, 46, 12);
	lv_obj_set_size(ui->screenRecording_sw_34, 40, 20);

	//Write style for screenRecording_sw_34, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_bg_opa(ui->screenRecording_sw_34, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui->screenRecording_sw_34, lv_color_hex(0x41485a), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_width(ui->screenRecording_sw_34, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->screenRecording_sw_34, 10, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->screenRecording_sw_34, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write style for screenRecording_sw_34, Part: LV_PART_INDICATOR, State: LV_STATE_CHECKED.
	lv_obj_set_style_bg_opa(ui->screenRecording_sw_34, 255, LV_PART_INDICATOR|LV_STATE_CHECKED);
	lv_obj_set_style_bg_color(ui->screenRecording_sw_34, lv_color_hex(0x2195f6), LV_PART_INDICATOR|LV_STATE_CHECKED);
	lv_obj_set_style_border_width(ui->screenRecording_sw_34, 0, LV_PART_INDICATOR|LV_STATE_CHECKED);

	//Write style for screenRecording_sw_34, Part: LV_PART_KNOB, State: LV_STATE_DEFAULT.
	lv_obj_set_style_bg_opa(ui->screenRecording_sw_34, 255, LV_PART_KNOB|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui->screenRecording_sw_34, lv_color_hex(0x292831), LV_PART_KNOB|LV_STATE_DEFAULT);
	lv_obj_set_style_border_width(ui->screenRecording_sw_34, 0, LV_PART_KNOB|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->screenRecording_sw_34, 10, LV_PART_KNOB|LV_STATE_DEFAULT);

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

	//Write codes screenRecording_label_114
	ui->screenRecording_label_114 = lv_label_create(ui->screenRecording_cont_ch30);
	lv_label_set_text(ui->screenRecording_label_114, "CH: 31");
	lv_label_set_long_mode(ui->screenRecording_label_114, LV_LABEL_LONG_WRAP);
	lv_obj_set_pos(ui->screenRecording_label_114, 137, 5);
	lv_obj_set_size(ui->screenRecording_label_114, 66, 32);

	//Write style for screenRecording_label_114, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->screenRecording_label_114, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->screenRecording_label_114, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->screenRecording_label_114, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->screenRecording_label_114, &lv_font_MontserratRegular_20, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->screenRecording_label_114, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_line_space(ui->screenRecording_label_114, 1, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->screenRecording_label_114, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->screenRecording_label_114, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->screenRecording_label_114, 7, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->screenRecording_label_114, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->screenRecording_label_114, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->screenRecording_label_114, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->screenRecording_label_114, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes screenRecording_label_113
	ui->screenRecording_label_113 = lv_label_create(ui->screenRecording_cont_ch30);
	lv_label_set_text(ui->screenRecording_label_113, "");
	lv_label_set_long_mode(ui->screenRecording_label_113, LV_LABEL_LONG_WRAP);
	lv_obj_set_pos(ui->screenRecording_label_113, 100, 4);
	lv_obj_set_size(ui->screenRecording_label_113, 25, 32);

	//Write style for screenRecording_label_113, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->screenRecording_label_113, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->screenRecording_label_113, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->screenRecording_label_113, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->screenRecording_label_113, &lv_font_FontAwesome5ProRegular_400_22, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->screenRecording_label_113, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_line_space(ui->screenRecording_label_113, 1, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->screenRecording_label_113, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->screenRecording_label_113, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->screenRecording_label_113, 6, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->screenRecording_label_113, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->screenRecording_label_113, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->screenRecording_label_113, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->screenRecording_label_113, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes screenRecording_sw_35
	ui->screenRecording_sw_35 = lv_switch_create(ui->screenRecording_cont_ch30);
	lv_obj_set_pos(ui->screenRecording_sw_35, 46, 12);
	lv_obj_set_size(ui->screenRecording_sw_35, 40, 20);

	//Write style for screenRecording_sw_35, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_bg_opa(ui->screenRecording_sw_35, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui->screenRecording_sw_35, lv_color_hex(0x41485a), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_width(ui->screenRecording_sw_35, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->screenRecording_sw_35, 10, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->screenRecording_sw_35, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write style for screenRecording_sw_35, Part: LV_PART_INDICATOR, State: LV_STATE_CHECKED.
	lv_obj_set_style_bg_opa(ui->screenRecording_sw_35, 255, LV_PART_INDICATOR|LV_STATE_CHECKED);
	lv_obj_set_style_bg_color(ui->screenRecording_sw_35, lv_color_hex(0x2195f6), LV_PART_INDICATOR|LV_STATE_CHECKED);
	lv_obj_set_style_border_width(ui->screenRecording_sw_35, 0, LV_PART_INDICATOR|LV_STATE_CHECKED);

	//Write style for screenRecording_sw_35, Part: LV_PART_KNOB, State: LV_STATE_DEFAULT.
	lv_obj_set_style_bg_opa(ui->screenRecording_sw_35, 255, LV_PART_KNOB|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui->screenRecording_sw_35, lv_color_hex(0x292831), LV_PART_KNOB|LV_STATE_DEFAULT);
	lv_obj_set_style_border_width(ui->screenRecording_sw_35, 0, LV_PART_KNOB|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->screenRecording_sw_35, 10, LV_PART_KNOB|LV_STATE_DEFAULT);

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

	//Write codes screenRecording_label_117
	ui->screenRecording_label_117 = lv_label_create(ui->screenRecording_cont_ch31);
	lv_label_set_text(ui->screenRecording_label_117, "CH: 31");
	lv_label_set_long_mode(ui->screenRecording_label_117, LV_LABEL_LONG_WRAP);
	lv_obj_set_pos(ui->screenRecording_label_117, 137, 5);
	lv_obj_set_size(ui->screenRecording_label_117, 66, 32);

	//Write style for screenRecording_label_117, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->screenRecording_label_117, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->screenRecording_label_117, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->screenRecording_label_117, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->screenRecording_label_117, &lv_font_MontserratRegular_20, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->screenRecording_label_117, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_line_space(ui->screenRecording_label_117, 1, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->screenRecording_label_117, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->screenRecording_label_117, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->screenRecording_label_117, 7, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->screenRecording_label_117, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->screenRecording_label_117, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->screenRecording_label_117, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->screenRecording_label_117, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes screenRecording_label_116
	ui->screenRecording_label_116 = lv_label_create(ui->screenRecording_cont_ch31);
	lv_label_set_text(ui->screenRecording_label_116, "");
	lv_label_set_long_mode(ui->screenRecording_label_116, LV_LABEL_LONG_WRAP);
	lv_obj_set_pos(ui->screenRecording_label_116, 100, 4);
	lv_obj_set_size(ui->screenRecording_label_116, 25, 32);

	//Write style for screenRecording_label_116, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->screenRecording_label_116, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->screenRecording_label_116, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->screenRecording_label_116, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->screenRecording_label_116, &lv_font_FontAwesome5ProRegular_400_22, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->screenRecording_label_116, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_line_space(ui->screenRecording_label_116, 1, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->screenRecording_label_116, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->screenRecording_label_116, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->screenRecording_label_116, 6, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->screenRecording_label_116, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->screenRecording_label_116, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->screenRecording_label_116, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->screenRecording_label_116, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes screenRecording_sw_36
	ui->screenRecording_sw_36 = lv_switch_create(ui->screenRecording_cont_ch31);
	lv_obj_set_pos(ui->screenRecording_sw_36, 46, 12);
	lv_obj_set_size(ui->screenRecording_sw_36, 40, 20);

	//Write style for screenRecording_sw_36, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_bg_opa(ui->screenRecording_sw_36, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui->screenRecording_sw_36, lv_color_hex(0x41485a), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_width(ui->screenRecording_sw_36, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->screenRecording_sw_36, 10, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->screenRecording_sw_36, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write style for screenRecording_sw_36, Part: LV_PART_INDICATOR, State: LV_STATE_CHECKED.
	lv_obj_set_style_bg_opa(ui->screenRecording_sw_36, 255, LV_PART_INDICATOR|LV_STATE_CHECKED);
	lv_obj_set_style_bg_color(ui->screenRecording_sw_36, lv_color_hex(0x2195f6), LV_PART_INDICATOR|LV_STATE_CHECKED);
	lv_obj_set_style_border_width(ui->screenRecording_sw_36, 0, LV_PART_INDICATOR|LV_STATE_CHECKED);

	//Write style for screenRecording_sw_36, Part: LV_PART_KNOB, State: LV_STATE_DEFAULT.
	lv_obj_set_style_bg_opa(ui->screenRecording_sw_36, 255, LV_PART_KNOB|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui->screenRecording_sw_36, lv_color_hex(0x292831), LV_PART_KNOB|LV_STATE_DEFAULT);
	lv_obj_set_style_border_width(ui->screenRecording_sw_36, 0, LV_PART_KNOB|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->screenRecording_sw_36, 10, LV_PART_KNOB|LV_STATE_DEFAULT);

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

	//Write codes screenRecording_label_120
	ui->screenRecording_label_120 = lv_label_create(ui->screenRecording_cont_ch32);
	lv_label_set_text(ui->screenRecording_label_120, "CH: 31");
	lv_label_set_long_mode(ui->screenRecording_label_120, LV_LABEL_LONG_WRAP);
	lv_obj_set_pos(ui->screenRecording_label_120, 137, 5);
	lv_obj_set_size(ui->screenRecording_label_120, 66, 32);

	//Write style for screenRecording_label_120, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->screenRecording_label_120, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->screenRecording_label_120, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->screenRecording_label_120, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->screenRecording_label_120, &lv_font_MontserratRegular_20, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->screenRecording_label_120, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_line_space(ui->screenRecording_label_120, 1, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->screenRecording_label_120, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->screenRecording_label_120, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->screenRecording_label_120, 7, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->screenRecording_label_120, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->screenRecording_label_120, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->screenRecording_label_120, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->screenRecording_label_120, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes screenRecording_label_119
	ui->screenRecording_label_119 = lv_label_create(ui->screenRecording_cont_ch32);
	lv_label_set_text(ui->screenRecording_label_119, "");
	lv_label_set_long_mode(ui->screenRecording_label_119, LV_LABEL_LONG_WRAP);
	lv_obj_set_pos(ui->screenRecording_label_119, 100, 4);
	lv_obj_set_size(ui->screenRecording_label_119, 25, 32);

	//Write style for screenRecording_label_119, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->screenRecording_label_119, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->screenRecording_label_119, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->screenRecording_label_119, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->screenRecording_label_119, &lv_font_FontAwesome5ProRegular_400_22, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->screenRecording_label_119, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_line_space(ui->screenRecording_label_119, 1, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->screenRecording_label_119, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->screenRecording_label_119, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->screenRecording_label_119, 6, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->screenRecording_label_119, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->screenRecording_label_119, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->screenRecording_label_119, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->screenRecording_label_119, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes screenRecording_sw_37
	ui->screenRecording_sw_37 = lv_switch_create(ui->screenRecording_cont_ch32);
	lv_obj_set_pos(ui->screenRecording_sw_37, 46, 12);
	lv_obj_set_size(ui->screenRecording_sw_37, 40, 20);

	//Write style for screenRecording_sw_37, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_bg_opa(ui->screenRecording_sw_37, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui->screenRecording_sw_37, lv_color_hex(0x41485a), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_width(ui->screenRecording_sw_37, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->screenRecording_sw_37, 10, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->screenRecording_sw_37, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write style for screenRecording_sw_37, Part: LV_PART_INDICATOR, State: LV_STATE_CHECKED.
	lv_obj_set_style_bg_opa(ui->screenRecording_sw_37, 255, LV_PART_INDICATOR|LV_STATE_CHECKED);
	lv_obj_set_style_bg_color(ui->screenRecording_sw_37, lv_color_hex(0x2195f6), LV_PART_INDICATOR|LV_STATE_CHECKED);
	lv_obj_set_style_border_width(ui->screenRecording_sw_37, 0, LV_PART_INDICATOR|LV_STATE_CHECKED);

	//Write style for screenRecording_sw_37, Part: LV_PART_KNOB, State: LV_STATE_DEFAULT.
	lv_obj_set_style_bg_opa(ui->screenRecording_sw_37, 255, LV_PART_KNOB|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui->screenRecording_sw_37, lv_color_hex(0x292831), LV_PART_KNOB|LV_STATE_DEFAULT);
	lv_obj_set_style_border_width(ui->screenRecording_sw_37, 0, LV_PART_KNOB|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->screenRecording_sw_37, 10, LV_PART_KNOB|LV_STATE_DEFAULT);

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

	//Write codes screenRecording_cont_recording
	ui->screenRecording_cont_recording = lv_obj_create(ui->screenRecording);
	lv_obj_set_pos(ui->screenRecording_cont_recording, 14, 59);
	lv_obj_set_size(ui->screenRecording_cont_recording, 212, 122);
	lv_obj_set_scrollbar_mode(ui->screenRecording_cont_recording, LV_SCROLLBAR_MODE_OFF);
	lv_obj_add_flag(ui->screenRecording_cont_recording, LV_OBJ_FLAG_HIDDEN);

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
	lv_obj_set_style_text_font(ui->screenRecording_label_recording_time, &lv_font_montserratMedium_35, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->screenRecording_label_recording_time, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_line_space(ui->screenRecording_label_recording_time, 1, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->screenRecording_label_recording_time, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->screenRecording_label_recording_time, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->screenRecording_label_recording_time, 6, LV_PART_MAIN|LV_STATE_DEFAULT);
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
	lv_label_set_text(ui->screenRecording_label_recording_remaining, "Remaining: 15:26:07");
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
