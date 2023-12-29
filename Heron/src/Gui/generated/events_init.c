/*
* Copyright 2023 NXP
* NXP Confidential and Proprietary. This software is owned or controlled by NXP and may only be used strictly in
* accordance with the applicable license terms. By expressly accepting such terms or by downloading, installing,
* activating and/or otherwise using the software, you are agreeing that you have read, and that you agree to
* comply with and are bound by, such license terms.  If you do not agree to be bound by the applicable license
* terms, then you may not retain, install, activate or otherwise use the software.
*/

#include "events_init.h"
#include <stdio.h>
#include "lvgl.h"


static void screen_bootup_event_handler (lv_event_t *e)
{
	lv_event_code_t code = lv_event_get_code(e);

	switch (code) {
	case LV_EVENT_SCREEN_LOADED:
	{
		//Write the load screen code.
	    lv_obj_t * act_scr = lv_scr_act();
	    lv_disp_t * d = lv_obj_get_disp(act_scr);
	    if (d->prev_scr == NULL && (d->scr_to_load == NULL || d->scr_to_load == act_scr)) {
	        if (guider_ui.screen_home_del == true) {
	          setup_scr_screen_home(&guider_ui);
	        }
	        lv_scr_load_anim(guider_ui.screen_home, LV_SCR_LOAD_ANIM_FADE_ON, 200, 3500, true);
	        guider_ui.screen_bootup_del = true;
	    }
		lv_obj_set_style_transform_pivot_x(guider_ui.screen_home_label_usb_status, 8, 0);
	lv_obj_set_style_transform_pivot_y(guider_ui.screen_home_label_usb_status, 8, 0);
	lv_obj_set_style_transform_angle(guider_ui.screen_home_label_usb_status, 2700, 0);
		break;
	}
	default:
		break;
	}
}
void events_init_screen_bootup(lv_ui *ui)
{
	lv_obj_add_event_cb(ui->screen_bootup, screen_bootup_event_handler, LV_EVENT_ALL, NULL);
}
static void screen_home_btn_ethernet_event_handler (lv_event_t *e)
{
	lv_event_code_t code = lv_event_get_code(e);

	switch (code) {
	case LV_EVENT_CLICKED:
	{
		//Write the load screen code.
	    lv_obj_t * act_scr = lv_scr_act();
	    lv_disp_t * d = lv_obj_get_disp(act_scr);
	    if (d->prev_scr == NULL && (d->scr_to_load == NULL || d->scr_to_load == act_scr)) {
	        if (guider_ui.screen_ethernet_del == true) {
	          setup_scr_screen_ethernet(&guider_ui);
	        }
	        lv_scr_load_anim(guider_ui.screen_ethernet, LV_SCR_LOAD_ANIM_FADE_ON, 200, 0, false);
	        guider_ui.screen_home_del = false;
	    }
		break;
	}
	default:
		break;
	}
}
static void screen_home_btn_compass_event_handler (lv_event_t *e)
{
	lv_event_code_t code = lv_event_get_code(e);

	switch (code) {
	case LV_EVENT_CLICKED:
	{
		//Write the load screen code.
	    lv_obj_t * act_scr = lv_scr_act();
	    lv_disp_t * d = lv_obj_get_disp(act_scr);
	    if (d->prev_scr == NULL && (d->scr_to_load == NULL || d->scr_to_load == act_scr)) {
	        if (guider_ui.screen_compass_del == true) {
	          setup_scr_screen_compass(&guider_ui);
	        }
	        lv_scr_load_anim(guider_ui.screen_compass, LV_SCR_LOAD_ANIM_FADE_ON, 200, 0, false);
	        guider_ui.screen_home_del = false;
	    }
		break;
	}
	default:
		break;
	}
}
void events_init_screen_home(lv_ui *ui)
{
	lv_obj_add_event_cb(ui->screen_home_btn_ethernet, screen_home_btn_ethernet_event_handler, LV_EVENT_ALL, NULL);
	lv_obj_add_event_cb(ui->screen_home_btn_compass, screen_home_btn_compass_event_handler, LV_EVENT_ALL, NULL);
}
static void screen_ethernet_btn_setup_event_handler (lv_event_t *e)
{
	lv_event_code_t code = lv_event_get_code(e);

	switch (code) {
	case LV_EVENT_RELEASED:
	{
		//Write the load screen code.
	    lv_obj_t * act_scr = lv_scr_act();
	    lv_disp_t * d = lv_obj_get_disp(act_scr);
	    if (d->prev_scr == NULL && (d->scr_to_load == NULL || d->scr_to_load == act_scr)) {
	        if (guider_ui.screen_ethernet_setup_del == true) {
	          setup_scr_screen_ethernet_setup(&guider_ui);
	        }
	        lv_scr_load_anim(guider_ui.screen_ethernet_setup, LV_SCR_LOAD_ANIM_MOVE_LEFT, 200, 200, true);
	        guider_ui.screen_ethernet_del = true;
	    }
		break;
	}
	default:
		break;
	}
}
static void screen_ethernet_btn_back_event_handler (lv_event_t *e)
{
	lv_event_code_t code = lv_event_get_code(e);

	switch (code) {
	case LV_EVENT_RELEASED:
	{
		//Write the load screen code.
	    lv_obj_t * act_scr = lv_scr_act();
	    lv_disp_t * d = lv_obj_get_disp(act_scr);
	    if (d->prev_scr == NULL && (d->scr_to_load == NULL || d->scr_to_load == act_scr)) {
	        if (guider_ui.screen_home_del == true) {
	          setup_scr_screen_home(&guider_ui);
	        }
	        lv_scr_load_anim(guider_ui.screen_home, LV_SCR_LOAD_ANIM_FADE_ON, 200, 0, true);
	        guider_ui.screen_ethernet_del = true;
	    }
		break;
	}
	default:
		break;
	}
}
void events_init_screen_ethernet(lv_ui *ui)
{
	lv_obj_add_event_cb(ui->screen_ethernet_btn_setup, screen_ethernet_btn_setup_event_handler, LV_EVENT_ALL, NULL);
	lv_obj_add_event_cb(ui->screen_ethernet_btn_back, screen_ethernet_btn_back_event_handler, LV_EVENT_ALL, NULL);
}
static void screen_ethernet_setup_btn_confirm_event_handler (lv_event_t *e)
{
	lv_event_code_t code = lv_event_get_code(e);

	switch (code) {
	case LV_EVENT_RELEASED:
	{
		//Write the load screen code.
	    lv_obj_t * act_scr = lv_scr_act();
	    lv_disp_t * d = lv_obj_get_disp(act_scr);
	    if (d->prev_scr == NULL && (d->scr_to_load == NULL || d->scr_to_load == act_scr)) {
	        if (guider_ui.screen_ethernet_del == true) {
	          setup_scr_screen_ethernet(&guider_ui);
	        }
	        lv_scr_load_anim(guider_ui.screen_ethernet, LV_SCR_LOAD_ANIM_FADE_ON, 200, 2500, true);
	        guider_ui.screen_ethernet_setup_del = true;
	    }
		lv_obj_clear_flag(guider_ui.screen_ethernet_setup_cont_confirmed, LV_OBJ_FLAG_HIDDEN);
		lv_obj_clear_flag(guider_ui.screen_ethernet_setup_cont_confirmed_background, LV_OBJ_FLAG_HIDDEN);
		break;
	}
	default:
		break;
	}
}
static void screen_ethernet_setup_btn_back_event_handler (lv_event_t *e)
{
	lv_event_code_t code = lv_event_get_code(e);

	switch (code) {
	case LV_EVENT_RELEASED:
	{
		//Write the load screen code.
	    lv_obj_t * act_scr = lv_scr_act();
	    lv_disp_t * d = lv_obj_get_disp(act_scr);
	    if (d->prev_scr == NULL && (d->scr_to_load == NULL || d->scr_to_load == act_scr)) {
	        if (guider_ui.screen_ethernet_del == true) {
	          setup_scr_screen_ethernet(&guider_ui);
	        }
	        lv_scr_load_anim(guider_ui.screen_ethernet, LV_SCR_LOAD_ANIM_MOVE_RIGHT, 200, 200, true);
	        guider_ui.screen_ethernet_setup_del = true;
	    }
		break;
	}
	default:
		break;
	}
}
void events_init_screen_ethernet_setup(lv_ui *ui)
{
	lv_obj_add_event_cb(ui->screen_ethernet_setup_btn_confirm, screen_ethernet_setup_btn_confirm_event_handler, LV_EVENT_ALL, NULL);
	lv_obj_add_event_cb(ui->screen_ethernet_setup_btn_back, screen_ethernet_setup_btn_back_event_handler, LV_EVENT_ALL, NULL);
}
static void screen_compass_event_handler (lv_event_t *e)
{
	lv_event_code_t code = lv_event_get_code(e);

	switch (code) {
	case LV_EVENT_SCREEN_LOADED:
	{
		lv_obj_set_style_transform_pivot_x(guider_ui.screen_compass_label_needle, 8, 0);
	lv_obj_set_style_transform_pivot_y(guider_ui.screen_compass_label_needle, 49, 0);
	//lv_obj_set_style_transform_angle(guider_ui.screen_compass_label_needle, 1800, 0);
		break;
	}
	default:
		break;
	}
}
static void screen_compass_btn_back_event_handler (lv_event_t *e)
{
	lv_event_code_t code = lv_event_get_code(e);

	switch (code) {
	case LV_EVENT_RELEASED:
	{
		//Write the load screen code.
	    lv_obj_t * act_scr = lv_scr_act();
	    lv_disp_t * d = lv_obj_get_disp(act_scr);
	    if (d->prev_scr == NULL && (d->scr_to_load == NULL || d->scr_to_load == act_scr)) {
	        if (guider_ui.screen_home_del == true) {
	          setup_scr_screen_home(&guider_ui);
	        }
	        lv_scr_load_anim(guider_ui.screen_home, LV_SCR_LOAD_ANIM_FADE_ON, 200, 200, true);
	        guider_ui.screen_compass_del = true;
	    }
		break;
	}
	default:
		break;
	}
}
void events_init_screen_compass(lv_ui *ui)
{
	lv_obj_add_event_cb(ui->screen_compass, screen_compass_event_handler, LV_EVENT_ALL, NULL);
	lv_obj_add_event_cb(ui->screen_compass_btn_back, screen_compass_btn_back_event_handler, LV_EVENT_ALL, NULL);
}

void events_init(lv_ui *ui)
{

}
