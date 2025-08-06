#include "stm32f4xx.h"
#include <stdint.h>
#include "UART.h"
#include "systck.h"
#define GPIOAEN (1U<<0)
#define PIN5 (1U<<5)
#define LED PIN5

char key;

int main(void)
{
	RCC->AHB1ENR |= GPIOAEN;

	GPIOA->MODER |= (1U<<10);
	GPIOA->MODER &= ~(1U<<11);

	USART2_INTI();

	while(1)
	{
		printf("A second has passed \n\r");
		GPIOA->ODR ^= LED;
		systckdelayms(1000);


	}

}
