// Copyright 2022 Markus Knutsson (@TweetyDaBird)
// SPDX-License-Identifier: GPL-2.0-or-later
#include QMK_KEYBOARD_H

enum custom_keycodes {
    NIKO_CHNG_LNG = SAFE_RANGE,             // LGUI + Space (Change Language)
};

void win_plus_symb(uint16_t code) {
    register_code(KC_LGUI);
    tap_code(code);
    unregister_code(KC_LGUI);
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    if (record->event.pressed) {
        switch (keycode) {
            case NIKO_CHNG_LNG:
                win_plus_symb(KC_SPC);
                return false;
        }
    }
    return true;
}

const uint16_t PROGMEM b_softsign_combo[] = {KC_COMM, KC_M, COMBO_END};
const uint16_t PROGMEM ru_x_combo[] = {KC_O, KC_P, COMBO_END};
const uint16_t PROGMEM ru_yo_combo[] = {KC_E, KC_R, COMBO_END};
const uint16_t PROGMEM grv_combo[] = {RALT(KC_J), RALT(KC_K), COMBO_END};
const uint16_t PROGMEM tild_combo[] = {RALT(KC_U), RALT(KC_I), COMBO_END};

combo_t key_combos[] = {
    COMBO(b_softsign_combo, KC_RBRC),
    COMBO(ru_x_combo, KC_LBRC),
    COMBO(ru_yo_combo, KC_QUOT),
    COMBO(grv_combo, RALT(KC_QUOT)),
    COMBO(tild_combo, RALT(KC_LBRC))
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /*
     * Layer 0 - Base Layer
     * ,-----------------------------------------.                    ,-----------------------------------------.
     * |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |XXXXXX|    |XXXXXX|  F7  |  F8  |  F9  | F10  | F11  | F12  |
     * |------+------+------+------+------+------|      |    |      |------+------+------+------+------+------|
     * |XXXXXX|   Q  |   W  |  E   |   R  |   T  |------|    |------|   Y  |   U  |   I  |  O   |   P  |XXXXXX|
     * |      |   й  |   ц  |  у  [ё]  к  |   е  |      |    |      |   н  |   г  |   ш  |  щ  [х]  з  |      |
     * |------+------+------+------+------+------|      |    |      |------+------+------+------+------+------|
     * |XXXXXX|   A  |   S  |   D  |   F  |   G  |------|    |------|   H  |   J  |   K  |   L  |      |XXXXXX|
     * |      |   ф  |   ы  |   в  |   а  |   п  |      |    |      |   р  |   о  |   л  |   д  |   ж  |      |
     * |------+------+------+------+------+------|XXXXXX|    |XXXXXX|------+------+------+------+------+------|
     * |XXXXXX|   Z  |   X  |   C  |   V  |   B  |------|    |------|   N  |  M   |      |      |      |XXXXXX|
     * |      |   я  |   ч  |   с  |   м  |   и  |      |    |      |   т  |  ь  [ъ]  б  |   ю  |   э  |      |
     * `----------------------------------------/       /     \      \-----------------------------------------'
     *                 |XXXXXX| Tab | MO(1) | Space |  /      /       \      \ | Bspc | MO(2) | Enter |XXXXXX|
     *                 `------------------------------------'           '------''---------------------------'
     */
    [0] = LAYOUT(
        KC_F1, KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   XXXXXXX,        XXXXXXX, KC_F7, KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,
        XXXXXXX,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                             KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    XXXXXXX,
        XXXXXXX,  MT(MOD_LGUI, KC_A),    MT(MOD_LALT, KC_S),    MT(MOD_LCTL, KC_D),    MT(MOD_LSFT, KC_F),    LT(1, KC_G),                             LT(1, KC_H),    MT(MOD_RSFT, KC_J),    MT(MOD_LCTL, KC_K),    MT(MOD_LALT, KC_L),    MT(MOD_LGUI, KC_SCLN), XXXXXXX,
        XXXXXXX, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    XXXXXXX,        KC_MPLY, KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, XXXXXXX,
                                            XXXXXXX, KC_TAB,  MO(2),   KC_SPC,        KC_BSPC,  MO(2),   KC_ENT, XXXXXXX
    ),

    /*
     * Layer 1 - Symbols Layer
     * ,-----------------------------------------.                    ,-----------------------------------------.
     * |XXXXXX|XXXXXX|XXXXXX|XXXXXX|XXXXXX|XXXXXX|XXXXXX|    |XXXXXX|XXXXXX|XXXXXX|XXXXXX|XXXXXX|XXXXXX|XXXXXX|
     * |------+------+------+------+------+------|      |    |      |------+------+------+------+------+------|
     * |XXXXXX|   !  |   @  |   #  |   $  |   %  |------|    |------|   {  |  (  [~]  )  |   [  |   ]  |XXXXXX|
     * |------+------+------+------+------+------|      |    |      |------+------+------+------+------+------|
     * |XXXXXX|   +  |   -  |   *  |   /  |   \  |------|    |------|   }  |  '  [`]  "  |   :  |   ;  |XXXXXX|
     * |------+------+------+------+------+------|XXXXXX|    |XXXXXX|------+------+------+------+------+------|
     * |XXXXXX|   №  |   |  |   &  |   _  |   =  |------|    |------|   <  |   >  |   ,  |   .  |   ?  |XXXXXX|
     * `-----------------------------------------/       /     \      \-----------------------------------------'
     *                  |XXXXXX|XXXXXX|XXXXXX|XXXXXX| /       /       \      \ | DEL  | CAPS | ChngLng |XXXXXX|
     *                  |      |      |      |      |/       /         \      \|      |      |         |      |
     *                  `------------------------------------'           '------''---------------------------'
     */
    [1] = LAYOUT(
        XXXXXXX,  XXXXXXX,      XXXXXXX, XXXXXXX, XXXXXXX,      XXXXXXX,      XXXXXXX,        XXXXXXX, XXXXXXX,      XXXXXXX,      XXXXXXX,      XXXXXXX,       XXXXXXX,       XXXXXXX,
        XXXXXXX, RALT(KC_Q), RALT(KC_W),   RALT(KC_E), RALT(KC_R),  RALT(KC_T),                          RALT(KC_Y),  RALT(KC_U), RALT(KC_I), RALT(KC_O),  RALT(KC_P),  XXXXXXX,
        XXXXXXX, RALT(KC_A), RALT(KC_S), RALT(KC_D), RALT(KC_F), RALT(KC_G),                          RALT(KC_H),  RALT(KC_J), RALT(KC_K), RALT(KC_L),  RALT(KC_SCLN),  XXXXXXX,
        XXXXXXX, RALT(KC_Z),      RALT(KC_X), RALT(KC_C), RALT(KC_V), RALT(KC_B),      XXXXXXX,        XXXXXXX, RALT(KC_N), RALT(KC_M), RALT(KC_COMM), RALT(KC_DOT),   RALT(KC_SLSH),  XXXXXXX,
                                            XXXXXXX,      XXXXXXX,      XXXXXXX,   XXXXXXX,                   XXXXXXX, XXXXXXX,   XXXXXXX,      XXXXXXX
    ),

    /*
* Layer 2 - Navigation layer
     * ,-----------------------------------------.                    ,-----------------------------------------.
     * |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |XXXXXX|    |XXXXXX|  F7  |  F8  |  F9  | F10  | F11  | F12  |
     * |------+------+------+------+------+------|      |    |      |------+------+------+------+------+------|
     * |XXXXXX|  1   |  2   |  3   |  4   |  5   |------|    |------|  6   |  7   |  8   |  9   |  0   |XXXXXX|
     * |------+------+------+------+------+------|      |    |      |------+------+------+------+------+------|
     * |XXXXXX|XXXXXX|XXXXXX|XXXXXX|XXXXXX|XXXXXX|------|    |------|XXXXXX| Left | Right| Down |  Up  |XXXXXX|
     * |------+------+------+------+------+------|XXXXXX|    |XXXXXX|------+------+------+------+------+------|
     * |XXXXXX|XXXXXX|XXXXXX|XXXXXX|XXXXXX|XXXXXX|------|    |------|XXXXXX| Home | End  | PgDn | PgUp |XXXXXX|
     * `-----------------------------------------/       /     \      \-----------------------------------------'
     *                  |XXXXXX| Esc  | MO(3)| Space| /       /       \      \ |XXXXXX|XXXXXX|XXXXXX|XXXXXX|
     *                  |      |      |      |      |/       /         \      \|      |      |      |      |
     *                  `------------------------------------'           '------''---------------------------'
     */
    [2] = LAYOUT(
        KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   XXXXXXX,        XXXXXXX, KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,
        XXXXXXX, KC_1, KC_2, KC_3, KC_4, KC_5,                          KC_6, KC_7, KC_8,  KC_9, KC_0,  XXXXXXX,
        XXXXXXX, MT(MOD_LGUI, XXXXXXX), MT(MOD_LALT, XXXXXXX), MT(MOD_LCTL, XXXXXXX),  MT(MOD_LSFT, XXXXXXX), XXXXXXX,                          KC_APP, MT(MOD_RSFT, KC_LEFT), MT(MOD_LCTL, KC_RGHT), MT(MOD_LALT, KC_DOWN), MT(MOD_LGUI, KC_UP),   XXXXXXX,
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,        XXXXXXX, XXXXXXX, KC_HOME, KC_END,  KC_PGDN, KC_PGUP, XXXXXXX,
                                            XXXXXXX, KC_ESC,  MO(3),   KC_SPC,        KC_BSPC, KC_CAPS, NIKO_CHNG_LNG,  XXXXXXX
    ),

    /*
     * Layer 3 - Function keys layer
     * ,-----------------------------------------.                    ,-----------------------------------------.
     * |XXXXXX|XXXXXX|XXXXXX|XXXXXX|XXXXXX|XXXXXX|XXXXXX|    |XXXXXX|XXXXXX|XXXXXX|XXXXXX|XXXXXX|XXXXXX|XXXXXX|
     * |------+------+------+------+------+------|      |    |      |------+------+------+------+------+------|
     * |XXXXXX|  F1  |  F2  |  F3  |  F4  |  F5  |------|    |------|  F6  |  F7  |  F8  |  F9  | F10  |XXXXXX|
     * |------+------+------+------+------+------|      |    |      |------+------+------+------+------+------|
     * |XXXXXX|XXXXXX|XXXXXX|XXXXXX|XXXXXX|XXXXXX|------|    |------|  F11 |  F12 |XXXXXX|XXXXXX|XXXXXX|XXXXXX|
     * |------+------+------+------+------+------|XXXXXX|    |XXXXXX|------+------+------+------+------+------|
     * |XXXXXX|XXXXXX|XXXXXX|XXXXXX|XXXXXX|XXXXXX|------|    |------|XXXXXX|XXXXXX|XXXXXX|XXXXXX|XXXXXX|XXXXXX|
     * `-----------------------------------------/       /     \      \-----------------------------------------'
     *                  |XXXXXX|XXXXXX|XXXXXX|XXXXXX| /       /       \      \ |XXXXXX|XXXXXX| TO(4)|XXXXXX|
     *                  |      |      |      |      |/       /         \      \|      |      |      |      |
     *                  `------------------------------------'           '------''---------------------------'
     */
    [3] = LAYOUT(
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
        XXXXXXX, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,                            KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10, XXXXXXX, 
        XXXXXXX, MT(MOD_LGUI, XXXXXXX), MT(MOD_LALT, XXXXXXX), MT(MOD_LCTL, XXXXXXX),  MT(MOD_LSFT, XXXXXXX), XXXXXXX,                         KC_F11, MT(MOD_RSFT, KC_F12), MT(MOD_LCTL, XXXXXXX), MT(MOD_LALT, XXXXXXX), MT(MOD_LGUI, XXXXXXX),   XXXXXXX,
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
                                            XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,        XXXXXXX, XXXXXXX, TO(4), XXXXXXX
    ),
    /*
* Layer 4 - System layer
     * ,-----------------------------------------.                    ,-----------------------------------------.
     * |XXXXXX|XXXXXX|XXXXXX|XXXXXX|XXXXXX|XXXXXX|XXXXXX|    |XXXXXX|XXXXXX|XXXXXX|XXXXXX|XXXXXX|XXXXXX|XXXXXX|
     * |------+------+------+------+------+------|      |    |      |------+------+------+------+------+------|
     * |XXXXXX| BOOT |XXXXXX|XXXXXX|XXXXXX|XXXXXX|------|    |------|XXXXXX|XXXXXX|XXXXXX|XXXXXX|SLEEP |XXXXXX|
     * |------+------+------+------+------+------|      |    |      |------+------+------+------+------+------|
     * |XXXXXX|XXXXXX|XXXXXX|XXXXXX|XXXXXX|XXXXXX|------|    |------|XXXXXX|XXXXXX|XXXXXX|XXXXXX|XXXXXX|XXXXXX|
     * |------+------+------+------+------+------|XXXXXX|    |XXXXXX|------+------+------+------+------+------|
     * |XXXXXX|XXXXXX|XXXXXX|XXXXXX|XXXXXX|XXXXXX|------|    |------|XXXXXX|XXXXXX|XXXXXX|XXXXXX|XXXXXX|XXXXXX|
     * `-----------------------------------------/       /     \      \-----------------------------------------'
     *                  |XXXXXX|XXXXXX|XXXXXX|XXXXXX| /       /       \      \ |XXXXXX|XXXXXX| TO(0)|XXXXXX|
     *                  |      |      |      |      |/       /         \      \|      |      |      |      |
     *                  `------------------------------------'           '------''---------------------------'
     */
    [4] = LAYOUT(
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
        XXXXXXX, QK_BOOT, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                          XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_SLEP, XXXXXXX,
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                          XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
                                            XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,        XXXXXXX, XXXXXXX, TO(0), XXXXXXX
    )
};

