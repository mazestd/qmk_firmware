// Copyright 2023 zzeneg (@zzeneg)
// SPDX-License-Identifier: GPL-2.0-or-later

#include "ori_display.h"
#include "display.h"
#include "raw_hid.h"
#include "lvgl_helpers.h"

uint16_t home_screen_timer = 0;

/* screens */
static lv_obj_t *screen_home;
static lv_obj_t *screen_media;

/* home screen content */
static lv_obj_t *label_time_hours;
static lv_obj_t *label_time_minutes;
static lv_obj_t *label_time_seconds;
static lv_obj_t *label_caps;

/* media screen content */
static lv_obj_t *label_media_artist;
static lv_obj_t *label_media_title;


void read_string(uint8_t *data, char *string_data) {
    uint8_t data_length = data[1];
    memcpy(string_data, data + 2, data_length);
    string_data[data_length] = '\0';
}

void start_home_screen_timer(void) {
    dprint("reset home screen\n");
    home_screen_timer = timer_read();
}

void init_screen_home_custom(void) {
    screen_home = lv_scr_act();
    lv_obj_add_style(screen_home, &style_screen, 0);
    use_flex_column(screen_home);

    label_time_hours = lv_label_create(screen_home);
    lv_label_set_text(label_time_hours, "00");

    label_time_minutes = lv_label_create(screen_home);
    lv_label_set_text(label_time_minutes, "00");

    label_time_seconds = lv_label_create(screen_home);
    lv_label_set_text(label_time_seconds, "00");

    lv_obj_set_style_text_font(label_time_hours, &montserrat_48_digits, LV_PART_MAIN);
    lv_obj_set_style_text_font(label_time_minutes, &montserrat_48_digits, LV_PART_MAIN);
    lv_obj_set_style_text_font(label_time_seconds, &montserrat_48_digits, LV_PART_MAIN);

    lv_obj_t *caps = lv_obj_create(screen_home);
    lv_obj_add_style(caps, &style_container, 0);
    use_flex_row(caps);

    label_caps      = create_button(caps, "CAPS", &style_button, &style_button_active);

}

void init_screen_media(void) {
    screen_media = lv_obj_create(NULL);
    lv_obj_add_style(screen_media, &style_screen, 0);
    use_flex_column(screen_media);
    lv_obj_set_flex_align(screen_media, LV_FLEX_ALIGN_SPACE_EVENLY, LV_FLEX_ALIGN_CENTER, LV_FLEX_ALIGN_CENTER);

    label_media_artist = lv_label_create(screen_media);
    lv_label_set_text(label_media_artist, "N/A");
    lv_label_set_long_mode(label_media_artist, LV_LABEL_LONG_WRAP);
    lv_obj_set_width(label_media_artist, lv_pct(90));
    lv_obj_set_style_text_align(label_media_artist, LV_TEXT_ALIGN_CENTER, 0);

    label_media_title = lv_label_create(screen_media);
    lv_label_set_text(label_media_title, "N/A");
    lv_label_set_long_mode(label_media_title, LV_LABEL_LONG_WRAP);
    lv_obj_set_width(label_media_title, lv_pct(90));
    lv_obj_set_style_text_align(label_media_title, LV_TEXT_ALIGN_CENTER, 0);
}

bool display_init_user(void) {
    init_screen_home_custom();
    init_screen_media();

    return false;
}

void display_process_raw_hid_data(uint8_t *data, uint8_t length) {
    uint8_t data_type = data[0];
    char    string_data[length - 2];
    dprintf("display_process_raw_hid_data - received data_type %u \n", data_type);
    switch (data_type) {
        case _TIME:
            dprintf("time %02d:%02d\n", data[1], data[2]);
            lv_label_set_text_fmt(label_time_hours, "%02d", data[1]);
            lv_label_set_text_fmt(label_time_minutes, "%02d", data[2]);
            lv_label_set_text_fmt(label_time_seconds, "%02d", data[3]);
            break;

        case _VOLUME:
            dprintf("volume %d\n", data[1]);
            /*
            lv_label_set_text_fmt(label_volume_home, "Volume: %02d%%", data[1]);
            lv_label_set_text_fmt(label_volume_arc, "%02d", data[1]);
            lv_arc_set_value(arc_volume, data[1]);
            lv_scr_load(screen_volume);
            start_home_screen_timer();
            */
            break;
            
        case _LAYOUT:
            dprintf("layout %d\n", data[1]);
            /*
            set_layout_icon(data[1]);
            */
            break;
           
            
        case _MEDIA_ARTIST:
            read_string(data, string_data);
            dprintf("media artist %s\n", string_data);
            lv_label_set_text(label_media_artist, string_data);
            lv_scr_load(screen_media);
            start_home_screen_timer();
            break;

        case _MEDIA_TITLE:
            read_string(data, string_data);
            dprintf("media title %s\n", string_data);
            lv_label_set_text(label_media_title, string_data);
            lv_scr_load(screen_media);
            start_home_screen_timer();
            break;
    }
}


void display_housekeeping_task(void) {
    if (home_screen_timer && timer_elapsed(home_screen_timer) > 5000) {
        home_screen_timer = 0;
        lv_scr_load(screen_home);
    }
}

void display_process_caps(bool active) {
    toggle_state(label_caps, LV_STATE_PRESSED, active);
}