#include "delay.h"
#include "uart.h"

int main(void) {
    uart_init(9600);

    for (;;) {
        uart_sendbyte('A');
        delay_ms(500);
    }
}
