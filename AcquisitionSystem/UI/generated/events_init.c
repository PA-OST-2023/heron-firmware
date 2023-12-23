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


#ifdef PLATFORMIO
#include "../../app.h"
#endif
#ifdef PLATFORMIO
#include "../../app.h"
#endif

static void screenBootup_event_handler (lv_event_t *e)
{
	lv_event_code_t code = lv_event_get_code(e);

	switch (code) {
	case LV_EVENT_SCREEN_LOADED:
	{
		//Write the load screen code.
	    lv_obj_t * act_scr = lv_scr_act();
	    lv_disp_t * d = lv_obj_get_disp(act_scr);
	    if (d->prev_scr == NULL && (d->scr_to_load == NULL || d->scr_to_load == act_scr)) {
	        if (guider_ui.screenRecording_del == true) {
	          setup_scr_screenRecording(&guider_ui);
	        }
	        lv_scr_load_anim(guider_ui.screenRecording, LV_SCR_LOAD_ANIM_FADE_ON, 200, 3500, true);
	        guider_ui.screenBootup_del = true;
	    }
		lv_obj_set_tile(guider_ui.screenRecording_tileview, guider_ui.screenRecording_tileview_tile_channels, LV_ANIM_OFF);
	
	lv_obj_set_style_transform_pivot_x(guider_ui.screenRecording_label_usb, 13, 0);
	lv_obj_set_style_transform_pivot_y(guider_ui.screenRecording_label_usb, 13, 0);
	lv_obj_set_style_transform_angle(guider_ui.screenRecording_label_usb, 2700, 0);
		break;
	}
	default:
		break;
	}
}
void events_init_screenBootup(lv_ui *ui)
{
	lv_obj_add_event_cb(ui->screenBootup, screenBootup_event_handler, LV_EVENT_ALL, NULL);
}
static void screenRecording_btn_current_time_event_handler (lv_event_t *e)
{
	lv_event_code_t code = lv_event_get_code(e);

	switch (code) {
	case LV_EVENT_RELEASED:
	{
		//Write the load screen code.
	    lv_obj_t * act_scr = lv_scr_act();
	    lv_disp_t * d = lv_obj_get_disp(act_scr);
	    if (d->prev_scr == NULL && (d->scr_to_load == NULL || d->scr_to_load == act_scr)) {
	        if (guider_ui.screenSetTime_del == true) {
	          setup_scr_screenSetTime(&guider_ui);
	        }
	        lv_scr_load_anim(guider_ui.screenSetTime, LV_SCR_LOAD_ANIM_NONE, 200, 200, false);
	        guider_ui.screenRecording_del = false;
	    }
		#ifdef PLATFORMIO
	App::callbackSetRollerTime();
	#endif
		break;
	}
	default:
		break;
	}
}
void events_init_screenRecording(lv_ui *ui)
{
	lv_obj_add_event_cb(ui->screenRecording_btn_current_time, screenRecording_btn_current_time_event_handler, LV_EVENT_ALL, NULL);
}
static void screenSetTime_btn_1_event_handler (lv_event_t *e)
{
	lv_event_code_t code = lv_event_get_code(e);

	switch (code) {
	case LV_EVENT_SHORT_CLICKED:
	{
		//Write the load screen code.
	    lv_obj_t * act_scr = lv_scr_act();
	    lv_disp_t * d = lv_obj_get_disp(act_scr);
	    if (d->prev_scr == NULL && (d->scr_to_load == NULL || d->scr_to_load == act_scr)) {
	        if (guider_ui.screenRecording_del == true) {
	          setup_scr_screenRecording(&guider_ui);
	        }
	        lv_scr_load_anim(guider_ui.screenRecording, LV_SCR_LOAD_ANIM_MOVE_RIGHT, 200, 200, false);
	        guider_ui.screenSetTime_del = false;
	    }
		lv_obj_set_tile(guider_ui.screenRecording_tileview, guider_ui.screenRecording_tileview_tile_channels, LV_ANIM_OFF);
	
	lv_obj_set_style_transform_pivot_x(guider_ui.screenRecording_label_usb, 13, 0);
	lv_obj_set_style_transform_pivot_y(guider_ui.screenRecording_label_usb, 13, 0);
	lv_obj_set_style_transform_angle(guider_ui.screenRecording_label_usb, 2700, 0);
		break;
	}
	default:
		break;
	}
}
static void screenSetTime_btnUpdateTime_event_handler (lv_event_t *e)
{
	lv_event_code_t code = lv_event_get_code(e);

	switch (code) {
	case LV_EVENT_CLICKED:
	{
		#ifdef PLATFORMIO
	App::callbackUpdateTime();
	#endif
	
	lv_obj_set_tile(guider_ui.screenRecording_tileview, guider_ui.screenRecording_tileview_tile_channels, LV_ANIM_OFF);
	
	lv_obj_set_style_transform_pivot_x(guider_ui.screenRecording_label_usb, 13, 0);
	lv_obj_set_style_transform_pivot_y(guider_ui.screenRecording_label_usb, 13, 0);
	lv_obj_set_style_transform_angle(guider_ui.screenRecording_label_usb, 2700, 0);
	
		//Write the load screen code.
	    lv_obj_t * act_scr = lv_scr_act();
	    lv_disp_t * d = lv_obj_get_disp(act_scr);
	    if (d->prev_scr == NULL && (d->scr_to_load == NULL || d->scr_to_load == act_scr)) {
	        if (guider_ui.screenRecording_del == true) {
	          setup_scr_screenRecording(&guider_ui);
	        }
	        lv_scr_load_anim(guider_ui.screenRecording, LV_SCR_LOAD_ANIM_MOVE_RIGHT, 200, 200, false);
	        guider_ui.screenSetTime_del = false;
	    }
		break;
	}
	default:
		break;
	}
}
void events_init_screenSetTime(lv_ui *ui)
{
	lv_obj_add_event_cb(ui->screenSetTime_btn_1, screenSetTime_btn_1_event_handler, LV_EVENT_ALL, NULL);
	lv_obj_add_event_cb(ui->screenSetTime_btnUpdateTime, screenSetTime_btnUpdateTime_event_handler, LV_EVENT_ALL, NULL);
}

void events_init(lv_ui *ui)
{

}
