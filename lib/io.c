#include <avr/io.h>

#include "io.h"
#include "types.h"

#define setbit(base, v) (base |= (1 << v))
#define clearbit(base, v) (base &= ~(1 << v))

#define SETORCLEAR(cond, addr, v)                                              \
  do {                                                                         \
    cond ? setbit(addr, v) : clearbit(addr, v);                                \
  } while (0)

static void disable_pwm(u8 pin) {
  switch (pin) {
    case 3:
      TCCR2A &= ~(1 << COM2B1);
      break;
    case 5:
      TCCR0A &= ~(1 << COM0B1);
      break;
    case 6:
      TCCR0A &= ~(1 << COM0A1);
      break;
    case 9:
      TCCR1A &= ~(1 << COM1A1);
      break;
    case 10:
      TCCR1A &= ~(1 << COM1B1);
      break;
    case 11:
      TCCR2A &= ~(1 << COM2A1);
      break;
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
      if (PIND & (1 << 0)) return HIGH;
      break;
    case 1:
      if (PIND & (1 << 1)) return HIGH;
      break;
    case 2:
      if (PIND & (1 << 2)) return HIGH;
      break;
    case 3:
      if (PIND & (1 << 3)) return HIGH;
      break;
    case 4:
      if (PIND & (1 << 4)) return HIGH;
      break;
    case 5:
      if (PIND & (1 << 5)) return HIGH;
      break;
    case 6:
      if (PIND & (1 << 6)) return HIGH;
      break;
    case 7:
      if (PIND & (1 << 7)) return HIGH;
      break;

    case 8:
      if (PINB & (1 << 0)) return HIGH;
      break;
    case 9:
      if (PINB & (1 << 1)) return HIGH;
      break;
    case 10:
      if (PINB & (1 << 2)) return HIGH;
      break;
    case 11:
      if (PINB & (1 << 3)) return HIGH;
      break;
    case 12:
      if (PINB & (1 << 4)) return HIGH;
      break;
    case 13:
      if (PINB & (1 << 5)) return HIGH;
      break;
  }

  return LOW;
}
