#pragma once

#ifdef LEADER_HRM_ENABLE
#    include "leader_hrm.h"
#endif

enum custom_keycodes {
	/*
	* layer_clear() when pressed.
	  Sends KC_F13 if layer is already default. */
	NORMAL = SAFE_RANGE, // 0x7e40,
	
	/* 
	* Reversed MO(_INSERT) */
	INS_RMO,
	
	/*
	* layer_on(_MOUSE) when pressed (doesn't bring back on release) */
	MOUSE,
	
	/*
	* Hard to explain. Just ignore, you don't need it */
	SMB_NRM,
	
	/*
	* RAlt+Tab when pressed.
	* T when pressed if any mod is on */
	T_ALTAB,
	
	/*
	* RCtrl+z when pressed.
	* Q when pressed if any mod is on */
	Q_UNDO,
	
	/*
	* RCtrl+y when pressed.
	* J when pressed if any mod is on */
	J_REDO,
	
	/*
	* RCtrl+s when pressed.
	* S when pressed if any mod is on */
	S_SAVE,
	
	/*
	* RGui+v when pressed.
	* D when pressed if any mod is on */
	D_CLIPB,
};

enum layers {
	_NORMAL,
	_INSERT,
	_SYMBOL,
	_U_SYMB,
	_MOUSE,
	_SYSTEM
};


#define SYMBOL  MO(_SYMBOL)
#define U_SYMBL MO(_U_SYMB)
#define OSM_LSF OSM(MOD_LSFT)
#define OSM_LCT OSM(MOD_LCTL)
#define INSERT  TO(_INSERT)


// --- Right Shifted Symbols ---

#define CK_TILD RSFT(KC_GRV)
#define CK_EXLM RSFT(KC_1)
#define CK_AT   RSFT(KC_2)
#define CK_HASH RSFT(KC_3)
#define CK_DLR  RSFT(KC_4)
#define CK_PERC RSFT(KC_5)
#define CK_CIRC RSFT(KC_6)
#define CK_AMPR RSFT(KC_7)
#define CK_ASTR RSFT(KC_8)
#define CK_LPRN RSFT(KC_9)
#define CK_RPRN RSFT(KC_0)
#define CK_UNDS RSFT(KC_MINS)
#define CK_PLUS RSFT(KC_EQL)
#define CK_LCBR RSFT(KC_LBRC)
#define CK_RCBR RSFT(KC_RBRC)
#define CK_PIPE RSFT(KC_BSLS)
#define CK_QUES RSFT(KC_SLSH)


#ifdef LEADER_HRM_ENABLE

const leader_hrm_t *leader_hrms = &(const leader_hrm_t) {
	.leader_mod = MOD_BIT_LSHIFT,
	.layers     = ~0,
	
	.l_row  = 1,
	.l_mods = &(const hrm_t *[3]) {
		&(const hrm_t){.col = 1, .mod = MOD_BIT_LCTRL},
		&(const hrm_t){2, MOD_BIT_LALT},
		&(const hrm_t){3, MOD_BIT_LGUI}
	},

	.r_row  = 5,
	.r_mods = &(const hrm_t *[3]) {
		&(const hrm_t){1, MOD_BIT_LCTRL},
		&(const hrm_t){2, MOD_BIT_LALT},
		&(const hrm_t){3, MOD_BIT_LGUI}
	},
};

#endif


#ifdef COMBO_ENABLE

const uint16_t PROGMEM to_system_combo[] = {KC_F23, KC_F24, COMBO_END};

combo_t key_combos[] = {
	COMBO(to_system_combo, OSL(_SYSTEM)),
};

#endif


#ifdef KEY_OVERRIDE_ENABLE

// This globally defines all key overrides to be used
const key_override_t **key_overrides = (const key_override_t *[]) {
	&ko_make_with_layers_and_negmods(MOD_BIT_LSHIFT, KC_BSPC, C(KC_BSPC), 1 << _NORMAL, ~MOD_BIT_LSHIFT),
	&ko_make_with_layers_and_negmods(MOD_BIT_LCTRL,  KC_BSPC, S(KC_BSPC), 1 << _NORMAL, ~MOD_BIT_LCTRL),
	&ko_make_with_layers_and_negmods(MOD_BIT_LSHIFT, KC_DEL,  C(KC_DEL),  1 << _NORMAL, ~MOD_BIT_LSHIFT),
	&ko_make_with_layers_and_negmods(MOD_BIT_LCTRL,  KC_DEL,  S(KC_DEL),  1 << _NORMAL, ~MOD_BIT_LCTRL),
	
	&ko_make_with_layers_and_negmods(MOD_BIT_LSHIFT, KC_LEFT, C(KC_LEFT), 1 << _NORMAL, ~MOD_BIT_LSHIFT),
	&ko_make_with_layers_and_negmods(MOD_BIT_LCTRL,  KC_LEFT, S(KC_LEFT), 1 << _NORMAL, ~MOD_BIT_LCTRL),
	&ko_make_with_layers_and_negmods(MOD_BIT_LSHIFT, KC_RGHT, C(KC_RGHT), 1 << _NORMAL, ~MOD_BIT_LSHIFT),
	&ko_make_with_layers_and_negmods(MOD_BIT_LCTRL,  KC_RGHT, S(KC_RGHT), 1 << _NORMAL, ~MOD_BIT_LCTRL),
	
	&ko_make_basic(MOD_BIT_LSHIFT, KC_MS_U, KC_WH_U),
	&ko_make_basic(MOD_BIT_LSHIFT, KC_MS_D, KC_WH_D),
	&ko_make_basic(MOD_BIT_LSHIFT, KC_MS_L, KC_WH_L),
	&ko_make_basic(MOD_BIT_LSHIFT, KC_MS_R, KC_WH_R),
	
	NULL // Null terminate the array of overrides!
};

#endif