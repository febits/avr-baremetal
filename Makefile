CC=avr-gcc
CFLAGS=-Os -DF_CPU=16000000UL -mmcu=atmega328p -Iinclude

BUILD_DIR=build
FIRM_DIR=firmwares

LIB_SRC=$(wildcard lib/*.c)
LIB_BIN=$(BUILD_DIR)/lib.o

FIRM_SRC=$(wildcard firmwares/*.c)
FIRM_BIN=$(patsubst %.c, $(BUILD_DIR)/%.bin, $(FIRM_SRC))

.PHONY: all clean always

default: always $(LIB_BIN) $(FIRM_BIN)

$(LIB_BIN): $(LIB_SRC)
	$(CC) $(CFLAGS) -c $^ -o $@

$(BUILD_DIR)/%.bin: %.c
	$(CC) $(CFLAGS) $(LIB_BIN) $< -o $@
	avr-objcopy -O ihex -R .eeprom $@ $@

always:
	mkdir -p $(BUILD_DIR)/firmwares

clean:
	rm -rf $(BUILD_DIR)
