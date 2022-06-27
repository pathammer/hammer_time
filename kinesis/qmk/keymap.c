#include QMK_KEYBOARD_H

#define QWERTY 0 // Base qwerty

#define ledTurnOff writePinHigh
#define ledTurnOn writePinLow


#define LED_KEYPAD E26
#define LED_SCROLL_LOCK A5
#define LED_NUM_LOCK A14
#define LED_CAPS_LOCK C7

//#define LED_NUM_LOCK_PIN A14
//#define LED_CAPS_LOCK_PIN C7
//#define LED_SCROLL_LOCK_PIN A5
//#define LED_COMPOSE_PIN E26

/****************************************************************************************************
*
* Keymap: Default Layer in Qwerty
*
* ,-------------------------------------------------------------------------------------------------------------------.
* | Esc    |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |  F8  |  F9  |  F10 |  F12 | PSCR | SLCK | PAUS |  FN0 |  BOOT  |
* |--------+------+------+------+------+------+---------------------------+------+------+------+------+------+--------|
* | =+     |  1!  |  2@  |  3#  |  4$  |  5%  |                           |  6^  |  7&  |  8*  |  9(  |  0)  | -_     |
* |--------+------+------+------+------+------|                           +------+------+------+------+------+--------|
* | Tab    |   Q  |   W  |   E  |   R  |   T  |                           |   Y  |   U  |   I  |   O  |   P  | \|     |
* |--------+------+------+------+------+------|                           |------+------+------+------+------+--------|
* | Caps   |   A  |   S  |   D  |   F  |   G  |                           |   H  |   J  |   K  |   L  |  ;:  | '"     |
* |--------+------+------+------+------+------|                           |------+------+------+------+------+--------|
* | Shift  |   Z  |   X  |   C  |   V  |   B  |                           |   N  |   M  |  ,.  |  .>  |  /?  | Shift  |
* `--------+------+------+------+------+-------                           `------+------+------+------+------+--------'
*          | `~   | INS  | Left | Right|                                         | Up   | Down |  [{  |  ]}  |
*          `---------------------------'                                         `---------------------------'
*                                        ,-------------.         ,-------------.
*                                        | Ctrl | Alt  |         | Gui  | Ctrl |
*                                 ,------|------|------|         |------+------+------.
*                                 |      |      | Home |         | PgUp |      |      |
*                                 | BkSp | Del  |------|         |------|Return| Space|
*                                 |      |      | End  |         | PgDn |      |      |
*                                 `--------------------'         `--------------------'
 */

