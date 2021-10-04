#include QMK_KEYBOARD_H
#include "version.h"

enum layers {
    BASE, // default layer
    SYMB, // symbols
    MDIA,  // media keys
    GAME, // gaming layer
};

enum custom_keycodes {
#ifdef ORYX_CONFIGURATOR
  VRSN = EZ_SAFE_RANGE,
#else
  VRSN = SAFE_RANGE,
#endif
  RGB_SLD
};

#define LANG_SWITCH LALT(KC_LSFT)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/* Keymap 0: Basic layer
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |  Esc   | 1  ! | 2  @ | 3  # | 4  $ | 5  % |  F1  |           | Lang | 6  ^ | 7  & | 8  * | 9  ( | 0  ) | Bckspc |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |  Tab   |   Q  |   W  |   E  |   R  |   T  |  F2  |           |  L2  |   Y  |   U  |   I  |   O  |   P  | \   |  |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |  Ctrl  |   A  |   S  |  D   |   F  |   G  |------|           |------|   H  |   J  |   K  |   L  | ;  : |  ' "   |
 * |--------+------+------+------+------+------|  F3  |           |  L1  |------+------+------+------+------+--------|
 * | LShift |   Z  |   X  |   C  |   V  |   B  |      |           |      |   N  |   M  | ,  < | . >  | /  ? |  - _   |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |  L1  | `  ~ | ' "  |  F1  |  L2  |                                       |  {   |  }   | [  { | ]  } |  L1  |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,--------------.       ,---------------.
 *                                        | Home  | End  |       | PgUp  |Insert |
 *                                 ,------|-------|------|       |-------+-------+------.
 *                                 |      |       |RCtrl |       | Del   |       |      |
 *                                 | Alt  | LGui  |------|       |-------| Enter |Space |
 *                                 |      |       | LGui |       | Bcsp  |       |      |
 *                                 `---------------------'       `----------------------'
 */
[BASE] = LAYOUT_ergodox(  // layer 0 : default
  // left hand
  KC_ESC,     KC_1,    KC_2,     KC_3,     KC_4,   KC_5,  LANG_SWITCH,
  KC_TAB,     KC_Q,    KC_W,     KC_E,     KC_R,   KC_T,  LAG(KC_U),
  KC_LCTL,    KC_A,    KC_S,     KC_D,     KC_F,   KC_G,
  KC_LSFT,    KC_Z,    KC_X,     KC_C,     KC_V,   KC_B,  LAG(KC_I),
  MO(1),      KC_GRV,  KC_QUOT,  KC_F1,  MO(2),

                                               KC_HOME,   KC_END,
                                                          KC_RCTRL,
                                      KC_LALT, KC_LGUI,   KC_PGDN,

  // right hand
LANG_SWITCH,   KC_6,     KC_7,     KC_8,     KC_9,     KC_0,      KC_BSPC,
      MO(2),   KC_Y,     KC_U,     KC_I,     KC_O,     KC_P,      KC_BSLS,
               KC_H,     KC_J,     KC_K,     KC_L,     KC_SCLN,   KC_QUOT,
      MO(1),   KC_N,     KC_M,     KC_COMM,  KC_DOT,   KC_SLSH,   KC_MINS,
                         KC_LCBR,  KC_RCBR,  KC_LBRC,  KC_RBRC,   MO(1),

  KC_PGUP,  KC_INS,
  KC_DEL,
  KC_BSPC,  KC_ENT,    KC_SPC
),
/* Keymap 1: Symbol Layer
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |        |  F1  |  F2  |  F3  |  F4  |  F5  |      |           |      |  F6  |  F7  |  F8  |  F9  |  F10 |   F11  |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |        |   !  |   @  |   {  |   }  |   |  |      |           |      |   Up |   7  |   8  |   9  |   *  |   F12  |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |   #  |   $  |   (  |   )  |   `  |------|           |------| Down |   4  |   5  |   6  |   +  |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |   %  |   ^  |   [  |   ]  |   ~  |      |           |      |   &  |   1  |   2  |   3  |   \  |        |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |      |      |      |      |      |                                       |   =  |    . |   0  |   -  |      |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |      |      |       |      |      |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |      |      |      |       |      |      |      |
 *                                 |      |      |------|       |------|      |      |
 *                                 |      |      |      |       |      |      |      |
 *                                 `--------------------'       `--------------------'
 */
