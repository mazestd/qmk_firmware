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

#pragma once
/* Debounce */
#define DEBOUNCE 10

/* BootMagic Lite Keys */
#define BOOTMAGIC_LITE_COLUMN 0
#define BOOTMAGIC_LITE_ROW 0

/* Matrix Size */
#define MATRIX_COLS 10
#define MATRIX_ROWS 10

/* Pin Assigment */
#define MATRIX_COL_PINS { GP29, GP28, GP27, GP26, GP25, GP24, GP23, GP22, GP4, GP5 }
#define MATRIX_ROW_PINS { GP3, GP2, GP1, GP0, GP15, GP14, GP7, GP6, GP8, GP9 }

/* Diode Direction */
#define DIODE_DIRECTION COL2ROW

// LCD Configuration
#define LCD_RST_PIN GP17
#define LCD_CS_PIN GP20
#define LCD_DC_PIN GP16
//#define LCD_BLK_PIN GP21

#define SPI_DRIVER_SPID0
#define SPI_SCK_PIN GP18
#define SPI_MOSI_PIN GP19
#define SPI_MISO_PIN GP21

// LED Pinout
#define LED_CAPS_LOCK_PIN GP13
#define LED_USER_PIN GP12

#define QUANTUM_PAINTER_DEBUG
#define QUANTUM_PAINTER_SUPPORTS_NATIVE_COLORS true