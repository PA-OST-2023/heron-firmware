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


FLASHMEM void setup_scr_screen_home(lv_ui *ui)
{
	//Write codes screen_home
	ui->screen_home = lv_obj_create(NULL);
	lv_obj_set_size(ui->screen_home, 240, 240);

	//Write style for screen_home, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_bg_opa(ui->screen_home, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui->screen_home, lv_color_hex(0x101418), LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes screen_home_tileview_menu
	ui->screen_home_tileview_menu = lv_tileview_create(ui->screen_home);
	ui->screen_home_tileview_menu_tile_system = lv_tileview_add_tile(ui->screen_home_tileview_menu, 0, 0, LV_DIR_RIGHT);
	ui->screen_home_tileview_menu_tile_ethernet = lv_tileview_add_tile(ui->screen_home_tileview_menu, 1, 0, LV_DIR_LEFT | LV_DIR_RIGHT);
	ui->screen_home_tileview_menu_tile_gnss = lv_tileview_add_tile(ui->screen_home_tileview_menu, 2, 0, LV_DIR_LEFT | LV_DIR_RIGHT);
	ui->screen_home_tileview_menu_tile_compass = lv_tileview_add_tile(ui->screen_home_tileview_menu, 3, 0, LV_DIR_LEFT | LV_DIR_RIGHT);
	ui->screen_home_tileview_menu_tile_arm_angle = lv_tileview_add_tile(ui->screen_home_tileview_menu, 4, 0, LV_DIR_LEFT | LV_DIR_RIGHT);
	ui->screen_home_tileview_menu_tile_ambient = lv_tileview_add_tile(ui->screen_home_tileview_menu, 5, 0, LV_DIR_LEFT | LV_DIR_RIGHT);
	ui->screen_home_tileview_menu_tile_settings = lv_tileview_add_tile(ui->screen_home_tileview_menu, 6, 0, LV_DIR_LEFT);
	lv_obj_set_pos(ui->screen_home_tileview_menu, 0, 55);
	lv_obj_set_size(ui->screen_home_tileview_menu, 240, 180);
	lv_obj_set_scrollbar_mode(ui->screen_home_tileview_menu, LV_SCROLLBAR_MODE_OFF);

	//Write style for screen_home_tileview_menu, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_bg_opa(ui->screen_home_tileview_menu, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->screen_home_tileview_menu, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->screen_home_tileview_menu, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write style for screen_home_tileview_menu, Part: LV_PART_SCROLLBAR, State: LV_STATE_DEFAULT.
	lv_obj_set_style_bg_opa(ui->screen_home_tileview_menu, 255, LV_PART_SCROLLBAR|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui->screen_home_tileview_menu, lv_color_hex(0xeaeff3), LV_PART_SCROLLBAR|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->screen_home_tileview_menu, 0, LV_PART_SCROLLBAR|LV_STATE_DEFAULT);



	//Write codes screen_home_label_system
	ui->screen_home_label_system = lv_label_create(ui->screen_home_tileview_menu_tile_system);
	lv_label_set_text(ui->screen_home_label_system, "System");
	lv_label_set_long_mode(ui->screen_home_label_system, LV_LABEL_LONG_WRAP);
	lv_obj_set_pos(ui->screen_home_label_system, 60, 140);
	lv_obj_set_size(ui->screen_home_label_system, 120, 20);

	//Write style for screen_home_label_system, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->screen_home_label_system, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->screen_home_label_system, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->screen_home_label_system, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->screen_home_label_system, &lv_font_montserratMedium_16, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->screen_home_label_system, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_line_space(ui->screen_home_label_system, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->screen_home_label_system, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->screen_home_label_system, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->screen_home_label_system, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->screen_home_label_system, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->screen_home_label_system, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->screen_home_label_system, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->screen_home_label_system, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes screen_home_btn_system
	ui->screen_home_btn_system = lv_btn_create(ui->screen_home_tileview_menu_tile_system);
	ui->screen_home_btn_system_label = lv_label_create(ui->screen_home_btn_system);
	lv_label_set_text(ui->screen_home_btn_system_label, "");
	lv_label_set_long_mode(ui->screen_home_btn_system_label, LV_LABEL_LONG_WRAP);
	lv_obj_align(ui->screen_home_btn_system_label, LV_ALIGN_CENTER, 0, 0);
	lv_obj_set_style_pad_all(ui->screen_home_btn_system, 0, LV_STATE_DEFAULT);
	lv_obj_set_pos(ui->screen_home_btn_system, 70, 20);
	lv_obj_set_size(ui->screen_home_btn_system, 100, 100);

	//Write style for screen_home_btn_system, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_bg_opa(ui->screen_home_btn_system, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui->screen_home_btn_system, lv_color_hex(0x4cc9f0), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_width(ui->screen_home_btn_system, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->screen_home_btn_system, 14, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->screen_home_btn_system, 13, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_color(ui->screen_home_btn_system, lv_color_hex(0x2195f6), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_opa(ui->screen_home_btn_system, 52, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_spread(ui->screen_home_btn_system, 3, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_ofs_x(ui->screen_home_btn_system, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_ofs_y(ui->screen_home_btn_system, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->screen_home_btn_system, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->screen_home_btn_system, &lv_font_FontAwesome6ProLight_300_50, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->screen_home_btn_system, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);



	//Write codes screen_home_label_ethernet
	ui->screen_home_label_ethernet = lv_label_create(ui->screen_home_tileview_menu_tile_ethernet);
	lv_label_set_text(ui->screen_home_label_ethernet, "Ethernet");
	lv_label_set_long_mode(ui->screen_home_label_ethernet, LV_LABEL_LONG_WRAP);
	lv_obj_set_pos(ui->screen_home_label_ethernet, 60, 140);
	lv_obj_set_size(ui->screen_home_label_ethernet, 120, 20);

	//Write style for screen_home_label_ethernet, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->screen_home_label_ethernet, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->screen_home_label_ethernet, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->screen_home_label_ethernet, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->screen_home_label_ethernet, &lv_font_montserratMedium_16, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->screen_home_label_ethernet, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_line_space(ui->screen_home_label_ethernet, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->screen_home_label_ethernet, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->screen_home_label_ethernet, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->screen_home_label_ethernet, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->screen_home_label_ethernet, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->screen_home_label_ethernet, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->screen_home_label_ethernet, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->screen_home_label_ethernet, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes screen_home_btn_ethernet
	ui->screen_home_btn_ethernet = lv_btn_create(ui->screen_home_tileview_menu_tile_ethernet);
	ui->screen_home_btn_ethernet_label = lv_label_create(ui->screen_home_btn_ethernet);
	lv_label_set_text(ui->screen_home_btn_ethernet_label, "");
	lv_label_set_long_mode(ui->screen_home_btn_ethernet_label, LV_LABEL_LONG_WRAP);
	lv_obj_align(ui->screen_home_btn_ethernet_label, LV_ALIGN_CENTER, 0, 0);
	lv_obj_set_style_pad_all(ui->screen_home_btn_ethernet, 0, LV_STATE_DEFAULT);
	lv_obj_set_pos(ui->screen_home_btn_ethernet, 70, 20);
	lv_obj_set_size(ui->screen_home_btn_ethernet, 100, 100);

	//Write style for screen_home_btn_ethernet, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_bg_opa(ui->screen_home_btn_ethernet, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui->screen_home_btn_ethernet, lv_color_hex(0x4361ee), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_width(ui->screen_home_btn_ethernet, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->screen_home_btn_ethernet, 14, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->screen_home_btn_ethernet, 13, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_color(ui->screen_home_btn_ethernet, lv_color_hex(0x4361ee), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_opa(ui->screen_home_btn_ethernet, 52, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_spread(ui->screen_home_btn_ethernet, 3, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_ofs_x(ui->screen_home_btn_ethernet, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_ofs_y(ui->screen_home_btn_ethernet, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->screen_home_btn_ethernet, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->screen_home_btn_ethernet, &lv_font_FontAwesome5ProLight_300_40, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->screen_home_btn_ethernet, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);



	//Write codes screen_home_label_gnss
	ui->screen_home_label_gnss = lv_label_create(ui->screen_home_tileview_menu_tile_gnss);
	lv_label_set_text(ui->screen_home_label_gnss, "GNSS");
	lv_label_set_long_mode(ui->screen_home_label_gnss, LV_LABEL_LONG_WRAP);
	lv_obj_set_pos(ui->screen_home_label_gnss, 60, 140);
	lv_obj_set_size(ui->screen_home_label_gnss, 120, 20);

	//Write style for screen_home_label_gnss, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->screen_home_label_gnss, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->screen_home_label_gnss, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->screen_home_label_gnss, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->screen_home_label_gnss, &lv_font_montserratMedium_16, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->screen_home_label_gnss, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_line_space(ui->screen_home_label_gnss, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->screen_home_label_gnss, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->screen_home_label_gnss, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->screen_home_label_gnss, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->screen_home_label_gnss, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->screen_home_label_gnss, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->screen_home_label_gnss, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->screen_home_label_gnss, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes screen_home_btn_gnss
	ui->screen_home_btn_gnss = lv_btn_create(ui->screen_home_tileview_menu_tile_gnss);
	ui->screen_home_btn_gnss_label = lv_label_create(ui->screen_home_btn_gnss);
	lv_label_set_text(ui->screen_home_btn_gnss_label, "");
	lv_label_set_long_mode(ui->screen_home_btn_gnss_label, LV_LABEL_LONG_WRAP);
	lv_obj_align(ui->screen_home_btn_gnss_label, LV_ALIGN_CENTER, 0, 0);
	lv_obj_set_style_pad_all(ui->screen_home_btn_gnss, 0, LV_STATE_DEFAULT);
	lv_obj_set_pos(ui->screen_home_btn_gnss, 70, 20);
	lv_obj_set_size(ui->screen_home_btn_gnss, 100, 100);

	//Write style for screen_home_btn_gnss, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_bg_opa(ui->screen_home_btn_gnss, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui->screen_home_btn_gnss, lv_color_hex(0xc30d72), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_width(ui->screen_home_btn_gnss, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->screen_home_btn_gnss, 14, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->screen_home_btn_gnss, 13, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_color(ui->screen_home_btn_gnss, lv_color_hex(0xc30d72), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_opa(ui->screen_home_btn_gnss, 52, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_spread(ui->screen_home_btn_gnss, 3, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_ofs_x(ui->screen_home_btn_gnss, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_ofs_y(ui->screen_home_btn_gnss, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->screen_home_btn_gnss, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->screen_home_btn_gnss, &lv_font_FontAwesome5ProLight_300_40, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->screen_home_btn_gnss, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);



	//Write codes screen_home_label_compass
	ui->screen_home_label_compass = lv_label_create(ui->screen_home_tileview_menu_tile_compass);
	lv_label_set_text(ui->screen_home_label_compass, "Compass\n");
	lv_label_set_long_mode(ui->screen_home_label_compass, LV_LABEL_LONG_WRAP);
	lv_obj_set_pos(ui->screen_home_label_compass, 60, 140);
	lv_obj_set_size(ui->screen_home_label_compass, 120, 20);

	//Write style for screen_home_label_compass, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->screen_home_label_compass, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->screen_home_label_compass, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->screen_home_label_compass, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->screen_home_label_compass, &lv_font_montserratMedium_16, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->screen_home_label_compass, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_line_space(ui->screen_home_label_compass, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->screen_home_label_compass, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->screen_home_label_compass, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->screen_home_label_compass, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->screen_home_label_compass, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->screen_home_label_compass, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->screen_home_label_compass, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->screen_home_label_compass, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes screen_home_btn_compass
	ui->screen_home_btn_compass = lv_btn_create(ui->screen_home_tileview_menu_tile_compass);
	ui->screen_home_btn_compass_label = lv_label_create(ui->screen_home_btn_compass);
	lv_label_set_text(ui->screen_home_btn_compass_label, "");
	lv_label_set_long_mode(ui->screen_home_btn_compass_label, LV_LABEL_LONG_WRAP);
	lv_obj_align(ui->screen_home_btn_compass_label, LV_ALIGN_CENTER, 0, 0);
	lv_obj_set_style_pad_all(ui->screen_home_btn_compass, 0, LV_STATE_DEFAULT);
	lv_obj_set_pos(ui->screen_home_btn_compass, 70, 20);
	lv_obj_set_size(ui->screen_home_btn_compass, 100, 100);

	//Write style for screen_home_btn_compass, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_bg_opa(ui->screen_home_btn_compass, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui->screen_home_btn_compass, lv_color_hex(0x06d6a0), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_width(ui->screen_home_btn_compass, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->screen_home_btn_compass, 14, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->screen_home_btn_compass, 13, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_color(ui->screen_home_btn_compass, lv_color_hex(0x06d6a0), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_opa(ui->screen_home_btn_compass, 52, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_spread(ui->screen_home_btn_compass, 3, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_ofs_x(ui->screen_home_btn_compass, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_ofs_y(ui->screen_home_btn_compass, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->screen_home_btn_compass, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->screen_home_btn_compass, &lv_font_FontAwesome6SharpLight_300_50, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->screen_home_btn_compass, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);



	//Write codes screen_home_label_arm_angle
	ui->screen_home_label_arm_angle = lv_label_create(ui->screen_home_tileview_menu_tile_arm_angle);
	lv_label_set_text(ui->screen_home_label_arm_angle, "Arm Angle");
	lv_label_set_long_mode(ui->screen_home_label_arm_angle, LV_LABEL_LONG_WRAP);
	lv_obj_set_pos(ui->screen_home_label_arm_angle, 60, 140);
	lv_obj_set_size(ui->screen_home_label_arm_angle, 120, 20);

	//Write style for screen_home_label_arm_angle, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->screen_home_label_arm_angle, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->screen_home_label_arm_angle, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->screen_home_label_arm_angle, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->screen_home_label_arm_angle, &lv_font_montserratMedium_16, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->screen_home_label_arm_angle, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_line_space(ui->screen_home_label_arm_angle, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->screen_home_label_arm_angle, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->screen_home_label_arm_angle, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->screen_home_label_arm_angle, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->screen_home_label_arm_angle, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->screen_home_label_arm_angle, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->screen_home_label_arm_angle, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->screen_home_label_arm_angle, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes screen_home_btn_arm_angle
	ui->screen_home_btn_arm_angle = lv_btn_create(ui->screen_home_tileview_menu_tile_arm_angle);
	ui->screen_home_btn_arm_angle_label = lv_label_create(ui->screen_home_btn_arm_angle);
	lv_label_set_text(ui->screen_home_btn_arm_angle_label, "");
	lv_label_set_long_mode(ui->screen_home_btn_arm_angle_label, LV_LABEL_LONG_WRAP);
	lv_obj_align(ui->screen_home_btn_arm_angle_label, LV_ALIGN_CENTER, 0, 0);
	lv_obj_set_style_pad_all(ui->screen_home_btn_arm_angle, 0, LV_STATE_DEFAULT);
	lv_obj_set_pos(ui->screen_home_btn_arm_angle, 70, 20);
	lv_obj_set_size(ui->screen_home_btn_arm_angle, 100, 100);

	//Write style for screen_home_btn_arm_angle, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_bg_opa(ui->screen_home_btn_arm_angle, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui->screen_home_btn_arm_angle, lv_color_hex(0xE94560), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_width(ui->screen_home_btn_arm_angle, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->screen_home_btn_arm_angle, 14, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->screen_home_btn_arm_angle, 13, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_color(ui->screen_home_btn_arm_angle, lv_color_hex(0xE94560), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_opa(ui->screen_home_btn_arm_angle, 52, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_spread(ui->screen_home_btn_arm_angle, 3, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_ofs_x(ui->screen_home_btn_arm_angle, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_ofs_y(ui->screen_home_btn_arm_angle, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->screen_home_btn_arm_angle, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->screen_home_btn_arm_angle, &lv_font_FontAwesome6Regular_400_50, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->screen_home_btn_arm_angle, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);



	//Write codes screen_home_label_ambient
	ui->screen_home_label_ambient = lv_label_create(ui->screen_home_tileview_menu_tile_ambient);
	lv_label_set_text(ui->screen_home_label_ambient, "Ambient\nSensor");
	lv_label_set_long_mode(ui->screen_home_label_ambient, LV_LABEL_LONG_WRAP);
	lv_obj_set_pos(ui->screen_home_label_ambient, 60, 140);
	lv_obj_set_size(ui->screen_home_label_ambient, 120, 40);

	//Write style for screen_home_label_ambient, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->screen_home_label_ambient, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->screen_home_label_ambient, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->screen_home_label_ambient, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->screen_home_label_ambient, &lv_font_montserratMedium_16, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->screen_home_label_ambient, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_line_space(ui->screen_home_label_ambient, 1, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->screen_home_label_ambient, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->screen_home_label_ambient, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->screen_home_label_ambient, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->screen_home_label_ambient, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->screen_home_label_ambient, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->screen_home_label_ambient, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->screen_home_label_ambient, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes screen_home_btn_ambient
	ui->screen_home_btn_ambient = lv_btn_create(ui->screen_home_tileview_menu_tile_ambient);
	ui->screen_home_btn_ambient_label = lv_label_create(ui->screen_home_btn_ambient);
	lv_label_set_text(ui->screen_home_btn_ambient_label, "");
	lv_label_set_long_mode(ui->screen_home_btn_ambient_label, LV_LABEL_LONG_WRAP);
	lv_obj_align(ui->screen_home_btn_ambient_label, LV_ALIGN_CENTER, 0, 0);
	lv_obj_set_style_pad_all(ui->screen_home_btn_ambient, 0, LV_STATE_DEFAULT);
	lv_obj_set_pos(ui->screen_home_btn_ambient, 70, 20);
	lv_obj_set_size(ui->screen_home_btn_ambient, 100, 100);

	//Write style for screen_home_btn_ambient, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_bg_opa(ui->screen_home_btn_ambient, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui->screen_home_btn_ambient, lv_color_hex(0xF6C90E), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_width(ui->screen_home_btn_ambient, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->screen_home_btn_ambient, 14, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->screen_home_btn_ambient, 13, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_color(ui->screen_home_btn_ambient, lv_color_hex(0xF6C90E), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_opa(ui->screen_home_btn_ambient, 52, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_spread(ui->screen_home_btn_ambient, 3, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_ofs_x(ui->screen_home_btn_ambient, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_ofs_y(ui->screen_home_btn_ambient, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->screen_home_btn_ambient, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->screen_home_btn_ambient, &lv_font_FontAwesome6ProLight_300_50, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->screen_home_btn_ambient, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);



	//Write codes screen_home_label_settings
	ui->screen_home_label_settings = lv_label_create(ui->screen_home_tileview_menu_tile_settings);
	lv_label_set_text(ui->screen_home_label_settings, "Settings");
	lv_label_set_long_mode(ui->screen_home_label_settings, LV_LABEL_LONG_WRAP);
	lv_obj_set_pos(ui->screen_home_label_settings, 60, 140);
	lv_obj_set_size(ui->screen_home_label_settings, 120, 40);

	//Write style for screen_home_label_settings, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->screen_home_label_settings, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->screen_home_label_settings, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->screen_home_label_settings, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->screen_home_label_settings, &lv_font_montserratMedium_16, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->screen_home_label_settings, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_line_space(ui->screen_home_label_settings, 1, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->screen_home_label_settings, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->screen_home_label_settings, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->screen_home_label_settings, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->screen_home_label_settings, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->screen_home_label_settings, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->screen_home_label_settings, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->screen_home_label_settings, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes screen_home_btn_settings
	ui->screen_home_btn_settings = lv_btn_create(ui->screen_home_tileview_menu_tile_settings);
	ui->screen_home_btn_settings_label = lv_label_create(ui->screen_home_btn_settings);
	lv_label_set_text(ui->screen_home_btn_settings_label, "");
	lv_label_set_long_mode(ui->screen_home_btn_settings_label, LV_LABEL_LONG_WRAP);
	lv_obj_align(ui->screen_home_btn_settings_label, LV_ALIGN_CENTER, 0, 0);
	lv_obj_set_style_pad_all(ui->screen_home_btn_settings, 0, LV_STATE_DEFAULT);
	lv_obj_set_pos(ui->screen_home_btn_settings, 70, 20);
	lv_obj_set_size(ui->screen_home_btn_settings, 100, 100);

	//Write style for screen_home_btn_settings, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_bg_opa(ui->screen_home_btn_settings, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui->screen_home_btn_settings, lv_color_hex(0x818181), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_width(ui->screen_home_btn_settings, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->screen_home_btn_settings, 14, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->screen_home_btn_settings, 13, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_color(ui->screen_home_btn_settings, lv_color_hex(0xF6C90E), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_opa(ui->screen_home_btn_settings, 52, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_spread(ui->screen_home_btn_settings, 3, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_ofs_x(ui->screen_home_btn_settings, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_ofs_y(ui->screen_home_btn_settings, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->screen_home_btn_settings, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->screen_home_btn_settings, &lv_font_FontAwesome5ProLight_300_50, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->screen_home_btn_settings, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes screen_home_cont_top_bar
	ui->screen_home_cont_top_bar = lv_obj_create(ui->screen_home);
	lv_obj_set_pos(ui->screen_home_cont_top_bar, 0, 0);
	lv_obj_set_size(ui->screen_home_cont_top_bar, 240, 50);
	lv_obj_set_scrollbar_mode(ui->screen_home_cont_top_bar, LV_SCROLLBAR_MODE_OFF);

	//Write style for screen_home_cont_top_bar, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->screen_home_cont_top_bar, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_opa(ui->screen_home_cont_top_bar, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_color(ui->screen_home_cont_top_bar, lv_color_hex(0xD200AC), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_side(ui->screen_home_cont_top_bar, LV_BORDER_SIDE_BOTTOM, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->screen_home_cont_top_bar, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->screen_home_cont_top_bar, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui->screen_home_cont_top_bar, lv_color_hex(0x292831), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->screen_home_cont_top_bar, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->screen_home_cont_top_bar, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->screen_home_cont_top_bar, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->screen_home_cont_top_bar, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->screen_home_cont_top_bar, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes screen_home_label_warning
	ui->screen_home_label_warning = lv_label_create(ui->screen_home_cont_top_bar);
	lv_label_set_text(ui->screen_home_label_warning, "");
	lv_label_set_long_mode(ui->screen_home_label_warning, LV_LABEL_LONG_WRAP);
	lv_obj_set_pos(ui->screen_home_label_warning, 168, 24);
	lv_obj_set_size(ui->screen_home_label_warning, 22, 19);
	lv_obj_add_flag(ui->screen_home_label_warning, LV_OBJ_FLAG_HIDDEN);

	//Write style for screen_home_label_warning, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->screen_home_label_warning, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->screen_home_label_warning, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->screen_home_label_warning, lv_color_hex(0xff8f00), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->screen_home_label_warning, &lv_font_FontAwesome5ProSolid_900_16, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->screen_home_label_warning, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_line_space(ui->screen_home_label_warning, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->screen_home_label_warning, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->screen_home_label_warning, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->screen_home_label_warning, 1, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->screen_home_label_warning, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->screen_home_label_warning, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->screen_home_label_warning, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->screen_home_label_warning, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes screen_home_label_usb_status
	ui->screen_home_label_usb_status = lv_label_create(ui->screen_home_cont_top_bar);
	lv_label_set_text(ui->screen_home_label_usb_status, "\n");
	lv_label_set_long_mode(ui->screen_home_label_usb_status, LV_LABEL_LONG_WRAP);
	lv_obj_set_pos(ui->screen_home_label_usb_status, 142, 26);
	lv_obj_set_size(ui->screen_home_label_usb_status, 22, 17);

	//Write style for screen_home_label_usb_status, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->screen_home_label_usb_status, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->screen_home_label_usb_status, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->screen_home_label_usb_status, lv_color_hex(0x444447), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->screen_home_label_usb_status, &lv_font_FontAwesome5_15, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->screen_home_label_usb_status, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_line_space(ui->screen_home_label_usb_status, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->screen_home_label_usb_status, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->screen_home_label_usb_status, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->screen_home_label_usb_status, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->screen_home_label_usb_status, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->screen_home_label_usb_status, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->screen_home_label_usb_status, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->screen_home_label_usb_status, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes screen_home_label_ethernet_status
	ui->screen_home_label_ethernet_status = lv_label_create(ui->screen_home_cont_top_bar);
	lv_label_set_text(ui->screen_home_label_ethernet_status, "");
	lv_label_set_long_mode(ui->screen_home_label_ethernet_status, LV_LABEL_LONG_WRAP);
	lv_obj_set_pos(ui->screen_home_label_ethernet_status, 109, 25);
	lv_obj_set_size(ui->screen_home_label_ethernet_status, 22, 17);

	//Write style for screen_home_label_ethernet_status, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->screen_home_label_ethernet_status, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->screen_home_label_ethernet_status, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->screen_home_label_ethernet_status, lv_color_hex(0x444447), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->screen_home_label_ethernet_status, &lv_font_FontAwesome5ProRegular_400_16, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->screen_home_label_ethernet_status, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_line_space(ui->screen_home_label_ethernet_status, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->screen_home_label_ethernet_status, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->screen_home_label_ethernet_status, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->screen_home_label_ethernet_status, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->screen_home_label_ethernet_status, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->screen_home_label_ethernet_status, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->screen_home_label_ethernet_status, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->screen_home_label_ethernet_status, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes screen_home_label_gnss_status
	ui->screen_home_label_gnss_status = lv_label_create(ui->screen_home_cont_top_bar);
	lv_label_set_text(ui->screen_home_label_gnss_status, "");
	lv_label_set_long_mode(ui->screen_home_label_gnss_status, LV_LABEL_LONG_WRAP);
	lv_obj_set_pos(ui->screen_home_label_gnss_status, 77, 25);
	lv_obj_set_size(ui->screen_home_label_gnss_status, 22, 17);

	//Write style for screen_home_label_gnss_status, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->screen_home_label_gnss_status, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->screen_home_label_gnss_status, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->screen_home_label_gnss_status, lv_color_hex(0x444447), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->screen_home_label_gnss_status, &lv_font_FontAwesome5ProRegular_400_16, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->screen_home_label_gnss_status, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_line_space(ui->screen_home_label_gnss_status, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->screen_home_label_gnss_status, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->screen_home_label_gnss_status, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->screen_home_label_gnss_status, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->screen_home_label_gnss_status, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->screen_home_label_gnss_status, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->screen_home_label_gnss_status, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->screen_home_label_gnss_status, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes screen_home_label_current_time
	ui->screen_home_label_current_time = lv_label_create(ui->screen_home_cont_top_bar);
	lv_label_set_text(ui->screen_home_label_current_time, "00:00");
	lv_label_set_long_mode(ui->screen_home_label_current_time, LV_LABEL_LONG_WRAP);
	lv_obj_set_pos(ui->screen_home_label_current_time, 92.5, 3);
	lv_obj_set_size(ui->screen_home_label_current_time, 55, 15);

	//Write style for screen_home_label_current_time, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->screen_home_label_current_time, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->screen_home_label_current_time, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->screen_home_label_current_time, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->screen_home_label_current_time, &lv_font_montserratMedium_16, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->screen_home_label_current_time, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_line_space(ui->screen_home_label_current_time, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->screen_home_label_current_time, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->screen_home_label_current_time, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->screen_home_label_current_time, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->screen_home_label_current_time, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->screen_home_label_current_time, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->screen_home_label_current_time, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->screen_home_label_current_time, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes screen_home_btn_warning
	ui->screen_home_btn_warning = lv_btn_create(ui->screen_home);
	ui->screen_home_btn_warning_label = lv_label_create(ui->screen_home_btn_warning);
	lv_label_set_text(ui->screen_home_btn_warning_label, "");
	lv_label_set_long_mode(ui->screen_home_btn_warning_label, LV_LABEL_LONG_WRAP);
	lv_obj_align(ui->screen_home_btn_warning_label, LV_ALIGN_LEFT_MID, 0, 0);
	lv_obj_set_style_pad_all(ui->screen_home_btn_warning, 0, LV_STATE_DEFAULT);
	lv_obj_set_pos(ui->screen_home_btn_warning, 0, 0);
	lv_obj_set_size(ui->screen_home_btn_warning, 240, 50);

	//Write style for screen_home_btn_warning, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_bg_opa(ui->screen_home_btn_warning, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_width(ui->screen_home_btn_warning, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->screen_home_btn_warning, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->screen_home_btn_warning, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->screen_home_btn_warning, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->screen_home_btn_warning, &lv_font_FontAwesome5ProRegular_400_16, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->screen_home_btn_warning, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes screen_home_cont_warning_background
	ui->screen_home_cont_warning_background = lv_obj_create(ui->screen_home);
	lv_obj_set_pos(ui->screen_home_cont_warning_background, 0, 0);
	lv_obj_set_size(ui->screen_home_cont_warning_background, 240, 240);
	lv_obj_set_scrollbar_mode(ui->screen_home_cont_warning_background, LV_SCROLLBAR_MODE_OFF);
	lv_obj_add_flag(ui->screen_home_cont_warning_background, LV_OBJ_FLAG_HIDDEN);

	//Write style for screen_home_cont_warning_background, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->screen_home_cont_warning_background, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->screen_home_cont_warning_background, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->screen_home_cont_warning_background, 108, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui->screen_home_cont_warning_background, lv_color_hex(0x828282), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->screen_home_cont_warning_background, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->screen_home_cont_warning_background, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->screen_home_cont_warning_background, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->screen_home_cont_warning_background, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->screen_home_cont_warning_background, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes screen_home_cont_warning
	ui->screen_home_cont_warning = lv_obj_create(ui->screen_home_cont_warning_background);
	lv_obj_set_pos(ui->screen_home_cont_warning, 25, 55);
	lv_obj_set_size(ui->screen_home_cont_warning, 190, 130);
	lv_obj_set_scrollbar_mode(ui->screen_home_cont_warning, LV_SCROLLBAR_MODE_OFF);

	//Write style for screen_home_cont_warning, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->screen_home_cont_warning, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_opa(ui->screen_home_cont_warning, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_color(ui->screen_home_cont_warning, lv_color_hex(0xff8f00), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_side(ui->screen_home_cont_warning, LV_BORDER_SIDE_FULL, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->screen_home_cont_warning, 10, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->screen_home_cont_warning, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui->screen_home_cont_warning, lv_color_hex(0x292831), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->screen_home_cont_warning, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->screen_home_cont_warning, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->screen_home_cont_warning, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->screen_home_cont_warning, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->screen_home_cont_warning, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes screen_home_cont_warning_ok
	ui->screen_home_cont_warning_ok = lv_obj_create(ui->screen_home_cont_warning);
	lv_obj_set_pos(ui->screen_home_cont_warning_ok, 0, 91);
	lv_obj_set_size(ui->screen_home_cont_warning_ok, 186, 15);
	lv_obj_set_scrollbar_mode(ui->screen_home_cont_warning_ok, LV_SCROLLBAR_MODE_OFF);

	//Write style for screen_home_cont_warning_ok, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->screen_home_cont_warning_ok, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_opa(ui->screen_home_cont_warning_ok, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_color(ui->screen_home_cont_warning_ok, lv_color_hex(0xff8f00), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_side(ui->screen_home_cont_warning_ok, LV_BORDER_SIDE_TOP, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->screen_home_cont_warning_ok, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->screen_home_cont_warning_ok, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui->screen_home_cont_warning_ok, lv_color_hex(0x525258), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->screen_home_cont_warning_ok, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->screen_home_cont_warning_ok, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->screen_home_cont_warning_ok, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->screen_home_cont_warning_ok, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->screen_home_cont_warning_ok, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes screen_home_btn_warning_ok
	ui->screen_home_btn_warning_ok = lv_btn_create(ui->screen_home_cont_warning);
	ui->screen_home_btn_warning_ok_label = lv_label_create(ui->screen_home_btn_warning_ok);
	lv_label_set_text(ui->screen_home_btn_warning_ok_label, "OK");
	lv_label_set_long_mode(ui->screen_home_btn_warning_ok_label, LV_LABEL_LONG_WRAP);
	lv_obj_align(ui->screen_home_btn_warning_ok_label, LV_ALIGN_CENTER, 0, 0);
	lv_obj_set_style_pad_all(ui->screen_home_btn_warning_ok, 0, LV_STATE_DEFAULT);
	lv_obj_set_pos(ui->screen_home_btn_warning_ok, 0, 96);
	lv_obj_set_size(ui->screen_home_btn_warning_ok, 186, 30);

	//Write style for screen_home_btn_warning_ok, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_bg_opa(ui->screen_home_btn_warning_ok, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui->screen_home_btn_warning_ok, lv_color_hex(0x525258), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_width(ui->screen_home_btn_warning_ok, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->screen_home_btn_warning_ok, 7, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->screen_home_btn_warning_ok, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->screen_home_btn_warning_ok, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->screen_home_btn_warning_ok, &lv_font_montserratMedium_16, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->screen_home_btn_warning_ok, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes screen_home_label_warning_text
	ui->screen_home_label_warning_text = lv_label_create(ui->screen_home_cont_warning);
	lv_label_set_text(ui->screen_home_label_warning_text, " ");
	lv_label_set_long_mode(ui->screen_home_label_warning_text, LV_LABEL_LONG_WRAP);
	lv_obj_set_pos(ui->screen_home_label_warning_text, 5, 5);
	lv_obj_set_size(ui->screen_home_label_warning_text, 176, 81);

	//Write style for screen_home_label_warning_text, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->screen_home_label_warning_text, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->screen_home_label_warning_text, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->screen_home_label_warning_text, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->screen_home_label_warning_text, &lv_font_montserratMedium_14, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->screen_home_label_warning_text, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_line_space(ui->screen_home_label_warning_text, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->screen_home_label_warning_text, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->screen_home_label_warning_text, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->screen_home_label_warning_text, 3, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->screen_home_label_warning_text, 3, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->screen_home_label_warning_text, 3, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->screen_home_label_warning_text, 3, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->screen_home_label_warning_text, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Update current screen layout.
	lv_obj_update_layout(ui->screen_home);

	
	//Init events for screen.
	events_init_screen_home(ui);
}
