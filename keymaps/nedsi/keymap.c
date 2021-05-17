#include QMK_KEYBOARD_H
#include "keymap.h"
#include "accented_letters.h"
#include <stdio.h>

// Tap dance states
typedef enum {
  SINGLE_TAP,
  SINGLE_HOLD,
  DOUBLE_SINGLE_TAP
} td_state_t;

// create a global instance of the tapdance state type
static td_state_t td_state;

// function to track the current tapdance state
int cur_dance (qk_tap_dance_state_t *state);


// track the tapdance state to return
int cur_dance (qk_tap_dance_state_t *state) {
  if (state->count == 1) {
    if (state->interrupted || !state->pressed) {
        return SINGLE_TAP;
    } else {
        return SINGLE_HOLD;
    }
  }
  if (state->count == 2) {
      return DOUBLE_SINGLE_TAP;
  }
  else {
      return 3; // any number higher than the maximum state value you return above
  }
};

// handle the possible states for each tapdance keycode you define:

// `finished` function for each tapdance keycode
void CA_CC_CV_finished (qk_tap_dance_state_t *state, void *user_data);

void CA_CC_CV_finished (qk_tap_dance_state_t *state, void *user_data) {
  td_state = cur_dance(state);
  switch (td_state) {
    case SINGLE_TAP:
      tap_code16(C(KC_C));
      break;
    case SINGLE_HOLD:
      tap_code16(C(KC_V));
      break;
    case DOUBLE_SINGLE_TAP:
      tap_code16(C(KC_A));
      break;
  }
};

// `finished` function for each tapdance keycode
void UNI_W_L_finished (qk_tap_dance_state_t *state, void *user_data);

void UNI_W_L_finished (qk_tap_dance_state_t *state, void *user_data) {
  td_state = cur_dance(state);
  switch (td_state) {
    case SINGLE_TAP:
      tap_code16(UC_M_WC);
      break;
    case DOUBLE_SINGLE_TAP:
      tap_code16(UC_M_LN);
    break;
    default: break;
  }
};

// `finished` function for each tapdance keycode
void NXT_PRV_finished (qk_tap_dance_state_t *state, void *user_data);

void NXT_PRV_finished (qk_tap_dance_state_t *state, void *user_data) {
  td_state = cur_dance(state);
  switch (td_state) {
    case SINGLE_TAP:
      tap_code16(KC_MNXT);
      break;
    case DOUBLE_SINGLE_TAP:
      tap_code16(KC_MPRV);
    break;
    default: break;
  }
};

qk_tap_dance_action_t tap_dance_actions[] = {
    [CA_CC_CV] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, CA_CC_CV_finished, NULL),
    [UNI_W_L] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, UNI_W_L_finished, NULL),
    [NXT_PRV] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, NXT_PRV_finished, NULL),
};

/*
 * Per key tapping term settings
 */
uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case HOME_A:
            return TAPPING_TERM + 50;
        case HOME_S:
            return TAPPING_TERM + 50;
        /* case HOME_D: */
        /*     return TAPPING_TERM - 20; */
        case HOME_F:
            return TAPPING_TERM - 20;
        case HOME_G:
            return TAPPING_TERM - 10;
        case HOME_H:
            return TAPPING_TERM - 10;
        case HOME_J:
            return TAPPING_TERM - 20;
        /* case HOME_K: */
        /*     return TAPPING_TERM - 20; */
        case HOME_L:
            return TAPPING_TERM + 50;
        case HOME_SCLN:
            return TAPPING_TERM + 50;
        default:
            return TAPPING_TERM;
    }
};


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_MAIN] = LAYOUT_split_3x5_3(
    KC_Q,   KC_W,   KC_E,   KC_R,   KC_T,                               KC_Y,    KC_U,    KC_I,    KC_O,       KC_P,
    HOME_A, HOME_S, HOME_D, HOME_F, HOME_G,                             HOME_H,  HOME_J,  HOME_K,  HOME_L,  HOME_SCLN,
    KC_Z,   KC_X,   KC_C,   KC_V,   KC_B,                               KC_N,    KC_M, KC_COMM,  KC_DOT,    KC_SLSH,
                    MO(_SYMBOLS), KC_TAB, CACCCV,                       KC_MPLY, KC_SPC, MO(_NUMBERS)
    ),

    [_GAMING] = LAYOUT_split_3x5_3( 
      KC_Q,   KC_W,   KC_E,   KC_R,   KC_T,                             KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,
      KC_A,   KC_S,   KC_D,   KC_F,   KC_G,                             KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN,
      KC_Z,   KC_X,   KC_C,   KC_V,   KC_B,                             KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH,
                      LT(_SYMBOLS, KC_ESC), KC_SPC, KC_LSFT,            KC_LALT, KC_SPC, LT(_NUMBERS, KC_ENT)
    ),

    [_SYMBOLS] = LAYOUT_split_3x5_3( 
      _______, _______, _______,    DEGR,  KC_DQT,                      KC_PIPE, KC_HASH, KC_LCBR, KC_RCBR, _______,
      _______, KC_TILD, KC_ASTR,  KC_GRV, KC_QUOT,                        KC_AT, KC_EXLM, KC_LBRC, KC_RBRC,  KC_DLR,
      _______, _______, KC_PERC, KC_CIRC, KC_MINS,                      KC_AMPR, KC_PLUS, KC_LPRN, KC_RPRN, KC_BSLS,
                        _______, _______, _______,                      _______,  KC_EQL,MO(_NAV)
    ),

    [_ACCENTS] = LAYOUT_split_3x5_3(  
      _______, _______, E_ACUTE, E_GRAVE, _______,                      DED_UML, U_GRAVE, I_CIRCU, O_CIRCU, _______,
      A_GRAVE, A_CIRCU, E_CIRCU, _______, _______,                      DED_CIR, _______, _______, _______, _______,
      _______, _______, C_CDILA, _______, _______,                      _______, _______, _______, _______, _______,
                        _______, _______, _______,                      _______, _______, _______
    ),

    [_NUMBERS] = LAYOUT_split_3x5_3( 
      KC_F9  , KC_F10 , KC_F11 , KC_F12 , _______,                      _______, KC_7,    KC_8,    KC_9,    _______,
      KC_F5  , KC_F6  , KC_F7  , KC_F8  , _______,                      KC_PPLS, KC_4   , KC_5   , KC_6   ,    KC_0,
      KC_F1  , KC_F2  , KC_F3  , KC_F4  , _______,                      _______, KC_1   , KC_2   , KC_3   ,  KC_DOT,
                       MO(_NAV), _______, _______,                      _______, _______, _______
    ),

    [_NAV] = LAYOUT_split_3x5_3( 
      _______, _______, _______, _______, _______,                      KC_HOME, KC_PGDN, KC_PGUP, KC_END , _______,
      KC_LGUI, KC_LALT, KC_LCTL, KC_LSFT, _______,                      KC_LEFT, KC_DOWN, KC_UP  , KC_RGHT, _______,
      _______, _______, _______, _______, _______,                      _______,A(KC_SPC),G(C(KC_LEFT)),G(C(KC_RGHT)), _______,
                        _______, _______, _______,                      _______, _______, _______
    )
};


#ifdef ENCODER_ENABLE
void encoder_update_user(uint8_t index, bool clockwise) {
  if (clockwise) {
      tap_code16(KC_VOLU);
  } else {
      tap_code16(KC_VOLD);
  }
}
#endif
