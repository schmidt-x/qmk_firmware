#include QMK_KEYBOARD_H
#include "keymap.h"
#include "helper.h"

#ifdef RAW_ENABLE
#    include "raw_hid.h"
#    include "hid.h"
#endif


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
	[_NORMAL] = LAYOUT(
		KC_ESC,  KC_W,    KC_L,    KC_Y,    KC_P,    KC_B,                          KC_PGUP, KC_HOME, KC_UP,   KC_END,  KC_PGDN, KC_TAB,
		KC_LSFT, KC_C,    R_SELCT, S_SAVE,  T_ALTAB, KC_G,                          KC_BSPC, KC_LEFT, KC_DOWN, KC_RGHT, KC_DEL,  KC_LSFT,
		KC_LCTL, Q_UNDO,  J_REDO,  KC_V,    D_CLIPB, KC_K,    KC_F23,      KC_F24,  KC_X,    KC_H,    KC_COMM, KC_DOT,  KC_QUOT, KC_LCTL,
		                                    INSERT,  NORMAL,  KC_SPC,      KC_ENT,  SYMBOL,  MOUSE
	),

	[_INSERT] = LAYOUT( // Canary (mod)
		KC_ESC,  KC_W,    KC_L,    KC_Y,    KC_P,    KC_B,                          KC_Z,    KC_F,    KC_O,    KC_U,    KC_SCLN, KC_TAB,
		OSM_LSF, KC_C,    KC_R,    KC_S,    KC_T,    KC_G,                          KC_M,    KC_N,    KC_E,    KC_I,    KC_A,    OSM_LSF,
		OSM_LCT, KC_Q,    KC_J,    KC_V,    KC_D,    KC_K,    _______,     _______, KC_X,    KC_H,    KC_COMM, KC_DOT,  KC_QUOT, OSM_LCT,
		                                    INS_RMO, _______, _______,     _______, _______, _______
	),

	[_SELECT] = LAYOUT(
		KC_ESC,  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                       SL_PGUP, SL_HOME, SL_UP,   SL_END,  SL_PGDN, KC_TAB,
		KC_LSFT, XXXXXXX, XXXXXXX, XXXXXXX, T_ALTAB, XXXXXXX,                       KC_BSPC, SL_LEFT, SL_DOWN, SL_RGHT, KC_DEL,  KC_LSFT,
		KC_LCTL, Q_UNDO,  J_CUT,   V_COPY,  D_PASTE, XXXXXXX, _______,     _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_LCTL,
		                                    INSERT,  _______, _______,     _______, _______, _______
	),

	[_SYMBOL] = LAYOUT(
		KC_CAPS, KC_GRV,  CK_AT,   CK_LCBR, CK_RCBR, CK_PIPE,                       CK_ASTR, KC_1,    KC_2,    KC_3,    CK_PLUS, KC_PSCR,
		KC_LSFT, CK_UNDS, KC_EQL,  CK_LPRN, CK_RPRN, CK_AMPR,                       KC_0,    KC_4,    KC_5,    KC_6,    KC_MINS, KC_LSFT,
		OSM_LCT, CK_EXLM, CK_HASH, KC_LBRC, KC_RBRC, KC_SLSH, XXXXXXX,     XXXXXXX, KC_BSLS, KC_7,    KC_8,    KC_9,    CK_QUES, OSM_LCT,
		                                    SMB_NRM, U_SYMBL, _______,     XXXXXXX, XXXXXXX, XXXXXXX
	),

	[_U_SYMB] = LAYOUT(
		XXXXXXX, XXXXXXX, KC_F2,   XXXXXXX, XXXXXXX, KC_F5,                         XXXXXXX, XXXXXXX, KC_INS,  KC_APP,  XXXXXXX, XXXXXXX,
		XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                       XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
		XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,     XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
		                                    XXXXXXX, XXXXXXX, XXXXXXX,     XXXXXXX, XXXXXXX, XXXXXXX
	),

	[_MOUSE] = LAYOUT(
		KC_ESC,  MS_ACL2, KC_F3,   KC_F4,   KC_F5,   KC_VOLU,                       XXXXXXX, XXXXXXX, MS_UP,   XXXXXXX, XXXXXXX, XXXXXXX,
		KC_LSFT, MS_ACL0, KC_F6,   KC_F7,   KC_F8,   KC_VOLD,                       XXXXXXX, MS_LEFT, MS_DOWN, MS_RGHT, XXXXXXX, KC_LSFT,
		XXXXXXX, KC_MSTP, KC_MPRV, KC_MPLY, KC_MNXT, KC_MUTE, _______,     _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_P0,
		                                    INSERT,  NORMAL,  MS_BTN1,     MS_BTN2, MS_BTN3, XXXXXXX
	),

	[_SYSTEM] = LAYOUT(
		XXXXXXX, XXXXXXX, KO_TOGG, XXXXXXX, XXXXXXX, KC_SLEP,                       KC_PWR,  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
		XXXXXXX, EE_CLR,  NK_TOGG, AHK_TG,  XXXXXXX, XXXXXXX,                       XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
		QK_BOOT, QK_RBT,  DB_TOGG, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,     XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
		                                    XXXXXXX, XXXXXXX, XXXXXXX,     XXXXXXX, XXXXXXX, XXXXXXX
	),
};


