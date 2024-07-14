// Copyright 2023 QMK
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H

enum tap_dance_codes {
  DANCE_E,  // Polska litera ę
  DANCE_O,  // Polska litera ó
  DANCE_A,  // Polska litera ą
  DANCE_S,  // Polska litera ś
  DANCE_L,  // Polska litera ł
  DANCE_Z,  // Polska litera ż
  DANCE_X,  // Polska litera ź
  DANCE_C,  // Polska litera ć
  DANCE_N,  // Polska litera ń
  DANCE_1,  // KC_DOT(.)    KC_EXLM(!)     KC_DOT/KC_DOT   KC_DOT
  DANCE_3,  // KC_SLASH(/)  (S(KC_MINS))(_)    KC_SLASH/KC_SLASH   KC_SLASH
  DANCE_15, // KC_SPACE     KC_UNDS(_)   KC_SPACE/KC_SPACE    KC_SPACE
  DANCE_31, // Win+Shift+S for screen shots
  DANCE_32, // KC_QUOTE(')     (LGUI(KC_QUOTE))    KC_GRAVE(`)    KC_GRAVE(`)
  DANCE_33, // (LALT(KC_3))     (LALT(LSFT(KC_2)))  (LALT(KC_3))/(LALT(KC_3))   (LALT(KC_3))
  DANCE_54, // KC_ESCAPE    (LALT(LGUI(KC_ESCAPE)))     KC_ESCAPE/KC_ESCAPE     KC_ESCAPE <- not used
  DANCE_55, // KC_Q     KC_H <- not used
  DANCE_56, // KC_TAB   (LGUI(KC_TAB))
  DANCE_57, // KC_DELETE    (LCTL(KC_K))
  DANCE_58, // KC_GRAVE     (LGUI(KC_GRAVE)) <- not used
  DANCE_59, // KC_SPACE     (LGUI(KC_O))
  DANCE_60, // KC_LEFT      (LALT(KC_LEFT))
  DANCE_63, // KC_RIGHT     (LGUI(KC_RIGHT))
  BKSL_HME, // KC_BSLS      KC_HOME
  PIPE_END, // KC_PIPE      KC_END
  CTRL_HOME, // KC_LBRC      CTRL+HOME
  CTRL_END, // KC_RBRC      CTRL+HOME
  MID_CLICK, // KC_MS_BTN1         KC_MS_BTN3
  SCREEN_CLIP, // KC_QUOTE          Win+Shift+S for screen shots
  RESET_MCU, // KC_NUM          RESET
  PRNT_SCRN, // KC_SCRL     KC_PSCR
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [0] = LAYOUT_ortho_3x5_2(
  // Base Layer - Letter Keys
  //---------------------------------------------------------------------------------------       ----------------------------------------------------------------------------------
    KC_Q,   KC_W,   KC_E,   KC_R,   KC_T,                                                         KC_Y,   KC_U,   KC_I,   KC_O,  KC_P,
  //------------------------------------------------------------------------------                ----------------------------------------------------------------------------
    KC_A,   KC_S,   MT(MOD_LALT,KC_D),    MT(MOD_LGUI,KC_F),    KC_G,  	                          KC_H,   MT(MOD_RGUI,KC_J),   MT(MOD_RALT,KC_K),  KC_L,  KC_SEMICOLON,
  //------------------------------------------------------------------------------                ----------------------------------------------------------------------------
    KC_Z,   KC_X,   KC_C,   KC_V,   KC_B,                                                         KC_N,   KC_M,   KC_COMMA,   KC_DOT,   KC_SLASH,
  //---------------------------------------------------------------------------------------       ----------------------------------------------------------------------------------
    OSM(MOD_LSFT),    MT(MOD_MEH,KC_SPACE),                                                       TO(1),  OSM(MOD_RCTL)
  //---------------------------------------------------------------------------------------       ----------------------------------------------------------------------------------
  ),

