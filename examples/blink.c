#include "io.h"
#include "utils.h"
#include "delay.h"

int main(void) {
    set_pin_mode(LED_BULTIN, OUTPUT);

    for (;;) {
        digital_write(LED_BULTIN, HIGH);
        delay_ms(500);
        digital_write(LED_BULTIN, LOW);
        delay_ms(500);
    }
}
