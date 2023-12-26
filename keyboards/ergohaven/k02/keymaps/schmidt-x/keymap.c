#include QMK_KEYBOARD_H
#include "oled/ergohaven_dark.c"
#include "keymap.h"


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

	[_NORMAL] = LAYOUT(
		KC_ESC,  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                       XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_CAPS, \
		KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                          KC_PGUP, KC_HOME, KC_UP,   KC_END,  KC_PGDN, KC_PSCR, \
		OSM_LSF, KC_A,    KC_S,    KC_D,    F_ALTAB, KC_G,                          KC_BSPC, KC_LEFT, KC_DOWN, KC_RGHT, KC_DEL,  OSM_LSF, \
		OSM_LCT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,                          KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_QUOT, OSM_LCT, \
		                  KC_LWIN, KC_LALT, INSERT,  KC_F13,  KC_SPC,      KC_ENT,  SYMBOL,  MOUSE,   KC_F23,  KC_F24  \
	),

	[_INSERT] = LAYOUT(
		_______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                       XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______, \
		_______, KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                          KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    _______, \
		_______, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,                          KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, _______, \
		_______, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,                          KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_QUOT, _______, \
		                  _______, _______, INS_RMO, NORMAL,  _______,     _______, _______, _______, _______, _______ \
	),

	[_SYMBOL] = LAYOUT(
		XXXXXXX, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,                         XXXXXXX, XXXXXXX, KC_INS,  XXXXXXX, XXXXXXX, XXXXXXX, \
		XXXXXXX, KC_GRV,  CK_AT,   CK_LCBR, CK_RCBR, CK_PIPE,                       CK_ASTR, KC_1,    KC_2,    KC_3,    CK_PLUS, XXXXXXX, \
		_______, CK_UNDS, KC_EQL,  CK_LPRN, CK_RPRN, CK_AMPR,                       KC_0,    KC_4,    KC_5,    KC_6,    KC_MINS, _______, \
		_______, CK_EXLM, CK_HASH, KC_LBRC, KC_RBRC, KC_SLSH,                       KC_BSLS, KC_7,    KC_8,    KC_9,    CK_QUES, _______, \
		                  XXXXXXX, XXXXXXX, SMB_NRM, XXXXXXX, _______,     XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX \
	),

	[_MOUSE] = LAYOUT(
		_______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                       XXXXXXX, XXXXXXX,  KC_P1,   KC_P2,  KC_P3,   KC_P4,   \
		XXXXXXX, XXXXXXX, KC_F3,   KC_F4,   KC_F5,   KC_VOLU,                       XXXXXXX, XXXXXXX, KC_MS_U, XXXXXXX, KC_P5,   KC_P6,   \
		KC_LSFT, XXXXXXX, KC_F6,   KC_F7,   KC_F8,   KC_VOLD,                       XXXXXXX, KC_MS_L, KC_MS_D, KC_MS_R, KC_P7,   KC_P8,   \
		XXXXXXX, KC_MSTP, KC_MPRV, KC_MPLY, KC_MNXT, KC_MUTE,                       XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_P9,   KC_P0,   \
		                  KC_LWIN, XXXXXXX, INSERT,  NORMAL,  KC_BTN1,     KC_BTN2, KC_BTN3, XXXXXXX, _______, _______ \
	),

	[_SYSTEM] = LAYOUT(
		XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_SLEP,                       KC_PWR,  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, \
		XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                       XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, \
		XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                       XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, \
		NK_TOGG, DB_TOGG, XXXXXXX, XXXXXXX, KO_TOGG, CM_TOGG,                       XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, \
		                  QK_BOOT, QK_RBT,  EE_CLR,  XXXXXXX, XXXXXXX,     XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX \
	),

};


bool process_record_user(uint16_t keycode, keyrecord_t *record) {
	switch (keycode) { // This will do most of the grunt work with the keycodes.
		case F_ALTAB: {
			static bool is_F_registered;
			
			if (record->event.pressed) {
				if (get_oneshot_mods() || get_mods()) { // if any modifier is used, act as normal F key
					register_code(KC_F);
					is_F_registered = true;
				} else {
					register_code(KC_LALT);
					tap_code(KC_TAB);
				}
			} else {
				if (is_F_registered) {
					unregister_code(KC_F);
					is_F_registered = false;
				} else {
					unregister_code(KC_LALT);
				}
			}
			return false;
		}
		case NORMAL:
			if (record->event.pressed && layer_state) {
				// No need to explicitly set _NORMAL since it's the default layer.
				// But not present in layer_state (i.e., layer_state == 0b0..0_00000000 even though _NORMAL is on).
				// If explicity set _NORMAL, layer_state == 0b0..0_00000001 (i.e, _default(_NORNAL) + _NORMAL)
				layer_clear();
			}
			return false;
		
		case INSERT:
			if (record->event.pressed) {
				layer_state_set(1 << _INSERT);
			}
			return false;
		
		case INS_RMO: // reversed MO
			if (record->event.pressed) {
				layer_off(_INSERT);
			} else {
				if (!layer_state)
					layer_on(_INSERT);
			}
			return false;
			
		case MOUSE:
			if (record->event.pressed) { 
				layer_on(_MOUSE);
			}
			return false;
		
		case SMB_NRM: {
			static bool should;
			static layer_state_t mask = (1 << _INSERT) | (1 << _SYMBOL);
			
			if (record->event.pressed) {
				if (layer_state != mask) return false;
				
				layer_clear();
				should = true;
			} else {
				if (!should) return false;
				
				if (matrix_is_on(9, 1)) {
					layer_state_set(mask);
				} else {
					layer_on(_INSERT);
				}
				
				should = false;
			}
			return false;
		}
		case KC_ESC:
			if (!record->event.pressed)
				return true;
			
			if (layer_state)
				layer_clear();
			else if (get_oneshot_mods()) {
				clear_oneshot_mods();
			}
			
			return true;

		default:
			return true; // Process all other keycodes normally
	}
}


