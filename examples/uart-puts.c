#include "delay.h"
#include "uart.h"

int main(void) {
    uart_init(9600);

    for (;;) {
        uart_puts((unsigned const char *)"Hello from UART!\n");
        delay_ms(500);
    }
}
