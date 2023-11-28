/* layer template

    [FOO] = LAYOUT(
        XX,      XX,      XX,      XX,      XX,      XX,      XX,                XX,      XX,      XX,      XX,      XX,      XX,      XX,
        XX,      XX,      XX,      XX,      XX,      XX,      XX,                XX,      XX,      XX,      XX,      XX,      XX,      XX,
        XX,      XX,      XX,      XX,      XX,      XX,      XX,                XX,      XX,      XX,      XX,      XX,      XX,      XX,
        XX,      XX,      XX,      XX,      XX,      XX,                                  XX,      XX,      XX,      XX,      XX,      XX,
        XX,      XX,      XX,      XX,      XX,          XX,                          XX,          XX,      XX,      XX,      XX,      XX,
                                                XX,      XX,      XX,        XX,      XX,      XX
    ),
*/


#include QMK_KEYBOARD_H
#include "version.h"

// 'syntax' definition
#define XX KC_NO    // blocked out
#define __ KC_TRANS // transparent

// button definitions
#define M_TL  MO(TL)  // Enter the left-thumb layer
#define M_TLP MO(TLP) // Enter the left-thumb-pinky layer
#define M_TR  MO(TR)  // Enter the left-thumb-pinky layer
#define M_SYS MO(SYS) // Enter the sys-layer
#define G_KMA DF(KMA) // Switch to the kmonad-compat layer
#define G_COL DF(COL) // Switch to the base layer

#define RGB_TLC TOGGLE_LAYER_COLOR // Some moonlander builtin I want to try


enum custom_keycodes {
  C_SLD = SAFE_RANGE,
  C_RED,
  C_GRN,
  C_BLU,
};


// layer names
enum layers {
    COL, // base colemak layer
    TL,  // left-thumb layer: numpad and symbols
    TLP, // left-thumb+pinky layer: arrows and more symbols
    TR,  // right-thumb: some brackets
    KMA, // kmonad-compat layer
    SYS, // LEDs, booting, KMA-switching
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [COL] = LAYOUT(
        XX,      KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    XX,                XX,      KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    XX,
        XX,      KC_Q,    KC_W,    KC_F,    KC_P,    KC_G,    XX,                XX,      KC_J,    KC_L,    KC_U,    KC_Y,    XX,      XX,
        XX,      KC_A,    KC_R,    KC_S,    KC_T,    KC_D,    KC_ESC,            XX,      KC_H,    KC_N,    KC_E,    KC_I,    KC_O,    KC_ENT,
        XX,      KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,                                KC_K,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, XX,
        M_SYS,   KC_TAB,    XX,    KC_LSFT, KC_LCTL,     XX,                          XX,          KC_LGUI, KC_MINS, KC_LALT, KC_ENT,  XX,
                                                M_TL,    XX,      XX,         XX,     M_TR,        KC_SPC
    ),

    [TL] = LAYOUT(
        XX,      KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   XX,                XX,      KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,
        XX,      KC_COLN, KC_BSLS, KC_LPRN, KC_RPRN, KC_GRV,  XX,                XX,      XX,      KC_7,    KC_8,    KC_9,    XX,      KC_F12,
        XX,      M_TLP,   KC_DQUO, KC_QUOT, KC_UNDS, XX,      XX,                XX,      KC_BSPC, KC_4,    KC_5,    KC_6,    XX,      XX,
        XX,      KC_PIPE, KC_TILD, XX,      XX,      XX,                                  KC_EQL,  KC_1,    KC_2,    KC_3,    KC_PLUS, XX,
        XX,      XX,      XX,      XX,      XX,          XX,                          XX,          KC_0,    XX,      XX,      KC_ENT,  XX,
                                                XX,      XX,      XX,        XX,      XX,     KC_SPC
    ),

