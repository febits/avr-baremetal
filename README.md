# AVR Bare Metal

Here I'll let some experiments with bare metal in [**AVR**](https://en.wikipedia.org/wiki/AVR_microcontrollers) microcontrollers.

In this repository, all the examples and stuff relationed will be exclusively to [**ATmega328P**](https://ww1.microchip.com/downloads/en/DeviceDoc/Atmel-7810-Automotive-Microcontrollers-ATmega328P_Datasheet.pdf) (which is a microcontroller from AVR family) and [**Arduino Uno**](https://docs.arduino.cc/hardware/uno-rev3/).

The code here are focused in re-create the functions provided by the Arduino Library, such as `pinMode`, `digitalWrite`, `digitalRead`, `delay`, etc. The firmwares in `firmwares` dir use those functions.

## Functions so far

- `set_pin_mode()`: sets the pin mode (`INPUT` or `OUTPUT`).
- `digital_write()`: writes `LOW` or `HIGH` in the given pin.
- `digital_read()`: reads `LOW` or `HIGH` from the given pin.

## Examples

- **Blinking LED:**
<video width="320" height="240" style="display: block;" controls>
  <source src="./assets/blink.mp4" type="video/mp4">
</video>

- **Toggle LED with Push-up Button:**
<video width="320" height="240" style="display: block;" controls>
  <source src="./assets/toggle.mp4.mp4" type="video/mp4">
</video>

- **7 segment display:**
<video width="320" height="240" style="display: block;" controls>
  <source src="./assets/7display.mp4" type="video/mp4">
</video>

## TODO

- [ ] Serial Ports Support (Analog)
- [ ] Bultin Timers Functions (delay, sleep, etc)
