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

/* LT() takes a plain layer number (0-15) and a basic keycode, not MO()/OSL() or custom keycodes.
 * MEDIA_LANG's tap action (KC_LANG) is custom, so it is handled in process_record_user. */
#define MEDIA_LANG LT(_MEDIA, KC_GRV)
#define SNUM_SPC   LT(_SHIFTED_NUMS, KC_SPC)
#define NAV_BSPC   LT(_NAV, KC_BSPC)
#define LOW_ENT    LT(_LOWER, KC_ENT)

/* Keys written in the physical layout of the board (right half has 2 extra keys under , and .) */
#define LAYOUT_visual( \
    L00, L01, L02, L03, L04, L05,      R00, R01, R02, R03, R04, R05, \
    L10, L11, L12, L13, L14, L15,      R10, R11, R12, R13, R14, R15, \
    L20, L21, L22, L23, L24, L25,      R20, R21, R22, R23, R24, R25, \
                                                  E1,  E2, \
                        T5,  T6,       U1,  U2, \
                        T3,  T4,       U3,  U4, \
                        T2,  T1,       U5,  U6 \
) LAYOUT( \
    L00, L01, L02, L03, L04, L05,  R00, R01, R02, R03, R04, R05, \
    L10, L11, L12, L13, L14, L15,  R10, R11, R12, R13, R14, R15, \
    L20, L21, L22, L23, L24, L25,  R20, R21, R22, R23, R24, R25, \
    T1, T2, T3, T4, T5, T6, \
    E1, E2, U1, U2, U3, U4, U5, U6 \
)

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
    [_BASE] = LAYOUT_visual(
        KC_ESC,  KC_Q,            KC_W,         KC_E,         KC_R,         KC_T,               KC_Y,     KC_U,            KC_I,            KC_O,           KC_P,            KC_BSLS,
        KC_TAB,  LCTL_T(KC_A),    LSFT_T(KC_S), LALT_T(KC_D), LGUI_T(KC_F), KC_G,               KC_H,     RGUI_T(KC_J),    RALT_T(KC_K),    RSFT_T(KC_L),   RCTL_T(KC_SCLN), KC_QUOT,
        KC_GRV,  KC_Z,            KC_X,         KC_C,         KC_V,         KC_B,               KC_N,     KC_M,            KC_COMM,         KC_DOT,         KC_SLSH,         KC_BSLS,
                                                                                                                           KC_PLUS,         KC_EQL,
                                                              MEDIA_LANG,   SNUM_SPC,           NAV_BSPC, SHIFT,
                                                              KC_DELETE,    KC_DELETE,          LOW_ENT,  LOW_ENT,
                                                              KC_GRV,       KC_BSPC,            KC_LANG,  KC_DELETE
    ),

    [_NAV] = LAYOUT_visual(
        KC_TRNS, KC_TRNS,         KC_TRNS,      KC_HASH,      KC_DLR,       KC_PERC,            KC_PSCR,  KC_HOME,         KC_END,          C(KC_INS),     S(KC_INS),      KC_INS,
        KC_TRNS, KC_TRNS,         KC_TRNS,      KC_TRNS,      KC_TRNS,      KC_TRNS,            KC_LEFT,  KC_DOWN,         KC_UP,           KC_RIGHT,       KC_PSCR,        KC_TRNS,
        KC_TRNS, KC_TRNS,         KC_TRNS,      KC_AT,        KC_EXLM,      KC_TRNS,            KC_TRNS,  KC_PGDN,         KC_PGUP,         KC_TRNS,        KC_TRNS,         KC_TRNS,
                                                                                                                           KC_TRNS,         KC_TRNS,
                                                              _______,      _______,            _______,  _______,
                                                              _______,      _______,            _______,  _______,
                                                              _______,      _______,            _______,  _______
    ),

    [_LOWER] = LAYOUT_visual(
        _______, _______,         _______,      _______,      _______,      KC_LBRC,            KC_RBRC,  KC_7,            KC_8,            KC_9,           KC_0,            KC_BSPC,
        _______, KC_HOME,         KC_PGUP,      KC_PGDN,      KC_END,       KC_LPRN,            KC_RPRN,  KC_4,            KC_5,            KC_6,           KC_MINS,         KC_UNDS,
        _______, _______,         _______,      _______,      _______,      _______,            _______,  KC_1,            KC_2,            KC_3,           KC_EQL,          QK_BOOT,
                                                                                                                           _______,         KC_P0,
                                                              _______,      _______,            _______,  _______,
                                                              _______,      _______,            _______,  _______,
                                                              _______,      _______,            _______,  _______
   ),

    [_NUMS] = LAYOUT_visual(
        KC_GRV,  KC_0,            KC_9,         KC_8,         KC_7,         KC_TRNS,            KC_PLUS,  KC_LPRN,         KC_RPRN,         KC_SCLN,        KC_SLSH,         KC_TRNS,
        KC_TRNS, LCTL_T(KC_TRNS), LSFT_T(KC_6), LALT_T(KC_5), LGUI_T(KC_4), KC_TRNS,            KC_MINS,  RGUI_T(KC_LBRC), RALT_T(KC_RBRC), RSFT_T(KC_EQL), CTL_T(KC_COLN),  KC_DQT,
        KC_TRNS, KC_TRNS,         KC_3,         KC_2,         KC_1,         KC_TRNS,            KC_UNDS,  KC_LCBR,         KC_RCBR,         KC_LT,          KC_GT,           KC_QUES,
                                                                                                                           KC_PLUS,         KC_EQL,
                                                              _______,      _______,            _______,  _______,
                                                              _______,      _______,            _______,  _______,
                                                              _______,      _______,            _______,  _______
    ),

    [_SHIFTED_NUMS] = LAYOUT_visual(
        KC_TILD, KC_RPRN,         KC_LPRN,      KC_ASTR,      KC_AMPR,      KC_PIPE,            KC_PLUS,  KC_LPRN,         KC_RPRN,         KC_SCLN,        KC_SLSH,         KC_TRNS,
        KC_TRNS, KC_TRNS,         KC_CIRC,      KC_PERC,      KC_DLR,       KC_TRNS,            KC_MINS,  RGUI_T(KC_LBRC), RALT_T(KC_RBRC), RSFT_T(KC_EQL), CTL_T(KC_COLN),  KC_DQT,
        QK_BOOT, KC_TRNS,         KC_HASH,      KC_AT,        KC_EXLM,      KC_TRNS,            KC_UNDS,  KC_LCBR,         KC_RCBR,         KC_LT,          KC_GT,           KC_QUES,
                                                                                                                           KC_PLUS,         KC_EQL,
                                                              _______,      _______,            _______,  _______,
                                                              _______,      _______,            _______,  _______,
                                                              _______,      _______,            _______,  _______
    ),

    [_ADJUST] = LAYOUT_visual(
        KC_TRNS, KC_TRNS,         KC_TRNS,      KC_TRNS,      KC_TRNS,      KC_TRNS,            KC_TRNS,  KC_7,            KC_8,            KC_9,           KC_TRNS,         KC_TRNS,
        KC_TRNS, KC_TRNS,         KC_TRNS,      KC_TRNS,      KC_TRNS,      KC_TRNS,            KC_TRNS,  KC_4,            KC_5,            KC_6,           KC_F11,          KC_F12,
        KC_TRNS, KC_F1,           KC_F2,        KC_F3,        KC_F4,        KC_F5,              KC_F7,    KC_F6,           KC_F7,           KC_F8,          KC_F9,           KC_F10,
                                                                                                                           KC_PLUS,         KC_EQL,
                                                              _______,      _______,            _______,  _______,
                                                              _______,      _______,            _______,  _______,
                                                              _______,      _______,            _______,  _______
    ),

    [_MEDIA] = LAYOUT_visual(
        _______, _______,         _______,      _______,      _______,      _______,            _______,  _______,         _______,         _______,        _______,         _______,
        _______, _______,         KC_MPRV,      KC_VOLD,      KC_VOLU,      KC_MNXT,            _______,  _______,         _______,         _______,        _______,         _______,
        _______, _______,         KC_MUTE,      KC_MUTE_MIC,  KC_MPLY,      _______,            _______,  _______,         _______,         _______,        _______,         _______,
                                                                                                                           _______,         _______,
                                                              _______,      _______,            _______,  _______,
                                                              _______,      _______,            _______,  _______,
                                                              _______,      _______,            _______,  _______
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
        case MEDIA_LANG:
            if (record->tap.count && record->event.pressed) {
                tap_code16_delay(LGUI(KC_GRV), 50); // Switch language on tap, MEDIA layer on hold
                return false;
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
