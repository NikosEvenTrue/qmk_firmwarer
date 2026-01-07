// Copyright 2022 Markus Knutsson (@TweetyDaBird)
// SPDX-License-Identifier: GPL-2.0-or-later
#include QMK_KEYBOARD_H

enum custom_keycodes {
    NIKO_UC_LBRC = SAFE_RANGE, // U+005B -> [
    NIKO_UC_RBRC,              // U+005D -> ]
    NIKO_UC_COLN,              // U+003A -> :
    NIKO_UC_SCLN,              // U+003B -> ;
    NIKO_UC_QUOT,              // U+0027 -> '
    NIKO_UC_DQUO,              // U+0022 -> "
    NIKO_UC_COMM,              // U+002C -> ,
    NIKO_UC_DOT,               // U+002E -> .
    NIKO_UC_QUES,              // U+003F -> ?
    NIKO_UC_SLSH,              // U+002F -> /
    NIKO_UC_PIPE,              // U+007C -> |
    NIKO_UC_BSLS,              // U+005C -> \    /
    NIKO_UC_AT,                // U+0040 -> @
    NIKO_UC_HASH,              // U+0023 -> #
    NIKO_UC_NUMO,              // U+2116 -> №
    NIKO_UC_DLR,               // U+0024 -> $
    NIKO_UC_PERC,              // U+0025 -> %
    NIKO_UC_CIRC,              // U+005E -> ^
    NIKO_UC_AMPR,              // U+0026 -> &
};

void tap_numpad_key(uint8_t digit) {
    switch (digit) {
        case 0: tap_code16(KC_KP_0); break;
        case 1: tap_code16(KC_KP_1); break;
        case 2: tap_code16(KC_KP_2); break;
        case 3: tap_code16(KC_KP_3); break;
        case 4: tap_code16(KC_KP_4); break;
        case 5: tap_code16(KC_KP_5); break;
        case 6: tap_code16(KC_KP_6); break;
        case 7: tap_code16(KC_KP_7); break;
        case 8: tap_code16(KC_KP_8); break;
        case 9: tap_code16(KC_KP_9); break;
    }
}

void send_alt_numpad_code(uint16_t code) {
    register_code(KC_LALT);

    if (code > 255) {
        tap_numpad_key(0);
    }

    uint8_t digits[5];
    int i = 0;
    if (code == 0) {
        digits[i++] = 0;
    } else {
        uint16_t n = code;
        while (n > 0) {
            digits[i++] = n % 10;
            n /= 10;
        }
    }

    for (int j = i - 1; j >= 0; j--) {
        tap_numpad_key(digits[j]);
    }

    unregister_code(KC_LALT);
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    if (record->event.pressed) {
        switch (keycode) {
            case NIKO_UC_LBRC:
                send_alt_numpad_code(91);
                return false;
            case NIKO_UC_RBRC:
                send_alt_numpad_code(93);
                return false;
            case NIKO_UC_COLN:
                send_alt_numpad_code(58);
                return false;
            case NIKO_UC_SCLN:
                send_alt_numpad_code(59);
                return false;
            case NIKO_UC_QUOT:
                send_alt_numpad_code(39);
                return false;
            case NIKO_UC_DQUO:
                send_alt_numpad_code(34);
                return false;
            case NIKO_UC_COMM:
                send_alt_numpad_code(44);
                return false;
            case NIKO_UC_DOT:
                send_alt_numpad_code(46);
                return false;
            case NIKO_UC_QUES:
                send_alt_numpad_code(63);
                return false;
            case NIKO_UC_SLSH:
                send_alt_numpad_code(47);
                return false;
            case NIKO_UC_PIPE:
                send_alt_numpad_code(124);
                return false;
            case NIKO_UC_BSLS:
                send_alt_numpad_code(92);
                return false;
            case NIKO_UC_AT:
                send_alt_numpad_code(64);
                return false;
            case NIKO_UC_HASH:
                send_alt_numpad_code(35);
                return false;
            case NIKO_UC_NUMO:
                send_alt_numpad_code(8470);
                return false;
            case NIKO_UC_DLR:
                send_alt_numpad_code(36);
                return false;
            case NIKO_UC_PERC:
                send_alt_numpad_code(37);
                return false;
            case NIKO_UC_CIRC:
                send_alt_numpad_code(94);
                return false;
            case NIKO_UC_AMPR:
                send_alt_numpad_code(38);
                return false;
        }
    }
    return true;
}

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [0] = LAYOUT(
        QK_GESC,    KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_MPLY,        KC_MPLY, KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS,
        KC_TAB,    KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                             KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    NIKO_UC_LBRC,
        KC_CAPS,   KC_A,    KC_S,    KC_D,    KC_F,    KC_G,                             KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,
        LCTL_T(KC_LEFT), KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_DOWN,        KC_UP,   KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, RCTL_T(KC_RGHT),
                                   TG(3), TG(2),   TG(1), LSFT_T(KC_SPC), RSFT_T(KC_ENT),   KC_RALT, TG(1), RGUI_T(KC_BSPC)
    ),

    [1] = LAYOUT(
        TG(3), KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   _______,        _______, KC_CIRC, KC_KP_7, KC_KP_8, KC_KP_9, XXXXXXX, XXXXXXX,
        _______, XXXXXXX, KC_UP,   XXXXXXX, XXXXXXX, XXXXXXX,                          KC_HASH, KC_KP_4, KC_KP_5, KC_KP_6, XXXXXXX, XXXXXXX,
        XXXXXXX, KC_LEFT, KC_DOWN, NIKO_UC_COMM ,NIKO_UC_LBRC, NIKO_UC_RBRC,                          KC_AMPR, KC_KP_1, KC_KP_2, KC_KP_3, XXXXXXX, XXXXXXX,
        _______, XXXXXXX, KC_PAST, KC_PPLS, KC_PSLS, KC_EQL,  _______,        _______, KC_DLR,  KC_KP_0, KC_PDOT, KC_COLN, KC_PMNS, _______,
                                   _______, _______, _______, _______,        _______, _______, _______, _______ 
    ),

    [2] = LAYOUT(
        _______, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   _______,        _______, KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  _______,
        _______, _______, _______, _______, _______, _______,                          _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______,                          _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______,        _______, _______, _______, _______, _______, _______, _______,
                                            _______, _______, _______,        _______, _______, _______, _______, _______
    ),

    [3] = LAYOUT(
        QK_BOOT, XXXXXXX, XXXXXXX, XXXXXXX, NK_TOGG, AC_TOGG, _______,        _______, XXXXXXX, XXXXXXX, XXXXXXX, UG_NEXT, UG_SATU, UG_TOGG,
        QK_RBT, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                          XXXXXXX, XXXXXXX, XXXXXXX,  UG_PREV, UG_SATD, RGB_M_P,
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_CAPS,                          XXXXXXX, XXXXXXX, XXXXXXX, UG_HUEU, UG_VALU, RGB_M_B,
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, UG_HUED, UG_VALD, RGB_M_R,
                                   _______, _______, _______, _______,        _______, _______, _______, _______ 
    )
};

