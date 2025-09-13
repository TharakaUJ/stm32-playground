.section .isr_vector, "a", %progbits
.type g_pfnVectors, %object
g_pfnVectors:
    .word _estack                    // 0x00: Initial stack pointer
    .word _start                     // 0x04: Reset handler
    .word NMI_Handler                // 0x08: NMI handler
    .word HardFault_Handler          // 0x0C: Hard fault handler
    .word MemManage_Handler          // 0x10: Memory management fault
    .word BusFault_Handler           // 0x14: Bus fault handler
    .word UsageFault_Handler         // 0x18: Usage fault handler
    .word 0                          // 0x1C: Reserved
    .word 0                          // 0x20: Reserved
    .word 0                          // 0x24: Reserved
    .word 0                          // 0x28: Reserved
    .word SVC_Handler                // 0x2C: SVCall handler
    .word DebugMon_Handler           // 0x30: Debug monitor handler
    .word 0                          // 0x34: Reserved
    .word PendSV_Handler             // 0x38: PendSV handler
    .word SysTick_Handler            // 0x3C: SysTick handler

.section .text
.global _start
_start:
    ldr   r0, =_estack
    mov   sp, r0
    bl main
loop: b loop

// Default exception handlers
NMI_Handler:       b .
HardFault_Handler: b .
MemManage_Handler: b .
BusFault_Handler:  b .
UsageFault_Handler: b .
SVC_Handler:       b .
DebugMon_Handler:  b .
PendSV_Handler:    b .
SysTick_Handler:   b .
