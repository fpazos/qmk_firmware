#include QMK_KEYBOARD_H
#include "stdio.h"

enum layers {
    _QWERTY = 0,
    _GAME,
    _LOWER,
    _RAISE,
    _ADJUST,
    _LOWERGAME
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* QWERTY
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * | ESC  |   1  |   2  |   3  |   4  |   5  |                    |   6  |   7  |   8  |   9  |   0  |  '   |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | Grv  |   Q  |   W  |   E  |   R  |   T  |                    |   Y  |   U  |   I  |   O  |   P  |  +   |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | Tab  |   A  |   S  |   D  |   F  |   G  |-------.    ,-------|   H  |   J  |   K  |   L  |   Ñ  |  ´   |
 * |------+------+------+------+------+------|   <   |    |  Ins  |------+------+------+------+------+------|
 * | RShif|   Z  |   X  |   C  |   V  |   B  |-------|    |-------|   N  |   M  |   ,  |   .  |   /  |RShEnt|
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *                   | RCtrl| Win  |Space | /BSpace /       \Space \  |BSpace| Left | Right|
 *                   |      | Alt  | Lower|/       /         \      \ |RAISE |AltGr |      |
 *                   `----------------------------'           '------''--------------------'
 */

 [_QWERTY] = LAYOUT( \
  KC_ESC,   KC_1,   KC_2,    KC_3,    KC_4,    KC_5,                     KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, \
  KC_GRV,   KC_Q,   KC_W,    KC_E,    KC_R,    KC_T,                     KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_RBRC, \
  KC_TAB,   KC_A,   KC_S,    KC_D,    KC_F,    KC_G,                     KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT, \
  KC_LSFT,  KC_Z,   KC_X,    KC_C,    KC_V,    KC_B, KC_NUBS,  KC_INS,  KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH,  MT(MOD_LSFT,KC_ENT), \
     KC_LCTRL, MT(MOD_LALT,KC_LGUI), LT(_LOWER, KC_SPC),KC_BSPC,  KC_SPC, LT(_RAISE, KC_BSPC),  MT(MOD_RALT,KC_LEFT), KC_RIGHT \
),
/* GAME
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * | ESC  |   1  |   2  |   3  |   4  |   5  |                    |   6  |   7  |   8  |   9  |   0  |  '   |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |   T  |  Tab |   Q  |   W  |   E  |   R  |                    |   Y  |   U  |   I  |   O  |   P  |  +   |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |   G  | Shif |   A  |   S  |   D  |   F  |-------.    ,-------|   H  |   J  |   K  |   L  |   Ñ  |  ´   |
 * |------+------+------+------+------+------|   <   |    |  Ins  |------+------+------+------+------+------|
 * |   B  | Ctrl |   Z  |   X  |   C  |   V  |-------|    |-------|   N  |   M  |   ,  |   .  |   /  |RShEnt|
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *                   |Toggl | Win  | Alt  | / Space /       \Space \  |BSpace| Left | Right|
 *                   |      |LowerG|      |/       /         \      \ |RAISE |AltGr |      |
 *                   `----------------------------'           '------''--------------------'
 */