[SYMB] = LAYOUT_ergodox(
       // left hand
       KC_TRNS,KC_F1,  KC_F2,  KC_F3,  KC_F4,  KC_F5,  KC_TRNS,
       KC_TRNS,KC_EXLM,KC_AT,  KC_LCBR,KC_RCBR,KC_PIPE,KC_TRNS,
       KC_TRNS,KC_HASH,KC_DLR, KC_LPRN,KC_RPRN,KC_GRV,
       KC_TRNS,KC_PERC,KC_CIRC,KC_LBRC,KC_RBRC,KC_TILD,KC_TRNS,
       KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,

                                       KC_TRNS,KC_TRNS,
                                               KC_TRNS,
                               KC_TRNS,KC_SPC,KC_TRNS,
       // right hand
       KC_TRNS, KC_F6,   KC_F7,  KC_F8,   KC_F9,   KC_F10,  KC_F11,
       KC_TRNS, KC_UP,   KC_7,   KC_8,    KC_9,    KC_ASTR, KC_F12,
                KC_DOWN, KC_4,   KC_5,    KC_6,    KC_PLUS, KC_TRNS,
       KC_TRNS, KC_AMPR, KC_1,   KC_2,    KC_3,    KC_BSLS, KC_TRNS,
                         KC_EQL,KC_DOT,  KC_0,    KC_MINS,  KC_TRNS,

       KC_TRNS, KC_TRNS,
       KC_TRNS,
       KC_TRNS, KC_TRNS, KC_TRNS
),
/* Keymap 2: Media and mouse keys
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |        |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |        |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      |      |      |      |      |------|           |------| Left | Down |  Up  |Right |      |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      |      |      |      |      |      |           |      |      |VolDwn|VolUp | Mute |      |        |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |      |      |      |      |      |                                       | Play | Prev | Next |      |      |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |      |      |       |      |      |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |      |      |      |       |      |Brwser|Brwser|
 *                                 |      |      |------|       |------|Back  | Fwd  |
 *                                 |      |      |      |       |      |      |      |
 *                                 `--------------------'       `--------------------'
 */
// MEDIA AND MOUSE
[MDIA] = LAYOUT_ergodox(
         RESET, KC_TRNS,        KC_TRNS,     KC_TRNS,        KC_TRNS, KC_TRNS,    KC_TRNS,
       KC_TRNS, KC_TRNS,        KC_TRNS,     KC_TRNS,        KC_TRNS, KC_TRNS,    KC_TRNS,
       KC_TRNS, KC_TRNS,        KC_TRNS,     KC_TRNS,        KC_TRNS, KC_TRNS,
       KC_TRNS, KC_TRNS,        KC_TRNS,     KC_TRNS,        KC_TRNS, KC_TRNS,    KC_TRNS,
       KC_TRNS, KC_TRNS,        KC_TRNS,     KC_TRNS,        KC_TRNS,

                                           KC_TRNS, KC_TRNS,
                                                    KC_TRNS,
                                  KC_TRNS, KC_TRNS, KC_TRNS,
    // right hand
       KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,  KC_TRNS, KC_TRNS,
       KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,  KC_TRNS, KC_TRNS,
                 KC_LEFT, KC_DOWN, KC_UP,   KC_RIGHT, KC_TRNS, KC_TRNS,
       KC_TRNS,  KC_TRNS, KC_VOLD, KC_VOLU, KC_MUTE,  KC_TRNS, KC_TRNS,
                          KC_MPLY, KC_MPRV, KC_MNXT,  KC_TRNS, KC_TRNS,

       KC_TRNS,  KC_TRNS,
       KC_TRNS,
       KC_TRNS,  KC_WBAK, KC_WFWD
),
/* Keymap 3: Gaming Layer
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |        |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |        |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      |      |      |      |      |------|           |------| Left | Down |  Up  |Right |      |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |      |      |      |      |      |                                       |      |      |      |      |      |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |      |      |       |      |      |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |      |      |      |       |      |      |      |
 *                                 |      |Space |------|       |------|      |      |
 *                                 |      |      |      |       |      |      |      |
 *                                 `--------------------'       `--------------------'
 */
// MEDIA AND MOUSE
[GAME] = LAYOUT_ergodox(
       KC_TRNS, KC_TRNS,        KC_TRNS,     KC_TRNS,        KC_TRNS, KC_TRNS,    KC_TRNS,
       KC_TRNS, KC_TRNS,        KC_TRNS,     KC_TRNS,        KC_TRNS, KC_TRNS,    KC_TRNS,
       KC_TRNS, KC_TRNS,        KC_TRNS,     KC_TRNS,        KC_TRNS, KC_TRNS,
       KC_TRNS, KC_TRNS,        KC_TRNS,     KC_TRNS,        KC_TRNS, KC_TRNS,    KC_TRNS,
       KC_TRNS, KC_TRNS,        KC_TRNS,     KC_TRNS,        KC_TRNS,

                                           KC_TRNS, KC_TRNS,
                                                    KC_TRNS,
                                  KC_TRNS, KC_SPC,  KC_TRNS,
    // right hand
       TG(GAME),  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,  KC_TRNS, KC_TRNS,
       KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,  KC_TRNS, KC_TRNS,
                 KC_LEFT, KC_DOWN, KC_UP,   KC_RIGHT, KC_TRNS, KC_TRNS,
       KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,  KC_TRNS, KC_TRNS,
                          KC_TRNS, KC_TRNS, KC_TRNS,  KC_TRNS, KC_TRNS,

       KC_TRNS,  KC_TRNS,
       KC_TRNS,
       KC_TRNS,  KC_WBAK, KC_WFWD
)
};
