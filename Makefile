CC=avr-gcc
CFLAGS=-Os -DF_CPU=16000000UL -mmcu=atmega328p -Iinclude

BUILD_DIR=build
EX_DIR=examples

LIB_SRC=$(wildcard lib/*.c)

EX_SRC=$(wildcard $(EX_DIR)/*.c)
EX_BIN=$(patsubst %.c, $(BUILD_DIR)/%.bin, $(EX_SRC))

.PHONY: all clean always

default: always $(EX_BIN)

$(BUILD_DIR)/%.bin: %.c
	$(CC) $(CFLAGS) $(LIB_SRC) $< -o $@
	avr-objcopy -O ihex -R .eeprom $@ $@

always:
	mkdir -p $(BUILD_DIR)/$(EX_DIR)

clean:
	rm -rf $(BUILD_DIR)
