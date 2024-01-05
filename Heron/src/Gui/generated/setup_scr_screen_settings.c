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


FLASHMEM void setup_scr_screen_settings(lv_ui *ui)
{
	//Write codes screen_settings
	ui->screen_settings = lv_obj_create(NULL);
	lv_obj_set_size(ui->screen_settings, 240, 240);

	//Write style for screen_settings, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_bg_opa(ui->screen_settings, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui->screen_settings, lv_color_hex(0x101418), LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes screen_settings_cont_settings
	ui->screen_settings_cont_settings = lv_obj_create(ui->screen_settings);
	lv_obj_set_pos(ui->screen_settings_cont_settings, 10, 50);
	lv_obj_set_size(ui->screen_settings_cont_settings, 220, 177);
	lv_obj_set_scrollbar_mode(ui->screen_settings_cont_settings, LV_SCROLLBAR_MODE_OFF);

	//Write style for screen_settings_cont_settings, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->screen_settings_cont_settings, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_opa(ui->screen_settings_cont_settings, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_color(ui->screen_settings_cont_settings, lv_color_hex(0x2195f6), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_side(ui->screen_settings_cont_settings, LV_BORDER_SIDE_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->screen_settings_cont_settings, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->screen_settings_cont_settings, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->screen_settings_cont_settings, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->screen_settings_cont_settings, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->screen_settings_cont_settings, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->screen_settings_cont_settings, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->screen_settings_cont_settings, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes screen_settings_cont_leds
	ui->screen_settings_cont_leds = lv_obj_create(ui->screen_settings_cont_settings);
	lv_obj_set_pos(ui->screen_settings_cont_leds, 20, 97);
	lv_obj_set_size(ui->screen_settings_cont_leds, 180, 150);
	lv_obj_set_scrollbar_mode(ui->screen_settings_cont_leds, LV_SCROLLBAR_MODE_OFF);

	//Write style for screen_settings_cont_leds, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->screen_settings_cont_leds, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_opa(ui->screen_settings_cont_leds, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_color(ui->screen_settings_cont_leds, lv_color_hex(0x2195f6), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_side(ui->screen_settings_cont_leds, LV_BORDER_SIDE_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->screen_settings_cont_leds, 4, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->screen_settings_cont_leds, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui->screen_settings_cont_leds, lv_color_hex(0x292831), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->screen_settings_cont_leds, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->screen_settings_cont_leds, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->screen_settings_cont_leds, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->screen_settings_cont_leds, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->screen_settings_cont_leds, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes screen_settings_slider_brightness_leds
	ui->screen_settings_slider_brightness_leds = lv_slider_create(ui->screen_settings_cont_leds);
	lv_slider_set_range(ui->screen_settings_slider_brightness_leds, 0, 255);
	lv_slider_set_mode(ui->screen_settings_slider_brightness_leds, LV_SLIDER_MODE_NORMAL);
	lv_slider_set_value(ui->screen_settings_slider_brightness_leds, 127, LV_ANIM_OFF);
	lv_obj_set_pos(ui->screen_settings_slider_brightness_leds, 20, 125);
	lv_obj_set_size(ui->screen_settings_slider_brightness_leds, 140, 5);

	//Write style for screen_settings_slider_brightness_leds, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_bg_opa(ui->screen_settings_slider_brightness_leds, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui->screen_settings_slider_brightness_leds, lv_color_hex(0x41485a), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->screen_settings_slider_brightness_leds, 50, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_outline_width(ui->screen_settings_slider_brightness_leds, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->screen_settings_slider_brightness_leds, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write style for screen_settings_slider_brightness_leds, Part: LV_PART_INDICATOR, State: LV_STATE_DEFAULT.
	lv_obj_set_style_bg_opa(ui->screen_settings_slider_brightness_leds, 255, LV_PART_INDICATOR|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui->screen_settings_slider_brightness_leds, lv_color_hex(0xffffff), LV_PART_INDICATOR|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->screen_settings_slider_brightness_leds, 50, LV_PART_INDICATOR|LV_STATE_DEFAULT);

	//Write style for screen_settings_slider_brightness_leds, Part: LV_PART_KNOB, State: LV_STATE_DEFAULT.
	lv_obj_set_style_bg_opa(ui->screen_settings_slider_brightness_leds, 255, LV_PART_KNOB|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui->screen_settings_slider_brightness_leds, lv_color_hex(0xffffff), LV_PART_KNOB|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->screen_settings_slider_brightness_leds, 50, LV_PART_KNOB|LV_STATE_DEFAULT);

	//Write codes screen_settings_label_brightness_leds
	ui->screen_settings_label_brightness_leds = lv_label_create(ui->screen_settings_cont_leds);
	lv_label_set_text(ui->screen_settings_label_brightness_leds, "Brightness: 100 %");
	lv_label_set_long_mode(ui->screen_settings_label_brightness_leds, LV_LABEL_LONG_WRAP);
	lv_obj_set_pos(ui->screen_settings_label_brightness_leds, 10, 91);
	lv_obj_set_size(ui->screen_settings_label_brightness_leds, 150, 20);

	//Write style for screen_settings_label_brightness_leds, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->screen_settings_label_brightness_leds, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->screen_settings_label_brightness_leds, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->screen_settings_label_brightness_leds, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->screen_settings_label_brightness_leds, &lv_font_montserratMedium_16, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->screen_settings_label_brightness_leds, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_line_space(ui->screen_settings_label_brightness_leds, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->screen_settings_label_brightness_leds, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->screen_settings_label_brightness_leds, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->screen_settings_label_brightness_leds, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->screen_settings_label_brightness_leds, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->screen_settings_label_brightness_leds, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->screen_settings_label_brightness_leds, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->screen_settings_label_brightness_leds, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes screen_settings_ddlist_mode_leds
	ui->screen_settings_ddlist_mode_leds = lv_dropdown_create(ui->screen_settings_cont_leds);
	lv_dropdown_set_options(ui->screen_settings_ddlist_mode_leds, "Audio\nOST");
	lv_obj_set_pos(ui->screen_settings_ddlist_mode_leds, 67, 47);
	lv_obj_set_size(ui->screen_settings_ddlist_mode_leds, 100, 30);

	//Write style for screen_settings_ddlist_mode_leds, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_text_color(ui->screen_settings_ddlist_mode_leds, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->screen_settings_ddlist_mode_leds, &lv_font_montserratMedium_16, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_width(ui->screen_settings_ddlist_mode_leds, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->screen_settings_ddlist_mode_leds, 8, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->screen_settings_ddlist_mode_leds, 6, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->screen_settings_ddlist_mode_leds, 6, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->screen_settings_ddlist_mode_leds, 3, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->screen_settings_ddlist_mode_leds, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui->screen_settings_ddlist_mode_leds, lv_color_hex(0x41485a), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->screen_settings_ddlist_mode_leds, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write style state: LV_STATE_CHECKED for &style_screen_settings_ddlist_mode_leds_extra_list_selected_checked
	static lv_style_t style_screen_settings_ddlist_mode_leds_extra_list_selected_checked;
	ui_init_style(&style_screen_settings_ddlist_mode_leds_extra_list_selected_checked);
	
	lv_style_set_text_color(&style_screen_settings_ddlist_mode_leds_extra_list_selected_checked, lv_color_hex(0xffffff));
	lv_style_set_text_font(&style_screen_settings_ddlist_mode_leds_extra_list_selected_checked, &lv_font_montserratMedium_16);
	lv_style_set_border_width(&style_screen_settings_ddlist_mode_leds_extra_list_selected_checked, 0);
	lv_style_set_radius(&style_screen_settings_ddlist_mode_leds_extra_list_selected_checked, 3);
	lv_style_set_bg_opa(&style_screen_settings_ddlist_mode_leds_extra_list_selected_checked, 255);
	lv_style_set_bg_color(&style_screen_settings_ddlist_mode_leds_extra_list_selected_checked, lv_color_hex(0x9c9c9c));
	lv_obj_add_style(lv_dropdown_get_list(ui->screen_settings_ddlist_mode_leds), &style_screen_settings_ddlist_mode_leds_extra_list_selected_checked, LV_PART_SELECTED|LV_STATE_CHECKED);

	//Write style state: LV_STATE_DEFAULT for &style_screen_settings_ddlist_mode_leds_extra_list_main_default
	static lv_style_t style_screen_settings_ddlist_mode_leds_extra_list_main_default;
	ui_init_style(&style_screen_settings_ddlist_mode_leds_extra_list_main_default);
	
	lv_style_set_max_height(&style_screen_settings_ddlist_mode_leds_extra_list_main_default, 90);
	lv_style_set_text_color(&style_screen_settings_ddlist_mode_leds_extra_list_main_default, lv_color_hex(0xffffff));
	lv_style_set_text_font(&style_screen_settings_ddlist_mode_leds_extra_list_main_default, &lv_font_montserratMedium_16);
	lv_style_set_border_width(&style_screen_settings_ddlist_mode_leds_extra_list_main_default, 0);
	lv_style_set_radius(&style_screen_settings_ddlist_mode_leds_extra_list_main_default, 3);
	lv_style_set_bg_opa(&style_screen_settings_ddlist_mode_leds_extra_list_main_default, 255);
	lv_style_set_bg_color(&style_screen_settings_ddlist_mode_leds_extra_list_main_default, lv_color_hex(0x41485a));
	lv_obj_add_style(lv_dropdown_get_list(ui->screen_settings_ddlist_mode_leds), &style_screen_settings_ddlist_mode_leds_extra_list_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write style state: LV_STATE_DEFAULT for &style_screen_settings_ddlist_mode_leds_extra_list_scrollbar_default
	static lv_style_t style_screen_settings_ddlist_mode_leds_extra_list_scrollbar_default;
	ui_init_style(&style_screen_settings_ddlist_mode_leds_extra_list_scrollbar_default);
	
	lv_style_set_radius(&style_screen_settings_ddlist_mode_leds_extra_list_scrollbar_default, 3);
	lv_style_set_bg_opa(&style_screen_settings_ddlist_mode_leds_extra_list_scrollbar_default, 255);
	lv_style_set_bg_color(&style_screen_settings_ddlist_mode_leds_extra_list_scrollbar_default, lv_color_hex(0x00ff00));
	lv_obj_add_style(lv_dropdown_get_list(ui->screen_settings_ddlist_mode_leds), &style_screen_settings_ddlist_mode_leds_extra_list_scrollbar_default, LV_PART_SCROLLBAR|LV_STATE_DEFAULT);

	//Write codes screen_settings_label_mode_leds
	ui->screen_settings_label_mode_leds = lv_label_create(ui->screen_settings_cont_leds);
	lv_label_set_text(ui->screen_settings_label_mode_leds, "Mode");
	lv_label_set_long_mode(ui->screen_settings_label_mode_leds, LV_LABEL_LONG_WRAP);
	lv_obj_set_pos(ui->screen_settings_label_mode_leds, 10, 53);
	lv_obj_set_size(ui->screen_settings_label_mode_leds, 60, 16);

	//Write style for screen_settings_label_mode_leds, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->screen_settings_label_mode_leds, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->screen_settings_label_mode_leds, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->screen_settings_label_mode_leds, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->screen_settings_label_mode_leds, &lv_font_montserratMedium_16, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->screen_settings_label_mode_leds, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_line_space(ui->screen_settings_label_mode_leds, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->screen_settings_label_mode_leds, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->screen_settings_label_mode_leds, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->screen_settings_label_mode_leds, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->screen_settings_label_mode_leds, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->screen_settings_label_mode_leds, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->screen_settings_label_mode_leds, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->screen_settings_label_mode_leds, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes screen_settings_sw_enable_leds
	ui->screen_settings_sw_enable_leds = lv_switch_create(ui->screen_settings_cont_leds);
	lv_obj_set_pos(ui->screen_settings_sw_enable_leds, 117, 6);
	lv_obj_set_size(ui->screen_settings_sw_enable_leds, 50, 26);

	//Write style for screen_settings_sw_enable_leds, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_bg_opa(ui->screen_settings_sw_enable_leds, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui->screen_settings_sw_enable_leds, lv_color_hex(0x41485a), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_width(ui->screen_settings_sw_enable_leds, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->screen_settings_sw_enable_leds, 13, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->screen_settings_sw_enable_leds, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write style for screen_settings_sw_enable_leds, Part: LV_PART_INDICATOR, State: LV_STATE_CHECKED.
	lv_obj_set_style_bg_opa(ui->screen_settings_sw_enable_leds, 255, LV_PART_INDICATOR|LV_STATE_CHECKED);
	lv_obj_set_style_bg_color(ui->screen_settings_sw_enable_leds, lv_color_hex(0x00C92C), LV_PART_INDICATOR|LV_STATE_CHECKED);
	lv_obj_set_style_border_width(ui->screen_settings_sw_enable_leds, 0, LV_PART_INDICATOR|LV_STATE_CHECKED);

	//Write style for screen_settings_sw_enable_leds, Part: LV_PART_KNOB, State: LV_STATE_DEFAULT.
	lv_obj_set_style_bg_opa(ui->screen_settings_sw_enable_leds, 255, LV_PART_KNOB|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui->screen_settings_sw_enable_leds, lv_color_hex(0x292831), LV_PART_KNOB|LV_STATE_DEFAULT);
	lv_obj_set_style_border_width(ui->screen_settings_sw_enable_leds, 0, LV_PART_KNOB|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->screen_settings_sw_enable_leds, 13, LV_PART_KNOB|LV_STATE_DEFAULT);

	//Write codes screen_settings_label_enable_leds
	ui->screen_settings_label_enable_leds = lv_label_create(ui->screen_settings_cont_leds);
	lv_label_set_text(ui->screen_settings_label_enable_leds, "Enable");
	lv_label_set_long_mode(ui->screen_settings_label_enable_leds, LV_LABEL_LONG_WRAP);
	lv_obj_set_pos(ui->screen_settings_label_enable_leds, 10, 11);
	lv_obj_set_size(ui->screen_settings_label_enable_leds, 108, 14);

	//Write style for screen_settings_label_enable_leds, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->screen_settings_label_enable_leds, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->screen_settings_label_enable_leds, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->screen_settings_label_enable_leds, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->screen_settings_label_enable_leds, &lv_font_montserratMedium_16, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->screen_settings_label_enable_leds, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_line_space(ui->screen_settings_label_enable_leds, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->screen_settings_label_enable_leds, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->screen_settings_label_enable_leds, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->screen_settings_label_enable_leds, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->screen_settings_label_enable_leds, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->screen_settings_label_enable_leds, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->screen_settings_label_enable_leds, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->screen_settings_label_enable_leds, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes screen_settings_label_title_leds
	ui->screen_settings_label_title_leds = lv_label_create(ui->screen_settings_cont_settings);
	lv_label_set_text(ui->screen_settings_label_title_leds, "LEDs");
	lv_label_set_long_mode(ui->screen_settings_label_title_leds, LV_LABEL_LONG_WRAP);
	lv_obj_set_pos(ui->screen_settings_label_title_leds, 20, 75);
	lv_obj_set_size(ui->screen_settings_label_title_leds, 108, 15);

	//Write style for screen_settings_label_title_leds, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->screen_settings_label_title_leds, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->screen_settings_label_title_leds, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->screen_settings_label_title_leds, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->screen_settings_label_title_leds, &lv_font_montserratMedium_16, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->screen_settings_label_title_leds, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_line_space(ui->screen_settings_label_title_leds, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->screen_settings_label_title_leds, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->screen_settings_label_title_leds, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->screen_settings_label_title_leds, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->screen_settings_label_title_leds, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->screen_settings_label_title_leds, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->screen_settings_label_title_leds, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->screen_settings_label_title_leds, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes screen_settings_cont_buzzer
	ui->screen_settings_cont_buzzer = lv_obj_create(ui->screen_settings_cont_settings);
	lv_obj_set_pos(ui->screen_settings_cont_buzzer, 20, 27);
	lv_obj_set_size(ui->screen_settings_cont_buzzer, 180, 40);
	lv_obj_set_scrollbar_mode(ui->screen_settings_cont_buzzer, LV_SCROLLBAR_MODE_OFF);

	//Write style for screen_settings_cont_buzzer, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->screen_settings_cont_buzzer, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_opa(ui->screen_settings_cont_buzzer, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_color(ui->screen_settings_cont_buzzer, lv_color_hex(0x2195f6), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_side(ui->screen_settings_cont_buzzer, LV_BORDER_SIDE_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->screen_settings_cont_buzzer, 4, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->screen_settings_cont_buzzer, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui->screen_settings_cont_buzzer, lv_color_hex(0x292831), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->screen_settings_cont_buzzer, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->screen_settings_cont_buzzer, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->screen_settings_cont_buzzer, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->screen_settings_cont_buzzer, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->screen_settings_cont_buzzer, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes screen_settings_sw_enable_buzzer
	ui->screen_settings_sw_enable_buzzer = lv_switch_create(ui->screen_settings_cont_buzzer);
	lv_obj_set_pos(ui->screen_settings_sw_enable_buzzer, 117, 6);
	lv_obj_set_size(ui->screen_settings_sw_enable_buzzer, 50, 26);

	//Write style for screen_settings_sw_enable_buzzer, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_bg_opa(ui->screen_settings_sw_enable_buzzer, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui->screen_settings_sw_enable_buzzer, lv_color_hex(0x41485a), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_width(ui->screen_settings_sw_enable_buzzer, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->screen_settings_sw_enable_buzzer, 13, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->screen_settings_sw_enable_buzzer, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write style for screen_settings_sw_enable_buzzer, Part: LV_PART_INDICATOR, State: LV_STATE_CHECKED.
	lv_obj_set_style_bg_opa(ui->screen_settings_sw_enable_buzzer, 255, LV_PART_INDICATOR|LV_STATE_CHECKED);
	lv_obj_set_style_bg_color(ui->screen_settings_sw_enable_buzzer, lv_color_hex(0x00C92C), LV_PART_INDICATOR|LV_STATE_CHECKED);
	lv_obj_set_style_border_width(ui->screen_settings_sw_enable_buzzer, 0, LV_PART_INDICATOR|LV_STATE_CHECKED);

	//Write style for screen_settings_sw_enable_buzzer, Part: LV_PART_KNOB, State: LV_STATE_DEFAULT.
	lv_obj_set_style_bg_opa(ui->screen_settings_sw_enable_buzzer, 255, LV_PART_KNOB|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui->screen_settings_sw_enable_buzzer, lv_color_hex(0x292831), LV_PART_KNOB|LV_STATE_DEFAULT);
	lv_obj_set_style_border_width(ui->screen_settings_sw_enable_buzzer, 0, LV_PART_KNOB|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->screen_settings_sw_enable_buzzer, 13, LV_PART_KNOB|LV_STATE_DEFAULT);

	//Write codes screen_settings_label_enable_buzzer
	ui->screen_settings_label_enable_buzzer = lv_label_create(ui->screen_settings_cont_buzzer);
	lv_label_set_text(ui->screen_settings_label_enable_buzzer, "Enable");
	lv_label_set_long_mode(ui->screen_settings_label_enable_buzzer, LV_LABEL_LONG_WRAP);
	lv_obj_set_pos(ui->screen_settings_label_enable_buzzer, 10, 11);
	lv_obj_set_size(ui->screen_settings_label_enable_buzzer, 108, 13);

	//Write style for screen_settings_label_enable_buzzer, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->screen_settings_label_enable_buzzer, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->screen_settings_label_enable_buzzer, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->screen_settings_label_enable_buzzer, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->screen_settings_label_enable_buzzer, &lv_font_montserratMedium_16, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->screen_settings_label_enable_buzzer, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_line_space(ui->screen_settings_label_enable_buzzer, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->screen_settings_label_enable_buzzer, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->screen_settings_label_enable_buzzer, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->screen_settings_label_enable_buzzer, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->screen_settings_label_enable_buzzer, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->screen_settings_label_enable_buzzer, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->screen_settings_label_enable_buzzer, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->screen_settings_label_enable_buzzer, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes screen_settings_label_title_buzzer
	ui->screen_settings_label_title_buzzer = lv_label_create(ui->screen_settings_cont_settings);
	lv_label_set_text(ui->screen_settings_label_title_buzzer, "Buzzer");
	lv_label_set_long_mode(ui->screen_settings_label_title_buzzer, LV_LABEL_LONG_WRAP);
	lv_obj_set_pos(ui->screen_settings_label_title_buzzer, 20, 5);
	lv_obj_set_size(ui->screen_settings_label_title_buzzer, 108, 15);

	//Write style for screen_settings_label_title_buzzer, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->screen_settings_label_title_buzzer, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->screen_settings_label_title_buzzer, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->screen_settings_label_title_buzzer, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->screen_settings_label_title_buzzer, &lv_font_montserratMedium_16, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->screen_settings_label_title_buzzer, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_line_space(ui->screen_settings_label_title_buzzer, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->screen_settings_label_title_buzzer, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->screen_settings_label_title_buzzer, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->screen_settings_label_title_buzzer, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->screen_settings_label_title_buzzer, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->screen_settings_label_title_buzzer, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->screen_settings_label_title_buzzer, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->screen_settings_label_title_buzzer, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes screen_settings_cont_spacer
	ui->screen_settings_cont_spacer = lv_obj_create(ui->screen_settings_cont_settings);
	lv_obj_set_pos(ui->screen_settings_cont_spacer, 20, 255);
	lv_obj_set_size(ui->screen_settings_cont_spacer, 180, 35);
	lv_obj_set_scrollbar_mode(ui->screen_settings_cont_spacer, LV_SCROLLBAR_MODE_OFF);

	//Write style for screen_settings_cont_spacer, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->screen_settings_cont_spacer, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->screen_settings_cont_spacer, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->screen_settings_cont_spacer, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->screen_settings_cont_spacer, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->screen_settings_cont_spacer, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->screen_settings_cont_spacer, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->screen_settings_cont_spacer, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->screen_settings_cont_spacer, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes screen_settings_btn_back
	ui->screen_settings_btn_back = lv_btn_create(ui->screen_settings);
	ui->screen_settings_btn_back_label = lv_label_create(ui->screen_settings_btn_back);
	lv_label_set_text(ui->screen_settings_btn_back_label, "");
	lv_label_set_long_mode(ui->screen_settings_btn_back_label, LV_LABEL_LONG_WRAP);
	lv_obj_align(ui->screen_settings_btn_back_label, LV_ALIGN_LEFT_MID, 0, 0);
	lv_obj_set_style_pad_all(ui->screen_settings_btn_back, 0, LV_STATE_DEFAULT);
	lv_obj_set_pos(ui->screen_settings_btn_back, 0, 0);
	lv_obj_set_size(ui->screen_settings_btn_back, 240, 50);

	//Write style for screen_settings_btn_back, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_bg_opa(ui->screen_settings_btn_back, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui->screen_settings_btn_back, lv_color_hex(0x292831), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_width(ui->screen_settings_btn_back, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_opa(ui->screen_settings_btn_back, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_color(ui->screen_settings_btn_back, lv_color_hex(0xD200AC), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_side(ui->screen_settings_btn_back, LV_BORDER_SIDE_BOTTOM, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->screen_settings_btn_back, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->screen_settings_btn_back, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->screen_settings_btn_back, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->screen_settings_btn_back, &lv_font_FontAwesome5ProRegular_400_16, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->screen_settings_btn_back, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes screen_settings_label_back
	ui->screen_settings_label_back = lv_label_create(ui->screen_settings);
	lv_label_set_text(ui->screen_settings_label_back, "");
	lv_label_set_long_mode(ui->screen_settings_label_back, LV_LABEL_LONG_WRAP);
	lv_obj_set_pos(ui->screen_settings_label_back, 50, 25);
	lv_obj_set_size(ui->screen_settings_label_back, 23, 16);

	//Write style for screen_settings_label_back, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->screen_settings_label_back, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->screen_settings_label_back, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->screen_settings_label_back, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->screen_settings_label_back, &lv_font_FontAwesome5ProRegular_400_16, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->screen_settings_label_back, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_line_space(ui->screen_settings_label_back, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->screen_settings_label_back, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->screen_settings_label_back, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->screen_settings_label_back, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->screen_settings_label_back, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->screen_settings_label_back, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->screen_settings_label_back, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->screen_settings_label_back, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes screen_settings_label_title
	ui->screen_settings_label_title = lv_label_create(ui->screen_settings);
	lv_label_set_text(ui->screen_settings_label_title, "Settings");
	lv_label_set_long_mode(ui->screen_settings_label_title, LV_LABEL_LONG_WRAP);
	lv_obj_set_pos(ui->screen_settings_label_title, 60, 20);
	lv_obj_set_size(ui->screen_settings_label_title, 120, 18);

	//Write style for screen_settings_label_title, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->screen_settings_label_title, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->screen_settings_label_title, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->screen_settings_label_title, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->screen_settings_label_title, &lv_font_montserratMedium_16, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->screen_settings_label_title, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_line_space(ui->screen_settings_label_title, 1, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->screen_settings_label_title, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->screen_settings_label_title, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->screen_settings_label_title, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->screen_settings_label_title, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->screen_settings_label_title, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->screen_settings_label_title, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->screen_settings_label_title, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Update current screen layout.
	lv_obj_update_layout(ui->screen_settings);

	
	//Init events for screen.
	events_init_screen_settings(ui);
}
