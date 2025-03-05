#include <avr/io.h>

#include "io.h"
#include "types.h"
#include "utils.h"

static inline void disable_pwm(u8 pin) {
    switch (pin) {
        case 3: clearbit(TCCR2A, COM2B1); break;
        case 5: clearbit(TCCR0A, COM0B1); break;
        case 6: clearbit(TCCR0A, COM0A1); break;
        case 9: clearbit(TCCR1A, COM1A1); break;
        case 10: clearbit(TCCR1A, COM1B1); break;
        case 11: clearbit(TCCR2A, COM2A1); break;
    }
}

op_status set_pin_mode(u8 pin, u8 mode) {
    if (pin > 13 || (mode != INPUT && mode != OUTPUT)) {
        return OUT_OF_RANGE;
    }

    if (pin <= 7) {
        SETORCLEAR(mode == OUTPUT, DDRD, pin);
    } else {
        SETORCLEAR(mode == OUTPUT, DDRB, (pin - 8));
    }

    return SUCCESS;
}

op_status digital_write(u8 pin, u8 state) {
    if (pin > 13 || (state != LOW && state != HIGH)) {
        return OUT_OF_RANGE;
    }

    disable_pwm(pin);

    if (pin <= 7) {
        SETORCLEAR(state == HIGH, PORTD, pin);
    } else {
        SETORCLEAR(state == HIGH, PORTB, (pin - 8));
    }

    return SUCCESS;
}

op_status digital_read(u8 pin) {
    if (pin > 13) {
        return OUT_OF_RANGE;
    }

    disable_pwm(pin);

    if (pin <= 7) {
        if (readbit(PIND, pin)) return HIGH;
    } else {
        if (readbit(PINB, (pin - 8))) return HIGH;
    }

    return LOW;
}
