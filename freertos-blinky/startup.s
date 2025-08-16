.section .isr_vector, "a", %progbits
.type g_pfnVectors, %object
g_pfnVectors:
    .word _estack
    .word _start
    .word NMI_Handler
    .word HardFault_Handler
    .word 0  // ... filler
    .word xPortPendSVHandler
    .word xPortSysTickHandler
    .word vPortSVCHandler

.section .text
.global _start
_start:
    ldr sp, =_estack
    bl main
loop: b loop

NMI_Handler:       b .
HardFault_Handler: b .
