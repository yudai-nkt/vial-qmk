// Copyright 2023 aki27 (@aki27kbd)
// SPDX-License-Identifier: GPL-2.0-or-later

#pragma once

#define VIAL_KEYBOARD_UID {0xC4, 0x18, 0xCC, 0x6D, 0x1C, 0x16, 0x5B, 0x8D}
#define VIAL_UNLOCK_COMBO_ROWS {0, 0}
#define VIAL_UNLOCK_COMBO_COLS {0, 7}

/* VIA */
#define DYNAMIC_KEYMAP_LAYER_COUNT 8


/* key matrix size */
#define MATRIX_COLS 8
#define MATRIX_ROWS 1


/* tapping term */
// #define TAPPING_FORCE_HOLD
#define TAPPING_TERM 200
// #define IGNORE_MOD_TAP_INTERRUPT


/* Encoder */
//#define ENCODERS_PAD_A { GP19 }
//#define ENCODERS_PAD_B { GP18 }
//#define ENCODER_RESOLUTION 2

/* Matrix*/
//#define DIRECT_PINS { GP17, GP20, GP27, GP28, GP29, GP0, GP1, GP16 }

/* COL2ROW, ROW2COL */
//#define DIODE_DIRECTION COL2ROW


/* Set 0 if debouncing isn't needed */
#define DEBOUNCE 5


/* Mechanical locking support. Use KC_LCAP, KC_LNUM or KC_LSCR instead in keymap */
#undef LOCKING_SUPPORT_ENABLE
/* Locking resynchronize hack */
#undef LOCKING_RESYNC_ENABLE


/* Trackball */

#ifdef POINTING_DEVICE_ENABLE

#    undef RP_SPI_USE_SPI0
#    define RP_SPI_USE_SPI0 TRUE
#    undef RP_SPI_USE_SPI1
#    define RP_SPI_USE_SPI1 FALSE
#    define SPI_DRIVER SPID0

#    define SPI_SCK_PIN GP2
#    define SPI_MISO_PIN GP4
#    define SPI_MOSI_PIN GP3

#endif


#ifndef PMW33XX_CS_PIN
#    define PMW33XX_CS_PIN GP5
#endif


#define POINTING_DEVICE_ROTATION_270

