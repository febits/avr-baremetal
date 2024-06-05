#include <util/delay.h>

#include "io.h"

#define LED_PIN 13

int main(void) {
  set_pin_mode(LED_PIN, OUTPUT);

  for (;;) {
    digital_write(LED_PIN, HIGH);
    _delay_ms(500);
    digital_write(LED_PIN, LOW);
    _delay_ms(500);
  }
}
