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
/*
#define LAYOUT( \
    A00, A01, A02, A03, A04, A05, A06, A07, A08, A09, A0a, A0b,\
    A10, A11, A12, A13, A14,           A17, A18, A19, A1a, A1b, \
    A20, A21, A22, A23, A24,           A27, A28, A29, A2a, A2b, \
    A30, A31, A32, A33, A34, A35, A36, A37, A38, A39, A3a, A3b \
   ) \
  { \
    { A00,   A01,   A02,   A03,   A04,   A05,   A06,   A07,   A08,   A09,   A0a,   A0b }, \
    { A10,   A11,   A12,   A13,   A14,   KC_NO, KC_NO, A17,   A18,   A19,   A1a,   A1b }, \
    { A20,   A21,   A22,   A23,   A24,   KC_NO, KC_NO, A27,   A28,   A29,   A2a,   A2b }, \
    { A30,   A31,   A32,   A33,   A34,   A35,   A36,   A37,   A38,   A39,   A3a,   A3b } \
  }
*/

typedef union {
    uint32_t raw;
    struct {
        uint8_t cpi_idx;
        uint8_t scrl_div;
        uint8_t rotation_angle;
        int8_t scrl_inv;
        bool scrl_mode;
        bool auto_mouse;
        report_mouse_t last_mouse;
    };
} cocot_config_t;

extern cocot_config_t cocot_config;

enum cocot_keycodes {

    COCOT_SAFE_RANGE = SAFE_RANGE,
    CPI_SW,
    SCRL_SW,
    ROT_R15,
    ROT_L15,
    SCRL_MO,
    SCRL_TO,
    SCRL_IN,
    AM_TOG
};

#define CPI_SW QK_KB_0
#define SCRL_SW QK_KB_1
#define ROT_R15 QK_KB_2
#define ROT_L15 QK_KB_3
#define SCRL_MO QK_KB_4
#define SCRL_TO QK_KB_5
#define SCRL_IN QK_KB_6
#define AM_TOG QK_KB_7


bool encoder_update_user(uint8_t index, bool clockwise);
bool encoder_update_kb(uint8_t index, bool clockwise);

bool cocot_get_scroll_mode(void);
void cocot_set_scroll_mode(bool mode);


void enable_click_layer(void);
void disable_click_layer(void);
int16_t my_abs(int16_t num);
int16_t mmouse_move_y_sign(int16_t num);
bool is_clickable_mode(void);


//void render_logo(void);
//void oled_write_layer_state(void);
