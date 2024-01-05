#pragma once

#include "action_layer.h"

typedef struct {
	const uint8_t row;
	const uint8_t col;
	const uint8_t mod;
} hrm_t;

typedef struct {
	const hrm_t         *(*l_mods)[3];
	const hrm_t         *(*r_mods)[3];
	const layer_state_t layers;
	const uint8_t       leader_mod;
} leader_hrm_t;

extern const leader_hrm_t *leader_hrms;

bool process_leader_hrm(const uint16_t keycode, const keyrecord_t *const record);