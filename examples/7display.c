#include <util/delay.h>

#include "io.h"
#include "types.h"

#define LED_NUMBER_MAX 8
#define MAX_DISPLAYABLE_DIGIT 9

//                         a  b  c  d  e  f  g  dp
u8 pins[LED_NUMBER_MAX] = {2, 3, 4, 5, 6, 7, 8, 9};
u8 numbers[10][LED_NUMBER_MAX] = {
    {HIGH, HIGH, HIGH, HIGH, HIGH, HIGH, LOW, LOW},
    {LOW, HIGH, HIGH, LOW, LOW, LOW, LOW, LOW},
    {HIGH, HIGH, LOW, HIGH, HIGH, LOW, HIGH, LOW},
    {HIGH, HIGH, HIGH, HIGH, LOW, LOW, HIGH, LOW},
    {LOW, HIGH, HIGH, LOW, LOW, HIGH, HIGH, LOW},
    {HIGH, LOW, HIGH, HIGH, LOW, HIGH, HIGH, LOW},
    {HIGH, LOW, HIGH, HIGH, HIGH, HIGH, HIGH, LOW},
    {HIGH, HIGH, HIGH, LOW, LOW, HIGH, LOW, LOW},
    {HIGH, HIGH, HIGH, HIGH, HIGH, HIGH, HIGH, LOW},
    {HIGH, HIGH, HIGH, LOW, LOW, HIGH, HIGH, LOW}};

bool display7_print(u8 num) {
    if (num < 0 || num > MAX_DISPLAYABLE_DIGIT) {
        return false;
    }

    for (u8 i = 0; i < LED_NUMBER_MAX; i++) {
        digital_write(pins[i], numbers[num][i]);
    }

    return true;
}

int main(void) {
    for (u8 i = 0; i < LED_NUMBER_MAX; i++) {
        set_pin_mode(pins[i], OUTPUT);
    }

    for (;;) {
        for (u8 i = 0; i < 10; i++) {
            display7_print(i);
            _delay_ms(500);
        }
    }
}
