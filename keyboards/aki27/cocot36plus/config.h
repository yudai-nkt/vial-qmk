// Copyright 2022 aki27 (@aki27kbd)
// SPDX-License-Identifier: GPL-2.0-or-later

#pragma once
#define OLED_FONT_H "keyboards/aki27/cocot36plus/lib/glcdfont.c"

#define DYNAMIC_KEYMAP_LAYER_COUNT 8


/* OLED */

#ifdef OLED_ENABLE
#    undef RP_I2C_USE_I2C0
#    define RP_I2C_USE_I2C0 FALSE
#    undef RP_I2C_USE_I2C1
#    define RP_I2C_USE_I2C1 TRUE
//#    define I2C_DRIVER I2CD2
#    define I2C1_SDA_PIN GP26
#    define I2C1_SCL_PIN GP27
#endif


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

#define POINTING_DEVICE_ROTATION_90

