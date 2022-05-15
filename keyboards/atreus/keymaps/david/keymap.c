// David Janssen, janssen.dhj@gmail.com, KMonad maintainer

#include QMK_KEYBOARD_H
/* #include "action_layer.h" */
/* #include "keymap_colemak.h" */

// Alias names to layer numbers
#define ALPH 0
#define NUMS 1
#define FKEY 2
#define GAME 3
#define KMO  4

// Alias names to layer-toggles
#define L_NUM  MO(NUMS) // Open the number layer while held
#define L_FKEY MO(FKEY) // Open the function-key layer while held

// Alias names to layer-switches
#define G_GAME TO(GAME) // Switch base layer to gaming
#define G_KMO  TO(KMO)  // Switch base layer to KMonad compat

// Aliases for shifted keycodes
#define S_DQUOT  S(KC_QUOT) // "
#define S_UNDER  S(KC_MINS) // _
#define S_TILDE  S(KC_GRV)  // ~
#define S_PIPE   S(KC_BSLS) // |
#define S_LPAR   S(KC_9)    // (
#define S_RPAR   S(KC_0)    // )
#define S_LCURL  S(KC_LBRC) // {
#define S_RCURL  S(KC_RBRC) // }

// Setup tap-dance for escaping base-state changes
enum {
  OUT = 0 // Tap once: /, tap twice, reset base-layer to ALPH
};

qk_tap_dance_action_t tap_dance_actions[] = {
  [OUT] = ACTION_TAP_DANCE_LAYER_MOVE(KC_SLSH, ALPH)
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  // Basic colemak layout
  [ALPH] = LAYOUT(
    KC_Q,    KC_W,    KC_F,    KC_P,    KC_G,                      KC_J,    KC_L,    KC_U,    KC_Y,    KC_SCLN,
    KC_A,    KC_R,    KC_S,    KC_T,    KC_D,                      KC_H,    KC_N,    KC_E,    KC_I,    KC_O,
    KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,                      KC_K,    KC_M,    KC_COMM, KC_DOT,  KC_LALT,
    KC_TAB,  KC_F4,   KC_F3,   KC_LSFT, KC_LCTL, L_NUM,   KC_ESC,  KC_SPC,  KC_LGUI, KC_MINS, KC_SLSH, KC_ENT
  ),

  // Basic numbers and symbols
  [NUMS] = LAYOUT(
    KC_NO,   KC_GRV,  S_TILDE, KC_LBRC, KC_RBRC,                   KC_NO,   KC_7,    KC_8,    KC_9,    KC_SLSH,
    KC_LSFT, S_DQUOT, S_UNDER, S_LPAR,  S_RPAR,                    KC_BSPC, KC_4,    KC_5,    KC_6,    KC_ASTR,
    KC_NO,   KC_QUOT, S_PIPE,  S_LCURL, S_RCURL,                   KC_EQL,  KC_1,    KC_2,    KC_3,    KC_MINS,
    KC_NO,   KC_NO,   KC_BSLS, KC_NO,   KC_NO,   KC_TRNS, L_FKEY,  KC_SPC,  KC_0,    KC_NO,   KC_DOT,  KC_PLUS
  ),

  // Function keys and utilities
  [FKEY] = LAYOUT(
    RESET,   KC_NO,   KC_NO,   KC_NO,   KC_NO,                     KC_NO,   KC_F7,   KC_F8,   KC_F9,   KC_F10,
    G_GAME,  KC_NO,   KC_NO,   KC_NO,   KC_NO,                     KC_NO,   KC_F4,   KC_F5,   KC_F6,   KC_F11,
    KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,                     KC_NO,   KC_F1,   KC_F2,   KC_F3,   KC_F12,
    G_KMO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO
  ),

  // Gaming layout with qwerty and left mod column
  [GAME] = LAYOUT(
    KC_ESC,  KC_Q,    KC_W,    KC_E,    KC_R,                      KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,
    KC_LCTL, KC_A,    KC_S,    KC_D,    KC_F,                      KC_G,    KC_H,    KC_J,    KC_K,    KC_L,
    KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,                      KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,
    KC_TAB,  KC_LALT, KC_M,    KC_ENT,  KC_SPC,  KC_NO,   KC_NO,   KC_LEFT, KC_RGHT, KC_SLSH, TD(OUT), KC_P
  ),

  // KMonad compat, no functionality except 1 tap-dance to escape
  [KMO] = LAYOUT(
    KC_Q,    KC_W,    KC_F,    KC_P,    KC_G,                      KC_J,    KC_L,    KC_U,    KC_Y,    KC_SCLN,
    KC_A,    KC_R,    KC_S,    KC_T,    KC_D,                      KC_H,    KC_N,    KC_E,    KC_I,    KC_O,
    KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,                      KC_K,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH,
    KC_TAB,  KC_F4,   KC_F5,   KC_LSFT, KC_LCTL, KC_F6,   KC_ESC,  KC_SPC,  KC_LGUI, KC_MINS, TD(OUT), KC_ENT
  )
};
