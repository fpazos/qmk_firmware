#include QMK_KEYBOARD_H


// Each layer gets a name for readability,	which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length,	obviously,	and you can also skip them
// entirely and just use numbers.
#define _QWERTY 0
#define _LOWER 1
#define _RAISE 2

enum custom_keycodes {
  QWERTY = SAFE_RANGE,
  LOWER,
  RAISE,
  ADJUST,
};


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/* QWERTY
 * ,------------------------------------------------.      ,------------------------------------------------.
 * |  Esc | ºª\  |   1  |   2  |   3  |   4  |   5  |      |   6  |   7  |   8  |   9  |   0  |   '  |   ¡  |
 * |------+------+------+------+------+------+------|      |------+------+------+------+------+------+------|
 * |   -  | Tab  |   Q  |   W  |   E  |   R  |   T  |      |   Y  |   U  |   I  |   O  |   P  |  `^[ |   ]  |
 * |------+------+------+------+------+------+------|      |------+------+------+------+------+------+------|
 * |   =  | Esc  |   A  |   S  |   D  |   F  |   G  |      |   H  |   J  |   K  |   L  |   ;  |   "  |Enter |
 * |------+------+------+------+------+------+------|      |------+------+------+------+------+------+------|
 * | Pg Up| Shift|   Z  |   X  |   C  |   V  |   B  |      |   N  |   M  |   ,  |   .  |   /  | Home | End  |
 * |------+------+------+------+------+------+------|      |------+------+------+------+------+------+------|
 * | Pg Dn|Adjust| Ctrl | Alt  | GUI  |Lower |Space |      |Space |Raise | Left | Down |  Up  | Right|   \  |
 * `------------------------------------------------'      `------------------------------------------------'
 */
  [_QWERTY] = LAYOUT_ortho_5x14(
	KC_ESC,		KC_GRV, 	KC_1,   	KC_2,		KC_3,		KC_4,		KC_5,		KC_6,		KC_7,		KC_8,		KC_9,		KC_0,		KC_MINS,	KC_EQL,
   KC_BSPC,		KC_CAPS,	KC_Q,   	KC_W,		KC_E,		KC_R,		KC_T,		KC_Y,		KC_U,		KC_I,		KC_O,		KC_P,		KC_LBRC,	KC_RBRC,
   KC_PGDN,		KC_TAB, 	KC_A,   	KC_S,		KC_D,		KC_F,		KC_G,		KC_H,		KC_J,		KC_K,		KC_L,		KC_SCLN,	KC_QUOT,	KC_NUHS,
   KC_LSFT,		KC_NUBS,	KC_Z,   	KC_X,		KC_C,		KC_V,		KC_B,		KC_N,		KC_M,		KC_COMM,	KC_DOT,		KC_SLSH,	KC_UP,		RSFT_T(KC_ENT),
   KC_END,		KC_LCTL,	KC_LGUI,	KC_INS,		TT(1),		LALT_T(KC_SPC),	KC_BSPC,	KC_SPC,		RALT_T(KC_BSPC),	TT(2),		KC_RCTL,	KC_LEFT,	KC_DOWN,	KC_RGHT
  ),
