#include QMK_KEYBOARD_H

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
	[0] = LAYOUT(
		KC_ESC,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                          KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSPC,
		KC_TAB,  KC_A,    KC_S,    KC_D,    KC_F,    KC_G,                          KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_RGUI,
		KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_LBRC,     KC_RBRC, KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_QUOT, KC_RSFT,
		                                    KC_LCTL, XXXXXXX, KC_SPC,      KC_ENT,  XXXXXXX, KC_RALT
	),
};


#ifdef OLED_ENABLE

oled_rotation_t oled_init_user(oled_rotation_t rotation) {
	if (is_keyboard_master()) {
		return OLED_ROTATION_270;
	} else {
		return OLED_ROTATION_180;
	}
	
	return rotation;
}

void render_layer_state(void) {
	
}

// Used to draw on to the oled screen
bool oled_task_user(void) {
	return false;
}

#endif