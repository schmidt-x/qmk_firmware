#pragma once

#include "action_layer.h"

typedef struct {
	const uint8_t col;
	const uint8_t mod;
} hrm_t;

typedef struct {
	const uint8_t       l_row;
	const uint8_t       r_row;
	const uint8_t       leader_mod;
	const hrm_t         *(*l_mods)[3];
	const hrm_t         *(*r_mods)[3];
	const layer_state_t layers;
} leader_hrm_t;

extern const leader_hrm_t *leader_hrms;

bool process_leader_hrm(const uint16_t keycode, const keyrecord_t *const record);