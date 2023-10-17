// Copyright 2023 Maze Studio
// SPDX-License-Identifier: GPL-2.0-or-later

#pragma once
#include_next <halconf.h>

#undef HAL_USE_I2C
#define HAL_USE_I2C TRUE