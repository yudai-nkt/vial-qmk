/* Copyright 2020 Alexander Tulloh
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

#include "quantum.h"

#define LAYOUT( \
    A00, A01, A02, A03, A04,           A05, A06, A07, A08, A09, \
    A10, A11, A12, A13, A14,    A34,   A15, A16, A17, A18, A19, \
    A20, A21, A22, A23, A24,           A25, A26, A27, A28, A29, \
              A31, A32, A33,    A35,   A36, A37, A38 \
   ) \
  { \
    { A00,   A01,   A02,   A03,   A04,   A05,   A06,   A07,   A08,   A09 }, \
    { A10,   A11,   A12,   A13,   A14,   A15,   A16,   A17,   A18,   A19 }, \
    { A20,   A21,   A22,   A23,   A24,   A25,   A26,   A27,   A28,   A29 }, \
    { KC_NO, A31,   A32,   A33,   A34,   A35,   A36,   A37,   A38,   KC_NO } \
  }

