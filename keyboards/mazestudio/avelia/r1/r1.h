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

#include "quantum.h"
#pragma once
#define NNN KC_NO

#define LAYOUT( \
    K00, K10, K01, K11, K02, K12, K03, K13, K04, K14, K05, K15, K06, K16, K07, K17, K08, K18, K09, \
    K20, K30, K21, K31, K22, K32, K23, K33, K24, K34, K25, K35, K26, K36,      K37, K28, K38, K29, \
    K40, K50, K41, K51, K42, K52, K43, K53, K44, K54, K45, K55, K46 ,      K47,                     \
    K60, K70,      K71, K62, K72, K63, K73, K64, K74, K65, K75, K66, K76,      K77, K68, K78, K69, \
    K80, K90, K81, K91,                          K94,      K95, K86, K96,      K97, K88, K98, K89 \
) { \
    { K00, K01, K02, K03, K04, K05, K06, K07, K08, K09 }, \
    { K10, K11, K12, K13, K14, K15, K16, K17, K18, NNN }, \
    { K20, K21, K22, K23, K24, K25, K26, NNN, K28, K29 }, \
    { K30, K31, K32, K33, K34, K35, K36, K37, K38, NNN }, \
    { K40, K41, K42, K43, K44, K45, K46, K47, NNN, NNN }, \
    { K50, K51, K52, K53, K54, K55, NNN, NNN, NNN, NNN }, \
    { K60, NNN, K62, K63, K64, K65, K66, NNN, K68, K69 }, \
    { K70, K71, K72, K73, K74, K75, K76, K77, K78, NNN }, \
    { K80, K81, NNN, NNN, NNN, NNN, K86, NNN, K88, K89 }, \
    { K90, K91, NNN, NNN, K94, K95, K96, K97, K98, NNN } \
}
