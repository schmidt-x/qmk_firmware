#include QMK_KEYBOARD_H
#include "keymap.h"
#include "helper.h"


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

	[_NORMAL] = LAYOUT(
		XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                       XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, \
		KC_ESC,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                          KC_PGUP, KC_HOME, KC_UP,   KC_END,  KC_PGDN, KC_TAB,  \
		KC_LSFT, KC_A,    KC_S,    KC_D,    F_ALTAB, KC_G,                          KC_BSPC, KC_LEFT, KC_DOWN, KC_RGHT, KC_DEL,  KC_LSFT, \
		KC_LCTL, Z_UNDO,  X_REDO,  KC_C,    KC_V,    KC_B,                          KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_QUOT, KC_LCTL, \
		                  XXXXXXX, XXXXXXX, INSERT,  NORMAL,  KC_SPC,      KC_ENT,  SYMBOL,  MOUSE,   KC_F23,  KC_F24  \
	),

	[_INSERT] = LAYOUT(
		XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                       XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, \
		_______, KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                          KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    _______, \
		OSM_LSF, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,                          KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, OSM_LSF, \
		OSM_LCT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,                          KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_QUOT, OSM_LCT, \
		                  XXXXXXX, XXXXXXX, INS_RMO, _______, _______,     _______, _______, _______, _______, _______ \
	),

	[_SYMBOL] = LAYOUT(
		XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                       XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, \
		KC_CAPS, KC_GRV,  CK_AT,   CK_LCBR, CK_RCBR, CK_PIPE,                       CK_ASTR, KC_1,    KC_2,    KC_3,    CK_PLUS, KC_PSCR, \
		KC_LSFT, CK_UNDS, KC_EQL,  CK_LPRN, CK_RPRN, CK_AMPR,                       KC_0,    KC_4,    KC_5,    KC_6,    KC_MINS, KC_LSFT, \
		OSM_LCT, CK_EXLM, CK_HASH, KC_LBRC, KC_RBRC, KC_SLSH,                       KC_BSLS, KC_7,    KC_8,    KC_9,    CK_QUES, OSM_LCT, \
		                  XXXXXXX, XXXXXXX, SMB_NRM, U_SYMBL, _______,     XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX \
	),

	[_U_SYMB] = LAYOUT(
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


bool process_record_user(uint16_t keycode, keyrecord_t *record) {

#ifdef LEADER_HRM_ENABLE
	if (!process_leader_hrm(keycode, record))
		return false;
#endif
	
	switch (keycode) { // This will do most of the grunt work with the keycodes.

		case Z_UNDO:
			if (record->event.pressed) {
				if (!get_mods()) {
					add_oneshot_mods(MOD_BIT_LCTRL);
				}
				register_code(KC_Z);
			} else {
				unregister_code(KC_Z);
			}

			return false;
		
		case X_REDO: {
			static bool is_redo;

			if (record->event.pressed) {
				if (!get_mods()) {
					add_mods(MOD_BIT_LCTRL);
					register_code(KC_Y);
					is_redo = true;
				} else {
					register_code(KC_X);
				}
			} else {
				if (is_redo) {
					del_mods(MOD_BIT_LCTRL);
					unregister_code(KC_Y);
					is_redo = false;
				} else {
					unregister_code(KC_X);
				}
			}

			return false;
		}

		case F_ALTAB: {
			static bool is_alt_tab;
			
			if (record->event.pressed) {
				if (!get_mods()) {
					add_mods(MOD_BIT_LALT);
					tap_code(KC_TAB);
					is_alt_tab = true;
				} else {
					register_code(KC_F);
				}
			} else {
				if (is_alt_tab) {
					unregister_mods(MOD_BIT_LALT);
					is_alt_tab = false;
				} else {
					unregister_code(KC_F);
				}
			}

			return false;
		}
		
		case NORMAL: {
			if (!record->event.pressed)
				return false;

			if (layer_is_default())
				tap_code(KC_F13);
			else
				layer_clear();
			
			return false;
		}

		case INSERT:
			if (record->event.pressed)
				layer_state_set(1 << _INSERT);

			return false;
		
		case INS_RMO:
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
			static layer_state_t mask = (1 << _INSERT) | (1 << _SYMBOL);
			
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
			if (!record->event.pressed) {
				return true;
			}
			
			if (!get_mods() && !layer_is_default()) {
				layer_clear();
			}
			
			clear_oneshot_mods();
			return true;

		default:
			return true; // Process all other keycodes normally
	}
}


// callback on layer change
layer_state_t layer_state_set_user(layer_state_t state) {
	clear_oneshot_mods();

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
	
	return state;	
}


// Caps Word
bool caps_word_press_user(uint16_t keycode) {
	switch (keycode) {
		case KC_A ... KC_Z:
			add_weak_mods(MOD_BIT_LSHIFT);
			return true;
		
		case KC_1 ... KC_0:
		case KC_BSPC:
		case KC_DEL:
		case CK_UNDS: // right shifted
			return true;
		
		default:
			return false;
	}
}

// TODO:
// void caps_word_set_user(bool active) {
	// if (active)
		
	// else
		
// }


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
		case _U_SYMB:
			oled_write_P(PSTR("SYMB+"), false);
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
