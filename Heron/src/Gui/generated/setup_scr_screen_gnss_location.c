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


FLASHMEM void setup_scr_screen_gnss_location(lv_ui *ui)
{
	//Write codes screen_gnss_location
	ui->screen_gnss_location = lv_obj_create(NULL);
	lv_obj_set_size(ui->screen_gnss_location, 240, 240);

	//Write style for screen_gnss_location, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_bg_opa(ui->screen_gnss_location, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui->screen_gnss_location, lv_color_hex(0x101418), LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes screen_gnss_location_btn_back
	ui->screen_gnss_location_btn_back = lv_btn_create(ui->screen_gnss_location);
	ui->screen_gnss_location_btn_back_label = lv_label_create(ui->screen_gnss_location_btn_back);
	lv_label_set_text(ui->screen_gnss_location_btn_back_label, "");
	lv_label_set_long_mode(ui->screen_gnss_location_btn_back_label, LV_LABEL_LONG_WRAP);
	lv_obj_align(ui->screen_gnss_location_btn_back_label, LV_ALIGN_LEFT_MID, 0, 0);
	lv_obj_set_style_pad_all(ui->screen_gnss_location_btn_back, 0, LV_STATE_DEFAULT);
	lv_obj_set_pos(ui->screen_gnss_location_btn_back, 0, 0);
	lv_obj_set_size(ui->screen_gnss_location_btn_back, 240, 50);

	//Write style for screen_gnss_location_btn_back, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_bg_opa(ui->screen_gnss_location_btn_back, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui->screen_gnss_location_btn_back, lv_color_hex(0x292831), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_width(ui->screen_gnss_location_btn_back, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_opa(ui->screen_gnss_location_btn_back, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_color(ui->screen_gnss_location_btn_back, lv_color_hex(0xD200AC), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_side(ui->screen_gnss_location_btn_back, LV_BORDER_SIDE_BOTTOM, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->screen_gnss_location_btn_back, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->screen_gnss_location_btn_back, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->screen_gnss_location_btn_back, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->screen_gnss_location_btn_back, &lv_font_FontAwesome5ProRegular_400_16, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->screen_gnss_location_btn_back, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes screen_gnss_location_label_back
	ui->screen_gnss_location_label_back = lv_label_create(ui->screen_gnss_location);
	lv_label_set_text(ui->screen_gnss_location_label_back, "");
	lv_label_set_long_mode(ui->screen_gnss_location_label_back, LV_LABEL_LONG_WRAP);
	lv_obj_set_pos(ui->screen_gnss_location_label_back, 50, 25);
	lv_obj_set_size(ui->screen_gnss_location_label_back, 23, 16);

	//Write style for screen_gnss_location_label_back, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->screen_gnss_location_label_back, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->screen_gnss_location_label_back, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->screen_gnss_location_label_back, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->screen_gnss_location_label_back, &lv_font_FontAwesome5ProRegular_400_16, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->screen_gnss_location_label_back, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_line_space(ui->screen_gnss_location_label_back, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->screen_gnss_location_label_back, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->screen_gnss_location_label_back, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->screen_gnss_location_label_back, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->screen_gnss_location_label_back, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->screen_gnss_location_label_back, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->screen_gnss_location_label_back, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->screen_gnss_location_label_back, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes screen_gnss_location_label_title
	ui->screen_gnss_location_label_title = lv_label_create(ui->screen_gnss_location);
	lv_label_set_text(ui->screen_gnss_location_label_title, "Location");
	lv_label_set_long_mode(ui->screen_gnss_location_label_title, LV_LABEL_LONG_WRAP);
	lv_obj_set_pos(ui->screen_gnss_location_label_title, 60, 20);
	lv_obj_set_size(ui->screen_gnss_location_label_title, 120, 18);

	//Write style for screen_gnss_location_label_title, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->screen_gnss_location_label_title, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->screen_gnss_location_label_title, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->screen_gnss_location_label_title, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->screen_gnss_location_label_title, &lv_font_montserratMedium_16, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->screen_gnss_location_label_title, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_line_space(ui->screen_gnss_location_label_title, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->screen_gnss_location_label_title, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->screen_gnss_location_label_title, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->screen_gnss_location_label_title, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->screen_gnss_location_label_title, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->screen_gnss_location_label_title, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->screen_gnss_location_label_title, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->screen_gnss_location_label_title, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes screen_gnss_location_qrcode_1
	ui->screen_gnss_location_qrcode_1 = lv_qrcode_create(ui->screen_gnss_location, 150, lv_color_hex(0xffffff), lv_color_hex(0x101418));
	const char * screen_gnss_location_qrcode_1_data = "https://google.com/maps/place/47.229030,8.821840";
	lv_qrcode_update(ui->screen_gnss_location_qrcode_1, screen_gnss_location_qrcode_1_data, strlen(screen_gnss_location_qrcode_1_data));
	lv_obj_set_pos(ui->screen_gnss_location_qrcode_1, 45, 57);
	lv_obj_set_size(ui->screen_gnss_location_qrcode_1, 150, 150);

	//Update current screen layout.
	lv_obj_update_layout(ui->screen_gnss_location);

	
	//Init events for screen.
	events_init_screen_gnss_location(ui);
}
