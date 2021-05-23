#include QMK_KEYBOARD_H


// Each layer gets a name for readability,  which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length,  obviously,  and you can also skip them
// entirely and just use numbers.
#define _QWERTY 0
#define _GAME 1
#define _LOWER 2
#define _RAISE 3
#define _ADJUST 4

enum custom_keycodes {
  QWERTY = SAFE_RANGE,
  LOWER,
  RAISE,
  ADJUST,
  GAME
};


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/* QWERTY
 * ,------------------------------------------------.      ,------------------------------------------------.
 * | ESC  | Grv  |   1  |   2  |   3  |   4  |   5  |      |   6  |   7  |   8  |   9  |   0  |   '  |   ¡  |
 * |------+------+------+------+------+------+------|      |------+------+------+------+------+------+------|
 * |  TAB | Caps |   Q  |   W  |   E  |   R  |   T  |      |   Y  |   U  |   I  |   O  |   P  |   [  |   ]  |
 * |------+------+------+------+------+------+------|      |------+------+------+------+------+------+------|
 * |PgDown| TAB  |   A  |   S  |   D  |   F  |   G  |      |   H  |   J  |   K  |   L  |   Ñ  |   ´  |   Ç  |
 * |------+------+------+------+------+------+------|      |------+------+------+------+------+------+------|
 * | Shift|  <>  |   Z  |   X  |   C  |   V  |   B  |      |   N  |   M  |   ,  |   .  |   -  |  Up  | Enter|
 * |------+------+------+------+------+------+------|      |------+------+------+------+------+------+------|
 * | END  | Ctrl | LGui |  INS |AltWin| Lower|BckSp |      |Space |Raise | AltGr| Ctrl | Left | Down | Right|
 * `------------------------------------------------'      `------------------------------------------------'
 */
  [_QWERTY] = LAYOUT_ortho_5x14(
   KC_ESC,    KC_GRV,   KC_1,     KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS,  KC_EQL,
   KC_BSPC,    KC_CAPS,  KC_Q,     KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC,  KC_RBRC,
   KC_PGDN,    KC_TAB,   KC_A,     KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN,  KC_QUOT,  KC_NUHS,
   KC_LSFT,    KC_NUBS,  KC_Z,     KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM,  KC_DOT,    KC_SLSH,  KC_UP, RSFT_T(KC_ENT),
   KC_END,    KC_LCTL,  KC_LGUI,  KC_INS, MT(MOD_LALT,KC_LGUI),  LT(_LOWER, KC_SPC),  KC_BSPC,  KC_SPC, LT(_RAISE, KC_BSPC), MOD_RALT,  KC_RCTL,  KC_LEFT,  KC_DOWN,  KC_RGHT
  ),

/* GAME
 * ,------------------------------------------------.      ,------------------------------------------------.
 * | ESC  |GrvEsc|   1  |   2  |   3  |   4  |   5  |      |   6  |   7  |   8  |   9  |   0  |   '  |   ¡  |
 * |------+------+------+------+------+------+------|      |------+------+------+------+------+------+------|
 * |  6   | Caps |   Q  |   W  |   E  |   R  |   T  |      |   Y  |   U  |   I  |   O  |   P  |   [  |   ]  |
 * |------+------+------+------+------+------+------|      |------+------+------+------+------+------+------|
 * |  7   | TAB  |   A  |   S  |   D  |   F  |   G  |      |   H  |   J  |   K  |   L  |   Ñ  |   ´  |   Ç  |
 * |------+------+------+------+------+------+------|      |------+------+------+------+------+------+------|
 * |  8   | Shift|   Z  |   X  |   C  |   V  |   B  |      |   N  |   M  |   ,  |   .  |   -  |  Up  | Enter|
 * |------+------+------+------+------+------+------|      |------+------+------+------+------+------+------|
 * |  9   | Ctrl | LGui | Toggl| Lower| Alt  |Space |      |Space |Raise | AltGr| Ctrl | Left | Down | Right|
 * `------------------------------------------------'      `------------------------------------------------'
 */
  [_GAME] = LAYOUT_ortho_5x14(
  KC_ESC,   KC_GRV,   KC_1,     KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS,  KC_EQL,
   KC_6,    KC_CAPS,  KC_Q,     KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC,  KC_RBRC,
   KC_7,    KC_TAB,   KC_A,     KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,  KC_NUHS,
   KC_8,    KC_LSFT,  KC_Z,     KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM,  KC_DOT, KC_SLSH,  KC_UP, RSFT_T(KC_ENT),
   KC_9,    KC_LCTL,  KC_LGUI,  TG(_GAME), LT(_LOWER, KC_SPC),  KC_LALT,  KC_SPC,  KC_SPC, LT(_RAISE, KC_BSPC), MT(MOD_RALT,KC_LEFT),  KC_RCTL,  KC_LEFT,  KC_DOWN,  KC_RGHT
  ),

