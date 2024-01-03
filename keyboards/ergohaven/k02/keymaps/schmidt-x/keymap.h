#pragma once

enum custom_keycodes {
	/*
	* layer_clear() when pressed.
	  Sends KC_F13 if layer is already default. */
	NORMAL = SAFE_RANGE, // 0x7e40,
	
	/*
	* layer_move(_INSERT) when pressed */
	INSERT,
	
	/* 
	* Reversed MO(_INSERT) */
	INS_RMO,
	
	/*
	* layer_on(_MOUSE) when pressed (doesn't bring back) */
	MOUSE,
	
	/*
	* Hard to explain. Just ignore, you don't need it */
	SMB_NRM,
	
	/*
	* Alt+Tab when pressed.
	* LCtrl when pressed if matrix_is_on(0, 2)
	  or if any other hrm-mod on the same side is on.
	* F when pressed if any mod is on */
	HRM_FAT,
};

// QK_RBT   0x7c01
// EE_CLR   0x7c03
// KO_TOGG  0x7c5d

enum layers {
	_NORMAL,
	_INSERT,
	_SYMBOL,
	_U_SYMB,
	_MOUSE,
	_FIVE,
	_SIX,
	_SEVEN,
	_EIGHT,
	_NINE,
	_TEN,
	_ELEVEN,
	_TWELVE,
	_THIRTEEN,
	_FOURTEEN,
	_SYSTEM
};


#define SYMBOL  MO(_SYMBOL)
#define U_SYMBL MO(_U_SYMB)
#define OSM_LSF OSM(MOD_LSFT)


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