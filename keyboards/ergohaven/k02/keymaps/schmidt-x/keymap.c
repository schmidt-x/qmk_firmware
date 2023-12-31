#include QMK_KEYBOARD_H
#include "oled/ergohaven_dark.c"
#include "keymap.h"


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

	[_NORMAL] = LAYOUT(
		XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                       XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, \
		KC_ESC,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                          KC_PGUP, KC_HOME, KC_UP,   KC_END,  KC_PGDN, KC_TAB,  \
		KC_LSFT, KC_A,    HRM_S,   HRM_D,   HRM_FAL, KC_G,                          KC_BSPC, KC_LEFT, KC_DOWN, KC_RGHT, KC_DEL,  KC_LSFT, \
		XXXXXXX, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,                          KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_QUOT, XXXXXXX, \
		                  XXXXXXX, XXXXXXX, INSERT,  NORMAL,  KC_SPC,      KC_ENT,  SYMBOL,  MOUSE,   KC_F23,  KC_F24  \
	),

	[_INSERT] = LAYOUT(
		XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                       XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, \
		_______, KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                          KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    _______, \
		OSM_LSF, KC_A,    HRM_S,   HRM_D,   HRM_F,   KC_G,                          KC_H,    HRM_J,   HRM_K,   HRM_L,   KC_SCLN, OSM_LSF, \
		XXXXXXX, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,                          KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_QUOT, XXXXXXX, \
		                  XXXXXXX, XXXXXXX, INS_RMO, _______, _______,     _______, _______, _______, _______, _______ \
	),

	[_R_SYMB] = LAYOUT(
		XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                       XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, \
		KC_CAPS, KC_GRV,  CK_AT,   CK_LCBR, CK_RCBR, CK_PIPE,                       CK_ASTR, KC_1,    KC_2,    KC_3,    CK_PLUS, KC_PSCR, \
		OSM_LSF, CK_UNDS, KC_EQL,  CK_LPRN, CK_RPRN, CK_AMPR,                       KC_0,    KC_4,    KC_5,    KC_6,    KC_MINS, OSM_LSF, \
		XXXXXXX, CK_EXLM, CK_HASH, KC_LBRC, KC_RBRC, KC_SLSH,                       KC_BSLS, KC_7,    KC_8,    KC_9,    CK_QUES, XXXXXXX, \
		                  XXXXXXX, XXXXXXX, SMB_NRM, XXXXXXX, _______,     XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX \
	),

	[_L_SYMB] = LAYOUT(
		XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                       XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, \
		XXXXXXX, XXXXXXX, KC_F2,   XXXXXXX, XXXXXXX, KC_F5,                         XXXXXXX, XXXXXXX, KC_INS,  XXXXXXX, XXXXXXX, XXXXXXX, \
		XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                       XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, \
		XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                       XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, \
		                  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,     XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX \
	),

	[_MOUSE] = LAYOUT(
		XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                       XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, \
		XXXXXXX, XXXXXXX, KC_F3,   KC_F4,   KC_F5,   KC_VOLU,                       XXXXXXX, XXXXXXX, KC_MS_U, XXXXXXX, XXXXXXX, XXXXXXX, \
		KC_LSFT, XXXXXXX, KC_F6,   KC_F7,   KC_F8,   KC_VOLD,                       XXXXXXX, KC_MS_L, KC_MS_D, KC_MS_R, XXXXXXX, XXXXXXX, \
		XXXXXXX, KC_MSTP, KC_MPRV, KC_MPLY, KC_MNXT, KC_MUTE,                       XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_P0,   \
		                  XXXXXXX, XXXXXXX, INSERT,  NORMAL,  KC_BTN1,     KC_BTN2, KC_BTN3, XXXXXXX, _______, _______ \
	),

	[_SYSTEM] = LAYOUT(
		XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                       XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, \
		XXXXXXX, XXXXXXX, KO_TOGG, XXXXXXX, XXXXXXX, KC_SLEP,                       KC_PWR,  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, \
		XXXXXXX, EE_CLR,  NK_TOGG, XXXXXXX, XXXXXXX, XXXXXXX,                       XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, \
		QK_BOOT, QK_RBT,  DB_TOGG, XXXXXXX, XXXXXXX, XXXXXXX,                       XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, \
		                  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,     XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX \
	),
};

