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
    NIKO_UC_LCBR,              // U+007B -> {
    NIKO_UC_RCBR,              // U+007D -> }
    NIKO_UC_GRV,               // U+0060 -> `
    NIKO_UC_TILD,              // U+007E -> ~
    NIKO_UC_EXLM,              // U+0021 -> !
    NIKO_UC_ASTR,              // U+002A -> *
    NIKO_UC_MINS,              // U+002D -> -
    NIKO_UC_UNDS,              // U+005F -> _
    NIKO_UC_EQL,               // U+003D -> =
    NIKO_UC_PLUS,              // U+002B -> +
    NIKO_UC_LPRN,              // U+0028 -> (
    NIKO_UC_RPRN,              // U+0029 -> )
    NIKO_UC_LT,                // U+003C -> <
    NIKO_UC_GT,                // U+003E -> >

    NIKO_CHNG_LNG,             // LGUI + Space (Change Language)
    NIKO_WIN_T,                // Win + T
    NIKO_WIN_B,                // Win + T
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

void win_plus_symb(uint16_t code) {
    register_code(KC_LGUI);
    tap_code(code);
    unregister_code(KC_LGUI);
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
            case NIKO_UC_LCBR:
                send_alt_numpad_code(123);
                return false;
            case NIKO_UC_RCBR:
                send_alt_numpad_code(125);
                return false;
            case NIKO_UC_GRV:
                send_alt_numpad_code(96);
                return false;
            case NIKO_UC_TILD:
                send_alt_numpad_code(126);
                return false;
            case NIKO_UC_EXLM:
                send_alt_numpad_code(33);
                return false;
            case NIKO_UC_ASTR:
                send_alt_numpad_code(42);
                return false;
            case NIKO_UC_MINS:
                send_alt_numpad_code(45);
                return false;
            case NIKO_UC_UNDS:
                send_alt_numpad_code(95);
                return false;
            case NIKO_UC_EQL:
                send_alt_numpad_code(61);
                return false;
            case NIKO_UC_PLUS:
                send_alt_numpad_code(43);
                return false;
            case NIKO_UC_LPRN:
                send_alt_numpad_code(40);
                return false;
            case NIKO_UC_RPRN:
                send_alt_numpad_code(41);
                return false;
            case NIKO_UC_LT:
                send_alt_numpad_code(60);
                return false;
            case NIKO_UC_GT:
                send_alt_numpad_code(62);
                return false;
            case NIKO_CHNG_LNG:
                win_plus_symb(KC_SPC);
                return false;
            case NIKO_WIN_T:
                win_plus_symb(KC_T);
                return false;
            case NIKO_WIN_B:
                win_plus_symb(KC_B);
                return false;
        }
    }
    return true;
}

// Defines the key combination for the combo
const uint16_t PROGMEM b_softsign_combo[] = {KC_COMM, KC_M, COMBO_END};
const uint16_t PROGMEM ru_x_combo[] = {KC_O, KC_P, COMBO_END};
const uint16_t PROGMEM ru_yo_combo[] = {KC_E, KC_R, COMBO_END};
const uint16_t PROGMEM grv_combo[] = {NIKO_UC_QUOT, NIKO_UC_DQUO, COMBO_END};
const uint16_t PROGMEM tild_combo[] = {NIKO_UC_LPRN, NIKO_UC_RPRN, COMBO_END};

