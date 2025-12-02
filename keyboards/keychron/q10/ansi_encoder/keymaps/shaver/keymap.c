/* Copyright 2022 @ Keychron (https://www.keychron.com)
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

#include QMK_KEYBOARD_H

// clang-format off

enum layers{
    MAC_BASE,
    MAC_FN,
    WIN_BASE,
    WIN_FN,
    WIN_NUMPAD
};

enum my_keycodes {
    KVM_PC1 = SAFE_RANGE,
    KVM_PC2,
    KVM_PC3,
    KVM_PC4,
};

#define KC_TASK LGUI(KC_TAB)
#define KC_FLXP LGUI(KC_E)
#define LAY_PAD MO(WIN_NUMPAD)

/* left hand home-row mods: A (GUI)    S (ALT)    D (SHIFT)   F (CTRL) */
#define GUI_A   LGUI_T(KC_A)
#define ALT_S   LALT_T(KC_S)
#define SFT_D   LSFT_T(KC_D)
#define CTL_F   LCTL_T(KC_F)

/* right hand home-row mods: J (CTRL)    K (SHIFT)   L (ALT)    ; (GUI) */
#define CTL_J   RCTL_T(KC_J)
#define SFT_K   RSFT_T(KC_K)
#define ALT_L   LALT_T(KC_L)  /* note: LALT here because RALT is used as compose */
#define GUI_SC  RGUI_T(KC_SCLN)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [MAC_BASE] = LAYOUT_ansi_89(
        KC_MUTE,  KC_ESC,   KC_F1,    KC_F2,    KC_F3,    KC_F4,    KC_F5,     KC_F6,    KC_F7,    KC_F8,    KC_F9,    KC_F10,   KC_F11,   KC_F12,   KC_INS,             KC_DEL,
        LAY_PAD,  KC_GRV,   KC_1,     KC_2,     KC_3,     KC_4,     KC_5,      KC_6,     KC_7,     KC_8,     KC_9,     KC_0,     KC_MINS,  KC_EQL,   KC_BSPC,            KC_PGUP,
        _______,  KC_TAB,   KC_Q,     KC_W,     KC_E,     KC_R,     KC_T,      KC_Y,     KC_U,     KC_I,     KC_O,     KC_P,     KC_LBRC,  KC_RBRC,  KC_BSLS,            KC_PGDN,
        _______,  KC_ESC,   KC_A,     KC_S,     KC_D,     KC_F,     KC_G,      KC_H,     KC_J,     KC_K,     KC_L,     KC_SCLN,  KC_QUOT,            KC_ENT,             KC_END,
        _______,  KC_LSFT,            KC_Z,     KC_X,     KC_C,     KC_V,      KC_B,     KC_B,     KC_N,     KC_M,     KC_COMM,  KC_DOT,   KC_SLSH,  KC_RSFT,  KC_UP,
        _______,  KC_LCTL,  KC_LWIN,            KC_LALT,  KC_SPC,  MO(WIN_FN),                     KC_SPC,             KC_RALT,                      KC_LEFT,  KC_DOWN,  KC_RGHT),

    [MAC_FN] = LAYOUT_ansi_89( /* unused */
        RM_TOGG,  _______,  KC_F1,    KC_F2,    KC_F3,    KC_F4,    KC_F5,     KC_F6,    KC_F7,    KC_F8,    KC_F9,    KC_F10,   KC_F11,   KC_F12,   _______,            _______,
        _______,  _______,  _______,  _______,  _______,  _______,  _______,   _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,            _______,
        _______,  RM_TOGG,  RM_NEXT,  RM_VALU,  RM_HUEU,  RM_SATU,  RM_SPDU,   _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,            _______,
        _______,  KC_CAPS,  RM_PREV,  RM_VALD,  RM_HUED,  RM_SATD,  RM_SPDD,   _______,  _______,  _______,  _______,  _______,  _______,            _______,            KC_HOME,
        _______,  _______,            _______,  _______,  _______,  _______,   _______,  _______,  NK_TOGG,  _______,  _______,  _______,  _______,  _______,  _______,
        _______,  _______,  _______,            _______,  _______,  _______,                       _______,            _______,                      _______,  _______,  _______),

    [WIN_BASE] = LAYOUT_ansi_89(
        KC_MUTE,  KC_ESC,   KC_F1,    KC_F2,    KC_F3,    KC_F4,    KC_F5,     KC_F6,    KC_F7,    KC_F8,    KC_F9,    KC_F10,   KC_F11,   KC_F12,   KC_INS,             KC_DEL,
        LAY_PAD,  KC_GRV,   KC_1,     KC_2,     KC_3,     KC_4,     KC_5,      KC_6,     KC_7,     KC_8,     KC_9,     KC_0,     KC_MINS,  KC_EQL,   KC_BSPC,            KC_PGUP,
        _______,  KC_TAB,   KC_Q,     KC_W,     KC_E,     KC_R,     KC_T,      KC_Y,     KC_U,     KC_I,     KC_O,     KC_P,     KC_LBRC,  KC_RBRC,  KC_BSLS,            KC_PGDN,
        _______,  KC_ESC,   GUI_A,    ALT_S,    SFT_D,    CTL_F,    KC_G,      KC_H,     CTL_J,    SFT_K,    ALT_L,    GUI_SC,   KC_QUOT,            KC_ENT,             KC_END,
        _______,  KC_LSFT,            KC_Z,     KC_X,     KC_C,     KC_V,      KC_B,     KC_B,     KC_N,     KC_M,     KC_COMM,  KC_DOT,   KC_SLSH,  KC_RSFT,  KC_UP,
        _______,  KC_LCTL,  KC_LWIN,            KC_LALT,  KC_SPC,  MO(WIN_FN),                     KC_SPC,             KC_RALT,                      KC_LEFT,  KC_DOWN,  KC_RGHT),

    [WIN_FN] = LAYOUT_ansi_89(
        KC_MPLY,  _______,  KC_BRID,  KC_BRIU,  KC_TASK,  KC_FLXP,  RM_VALD,   RM_VALU,  KC_MPRV,  KC_MPLY,  KC_MNXT,  KC_MUTE,  KC_VOLD,   KC_VOLU,  KC_SCRL,            KC_PSCR,
        _______,  _______,  _______,  _______,  _______,  _______,  _______,   _______,  _______,  _______,  _______,  _______,  _______,   _______,  _______,            RM_VALU,
        _______,  RM_TOGG,  RM_NEXT,  RM_VALU,  RM_HUEU,  RM_SATU,  RM_SPDU,   _______,  _______,  _______,  _______,  _______,  _______,   _______,  _______,            RM_VALD,
        QK_MAKE,  KC_CAPS,  RM_PREV,  RM_VALD,  RM_HUED,  RM_SATD,  RM_SPDD,   _______,  _______,  _______,  _______,  _______,  _______,             _______,            KC_HOME,
        DB_TOGG,  _______,            _______,  _______,  _______,  _______,   _______,  _______,  NK_TOGG,  _______,  _______,  _______,   _______,  _______,  _______,
        QK_BOOT,  _______,  _______,            _______,  _______,  _______,                       _______,            _______,                       _______,  _______,  _______),

    [WIN_NUMPAD] = LAYOUT_ansi_89(
        _______,  _______,  KVM_PC1,  KVM_PC2,  KVM_PC3,  KVM_PC4,  _______,   _______,  _______,  _______,  _______,  _______,  _______,   _______,  _______,            KC_PAUSE,
        _______,  _______,  KC_KP_1,  KC_KP_2,  KC_KP_3,  KC_KP_4,  KC_KP_5,   KC_KP_6,  KC_KP_7,  KC_KP_8,  KC_KP_9,  KC_KP_0,  KC_PMNS,   KC_PPLS,  _______,            _______,
        _______,  _______,  KC_KP_7,  KC_KP_8,  KC_KP_9,  _______,  _______,   _______,  _______,  KC_PAST,  _______,  _______,  _______,   _______,  _______,            _______,
        _______,  KC_NUM,   KC_KP_4,  KC_KP_5,  KC_KP_6,  _______,  _______,   _______,  _______,  _______,  _______,  _______,  _______,             KC_PENT,            _______,
        _______,  _______,            KC_KP_1,  KC_KP_2,  KC_KP_3,  _______,   _______,  _______,  _______,  _______,  _______,  KC_PDOT,   KC_PSLS,  _______,  _______,
        _______,  _______,  _______,            _______,  KC_PENT,  _______,                       _______,            _______,                       _______,  _______,  _______),

};

