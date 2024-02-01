/*
Copyright 2022 aki27

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#include QMK_KEYBOARD_H
#include <stdio.h>
#include <math.h>
#include "quantum.h"


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


#define MS_BTN1 KC_MS_BTN1
#define MS_BTN2 KC_MS_BTN2
#define MS_BTN3 KC_MS_BTN3


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    [0] = LAYOUT(
        KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,             KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,
        KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_ESC,  KC_H,    KC_J,    KC_K,    KC_L,    KC_MINS,
        KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,             KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH,
                          KC_LALT, KC_LNG2, KC_SPC,  MS_BTN1, KC_ENT,  KC_LNG1, KC_BSPC
    ),
    [1] = LAYOUT(
        KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC,          KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN,
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_ESC,  KC_H,    KC_J,    KC_K,    KC_L,    KC_MINS,
        KC_GRV,  KC_TILD, KC_NUBS, KC_PIPE, XXXXXXX,          KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH,
                          KC_LALT, KC_LNG2, KC_SPC,  MS_BTN1, KC_ENT,  KC_LNG1, KC_BSPC
    ),
    [2] = LAYOUT(
        KC_1,    KC_2,    KC_3,    KC_4,    KC_5,             KC_6,    KC_7,    KC_8,    KC_9,    KC_0,
        KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_ESC,  KC_APP,  KC_UP,   KC_EQL,  KC_PLUS, KC_MINS,
        KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,           KC_LEFT, KC_DOWN, KC_RGHT, KC_DOT,  KC_SLSH,
                          KC_LALT, KC_LNG2, KC_SPC,  MS_BTN1, KC_ENT,  KC_LNG1, KC_BSPC
    ),
    [3] = LAYOUT(
        KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,             KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,
        KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_ESC,  KC_H,    KC_J,    KC_K,    KC_L,    KC_MINS,
        KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,             KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH,
                          KC_LALT, KC_LNG2, KC_SPC,  MS_BTN1, KC_ENT,  KC_LNG1, KC_BSPC
    ),
    [4] = LAYOUT(
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,          MS_BTN3, MS_BTN2, XXXXXXX, XXXXXXX, XXXXXXX,
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,          XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
                          XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, MS_BTN1, SCRL_MO, XXXXXXX
    ),
    [5] = LAYOUT(
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,          XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,          XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
                          XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX    ),
    [6] = LAYOUT(
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,          XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,          XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
                          XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX    ),
    [7] = LAYOUT(
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,          XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,          XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
                          XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX    )
};



#if defined(ENCODER_MAP_ENABLE)
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][2] = {
    [0] =   { ENCODER_CCW_CW(KC_PGUP, KC_PGDN) },
    [1] =   { ENCODER_CCW_CW(XXXXXXX, XXXXXXX) },
    [2] =   { ENCODER_CCW_CW(XXXXXXX, XXXXXXX) },
    [3] =   { ENCODER_CCW_CW(XXXXXXX, XXXXXXX) },
    [4] =   { ENCODER_CCW_CW(XXXXXXX, XXXXXXX) },
    [5] =   { ENCODER_CCW_CW(XXXXXXX, XXXXXXX) },
    [6] =   { ENCODER_CCW_CW(XXXXXXX, XXXXXXX) },
    [7] =   { ENCODER_CCW_CW(XXXXXXX, XXXXXXX) },
};
#endif




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


bool cocot_get_scroll_mode(void) {
    return cocot_config.scrl_mode;
}

void cocot_set_scroll_mode(bool mode) {
    cocot_config.scrl_mode = mode;
}


#ifndef COCOT_SCROLL_INV_DEFAULT
#    define COCOT_SCROLL_INV_DEFAULT 1
#endif

#ifndef COCOT_CPI_OPTIONS
#    define COCOT_CPI_OPTIONS { 200, 400, 800, 1600, 3200 }
#    ifndef COCOT_CPI_DEFAULT
#       define COCOT_CPI_DEFAULT 3
#    endif
#endif
#ifndef COCOT_CPI_DEFAULT
#    define COCOT_CPI_DEFAULT 3
#endif

#ifndef COCOT_SCROLL_DIVIDERS
#    define COCOT_SCROLL_DIVIDERS { 1, 2, 3, 4, 5, 6 }
#    ifndef COCOT_SCROLL_DIV_DEFAULT
#       define COCOT_SCROLL_DIV_DEFAULT 4
#    endif
#endif
#ifndef COCOT_SCROLL_DIV_DEFAULT
#    define COCOT_SCROLL_DIV_DEFAULT 4
#endif


#ifndef COCOT_ROTATION_ANGLE
#    define COCOT_ROTATION_ANGLE { -75, -60, -45, -30, -15, 0, 15, 30, 45, 60, 75 }
#    ifndef COCOT_ROTATION_DEFAULT
#       define COCOT_ROTATION_DEFAULT 3
#    endif
#endif
#ifndef COCOT_ROTATION_DEFAULT
#    define COCOT_ROTATION_DEFAULT 3
#endif
#ifndef COCOT_AUTO_MOUSE_MODE
#    define COCOT_AUTO_MOUSE_MODE 1
#endif


cocot_config_t cocot_config;
uint16_t cpi_array[] = COCOT_CPI_OPTIONS;
uint16_t scrl_div_array[] = COCOT_SCROLL_DIVIDERS;
uint16_t angle_array[] = COCOT_ROTATION_ANGLE;
#define CPI_OPTION_SIZE (sizeof(cpi_array) / sizeof(uint16_t))
#define SCRL_DIV_SIZE (sizeof(scrl_div_array) / sizeof(uint16_t))
#define ANGLE_SIZE (sizeof(angle_array) / sizeof(uint16_t))



void eeconfig_init_user(void) {
    cocot_config.cpi_idx = COCOT_CPI_DEFAULT;
    cocot_config.scrl_div = COCOT_SCROLL_DIV_DEFAULT;
    cocot_config.rotation_angle = COCOT_ROTATION_DEFAULT;
    cocot_config.scrl_inv = COCOT_SCROLL_INV_DEFAULT;
    cocot_config.scrl_mode = false;
    cocot_config.auto_mouse = COCOT_AUTO_MOUSE_MODE;
    eeconfig_update_user(cocot_config.raw);
}



void matrix_init_user(void) {
    // is safe to just read CPI setting since matrix init
    // comes before pointing device init.
    cocot_config.raw = eeconfig_read_user();
    if (cocot_config.cpi_idx > CPI_OPTION_SIZE) // || cocot_config.scrl_div > SCRL_DIV_SIZE || cocot_config.rotation_angle > ANGLE_SIZE)
    {
        eeconfig_init_user();
    }
}



layer_state_t layer_state_set_user(layer_state_t state) {
    switch(get_highest_layer(remove_auto_mouse_layer(state, true))) {
        case 1 ... 2:
            //rgblight_sethsv_range(HSV_YELLOW, 0, 9);
            cocot_set_scroll_mode(true);
            state = remove_auto_mouse_layer(state, false);
            set_auto_mouse_enable(false);
            break;
        case 3 ... 7:
            //rgblight_sethsv_range(HSV_CYAN, 0, 9);
            cocot_set_scroll_mode(false);
            set_auto_mouse_enable(cocot_config.auto_mouse);
            break;
        default:
            //rgblight_sethsv_range(HSV_RED, 0, 9);
            cocot_set_scroll_mode(false);
            //set_auto_mouse_enable(true);
            set_auto_mouse_enable(cocot_config.auto_mouse);
            break;
        }
    //rgblight_set_effect_range( 9, 36);
  return state;
};


bool process_record_user(uint16_t keycode, keyrecord_t* record) {
    // xprintf("KL: kc: %u, col: %u, row: %u, pressed: %u\n", keycode, record->event.key.col, record->event.key.row, record->event.pressed);
    
    switch (keycode) {
        #ifndef MOUSEKEY_ENABLE
                // process KC_MS_BTN1~8 by myself
                // See process_action() in quantum/action.c for details.
                case KC_MS_BTN1 ... KC_MS_BTN8: {
                    extern void register_button(bool, enum mouse_buttons);
                    register_button(record->event.pressed, MOUSE_BTN_MASK(keycode - KC_MS_BTN1));
                    return false;
                }
        #endif

        case AM_TOG:
        
            if(record->event.pressed) { // key down
                auto_mouse_layer_off(); // disable target layer if needed
                cocot_config.auto_mouse ^= 1;
                set_auto_mouse_enable(cocot_config.auto_mouse);
            } // do nothing on key up
            return false; // prevent further processing of keycode            
    }

    if (keycode == CPI_SW && record->event.pressed) {
        cocot_config.cpi_idx = (cocot_config.cpi_idx + 1) % CPI_OPTION_SIZE;
        eeconfig_update_user(cocot_config.raw);
        pointing_device_set_cpi(cpi_array[cocot_config.cpi_idx]);
    }

    if (keycode == SCRL_SW && record->event.pressed) {
        cocot_config.scrl_div = (cocot_config.scrl_div + 1) % SCRL_DIV_SIZE;
        eeconfig_update_user(cocot_config.raw);
    }
    
    if (keycode == ROT_R15 && record->event.pressed) {
        cocot_config.rotation_angle = (cocot_config.rotation_angle + 1) % ANGLE_SIZE;
        eeconfig_update_user(cocot_config.raw);
    }

    if (keycode == ROT_L15 && record->event.pressed) {
        cocot_config.rotation_angle = (ANGLE_SIZE + cocot_config.rotation_angle - 1) % ANGLE_SIZE;
        eeconfig_update_user(cocot_config.raw);
    }

    if (keycode == SCRL_IN && record->event.pressed) {
        cocot_config.scrl_inv = - cocot_config.scrl_inv;
        eeconfig_update_user(cocot_config.raw);
    }

    if (keycode == SCRL_TO && record->event.pressed) {
        { cocot_config.scrl_mode ^= 1; }
    }

    if (keycode == SCRL_MO) {
        { cocot_config.scrl_mode ^= 1; }
    }

    return true;
}



// Scroll Accumulation
static int16_t h_acm       = 0;
static int16_t v_acm       = 0;


void pointing_device_init_user(void) {
    pointing_device_set_cpi(cpi_array[cocot_config.cpi_idx]);
    set_auto_mouse_layer(4);
    set_auto_mouse_enable(cocot_config.auto_mouse);
    //set_auto_mouse_enable(true);
}



report_mouse_t pointing_device_task_user(report_mouse_t mouse_report) {

    double rad = angle_array[cocot_config.rotation_angle] * (M_PI / 180) * -1;
    int8_t x_rev =  + mouse_report.x * cos(rad) - mouse_report.y * sin(rad);
    int8_t y_rev =  + mouse_report.x * sin(rad) + mouse_report.y * cos(rad);

    if (cocot_get_scroll_mode()) {
        // rock scroll direction
        if (abs(x_rev) > abs(y_rev)) {
            y_rev = 0;
        } else {
            x_rev = 0;
        }

        // accumulate scroll
        h_acm += x_rev * cocot_config.scrl_inv;
        v_acm += y_rev * cocot_config.scrl_inv * -1;

        int8_t h_rev = h_acm >> scrl_div_array[cocot_config.scrl_div];
        int8_t v_rev = v_acm >> scrl_div_array[cocot_config.scrl_div];

        // clear accumulated scroll on assignment

        if (h_rev != 0) {
            if (mouse_report.h + h_rev > 127) {
                h_rev = 127 - mouse_report.h;
            } else if (mouse_report.h + h_rev < -127) {
                h_rev = -127 - mouse_report.h;
            }
            mouse_report.h += h_rev;
            h_acm -= h_rev << scrl_div_array[cocot_config.scrl_div];
        }
        if (v_rev != 0) {
            if (mouse_report.v + v_rev > 127) {
                v_rev = 127 - mouse_report.v;
            } else if (mouse_report.v + v_rev < -127) {
                v_rev = -127 - mouse_report.v;
            }
            mouse_report.v += v_rev;
            v_acm -= v_rev << scrl_div_array[cocot_config.scrl_div];
        }

        mouse_report.x = 0;
        mouse_report.y = 0;
    } else {
        mouse_report.x = -x_rev;
        mouse_report.y = y_rev;
    }

    return mouse_report;
}



bool is_mouse_record_user(uint16_t keycode, keyrecord_t* record) {
    switch(keycode) {
      case KC_LCTL:
        return true;
      case KC_LSFT:
        return true;
      case SCRL_MO:
        return true;
      default:
        return false;
    }
    return is_mouse_record_user(keycode, record);
}



#ifdef RGB_MATRIX_ENABLE
    led_config_t g_led_config = { {
    // Key Matrix to LED Index
        {  1, 3, 5, 7, 9,51,53,55,57,59 },
        { 10,12,14,16,18,42,44,46,48,50 },
        { 19,20,21,22,23,37,38,39,40,41 },
        { NO_LED,24,26,28, 0,30,32,34,36,NO_LED }
    }, {
    // LED Index to Physical Position
        {126, 174}, {8, 244}, {19, 239}, {32, 249}, {43, 244}, {56, 254}, {66, 233}, {78, 235}, {89, 214}, {101, 216}, {4, 183}, {15, 178}, {28, 187}, {39, 182}, {52, 192}, {62, 171}, {74, 173}, {85, 153}, {97, 155}, {0, 121}, {24, 126}, {48, 131}, {70, 112}, {93, 93}, {52, 40}, {64, 33}, {75, 23}, {88, 12}, {100, 5}, {113, 0}, {126, 0}, {139, 0}, {152, 5}, {165, 11}, {177, 23}, {189, 33}, {201, 39}, {160, 93}, {183, 112}, {205, 130}, {229, 126}, {254, 121}, {156, 155}, {168, 153}, {179, 173}, {191, 171}, {201, 192}, {214, 182}, {225, 187}, {238, 178}, {249, 183}, {152, 216}, {164, 214}, {175, 235}, {187, 233}, {197, 253}, {210, 244}, {221, 249}, {234, 239}, {245, 244}
    }, {
    // LED Index to Flag
        4, 4, 2, 4, 2, 4, 2, 4, 2, 4, 4, 2, 4, 2, 4, 2, 4, 2, 4, 4, 4, 4, 4, 4, 4, 2, 4, 2, 4, 2, 4, 2, 4, 2, 4, 2, 4, 4, 4, 4, 4, 4, 4, 2, 4, 2, 4, 2, 4, 2, 4, 4, 2, 4, 2, 4, 2, 4, 2, 4
} };


bool rgb_matrix_indicators_advanced_user(uint8_t led_min, uint8_t led_max) { 
    int is_layer = get_highest_layer(layer_state|default_layer_state);  
    HSV hsv = {0, 255, rgblight_get_val()};
    if (is_layer == 1) {
      hsv.h = 128; //CYAN
    } else if (is_layer == 2)  {
      hsv.h = 85; //GREEN
    } else if (is_layer == 3)  {
      hsv.h = 43; //YELLOW
    } else if (is_layer == 4)  {
      hsv.h = 0; //RED
    } else if (is_layer == 5)  {
      hsv.h = 191; //PURPLE
    } else if (is_layer == 6)  {
      hsv.h = 64; //CHARTREUSE
    } else if (is_layer == 7)  {
      hsv.h = 224;
    } else {
      hsv.h = 11; //CORAL
    }
    RGB rgb = hsv_to_rgb(hsv);
 
    for (uint8_t i = led_min; i <= led_max; i++) {
        if (HAS_FLAGS(g_led_config.flags[i], 0x02)) {
          rgb_matrix_set_color(i, rgb.r, rgb.g, rgb.b);
        }
    }
    return false;
};

#endif






