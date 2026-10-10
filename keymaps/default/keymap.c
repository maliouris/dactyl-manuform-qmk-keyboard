#include QMK_KEYBOARD_H
#define TAPPING_TERM 200

#define _BASE 0
#define _LOWER 2
#define _NAV 3
#define _NUMS 4
#define _SHIFTED_NUMS 5
#define _ADJUST 6
#define _MEDIA 1

#define SFT_ESC  SFT_T(KC_ESC)
#define CTL_BSPC CTL_T(KC_BSPC)
#define ALT_SPC  ALT_T(KC_SPC)
#define SFT_ENT  SFT_T(KC_ENT)

#define KC_ML MS_LEFT
#define KC_MR MS_RGHT
#define KC_MU MS_UP
#define KC_MD MS_DOWN
#define KC_MB1 MS_BTN1
#define KC_MB2 MS_BTN1

#define RAISE OSL(_RAISE)
#define LOWER OSL(_LOWER)
#define NAV MO(_NAV)
#define NUMS OSL(_NUMS)
#define SHIFTED_NUMS OSL(_SHIFTED_NUMS)
#define ADJUST MO(_ADJUST)
#define SHIFT OS_LSFT
#define MEDIA MO(_MEDIA)

enum my_keycodes {
   KC_MUTE_MIC = SAFE_RANGE,
   KC_LANG
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /* Base (qwerty)
     * +-----------------------------------------+                             +-----------------------------------------+
     * | ESC  |   q  |   w  |   e  |   r  |   t  |                             |   y  |   u  |   i  |   o  |   p  |      |
     * |------+------+------+------+------+------|                             |------+------+------+------+------+------|
     * | TAB  |   a  |   s  |   d  |   f  |   g  |                             |   h  |   j  |   k  |   l  |   ;  |      |
     * |------+------+------+------+------+------|                             |------+------+------+------+------+------|
     * | SHFT |   z  |   x  |   c  |   v  |   b  |                             |   n  |   m  |   ,  |   .  |   /  |      |
     * +------+------+------+------+-------------+                             +-------------+------+------+------+------+
     *               									     |  [   |   ]  |            
     *               +-------------+-------------+                             +-------------+-------------+
     *                             |      |      |                             |      |      |
     *                             |------+------|                             |------+------|
     *                             |      |      |                             |      |      |
     *                             +-------------+                             +-------------+
     *                                           +-------------+ +-------------+
     *                                           |      |      | |      |      |
     *                                           |------+------| |------+------|
     *                                           |      |      | |      |      |
     *                                           +-------------+ +-------------+
     */
    [_BASE] = LAYOUT(
        KC_ESC,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,               KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSPC,
        KC_TAB,  LCTL_T(KC_A), LSFT_T(KC_S), LALT_T(KC_D),  LGUI_T(KC_F),  KC_G,                     KC_H,     RGUI_T(KC_J),  RALT_T(KC_K), RSFT_T(KC_L), RCTL_T(KC_SCLN),  KC_QUOT,
        KC_GRV, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,               KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_BSLS,
        KC_BSPC, KC_GRV, MEDIA, KC_LANG, SHIFTED_NUMS, KC_SPC,
                                                KC_PLUS, KC_EQL,
                                                NAV, SHIFT,
                                                KC_ENT, LOWER,
                                                KC_LANG, KC_DELETE
    ),

    [_NAV] = LAYOUT(
        KC_TRNS,     KC_TRNS,  KC_TRNS,    KC_HASH,    KC_DLR,   KC_PERC,                  KC_PSCR,    KC_HOME,     KC_END,       KC_TRNS,  KC_PSCR,  KC_BSPC,
        KC_TRNS,    KC_TRNS,  KC_TRNS,  KC_TRNS,    KC_TRNS,  KC_TRNS,                  KC_LEFT,    KC_DOWN,     KC_UP,     KC_RIGHT, KC_INS,  KC_DELETE,
        KC_TRNS,    KC_TRNS,  KC_TRNS,  KC_AT,    KC_EXLM,  KC_TRNS,                  KC_TRNS,    KC_PGDN,     KC_PGUP,     KC_TRNS,  KC_TRNS,  KC_TRNS,
        _______, _______, _______, _______, _______, _______,
                                                KC_PLUS, KC_EQL,
                                                _______, _______,
                                                _______, _______,
                                                _______, _______
    ),

    [_LOWER] = LAYOUT(
        _______, _______, _______, _______, _______, KC_LBRC,             KC_RBRC, KC_7,   KC_8,   KC_9,   KC_0, KC_BSPC,
        _______, KC_HOME, KC_PGUP, KC_PGDN, KC_END , KC_LPRN,             KC_RPRN, KC_4,   KC_5,   KC_6,   KC_MINS, KC_UNDS,
        _______, _______, _______, _______, _______, _______,             _______, KC_1,   KC_2,   KC_3,   KC_EQL,  QK_BOOT,
        _______, _______, _______, _______, _______, _______,
                                                _______, KC_P0,
                                                _______, _______,
                                                _______, _______,
                                                _______, _______
   ),

