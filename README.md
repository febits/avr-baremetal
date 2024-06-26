# AVR Bare Metal

Here I'll let some experiments with bare metal in [**AVR**](https://en.wikipedia.org/wiki/AVR_microcontrollers) microcontrollers.

In this repository, all the examples and stuff will be exclusively to [**ATmega328P**](https://ww1.microchip.com/downloads/en/DeviceDoc/Atmel-7810-Automotive-Microcontrollers-ATmega328P_Datasheet.pdf) (which is a microcontroller from AVR family) and [**Arduino Uno**](https://docs.arduino.cc/hardware/uno-rev3/).

The code here are focused to re-create the functions provided by the Arduino Library, such as `pinMode`, `digitalWrite`, `digitalRead`, `delay`, etc. The firmwares in `firmwares` dir use those functions.

## Functions so far

- `set_pin_mode()`: sets the pin mode (`INPUT` or `OUTPUT`).
- `digital_write()`: writes `LOW` or `HIGH` in the given pin.
- `digital_read()`: reads `LOW` or `HIGH` from the given pin.

## Try it yourself

Compiling the standard lib and the examples (firmwares):

```bash
make
```

After that, you can upload the examples inside the `build/firmwares/` dir:

```
./upload [SERIALPORT] build/firmwares/*.bin
```

> SERIALPORT is platform dependent, but in my case is something like `/dev/ttyUSB0`.

> Any .bin in `build/firmwares` can be uploaded, but check and modify the code in `firmwares` if necessary.

> Remember: only works on ATmega328P with Arduino Uno.

## Examples

- [**Blinking LED**](https://youtu.be/FJVqrd77pOk)
- [**Toggle LED with Push-up Button**](https://youtu.be/GDJenpOJX3I)
- [**7 segment display**](https://youtu.be/rD-V1SiSl1o)

## TODO

- [ ] Serial Ports Support (Analog)
- [ ] Bultin Timers Functions (delay, sleep, etc)
