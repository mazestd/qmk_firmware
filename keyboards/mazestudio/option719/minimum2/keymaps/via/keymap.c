// Copyright 2023 QMK
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H
#include <qp.h>
#include "raw_hid.h"
#include "process.h"
#include "fonts/techfont.qff.h"

static painter_font_handle_t font;
static painter_device_t display;

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /*
     * ┌───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┐ ┌───┬───┬───┐
     * │Esc│ 1 │ 2 │ 3 │ 4 │ 5 │ 6 │ 7 │ 8 │ 9 │ 0 │ - │ = │ \ │Del│ │Ins│Hom│PgU│
     * ├───┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴───┤ ├───┼───┼───┤
     * │ Tab │ Q │ W │ E │ R │ T │ Y │ U │ I │ O │ P │ [ │ ] │BsSpc│ │Del│End│PgD│
     * ├─────┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴─────┤ └───┴───┴───┘
     * │ Caps │ A │ S │ D │ F │ G │ H │ J │ K │ L │ ; │ ' │  Enter │
     * ├──────┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴────────┤     ┌───┐
     * │ Shift  │ Z │ X │ C │ V │ B │ N │ M │ , │ . │ / │    Shift │     │ ↑ │
     * ├────┬───┴┬──┴─┬─┴───┴───┴───┴───┴───┴───┴┬──┴───┼───┬──────┤ ┌───┼───┼───┐
     * │Ctrl│GUI │Alt │                          │ Alt  │GUI│ Ctrl │ │ ← │ ↓ │ → │
     * └────┴────┴────┴──────────────────────────┴──────┴───┴──────┘ └───┴───┴───┘
     */
    [0] = LAYOUT(
        KC_ESC,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,  KC_BSLS, KC_DEL, KC_INS,  KC_HOME, KC_PGUP,
        KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC, KC_RBRC, KC_BSPC,         KC_DEL,  KC_END,  KC_PGDN,
        KC_CAPS, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,          KC_ENT,          _______,  _______,  _______,
        KC_LSFT,          KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT, MO(1),           _______,  KC_UP,   _______,
        KC_LCTL, KC_LGUI, KC_LALT,                            KC_SPC,                             KC_RALT,          KC_RGUI, KC_RCTL,         KC_LEFT, KC_DOWN, KC_RGHT
    )
};

void keyboard_post_init_kb(void) {
    setPinOutput(GP2);
    writePinHigh(GP2);
    debug_enable = true;

    font = qp_load_font_mem(font_techfont);
    display = qp_st7789_make_spi_device(LCD_WIDTH, LCD_HEIGHT, LCD_CS_PIN, LCD_DC_PIN, LCD_RST_PIN, 0, 3);
    qp_set_viewport_offsets(display, 35, 0);
    wait_ms(1000);
}

/* Raw HID processing*/
void raw_hid_receive(uint8_t *data, uint8_t length) {
    //dprintf("raw_hid_receive - received %u bytes \n", length);
    //printf("Received data %u:", data[1]);
    //printf("%u:", data[2]);
    //printf("%u \n", data[3]);
    uint8_t data_type = data[0];

    if(data_type == 248) {
        printf("Received clock: %s\n", (const char *)&data[1]);
        if(qp_init(display, QP_ROTATION_0 == true)) {
            qp_drawtext_recolor(display, 15, 10, font, (const char *)&data[1], 0, 0, 0, 0, 0, 255);
            qp_flush(display);
        } else {
            printf("not initialized");            
        }
    }
}