    [_NUMS] = LAYOUT(
        KC_GRV,  KC_0,             KC_9,         KC_8,         KC_7,         KC_TRNS,                   KC_PLUS,    KC_LPRN,          KC_RPRN,          KC_SCLN,         KC_SLSH,          KC_TRNS,
        KC_TRNS, LCTL_T(KC_TRNS),  LSFT_T(KC_6), LALT_T(KC_5), LGUI_T(KC_4), KC_TRNS,                   KC_MINS,    RGUI_T(KC_LBRC),  RALT_T(KC_RBRC),  RSFT_T(KC_EQL),  CTL_T(KC_COLN),  KC_DQT,
        KC_TRNS, KC_TRNS,          KC_3,         KC_2,         KC_1,         KC_TRNS,                   KC_UNDS,    KC_LCBR,          KC_RCBR,          KC_LT,           KC_GT,            KC_QUES,
        _______, _______, _______, _______, _______, _______,
                                                KC_PLUS, KC_EQL,
                                                _______, _______,
                                                _______, _______,
                                                _______, _______
    ),

    [_SHIFTED_NUMS] = LAYOUT(
        KC_TILD,  KC_RPRN,  KC_LPRN,  KC_ASTR,  KC_AMPR,  KC_PIPE,                   KC_PLUS,  KC_LPRN,          KC_RPRN,          KC_SCLN,         KC_SLSH,          KC_TRNS,
        KC_TRNS,  KC_TRNS,  KC_CIRC,  KC_PERC,  KC_DLR, KC_TRNS,                   KC_MINS,  RGUI_T(KC_LBRC),  RALT_T(KC_RBRC),  RSFT_T(KC_EQL),  CTL_T(KC_COLN),  KC_DQT,
        QK_BOOT,  KC_TRNS,  KC_HASH,  KC_AT,  KC_EXLM,  KC_TRNS,                   KC_UNDS,  KC_LCBR,          KC_RCBR,          KC_LT,           KC_GT,            KC_QUES,
        _______, _______, _______, _______, _______, _______,
                                                KC_PLUS, KC_EQL,
                                                _______, _______,
                                                _______, _______,
                                                _______, _______
    ),

    [_ADJUST] = LAYOUT(
        KC_TRNS,    KC_TRNS,  KC_TRNS,  KC_TRNS,    KC_TRNS,  KC_TRNS,                  KC_TRNS,    KC_7,     KC_8,       KC_9,  KC_TRNS,  KC_TRNS,
        KC_TRNS,    KC_TRNS,  KC_TRNS,  KC_TRNS,    KC_TRNS,  KC_TRNS,                  KC_TRNS,    KC_4,     KC_5,       KC_6,  KC_F11,  KC_F12,
        KC_TRNS,    KC_F1,      KC_F2,    KC_F3,    KC_F4,      KC_F5,                  KC_F7,      KC_F6,    KC_F7,     KC_F8,   KC_F9,   KC_F10,
        _______, _______, _______, _______, _______, _______,
                                                KC_PLUS, KC_EQL,
                                                _______, _______,
                                                _______, _______,
                                                _______, _______
    ),

    [_MEDIA] = LAYOUT(
        _______, _______, _______, _______, _______, _______,             _______, _______,   _______,   _______,   _______, _______,
        _______, _______, KC_MPRV, KC_VOLD, KC_VOLU, KC_MNXT,             _______, _______,   _______,   _______,   _______, _______,
        _______, _______, KC_MUTE, KC_MUTE_MIC, KC_MPLY, _______,             _______, _______,   _______,   _______,   _______,  _______,
        _______, _______, _______, _______, _______, _______,
                                                _______, _______,
                                                _______, _______,
                                                _______, _______,
                                                _______, _______
   )
};

layer_state_t layer_state_set_user(layer_state_t state) {
    state = update_tri_layer_state(state, _NUMS, _NAV, _ADJUST);
    state = update_tri_layer_state(state, _SHIFTED_NUMS, _NAV, _ADJUST);
    return state;
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case CTL_T(KC_COLN):
            if (record->tap.count && record->event.pressed) {
                tap_code16(KC_COLN); // Send KC_COLN on tap
                return false;        // Return false to ignore further processing of key
            }
            break;
        case KC_LANG:
            if (record->event.pressed) {
                tap_code16_delay(LGUI(KC_GRV), 50);
                return false;
            }
            break;
        case KC_MUTE_MIC:
            if (record->event.pressed) {
                tap_code16(LGUI(KC_M));         // tap M
                return false;
            }
            break;
    }
    return true;
}
