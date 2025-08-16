#ifndef FREERTOS_CONFIG_H
#define FREERTOS_CONFIG_H

#include <stdint.h>

/*-----------------------------------------------------------
 * Application specific definitions.
 * Adjust these values for your hardware and requirements.
 *----------------------------------------------------------*/

#define configUSE_PREEMPTION            1
#define configUSE_IDLE_HOOK             0
#define configUSE_TICK_HOOK             0
#define configCPU_CLOCK_HZ              ( ( unsigned long ) 72000000 )  /* 72 MHz for STM32F103 */
#define configTICK_RATE_HZ              ( ( TickType_t ) 1000 )         /* 1 ms tick */
#define configMAX_PRIORITIES            ( 5 )
#define configMINIMAL_STACK_SIZE        ( ( unsigned short ) 128 )
#define configTOTAL_HEAP_SIZE           ( ( size_t ) ( 10 * 1024 ) )    /* 10 KB heap */
#define configMAX_TASK_NAME_LEN         ( 16 )
#define configUSE_16_BIT_TICKS          0
#define configIDLE_SHOULD_YIELD         1

/* Mutexes, semaphores, etc. */
#define configUSE_MUTEXES               1
#define configUSE_COUNTING_SEMAPHORES   1
#define configUSE_RECURSIVE_MUTEXES     1

/* Co-routines (usually disabled on Cortex-M3) */
#define configUSE_CO_ROUTINES           0
#define configMAX_CO_ROUTINE_PRIORITIES ( 2 )

/* Software timers */
#define configUSE_TIMERS                1
#define configTIMER_TASK_PRIORITY       ( 2 )
#define configTIMER_QUEUE_LENGTH        5
#define configTIMER_TASK_STACK_DEPTH    ( configMINIMAL_STACK_SIZE * 2 )

/* Cortex-M specific definitions. */
#define configPRIO_BITS                 4 /* STM32F103 has 16 priority levels (4 bits) */

#define configLIBRARY_LOWEST_INTERRUPT_PRIORITY         0xf
#define configLIBRARY_MAX_SYSCALL_INTERRUPT_PRIORITY    5
#define configKERNEL_INTERRUPT_PRIORITY                 ( configLIBRARY_LOWEST_INTERRUPT_PRIORITY << (8 - configPRIO_BITS) )
#define configMAX_SYSCALL_INTERRUPT_PRIORITY            ( configLIBRARY_MAX_SYSCALL_INTERRUPT_PRIORITY << (8 - configPRIO_BITS) )

/* Optional trace/debug */
#define configUSE_TRACE_FACILITY        0

#endif /* FREERTOS_CONFIG_H */
