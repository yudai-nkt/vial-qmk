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
    A000, A001, A002, A003, A004, A005, A006, A007, A008, A009, A010, A011, A012, \
    A100, A101, A102, A103, A104,             A107, A108, A109, A110, A111, RE_A,\
    A200, A201, A202, A203, A204,       A206, A207, A208, A209, A210, A211, RE_B,\
    A300, A301, A302, A303, A304, A305, A306, A307, A308, A309, A310, A311 \
   ) \
  { \
    { A000,   A001,   A002,   A003,   A004,   A005,   A006,   A007,   A008,   A009,   A010,   A011,   A012 }, \
    { A100,   A101,   A102,   A103,   A104,  KC_NO,  KC_NO,   A107,   A108,   A109,   A110,   A111,   RE_A }, \
    { A200,   A201,   A202,   A203,   A204,  KC_NO,   A206,   A207,   A208,   A209,   A210,   A211,   RE_B }, \
    { A300,   A301,   A302,   A303,   A304,   A305,   A306,   A307,   A308,   A309,   A310,   A311,  KC_NO } \
  }



typedef union {
    uint32_t raw;
    struct {
        uint8_t cpi_idx;
        uint8_t scrl_div;
        uint8_t rotation_angle;
        int8_t scrl_inv;
        bool scrl_mode;
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
};

#define CPI_SW QK_KB_0
#define SCRL_SW QK_KB_1
#define ROT_R15 QK_KB_2
#define ROT_L15 QK_KB_3
#define SCRL_MO QK_KB_4
#define SCRL_TO QK_KB_5
#define SCRL_IN QK_KB_6



bool encoder_update_user(uint8_t index, bool clockwise);
bool encoder_update_kb(uint8_t index, bool clockwise);

bool cocot_get_scroll_mode(void);
void cocot_set_scroll_mode(bool mode);


void enable_click_layer(void);
void disable_click_layer(void);
int16_t my_abs(int16_t num);
int16_t mmouse_move_y_sign(int16_t num);
bool is_clickable_mode(void);


void render_logo(void);
void oled_write_layer_state(void);
