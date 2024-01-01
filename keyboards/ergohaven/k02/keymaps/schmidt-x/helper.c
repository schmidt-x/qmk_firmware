#include "helper.h"

bool layer_is_default(void) {
  return !layer_state;
}

bool l_sft_matrix_is_on(void) {
	return matrix_is_on(2, 0);
}

bool r_sft_matrix_is_on(void) {
	return matrix_is_on(7, 5);
}

#ifdef HRM_ENABLE
bool hrm(bool pressed, bool *is_mod, bool left, uint8_t mods) {
	if (pressed) {
		if (left ? l_sft_matrix_is_on() : r_sft_matrix_is_on()) {
			register_mods(mods);
			*is_mod = true;
		} else {
			return true;
		}
	} else {
		if (*is_mod) {
			unregister_mods(mods);
			*is_mod = false;
		} else {
			return true;
		}
	}
	
	return false;
}
#endif