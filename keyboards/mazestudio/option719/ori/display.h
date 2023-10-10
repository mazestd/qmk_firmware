// Copyright 2023 zzeneg (@zzeneg)
// SPDX-License-Identifier: GPL-2.0-or-later

#include "qp_lvgl.h"

/* shared styles */
extern lv_style_t style_screen;
extern lv_style_t style_container;
extern lv_style_t style_button;
extern lv_style_t style_button_active;

bool display_init_kb(void);
bool display_init_user(void);
void display_housekeeping_task(void);
void display_process_caps(bool active);
