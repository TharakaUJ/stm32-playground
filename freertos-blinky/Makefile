# Path to local toolchain
TOOLCHAIN = $(CURDIR)/arm-none-eabi-gcc/bin

CC = $(TOOLCHAIN)/arm-none-eabi-gcc
OBJCOPY = $(TOOLCHAIN)/arm-none-eabi-objcopy


CFLAGS=-mcpu=cortex-m3 -mthumb -O2 -std=gnu11 -ffreestanding -nostdlib
LDFLAGS=-T linker.ld -nostdlib -Wl,--gc-sections

SRC = main.c startup.s mem.c \
      FreeRTOS/tasks.c \
      FreeRTOS/list.c \
      FreeRTOS/queue.c \
      FreeRTOS/timers.c \
      FreeRTOS/portable/GCC/ARM_CM3/port.c \
      FreeRTOS/portable/MemMang/heap_4.c

INCLUDES = -I. \
           -IFreeRTOS/include \
           -IFreeRTOS/include \
           -IFreeRTOS/portable/GCC/ARM_CM3

all: main.bin

main.elf: $(SRC)
	$(CC) $(CFLAGS) $(INCLUDES) $(SRC) $(LDFLAGS) -o main.elf

main.bin: main.elf
	$(OBJCOPY) -O binary main.elf main.bin

clean:
	rm -f *.o *.elf *.bin
