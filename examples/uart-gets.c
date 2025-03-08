#include <string.h>

#include "uart.h"

int main(void) {
    uart_init(9600);

    unsigned char buf[10] = {0};

    for (;;) {
        memset(buf, 0, 10);
        uart_gets(buf, 10);
        uart_puts(buf);
    }
}
