#include "helper.h"
#include "action_layer.h"
#include "action_util.h"

bool layer_is_default(void) {
	return !layer_state;
}

bool layer_is_not_default(void) {
	return layer_state;
}

bool no_mods(void) {
	return !get_mods();
}

bool handle_2key_macro(bool is_pressed, bool *state, uint8_t mods, uint8_t keycode, uint8_t alt_keycode) {
	if (is_pressed) {
		if (no_mods()) {
			add_oneshot_mods(mods);
			register_code(keycode);
			*state = true;
		} else {
			register_code(alt_keycode);
		}
	} else {
		if (*state) {
			unregister_code(keycode);
			*state = false;
		} else {
			unregister_code(alt_keycode);
		}
	}
	return false;
}