bool process_record_user(uint16_t keycode, keyrecord_t *record) {

#ifdef LEADER_HRM_ENABLE
	if (!process_leader_hrm(keycode, record)) {
		return false;
	}
#endif
	
	switch (keycode) { // This will do most of the grunt work with the keycodes.

		case D_CLIPB: {
			static bool is_clipboard;
			
			if (record->event.pressed) {
				if (no_mods()) {
					add_mods(MOD_BIT_RGUI);
					register_code(KC_V);
					is_clipboard = true;
				} else {
					register_code(KC_D);
				}
			} else {
				if (is_clipboard) {
					del_mods(MOD_BIT_RGUI);
					unregister_code(KC_V);
					is_clipboard = false;
				} else {
					unregister_code(KC_D);
				}
			}
			
			return false;
		}

		case S_SAVE: {
			if (record->event.pressed) {
				if (no_mods()) {
					add_oneshot_mods(MOD_BIT_RCTRL);
				}
				register_code(KC_S);
			} else {
				unregister_code(KC_S);
			}

			return false;
		}

		case Q_UNDO: {
			static bool is_undo;

			if (record->event.pressed) {
				if (no_mods()) {
					add_mods(MOD_BIT_RCTRL);
					register_code(KC_Z);
					is_undo = true;
				} else {
					register_code(KC_Q);
				}
			} else {
				if (is_undo) {
					del_mods(MOD_BIT_RCTRL);
					unregister_code(KC_Z);
					is_undo = false;
				} else {
					unregister_code(KC_Q);
				}
			}

			return false;
		}
		
		case J_REDO: {
			static bool is_redo;

			if (record->event.pressed) {
				if (no_mods()) {
					add_mods(MOD_BIT_RCTRL);
					register_code(KC_Y);
					is_redo = true;
				} else {
					register_code(KC_J);
				}
			} else {
				if (is_redo) {
					del_mods(MOD_BIT_RCTRL);
					unregister_code(KC_Y);
					is_redo = false;
				} else {
					unregister_code(KC_J);
				}
			}

			return false;
		}

		case J_CUT: {
			static bool is_cut;
			
			if (record->event.pressed) {
				if (no_mods()) {
					add_oneshot_mods(MOD_BIT_RCTRL);
					register_code(KC_X);
					is_cut = true;
				} else {
					register_code(KC_J);
				}
			} else {
				if (is_cut) {
					unregister_code(KC_X);
					is_cut = false;
				} else {
					unregister_code(KC_J);
				}
			}
			
			return false;
		}
		
		case V_COPY: {
			static bool is_copy;
			
			if (record->event.pressed) {
				if (no_mods()) {
					add_oneshot_mods(MOD_BIT_RCTRL);
					register_code(KC_C);
					is_copy = true;
				} else {
					register_code(KC_V);
				}
			} else {
				if (is_copy) {
					unregister_code(KC_C);
					is_copy = false;
				} else {
					unregister_code(KC_V);
				}
			}
			
			return false;
		}
		
		case D_PASTE: {
			static bool is_paste;
			
			if (record->event.pressed) {
				if (no_mods()) {
					add_oneshot_mods(MOD_BIT_RCTRL);
					register_code(KC_V);
					is_paste = true;
				} else {
					register_code(KC_D);
				}
			} else {
				if (is_paste) {
					unregister_code(KC_V);
					is_paste = false;
				} else {
					unregister_code(KC_D);
				}
			}
			
			return false;
		}

		case T_ALTAB: {
			static bool is_alt_tab;
			
			if (record->event.pressed) {
				if (no_mods()) {
					add_mods(MOD_BIT_RALT);
					tap_code(KC_TAB);
					is_alt_tab = true;
				} else {
					register_code(KC_T);
				}
			} else {
				if (is_alt_tab) {
					unregister_mods(MOD_BIT_RALT);
					is_alt_tab = false;
				} else {
					unregister_code(KC_T);
				}
			}

			return false;
		}
		
		case NORMAL:
			if (record->event.pressed) {
				layer_clear();
			}
			return false;
		
		case INS_RMO:
			if (record->event.pressed) {
				layer_off(_INSERT);
			} else {
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
			layer_state_t layer_mask = (1 << _INSERT) | (1 << _SYMBOL);
			
			if (record->event.pressed) {
				if (layer_state != layer_mask) {
					return false;
				}
				
				layer_clear();
				should = true;
			} else {
				if (!should) {
					return false;
				}
				
				if (matrix_is_on(7, 2)) {
					layer_state_set(layer_mask);
				} else {
					layer_on(_INSERT);
				}
				
				should = false;
			}
			return false;
		}

		case R_SELCT: {
			static bool is_select;
		
			if (record->event.pressed) {
				if (no_mods()) {
					layer_on(_SELECT);
					is_select = true;
				} else {
					register_code(KC_R);
				}
			} else {
				if (is_select) {
					is_select = false;
				} else {
					unregister_code(KC_R);
				}
			}
			
			return false;
		}
		
		case AHK_TG:
			if (record->event.pressed) {
				ahk_enabled = !ahk_enabled;
			}
			return false;

		case KC_ESC:
			if (!record->event.pressed) {
				return true;
			}
			
			if (no_mods() && layer_is_not_default()) {
				layer_clear();
			}
			
			clear_oneshot_mods();
			return true;

		default:
			return true; // Process all other keycodes normally
	}
}


