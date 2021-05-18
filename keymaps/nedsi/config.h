#pragma once

#ifdef OLED_DRIVER_ENABLE
  #define OLED_DISPLAY_128X64
#endif

#ifdef RGBLIGHT_ENABLE
  #define RGBLIGHT_HUE_STEP 8
  #define RGBLIGHT_SAT_STEP 8
  #define RGBLIGHT_VAL_STEP 8
#endif

#ifdef ENCODER_ENABLE
#    define ENCODER_DIRECTION_FLIP
#    define ENCODER_RESOLUTION 2
#endif

#define NO_ACTION_MACRO
#define TAPPING_TERM 170
#define TAPPING_TERM_PER_KEY

// Prevent normal rollover on alphas from accidentally triggering mods.
#define IGNORE_MOD_TAP_INTERRUPT

// This prevents accidental repeats of the tap-hold keys when typing quickly.
#define TAPPING_FORCE_HOLD

// This prevents short hold periods to be interpreted as individual taps when typing quickly.
#define PERMISSIVE_HOLD

#define COMBO_TERM 70

#define UNICODE_SELECTED_MODES UC_WINC
/* #define UNICODE_KEY_LNX LCTL(LSFT(KC_E)) */
