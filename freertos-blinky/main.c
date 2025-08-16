#include "FreeRTOS.h"
#include "task.h"
#include <stdint.h>

#define RCC_APB2ENR (*(volatile uint32_t*)0x40021018)
#define GPIOC_CRH   (*(volatile uint32_t*)0x40011004)
#define GPIOC_ODR   (*(volatile uint32_t*)0x4001100C)

void vBlinkTask(void *pvParameters) {
    while (1) {
        GPIOC_ODR ^= (1 << 13);
        vTaskDelay(pdMS_TO_TICKS(500));
    }
}

int main(void) {
    RCC_APB2ENR |= (1 << 4); // Enable GPIOC
    GPIOC_CRH &= ~(0xF << 20);
    GPIOC_CRH |= (0x1 << 20); // Output, push-pull

    xTaskCreate(vBlinkTask, "Blink", 128, NULL, 1, NULL);
    vTaskStartScheduler();

    while (1); // Should never reach here
}
