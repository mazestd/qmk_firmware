// Copyright 2022 Jose Pablo Ramirez (@jpe230)
// SPDX-License-Identifier: GPL-2.0-or-later

/*

#include <qp.h>
#include "images/anime.qgf.h"

static painter_image_handle_t image;

uint32_t deffered_init(uint32_t trigger_time, void *cb_arg)
{
    image = qp_load_image_mem(gfx_anime);

    painter_device_t display = qp_st7789_make_spi_device(240, 320, LCD_CS_PIN, LCD_DC_PIN, LCD_RST_PIN, 0, 3);
    qp_set_viewport_offsets(display, 0, 20);
    qp_init(display, QP_ROTATION_0);

    //qp_rect(display, 1, 2, 80, 40, 24, 255, 255, true);
    qp_animate(display, (240 - image->width), (280 - image->height), image);
    //qp_drawimage(display, (240 - background->width), (280 - background->height), background);

    return(0);
}

void keyboard_post_init_kb(void)
{
    //debug_enable = true;
    defer_exec(3000, deffered_init, NULL);
}

*/

#include "display.h"
#include "qp.h"
#include "lvgl_helpers.h"

/* shared styles */
lv_style_t style_screen;
lv_style_t style_container;
lv_style_t style_button;
lv_style_t style_button_active;

/* screens */
static lv_obj_t *screen_home;

/* home screen content */
static lv_obj_t *label_caps;

/* Create Painter Device */
static painter_device_t display;

void init_styles(void) {
    lv_style_init(&style_screen);
    lv_style_set_bg_color(&style_screen, lv_color_hex(0x282828));

    lv_style_init(&style_container);
    lv_style_set_pad_top(&style_container, 4);
    lv_style_set_pad_bottom(&style_container, 4);
    lv_style_set_pad_left(&style_container, 4);
    lv_style_set_pad_right(&style_container, 4);
    lv_style_set_bg_opa(&style_container, 0);
    lv_style_set_border_width(&style_container, 0);
    lv_style_set_width(&style_container, lv_pct(100));
    lv_style_set_height(&style_container, LV_SIZE_CONTENT);

    lv_style_init(&style_button);
    lv_style_set_pad_top(&style_button, 0);
    lv_style_set_pad_bottom(&style_button, 0);
    lv_style_set_pad_left(&style_button, 0);
    lv_style_set_pad_right(&style_button, 0);
    lv_style_set_radius(&style_button, 6);
    lv_style_set_text_color(&style_button, lv_palette_main(LV_PALETTE_PURPLE));

    lv_style_init(&style_button_active);
    lv_style_set_bg_color(&style_button_active, lv_palette_main(LV_PALETTE_PURPLE));
    lv_style_set_bg_opa(&style_button_active, LV_OPA_100);
    lv_style_set_text_color(&style_button_active, lv_color_black());
}

void init_screen_home(void) {
    screen_home = lv_scr_act();
    
    lv_obj_add_style(screen_home, &style_screen, 0);
    use_flex_column(screen_home);
    /*
    lv_obj_t *mods = lv_obj_create(screen_home);
    lv_obj_add_style(mods, &style_container, 0);
    use_flex_column(mods);
    */
    label_caps = create_button(screen_home, "CAPS", &style_button, &style_button_active);
}

bool display_init_kb(void) {
    dprint("display_init_kb - start\n");

    setPinOutput(GP2);
    writePinHigh(GP2);

    display = qp_st7789_make_spi_device(240, 300, LCD_CS_PIN, LCD_DC_PIN, LCD_RST_PIN, 16, 3);
    qp_set_viewport_offsets(display, 0, 20);

    if (!qp_init(display, QP_ROTATION_180) || !qp_power(display, true) || !qp_lvgl_attach(display)) return false;

    dprint("display_init_kb - initialised\n");

    lv_disp_t  *lv_display = lv_disp_get_default();
    lv_theme_t *lv_theme   = lv_theme_default_init(lv_display, lv_palette_main(LV_PALETTE_PURPLE), lv_palette_main(LV_PALETTE_BLUE), true, LV_FONT_DEFAULT);
    lv_disp_set_theme(lv_display, lv_theme);
    init_styles();

    bool res = display_init_user();
    if (res) {
        dprint("display_init_kb - adding default home screen\n");
        init_screen_home();
    }

    return true;
}

__attribute__((weak)) bool display_init_user(void) {
    return true;
}

__attribute__((weak)) void display_housekeeping_task(void) {
    dprint("display_housekeeping_task_kb\n");
}

__attribute__((weak)) void display_process_caps(bool active) {
    dprint("display_process_caps\n");
    toggle_state(label_caps, LV_STATE_PRESSED, active);
}