 [_GAME] = LAYOUT( \
  KC_ESC,   KC_1,     KC_2,   KC_3,    KC_4,   KC_5,                     KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, \
  KC_T,     KC_TAB,   KC_Q,   KC_W,    KC_E,   KC_R,                     KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_RBRC, \
  KC_G,     KC_LSFT,  KC_A,   KC_S,    KC_D,   KC_F,                     KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT, \
  KC_B,    KC_LCTRL,  KC_Z,   KC_X,    KC_C,   KC_V,  KC_NUBS,  KC_INS,  KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH,  MT(MOD_LSFT,KC_ENT), \
           TG(_GAME), LT(_LOWERGAME, KC_LGUI), KC_LALT,KC_SPC,  KC_SPC, LT(_RAISE, KC_BSPC),  MT(MOD_RALT,KC_LEFT), KC_RIGHT \
),
/* LOWER
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * | F12  |  F1  |  F2  |  F3  |  F4  |  F5  |                    |  F6  |  F7  |  F8  |  F9  | F10  | F11  |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |      |   |  |   &  |   !  | CtF5 |                    |      |Print1|  #   |  @   |      | `^[  |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |   ~  |   {  |   [  |   (  |   '  |-------.    ,-------|   "  |   )  |   ]  |   }  |      | çÇ}  |
 * |------+------+------+------+------+------|   \   |    | Print |------+------+------+------+------+------|
 * |      |   %  |   *  |   -  |   +  |   /  |-------|    |-------| Save | Undo | Redo | Paste| Cut  | Copy |
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *                   | RCtrl| Win  |Space | / Del   /       \Space \  |BSpace| Left | Right|
 *                   |      | Alt  | Lower|/       /         \      \ |RAISE |AltGr |      |
 *                   `----------------------------'           '------''--------------------'
 */
[_LOWER] = LAYOUT( \
  KC_F12, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,                                              KC_F6,  KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11, \
  KC_CAPS, _______, ALGR(KC_1), KC_CIRC, RSFT(KC_1), C(KC_F5),                                  _______, RALT(KC_PSCR), RALT(KC_3), RALT(KC_2), KC_EQL, KC_LBRC,\
  _______, RALT(KC_4), RALT(KC_QUOT),RALT(KC_LBRC),RSFT(KC_8),KC_MINS,                            KC_AT, RSFT(KC_9), ALGR(KC_RBRC), ALGR(KC_NUHS), _______, KC_NUHS, \
  _______, RSFT(KC_5), RSFT(KC_RBRC), KC_SLSH, KC_RBRC, RSFT(KC_7), ALGR(KC_GRV),      KC_PSCR, C(KC_S), C(KC_Z), C(KC_Y), C(KC_V), C(KC_C), C(KC_X), \
                                    _______, _______, _______, KC_DEL,                    _______, _______, _______, _______\
),

/* RAISE
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |      |      |      |      |      |      |                    |      |      |      |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      | MPrv | Stop | Play | MNxt |      |                    |      |      |  Up  |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      | PagUp| Home | End  | PagDw|      |-------.    ,-------|      | Left | Down | Right|      |      |
 * |------+------+------+------+------+------|       |    |ctaltsu|------+------+------+------+------+------|
 * |      |      | Mute | Vol- | Vol+ |      |-------|    |-------|      |CopMsy|PegMsy|      |      |      |
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *                   | RCtrl| Win  |Space | /BSpace /       \Space \  |BSpace| Left | Right|
 *                   |      | Alt  | Lower|/       /         \      \ |RAISE |AltGr |      |
 *                   `----------------------------'           '------''--------------------'
 */

[_RAISE] = LAYOUT( \
  _______, _______, _______, _______, _______, _______,                           _______, _______, _______, _______, _______, KC_EQL, \
  _______,  KC_MPRV, KC_MSTP, KC_MPLY, KC_MNXT,_______,                           _______, _______, KC_UP  , _______, _______, _______, \
  _______,  KC_PGUP, KC_HOME, KC_END, KC_PGDN, _______,                           _______, KC_LEFT, KC_DOWN, KC_RGHT, _______, _______, \
  _______,  _______, KC_MUTE, KC_VOLD, KC_VOLU,_______,  _______,     LCA(KC_DEL),_______, C(KC_INS), RSFT(KC_INS), _______, _______, _______, \
                             _______, _______, _______,  _______,       _______,  _______, _______, _______ \
),
/* ADJUST
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |      |      |      |      |      |      |                    | NLock| NP7  | NP8  | NP9  | NP+  |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |      |      |      |      |      |                    |      | NP4  | NP5  | NP6  | NP-  |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |RGB ON| HUE+ | SAT+ | VAL+ |      |-------.    ,-------|      | NP1  | NP2  | NP3  | NP*  | NPEnt|
 * |------+------+------+------+------+------|       |    |       |------+------+------+------+------+------|
 * |      | MODE | HUE- | SAT- | VAL- |      |-------|    |-------|      | NP0  | NP0  | NP.  | NP/  |      |
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *                   | RCtrl| Win  |Space | /BSpace /       \Space \  |BSpace| Left | Right|
 *                   |      | Alt  | Lower|/       /         \      \ |RAISE |AltGr |      |
 *                   `----------------------------'           '------''--------------------'
 */
  [_ADJUST] = LAYOUT( \
  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                   KC_NLCK, KC_P7, KC_P8, KC_P9,   KC_PPLS, XXXXXXX,      \
  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,TG(_GAME),XXXXXXX,                   XXXXXXX, KC_P4, KC_P5, KC_P6,   KC_PMNS, XXXXXXX,  \
  XXXXXXX, RGB_TOG, RGB_HUI, RGB_SAI, RGB_VAI, XXXXXXX,                   XXXXXXX, KC_P1, KC_P2, KC_P3,   KC_PAST, KC_PENT,  \
  XXXXXXX, RGB_MOD, RGB_HUD, RGB_SAD, RGB_VAD, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_P0, KC_P0, KC_PDOT, KC_PSLS, XXXXXXX,\
                             _______, _______, _______, _______, _______, _______, _______, _______ \
  ),
    /* LOWERGAME
    * ,-----------------------------------------.                    ,-----------------------------------------.
    * |      |   6  |   7  |   8  |   9  |   0  |                    |   6  |   7  |   8  |   9  |   0  |  '   |
    * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
    * |      |      |      |      |      |      |                    |      |      |      |      |      |      |
    * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
    * |      |      |      |      |      |      |-------.    ,-------|      |      |      |      |      |      |
    * |------+------+------+------+------+------|   <   |    |  Ins  |------+------+------+------+------+------|
    * |      |      |      |      |      |      |-------|    |-------|      |      |      |      |      |      |
    * `-----------------------------------------/       /     \      \-----------------------------------------'
    *                   |Toggl | Win  |Space | / Space /       \Space \  |BSpace| Left | Right|
    *                   |      | Alt  | Lower|/       /         \      \ |RAISE |AltGr |      |
    *                   `----------------------------'           '------''--------------------'
    */

