#define DYNAMIC_KEYMAP_LAYER_COUNT 16
#define DYNAMIC_KEYMAP_MACRO_COUNT 109

#define RP2040_BOOTLOADER_DOUBLE_TAP_RESET // Activates the double-tap behavior
#define RP2040_BOOTLOADER_DOUBLE_TAP_RESET_TIMEOUT 200U // Timeout window in ms in which the double tap can occur.
#define RP2040_BOOTLOADER_DOUBLE_TAP_RESET_LED_MASK 0U // Specify a optional status led which blinks when entering the bootloader

#define HOLD_ON_OTHER_KEY_PRESS
#define FORCE_NKRO

#define DOUBLE_TAP_SHIFT_TURNS_ON_CAPS_WORD

// #undef PRINTF_SUPPORT_DECIMAL_SPECIFIERS
// #define PRINTF_SUPPORT_DECIMAL_SPECIFIERS 1