#if defined(ENCODER_ENABLE) && defined(ENCODER_MAP_ENABLE)
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][2] = {
    [MAC_BASE] =   { ENCODER_CCW_CW(KC_VOLD, KC_VOLU) },
    [MAC_FN]   =   { ENCODER_CCW_CW(KC_MPRV, KC_MNXT) },
    [WIN_BASE] =   { ENCODER_CCW_CW(KC_VOLD, KC_VOLU) },
    [WIN_FN]   =   { ENCODER_CCW_CW(KC_MPRV, KC_MNXT) },
    [WIN_NUMPAD] = { ENCODER_CCW_CW(KC_MPRV, KC_MNXT) }
};
#endif // ENCODER_MAP_ENABLE

enum combos {
    ZV_PASTE,
    ZC_COPY,
    COMBO_LENGTH
};

const uint16_t PROGMEM af_combo[] = { KC_A, KC_F, COMBO_END };
const uint16_t PROGMEM ad_combo[] = { KC_A, KC_D, COMBO_END };
const uint16_t PROGMEM zv_combo[] = { KC_Z, KC_V, COMBO_END };
const uint16_t PROGMEM zc_combo[] = { KC_Z, KC_C, COMBO_END };

uint16_t COMBO_LEN = COMBO_LENGTH;

