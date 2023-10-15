/*
* Copyright 2023 NXP
* NXP Confidential and Proprietary. This software is owned or controlled by NXP and may only be used strictly in
* accordance with the applicable license terms. By expressly accepting such terms or by downloading, installing,
* activating and/or otherwise using the software, you are agreeing that you have read, and that you agree to
* comply with and are bound by, such license terms.  If you do not agree to be bound by the applicable license
* terms, then you may not retain, install, activate or otherwise use the software.
*/

#ifndef GUI_GUIDER_H
#define GUI_GUIDER_H
#ifdef __cplusplus
extern "C" {
#endif

#include "lvgl.h"

typedef struct
{
  
	lv_obj_t *screenBootup;
	bool screenBootup_del;
	lv_obj_t *screenBootup_label_1;
	lv_obj_t *screenRecording;
	bool screenRecording_del;
	lv_obj_t *screenRecording_cont_1;
	lv_obj_t *screenRecording_label_1;
	lv_obj_t *screenRecording_btnCurrentTime;
	lv_obj_t *screenRecording_btnCurrentTime_label;
	lv_obj_t *screenRecording_label_2;
	lv_obj_t *screenSetTime;
	bool screenSetTime_del;
	lv_obj_t *screenSetTime_cont_1;
	lv_obj_t *screenSetTime_label_4;
	lv_obj_t *screenSetTime_btnUpdateTime;
	lv_obj_t *screenSetTime_btnUpdateTime_label;
	lv_obj_t *screenSetTime_label_8;
	lv_obj_t *screenSetTime_label_7;
	lv_obj_t *screenSetTime_label_6;
	lv_obj_t *screenSetTime_label_5;
	lv_obj_t *screenSetTime_rollerSecond;
	lv_obj_t *screenSetTime_rollerMinute;
	lv_obj_t *screenSetTime_rollerHour;
	lv_obj_t *screenSetTime_rollerYear;
	lv_obj_t *screenSetTime_rollerMonth;
	lv_obj_t *screenSetTime_rollerDay;
}lv_ui;

void ui_init_style(lv_style_t * style);
void init_scr_del_flag(lv_ui *ui);
void setup_ui(lv_ui *ui);
extern lv_ui guider_ui;

void setup_scr_screenBootup(lv_ui *ui);
void setup_scr_screenRecording(lv_ui *ui);
void setup_scr_screenSetTime(lv_ui *ui);

LV_FONT_DECLARE(lv_font_montserratMedium_16)
LV_FONT_DECLARE(lv_font_FontAwesome5ProRegular_400_16)
LV_FONT_DECLARE(lv_font_montserratMedium_12)
LV_FONT_DECLARE(lv_font_FontAwesome5_16)


#ifdef __cplusplus
}
#endif
#endif
