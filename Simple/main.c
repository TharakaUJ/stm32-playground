#include <stdint.h>

// Register definitions for STM32F103
#define RCC_APB2ENR   (*(volatile uint32_t *)0x40021018)
#define GPIOC_CRH     (*(volatile uint32_t *)0x40011004)
#define GPIOC_ODR     (*(volatile uint32_t *)0x4001100C)

void delay(volatile uint32_t count) {
    while (count--) {
        __asm__("nop");
    }
}

int main(void) {
    // Enable GPIOC clock
    RCC_APB2ENR |= (1 << 4);      
    
    // Configure PC13 as output (10MHz, push-pull)
    GPIOC_CRH &= ~(0xF << 20);    // Clear CNF13/MODE13
    GPIOC_CRH |=  (0x1 << 20);    // Set MODE13 to output 10MHz, CNF13 to push-pull

    while (1) {
        // Turn LED on (active low)
        GPIOC_ODR &= ~(1 << 13);  
        delay(500000);            
        
        // Turn LED off (active low)
        GPIOC_ODR |= (1 << 13);   
        delay(500000);            
    }
}