// Tap Dance declarations
enum {
    DANCE_CAPS,
    DANCE_DASH,
    DANCE_INS,
};


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [0] = LAYOUT(TD(DANCE_CAPS), KC_F1, KC_F2, KC_F3, KC_F4, KC_F5, KC_F6, KC_F7, KC_F8, KC_EQL, KC_1, KC_2, KC_3, KC_4, KC_5, LT(1,KC_TAB), KC_Q, KC_W, KC_E, KC_R, KC_T, TD(DANCE_CAPS), KC_A, KC_S, KC_D, KC_F, KC_G, KC_LSPO, LT(3,KC_Z), KC_X, KC_C, KC_V, KC_B, KC_GRV, TD(DANCE_INS), LT(4,KC_LEFT), LT(2,KC_RGHT), KC_TAB, KC_LGUI, KC_HOME, LCTL_T(KC_BSPC), LCAG_T(KC_DEL), LT(3,KC_END), KC_F9, KC_F10, KC_F11, KC_F12, KC_PSCR, KC_SLCK, KC_PAUS, TG(1), RESET, KC_6, KC_7, KC_8, KC_9, KC_0, TD(DANCE_DASH), KC_Y, KC_U, KC_I, KC_O, KC_P, KC_BSLS, KC_H, KC_J, KC_K, KC_L, KC_SCLN, KC_QUOT, KC_N, KC_M, KC_COMM, KC_DOT, KC_SLSH, KC_RSPC, LT(2,KC_UP), LT(4,KC_DOWN), KC_LBRC, KC_RBRC, KC_RALT, KC_RGUI, KC_PGUP, LT(3,KC_PGDN), RALT_T(KC_ENT), KC_SPC),
    [1] = LAYOUT(KC_ESC, KC_F1, KC_F2, KC_F3, KC_F4, KC_F5, KC_F6, KC_F7, KC_F8, KC_GRV, KC_1, KC_2, KC_3, KC_4, KC_5, KC_Y, KC_TAB, KC_Q, KC_W, KC_E, KC_R, KC_ESC, KC_LSFT, KC_A, KC_S, KC_D, KC_F, KC_LSFT, KC_EQL, KC_Z, KC_X, KC_C, KC_V, KC_GRV, KC_INS, KC_LEFT, KC_RGHT, KC_LCTL, KC_LALT, KC_HOME, KC_SPC, KC_DEL, KC_PGDN, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_TRNS, KC_NO, KC_NO, KC_NLCK, KC_PEQL, KC_PSLS, KC_PAST, KC_NO, KC_NO, KC_P7, KC_P8, KC_P9, KC_PMNS, KC_NO, KC_NO, KC_P4, KC_P5, KC_P6, KC_PPLS, KC_NO, KC_NO, KC_P1, KC_P2, KC_P3, KC_PENT, KC_NO, KC_NO, KC_NO, KC_PDOT, KC_PENT, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_P0),
    [2] = LAYOUT(KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_F8, KC_F9, KC_F10, KC_F11, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_LEFT, KC_DOWN, KC_UP, KC_RGHT, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO),
    [3] = LAYOUT(KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_LCTL, KC_LALT, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_WH_L, KC_NO, KC_WH_R, KC_NO, KC_NO, KC_WH_U, KC_BTN4, KC_MS_U, KC_BTN5, KC_NO, KC_NO, KC_WH_D, KC_MS_L, KC_MS_D, KC_MS_R, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_MPLY, KC_NO, KC_VOLU, KC_VOLD, KC_MPRV, KC_MNXT, KC_NO, KC_NO, KC_NO, KC_NO, KC_BTN2, KC_BTN1),
    [4] = LAYOUT(KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_LSFT, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_DEL, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, LALT(KC_LEFT), RSFT(KC_F10), LALT(KC_RIGHT), KC_NO, KC_NO, LSA(KC_LEFT), LCTL(KC_PGDOWN), LCTL(KC_PGUP), LSA(KC_RGHT), KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_RSFT, LALT(KC_J), LALT(KC_K), (QK_LCTL | QK_LGUI | (KC_LEFT)), (QK_LCTL | QK_LGUI | (KC_RIGHT)), KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO)
};




uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case RALT_T(KC_ENT):
            return TAPPING_TERM + 100;
        case LT(4,KC_SPC):
            return TAPPING_TERM - 20;
        default:
            return TAPPING_TERM;
    }
}

void matrix_init_user(void) {}

void matrix_scan_user(void) {}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    return true;
}

void led_set_user(uint8_t usb_led) {

}

bool led_update_user(led_t usb_led) {
    if (usb_led.num_lock) {
        ledTurnOn(LED_NUM_LOCK);
    } else {
        ledTurnOff(LED_NUM_LOCK);
    }

    if (usb_led.caps_lock) {
        ledTurnOn(LED_CAPS_LOCK);
    } else {
        ledTurnOff(LED_CAPS_LOCK);
    }
    return false;
}


layer_state_t layer_state_set_user(layer_state_t state) {
    ledTurnOff(LED_KEYPAD);
    ledTurnOff(LED_SCROLL_LOCK);

    uint8_t layer = get_highest_layer(state);
    bool LED_1 = !(layer & 0x1);
    bool LED_2 = !(layer & 0x2);
    writePin(LED_KEYPAD, LED_1);
    writePin(LED_SCROLL_LOCK, LED_2);
    return state;
}

typedef struct {
    bool is_press_action;
    uint8_t step;
} tap;

enum {
    SINGLE_TAP = 1,
    SINGLE_HOLD,
    DOUBLE_TAP,
    DOUBLE_HOLD,
    DOUBLE_SINGLE_TAP,
    MORE_TAPS
};


static tap dance_state[3];

uint8_t dance_step(qk_tap_dance_state_t *state);

uint8_t dance_step(qk_tap_dance_state_t *state) {
    if (state->count == 1) {
        if (state->interrupted || !state->pressed) return SINGLE_TAP;
        else return SINGLE_HOLD;
    } else if (state->count == 2) {
        if (state->interrupted) return DOUBLE_SINGLE_TAP;
        else if (state->pressed) return DOUBLE_HOLD;
        else return DOUBLE_TAP;
    }
    return MORE_TAPS;
}


void on_dance_0(qk_tap_dance_state_t *state, void *user_data);
void dance_0_finished(qk_tap_dance_state_t *state, void *user_data);
void dance_0_reset(qk_tap_dance_state_t *state, void *user_data);

