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

#include "quantum.h"
#pragma once 
#define NNN KC_NO

//   F1,  F6, ESC,   1,   2,   3,   4,   5,   6,   7,   8,   9,   0,   -,   =,   |, Del, Hom 
//   F2,  F7, Tab,   Q,   W,   E,   R,   T,   Y,   U,   I,   O,   P,   [,   ],    BSP  , End
//   F3,  F8,    CAP,   A,   S,   D,   F,   G,   H,   J,   K,   L,   ;,   ',    ENT,     NNN 
//   F4,  F9,    Shf,   Z,   X,   C,   V,   B,   N,   M,   <,   >,   ?, Shf,     Up,     NNN
//   F5,  F10,  Ctl, Win, Alt, Spc, Alt, Lft, Dwn, Rght

#define LAYOUT_split_bs(\
    K00, K10, K01, K11, K02, K12, K03, K13, K04, K14, K05, K15, K06, K16, K07, K17, K18, K08, \
    K20, K30, K21, K31, K22, K32, K23, K33, K24, K34, K25, K35, K26, K36, K27,    K37,   K28, \
    K40, K50,    K41, K42, K52, K43, K53, K44, K54, K45, K55, K46, K56, K47,    K57,     K48, \
    K60, K70,    K61, K62, K72, K63, K73, K64, K74, K65, K75, K66, K76, K67,    K77,     K68, \
    K80, K90,  K81, K82, K92, K94, K96, K87, K97, K88 \
) { \
    { K00, K01, K02, K03, K04, K05, K06, K07, K08 }, \
    { K10, K11, K12, K13, K14, K15, K16, K17, K18 }, \
    { K20, K21, K22, K23, K24, K25, K26, K27, K28 }, \
    { K30, K31, K32, K33, K34, K35, K36, K37, NNN }, \
    { K40, K41, K42, K43, K44, K45, K46, K47, K48 }, \
    { K50, NNN, K52, K53, K54, K55, K56, K57, NNN }, \
    { K60, K61, K62, K63, K64, K65, K66, K67, K68 }, \
    { K70, NNN, K72, K73, K74, K75, K76, K77, NNN }, \
    { K80, K81, K82, NNN, NNN, NNN, NNN, K87, K88 }, \
    { K90, NNN, K92, NNN, K94, NNN, K96, K97, NNN } \
}