// callback on layer change
layer_state_t layer_state_set_user(layer_state_t state) {
	uint8_t prev_mods = get_mods();
	if (prev_mods)
		clear_mods();
	
	if (get_oneshot_mods()) {
		clear_oneshot_mods();
	}
	
	switch (get_highest_layer(state)) {
		case _NORMAL:
			tap_code(KC_F13); // turn on Normal mode in AHK
			break;

		case _INSERT:
			tap_code(KC_F14); // turn on Insert mode in AHK
			break;
		
		case _SYMBOL:
			tap_code(KC_F15); // turn on Symbol mode in AHK
			break;

		case _MOUSE:
			tap_code(KC_F16); // turn on Mouse mode in AHK
			break;
	}
	
	if (prev_mods)
		set_mods(prev_mods);
	
	return state;	
}


// void matrix_scan_user(void) { // The very important timer.
	
// }


#ifdef OLED_ENABLE

oled_rotation_t oled_init_user(oled_rotation_t rotation) {
	if (is_keyboard_master())
		return OLED_ROTATION_270; 
	// else
		// return OLED_ROTATION_180;
	
	return rotation;
}

void render_layer_state(void) {
	oled_write_ln_P(PSTR("K:02\n"), false);

	if (keymap_config.swap_lctl_lgui) {
		oled_write_ln_P(PSTR("Mac\n\n"), false);
	} else {
		oled_write_ln_P(PSTR("Win\n\n"), false);
	}

	oled_write_ln_P(PSTR("MODE\n"), false);

	switch (get_highest_layer(layer_state)) {
		case _NORMAL:
			oled_write_P(PSTR("NORML"), false);
			break;
		case _INSERT:
			oled_write_P(PSTR("INSRT"), false);
			break;
		case _SYMBOL:
			oled_write_P(PSTR("SYMB\n"), false);
			break;
		case _MOUSE:
			oled_write_P(PSTR("MOUSE"), false);
			break;
		case _FOUR:
			oled_write_P(PSTR("4\n"), false);
			break;
		case _FIVE:
			oled_write_P(PSTR("5\n"), false);
			break;
		case _SIX:
			oled_write_P(PSTR("6\n"), false);
			break;
		case _SEVEN:
			oled_write_P(PSTR("7\n"), false);
			break;
		case _EIGHT:
			oled_write_P(PSTR("8\n"), false);
			break;
		case _NINE:
			oled_write_P(PSTR("9\n"), false);
			break;
		case _TEN:
			oled_write_P(PSTR("10\n"), false);
			break;
		case _ELEVEN:
			oled_write_P(PSTR("11\n"), false);
			break;
		case _TWELVE:
			oled_write_P(PSTR("12\n"), false);
			break;
		case _THIRTEEN:
			oled_write_P(PSTR("13\n"), false);
			break;
		case _FOURTEEN:
			oled_write_P(PSTR("14\n"), false);
			break;
		case _SYSTEM:
			oled_write_P(PSTR("SYSTM"), false);
			break;
		default:
			oled_write_ln_P(PSTR("Undef"), false);
	}
	
	oled_write_ln_P(PSTR("\n"), false);
	
	if (debug_config.enable)
		oled_write_ln_P(PSTR("DEBUG"), false);
	else
		oled_write_ln_P(PSTR("\n"), false);
	
	if (keymap_config.nkro)
		oled_write_ln_P(PSTR("NKRO\n"), false);
	else
		oled_write_ln_P(PSTR("6KRO\n"), false);

	led_t led_usb_state = host_keyboard_led_state();
	oled_write_P(PSTR("CPSLK"), led_usb_state.caps_lock);
}

// Used to draw on to the oled screen
bool oled_task_user(void) {
	if (is_keyboard_master())
		render_layer_state();
	// else
	//	ergohaven_dark_draw();
	
	return false;
}

#endif
