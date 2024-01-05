#include "leader_hrm.h"
#include "quantum_keycodes.h"

__attribute__((weak)) const leader_hrm_t *leader_hrms = NULL;

static uint8_t hrm_mods;


bool is_leader_mod(const uint16_t keycode) {
	
	if (IS_QK_ONE_SHOT_MOD(keycode))
		return ((QK_ONE_SHOT_MOD_GET_MODS(keycode)) << (keycode & 0x10 ? 4 : 0)) & leader_hrms->leader_mod;
	
	return IS_MODIFIER_KEYCODE(keycode) && MOD_BIT(keycode) & leader_hrms->leader_mod;
}

bool name_me(const keyrecord_t *const record, const uint8_t shift) {
	const hrm_t *(*const mods)[3] = shift == 0
		? leader_hrms->l_mods
		: leader_hrms->r_mods;
	
	for (uint8_t i = 0; i < 3; i++) {
		const hrm_t *const hrm = (*mods)[i];
		
		if (hrm == NULL)
			break;
		
		if (hrm->row != record->event.key.row || hrm->col != record->event.key.col)
			continue;
		
		if (record->event.pressed) {
			register_mods(hrm->mod);
			hrm_mods |= 1 << (i + shift);
		} else {
			unregister_mods(hrm->mod);
			hrm_mods &= ~(1 << (i + shift));
		}
		
		return false;
	}
	
	return true;
}


bool process_leader_hrm(const uint16_t keycode, const keyrecord_t *const record) {
	if (leader_hrms == NULL)
		return true;
	
	uint8_t shift;
	
	// TODO:
	if  (record->event.key.row < MATRIX_ROWS/2) {
		// Check if there is any mod defined for the left side
		if (leader_hrms->l_mods == NULL)
			return true;
		
		shift = 0;
	} else {
		// Do the same for the right side
		if (leader_hrms->r_mods == NULL)
			return true;
		
		shift = 4;
	}
	
	if (is_leader_mod(keycode)) {
		if (record->event.pressed)
			hrm_mods |= 1 << (3 + shift);
		else
			hrm_mods &= ~(1 << (3 + shift));
		
		return true;
	}
	
	// Check the layer
	if ((leader_hrms->layers & (1 << read_source_layers_cache(record->event.key))) == 0)
		return true;
	
	// Check if there is any active mod
	if ((hrm_mods & (0b1111 << shift)) == 0)
		return true;
	
	return name_me(record, shift);
}