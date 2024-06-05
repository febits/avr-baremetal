#ifndef IO_H
#define IO_H

#include "types.h"

typedef enum { INPUT, OUTPUT } mode;
typedef enum { OUT_OF_RANGE = -1, LOW, HIGH, SUCCESS } op_status;

#define _PORTB (*(volatile byte *)0x25)
#define _DDRB  (*(volatile byte *)0x24)
#define _PINB  (*(volatile byte *)0x23)

#define _PORTD (*(volatile byte *)0x2b)
#define _DDRD  (*(volatile byte *)0x2a)
#define _PIND  (*(volatile byte *)0x29)

op_status set_pin_mode(u8 pin, u8 mode);
op_status digital_write(u8 pin, u8 state);
op_status digital_read(u8 pin);

#endif
