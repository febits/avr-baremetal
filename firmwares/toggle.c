#include <util/delay.h>

#include "io.h"
#include "types.h"

#define LED_PIN 12
#define BUTTON_PIN 13

int main(void) {
  set_pin_mode(LED_PIN, OUTPUT);
  set_pin_mode(BUTTON_PIN, INPUT);

  u8 state = LOW;

  for (;;) {
    if (digital_read(BUTTON_PIN)) {
      state = !state;
      digital_write(LED_PIN, state);
      _delay_ms(200);
    }
  }
}
