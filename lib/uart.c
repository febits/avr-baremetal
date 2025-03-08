#include <avr/io.h>
#include <stddef.h>

#include "types.h"
#include "utils.h"

#define BRATE(brate) ((F_CPU / (16UL * (brate))) - 1UL)

void uart_init(u32 baudrate) {
    UBRR0 = BRATE(baudrate);

    UCSR0C = (0 << UMSEL00) | (0 << UMSEL01) | (0 << UPM01) | (0 << UPM00) |
             (0 << USBS0) | (0 << UCSZ02) | (1 << UCSZ01) | (1 << UCSZ00);

    UCSR0B = (1 << RXEN0) | (1 << TXEN0);
}

void uart_sendbyte(u8 data) {
    while (!readbit(UCSR0A, UDRE0))
        ;

    UDR0 = data;
}

u8 uart_recvbyte(void) {
    while (!readbit(UCSR0A, RXC0))
        ;

    return UDR0;
}

void uart_puts(unsigned const char *s) {
    while (*s != '\0')
        uart_sendbyte(*s++);
}

void uart_gets(unsigned char *buf, size_t size) {
    size_t i = 0;

    while (i < size - 1) {
        buf[i] = uart_recvbyte();
        if (buf[i] == '\n') break;
        i++;
    }

    buf[size - 1] = '\0';
}
