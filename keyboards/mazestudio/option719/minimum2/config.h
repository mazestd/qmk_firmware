// Copyright 2023 Maze Studio
// SPDX-License-Identifier: GPL-2.0-or-later

#pragma once

/* SPI Configuration for Display
#define SPI_DRIVER SPID0
#define SPI_SCK_PIN GP6
#define SPI_MOSI_PIN GP7

// LCD 1 Display Config
#define LCD_DC_PIN GP4
#define LCD_CS_PIN GP3
#define LCD_RST_PIN GP5
#define QUANTUM_PAINTER_LVGL_USE_CUSTOM_CONF */

/* SPI config for display/touchpad */
#define SPI_DRIVER SPID0
#define SPI_SCK_PIN GP18
#define SPI_MOSI_PIN GP19

/* LCD config */
#define LCD_DC_PIN GP4
#define LCD_CS_PIN GP3
#define LCD_RST_PIN GP5
#define LCD_WIDTH 170
#define LCD_HEIGHT 320

/* Quantum Painter Config */
#define QUANTUM_PAINTER_DEBUG
#define QUANTUM_PAINTER_SUPPORTS_NATIVE_COLORS true
#define QUANTUM_PAINTER_DISPLAY_TIMEOUT 0