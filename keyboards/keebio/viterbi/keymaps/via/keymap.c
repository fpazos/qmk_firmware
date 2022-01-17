#include QMK_KEYBOARD_H

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {


  LAYOUT_ortho_5x14(
    KC_ESC,KC_GRV, KC_1,  KC_2,  KC_3,      KC_4,     KC_5,               KC_6,KC_7,KC_8,KC_9,KC_0,KC_MINS,KC_EQL,
   KC_BSPC,KC_CAPS,KC_Q,  KC_W,  KC_E,      KC_R,     KC_T,               KC_Y,KC_U,KC_I,KC_O,KC_P,KC_LBRC,KC_RBRC,
   KC_PGDN,KC_TAB, KC_A,  KC_S,  KC_D,      KC_F,     KC_G,               KC_H,KC_J,KC_K,KC_L,KC_SCLN,KC_QUOT,KC_NUHS,
   KC_LSFT,KC_NUBS,KC_Z,  KC_X,  KC_C,      KC_V,     KC_B,               KC_N,KC_M,KC_COMM,KC_DOT,KC_SLSH,KC_UP,RSFT_T(KC_ENT),
   KC_END,KC_LCTL,KC_LGUI,KC_INS,LALT_T(KC_SPC),TT(1),KC_BSPC,            KC_SPC,RALT_T(KC_BSPC),TT(2),KC_RCTL,KC_LEFT,KC_DOWN,KC_RGHT
  ),

  LAYOUT_ortho_5x14(
    _______,_______,KC_F1,KC_F2,KC_F3,KC_F4,KC_F5,                            KC_F6,KC_F7,KC_F8,KC_F9,KC_F10,KC_F11,KC_F12,
    KC_DEL,_______,_______,KC_TILD,ALGR(KC_1),KC_CIRC,C(KC_F5),             _______,_______,_______,_______,_______,_______,_______,
    KC_PGUP,_______,_______,RALT(KC_QUOT),RALT(KC_LBRC),RSFT(KC_8),KC_G,    KC_H,RSFT(KC_9),RALT(KC_RBRC),RALT(KC_NUHS),KC_SCLN,KC_QUOT,KC_NUHS,
    _______,_______,RSFT(KC_5),RSFT(KC_RBRC),KC_SLSH,KC_RBRC,RSFT(KC_7),    ALGR(KC_GRV),_______,_______,_______,_______,_______,_______,
    KC_HOME,_______,_______,KC_PSCR,_______,_______,KC_DEL,                 _______,_______,_______,_______,_______,_______,_______
  ),

  LAYOUT_ortho_5x14(
    _______,_______,_______,_______,_______,_______,_______,           KC_6,    KC_P7,KC_P8,KC_P9,KC_PPLS,     KC_MINS,KC_EQL,
    _______,_______,_______,_______,_______,_______,_______,           KC_NLCK, KC_P4, KC_P5,  KC_P6, KC_PMNS, _______, _______,
    _______,_______,KC_MRWD,KC_MSTP,KC_MPLY,KC_MFFD,_______,           _______, KC_P1, KC_P2,  KC_P3, KC_PAST, _______, _______,
    _______,_______,_______,KC_MUTE,KC_VOLD,KC_VOLU,_______,           _______, KC_P0, KC_P0,  KC_PDOT, KC_PSLS, _______, KC_PENT,
    _______,_______,_______,KC_NLCK,_______,_______,_______,           _______,_______,_______,_______,_______,_______,_______
  ),

  LAYOUT_ortho_5x14(
    _______, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,       KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  _______,
    _______, _______, RESET  , RGB_TOG, RGB_MOD, RGB_HUD, RGB_HUI,     RGB_SAD, RGB_SAI, RGB_VAD, RGB_VAI, _______, KC_DEL,  _______,
    _______, _______, _______, _______, AU_ON,   AU_OFF,  AG_NORM,     AG_SWAP, _______,  _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______,     _______, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______,     _______, _______, _______, _______, _______, _______, _______
  )

};