combo_t key_combos[] = {
    [ZV_PASTE] = COMBO(zv_combo, LCTL(KC_V)),
    [ZC_COPY] = COMBO(zc_combo, LCTL(KC_C)),
};

bool rgb_matrix_indicators_advanced_user(uint8_t led_min, uint8_t led_max) {
    led_t state = host_keyboard_led_state();

    if (state.caps_lock) {
        RGB_MATRIX_INDICATOR_SET_COLOR(48, 255, 255, 255);
    }
    if (state.scroll_lock) {
        RGB_MATRIX_INDICATOR_SET_COLOR(84, 255, 255, 255);
    }
    if (state.num_lock) {
        RGB_MATRIX_INDICATOR_SET_COLOR(15, 255, 255, 255);
    }
    return false;
}

bool process_record_user(uint16_t keycode, keyrecord_t * record) {
    if (keycode < KVM_PC1 || keycode > KVM_PC4 || !record->event.pressed) {
        return true;
    }

 #define KVM_SWITCH(KEY_) SS_DOWN(X_SCRL) SS_UP(X_SCRL) SS_DOWN(X_SCRL) SS_UP(X_SCRL) SS_DOWN(KEY_) SS_UP(KEY_)
    switch (keycode) {
        case KVM_PC1: SEND_STRING_DELAY(KVM_SWITCH(X_1), 50); break;
        case KVM_PC2: SEND_STRING_DELAY(KVM_SWITCH(X_2), 50); break;
        case KVM_PC3: SEND_STRING_DELAY(KVM_SWITCH(X_3), 50); break;
        case KVM_PC4: SEND_STRING_DELAY(KVM_SWITCH(X_4), 50); break;
        default:;
    }
 #undef KVM_SWITCH

    return false;
}