bool layer_is_default(void) {
  return !layer_state;
}

bool l_sft_matrix_is_on(void) {
	return matrix_is_on(2, 0);
}

bool r_sft_matrix_is_on(void) {
	return matrix_is_on(7, 5);
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
	switch (keycode) { // This will do most of the grunt work with the keycodes.
		case HRM_S: {
			static bool release;
			
			if (record->event.pressed) {
				if (l_sft_matrix_is_on()) {
					register_mods(MOD_BIT_LGUI);
					release = true;
				} else {
					register_code(KC_S);
				}
			} else {
				if (release) {
					unregister_mods(MOD_BIT_LGUI);
					release = false;
				} else {
					unregister_code(KC_S);
				}
			}
			
			return false;
		}
		case HRM_D: {
			static bool release;
			
			if (record->event.pressed) {
				if (l_sft_matrix_is_on()) {
					register_mods(MOD_BIT_LALT);
					release = true;
				} else {
					register_code(KC_D);
				}
			} else {
				if (release) {
					unregister_mods(MOD_BIT_LALT);
					release = false;
				} else {
					unregister_code(KC_D);
				}
			}
			
			return false;
		}
		case HRM_F: {
			static bool release;
			
			if (record->event.pressed) {
				if (l_sft_matrix_is_on()) {
					register_mods(MOD_BIT_LCTRL);
					release = true;
				} else {
					register_code(KC_F);
				}
			} else {
				if (release) {
					unregister_mods(MOD_BIT_LCTRL);
					release = false;
				} else {
					unregister_code(KC_F);
				}
			}
			
			return false;
		}
		case HRM_FAL: {
			static uint8_t state;
			
			if (record->event.pressed) {
				if (!get_mods() && !get_oneshot_mods()) {
					register_code(KC_RALT);
					tap_code(KC_TAB);
					state = 1;
				} else if (l_sft_matrix_is_on()) {
					register_mods(MOD_BIT_LCTRL);
					state = 2;
				} else {
					register_code(KC_F);
				}
			} else {
				switch (state) {
					case 1:
						unregister_code(KC_RALT);
						break;
					case 2:
						unregister_mods(MOD_BIT_LCTRL);
						break;
					default:
						unregister_code(KC_F);
						break;
				}
				state = 0;
			}
			return false;
		}
		case KC_LEFT: {
			static bool release;
			
			if (record->event.pressed) {
				if (r_sft_matrix_is_on()) {
					register_mods(MOD_BIT_LCTRL);
					release = true;
				} else {
					return true;
				}
			} else {
				if (release) {
					unregister_mods(MOD_BIT_LCTRL);
					release = false;
				} else {
					return true;
				}
			}
			
			return false;
		}
		case KC_DOWN: {
			static bool release;
			
			if (record->event.pressed) {
				if (r_sft_matrix_is_on()) {
					register_mods(MOD_BIT_LALT);
					release = true;
				} else {
					return true;
				}
			} else {
				if (release) {
					unregister_mods(MOD_BIT_LALT);
					release = false;
				} else {
					return true;
				}
			}
			
			return false;
		}
		case KC_RGHT: {
			static bool release;
			
			if (record->event.pressed) {
				if (r_sft_matrix_is_on()) {
					register_mods(MOD_BIT_LGUI);
					release = true;
				} else {
					return true;
				}
			} else {
				if (release) {
					unregister_mods(MOD_BIT_LGUI);
					release = false;
				} else {
					return true;
				}
			}
			
			return false;
		}
		case HRM_J: {
			static bool release;
			
			if (record->event.pressed) {
				if (r_sft_matrix_is_on()) {
					register_mods(MOD_BIT_LCTRL);
					release = true;
				} else {
					register_code(KC_J);
				}
			} else {
				if (release) {
					unregister_mods(MOD_BIT_LCTRL);
					release = false;
				} else {
					unregister_code(KC_J);
				}
			}
			
			return false;
		}
		case HRM_K: {
			static bool release;
			
			if (record->event.pressed) {
				if (r_sft_matrix_is_on()) {
					register_mods(MOD_BIT_LALT);
					release = true;
				} else {
					register_code(KC_K);
				}
			} else {
				if (release) {
					unregister_mods(MOD_BIT_LALT);
					release = false;
				} else {
					unregister_code(KC_K);
				}
			}
			
			return false;
		}
		case HRM_L: {
			static bool release;
			
			if (record->event.pressed) {
				if (r_sft_matrix_is_on()) {
					register_mods(MOD_BIT_LGUI);
					release = true;
				} else {
					register_code(KC_L);
				}
			} else {
				if (release) {
					unregister_mods(MOD_BIT_LGUI);
					release = false;
				} else {
					unregister_code(KC_L);
				}
			}

			return false;
		}
		case NORMAL: {
			static bool symbol;
			
			if (record->event.pressed) {
				if (get_mods()) {
					layer_on(_L_SYMB);
					symbol = true;
				} else {
					if (layer_is_default())
						tap_code(KC_F13);
					else
						layer_clear();
				}
			} else {
				if (symbol) {
					layer_off(_L_SYMB);
					symbol = false;
				}
			}
			
			return false;
		}
		case INSERT:
			if (record->event.pressed)
				layer_state_set(1 << _INSERT);

			return false;
		
		case INS_RMO: // reversed MO
			if (record->event.pressed) {
				layer_off(_INSERT);
			} else {
				if (layer_is_default())
					layer_on(_INSERT);
			}
			return false;
			
		case MOUSE:
			if (record->event.pressed)
				layer_on(_MOUSE);
      
			return false;
		
		case SMB_NRM: {
			static bool should;
			static layer_state_t mask = (1 << _INSERT) | (1 << _R_SYMB);
			
			if (record->event.pressed) {
				if (layer_state != mask)
					return false;
				
				layer_clear();
				should = true;
			} else {
				if (!should)
					return false;
				
				if (matrix_is_on(9, 1))
					layer_state_set(mask);
				else
					layer_on(_INSERT);
				
				should = false;
			}
			return false;
		}
		case KC_ESC:
			if (!record->event.pressed)
				return true;
			
			if (!layer_is_default())
				layer_clear();
			
			if (get_oneshot_mods())
				clear_oneshot_mods();
			
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
	
	uint8_t prev_oneshot_mods = get_oneshot_mods();
	if (prev_oneshot_mods)
		clear_oneshot_mods();

	switch (get_highest_layer(state)) {
		case _NORMAL:
			tap_code(KC_F13); // turn on Normal mode in AHK
			break;

		case _INSERT:
			tap_code(KC_F14); // turn on Insert mode in AHK
			break;
		
		case _R_SYMB:
		case _L_SYMB:
			tap_code(KC_F15); // turn on Symbol mode in AHK
			break;

		case _MOUSE:
			tap_code(KC_F16); // turn on Mouse mode in AHK
			break;
	}
	
	if (prev_mods)
		set_mods(prev_mods);
	
	if (prev_oneshot_mods)
		set_oneshot_mods(prev_oneshot_mods);
	
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
		case _R_SYMB:
			oled_write_P(PSTR("R_SYM"), false);
			break;
		case _L_SYMB:
			oled_write_P(PSTR("L_SYM"), false);
			break;
		case _MOUSE:
			oled_write_P(PSTR("MOUSE"), false);
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