    [_LOWERGAME] = LAYOUT( \
    _______,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,                   _______, _______, _______, _______, _______, _______, \
    KC_CAPS,   KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,                   _______, _______, _______, _______, _______, _______, \
    _______,   KC_F6,   KC_F7,   KC_F8,   KC_F9,  KC_F10,                   _______, _______, _______, _______, _______, _______, \
    _______, _______, _______, _______,  KC_F11,  KC_F12, _______, _______, _______, _______, _______, _______, _______, _______, \
                               _______, _______, _______, _______, _______, _______, _______, _______ \
    )
};

layer_state_t layer_state_set_user(layer_state_t state) {
  return update_tri_layer_state(state, _LOWER, _RAISE, _ADJUST);
}

#ifdef OLED_DRIVER_ENABLE
char wpm_str[10];
oled_rotation_t oled_init_user(oled_rotation_t rotation) {
    if (!is_keyboard_master()) {
        return OLED_ROTATION_180;  // flips the display 180 degrees if offhand
    }

    return rotation;
}

static void render_logo(void) {
    static const char PROGMEM fp_logo[18][64] = {
        // 0
        {
        0xD5, 0xD5, 0xD5, 0xD5, 0xD5, 0xD5, 0xD5, 0xD5, 0x88, 0x89, 0x8A, 0x8B, 0x8C, 0xD5, 0xD5, 0xD5, 0xD5, 0xD5, 0xD5, 0xD5, 0xD5,
        0xD5, 0xD5, 0xD5, 0xD5, 0xD5, 0xD5, 0xD5, 0xD5, 0xA8, 0xA9, 0xAA, 0xAB, 0xAC, 0xD5, 0xD5, 0xD5, 0xD5, 0xD5, 0xD5, 0xD5, 0xD5,
        0xD5, 0xD5, 0xD5, 0xD5, 0xD5, 0xD5, 0xD5, 0xD5, 0xC8, 0xC9, 0xCA, 0xCB, 0xCC, 0xD5, 0xD5, 0xD5, 0xD5, 0xD5, 0xD5, 0xD5, 0xD5, 0x00
        },
        // 1
        {
        0xD5, 0xD5, 0xD5, 0xD5, 0xD5, 0xD5, 0xD5, 0xD5, 0x88, 0x89, 0x8A, 0x8B, 0x8C, 0xD5, 0xD5, 0xD5, 0xD5, 0xD5, 0xD5, 0xD5, 0xD5,
        0xD5, 0xD5, 0xD5, 0xD5, 0xD5, 0xD5, 0xD5, 0xA7, 0xA8, 0xA9, 0xAA, 0xAB, 0xAC, 0xAD, 0xD5, 0xD5, 0xD5, 0xD5, 0xD5, 0xD5, 0xD5,
        0xD5, 0xD5, 0xD5, 0xD5, 0xD5, 0xD5, 0xD5, 0xD5, 0xC8, 0xC9, 0xCA, 0xCB, 0xCC, 0xD5, 0xD5, 0xD5, 0xD5, 0xD5, 0xD5, 0xD5, 0xD5, 0x00
        },
        // 2
        {
        0xD5, 0xD5, 0xD5, 0xD5, 0xD5, 0xD5, 0xD5, 0x87, 0x88, 0x89, 0x8A, 0x8B, 0x8C, 0x8D, 0xD5, 0xD5, 0xD5, 0xD5, 0xD5, 0xD5, 0xD5,
        0xD5, 0xD5, 0xD5, 0xD5, 0xD5, 0xD5, 0xD5, 0xA7, 0xA8, 0xA9, 0xAA, 0xAB, 0xAC, 0xAD, 0xD5, 0xD5, 0xD5, 0xD5, 0xD5, 0xD5, 0xD5,
        0xD5, 0xD5, 0xD5, 0xD5, 0xD5, 0xD5, 0xD5, 0xC7, 0xC8, 0xC9, 0xCA, 0xCB, 0xCC, 0xCD, 0xD5, 0xD5, 0xD5, 0xD5, 0xD5, 0xD5, 0xD5, 0x00
        },
        // 3
        {
        0xD5, 0xD5, 0xD5, 0xD5, 0xD5, 0xD5, 0xD5, 0x87, 0x88, 0x89, 0x8A, 0x8B, 0x8C, 0x8D, 0xD5, 0xD5, 0xD5, 0xD5, 0xD5, 0xD5, 0xD5,
        0xD5, 0xD5, 0xD5, 0xD5, 0xD5, 0xD5, 0xA6, 0xA7, 0xA8, 0xA9, 0xAA, 0xAB, 0xAC, 0xAD, 0xAE, 0xD5, 0xD5, 0xD5, 0xD5, 0xD5, 0xD5,
        0xD5, 0xD5, 0xD5, 0xD5, 0xD5, 0xD5, 0xD5, 0xC7, 0xC8, 0xC9, 0xCA, 0xCB, 0xCC, 0xCD, 0xD5, 0xD5, 0xD5, 0xD5, 0xD5, 0xD5, 0xD5, 0x00
        },
        // 4
        {
        0xD5, 0xD5, 0xD5, 0xD5, 0xD5, 0xD5, 0x86, 0x87, 0x88, 0x89, 0x8A, 0x8B, 0x8C, 0x8D, 0x8E, 0xD5, 0xD5, 0xD5, 0xD5, 0xD5, 0xD5,
        0xD5, 0xD5, 0xD5, 0xD5, 0xD5, 0xD5, 0xA6, 0xA7, 0xA8, 0xA9, 0xAA, 0xAB, 0xAC, 0xAD, 0xAE, 0xD5, 0xD5, 0xD5, 0xD5, 0xD5, 0xD5,
        0xD5, 0xD5, 0xD5, 0xD5, 0xD5, 0xD5, 0xC6, 0xC7, 0xC8, 0xC9, 0xCA, 0xCB, 0xCC, 0xCD, 0xCE, 0xD5, 0xD5, 0xD5, 0xD5, 0xD5, 0xD5, 0x00
        },
        // 6
        {
        0xD5, 0xD5, 0xD5, 0xD5, 0xD5, 0xD5, 0x86, 0x87, 0x88, 0x89, 0x8A, 0x8B, 0x8C, 0x8D, 0x8E, 0xD5, 0xD5, 0xD5, 0xD5, 0xD5, 0xD5,
        0xD5, 0xD5, 0xD5, 0xD5, 0xD5, 0xA5, 0xA6, 0xA7, 0xA8, 0xA9, 0xAA, 0xAB, 0xAC, 0xAD, 0xAE, 0xAF, 0xD5, 0xD5, 0xD5, 0xD5, 0xD5,
        0xD5, 0xD5, 0xD5, 0xD5, 0xD5, 0xD5, 0xC6, 0xC7, 0xC8, 0xC9, 0xCA, 0xCB, 0xCC, 0xCD, 0xCE, 0xD5, 0xD5, 0xD5, 0xD5, 0xD5, 0xD5, 0x00
        },
        // 7
        {
        0xD5, 0xD5, 0xD5, 0xD5, 0xD5, 0x85, 0x86, 0x87, 0x88, 0x89, 0x8A, 0x8B, 0x8C, 0x8D, 0x8E, 0x8F, 0xD5, 0xD5, 0xD5, 0xD5, 0xD5,
        0xD5, 0xD5, 0xD5, 0xD5, 0xD5, 0xA5, 0xA6, 0xA7, 0xA8, 0xA9, 0xAA, 0xAB, 0xAC, 0xAD, 0xAE, 0xAF, 0xD5, 0xD5, 0xD5, 0xD5, 0xD5,
        0xD5, 0xD5, 0xD5, 0xD5, 0xD5, 0xC5, 0xC6, 0xC7, 0xC8, 0xC9, 0xCA, 0xCB, 0xCC, 0xCD, 0xCE, 0xCF, 0xD5, 0xD5, 0xD5, 0xD5, 0xD5, 0x00
        },
        // 8
        {
        0xD5, 0xD5, 0xD5, 0xD5, 0xD5, 0x85, 0x86, 0x87, 0x88, 0x89, 0x8A, 0x8B, 0x8C, 0x8D, 0x8E, 0x8F, 0xD5, 0xD5, 0xD5, 0xD5, 0xD5,
        0xD5, 0xD5, 0xD5, 0xD5, 0xA4, 0xA5, 0xA6, 0xA7, 0xA8, 0xA9, 0xAA, 0xAB, 0xAC, 0xAD, 0xAE, 0xAF, 0xB0, 0xD5, 0xD5, 0xD5, 0xD5,
        0xD5, 0xD5, 0xD5, 0xD5, 0xD5, 0xC5, 0xC6, 0xC7, 0xC8, 0xC9, 0xCA, 0xCB, 0xCC, 0xCD, 0xCE, 0xCF, 0xD5, 0xD5, 0xD5, 0xD5, 0xD5, 0x00
        },
        // 9
        {
        0xD5, 0xD5, 0xD5, 0xD5, 0x84, 0x85, 0x86, 0x87, 0x88, 0x89, 0x8A, 0x8B, 0x8C, 0x8D, 0x8E, 0x8F, 0x90, 0xD5, 0xD5, 0xD5, 0xD5,
        0xD5, 0xD5, 0xD5, 0xD5, 0xA4, 0xA5, 0xA6, 0xA7, 0xA8, 0xA9, 0xAA, 0xAB, 0xAC, 0xAD, 0xAE, 0xAF, 0xB0, 0xD5, 0xD5, 0xD5, 0xD5,
        0xD5, 0xD5, 0xD5, 0xD5, 0xC4, 0xC5, 0xC6, 0xC7, 0xC8, 0xC9, 0xCA, 0xCB, 0xCC, 0xCD, 0xCE, 0xCF, 0xD0, 0xD5, 0xD5, 0xD5, 0xD5, 0x00
        },
        // 10
        {
        0xD5, 0xD5, 0xD5, 0xD5, 0x84, 0x85, 0x86, 0x87, 0x88, 0x89, 0x8A, 0x8B, 0x8C, 0x8D, 0x8E, 0x8F, 0x90, 0xD5, 0xD5, 0xD5, 0xD5,
        0xD5, 0xD5, 0xD5, 0xA3, 0xA4, 0xA5, 0xA6, 0xA7, 0xA8, 0xA9, 0xAA, 0xAB, 0xAC, 0xAD, 0xAE, 0xAF, 0xB0, 0xB1, 0xD5, 0xD5, 0xD5,
        0xD5, 0xD5, 0xD5, 0xD5, 0xC4, 0xC5, 0xC6, 0xC7, 0xC8, 0xC9, 0xCA, 0xCB, 0xCC, 0xCD, 0xCE, 0xCF, 0xD0, 0xD5, 0xD5, 0xD5, 0xD5, 0x00
        },
        // 11
        {
        0xD5, 0xD5, 0xD5, 0x83, 0x84, 0x85, 0x86, 0x87, 0x88, 0x89, 0x8A, 0x8B, 0x8C, 0x8D, 0x8E, 0x8F, 0x90, 0x91, 0xD5, 0xD5, 0xD5,
        0xD5, 0xD5, 0xD5, 0xA3, 0xA4, 0xA5, 0xA6, 0xA7, 0xA8, 0xA9, 0xAA, 0xAB, 0xAC, 0xAD, 0xAE, 0xAF, 0xB0, 0xB1, 0xD5, 0xD5, 0xD5,
        0xD5, 0xD5, 0xD5, 0xC3, 0xC4, 0xC5, 0xC6, 0xC7, 0xC8, 0xC9, 0xCA, 0xCB, 0xCC, 0xCD, 0xCE, 0xCF, 0xD0, 0xD1, 0xD5, 0xD5, 0xD5, 0x00
        },
        // 12
        {
        0xD5, 0xD5, 0xD5, 0x83, 0x84, 0x85, 0x86, 0x87, 0x88, 0x89, 0x8A, 0x8B, 0x8C, 0x8D, 0x8E, 0x8F, 0x90, 0x91, 0xD5, 0xD5, 0xD5,
        0xD5, 0xD5, 0xA2, 0xA3, 0xA4, 0xA5, 0xA6, 0xA7, 0xA8, 0xA9, 0xAA, 0xAB, 0xAC, 0xAD, 0xAE, 0xAF, 0xB0, 0xB1, 0xB2, 0xD5, 0xD5,
        0xD5, 0xD5, 0xD5, 0xC3, 0xC4, 0xC5, 0xC6, 0xC7, 0xC8, 0xC9, 0xCA, 0xCB, 0xCC, 0xCD, 0xCE, 0xCF, 0xD0, 0xD1, 0xD5, 0xD5, 0xD5, 0x00
        },
        // 13
        {
        0xD5, 0xD5, 0x82, 0x83, 0x84, 0x85, 0x86, 0x87, 0x88, 0x89, 0x8A, 0x8B, 0x8C, 0x8D, 0x8E, 0x8F, 0x90, 0x91, 0x92, 0xD5, 0xD5,
        0xD5, 0xD5, 0xA2, 0xA3, 0xA4, 0xA5, 0xA6, 0xA7, 0xA8, 0xA9, 0xAA, 0xAB, 0xAC, 0xAD, 0xAE, 0xAF, 0xB0, 0xB1, 0xB2, 0xD5, 0xD5,
        0xD5, 0xD5, 0xC2, 0xC3, 0xC4, 0xC5, 0xC6, 0xC7, 0xC8, 0xC9, 0xCA, 0xCB, 0xCC, 0xCD, 0xCE, 0xCF, 0xD0, 0xD1, 0xD2, 0xD5, 0xD5, 0x00
        },
        // 14
        {
        0xD5, 0xD5, 0x82, 0x83, 0x84, 0x85, 0x86, 0x87, 0x88, 0x89, 0x8A, 0x8B, 0x8C, 0x8D, 0x8E, 0x8F, 0x90, 0x91, 0x92, 0xD5, 0xD5,
        0xD5, 0xA1, 0xA2, 0xA3, 0xA4, 0xA5, 0xA6, 0xA7, 0xA8, 0xA9, 0xAA, 0xAB, 0xAC, 0xAD, 0xAE, 0xAF, 0xB0, 0xB1, 0xB2, 0xB3, 0xD5,
        0xD5, 0xD5, 0xC2, 0xC3, 0xC4, 0xC5, 0xC6, 0xC7, 0xC8, 0xC9, 0xCA, 0xCB, 0xCC, 0xCD, 0xCE, 0xCF, 0xD0, 0xD1, 0xD2, 0xD5, 0xD5, 0x00
        },
        // 15
        {
        0xD5, 0x81, 0x82, 0x83, 0x84, 0x85, 0x86, 0x87, 0x88, 0x89, 0x8A, 0x8B, 0x8C, 0x8D, 0x8E, 0x8F, 0x90, 0x91, 0x92, 0x93, 0xD5,
        0xD5, 0xA1, 0xA2, 0xA3, 0xA4, 0xA5, 0xA6, 0xA7, 0xA8, 0xA9, 0xAA, 0xAB, 0xAC, 0xAD, 0xAE, 0xAF, 0xB0, 0xB1, 0xB2, 0xB3, 0xD5,
        0xD5, 0xC1, 0xC2, 0xC3, 0xC4, 0xC5, 0xC6, 0xC7, 0xC8, 0xC9, 0xCA, 0xCB, 0xCC, 0xCD, 0xCE, 0xCF, 0xD0, 0xD1, 0xD2, 0xD3, 0xD5, 0x00
        },
        // 16
        {
        0xD5, 0x81, 0x82, 0x83, 0x84, 0x85, 0x86, 0x87, 0x88, 0x89, 0x8A, 0x8B, 0x8C, 0x8D, 0x8E, 0x8F, 0x90, 0x91, 0x92, 0x93, 0xD5,
        0xA0, 0xA1, 0xA2, 0xA3, 0xA4, 0xA5, 0xA6, 0xA7, 0xA8, 0xA9, 0xAA, 0xAB, 0xAC, 0xAD, 0xAE, 0xAF, 0xB0, 0xB1, 0xB2, 0xB3, 0xB4,
        0xD5, 0xC1, 0xC2, 0xC3, 0xC4, 0xC5, 0xC6, 0xC7, 0xC8, 0xC9, 0xCA, 0xCB, 0xCC, 0xCD, 0xCE, 0xCF, 0xD0, 0xD1, 0xD2, 0xD3, 0xD5, 0x00
        },
        // 17
        {
        0x80, 0x81, 0x82, 0x83, 0x84, 0x85, 0x86, 0x87, 0x88, 0x89, 0x8A, 0x8B, 0x8C, 0x8D, 0x8E, 0x8F, 0x90, 0x91, 0x92, 0x93, 0x94,
        0xA0, 0xA1, 0xA2, 0xA3, 0xA4, 0xA5, 0xA6, 0xA7, 0xA8, 0xA9, 0xAA, 0xAB, 0xAC, 0xAD, 0xAE, 0xAF, 0xB0, 0xB1, 0xB2, 0xB3, 0xB4,
        0xC0, 0xC1, 0xC2, 0xC3, 0xC4, 0xC5, 0xC6, 0xC7, 0xC8, 0xC9, 0xCA, 0xCB, 0xCC, 0xCD, 0xCE, 0xCF, 0xD0, 0xD1, 0xD2, 0xD3, 0xD4, 0x00
        }
    };

    uint8_t frame = (floor(get_current_wpm() / 5)) - 1;
    if (frame > 17){
        frame = 17;
    } else if (frame < 0 || !frame) {
        frame = 0;
    }

    oled_write_P(fp_logo[(abs(frame))], false);

}

