#include "stm32f4xx.h"

#define CCIEN (1U<<0)
#define GPIOAEN (1U<<0)
#define TIM3EN (1U<<1)
#define TIM3_CR1 (1U<<0)
#define CC1S ((1U<<0))

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

	TIM2->PSC =16000-1;

	TIM2->ARR =10000-1;

	TIM2->CCMR1 |= (1U<<5);
	TIM2->CCMR1 |= (1U<<4);
	TIM2->CCMR1 &= ~(1U<<6);


	TIM2->CCER |= CCIEN;

	TIM2->CNT = 0;

	TIM2->CR1 |= (1U<<0);
}

void tim3_pa6_input_capture(void)
{
	    RCC->AHB1ENR |=GPIOAEN;

		GPIOA->MODER |= (1U<<13);
		GPIOA->MODER &= ~(1U<<12);

		GPIOA->AFR[0] |= (1U<<25);
		GPIOA->AFR[0] &= ~(1U<<24);
		GPIOA->AFR[0] &= ~(1U<<26);
		GPIOA->AFR[0] &= ~(1U<<27);


		RCC->APB1ENR |= TIM3EN;

		TIM3->PSC = 16000-1;

		TIM3->CCMR1 |= CC1S;

	
		TIM3->CCER |= CCIEN;

		TIM3->CR1 |= TIM3_CR1;
}
