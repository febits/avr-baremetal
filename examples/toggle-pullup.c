#include <util/delay.h>

#include "io.h"
#include "types.h"
#include "utils.h"

#define BUTTON_PIN 12

int main(void) {
    set_pin_mode(LED_BULTIN, OUTPUT);
    set_pin_mode(BUTTON_PIN, INPUT_PULLUP);

    bool state = LOW;

    for (;;) {
        if (!digital_read(BUTTON_PIN)) {
            state = !state;
            digital_write(LED_BULTIN, state);
            _delay_ms(200);
        }
    }
}
