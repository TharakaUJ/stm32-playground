#include <stdint.h>

#define RCC_APB2ENR   (*(volatile uint32_t *)0x40021018)
#define GPIOC_CRH     (*(volatile uint32_t *)0x40011004)
#define GPIOC_ODR     (*(volatile uint32_t *)0x4001100C)
#define GPIOA_CRL     (*(volatile uint32_t *)0x40010800)
#define GPIOA_ODR     (*(volatile uint32_t *)0x4001080C)

void delay(volatile uint32_t count) {
    while (count--) {
        __asm__("nop");
    }
}

int main(void) {
    RCC_APB2ENR |= (1 << 4);      // Enable GPIOC clock
    RCC_APB2ENR |= (1 << 2);      // Enable GPIOA clock
    
    GPIOC_CRH &= ~(0xF << 20);    // Clear CNF13/MODE13
    GPIOC_CRH |=  (0x1 << 20);    // Set MODE13 to output 10MHz, CNF13 to push-pull
    
    GPIOA_CRL &= ~(0xF << 4);     // Clear CNF1/MODE1 (PA1)
    GPIOA_CRL |=  (0x1 << 4);     // Set MODE1 to output 10MHz, CNF1 to push-pull
    
    GPIOA_CRL &= ~(0xF << 8);     // Clear CNF2/MODE2 (PA2)
    GPIOA_CRL |=  (0x1 << 8);     // Set MODE2 to output 10MHz, CNF2 to push-pull

    while (1) {
        GPIOC_ODR &= ~(1 << 13);  // Clear PC13 (turn on LED - active low)
        GPIOA_ODR |= (1 << 1);    // Set PA1 high
        GPIOA_ODR |= (1 << 2);    // Set PA2 high
        delay(1000000);           // 1 second delay
        GPIOC_ODR |= (1 << 13);   // Set PC13 (turn off LED - active low)
        GPIOA_ODR &= ~(1 << 1);   // Set PA1 low
        GPIOA_ODR &= ~(1 << 2);   // Set PA2 low
        delay(1000000);           // 1 second delay
    }
}