#if defined(ENCODER_MAP_ENABLE)
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][NUM_DIRECTIONS] = {
    [0] = { ENCODER_CCW_CW(KC_TRNS, KC_TRNS), ENCODER_CCW_CW(KC_VOLU, KC_VOLD) },
    [1] = { ENCODER_CCW_CW(KC_TRNS, KC_TRNS), ENCODER_CCW_CW(MS_WHLD, MS_WHLU) },
    [2] = { ENCODER_CCW_CW(KC_TRNS, KC_TRNS), ENCODER_CCW_CW(KC_TRNS, KC_TRNS) },
    [3] = { ENCODER_CCW_CW(KC_TRNS, KC_TRNS), ENCODER_CCW_CW(KC_TRNS, KC_TRNS) },
    [4] = { ENCODER_CCW_CW(KC_TRNS, KC_TRNS), ENCODER_CCW_CW(KC_TRNS, KC_TRNS) }
};
#endif

#ifdef OLED_ENABLE

static void print_status_narrow(void) {
    oled_write_P(PSTR("Layer"), false);
    switch (get_highest_layer(layer_state)) {
        case 0:
            oled_write_P(PSTR("-Base\n"), false);
            break;
        case 1:
            oled_write_P(PSTR("-Symb\n"), false);
            break;
        case 2:
            oled_write_P(PSTR("-Nav \n"), false);
            break;
        case 3:
            oled_write_P(PSTR("-Func \n"), false);
            break;
        case 4:
            oled_write_P(PSTR("-Sys \n"), false);
            break;
        default:
            oled_write_P(PSTR("Undef"), false);
    }

    oled_write_P(PSTR("\n"), false);
    led_t led_usb_state = host_keyboard_led_state();
    oled_write_ln_P(PSTR("Caps  Lock"), led_usb_state.caps_lock);

    oled_write_P(PSTR("\n"), false);
    oled_write_P(PSTR("Num   Lock"), led_usb_state.num_lock);
}

