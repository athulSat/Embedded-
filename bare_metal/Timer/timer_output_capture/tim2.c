#include "stm32f4xx.h"

#define OC_Toggle ((1U<<4) | (1U<<5))
#define CCIEN (1U<<0)
#define GPIOAEN (1U<<0);

void tim2_init(void)
{
	TIM2->PSC =1600-1;
	TIM2->ARR =1000-1;
	TIM2->CNT=0;
	TIM2->CR1 =(1U<<0);
}
void tim2_pa5_output_capture(void)
{
	RCC->AHB1ENR |= GPIOAEN;

	GPIOA->MODER |=(1U<<11);
	GPIOA->MODER &= ~(1U<<10);

	GPIOA->AFR[0] |= (1U<<20);
	GPIOA->AFR[0] &= ~(1U<<21);
	GPIOA->AFR[0] &= ~(1U<<22);
	GPIOA->AFR[0] &= ~(1U<<23);

	RCC->APB1ENR |=(1U<<0);

	TIM2->PSC =1600-1;

	TIM2->ARR =1000-1;

	TIM2->CCMR1 |=OC_Toggle;

	TIM2->CCER |= CCIEN;

	TIM2->CNT=0;

	TIM2->CR1 =(1U<<0);
}
