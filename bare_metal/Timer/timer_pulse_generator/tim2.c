#include "stm32f4xx.h"

// PB8-TIM2_ETR
//PC13 switch;

#define GPIOBEN (1U<<1)
#define TIM2EN (1U<<0)
#define SMS2 ((1U<<2)|(1U<<1)|(1U<<0))
#define TS  ((1U<<6)|(1U<<5)|(1U<<4))
#define ECE (1U<<14)

void pb8_ext_trig(void)
{
	/**Enable clock access**/
	RCC->AHB1ENR |= GPIOBEN;

	/**Set the Mode**/
	GPIOB->MODER |=(1U<<17) ;
	GPIOB->MODER &= ~(1U<<16);

	/**set portb8 in AF**/
	GPIOB->AFR[1] |=  (1U<<0);
	GPIOB->AFR[1] &= ~(1U<<1);
	GPIOB->AFR[1] &= ~(1U<<2);
	GPIOB->AFR[1] &= ~(1U<<3);

	/**clock Access to port timer 2**/

	RCC->APB1ENR |=TIM2EN;
	TIM2->SMCR |= (SMS2 | TS | ECE);
	TIM2->CNT=0;
	TIM2->CR1 |= (1U<<0);
}

