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

static uint8_t left_mods;
static uint8_t right_mods;

bool l_hrm(bool pressed, bool *is_hrm, uint8_t mods) {
	if (pressed) {
		if (left_mods || l_sft_matrix_is_on()) {
			register_mods(mods);
			*is_hrm = true;
			left_mods |= mods;
		} else {
			return true;
		}
	} else {
		if (*is_hrm) {
			unregister_mods(mods);
			*is_hrm = false;
			left_mods &= ~mods;
		} else {
			return true;
		}
	}
	
	return false;
}

bool r_hrm(bool pressed, bool *is_hrm, uint8_t mods) {
	if (pressed) {
		if (right_mods || r_sft_matrix_is_on()) {
			register_mods(mods);
			*is_hrm = true;
			right_mods |= mods;
		} else {
			return true;
		}
	} else {
		if (*is_hrm) {
			unregister_mods(mods);
			*is_hrm = false;
			right_mods &= ~mods;
		} else {
			return true;
		}
	}
	
	return false;
}

#endif