static void print_large_layer_number(void) {
    switch (get_highest_layer(layer_state)) {
        case 0:
            oled_write_ln_P(PSTR("#####"), false);
            oled_write_ln_P(PSTR("#   #"), false);
            oled_write_ln_P(PSTR("#   #"), false);
            oled_write_ln_P(PSTR("#   #"), false);
            oled_write_ln_P(PSTR("#   #"), false);
            oled_write_ln_P(PSTR("#   #"), false);
            oled_write_ln_P(PSTR("#   #"), false);
            oled_write_ln_P(PSTR("#####"), false);
            break;
        case 1:
            oled_write_ln_P(PSTR("  #  "), false);
            oled_write_ln_P(PSTR(" ##  "), false);
            oled_write_ln_P(PSTR("# #  "), false);
            oled_write_ln_P(PSTR("  #  "), false);
            oled_write_ln_P(PSTR("  #  "), false);
            oled_write_ln_P(PSTR("  #  "), false);
            oled_write_ln_P(PSTR("  #  "), false);
            oled_write_ln_P(PSTR("#####"), false);
            break;
        case 2:
            oled_write_ln_P(PSTR("#####"), false);
            oled_write_ln_P(PSTR("    #"), false);
            oled_write_ln_P(PSTR("    #"), false);
            oled_write_ln_P(PSTR("#####"), false);
            oled_write_ln_P(PSTR("#    "), false);
            oled_write_ln_P(PSTR("#    "), false);
            oled_write_ln_P(PSTR("#    "), false);
            oled_write_ln_P(PSTR("#####"), false);
            break;
        case 3:
            oled_write_ln_P(PSTR("#####"), false);
            oled_write_ln_P(PSTR("    #"), false);
            oled_write_ln_P(PSTR("    #"), false);
            oled_write_ln_P(PSTR("#####"), false);
            oled_write_ln_P(PSTR("    #"), false);
            oled_write_ln_P(PSTR("    #"), false);
            oled_write_ln_P(PSTR("    #"), false);
            oled_write_ln_P(PSTR("#####"), false);
            break;
        case 4:
            oled_write_ln_P(PSTR("#   #"), false);
            oled_write_ln_P(PSTR("#   #"), false);
            oled_write_ln_P(PSTR("#   #"), false);
            oled_write_ln_P(PSTR("#####"), false);
            oled_write_ln_P(PSTR("    #"), false);
            oled_write_ln_P(PSTR("    #"), false);
            oled_write_ln_P(PSTR("    #"), false);
            oled_write_ln_P(PSTR("    #"), false);
            break;
        // case 5:
        //     oled_write_ln_P(PSTR("#####"), false);
        //     oled_write_ln_P(PSTR("#    "), false);
        //     oled_write_ln_P(PSTR("#    "), false);
        //     oled_write_ln_P(PSTR("#### "), false);
        //     oled_write_ln_P(PSTR("    #"), false);
        //     oled_write_ln_P(PSTR("    #"), false);
        //     oled_write_ln_P(PSTR("    #"), false);
        //     oled_write_ln_P(PSTR("#####"), false);
        //     break;
        // case 6:
        //     oled_write_ln_P(PSTR("#####"), false);
        //     oled_write_ln_P(PSTR("#    "), false);
        //     oled_write_ln_P(PSTR("#    "), false);
        //     oled_write_ln_P(PSTR("#####"), false);
        //     oled_write_ln_P(PSTR("#   #"), false);
        //     oled_write_ln_P(PSTR("#   #"), false);
        //     oled_write_ln_P(PSTR("#   #"), false);
        //     oled_write_ln_P(PSTR("#####"), false);
        //     break;
        // case 7:
        //     oled_write_ln_P(PSTR("#####"), false);
        //     oled_write_ln_P(PSTR("    #"), false);
        //     oled_write_ln_P(PSTR("   # "), false);
        //     oled_write_ln_P(PSTR("  #  "), false);
        //     oled_write_ln_P(PSTR(" #   "), false);
        //     oled_write_ln_P(PSTR("#    "), false);
        //     oled_write_ln_P(PSTR("#    "), false);
        //     oled_write_ln_P(PSTR("#    "), false);
        //     break;
        // case 8:
        //     oled_write_ln_P(PSTR("#####"), false);
        //     oled_write_ln_P(PSTR("#   #"), false);
        //     oled_write_ln_P(PSTR("#   #"), false);
        //     oled_write_ln_P(PSTR("#####"), false);
        //     oled_write_ln_P(PSTR("#   #"), false);
        //     oled_write_ln_P(PSTR("#   #"), false);
        //     oled_write_ln_P(PSTR("#   #"), false);
        //     oled_write_ln_P(PSTR("#####"), false);
        //     break;
        // case 9:
        //     oled_write_ln_P(PSTR("#####"), false);
        //     oled_write_ln_P(PSTR("#   #"), false);
        //     oled_write_ln_P(PSTR("#   #"), false);
        //     oled_write_ln_P(PSTR("#####"), false);
        //     oled_write_ln_P(PSTR("    #"), false);
        //     oled_write_ln_P(PSTR("    #"), false);
        //     oled_write_ln_P(PSTR("    #"), false);
        //     oled_write_ln_P(PSTR("#####"), false);
        //     break;
        default:
            oled_write_ln_P(PSTR("?????"), false);
            break;
    }
}

bool oled_task_user(void) {
    if (is_keyboard_master()) {
        print_status_narrow();
    } else {
        print_large_layer_number();
    }
    return false;
}

#endif