// Defines the combos themselves
combo_t key_combos[] = {
    COMBO(b_softsign_combo, KC_RBRC),
    COMBO(ru_x_combo, KC_LBRC),
    COMBO(ru_yo_combo, KC_GRV),
    COMBO(grv_combo, NIKO_UC_GRV),
    COMBO(tild_combo, NIKO_UC_TILD)
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
        XXXXXXX,  MT(MOD_LGUI, KC_A),    MT(MOD_LALT, KC_S),    MT(MOD_LCTL, KC_D),    MT(MOD_LSFT, KC_F),    KC_G,                             KC_H,    MT(MOD_RSFT, KC_J),    MT(MOD_LCTL, KC_K),    MT(MOD_LALT, KC_L),    MT(MOD_LGUI, KC_SCLN), XXXXXXX,
        XXXXXXX, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    XXXXXXX,        KC_MPLY, KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_QUOT, XXXXXXX,
                                            XXXXXXX, KC_TAB,  MO(1),   KC_SPC,        KC_BSPC,  MO(2),   KC_ENT, XXXXXXX
    ),

    /*
     * Layer 1 - Symbols Layer
     * ,-----------------------------------------.                    ,-----------------------------------------.
     * | NUM  |XXXXXX|XXXXXX|XXXXXX|XXXXXX|XXXXXX|XXXXXX|    |XXXXXX|XXXXXX|XXXXXX|XXXXXX|XXXXXX|XXXXXX|XXXXXX|
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
        KC_NUM,  XXXXXXX,      XXXXXXX, XXXXXXX, XXXXXXX,      XXXXXXX,      XXXXXXX,        XXXXXXX, XXXXXXX,      XXXXXXX,      XXXXXXX,      XXXXXXX,       XXXXXXX,       XXXXXXX,
        XXXXXXX, NIKO_UC_EXLM, NIKO_UC_AT,   NIKO_UC_HASH, NIKO_UC_DLR,  NIKO_UC_PERC,                          NIKO_UC_LCBR,  NIKO_UC_LPRN, NIKO_UC_RPRN, NIKO_UC_LBRC,  NIKO_UC_RBRC,  NIKO_UC_GT,
        XXXXXXX, NIKO_UC_PLUS, NIKO_UC_MINS, NIKO_UC_ASTR, NIKO_UC_SLSH, NIKO_UC_BSLS,                          NIKO_UC_RCBR,  NIKO_UC_QUOT, NIKO_UC_DQUO, NIKO_UC_COLN,  NIKO_UC_SCLN,  NIKO_UC_LT,
        XXXXXXX, NIKO_UC_NUMO,      NIKO_UC_PIPE, NIKO_UC_AMPR, NIKO_UC_UNDS, NIKO_UC_EQL,      XXXXXXX,        XXXXXXX, NIKO_UC_LT, NIKO_UC_GT, NIKO_UC_COMM, NIKO_UC_DOT,   NIKO_UC_QUES,  XXXXXXX,
                                            XXXXXXX,      XXXXXXX,      XXXXXXX,   XXXXXXX,                   KC_DEL, KC_CAPS,   NIKO_CHNG_LNG,      XXXXXXX
    ),

    /*
* Layer 2 - Navigation & Funct1ion Keys
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
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, NIKO_WIN_T, NIKO_WIN_B, XXXXXXX,        XXXXXXX, XXXXXXX, KC_HOME, KC_END,  KC_PGDN, KC_PGUP, XXXXXXX,
                                            XXXXXXX, KC_ESC,  MO(3),   KC_SPC,        XXXXXXX, XXXXXXX, XXXXXXX,  XXXXXXX
    ),

    /*
     * Layer 3 - Reset Layer
     * ,-----------------------------------------.                    ,-----------------------------------------.
     * | BOOT |XXXXXX|XXXXXX|XXXXXX|XXXXXX|XXXXXX|XXXXXX|    |XXXXXX|XXXXXX|XXXXXX|XXXXXX|XXXXXX|XXXXXX|XXXXXX|
     * |------+------+------+------+------+------|      |    |      |------+------+------+------+------+------|
     * |XXXXXX|XXXXXX|XXXXXX|XXXXXX|XXXXXX|XXXXXX|------|    |------|XXXXXX|XXXXXX|XXXXXX|XXXXXX|XXXXXX|XXXXXX|
     * |------+------+------+------+------+------|      |    |      |------+------+------+------+------+------|
     * |XXXXXX|XXXXXX|XXXXXX|XXXXXX|XXXXXX|XXXXXX|------|    |------|XXXXXX|XXXXXX|XXXXXX|XXXXXX|XXXXXX|XXXXXX|
     * |------+------+------+------+------+------|XXXXXX|    |XXXXXX|------+------+------+------+------+------|
     * |XXXXXX|XXXXXX|XXXXXX|XXXXXX|XXXXXX|XXXXXX|------|    |------|XXXXXX|XXXXXX|XXXXXX|XXXXXX|XXXXXX|XXXXXX|
     * `-----------------------------------------/       /     \      \-----------------------------------------'
     *                  |XXXXXX|XXXXXX|XXXXXX|XXXXXX| /       /       \      \ |XXXXXX|XXXXXX|XXXXXX|XXXXXX|
     *                  |      |      |      |      |/       /         \      \|      |      |      |      |
     *                  `------------------------------------'           '------''---------------------------'
     */
    [3] = LAYOUT(
        QK_BOOT, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                          XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                          XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
                                            XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX
    )
};

#if defined(ENCODER_MAP_ENABLE)
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][NUM_DIRECTIONS] = {
    [0] = { ENCODER_CCW_CW(KC_TRNS, KC_TRNS), ENCODER_CCW_CW(KC_VOLU, KC_VOLD) },
    [1] = { ENCODER_CCW_CW(KC_TRNS, KC_TRNS), ENCODER_CCW_CW(MS_WHLD, MS_WHLU) },
    [2] = { ENCODER_CCW_CW(KC_TRNS, KC_TRNS), ENCODER_CCW_CW(KC_TRNS, KC_TRNS) },
    [3] = { ENCODER_CCW_CW(KC_TRNS, KC_TRNS), ENCODER_CCW_CW(KC_TRNS, KC_TRNS) }
};
#endif

#ifdef OLED_ENABLE

static void print_status_narrow(void) {
    // Print current layer
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

// Function to "draw" large layer numbers on the slave OLED
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
        // case 4:
        //     oled_write_ln_P(PSTR("#   #"), false);
        //     oled_write_ln_P(PSTR("#   #"), false);
        //     oled_write_ln_P(PSTR("#   #"), false);
        //     oled_write_ln_P(PSTR("#####"), false);
        //     oled_write_ln_P(PSTR("    #"), false);
        //     oled_write_ln_P(PSTR("    #"), false);
        //     oled_write_ln_P(PSTR("    #"), false);
        //     oled_write_ln_P(PSTR("    #"), false);
        //     break;
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
            oled_write_ln_P(PSTR("    ?"), false);
            oled_write_ln_P(PSTR("    ?"), false);
            oled_write_ln_P(PSTR("   ? "), false);
            oled_write_ln_P(PSTR("  ?  "), false);
            oled_write_ln_P(PSTR("  ?  "), false);
            oled_write_ln_P(PSTR("     "), false);
            oled_write_ln_P(PSTR("  ?  "), false);
            break;
    }
}

bool oled_task_user(void) {
    if (is_keyboard_master()) {
        // Render the master OLED with standard info
        print_status_narrow();
    } else {
        // Render the slave OLED with the large layer number
        print_large_layer_number();
    }
    return false;
}

#endif