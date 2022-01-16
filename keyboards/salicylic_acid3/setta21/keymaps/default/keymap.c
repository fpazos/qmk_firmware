#include QMK_KEYBOARD_H


#ifdef RGBLIGHT_ENABLE
//Following line allows macro to read current RGB settings
extern rgblight_config_t rgblight_config;
#endif

extern uint8_t is_master;

// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.
enum layer_number {
  _BASE,
  _MEDIA,
  _ARROW,
  _ADJUST,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_BASE] = LAYOUT_numpad_6x4(
      //,-----------------------------------|
       KC_ESC, TG(_MEDIA), KC_EQL,  KC_BSPC,
      //|--------+--------+--------+--------|
          KC_NLCK, KC_PSLS, KC_PAST, KC_PMNS,
      //|--------+--------+--------+--------|
            KC_P7,   KC_P8,   KC_P9, KC_PPLS,
      //|--------+--------+--------+--------|
            KC_P4,   KC_P5,   KC_P6,
      //|--------+--------+--------+--------|
            KC_P1,   KC_P2,   KC_P3, KC_PENT,
      //|--------+--------+--------+--------|
            LT(_ARROW, KC_P0), KC_PDOT
      //`-----------------------------------'
  ),

  [_MEDIA] = LAYOUT_numpad_6x4(
      //,-----------------------------------|
          KC_MPRV, KC_MSTP, KC_MPLY, KC_MNXT,
      //|--------+--------+--------+--------|
           KC_F13,  KC_F14, KC_MUTE, KC_VOLD,
      //|--------+--------+--------+--------|
           KC_F16,  KC_F17,  KC_F18, KC_VOLU,
      //|--------+--------+--------+--------|
           KC_F19,  KC_F20,  KC_F21,
      //|--------+--------+--------+--------|
       TG(_MEDIA), _______, _______, _______,
      //|--------+--------+--------+--------|
             MO(_ADJUST),    _______
      //`-----------------------------------'
  ),

  [_ARROW] = LAYOUT_numpad_6x4(
      //,-----------------------------------|
           KC_ESC, _______, _______, _______,
      //|--------+--------+--------+--------|
          _______, _______, _______, KC_PGUP,
      //|--------+--------+--------+--------|
          KC_HOME,   KC_UP,  KC_END, KC_PGDN,
      //|--------+--------+--------+--------|
          KC_LEFT, KC_DOWN,KC_RIGHT,
      //|--------+--------+--------+--------|
          _______, KC_DOWN, _______, _______,
      //|--------+--------+--------+--------|
             MO(_ARROW),    _______
      //`-----------------------------------'
  ),

  [_ADJUST] = LAYOUT_numpad_6x4( /* Base */
      //,-----------------------------------|
      MO(_ADJUST), _______, _______, _______,
      //|--------+--------+--------+--------|
          XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
      //|--------+--------+--------+--------|
          RGB_SAD, RGB_SAI, XXXXXXX, RGB_TOG,
      //|--------+--------+--------+--------|
          RGB_HUD, RGB_HUI, XXXXXXX,
      //|--------+--------+--------+--------|
          RGB_VAD, RGB_VAI, XXXXXXX, RGB_MOD,
      //|--------+--------+--------+--------|
                MO(_ADJUST),      XXXXXXX
      //`-----------------------------------'
  )
};