#ifdef RAW_ENABLE

void raw_hid_receive(uint8_t *data, uint8_t length) {
	uint8_t id = data[0];
	
	switch (id) {
		case HID_AHK:
			hid_handle_ahk(data[1], &ahk_enabled);
			return;
		
		case HID_PING:
			hid_handle_ping(data, length);
			return;
		
		default:
			return;
	}
}

#endif


// void suspend_wakeup_init_user(void) {
	// soft_reset_keyboard();
// }


// callback on layer change
layer_state_t layer_state_set_user(layer_state_t state) {
	clear_oneshot_mods();
	
	if (!ahk_enabled) {
		return state;
	}
	
	switch (get_highest_layer(state)) {
		case _NORMAL:
			tap_code(KC_F13); // turn on Normal mode in AHK
			break;

		case _INSERT:
			tap_code(KC_F14); // turn on Insert mode in AHK
			break;

		case _SELECT:
			tap_code(KC_F17); // turn on Select mode in AHK
			break;

		case _SYMBOL:
			tap_code(KC_F15); // turn on Symbol mode in AHK
			break;

		case _MOUSE:
			tap_code(KC_F16); // turn on Mouse mode in AHK
			break;
	}
	
	return state;	
}


#ifdef CAPS_WORD_ENABLE

bool caps_word_press_user(uint16_t keycode) {
	switch (keycode) {
		case KC_A ... KC_Z:
			add_weak_mods(MOD_BIT_LSHIFT);
			return true;
		
		case KC_1 ... KC_0:
		case KC_BSPC:
		case KC_DEL:
		case KC_MINS:
		case CK_UNDS: // right shifted
			return true;
		
		default:
			return false;
	}
}

// TODO:
// void caps_word_set_user(bool active) {
	// if (active) {
		
	// } else {
		
	// }
// }

#endif


// void matrix_scan_user(void) { // The very important timer.
	
// }


#ifdef OLED_ENABLE

oled_rotation_t oled_init_user(oled_rotation_t rotation) {
	return OLED_ROTATION_270;
}

void render_layer_state(void) {
	oled_write_ln_P(PSTR("\ni44\n"), false);

	if (keymap_config.swap_lctl_lgui) {
		oled_write_ln_P(PSTR("Mac\n\n"), false);
	} else {
		oled_write_ln_P(PSTR("Win\n\n"), false);
	}

	switch (get_highest_layer(layer_state)) {
		case _NORMAL:
			oled_write_P(PSTR("NORML"), false);
			break;
		case _INSERT:
			oled_write_P(PSTR("INSRT"), false);
			break;
		case _SELECT:
			oled_write_P(PSTR("SELCT"), false);
			break;
		case _SYMBOL:
			oled_write_P(PSTR("SYMB\n"), false);
			break;
		case _U_SYMB:
			oled_write_P(PSTR("SYMB+"), false);
			break;
		case _MOUSE:
			oled_write_P(PSTR("MOUSE"), false);
			break;
		case _SYSTEM:
			oled_write_P(PSTR("SYSTM"), false);
			break;
		default:
			oled_write_P(PSTR("Undef"), false);
	}
	
	if (ahk_enabled) {
		oled_write_ln_P(PSTR("\nAHK\n"), false);
	} else {
		oled_write_ln_P(PSTR("\n\n"), false);
	}
	
	if (!debug_config.enable) {
		oled_write_P(PSTR("\n"), false);
	}
	
	if (keymap_config.nkro) {
		oled_write_ln_P(PSTR("NKRO\n"), false);
	} else {
		oled_write_ln_P(PSTR("6KRO\n"), false);
	}
	
	led_t led_usb_state = host_keyboard_led_state();
	oled_write_P(PSTR("CPSLK\n"), led_usb_state.caps_lock);

	if (debug_config.enable) {
		oled_write_ln_P(PSTR("DEBUG"), false);
	} else {
		oled_write_ln_P(PSTR("\n"), false);
	}
}

// Used to draw on to the oled screen
bool oled_task_user(void) {
	if (is_keyboard_master()) {
		render_layer_state();
	} else {
		oled_off();
	}
	
	return false;
}

#endif