#if defined(ENCODER_MAP_ENABLE)
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][NUM_DIRECTIONS] = {
    [0] = { ENCODER_CCW_CW(KC_VOLD, KC_VOLU), ENCODER_CCW_CW(KC_VOLD, KC_VOLU) },
    [1] = { ENCODER_CCW_CW(KC_TRNS, KC_TRNS), ENCODER_CCW_CW(KC_TRNS, KC_TRNS) },
    [2] = { ENCODER_CCW_CW(KC_TRNS, KC_TRNS), ENCODER_CCW_CW(KC_TRNS, KC_TRNS) },
    [3] = { ENCODER_CCW_CW(KC_TRNS, KC_TRNS), ENCODER_CCW_CW(KC_TRNS, KC_TRNS) }
};
#endif

#ifdef OLED_ENABLE
static void print_status_narrow(void) {
    // Create OLED content
    oled_write_P(PSTR("\n"), false);
    oled_write_P(PSTR(""), false);
    oled_write_P(PSTR("Lotus -58-"), false);
    oled_write_P(PSTR("\n"), false);

    // Print current layer
    oled_write_P(PSTR("Layer"), false);
    switch (get_highest_layer(layer_state)) {
        case 0:
            oled_write_P(PSTR("-Base\n"), false);
            break;
        case 1:
            oled_write_P(PSTR("-Num \n"), false);
            break;
        case 2:
            oled_write_P(PSTR("-Func\n"), false);
            break;
        case 3:
            oled_write_P(PSTR("-Sys \n"), false);
            break;
        default:
            oled_write_P(PSTR("Undef"), false);
    }
    
    oled_write_P(PSTR("\n"), false);
    led_t led_usb_state = host_keyboard_led_state();
    oled_write_ln_P(PSTR("Caps- lock"), led_usb_state.caps_lock);
    
#ifdef AUTO_SHIFT_ENABLE

    bool autoshift = get_autoshift_state();
    oled_advance_page(true);
    oled_write_P(PSTR("Auto-Shift"), autoshift);
    oled_advance_page(true);
    
#endif

    
}

bool oled_task_user(void) {
    // Render the OLED
    print_status_narrow();
    return false;
}

#endif