void on_dance_0(qk_tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(KC_ESCAPE);
        tap_code16(KC_ESCAPE);
        tap_code16(KC_ESCAPE);
    }
    if(state->count > 3) {
        tap_code16(KC_ESCAPE);
    }
}

void dance_0_finished(qk_tap_dance_state_t *state, void *user_data) {
    dance_state[0].step = dance_step(state);
    switch (dance_state[0].step) {
        case SINGLE_TAP: register_code16(KC_ESCAPE); break;
        case DOUBLE_TAP: register_code16(KC_ESCAPE); register_code16(KC_ESCAPE); break;
        case DOUBLE_HOLD: register_code16(KC_CAPSLOCK); break;
        case DOUBLE_SINGLE_TAP: tap_code16(KC_ESCAPE); register_code16(KC_ESCAPE);
    }
}

void dance_0_reset(qk_tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[0].step) {
        case SINGLE_TAP: unregister_code16(KC_ESCAPE); break;
        case DOUBLE_TAP: unregister_code16(KC_ESCAPE); break;
        case DOUBLE_HOLD: unregister_code16(KC_CAPSLOCK); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(KC_ESCAPE); break;
    }
    dance_state[0].step = 0;
}
void on_dance_1(qk_tap_dance_state_t *state, void *user_data);
void dance_1_finished(qk_tap_dance_state_t *state, void *user_data);
void dance_1_reset(qk_tap_dance_state_t *state, void *user_data);

void on_dance_1(qk_tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(LSFT(KC_INSERT));
        tap_code16(LSFT(KC_INSERT));
        tap_code16(LSFT(KC_INSERT));
    }
    if(state->count > 3) {
        tap_code16(LSFT(KC_INSERT));
    }
}

void dance_1_finished(qk_tap_dance_state_t *state, void *user_data) {
    dance_state[1].step = dance_step(state);
    switch (dance_state[1].step) {
        case SINGLE_TAP: register_code16(LSFT(KC_INSERT)); break;
        case SINGLE_HOLD: register_code16(LSFT(KC_F10)); break;
        case DOUBLE_TAP: register_code16(LSFT(KC_INSERT)); register_code16(LSFT(KC_INSERT)); break;
        case DOUBLE_SINGLE_TAP: tap_code16(LSFT(KC_INSERT)); register_code16(LSFT(KC_INSERT));
    }
}

void dance_1_reset(qk_tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[1].step) {
        case SINGLE_TAP: unregister_code16(LSFT(KC_INSERT)); break;
        case SINGLE_HOLD: unregister_code16(LSFT(KC_F10)); break;
        case DOUBLE_TAP: unregister_code16(LSFT(KC_INSERT)); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(LSFT(KC_INSERT)); break;
    }
    dance_state[1].step = 0;
}
void on_dance_2(qk_tap_dance_state_t *state, void *user_data);
void dance_2_finished(qk_tap_dance_state_t *state, void *user_data);
void dance_2_reset(qk_tap_dance_state_t *state, void *user_data);

void on_dance_2(qk_tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(KC_MINUS);
        tap_code16(KC_MINUS);
        tap_code16(KC_MINUS);
    }
    if(state->count > 3) {
        tap_code16(KC_MINUS);
    }
}

void dance_2_finished(qk_tap_dance_state_t *state, void *user_data) {
    dance_state[2].step = dance_step(state);
    switch (dance_state[2].step) {
        case SINGLE_TAP: register_code16(KC_MINUS); break;
        case SINGLE_HOLD: register_code16(KC_UNDS); break;
        case DOUBLE_TAP: register_code16(KC_MINUS); register_code16(KC_MINUS); break;
        case DOUBLE_SINGLE_TAP: tap_code16(KC_MINUS); register_code16(KC_MINUS);
    }
}

void dance_2_reset(qk_tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[2].step) {
        case SINGLE_TAP: unregister_code16(KC_MINUS); break;
        case SINGLE_HOLD: unregister_code16(KC_UNDS); break;
        case DOUBLE_TAP: unregister_code16(KC_MINUS); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(KC_MINUS); break;
    }
    dance_state[2].step = 0;
}

qk_tap_dance_action_t tap_dance_actions[] = {
    [DANCE_CAPS] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_0, dance_0_finished, dance_0_reset),
    [DANCE_INS] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_1, dance_1_finished, dance_1_reset),
    [DANCE_DASH] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_2, dance_2_finished, dance_2_reset),
};