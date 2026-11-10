#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include <gd32f105.h>

int main(void) {
    printf("Hello! I`m was born!\n");

    SysTick_Config(SystemCoreClock/10);

    return EXIT_SUCCESS;
}

void SysTick_Handler(void) {
    __NOP();
}