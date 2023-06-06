/* Copyright 2022 Maze Studio
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include "r1.h"
#include <qp.h>
#include "anime.qgf.h"


static painter_device_t display;
//static painter_image_handle_t image;

uint32_t deffered_init(uint32_t trigger_time, void *cb_arg)
{
    display = qp_st7735_make_spi_device(80, 160, LCD_CS_PIN, LCD_DC_PIN, LCD_RST_PIN, 8, 0);
    qp_init(display, QP_ROTATION_90);

    qp_rect(display, 1, 2, 80, 40, 24, 255, 255, true);

    return(0);
}

void keyboard_post_init_kb(void)
{
    debug_enable = true;
    defer_exec(3000, deffered_init, NULL);
}

