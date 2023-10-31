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
	lv_obj_t *screenBootup_img_2;
	lv_obj_t *screenRecording;
	bool screenRecording_del;
	lv_obj_t *screenRecording_cont_top_bar;
	lv_obj_t *screenRecording_btn_warning;
	lv_obj_t *screenRecording_btn_warning_label;
	lv_obj_t *screenRecording_label_ethernet;
	lv_obj_t *screenRecording_label_headphones;
	lv_obj_t *screenRecording_btn_current_time;
	lv_obj_t *screenRecording_btn_current_time_label;
	lv_obj_t *screenRecording_bar_volume;
	lv_obj_t *screenRecording_label_volume;
	lv_obj_t *screenRecording_label_usb;
	lv_obj_t *screenRecording_label_sd_card;
	lv_obj_t *screenRecording_tileview;
	lv_obj_t *screenRecording_tileview_tile_files;
	lv_obj_t *screenRecording_tileview_tile_channels;
	lv_obj_t *screenRecording_cont_disk_storage;
	lv_obj_t *screenRecording_bar_disk_storage;
	lv_obj_t *screenRecording_label_121;
	lv_obj_t *screenRecording_label_disk_storage;
	lv_obj_t *screenRecording_list_1;
	lv_obj_t *screenRecording_list_1_item0;
	lv_obj_t *screenRecording_list_1_item1;
	lv_obj_t *screenRecording_list_1_item2;
	lv_obj_t *screenRecording_list_1_item3;
	lv_obj_t *screenRecording_list_1_item4;
	lv_obj_t *screenRecording_cont_10;
	lv_obj_t *screenRecording_cont_ch01;
	lv_obj_t *screenRecording_label_ch_01;
	lv_obj_t *screenRecording_label_spk_01;
	lv_obj_t *screenRecording_sw_01;
	lv_obj_t *screenRecording_label_13;
	lv_obj_t *screenRecording_cont_ch02;
	lv_obj_t *screenRecording_label_ch_02;
	lv_obj_t *screenRecording_label_spk_02;
	lv_obj_t *screenRecording_sw_02;
	lv_obj_t *screenRecording_label_28;
	lv_obj_t *screenRecording_cont_ch03;
	lv_obj_t *screenRecording_label_ch_03;
	lv_obj_t *screenRecording_label_spk_03;
	lv_obj_t *screenRecording_sw_03;
	lv_obj_t *screenRecording_label_31;
	lv_obj_t *screenRecording_cont_ch04;
	lv_obj_t *screenRecording_label_ch_04;
	lv_obj_t *screenRecording_label_spk_04;
	lv_obj_t *screenRecording_sw_04;
	lv_obj_t *screenRecording_label_34;
	lv_obj_t *screenRecording_cont_ch05;
	lv_obj_t *screenRecording_label_ch_05;
	lv_obj_t *screenRecording_label_spk_05;
	lv_obj_t *screenRecording_sw_05;
	lv_obj_t *screenRecording_label_37;
	lv_obj_t *screenRecording_cont_ch06;
	lv_obj_t *screenRecording_label_ch_06;
	lv_obj_t *screenRecording_label_spk_06;
	lv_obj_t *screenRecording_sw_06;
	lv_obj_t *screenRecording_label_40;
	lv_obj_t *screenRecording_cont_ch07;
	lv_obj_t *screenRecording_label_ch_07;
	lv_obj_t *screenRecording_label_spk_07;
	lv_obj_t *screenRecording_sw_07;
	lv_obj_t *screenRecording_label_43;
	lv_obj_t *screenRecording_cont_ch08;
	lv_obj_t *screenRecording_label_ch_08;
	lv_obj_t *screenRecording_label_spk_08;
	lv_obj_t *screenRecording_sw_08;
	lv_obj_t *screenRecording_label_46;
	lv_obj_t *screenRecording_cont_ch09;
	lv_obj_t *screenRecording_label_ch_09;
	lv_obj_t *screenRecording_label_spk_09;
	lv_obj_t *screenRecording_sw_09;
	lv_obj_t *screenRecording_label_49;
	lv_obj_t *screenRecording_cont_ch10;
	lv_obj_t *screenRecording_label_ch_10;
	lv_obj_t *screenRecording_label_spk_10;
	lv_obj_t *screenRecording_sw_10;
	lv_obj_t *screenRecording_label_52;
	lv_obj_t *screenRecording_cont_ch11;
	lv_obj_t *screenRecording_label_ch_11;
	lv_obj_t *screenRecording_label_spk_11;
	lv_obj_t *screenRecording_sw_11;
	lv_obj_t *screenRecording_label_55;
	lv_obj_t *screenRecording_cont_ch12;
	lv_obj_t *screenRecording_label_ch_12;
	lv_obj_t *screenRecording_label_spk_12;
	lv_obj_t *screenRecording_sw_12;
	lv_obj_t *screenRecording_label_58;
	lv_obj_t *screenRecording_cont_ch13;
	lv_obj_t *screenRecording_label_ch_13;
	lv_obj_t *screenRecording_label_spk_13;
	lv_obj_t *screenRecording_sw_13;
	lv_obj_t *screenRecording_label_61;
	lv_obj_t *screenRecording_cont_ch14;
	lv_obj_t *screenRecording_label_ch_14;
	lv_obj_t *screenRecording_label_spk_14;
	lv_obj_t *screenRecording_sw_14;
	lv_obj_t *screenRecording_label_64;
	lv_obj_t *screenRecording_cont_ch15;
	lv_obj_t *screenRecording_label_ch_15;
	lv_obj_t *screenRecording_label_spk_15;
	lv_obj_t *screenRecording_sw_15;
	lv_obj_t *screenRecording_label_67;
	lv_obj_t *screenRecording_cont_ch16;
	lv_obj_t *screenRecording_label_ch_16;
	lv_obj_t *screenRecording_label_spk_16;
	lv_obj_t *screenRecording_sw_16;
	lv_obj_t *screenRecording_label_70;
	lv_obj_t *screenRecording_cont_ch17;
	lv_obj_t *screenRecording_label_ch_17;
	lv_obj_t *screenRecording_label_spk_17;
	lv_obj_t *screenRecording_sw_17;
	lv_obj_t *screenRecording_label_73;
	lv_obj_t *screenRecording_cont_ch18;
	lv_obj_t *screenRecording_label_ch_18;
	lv_obj_t *screenRecording_label_spk_18;
	lv_obj_t *screenRecording_sw_18;
	lv_obj_t *screenRecording_label_76;
	lv_obj_t *screenRecording_cont_ch19;
	lv_obj_t *screenRecording_label_ch_19;
	lv_obj_t *screenRecording_label_spk_19;
	lv_obj_t *screenRecording_sw_19;
	lv_obj_t *screenRecording_label_79;
	lv_obj_t *screenRecording_cont_ch20;
	lv_obj_t *screenRecording_label_ch_20;
	lv_obj_t *screenRecording_label_spk_20;
	lv_obj_t *screenRecording_sw_20;
	lv_obj_t *screenRecording_label_82;
	lv_obj_t *screenRecording_cont_ch21;
	lv_obj_t *screenRecording_label_ch_21;
	lv_obj_t *screenRecording_label_spk_21;
	lv_obj_t *screenRecording_sw_21;
	lv_obj_t *screenRecording_label_85;
	lv_obj_t *screenRecording_cont_ch22;
	lv_obj_t *screenRecording_label_ch_22;
	lv_obj_t *screenRecording_label_spk_22;
	lv_obj_t *screenRecording_sw_22;
	lv_obj_t *screenRecording_label_88;
	lv_obj_t *screenRecording_cont_ch23;
	lv_obj_t *screenRecording_label_ch_23;
	lv_obj_t *screenRecording_label_spk_23;
	lv_obj_t *screenRecording_sw_23;
	lv_obj_t *screenRecording_label_91;
	lv_obj_t *screenRecording_cont_ch24;
	lv_obj_t *screenRecording_label_ch_24;
	lv_obj_t *screenRecording_label_spk_24;
	lv_obj_t *screenRecording_sw_24;
	lv_obj_t *screenRecording_label_94;
	lv_obj_t *screenRecording_cont_ch25;
	lv_obj_t *screenRecording_label_ch_25;
	lv_obj_t *screenRecording_label_spk_25;
	lv_obj_t *screenRecording_sw_25;
	lv_obj_t *screenRecording_label_97;
	lv_obj_t *screenRecording_cont_ch26;
	lv_obj_t *screenRecording_label_ch_26;
	lv_obj_t *screenRecording_label_spk_26;
	lv_obj_t *screenRecording_sw_26;
	lv_obj_t *screenRecording_label_100;
	lv_obj_t *screenRecording_cont_ch27;
	lv_obj_t *screenRecording_label_ch_27;
	lv_obj_t *screenRecording_label_spk_27;
	lv_obj_t *screenRecording_sw_27;
	lv_obj_t *screenRecording_label_103;
	lv_obj_t *screenRecording_cont_ch28;
	lv_obj_t *screenRecording_label_ch_28;
	lv_obj_t *screenRecording_label_spk_28;
	lv_obj_t *screenRecording_sw_28;
	lv_obj_t *screenRecording_label_106;
	lv_obj_t *screenRecording_cont_ch29;
	lv_obj_t *screenRecording_label_ch_29;
	lv_obj_t *screenRecording_label_spk_29;
	lv_obj_t *screenRecording_sw_29;
	lv_obj_t *screenRecording_label_109;
	lv_obj_t *screenRecording_cont_ch30;
	lv_obj_t *screenRecording_label_ch_30;
	lv_obj_t *screenRecording_label_spk_30;
	lv_obj_t *screenRecording_sw_30;
	lv_obj_t *screenRecording_label_112;
	lv_obj_t *screenRecording_cont_ch31;
	lv_obj_t *screenRecording_label_ch_31;
	lv_obj_t *screenRecording_label_spk_31;
	lv_obj_t *screenRecording_sw_31;
	lv_obj_t *screenRecording_label_115;
	lv_obj_t *screenRecording_cont_ch32;
	lv_obj_t *screenRecording_label_ch_32;
	lv_obj_t *screenRecording_label_spk_32;
	lv_obj_t *screenRecording_sw_32;
	lv_obj_t *screenRecording_label_118;
	lv_obj_t *screenRecording_cont_recording;
	lv_obj_t *screenRecording_label_recording_time;
	lv_obj_t *screenRecording_label_6;
	lv_obj_t *screenRecording_label_recording_remaining;
	lv_obj_t *screenSetTime;
	bool screenSetTime_del;
	lv_obj_t *screenSetTime_cont_2;
	lv_obj_t *screenSetTime_label_4;
	lv_obj_t *screenSetTime_btn_1;
	lv_obj_t *screenSetTime_btn_1_label;
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
LV_IMG_DECLARE(_Heron_alpha_100x100);

LV_FONT_DECLARE(lv_font_montserratMedium_16)
LV_FONT_DECLARE(lv_font_FontAwesome5ProSolid_900_16)
LV_FONT_DECLARE(lv_font_montserratMedium_12)
LV_FONT_DECLARE(lv_font_FontAwesome5ProRegular_400_16)
LV_FONT_DECLARE(lv_font_FontAwesome5_16)
LV_FONT_DECLARE(lv_font_montserratMedium_14)
LV_FONT_DECLARE(lv_font_montserratMedium_13)
LV_FONT_DECLARE(lv_font_FontAwesome5ProRegular_400_11)
LV_FONT_DECLARE(lv_font_MontserratRegular_20)
LV_FONT_DECLARE(lv_font_FontAwesome5ProRegular_400_22)
LV_FONT_DECLARE(lv_font_montserratMedium_24)
LV_FONT_DECLARE(lv_font_montserratMedium_35)


#ifdef __cplusplus
}
#endif
#endif
