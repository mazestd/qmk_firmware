// Copyright 2023 QMK
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H
#include "raw_hid.h"
#include "graphics.h"

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /*
     * ┌───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┐ ┌───┬───┬───┐
     * │Esc│ 1 │ 2 │ 3 │ 4 │ 5 │ 6 │ 7 │ 8 │ 9 │ 0 │ - │ = │ \ │Del│ │Ins│Hom│PgU│
     * ├───┴─┬─┴─┬─┴─┬─┴─
     */
    [0] = LAYOUT(
        KC_0, KC_0, KC_0, KC_0,
        KC_0, KC_0, KC_0, KC_0,
        KC_0, KC_0, KC_0, KC_0,
        KC_0, KC_0, KC_0, KC_0
    )
};

void raw_hid_receive_kb(uint8_t *data, uint8_t length) {
    display_processing(data, length);
}