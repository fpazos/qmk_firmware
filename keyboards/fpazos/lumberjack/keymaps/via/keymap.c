/* Copyright 2020 Paul James
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

/* Por algún misterio del destino ha decidido que aquí no quería funcionar y lo he copiado, compilado y flasheado a través de la carpeta PEEJ/LUMBERJACK */

#include QMK_KEYBOARD_H

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

[0] = LAYOUT_ortho_5x12(
  KC_ESC,  KC_1,  KC_2,  KC_3,  KC_4,  KC_5,  KC_6,  KC_7,  KC_8,  KC_9,  KC_0,  KC_MINS,
  KC_GRV,  KC_Q,  KC_W,  KC_E,  KC_R,  KC_T,  KC_Y,  KC_U,  KC_I,  KC_O,  KC_P,  KC_RBRC,
  KC_TAB,  KC_A,  KC_S,  KC_D,  KC_F,  KC_G,  KC_H,  KC_J,  KC_K,  KC_L,  KC_SCLN, KC_QUOT,
  KC_LSFT, KC_Z,  KC_X,  KC_C,  KC_V,  KC_B,  KC_N,  KC_M,  KC_COMM, KC_DOT,  KC_SLSH, MT(MOD_LSFT,KC_ENT),
  KC_LCTL, KC_LALT, KC_NUBS, KC_LGUI, LT(2, KC_SPC),   KC_BSPC,  KC_SPC,  LT(3, KC_BSPC), KC_RALT, KC_RGUI, KC_RGHT, KC_LCTL
),
[1] = LAYOUT_ortho_5x12(
  KC_ESC,  KC_1,  KC_2,  KC_3,  KC_4,  KC_5,  KC_6,  KC_7,  KC_8,  KC_9,  KC_0,  KC_MINS,
  KC_CAPS, KC_Q,  KC_W,  KC_E,  KC_R,  KC_T,  KC_Y,  KC_U,  KC_I,  KC_O,  KC_P,  KC_RBRC,
  KC_TAB,  KC_A,  KC_S,  KC_D,  KC_F,  KC_G,  KC_H,  KC_J,  KC_K,  KC_L,  KC_SCLN, KC_QUOT,
  KC_LSFT, KC_Z,  KC_X,  KC_C,  KC_V,  KC_B,  KC_N,  KC_M,  KC_COMM, KC_DOT,  KC_SLSH, KC_ENT,
  KC_LCTL, KC_LALT, KC_GRV, KC_LGUI, LT(2, KC_BSPC),  KC_SPC,  KC_BSPC,  LT(3, KC_BSPC), KC_RALT, KC_RGUI, KC_RGHT, KC_RCTL
),
[2] = LAYOUT_ortho_5x12(
  KC_F12,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,
  KC_CAPS, RSFT(KC_0), ALGR(KC_1), KC_CIRC, RSFT(KC_1), C(KC_F5), KC_PSCR, RALT(KC_PSCR), RALT(KC_3), RALT(KC_2), KC_EQL, KC_LBRC,
  _______, RALT(KC_4), RALT(KC_QUOT),RALT(KC_LBRC),RSFT(KC_8),KC_MINS,KC_AT, RSFT(KC_9), ALGR(KC_RBRC), ALGR(KC_NUHS), SGUI(KC_R), KC_NUHS,
  RSFT(KC_5), RSFT(KC_RBRC), KC_SLSH, KC_RBRC, RSFT(KC_7), ALGR(KC_GRV),SGUI(KC_4), C(KC_Z), C(KC_Y), C(KC_V), C(KC_C), C(KC_X),
  _______, _______, _______, _______, _______, KC_DEL, KC_DEL, _______, _______, _______, _______, _______
),
[3] = LAYOUT_ortho_5x12(
  _______, _______, _______, _______,TG(1),_______, _______, _______, _______, _______, _______, KC_EQL,
  _______, KC_MPRV, KC_MSTP, KC_MPLY, KC_MNXT, _______, _______, _______,   KC_UP, _______, _______, _______,
  _______, KC_PGUP, KC_HOME,  KC_END, KC_PGDN, _______, _______, KC_LEFT, KC_DOWN, KC_RGHT, _______, _______,
  _______, _______, KC_MUTE, KC_VOLD, KC_VOLU, _______, LCA(KC_DEL), C(KC_INS), RSFT(KC_INS), _______, _______, _______,
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
)

};

void keyboard_pre_init_user() {
    writePin(LED1, true);
    writePin(LED2, true);
}

void keyboard_post_init_user() {
    writePin(LED1, false);
    writePin(LED2, false);
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    writePin(LED1, record->event.pressed);

    return true;
}

layer_state_t layer_state_set_user(layer_state_t state) {
    writePin(LED2, state);

    return state;
}