  [1] = LAYOUT_ortho_3x5_2(
  // Symbols Layer
  //------------------------------------------------------------------------------------       ----------------------------------------------------------------------------------
    KC_ESCAPE,  KC_GRAVE,   KC_PIPE,   KC_QUOT,     KC_DOT,                                    KC_MINS,    KC_7,   KC_8,   KC_9,   KC_BSPC,
  //------------------------------------------------------------------------------------       ----------------------------------------------------------------------------------
    KC_TAB,     TD(BKSL_HME),   LSFT(KC_LBRC),  LSFT(KC_RBRC),  KC_SEMICOLON,                  KC_EQL, KC_4,   KC_5,   KC_6,   KC_ENTER,
  //------------------------------------------------------------------------------------       ----------------------------------------------------------------------------------
    KC_TILD,    KC_LBRC,    KC_LPRN,    KC_RPRN,   KC_RBRC,                                    KC_0,   KC_1,   KC_2,   KC_3,   KC_DELETE,
  //------------------------------------------------------------------------------------       ----------------------------------------------------------------------------------
    OSM(MOD_LSFT),    TO(0),                                                                   TO(2),    KC_LALT
  ),

  [2] = LAYOUT_ortho_3x5_2(
  // Navigation Layer
  //--------------------------------------------------------------------------------          ----------------------------------------------------------------------------------
    KC_ESCAPE,  KC_MS_WH_LEFT,  KC_MS_UP,   KC_MS_WH_RIGHT,  KC_PGUP,                         LCTL(LSFT(KC_TAB)), LALT(KC_LEFT),  KC_UP,   LALT(KC_RIGHT),  KC_BSPC,
  //--------------------------------------------------------------------------------          ----------------------------------------------------------------------------------
    KC_TAB,   KC_MS_LEFT, KC_MS_DOWN, KC_MS_RIGHT,    MT(MOD_LGUI,KC_DEL),                    RCTL(KC_TAB),   KC_LEFT,   KC_DOWN, KC_RIGHT,   KC_ENTER,
  //--------------------------------------------------------------------------------          ----------------------------------------------------------------------------------
    OSM(MOD_LCTL),   KC_MS_WH_UP,    KC_MS_WH_DOWN,  KC_MS_BTN2, KC_PGDN,                     KC_MS_BTN1,     TD(CTRL_HOME),   KC_INS,   TD(CTRL_END),   KC_DELETE,
  //--------------------------------------------------------------------------------          ----------------------------------------------------------------------------------
    OSM(MOD_LSFT),    TO(0),                                                                  TO(3),    KC_LALT
  ),

  [3] = LAYOUT_ortho_3x5_2(
  // Audio/Function Keys layer
  //--------------------------------------------------------------------------------------------------      -----------------------------------------------------
    KC_ESCAPE,  KC_MEDIA_PLAY_PAUSE,    KC_MEDIA_PREV_TRACK,    KC_MEDIA_NEXT_TRACK,    TD(PRNT_SCRN),      KC_F9,  KC_F10,  KC_F11,    KC_F12,  KC_BSPC,
  //--------------------------------------------------------------------------------------------------      -----------------------------------------------------
    KC_TAB,     KC_MUTE,    KC_AUDIO_VOL_DOWN,  KC_AUDIO_VOL_UP,    KC_PAUS,                                KC_F5,  KC_F6,   KC_F7,     KC_F8,   KC_ENTER,
  //---------------------------------------------------------------------------------------------------     -----------------------------------------------------
    KC_CAPS,    KC_KP_ASTERISK, KC_BRIGHTNESS_DOWN, KC_BRIGHTNESS_UP,   /*TD(RESET_MCU)*/ QK_BOOT,          KC_F1,  KC_F2,   KC_F3,     KC_F4,   KC_DELETE,
  //---------------------------------------------------------------------------------------------------     -----------------------------------------------------
	  OSM(MOD_LSFT),    TO(0),                                                                                TO(4),    KC_LALT
  ),

  [4] = LAYOUT_ortho_3x5_2(
  // Gaming layer
  //--------------------------------------------------------------------------------------------------      -----------------------------------------------------
    KC_TAB,    KC_Q,     KC_W,     KC_E,     KC_R,                                                          KC_T,    KC_NO,    KC_NO,    KC_NO,  KC_NO,
  //--------------------------------------------------------------------------------------------------      -----------------------------------------------------
    KC_LEFT_SHIFT,     KC_A,    KC_S,    KC_D,    KC_F,                                                     KC_H,  KC_NO,   KC_NO,     KC_NO,   KC_NO,
  //---------------------------------------------------------------------------------------------------     -----------------------------------------------------
    KC_LCTL,   KC_Z,   KC_X,   KC_C,   KC_V,                                                                KC_NO,  KC_M,   KC_NO,     KC_NO,   KC_NO,
  //---------------------------------------------------------------------------------------------------     -----------------------------------------------------
    KC_NO,  KC_SPACE,                                                                                       TO(0),    KC_NO
  )
};

