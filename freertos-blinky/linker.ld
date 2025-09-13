ENTRY(_start)

MEMORY {
  FLASH (rx) : ORIGIN = 0x08005000, LENGTH = 64K
  RAM (rwx)  : ORIGIN = 0x20000000, LENGTH = 20K
}

_estack = ORIGIN(RAM) + LENGTH(RAM);


SECTIONS {
  .isr_vector : {
    *(.isr_vector*)
  } > FLASH
  
  .text : {
    *(.text*)
    *(.rodata*)
  } > FLASH

  .bss : {
    *(.bss*)
  } > RAM

  .stack (COPY) : {
    *(.stack)
  } > RAM
}
