// Copyright 2024 aki27 (@aki27kbd)
// SPDX-License-Identifier: GPL-2.0-or-later

#pragma once

#define VIAL_KEYBOARD_UID {0xB9, 0x29, 0x4B, 0x9E, 0x0B, 0x83, 0x8D, 0xF4}
#define VIAL_UNLOCK_COMBO_ROWS {0, 0}
#define VIAL_UNLOCK_COMBO_COLS {1, 11}

/* VIA */
#define DYNAMIC_KEYMAP_LAYER_COUNT 8

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

#define POINTING_DEVICE_ROTATION_180


/* RGB LED */
/*
#define WS2812_PIO_USE_PIO1
#define WS2812_DI_PIN GP0

#ifdef RGBLIGHT_ENABLE
    #define RGBLED_NUM 45
    #define RGBLIGHT_LIMIT_VAL 80
    #define RGBLIGHT_HUE_STEP 10
    #define RGBLIGHT_SAT_STEP 17
    #define RGBLIGHT_VAL_STEP 17

    // #define RGBLIGHT_ANIMATIONS
    #define RGBLIGHT_EFFECT_BREATHING
    #define RGBLIGHT_EFFECT_RAINBOW_MOOD
    #define RGBLIGHT_EFFECT_RAINBOW_SWIRL
    #define RGBLIGHT_EFFECT_SNAKE
    #define RGBLIGHT_EFFECT_KNIGHT
    #define RGBLIGHT_EFFECT_CHRISTMAS
    #define RGBLIGHT_EFFECT_STATIC_GRADIENT
    #define RGBLIGHT_EFFECT_RGB_TEST
    #define RGBLIGHT_EFFECT_ALTERNATING
#endif
*/

/* RGB MATRIX */
/*
//#define DRIVER_LED_TOTAL 60
#define RGB_MATRIX_LED_COUNT 45

#ifdef RGB_MATRIX_ENABLE
  #define RGB_MATRIX_KEYPRESSES // reacts to keypresses
//  #define RGB_MATRIX_KEYRELEASES // reacts to keyreleases (instead of keypresses)
  #define RGB_MATRIX_FRAMEBUFFER_EFFECTS // enable framebuffer effects
  #define RGB_DISABLE_TIMEOUT 120000 // number of milliseconds to wait until rgb automatically turns off
//  #define RGB_DISABLE_AFTER_TIMEOUT 0 // OBSOLETE: number of ticks to wait until disabling effects
  #define RGB_DISABLE_WHEN_USB_SUSPENDED true// turn off effects when suspended
//  #define RGB_MATRIX_LED_PROCESS_LIMIT (DRIVER_LED_TOTAL + 4) / 5 // limits the number of LEDs to process in an animation per task run (increases keyboard responsiveness)
//  #define RGB_MATRIX_LED_FLUSH_LIMIT 16 // limits in milliseconds how frequently an animation will update the LEDs. 16 (16ms) is equivalent to limiting to 60fps (increases keyboard responsiveness)
  #define RGB_MATRIX_MAXIMUM_BRIGHTNESS 128 // limits maximum brightness of LEDs to 200 out of 255. If not defined maximum brightness is set to 255
//  #define RGB_MATRIX_STARTUP_MODE RGB_MATRIX_CYCLE_LEFT_RIGHT // Sets the default mode, if none has been set
//  #define RGB_MATRIX_STARTUP_HUE 0 // Sets the default hue value, if none has been set
//  #define RGB_MATRIX_STARTUP_SAT 255 // Sets the default saturation value, if none has been set
//  #define RGB_MATRIX_STARTUP_VAL 50 // Sets the default brightness value, if none has been set
//  #define RGB_MATRIX_STARTUP_SPD 127 // Sets the default animation speed, if none has been set
#define RGB_MATRIX_HUE_STEP 4
#define RGB_MATRIX_SAT_STEP 4
#define RGB_MATRIX_VAL_STEP 4
#define RGB_MATRIX_SPD_STEP 4
//  #define RGB_MATRIX_DISABLE_KEYCODES // disables control of rgb matrix by keycodes (must use code functions to control the feature)
//  #define RGB_MATRIX_SPLIT { X, Y }     // (Optional) For split keyboards, the number of LEDs connected on each half. X = left, Y = Right.
                                        // If RGB_MATRIX_KEYPRESSES or RGB_MATRIX_KEYRELEASES is enabled, you also will want to enable SPLIT_TRANSPORT_MIRROR

#define ENABLE_RGB_MATRIX_GRADIENT_UP_DOWN
#define ENABLE_RGB_MATRIX_GRADIENT_LEFT_RIGHT
#define ENABLE_RGB_MATRIX_CYCLE_ALL
#define ENABLE_RGB_MATRIX_SOLID_REACTIVE_SIMPLE
#define ENABLE_RGB_MATRIX_SPLASH
#define RGB_MATRIX_STARTUP_MODE RGB_MATRIX_CYCLE_ALL
#endif
*/

/* OLED */
/*
#ifdef OLED_ENABLE
#    undef RP_I2C_USE_I2C0
#    define RP_I2C_USE_I2C0 FALSE
#    undef RP_I2C_USE_I2C1
#    define RP_I2C_USE_I2C1 TRUE
//#    define I2C_DRIVER I2CD2
#    define I2C1_SDA_PIN GP26
#    define I2C1_SCL_PIN GP27
#endif
*/
