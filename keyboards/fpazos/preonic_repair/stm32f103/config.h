/* Copyright 2021 Mike Tsao
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

// config.h

#pragma once

#include "config_common.h"

#define USB2422_ADDRESS 0x58
#define USB2422_VENDOR_ID 0x04D8
#define USB2422_PRODUCT_ID 0xEEC5
#define USB2422_DEVICE_VER 0x0101
#define USB2422_MANUFACTURER "Massdrop Inc."
#define USB2422_PRODUCT "Massdrop Hub"
#define USB2422_ACTIVE_PIN A18

// key matrix pins
#define MATRIX_ROW_PINS { A10, A9, B10, B1, B0, A7, A6, A5, A4, A3 }
#define MATRIX_COL_PINS { B5, B4, B3, A15, A12, A11 }

// { C14, C15, A0, A1, A2, A3 }
// { A4, A5, A6, A7, B0, B1, B10, B11, B12, B13, B14, B15, A8, A9, A10, A15, B3 }

// COL2ROW or ROW2COL
#define DIODE_DIRECTION COL2ROW
