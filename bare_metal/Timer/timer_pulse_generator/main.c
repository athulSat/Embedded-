#include "stm32f4xx.h"
#include <stdint.h>
#include "UART.h"
#include "systck.h"
#include "tim.h"
#include <stdio.h>

//PC13
#define GPIOAEN (1U<<0)

#define PIN5 (1U<<5)

int main(void)
{
	RCC->AHB1ENR |=GPIOAEN;
	GPIOA->MODER |=(1U<<10);
	GPIOA->MODER &= ~(1U<<11);
	pb8_ext_trig();
//LSb is used to toggle the led
	while(1)
	{
		if(TIM2->CNT & 1) GPIOA->ODR |= PIN5;
		else GPIOA->ODR &= ~(PIN5);

	}





}
