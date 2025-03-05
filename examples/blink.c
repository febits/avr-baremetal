#include <util/delay.h>

#include "io.h"
#include "utils.h"

int main(void) {
    set_pin_mode(LED_BULTIN, OUTPUT);

    for (;;) {
        digital_write(LED_BULTIN, HIGH);
        _delay_ms(500);
        digital_write(LED_BULTIN, LOW);
        _delay_ms(500);
    }
}
