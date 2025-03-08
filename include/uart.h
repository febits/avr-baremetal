#ifndef UART_H
#define UART_H

#include <stddef.h>

#include "types.h"

void uart_init(u32 baudrate);
void uart_sendbyte(u8 data);
u8 uart_recvbyte(void);
void uart_puts(unsigned const char *s);
void uart_gets(unsigned char *buf, size_t size);

#endif
