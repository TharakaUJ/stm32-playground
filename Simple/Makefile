CC = /home/tharaka/Documents/stm32-playground/freertos-blinky/arm-none-eabi-gcc/bin/arm-none-eabi-gcc
OBJCOPY = /home/tharaka/Documents/stm32-playground/freertos-blinky/arm-none-eabi-gcc/bin/arm-none-eabi-objcopy

CFLAGS = -mcpu=cortex-m3 -mthumb -O2 -std=gnu11 -ffreestanding -nostdlib
LDFLAGS = -T linker.ld -nostdlib -Wl,--gc-sections

TARGET = main
SOURCES = main.c startup.s

all: $(TARGET).bin

$(TARGET).elf: $(SOURCES) linker.ld
	$(CC) $(CFLAGS) $(SOURCES) $(LDFLAGS) -o $@

$(TARGET).bin: $(TARGET).elf
	$(OBJCOPY) -O binary $< $@

clean:
	rm -f *.o *.elf *.bin

upload: $(TARGET).bin
	dfu-util -d 1eaf:0003 -a 1 -D $(TARGET).bin

.PHONY: all clean upload
