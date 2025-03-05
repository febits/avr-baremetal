#include <avr/io.h>

#include "io.h"
#include "types.h"
#include "utils.h"

static void disable_pwm(u8 pin) {
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
    if ((pin < 0 || pin > 13) || (mode != INPUT && mode != OUTPUT)) {
        return OUT_OF_RANGE;
    }

    switch (pin) {
        case 0: SETORCLEAR(mode == OUTPUT, DDRD, 0); break;
        case 1: SETORCLEAR(mode == OUTPUT, DDRD, 1); break;
        case 2: SETORCLEAR(mode == OUTPUT, DDRD, 2); break;
        case 3: SETORCLEAR(mode == OUTPUT, DDRD, 3); break;
        case 4: SETORCLEAR(mode == OUTPUT, DDRD, 4); break;
        case 5: SETORCLEAR(mode == OUTPUT, DDRD, 5); break;
        case 6: SETORCLEAR(mode == OUTPUT, DDRD, 6); break;
        case 7: SETORCLEAR(mode == OUTPUT, DDRD, 7); break;

        case 8: SETORCLEAR(mode == OUTPUT, DDRB, 0); break;
        case 9: SETORCLEAR(mode == OUTPUT, DDRB, 1); break;
        case 10: SETORCLEAR(mode == OUTPUT, DDRB, 2); break;
        case 11: SETORCLEAR(mode == OUTPUT, DDRB, 3); break;
        case 12: SETORCLEAR(mode == OUTPUT, DDRB, 4); break;
        case 13: SETORCLEAR(mode == OUTPUT, DDRB, 5); break;
    }

    return SUCCESS;
}

op_status digital_write(u8 pin, u8 state) {
    if ((pin < 0 || pin > 13) || (state != LOW && state != HIGH)) {
        return OUT_OF_RANGE;
    }

    disable_pwm(pin);

    switch (pin) {
        case 0: SETORCLEAR(state == HIGH, PORTD, 0); break;
        case 1: SETORCLEAR(state == HIGH, PORTD, 1); break;
        case 2: SETORCLEAR(state == HIGH, PORTD, 2); break;
        case 3: SETORCLEAR(state == HIGH, PORTD, 3); break;
        case 4: SETORCLEAR(state == HIGH, PORTD, 4); break;
        case 5: SETORCLEAR(state == HIGH, PORTD, 5); break;
        case 6: SETORCLEAR(state == HIGH, PORTD, 6); break;
        case 7: SETORCLEAR(state == HIGH, PORTD, 7); break;

        case 8: SETORCLEAR(state == HIGH, PORTB, 0); break;
        case 9: SETORCLEAR(state == HIGH, PORTB, 1); break;
        case 10: SETORCLEAR(state == HIGH, PORTB, 2); break;
        case 11: SETORCLEAR(state == HIGH, PORTB, 3); break;
        case 12: SETORCLEAR(state == HIGH, PORTB, 4); break;
        case 13: SETORCLEAR(state == HIGH, PORTB, 5); break;
    }

    return SUCCESS;
}

op_status digital_read(u8 pin) {
    if (pin < 0 || pin > 13) {
        return OUT_OF_RANGE;
    }

    disable_pwm(pin);

    switch (pin) {
        case 0:
            if (readbit(PIND, 0)) return HIGH;
            break;
        case 1:
            if (readbit(PIND, 1)) return HIGH;
            break;
        case 2:
            if (readbit(PIND, 2)) return HIGH;
            break;
        case 3:
            if (readbit(PIND, 3)) return HIGH;
            break;
        case 4:
            if (readbit(PIND, 4)) return HIGH;
            break;
        case 5:
            if (readbit(PIND, 5)) return HIGH;
            break;
        case 6:
            if (readbit(PIND, 6)) return HIGH;
            break;
        case 7:
            if (readbit(PIND, 7)) return HIGH;
            break;

        case 8:
            if (readbit(PINB, 0)) return HIGH;
            break;
        case 9:
            if (readbit(PINB, 1)) return HIGH;
            break;
        case 10:
            if (readbit(PINB, 2)) return HIGH;
            break;
        case 11:
            if (readbit(PINB, 3)) return HIGH;
            break;
        case 12:
            if (readbit(PINB, 4)) return HIGH;
            break;
        case 13:
            if (readbit(PINB, 5)) return HIGH;
            break;
    }

    return LOW;
}
