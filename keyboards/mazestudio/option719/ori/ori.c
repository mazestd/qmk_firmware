// Copyright 2023 Maze Studio
// SPDX-License-Identifier: GPL-2.0-or-later

#include "ori.h"
#include "display.h"

static bool display_enabled;

// This function will be used in keymaps
bool is_display_enabled(void) {
    return display_enabled;
}

bool led_update_kb(led_t led_state) {
    bool res = led_update_user(led_state);
    if (res && display_enabled) {
        display_process_caps(led_state.caps_lock);
    }

    return res;
}

void housekeeping_task_kb(void) {
    if (display_enabled) {
        display_housekeeping_task();
    }

    housekeeping_task_user();
}

void keyboard_post_init_kb(void) {
    display_enabled = display_init_kb();
    keyboard_post_init_user();
}