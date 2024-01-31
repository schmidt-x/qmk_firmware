#include "leader_hrm.h"
#include "quantum_keycodes.h"

__attribute__((weak)) const leader_hrm_t *leader_hrms = NULL;

static uint8_t hrm_mods;


bool is_leader_mod(const uint16_t keycode, const uint8_t count) {
	// uncomment, if you ever need it
	/*
	if (IS_QK_MOD_TAP(keycode)) {
		if (count)
			return false;
		
		uint8_t mods = QK_MOD_TAP_GET_MODS(keycode);
		return leader_hrms->leader_mod & (mods << (mods & 0x10 ? 4 : 0));
	} */
	
	if (IS_QK_ONE_SHOT_MOD(keycode)) {
		if (count)
			return false;
		
		uint8_t mods = QK_ONE_SHOT_MOD_GET_MODS(keycode);
		return leader_hrms->leader_mod & (mods << (mods & 0x10 ? 4 : 0));
	}
	
	return IS_MODIFIER_KEYCODE(keycode) && leader_hrms->leader_mod & MOD_BIT(keycode);
}

bool process_mods(const keyrecord_t *const record, const uint8_t shift) {
	const hrm_t *(*const mods)[3] = shift == 0
		? leader_hrms->l_mods
		: leader_hrms->r_mods;
	
	for (uint8_t i = 0; i < 3; i++) {
		const hrm_t *const hrm = (*mods)[i];
		
		if (hrm == NULL)
			break;
		
		if (hrm->col != record->event.key.col)
			continue;
		
		const uint8_t mod_mask = 1 << (i + shift);
		
		if (record->event.pressed) {
			register_mods(hrm->mod);
			hrm_mods |= mod_mask;
		} else {
			// There may be a situation where we're trying to unregister a mod that hasn't been registered before.
			// If we press hrm keys without any mod being active, press Leader mod and then release the previuosly
			// held hrm keys, we will get here, even though those hrm keys were registered as "normal" keys.
			if (!(hrm_mods & mod_mask))
				return true;
			
			unregister_mods(hrm->mod);
			hrm_mods &= ~mod_mask;
		}
		
		return false;
	}
	
	return true;
}


bool process_leader_hrm(const uint16_t keycode, const keyrecord_t *const record) {
	if (leader_hrms == NULL)
		return true;
	
	bool is_hrm_row;
	uint8_t shift;
	
#ifndef SPLIT_KEYBOARD
	if (record->event.key.col < MATRIX_COLS/2) {
#else
	if (record->event.key.row < MATRIX_ROWS/2) {
#endif
		// Check if there is any mod defined for the left side
		if (leader_hrms->l_mods == NULL)
			return true;
		
		is_hrm_row = leader_hrms->l_row == record->event.key.row;
		shift = 0;
	} else {
		// Do the same for the right side
		if (leader_hrms->r_mods == NULL)
			return true;
		
		is_hrm_row = leader_hrms->r_row == record->event.key.row;
		shift = 4;
	}
	
	if (is_leader_mod(keycode, record->tap.count)) {
		if (record->event.pressed)
			hrm_mods |= 1 << (3 + shift);
		else
			hrm_mods &= ~(1 << (3 + shift));
		
		return true;
	}
	
	if (!is_hrm_row)
		return true;
	
	// Check the layer
	if ((leader_hrms->layers & (1 << read_source_layers_cache(record->event.key))) == 0)
		return true;
	
	// Check if there is any active mod
	if ((hrm_mods & (0xF << shift)) == 0)
		return true;
	
	return process_mods(record, shift);
}