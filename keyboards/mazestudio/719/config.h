// Copyright 2023 Maze Studio
// SPDX-License-Identifier: GPL-2.0-or-later

#pragma once

/* OLED Configuration */
#define I2C_DRIVER I2CD1
#define I2C1_SDA_PIN GP2
#define I2C1_SCL_PIN GP3

#define OLED_DISPLAY_128X64
#define OLED_TIMEOUT 300000
#define OLED_BRIGHTNESS 128

/* SPI config for display/touchpad */
#define SPI_DRIVER SPID1
#define SPI_SCK_PIN GP10
#define SPI_MOSI_PIN GP11

/* LCD config */
#define LCD_BL_PIN GP6
#define LCD_DC_PIN GP7
#define LCD_CS_PIN GP8
#define LCD_RST_PIN GP9
#define LCD_WIDTH 170
#define LCD_HEIGHT 320

/* Quantum Painter Config */
#define QUANTUM_PAINTER_DEBUG
#define QUANTUM_PAINTER_SUPPORTS_NATIVE_COLORS true
#define QUANTUM_PAINTER_DISPLAY_TIMEOUT 0

