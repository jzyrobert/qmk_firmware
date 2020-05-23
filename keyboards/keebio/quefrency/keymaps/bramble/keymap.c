#include QMK_KEYBOARD_H

extern keymap_config_t keymap_config;

// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.
#define _BASE 0
#define _COLE 1
#define _FN1 2

enum custom_keycodes {
  QWERTY = SAFE_RANGE,
  EMAIL,
  SCHOOL_EMAIL,
  RICKROLL,
  PSVM
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_BASE] = LAYOUT_65(
    KC_GESC, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,  KC_BSPC,  KC_BSPC, KC_INSERT, \
    KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC, KC_RBRC, KC_BSLS, KC_DELETE, \
    KC_CAPS, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT, KC_ENT,  KC_PGUP, \
    KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT, KC_UP,   KC_PGDN, \
    OSL(_FN1), KC_LCTL, KC_LGUI, KC_LALT, KC_SPC,           KC_SPC, KC_SPC,  KC_RALT, KC_RCTL, DF(_COLE), KC_LEFT, KC_DOWN, KC_RGHT
  ),

  [_COLE] = LAYOUT_65(
    KC_GESC, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,  KC_CAPS,  KC_CAPS, KC_INSERT, \
    KC_TAB,  KC_Q,    KC_W,    KC_F,    KC_P,    KC_B,    KC_J,    KC_L,    KC_U,    KC_Y,    KC_SCLN,    KC_LBRC, KC_RBRC, KC_BSLS, KC_DELETE, \
    KC_BSPC, KC_A,    KC_R,    KC_S,    KC_T,    KC_G,    KC_K,    KC_N,    KC_E,    KC_I,    KC_O, KC_QUOT, KC_ENT,  KC_PGUP, \
    KC_LSFT, KC_X,    KC_C,    KC_D,    KC_V,    KC_Z,    KC_M,    KC_H,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT, KC_UP,   KC_PGDN, \
    OSL(_FN1), KC_LCTL, KC_LGUI, KC_LALT, KC_SPC,           KC_SPC, KC_SPC,  KC_RALT, KC_RCTL, DF(_BASE), KC_LEFT, KC_DOWN, KC_RGHT
  ),

  [_FN1] = LAYOUT_65(
    KC_GRV , KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_BSPC,  KC_BSPC, _______, \
    _______, _______, _______, EMAIL, RICKROLL, _______, _______, _______, _______, _______, PSVM, _______, _______, _______, _______, \
    KC_DEL,  _______, SCHOOL_EMAIL, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
    KC_TRNS, _______, _______, _______, _______,          _______, _______, _______, _______, _______, _______, _______, _______
  )
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode){
      case EMAIL:
        if (record->event.pressed) {
          SEND_STRING("jzyrobert@googlemail.com");
        }
        break;
      case SCHOOL_EMAIL:
        if (record->event.pressed) {
          SEND_STRING("rzj17@ic.ac.uk");
        }
        break;
      case RICKROLL:
        if (record->event.pressed) {
          SEND_STRING("https://www.youtube.com/watch?v=dQw4w9WgXcQ");
        }
        break;
      case PSVM:
        if (record->event.pressed) {
          SEND_STRING("public static void main");
        }
        break;
    }
    return true;
};
