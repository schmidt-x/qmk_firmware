#pragma once

#define RP2040_BOOTLOADER_DOUBLE_TAP_RESET // Activates the double-tap behavior
#define RP2040_BOOTLOADER_DOUBLE_TAP_RESET_TIMEOUT 200U // Timeout window in ms in which the double tap can occur.
#define RP2040_BOOTLOADER_DOUBLE_TAP_RESET_LED_MASK 0U // Specify a optional status led which blinks when entering the bootloader

#define BOOTMAGIC_ROW          0
#define BOOTMAGIC_COLUMN       5
#define BOOTMAGIC_ROW_RIGHT    4
#define BOOTMAGIC_COLUMN_RIGHT 5

/* Serial settings */
#define SERIAL_USART_FULL_DUPLEX
#define SERIAL_USART_TX_PIN GP0
#define SERIAL_USART_RX_PIN GP1

#define SPLIT_HAND_PIN GP29
#define SPLIT_WATCHDOG_ENABLE

#ifdef OLED_ENABLE
#    define OLED_DISPLAY_128X32
#    define I2C1_SCL_PIN GP3
#    define I2C1_SDA_PIN GP2
#    define OLED_BRIGHTNESS 128
#    define I2C_DRIVER I2CD1

#    define SPLIT_LAYER_STATE_ENABLE
#    define SPLIT_LED_STATE_ENABLE
#    define SPLIT_MODS_ENABLE
// #    define SPLIT_OLED_ENABLE
#endif

#ifdef RGBLIGHT_ENABLE
#    define RGBLED_NUM 2 // ?
#    define RGBLED_SPLIT {1, 1}
#    define RGBLIGHT_SLEEP
#    define RGBLIGHT_SPLIT
#    define RGBLIGHT_LAYERS
#    define RGBLIGHT_MAX_LAYERS 16
#    define RGBLIGHT_LAYERS_RETAIN_VAL
#    define RGBLIGHT_DEFAULT_VAL 150
#    define RGBLIGHT_LIMIT_VAL 150
#    define RGBLIGHT_DEFAULT_SAT 0
#endif