/* Lower
 * ,------------------------------------------------.      ,------------------------------------------------.
 * | SUP  |   ~  |  F1  |  F3  |  F3  |  F4  |  F5  |      |  F6  |  F7  |  F8  |  F9  | F10  | F11  | F12  |
 * |------+------+------+------+------+------+------|      |------+------+------+------+------+------+------|
 * | DEL  |      |      |  |   |   &  |   !  | CtF5 |      |      |Print1|  #   |  @   |      |      |      |
 * |------+------+------+------+------+------+------|      |------+------+------+------+------+------+------|
 * | PgUp |      |   ~  |   {  |   [  |   (  |   '  |      |   "  |   )  |   ]  |   }  |      |      |      |
 * |------+------+------+------+------+------+------|      |------+------+------+------+------+------+------|
 * |      |      |   %  |   *  |   -  |   +  |   /  |      | Save | Undo | Redo | Paste| Cut  | Copy |      |
 * |------+------+------+------+------+------+------|      |------+------+------+------+------+------+------|
 * | Home |      |      |      |      |      | DEL  |      |      |      |      |      |      |      |      |
 * `------------------------------------------------'      `------------------------------------------------'
 */
  [_LOWER] = LAYOUT_ortho_5x14(
  _______,   _______,   KC_F1,   KC_F2,    KC_F3,    KC_F4,    KC_F5,    KC_F6,    KC_F7,    KC_F8,    KC_F9,    KC_F10,    KC_F11,    KC_F12,
  KC_DEL,   _______,  _______, ALGR(KC_1), KC_CIRC, RSFT(KC_1),    LCTL(KC_F5),    _______, RALT(KC_PSCR), RALT(KC_3), RALT(KC_2), _______, _______, _______,
  KC_PGUP,  KC_TAB,RALT(KC_4), RALT(KC_QUOT),RALT(KC_LBRC),RSFT(KC_8),KC_MINS,  KC_AT, RSFT(KC_9), ALGR(KC_RBRC), ALGR(KC_NUHS),    KC_SCLN,  KC_QUOT,  KC_NUHS,
  KC_LSFT,   RSFT(KC_5), RSFT(KC_RBRC), KC_SLSH, KC_RBRC, RSFT(KC_7), ALGR(KC_GRV), C(KC_S), C(KC_Z), C(KC_Y), C(KC_V), C(KC_C), C(KC_X),  _______,
  KC_HOME,  _______,  _______,  KC_PSCR,  _______,  _______,  KC_DEL,    _______,    _______,  _______,  _______,  _______,  _______,  _______
  ),

/* RAISE
 * ,------------------------------------------------.      ,------------------------------------------------.
 * |      |      |      |      |      |      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------|      |------+------+------+------+------+------+------|
 * |      |      | MPrv | Stop | Play | MNxt |      |      |      |      |  Up  |      |      |      |      |
 * |------+------+------+------+------+------+------|      |------+------+------+------+------+------+------|
 * |      |      | PagUp| Home | End  | PagDw|      |      |      | Left | Down | Right|      |      |      |
 * |------+------+------+------+------+------+------|      |------+------+------+------+------+------+------|
 * |      |      |      | Mute | Vol- | Vol+ |      |      |ctalsu|CopMsy|PegMsy|      |      |      |      |
 * |------+------+------+------+------+------+------|      |------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |      |      |      |      |
 * `------------------------------------------------'      `------------------------------------------------'
 */
  [_RAISE] = LAYOUT_ortho_5x14(
  _______, _______, _______, _______, _______, _______, _______,      _______, _______, _______, _______, _______, _______, _______,
  _______, _______, KC_MPRV, KC_MSTP, KC_MPLY, KC_MNXT, _______,      _______, _______, KC_UP  , _______, _______, _______, _______,
  _______, _______, KC_PGUP, KC_HOME, KC_END,  KC_PGDN, _______,      _______, KC_LEFT, KC_DOWN, KC_RGHT, _______, _______, _______,
  _______, _______, _______, KC_MUTE, KC_VOLD, KC_VOLU, _______,  LCA(KC_DEL), C(KC_INS), RSFT(KC_INS), _______, _______, _______, _______,
  _______, _______, _______, _______, _______, _______, _______,      _______, _______, _______, _______, _______, _______, _______
  ),

/* ADJUST
 * ,------------------------------------------------.      ,------------------------------------------------.
 * |      |      |      |      |      |      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------|      |------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------|      |------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------|      |------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------|      |------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |      |      |      |      |
 * `------------------------------------------------'      `------------------------------------------------'
 */
  [_ADJUST] = LAYOUT_ortho_5x14(
  _______, _______, _______, _______, _______, _______, _______,      KC_NLCK, KC_P7,   KC_P8,   KC_P9,   KC_PPLS, _______, _______,
  _______, _______, _______, _______, _______, _______, _______,      _______, KC_P4,   KC_P5,   KC_P6,   KC_PMNS, _______, _______,
  _______, _______, _______, _______, _______, TG(_GAME), _______,      _______, KC_P1,   KC_P2,   KC_P3,   KC_PAST, _______, _______,
  _______, _______, _______, _______, _______, _______, _______,      _______, KC_P0,   KC_P0,   KC_PDOT, KC_PSLS, _______, _______,
  _______, _______, _______, _______, _______, _______, _______,      _______, _______, _______, _______, _______, _______, _______
  )
};


bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case QWERTY:
      if (record->event.pressed) {
        set_single_persistent_default_layer(_QWERTY);
      }
      return false;
      break;
    case LOWER:
      if (record->event.pressed) {
        layer_on(_LOWER);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      } else {
        layer_off(_LOWER);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      }
      return false;
      break;
    case RAISE:
      if (record->event.pressed) {
        layer_on(_RAISE);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      } else {
        layer_off(_RAISE);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      }
      return false;
      break;
    case ADJUST:
      if (record->event.pressed) {
        layer_on(_ADJUST);
      } else {
        layer_off(_ADJUST);
      }
      return false;
      break;
  }
  return true;
}
