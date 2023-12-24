#ifndef KEYMAP_H
#define KEYMAP_H

enum custom_keycodes {
	F_ALTAB = SAFE_RANGE, // 0x7e40
	NORMAL,
	INSERT,
	INS_RMO,
	MOUSE,
	SMB_NRM,
};

// QK_RBT   0x7c01
// EE_CLR   0x7c03
// KO_TOGG  0x7c5d

enum layers {
	_NORMAL,
	_INSERT,
	_SYMBOL,
	_MOUSE,
	_FOUR,
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
#define OSM_LSF OSM(MOD_LSFT)
#define OSL_SYS OSL(_SYSTEM)

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


// const uint16_t PROGMEM to_system_layer[] = {KC_ESC, KC_CAPS, COMBO_END};

// combo_t key_combos[] = {
	// COMBO(to_system_layer, OSL(_SYSTEM)),
// };


const key_override_t lsft_bspc_to_lctl_bspc = ko_make_with_layers_and_negmods(MOD_BIT(KC_LSFT), KC_BSPC, C(KC_BSPC), 1 << _NORMAL, ~MOD_BIT(KC_LSFT));
const key_override_t lctl_bspc_to_lsft_bspc = ko_make_with_layers_and_negmods(MOD_BIT(KC_LCTL), KC_BSPC, S(KC_BSPC), 1 << _NORMAL, ~MOD_BIT(KC_LCTL));
const key_override_t lsft_del_to_lctl_del   = ko_make_with_layers_and_negmods(MOD_BIT(KC_LSFT), KC_DEL,  C(KC_DEL),  1 << _NORMAL, ~MOD_BIT(KC_LSFT));
const key_override_t lctl_del_to_lsft_del   = ko_make_with_layers_and_negmods(MOD_BIT(KC_LCTL), KC_DEL,  S(KC_DEL),  1 << _NORMAL, ~MOD_BIT(KC_LCTL));

const key_override_t lsft_left_to_lctl_left = ko_make_with_layers_and_negmods(MOD_BIT(KC_LSFT), KC_LEFT, C(KC_LEFT), 1 << _NORMAL, ~MOD_BIT(KC_LSFT));
const key_override_t lctl_left_to_lsft_left = ko_make_with_layers_and_negmods(MOD_BIT(KC_LCTL), KC_LEFT, S(KC_LEFT), 1 << _NORMAL, ~MOD_BIT(KC_LCTL));
const key_override_t lsft_rght_to_lctl_rght = ko_make_with_layers_and_negmods(MOD_BIT(KC_LSFT), KC_RGHT, C(KC_RGHT), 1 << _NORMAL, ~MOD_BIT(KC_LSFT));
const key_override_t lctl_rght_to_lsft_rght = ko_make_with_layers_and_negmods(MOD_BIT(KC_LCTL), KC_RGHT, S(KC_RGHT), 1 << _NORMAL, ~MOD_BIT(KC_LCTL));

const key_override_t lsft_msu_to_whu = ko_make_basic(MOD_BIT(KC_LSFT), KC_MS_U, KC_WH_U);
const key_override_t lsft_msd_to_whd = ko_make_basic(MOD_BIT(KC_LSFT), KC_MS_D, KC_WH_D);
const key_override_t lsft_msl_to_whl = ko_make_basic(MOD_BIT(KC_LSFT), KC_MS_L, KC_WH_L);
const key_override_t lsft_msr_to_whr = ko_make_basic(MOD_BIT(KC_LSFT), KC_MS_R, KC_WH_R);

// This globally defines all key overrides to be used
const key_override_t **key_overrides = (const key_override_t *[]) {
	&lsft_bspc_to_lctl_bspc,
	&lctl_bspc_to_lsft_bspc,
	&lsft_del_to_lctl_del,
	&lctl_del_to_lsft_del,
	&lsft_left_to_lctl_left,
	&lctl_left_to_lsft_left,
	&lsft_rght_to_lctl_rght,
	&lctl_rght_to_lsft_rght,
	&lsft_msu_to_whu,
	&lsft_msd_to_whd,
	&lsft_msl_to_whl,
	&lsft_msr_to_whr,
	NULL // Null terminate the array of overrides!
};

#endif