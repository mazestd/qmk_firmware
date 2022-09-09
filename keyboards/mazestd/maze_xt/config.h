/* Copyright 2022 oxkeys
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

#pragma once

#include "config_common.h"

/* Device Description */
#define MANUFACTURER    SCLabs
#define PRODUCT         maze_xt
#define VENDOR_ID       0xF005 // 0xF005 for SCLabs
#define PRODUCT_ID      0x1250 // 0x1250 for MazeXT
#define DEVICE_VER      0x0005

/* Matrix Size */
#define MATRIX_COLS 9
#define MATRIX_ROWS 10

/* Pin Assignment */
#define MATRIX_ROW_PINS { B5, B4, D7, D6, D4, D5, D3, D2, F1, F0 }
#define MATRIX_COL_PINS { B3 ,B1, B2, F5, F4, E6, C7, C6, B6 }

/* Diode Direction */
#define DIODE_DIRECTION COL2ROW

/* Debounce reduces chatter */
#define DEBOUNCE 10

/* BootMagic Lite Keys */
#define BOOTMAGIC_LITE_ROW 0
#define BOOTMAGIC_LITE_COLUMN 0

