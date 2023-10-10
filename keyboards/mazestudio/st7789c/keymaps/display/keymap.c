// Copyright 2022 Jose Pablo Ramirez (@jpe230)
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H
#include <qp.h>
#include "work.qgf.h"

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [0] = LAYOUT_ortho_1x1(KC_0)
};

static painter_image_handle_t image;

uint32_t deffered_init(uint32_t trigger_time, void *cb_arg)
{
    setPinOutput(GP20);
    writePinHigh(GP20);
    
    image = qp_load_image_mem(gfx_work);

    painter_device_t display = qp_st7789_make_spi_device(170, 320, LCD_CS_PIN, LCD_DC_PIN, LCD_RST_PIN, 0, 3);
    qp_set_viewport_offsets(display, 35, 0);
    qp_init(display, QP_ROTATION_0);

    qp_drawimage(display, (170 - image->width), (320 - image->height), image);

    return(0);
}

void keyboard_post_init_kb(void)
{
    debug_enable = true;
    defer_exec(3000, deffered_init, NULL);
}