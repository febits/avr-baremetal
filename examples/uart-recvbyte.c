#include "io.h"
#include "uart.h"
#include "utils.h"

#define TOGGLE_CHAR 'T'

int main(void) {
    set_pin_mode(LED_BULTIN, OUTPUT);
    uart_init(9600);

    bool state = LOW;

    for (;;) {
        if (uart_recvbyte() == 'T') {
            state = !state;
            digital_write(LED_BULTIN, state);
        }
    }
}
