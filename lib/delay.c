#include <avr/io.h>

#include "types.h"
#include "utils.h"

void delay_ms(u32 ms) {
    TCCR1B |= (1 << WGM12);
    TCCR1B |= (1 << CS10);

    OCR1A = 15999;

    for (u32 i = 0; i < ms; i++) {
        TCNT1 = 0;
        TIFR1 |= (1 << OCF1A);

        while (!readbit(TIFR1, OCF1A))
            ;
    }
}

void delay_us(u32 us) {
    TCCR1B |= (1 << WGM12);
    TCCR1B |= (1 << CS10);

    OCR1A = 15;

    for (u32 i = 0; i < us; i++) {
        TCNT1 = 0;
        TIFR1 |= (1 << OCF1A);

        while (!readbit(TIFR1, OCF1A))
            ;
    }
}
