// Copyright 2022 Jose Pablo Ramirez (@jpe230)
// SPDX-License-Identifier: GPL-2.0-or-later

#pragma once

/* SPI config for display/touchpad */
#define SPI_DRIVER SPID0
#define SPI_SCK_PIN GP18
#define SPI_MOSI_PIN GP19

/* LCD config */
#define LCD_DC_PIN GP4
#define LCD_CS_PIN GP3
#define LCD_RST_PIN GP5

#define QUANTUM_PAINTER_DEBUG
#define QUANTUM_PAINTER_SUPPORTS_NATIVE_COLORS true
#define QUANTUM_PAINTER_DISPLAY_TIMEOUT 0
