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


void setup_scr_screen_ethernet_setup(lv_ui *ui)
{
	//Write codes screen_ethernet_setup
	ui->screen_ethernet_setup = lv_obj_create(NULL);
	lv_obj_set_size(ui->screen_ethernet_setup, 240, 240);

	//Write style for screen_ethernet_setup, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_bg_opa(ui->screen_ethernet_setup, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui->screen_ethernet_setup, lv_color_hex(0x101418), LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes screen_ethernet_setup_label_dot_2
	ui->screen_ethernet_setup_label_dot_2 = lv_label_create(ui->screen_ethernet_setup);
	lv_label_set_text(ui->screen_ethernet_setup_label_dot_2, ".");
	lv_label_set_long_mode(ui->screen_ethernet_setup_label_dot_2, LV_LABEL_LONG_WRAP);
	lv_obj_set_pos(ui->screen_ethernet_setup_label_dot_2, 169, 116);
	lv_obj_set_size(ui->screen_ethernet_setup_label_dot_2, 16, 16);

	//Write style for screen_ethernet_setup_label_dot_2, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->screen_ethernet_setup_label_dot_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->screen_ethernet_setup_label_dot_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->screen_ethernet_setup_label_dot_2, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->screen_ethernet_setup_label_dot_2, &lv_font_montserratMedium_14, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->screen_ethernet_setup_label_dot_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_line_space(ui->screen_ethernet_setup_label_dot_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->screen_ethernet_setup_label_dot_2, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->screen_ethernet_setup_label_dot_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->screen_ethernet_setup_label_dot_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->screen_ethernet_setup_label_dot_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->screen_ethernet_setup_label_dot_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->screen_ethernet_setup_label_dot_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->screen_ethernet_setup_label_dot_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes screen_ethernet_setup_label_dot_1
	ui->screen_ethernet_setup_label_dot_1 = lv_label_create(ui->screen_ethernet_setup);
	lv_label_set_text(ui->screen_ethernet_setup_label_dot_1, ".");
	lv_label_set_long_mode(ui->screen_ethernet_setup_label_dot_1, LV_LABEL_LONG_WRAP);
	lv_obj_set_pos(ui->screen_ethernet_setup_label_dot_1, 112, 116);
	lv_obj_set_size(ui->screen_ethernet_setup_label_dot_1, 16, 16);

	//Write style for screen_ethernet_setup_label_dot_1, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->screen_ethernet_setup_label_dot_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->screen_ethernet_setup_label_dot_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->screen_ethernet_setup_label_dot_1, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->screen_ethernet_setup_label_dot_1, &lv_font_montserratMedium_14, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->screen_ethernet_setup_label_dot_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_line_space(ui->screen_ethernet_setup_label_dot_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->screen_ethernet_setup_label_dot_1, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->screen_ethernet_setup_label_dot_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->screen_ethernet_setup_label_dot_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->screen_ethernet_setup_label_dot_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->screen_ethernet_setup_label_dot_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->screen_ethernet_setup_label_dot_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->screen_ethernet_setup_label_dot_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes screen_ethernet_setup_label_dot_0
	ui->screen_ethernet_setup_label_dot_0 = lv_label_create(ui->screen_ethernet_setup);
	lv_label_set_text(ui->screen_ethernet_setup_label_dot_0, ".");
	lv_label_set_long_mode(ui->screen_ethernet_setup_label_dot_0, LV_LABEL_LONG_WRAP);
	lv_obj_set_pos(ui->screen_ethernet_setup_label_dot_0, 55, 116);
	lv_obj_set_size(ui->screen_ethernet_setup_label_dot_0, 16, 16);

	//Write style for screen_ethernet_setup_label_dot_0, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->screen_ethernet_setup_label_dot_0, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->screen_ethernet_setup_label_dot_0, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->screen_ethernet_setup_label_dot_0, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->screen_ethernet_setup_label_dot_0, &lv_font_montserratMedium_14, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->screen_ethernet_setup_label_dot_0, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_line_space(ui->screen_ethernet_setup_label_dot_0, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->screen_ethernet_setup_label_dot_0, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->screen_ethernet_setup_label_dot_0, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->screen_ethernet_setup_label_dot_0, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->screen_ethernet_setup_label_dot_0, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->screen_ethernet_setup_label_dot_0, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->screen_ethernet_setup_label_dot_0, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->screen_ethernet_setup_label_dot_0, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes screen_ethernet_setup_btn_confirm
	ui->screen_ethernet_setup_btn_confirm = lv_btn_create(ui->screen_ethernet_setup);
	ui->screen_ethernet_setup_btn_confirm_label = lv_label_create(ui->screen_ethernet_setup_btn_confirm);
	lv_label_set_text(ui->screen_ethernet_setup_btn_confirm_label, "");
	lv_label_set_long_mode(ui->screen_ethernet_setup_btn_confirm_label, LV_LABEL_LONG_WRAP);
	lv_obj_align(ui->screen_ethernet_setup_btn_confirm_label, LV_ALIGN_LEFT_MID, 0, 0);
	lv_obj_set_style_pad_all(ui->screen_ethernet_setup_btn_confirm, 0, LV_STATE_DEFAULT);
	lv_obj_set_pos(ui->screen_ethernet_setup_btn_confirm, 0, 200);
	lv_obj_set_size(ui->screen_ethernet_setup_btn_confirm, 240, 40);

	//Write style for screen_ethernet_setup_btn_confirm, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_bg_opa(ui->screen_ethernet_setup_btn_confirm, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui->screen_ethernet_setup_btn_confirm, lv_color_hex(0x292831), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_width(ui->screen_ethernet_setup_btn_confirm, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_opa(ui->screen_ethernet_setup_btn_confirm, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_color(ui->screen_ethernet_setup_btn_confirm, lv_color_hex(0x00c92c), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_side(ui->screen_ethernet_setup_btn_confirm, LV_BORDER_SIDE_TOP, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->screen_ethernet_setup_btn_confirm, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->screen_ethernet_setup_btn_confirm, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->screen_ethernet_setup_btn_confirm, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->screen_ethernet_setup_btn_confirm, &lv_font_FontAwesome5ProRegular_400_16, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->screen_ethernet_setup_btn_confirm, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes screen_ethernet_setup_label_confirm
	ui->screen_ethernet_setup_label_confirm = lv_label_create(ui->screen_ethernet_setup);
	lv_label_set_text(ui->screen_ethernet_setup_label_confirm, "Confirm");
	lv_label_set_long_mode(ui->screen_ethernet_setup_label_confirm, LV_LABEL_LONG_WRAP);
	lv_obj_set_pos(ui->screen_ethernet_setup_label_confirm, 60, 210);
	lv_obj_set_size(ui->screen_ethernet_setup_label_confirm, 120, 18);

	//Write style for screen_ethernet_setup_label_confirm, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->screen_ethernet_setup_label_confirm, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->screen_ethernet_setup_label_confirm, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->screen_ethernet_setup_label_confirm, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->screen_ethernet_setup_label_confirm, &lv_font_montserratMedium_16, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->screen_ethernet_setup_label_confirm, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_line_space(ui->screen_ethernet_setup_label_confirm, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->screen_ethernet_setup_label_confirm, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->screen_ethernet_setup_label_confirm, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->screen_ethernet_setup_label_confirm, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->screen_ethernet_setup_label_confirm, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->screen_ethernet_setup_label_confirm, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->screen_ethernet_setup_label_confirm, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->screen_ethernet_setup_label_confirm, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes screen_ethernet_setup_btn_back
	ui->screen_ethernet_setup_btn_back = lv_btn_create(ui->screen_ethernet_setup);
	ui->screen_ethernet_setup_btn_back_label = lv_label_create(ui->screen_ethernet_setup_btn_back);
	lv_label_set_text(ui->screen_ethernet_setup_btn_back_label, "");
	lv_label_set_long_mode(ui->screen_ethernet_setup_btn_back_label, LV_LABEL_LONG_WRAP);
	lv_obj_align(ui->screen_ethernet_setup_btn_back_label, LV_ALIGN_LEFT_MID, 0, 0);
	lv_obj_set_style_pad_all(ui->screen_ethernet_setup_btn_back, 0, LV_STATE_DEFAULT);
	lv_obj_set_pos(ui->screen_ethernet_setup_btn_back, 0, 0);
	lv_obj_set_size(ui->screen_ethernet_setup_btn_back, 240, 50);

	//Write style for screen_ethernet_setup_btn_back, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_bg_opa(ui->screen_ethernet_setup_btn_back, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui->screen_ethernet_setup_btn_back, lv_color_hex(0x292831), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_width(ui->screen_ethernet_setup_btn_back, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_opa(ui->screen_ethernet_setup_btn_back, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_color(ui->screen_ethernet_setup_btn_back, lv_color_hex(0xD200AC), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_side(ui->screen_ethernet_setup_btn_back, LV_BORDER_SIDE_BOTTOM, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->screen_ethernet_setup_btn_back, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->screen_ethernet_setup_btn_back, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->screen_ethernet_setup_btn_back, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->screen_ethernet_setup_btn_back, &lv_font_FontAwesome5ProRegular_400_16, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->screen_ethernet_setup_btn_back, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes screen_ethernet_setup_label_back
	ui->screen_ethernet_setup_label_back = lv_label_create(ui->screen_ethernet_setup);
	lv_label_set_text(ui->screen_ethernet_setup_label_back, "");
	lv_label_set_long_mode(ui->screen_ethernet_setup_label_back, LV_LABEL_LONG_WRAP);
	lv_obj_set_pos(ui->screen_ethernet_setup_label_back, 50, 25);
	lv_obj_set_size(ui->screen_ethernet_setup_label_back, 23, 16);

	//Write style for screen_ethernet_setup_label_back, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->screen_ethernet_setup_label_back, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->screen_ethernet_setup_label_back, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->screen_ethernet_setup_label_back, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->screen_ethernet_setup_label_back, &lv_font_FontAwesome5ProRegular_400_16, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->screen_ethernet_setup_label_back, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_line_space(ui->screen_ethernet_setup_label_back, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->screen_ethernet_setup_label_back, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->screen_ethernet_setup_label_back, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->screen_ethernet_setup_label_back, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->screen_ethernet_setup_label_back, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->screen_ethernet_setup_label_back, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->screen_ethernet_setup_label_back, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->screen_ethernet_setup_label_back, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes screen_ethernet_setup_label_title
	ui->screen_ethernet_setup_label_title = lv_label_create(ui->screen_ethernet_setup);
	lv_label_set_text(ui->screen_ethernet_setup_label_title, "Setup");
	lv_label_set_long_mode(ui->screen_ethernet_setup_label_title, LV_LABEL_LONG_WRAP);
	lv_obj_set_pos(ui->screen_ethernet_setup_label_title, 60, 20);
	lv_obj_set_size(ui->screen_ethernet_setup_label_title, 120, 18);

	//Write style for screen_ethernet_setup_label_title, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->screen_ethernet_setup_label_title, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->screen_ethernet_setup_label_title, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->screen_ethernet_setup_label_title, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->screen_ethernet_setup_label_title, &lv_font_montserratMedium_16, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->screen_ethernet_setup_label_title, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_line_space(ui->screen_ethernet_setup_label_title, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->screen_ethernet_setup_label_title, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->screen_ethernet_setup_label_title, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->screen_ethernet_setup_label_title, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->screen_ethernet_setup_label_title, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->screen_ethernet_setup_label_title, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->screen_ethernet_setup_label_title, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->screen_ethernet_setup_label_title, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes screen_ethernet_setup_roller_ip_3
	ui->screen_ethernet_setup_roller_ip_3 = lv_roller_create(ui->screen_ethernet_setup);
	lv_roller_set_options(ui->screen_ethernet_setup_roller_ip_3, "0\n1\n2\n3\n4\n5\n6\n7\n8\n9\n10\n11\n12\n13\n14\n15\n16\n17\n18\n19\n20\n21\n22\n23\n24\n25\n26\n27\n28\n29\n30\n31\n32\n33\n34\n35\n36\n37\n38\n39\n40\n41\n42\n43\n44\n45\n46\n47\n48\n49\n50\n51\n52\n53\n54\n55\n56\n57\n58\n59\n60\n61\n62\n63\n64\n65\n66\n67\n68\n69\n70\n71\n72\n73\n74\n75\n76\n77\n78\n79\n80\n81\n82\n83\n84\n85\n86\n87\n88\n89\n90\n91\n92\n93\n94\n95\n96\n97\n98\n99\n100\n101\n102\n103\n104\n105\n106\n107\n108\n109\n110\n111\n112\n113\n114\n115\n116\n117\n118\n119\n120\n121\n122\n123\n124\n125\n126\n127\n128\n129\n130\n131\n132\n133\n134\n135\n136\n137\n138\n139\n140\n141\n142\n143\n144\n145\n146\n147\n148\n149\n150\n151\n152\n153\n154\n155\n156\n157\n158\n159\n160\n161\n162\n163\n164\n165\n166\n167\n168\n169\n170\n171\n172\n173\n174\n175\n176\n177\n178\n179\n180\n181\n182\n183\n184\n185\n186\n187\n188\n189\n190\n191\n192\n193\n194\n195\n196\n197\n198\n199\n200\n201\n202\n203\n204\n205\n206\n207\n208\n209\n210\n211\n212\n213\n214\n215\n216\n217\n218\n219\n220\n221\n222\n223\n224\n225\n226\n227\n228\n229\n230\n231\n232\n233\n234\n235\n236\n237\n238\n239\n240\n241\n242\n243\n244\n245\n246\n247\n248\n249\n250\n251\n252\n253\n254\n255", LV_ROLLER_MODE_NORMAL);
	lv_roller_set_visible_row_count(ui->screen_ethernet_setup_roller_ip_3, 2);
	lv_obj_set_pos(ui->screen_ethernet_setup_roller_ip_3, 181, 86);
	lv_obj_set_width(ui->screen_ethernet_setup_roller_ip_3, 49);

	//Write style for screen_ethernet_setup_roller_ip_3, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_radius(ui->screen_ethernet_setup_roller_ip_3, 5, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->screen_ethernet_setup_roller_ip_3, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui->screen_ethernet_setup_roller_ip_3, lv_color_hex(0x292831), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->screen_ethernet_setup_roller_ip_3, lv_color_hex(0x333333), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->screen_ethernet_setup_roller_ip_3, &lv_font_montserratMedium_16, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->screen_ethernet_setup_roller_ip_3, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_width(ui->screen_ethernet_setup_roller_ip_3, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_opa(ui->screen_ethernet_setup_roller_ip_3, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_color(ui->screen_ethernet_setup_roller_ip_3, lv_color_hex(0x293031), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_side(ui->screen_ethernet_setup_roller_ip_3, LV_BORDER_SIDE_FULL, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->screen_ethernet_setup_roller_ip_3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write style for screen_ethernet_setup_roller_ip_3, Part: LV_PART_SELECTED, State: LV_STATE_DEFAULT.
	lv_obj_set_style_bg_opa(ui->screen_ethernet_setup_roller_ip_3, 0, LV_PART_SELECTED|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->screen_ethernet_setup_roller_ip_3, lv_color_hex(0xFFFFFF), LV_PART_SELECTED|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->screen_ethernet_setup_roller_ip_3, &lv_font_montserratMedium_16, LV_PART_SELECTED|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->screen_ethernet_setup_roller_ip_3, LV_TEXT_ALIGN_CENTER, LV_PART_SELECTED|LV_STATE_DEFAULT);

	//Write codes screen_ethernet_setup_roller_ip_2
	ui->screen_ethernet_setup_roller_ip_2 = lv_roller_create(ui->screen_ethernet_setup);
	lv_roller_set_options(ui->screen_ethernet_setup_roller_ip_2, "0\n1\n2\n3\n4\n5\n6\n7\n8\n9\n10\n11\n12\n13\n14\n15\n16\n17\n18\n19\n20\n21\n22\n23\n24\n25\n26\n27\n28\n29\n30\n31\n32\n33\n34\n35\n36\n37\n38\n39\n40\n41\n42\n43\n44\n45\n46\n47\n48\n49\n50\n51\n52\n53\n54\n55\n56\n57\n58\n59\n60\n61\n62\n63\n64\n65\n66\n67\n68\n69\n70\n71\n72\n73\n74\n75\n76\n77\n78\n79\n80\n81\n82\n83\n84\n85\n86\n87\n88\n89\n90\n91\n92\n93\n94\n95\n96\n97\n98\n99\n100\n101\n102\n103\n104\n105\n106\n107\n108\n109\n110\n111\n112\n113\n114\n115\n116\n117\n118\n119\n120\n121\n122\n123\n124\n125\n126\n127\n128\n129\n130\n131\n132\n133\n134\n135\n136\n137\n138\n139\n140\n141\n142\n143\n144\n145\n146\n147\n148\n149\n150\n151\n152\n153\n154\n155\n156\n157\n158\n159\n160\n161\n162\n163\n164\n165\n166\n167\n168\n169\n170\n171\n172\n173\n174\n175\n176\n177\n178\n179\n180\n181\n182\n183\n184\n185\n186\n187\n188\n189\n190\n191\n192\n193\n194\n195\n196\n197\n198\n199\n200\n201\n202\n203\n204\n205\n206\n207\n208\n209\n210\n211\n212\n213\n214\n215\n216\n217\n218\n219\n220\n221\n222\n223\n224\n225\n226\n227\n228\n229\n230\n231\n232\n233\n234\n235\n236\n237\n238\n239\n240\n241\n242\n243\n244\n245\n246\n247\n248\n249\n250\n251\n252\n253\n254\n255", LV_ROLLER_MODE_NORMAL);
	lv_roller_set_visible_row_count(ui->screen_ethernet_setup_roller_ip_2, 2);
	lv_obj_set_pos(ui->screen_ethernet_setup_roller_ip_2, 124, 86);
	lv_obj_set_width(ui->screen_ethernet_setup_roller_ip_2, 49);

	//Write style for screen_ethernet_setup_roller_ip_2, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_radius(ui->screen_ethernet_setup_roller_ip_2, 5, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->screen_ethernet_setup_roller_ip_2, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui->screen_ethernet_setup_roller_ip_2, lv_color_hex(0x292831), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->screen_ethernet_setup_roller_ip_2, lv_color_hex(0x333333), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->screen_ethernet_setup_roller_ip_2, &lv_font_montserratMedium_16, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->screen_ethernet_setup_roller_ip_2, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_width(ui->screen_ethernet_setup_roller_ip_2, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_opa(ui->screen_ethernet_setup_roller_ip_2, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_color(ui->screen_ethernet_setup_roller_ip_2, lv_color_hex(0x293031), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_side(ui->screen_ethernet_setup_roller_ip_2, LV_BORDER_SIDE_FULL, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->screen_ethernet_setup_roller_ip_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write style for screen_ethernet_setup_roller_ip_2, Part: LV_PART_SELECTED, State: LV_STATE_DEFAULT.
	lv_obj_set_style_bg_opa(ui->screen_ethernet_setup_roller_ip_2, 0, LV_PART_SELECTED|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->screen_ethernet_setup_roller_ip_2, lv_color_hex(0xFFFFFF), LV_PART_SELECTED|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->screen_ethernet_setup_roller_ip_2, &lv_font_montserratMedium_16, LV_PART_SELECTED|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->screen_ethernet_setup_roller_ip_2, LV_TEXT_ALIGN_CENTER, LV_PART_SELECTED|LV_STATE_DEFAULT);

	//Write codes screen_ethernet_setup_roller_ip_1
	ui->screen_ethernet_setup_roller_ip_1 = lv_roller_create(ui->screen_ethernet_setup);
	lv_roller_set_options(ui->screen_ethernet_setup_roller_ip_1, "0\n1\n2\n3\n4\n5\n6\n7\n8\n9\n10\n11\n12\n13\n14\n15\n16\n17\n18\n19\n20\n21\n22\n23\n24\n25\n26\n27\n28\n29\n30\n31\n32\n33\n34\n35\n36\n37\n38\n39\n40\n41\n42\n43\n44\n45\n46\n47\n48\n49\n50\n51\n52\n53\n54\n55\n56\n57\n58\n59\n60\n61\n62\n63\n64\n65\n66\n67\n68\n69\n70\n71\n72\n73\n74\n75\n76\n77\n78\n79\n80\n81\n82\n83\n84\n85\n86\n87\n88\n89\n90\n91\n92\n93\n94\n95\n96\n97\n98\n99\n100\n101\n102\n103\n104\n105\n106\n107\n108\n109\n110\n111\n112\n113\n114\n115\n116\n117\n118\n119\n120\n121\n122\n123\n124\n125\n126\n127\n128\n129\n130\n131\n132\n133\n134\n135\n136\n137\n138\n139\n140\n141\n142\n143\n144\n145\n146\n147\n148\n149\n150\n151\n152\n153\n154\n155\n156\n157\n158\n159\n160\n161\n162\n163\n164\n165\n166\n167\n168\n169\n170\n171\n172\n173\n174\n175\n176\n177\n178\n179\n180\n181\n182\n183\n184\n185\n186\n187\n188\n189\n190\n191\n192\n193\n194\n195\n196\n197\n198\n199\n200\n201\n202\n203\n204\n205\n206\n207\n208\n209\n210\n211\n212\n213\n214\n215\n216\n217\n218\n219\n220\n221\n222\n223\n224\n225\n226\n227\n228\n229\n230\n231\n232\n233\n234\n235\n236\n237\n238\n239\n240\n241\n242\n243\n244\n245\n246\n247\n248\n249\n250\n251\n252\n253\n254\n255", LV_ROLLER_MODE_NORMAL);
	lv_roller_set_visible_row_count(ui->screen_ethernet_setup_roller_ip_1, 2);
	lv_obj_set_pos(ui->screen_ethernet_setup_roller_ip_1, 67, 86);
	lv_obj_set_width(ui->screen_ethernet_setup_roller_ip_1, 49);

	//Write style for screen_ethernet_setup_roller_ip_1, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_radius(ui->screen_ethernet_setup_roller_ip_1, 5, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->screen_ethernet_setup_roller_ip_1, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui->screen_ethernet_setup_roller_ip_1, lv_color_hex(0x292831), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->screen_ethernet_setup_roller_ip_1, lv_color_hex(0x333333), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->screen_ethernet_setup_roller_ip_1, &lv_font_montserratMedium_16, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->screen_ethernet_setup_roller_ip_1, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_width(ui->screen_ethernet_setup_roller_ip_1, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_opa(ui->screen_ethernet_setup_roller_ip_1, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_color(ui->screen_ethernet_setup_roller_ip_1, lv_color_hex(0x293031), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_side(ui->screen_ethernet_setup_roller_ip_1, LV_BORDER_SIDE_FULL, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->screen_ethernet_setup_roller_ip_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write style for screen_ethernet_setup_roller_ip_1, Part: LV_PART_SELECTED, State: LV_STATE_DEFAULT.
	lv_obj_set_style_bg_opa(ui->screen_ethernet_setup_roller_ip_1, 0, LV_PART_SELECTED|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->screen_ethernet_setup_roller_ip_1, lv_color_hex(0xFFFFFF), LV_PART_SELECTED|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->screen_ethernet_setup_roller_ip_1, &lv_font_montserratMedium_16, LV_PART_SELECTED|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->screen_ethernet_setup_roller_ip_1, LV_TEXT_ALIGN_CENTER, LV_PART_SELECTED|LV_STATE_DEFAULT);

	//Write codes screen_ethernet_setup_roller_ip_0
	ui->screen_ethernet_setup_roller_ip_0 = lv_roller_create(ui->screen_ethernet_setup);
	lv_roller_set_options(ui->screen_ethernet_setup_roller_ip_0, "0\n1\n2\n3\n4\n5\n6\n7\n8\n9\n10\n11\n12\n13\n14\n15\n16\n17\n18\n19\n20\n21\n22\n23\n24\n25\n26\n27\n28\n29\n30\n31\n32\n33\n34\n35\n36\n37\n38\n39\n40\n41\n42\n43\n44\n45\n46\n47\n48\n49\n50\n51\n52\n53\n54\n55\n56\n57\n58\n59\n60\n61\n62\n63\n64\n65\n66\n67\n68\n69\n70\n71\n72\n73\n74\n75\n76\n77\n78\n79\n80\n81\n82\n83\n84\n85\n86\n87\n88\n89\n90\n91\n92\n93\n94\n95\n96\n97\n98\n99\n100\n101\n102\n103\n104\n105\n106\n107\n108\n109\n110\n111\n112\n113\n114\n115\n116\n117\n118\n119\n120\n121\n122\n123\n124\n125\n126\n127\n128\n129\n130\n131\n132\n133\n134\n135\n136\n137\n138\n139\n140\n141\n142\n143\n144\n145\n146\n147\n148\n149\n150\n151\n152\n153\n154\n155\n156\n157\n158\n159\n160\n161\n162\n163\n164\n165\n166\n167\n168\n169\n170\n171\n172\n173\n174\n175\n176\n177\n178\n179\n180\n181\n182\n183\n184\n185\n186\n187\n188\n189\n190\n191\n192\n193\n194\n195\n196\n197\n198\n199\n200\n201\n202\n203\n204\n205\n206\n207\n208\n209\n210\n211\n212\n213\n214\n215\n216\n217\n218\n219\n220\n221\n222\n223\n224\n225\n226\n227\n228\n229\n230\n231\n232\n233\n234\n235\n236\n237\n238\n239\n240\n241\n242\n243\n244\n245\n246\n247\n248\n249\n250\n251\n252\n253\n254\n255", LV_ROLLER_MODE_NORMAL);
	lv_roller_set_visible_row_count(ui->screen_ethernet_setup_roller_ip_0, 2);
	lv_obj_set_pos(ui->screen_ethernet_setup_roller_ip_0, 10, 86);
	lv_obj_set_width(ui->screen_ethernet_setup_roller_ip_0, 49);

	//Write style for screen_ethernet_setup_roller_ip_0, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_radius(ui->screen_ethernet_setup_roller_ip_0, 5, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->screen_ethernet_setup_roller_ip_0, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui->screen_ethernet_setup_roller_ip_0, lv_color_hex(0x292831), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->screen_ethernet_setup_roller_ip_0, lv_color_hex(0x333333), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->screen_ethernet_setup_roller_ip_0, &lv_font_montserratMedium_16, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->screen_ethernet_setup_roller_ip_0, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_width(ui->screen_ethernet_setup_roller_ip_0, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_opa(ui->screen_ethernet_setup_roller_ip_0, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_color(ui->screen_ethernet_setup_roller_ip_0, lv_color_hex(0x293031), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_side(ui->screen_ethernet_setup_roller_ip_0, LV_BORDER_SIDE_FULL, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->screen_ethernet_setup_roller_ip_0, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write style for screen_ethernet_setup_roller_ip_0, Part: LV_PART_SELECTED, State: LV_STATE_DEFAULT.
	lv_obj_set_style_bg_opa(ui->screen_ethernet_setup_roller_ip_0, 0, LV_PART_SELECTED|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->screen_ethernet_setup_roller_ip_0, lv_color_hex(0xFFFFFF), LV_PART_SELECTED|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->screen_ethernet_setup_roller_ip_0, &lv_font_montserratMedium_16, LV_PART_SELECTED|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->screen_ethernet_setup_roller_ip_0, LV_TEXT_ALIGN_CENTER, LV_PART_SELECTED|LV_STATE_DEFAULT);

	//Write codes screen_ethernet_setup_label_ip_address
	ui->screen_ethernet_setup_label_ip_address = lv_label_create(ui->screen_ethernet_setup);
	lv_label_set_text(ui->screen_ethernet_setup_label_ip_address, "IP Address");
	lv_label_set_long_mode(ui->screen_ethernet_setup_label_ip_address, LV_LABEL_LONG_WRAP);
	lv_obj_set_pos(ui->screen_ethernet_setup_label_ip_address, 78, 63);
	lv_obj_set_size(ui->screen_ethernet_setup_label_ip_address, 85, 15);

	//Write style for screen_ethernet_setup_label_ip_address, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->screen_ethernet_setup_label_ip_address, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->screen_ethernet_setup_label_ip_address, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->screen_ethernet_setup_label_ip_address, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->screen_ethernet_setup_label_ip_address, &lv_font_montserratMedium_14, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->screen_ethernet_setup_label_ip_address, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_line_space(ui->screen_ethernet_setup_label_ip_address, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->screen_ethernet_setup_label_ip_address, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->screen_ethernet_setup_label_ip_address, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->screen_ethernet_setup_label_ip_address, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->screen_ethernet_setup_label_ip_address, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->screen_ethernet_setup_label_ip_address, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->screen_ethernet_setup_label_ip_address, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->screen_ethernet_setup_label_ip_address, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes screen_ethernet_setup_label_configuration_port
	ui->screen_ethernet_setup_label_configuration_port = lv_label_create(ui->screen_ethernet_setup);
	lv_label_set_text(ui->screen_ethernet_setup_label_configuration_port, "Configuration Port: 6667");
	lv_label_set_long_mode(ui->screen_ethernet_setup_label_configuration_port, LV_LABEL_LONG_WRAP);
	lv_obj_set_pos(ui->screen_ethernet_setup_label_configuration_port, 30, 178);
	lv_obj_set_size(ui->screen_ethernet_setup_label_configuration_port, 180, 14);

	//Write style for screen_ethernet_setup_label_configuration_port, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->screen_ethernet_setup_label_configuration_port, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->screen_ethernet_setup_label_configuration_port, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->screen_ethernet_setup_label_configuration_port, lv_color_hex(0x8a8a8a), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->screen_ethernet_setup_label_configuration_port, &lv_font_montserratMedium_12, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->screen_ethernet_setup_label_configuration_port, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_line_space(ui->screen_ethernet_setup_label_configuration_port, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->screen_ethernet_setup_label_configuration_port, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->screen_ethernet_setup_label_configuration_port, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->screen_ethernet_setup_label_configuration_port, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->screen_ethernet_setup_label_configuration_port, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->screen_ethernet_setup_label_configuration_port, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->screen_ethernet_setup_label_configuration_port, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->screen_ethernet_setup_label_configuration_port, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes screen_ethernet_setup_label_streaming_port
	ui->screen_ethernet_setup_label_streaming_port = lv_label_create(ui->screen_ethernet_setup);
	lv_label_set_text(ui->screen_ethernet_setup_label_streaming_port, "Streaming Port: 6666");
	lv_label_set_long_mode(ui->screen_ethernet_setup_label_streaming_port, LV_LABEL_LONG_WRAP);
	lv_obj_set_pos(ui->screen_ethernet_setup_label_streaming_port, 47, 163);
	lv_obj_set_size(ui->screen_ethernet_setup_label_streaming_port, 146, 14);

	//Write style for screen_ethernet_setup_label_streaming_port, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->screen_ethernet_setup_label_streaming_port, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->screen_ethernet_setup_label_streaming_port, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->screen_ethernet_setup_label_streaming_port, lv_color_hex(0x8a8a8a), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->screen_ethernet_setup_label_streaming_port, &lv_font_montserratMedium_12, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->screen_ethernet_setup_label_streaming_port, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_line_space(ui->screen_ethernet_setup_label_streaming_port, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->screen_ethernet_setup_label_streaming_port, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->screen_ethernet_setup_label_streaming_port, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->screen_ethernet_setup_label_streaming_port, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->screen_ethernet_setup_label_streaming_port, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->screen_ethernet_setup_label_streaming_port, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->screen_ethernet_setup_label_streaming_port, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->screen_ethernet_setup_label_streaming_port, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes screen_ethernet_setup_cont_confirmed_background
	ui->screen_ethernet_setup_cont_confirmed_background = lv_obj_create(ui->screen_ethernet_setup);
	lv_obj_set_pos(ui->screen_ethernet_setup_cont_confirmed_background, 0, 0);
	lv_obj_set_size(ui->screen_ethernet_setup_cont_confirmed_background, 240, 240);
	lv_obj_set_scrollbar_mode(ui->screen_ethernet_setup_cont_confirmed_background, LV_SCROLLBAR_MODE_OFF);
	lv_obj_add_flag(ui->screen_ethernet_setup_cont_confirmed_background, LV_OBJ_FLAG_HIDDEN);

	//Write style for screen_ethernet_setup_cont_confirmed_background, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->screen_ethernet_setup_cont_confirmed_background, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->screen_ethernet_setup_cont_confirmed_background, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->screen_ethernet_setup_cont_confirmed_background, 108, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui->screen_ethernet_setup_cont_confirmed_background, lv_color_hex(0x828282), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->screen_ethernet_setup_cont_confirmed_background, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->screen_ethernet_setup_cont_confirmed_background, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->screen_ethernet_setup_cont_confirmed_background, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->screen_ethernet_setup_cont_confirmed_background, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->screen_ethernet_setup_cont_confirmed_background, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes screen_ethernet_setup_cont_confirmed
	ui->screen_ethernet_setup_cont_confirmed = lv_obj_create(ui->screen_ethernet_setup);
	lv_obj_set_pos(ui->screen_ethernet_setup_cont_confirmed, 25, 80.5);
	lv_obj_set_size(ui->screen_ethernet_setup_cont_confirmed, 190, 79);
	lv_obj_set_scrollbar_mode(ui->screen_ethernet_setup_cont_confirmed, LV_SCROLLBAR_MODE_OFF);
	lv_obj_add_flag(ui->screen_ethernet_setup_cont_confirmed, LV_OBJ_FLAG_HIDDEN);

	//Write style for screen_ethernet_setup_cont_confirmed, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->screen_ethernet_setup_cont_confirmed, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_opa(ui->screen_ethernet_setup_cont_confirmed, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_color(ui->screen_ethernet_setup_cont_confirmed, lv_color_hex(0x00c92c), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_side(ui->screen_ethernet_setup_cont_confirmed, LV_BORDER_SIDE_FULL, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->screen_ethernet_setup_cont_confirmed, 10, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->screen_ethernet_setup_cont_confirmed, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui->screen_ethernet_setup_cont_confirmed, lv_color_hex(0x292831), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->screen_ethernet_setup_cont_confirmed, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->screen_ethernet_setup_cont_confirmed, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->screen_ethernet_setup_cont_confirmed, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->screen_ethernet_setup_cont_confirmed, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->screen_ethernet_setup_cont_confirmed, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes screen_ethernet_setup_label_confirmed
	ui->screen_ethernet_setup_label_confirmed = lv_label_create(ui->screen_ethernet_setup_cont_confirmed);
	lv_label_set_text(ui->screen_ethernet_setup_label_confirmed, "IP Address Updated");
	lv_label_set_long_mode(ui->screen_ethernet_setup_label_confirmed, LV_LABEL_LONG_WRAP);
	lv_obj_set_pos(ui->screen_ethernet_setup_label_confirmed, 0, 30);
	lv_obj_set_size(ui->screen_ethernet_setup_label_confirmed, 190, 15);

	//Write style for screen_ethernet_setup_label_confirmed, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->screen_ethernet_setup_label_confirmed, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->screen_ethernet_setup_label_confirmed, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->screen_ethernet_setup_label_confirmed, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->screen_ethernet_setup_label_confirmed, &lv_font_montserratMedium_14, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->screen_ethernet_setup_label_confirmed, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_line_space(ui->screen_ethernet_setup_label_confirmed, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->screen_ethernet_setup_label_confirmed, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->screen_ethernet_setup_label_confirmed, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->screen_ethernet_setup_label_confirmed, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->screen_ethernet_setup_label_confirmed, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->screen_ethernet_setup_label_confirmed, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->screen_ethernet_setup_label_confirmed, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->screen_ethernet_setup_label_confirmed, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Update current screen layout.
	lv_obj_update_layout(ui->screen_ethernet_setup);

	
	//Init events for screen.
	events_init_screen_ethernet_setup(ui);
}