/* QWERTY
 * ,------------------------------------------------.      ,------------------------------------------------.
 * |  Ins |   `  |   1  |   2  |   3  |   4  |   5  |      |   6  |   7  |   8  |   9  |   0  | Bksp | Del  |
 * |------+------+------+------+------+------+------|      |------+------+------+------+------+------+------|
 * |   -  | Tab  |   Q  |   W  |   E  |   R  |   T  |      |   Y  |   U  |   I  |   O  |   P  |   [  |   ]  |
 * |------+------+------+------+------+------+------|      |------+------+------+------+------+------+------|
 * |   =  | Esc  |   A  |   S  |   D  |   F  |   G  |      |   H  |   J  |   K  |   L  |   ;  |   "  |Enter |
 * |------+------+------+------+------+------+------|      |------+------+------+------+------+------+------|
 * | Pg Up| Shift|   Z  |   X  |   C  |   V  |   B  |      |   N  |   M  |   ,  |   .  |   /  | Home | End  |
 * |------+------+------+------+------+------+------|      |------+------+------+------+------+------+------|
 * | Pg Dn|Adjust| Ctrl | Alt  | GUI  |Lower |Space |      |Space |Raise | Left | Down |  Up  | Right|   \  |
 * `------------------------------------------------'      `------------------------------------------------'
 */
  [_LOWER] = LAYOUT_ortho_5x14(
	KC_ESC,		KC_GRV,		KC_F1,		KC_F2,		KC_F3,		KC_F4,		KC_F5,		KC_F6,		KC_F7,		KC_F8,		KC_F9,		KC_F10,		KC_F11,		KC_F12,
	KC_DEL,		KC_CAPS,	KC_Q,		KC_W,		KC_E,		KC_R,		LCTL(KC_F5),		KC_Y,		KC_U,		KC_I,		KC_O,		KC_P,		KC_LBRC,	KC_RBRC,
	KC_PGUP,	KC_TAB,		KC_A,		RALT(KC_QUOT),	RALT(KC_LBRC),	RSFT(KC_8),		KC_G,		KC_H,		RSFT(KC_9),		RALT(KC_RBRC),		RALT(KC_NUHS),		KC_SCLN,	KC_QUOT,	KC_NUHS,
	KC_LSFT,	KC_NUBS,	KC_Z,		KC_X,		KC_C,		KC_V,		KC_B,		KC_N,		KC_M,		KC_COMM,	KC_DOT,		KC_SLSH,	KC_UP,		RSFT_T(KC_ENT),
	KC_HOME,	KC_LCTL,	KC_LGUI,	KC_PSCR,	KC_TRNS,	LALT_T(KC_SPC),	KC_DEL,		KC_SPC,		RALT_T(KC_BSPC),	KC_TRNS,	KC_RCTL,	KC_LEFT,	KC_DOWN,	KC_RGHT
  ),
/* QWERTY
 * ,------------------------------------------------.      ,------------------------------------------------.
 * |  Ins |   `  |   1  |   2  |   3  |   4  |   5  |      |   6  |   7  |   8  |   9  |   0  | Bksp | Del  |
 * |------+------+------+------+------+------+------|      |------+------+------+------+------+------+------|
 * |   -  | Tab  |   Q  |   W  |   E  |   R  |   T  |      |   Y  |   U  |   I  |   O  |   P  |   [  |   ]  |
 * |------+------+------+------+------+------+------|      |------+------+------+------+------+------+------|
 * |   =  | Esc  |   A  |   S  |   D  |   F  |   G  |      |   H  |   J  |   K  |   L  |   ;  |   "  |Enter |
 * |------+------+------+------+------+------+------|      |------+------+------+------+------+------+------|
 * | Pg Up| Shift|   Z  |   X  |   C  |   V  |   B  |      |   N  |   M  |   ,  |   .  |   /  | Home | End  |
 * |------+------+------+------+------+------+------|      |------+------+------+------+------+------+------|
 * | Pg Dn|Adjust| Ctrl | Alt  | GUI  |Lower |Space |      |Space |Raise | Left | Down |  Up  | Right|   \  |
 * `------------------------------------------------'      `------------------------------------------------'
 */
  [_RAISE] = LAYOUT_ortho_5x14(
	KC_ESC,		KC_GRV,		KC_1,		KC_2,		KC_3,		KC_4,		KC_5,		KC_6,		KC_P7,		KC_P8,		KC_P9,		KC_PPLS,	KC_MINS,	KC_EQL,
	KC_DEL,		KC_CAPS,	KC_NO,		KC_NO,		KC_NO,		KC_NO,		KC_NO,		KC_NLCK,	KC_P4,		KC_P5,		KC_P6,		KC_PMNS,	KC_LBRC,	KC_RBRC,
	KC_PGUP,	KC_TAB,		KC_MRWD,	KC_MSTP,	KC_MPLY,	KC_MFFD,	KC_NO,		KC_NO,		KC_P1,		KC_P2,		KC_P3,		KC_PAST,	KC_SCLN,	KC_QUOT,
	KC_LSFT,	KC_NUBS,	KC_NO,		KC_MUTE,	KC_VOLD,	KC_VOLU,	KC_NO,		KC_NO,		KC_P0,		KC_P0,		KC_PDOT,	KC_PSLS,	KC_UP,		RSFT_T(KC_ENT),
	KC_HOME,	KC_LCTL,	KC_LGUI,	KC_NLCK,	KC_TRNS,	LALT_T(KC_SPC),	KC_BSPC,	KC_SPC,		RALT_T(KC_BSPC),	KC_TRNS,	KC_RCTL,	KC_LEFT,	KC_DOWN,	KC_RGHT
  ),

};

