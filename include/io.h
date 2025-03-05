#ifndef IO_H
#define IO_H

#include "types.h"

typedef enum { INPUT, OUTPUT } mode;
typedef enum { OUT_OF_RANGE = -1, LOW, HIGH, SUCCESS } op_status;

op_status set_pin_mode(u8 pin, u8 mode);
op_status digital_write(u8 pin, u8 state);
op_status digital_read(u8 pin);

#endif