    [TLP] = LAYOUT(
        XX,      XX,      XX,      XX,      XX,      XX,      XX,                XX,      XX,      XX,      XX,      XX,      XX,      XX,
        XX,      XX,      KC_PGUP, KC_UP,   KC_PGDN, XX,      XX,                XX,      XX,      KC_AMPR, KC_ASTR, XX,      XX,      XX,
        XX,      XX,      KC_LEFT, KC_DOWN, KC_RGHT, XX,      XX,                XX,      XX,      KC_DLR,  KC_PERC, KC_CIRC, XX,      XX,
        XX,      XX,      KC_HOME, KC_MUTE, KC_END,  XX,                                  KC_PLUS, KC_EXLM, KC_AT,   KC_HASH, XX,      XX,
        XX,      XX,      XX,      XX,      XX,          XX,                          XX,          XX,      XX,      XX,      XX,      XX,
                                                XX,      XX,      XX,        XX,      XX,      XX
    ),

    [TR] = LAYOUT(
        XX,      XX,      XX,      XX,      XX,      XX,      XX,                XX,      XX,      XX,      XX,      XX,      XX,      XX,
        XX,      XX,      KC_LBRC, KC_RBRC, XX,      XX,      XX,                XX,      XX,      XX,      XX,      XX,      XX,      XX,
        XX,      XX,      KC_LPRN, KC_RPRN, XX,      XX,      XX,                XX,      XX,      XX,      XX,      XX,      XX,      XX,
        XX,      XX,      KC_LCBR, KC_RCBR, XX,      XX,                                  XX,      XX,      XX,      XX,      XX,      XX,
        XX,      XX,      XX,      XX,      XX,          XX,                          XX,          XX,      XX,      XX,      XX,      XX,
                                                XX,      XX,      XX,        XX,      XX,      XX
    ),

    [KMA] = LAYOUT(
        KC_F1,   KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_F6,             KC_F13,  KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_F19,
        KC_F2,   KC_Q,    KC_W,    KC_F,    KC_P,    KC_G,    KC_F7,             KC_F14,  KC_J,    KC_L,    KC_U,    KC_Y,    KC_F18,  KC_F20,
        KC_F3,   KC_A,    KC_R,    KC_S,    KC_T,    KC_D,    KC_ESC,            KC_F15,  KC_H,    KC_N,    KC_E,    KC_I,    KC_O,    KC_ENT,
        KC_F4,   KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,                                KC_K,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_F21,
        M_SYS,   KC_TAB,  KC_F5,   KC_LSFT, KC_LCTL,     KC_F8,                       KC_F17,      KC_LGUI, KC_MINS, KC_LALT, KC_ENT,  KC_F22,
                                                KC_F9,   KC_F10,  KC_F11,     KC_F12, KC_F23,  KC_SPC
    ),

    [SYS] = LAYOUT(
        XX,      XX,      XX,      XX,      XX,      XX,      XX,                G_KMA,   G_COL,   XX,      XX,      XX,      XX,      QK_BOOT,
        XX,      XX,      XX,      XX,      XX,      XX,      XX,                XX,      XX,      XX,      XX,      XX,      XX,      XX,
        XX,      XX,      XX,      XX,      XX,      XX,      XX,                XX,      XX,      XX,      XX,      XX,      XX,      XX,
        XX,      XX,      XX,      XX,      XX,      XX,                                  XX,      XX,      XX,      XX,      XX,      XX,
        XX,      XX,      C_RED,   C_GRN,   C_BLU,       RGB_MOD,                     RGB_TOG,     XX,      XX,      XX,      XX,      XX,
                                                RGB_VAD, RGB_VAI, RGB_TLC,   C_SLD,   RGB_HUD, RGB_HUI
    ),
};



bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {

    case C_SLD:
        if (record->event.pressed) {
            rgblight_mode(1);
        }
        return false;
    case C_RED:
        if (record->event.pressed) {
            rgblight_mode(1);
            rgblight_sethsv(0,245,245);
        }
        return false;
      case C_GRN:
        if (record->event.pressed) {
            rgblight_mode(1);
            rgblight_sethsv(74,255,206);
        }
        return false;
      case C_BLU:
        if (record->event.pressed) {
            rgblight_mode(1);
            rgblight_sethsv(152,255,255);
        }
        return false;
    }
  return true;
}