static void render_status(void) {
    // Version information
    oled_write_P(PSTR("Lily58L rev1 fpazos\n"), false);

    // Host Keyboard Layer Status
    oled_write_P(PSTR("Layer: "), false);
    switch (get_highest_layer(layer_state)) {
        case _QWERTY:
            oled_write_P(PSTR("Default\n"), false);
            break;
        case _GAME:
            oled_write_P(PSTR("Game\n"), false);
            break;
        case _LOWER:
            oled_write_P(PSTR("Lower\n"), false);
            break;
        case _RAISE:
            oled_write_P(PSTR("Raise\n"), false);
            break;
        case _ADJUST:
            oled_write_P(PSTR("Adjust\n"), false);
            break;
        case _LOWERGAME:
            oled_write_P(PSTR("Game Low\n"), false);
            break;
        default:
            oled_write_P(PSTR("Undefined\n"), false);
    }

    // Host Keyboard LED Status
    uint8_t led_usb_state = host_keyboard_leds();
    oled_write_P(IS_LED_ON(led_usb_state, USB_LED_NUM_LOCK) ? PSTR("NUMLCK ") : PSTR("       "), false);
    oled_write_P(IS_LED_ON(led_usb_state, USB_LED_CAPS_LOCK) ? PSTR("CAPLCK ") : PSTR("       "), false);
    oled_write_P(IS_LED_ON(led_usb_state, USB_LED_SCROLL_LOCK) ? PSTR("SCRLCK") : PSTR("       "), false);

    oled_write_P(PSTR("WPM:"), false);
    sprintf(wpm_str, "%03d", get_current_wpm());
    oled_set_cursor(5,3);
    oled_write(wpm_str, false);
}

void oled_task_user(void) {
    if (is_keyboard_master()) {
        render_status(); // Renders the current keyboard state (layer, lock, caps, scroll, etc)
    } else {
        render_logo();  // Renders a static logo
        // oled_scroll_left();  // Turns on scrolling
    }
}
#endif

#ifdef ENCODER_ENABLE
void encoder_update_user(uint8_t index, bool clockwise) {
    if (index == 0) {
        // Volume control
        if (clockwise) {
            tap_code(KC_VOLU);
        } else {
            tap_code(KC_VOLD);
        }
    }
    else if (index == 1) {
        // Page up/Page down
        if (clockwise) {
            tap_code(KC_PGDN);
        } else {
            tap_code(KC_PGUP);
        }
    }
}
#endif
