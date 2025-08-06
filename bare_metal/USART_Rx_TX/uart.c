#ifndef UART_C_
#define UART_C_

#include "UART.h"
#include <math.h>
#include <stdint.h>

#define GPIOAEN  (1U<<0)
#define USART2EN (1U<<17)
#define CR1_TE   (1U<<3)
#define CR1_RE   (1U<<2)
#define CR1_UE   (1U<<13)
#define SR_TXE   (1U << 7)
#define SR_RXE   (1U << 5)

int __io_putchar(int ch)
{
	uart2_write(ch);
	return ch;
}

void USART2_INTI(void)
{
	RCC->AHB1ENR |= GPIOAEN;
	RCC->APB1ENR |= USART2EN;

	/**PortA 2 **/
	GPIOA->MODER |= (1U<<5);
	GPIOA->MODER &= ~(1U<<4);

	/*PortA 3**/
	GPIOA->MODER |=(1U<<7);
	GPIOA->MODER &= ~(1U<<6);




	/**Alternate function **/
	GPIOA->AFR[0] &= ~(1U<<11);
	GPIOA->AFR[0] |= (1U<<10);
	GPIOA->AFR[0] |= (1U<<9);
	GPIOA->AFR[0] |= (1U<<8);

	GPIOA->AFR[0] &= ~(1U<<15);
	GPIOA->AFR[0] |= (1U<<12);
	GPIOA->AFR[0] |= (1U<<13);
	GPIOA->AFR[0] |= (1U<<14);



	USART2->CR1 |= (CR1_TE |CR1_RE);
	USART2->CR2 = 0x0000;
	USART2->CR3 = 0x0000;
	USART2->BRR= 0x0683;
	USART2->CR1 |= CR1_UE;

}

void uart2_write(int ch)
{
	while(!(USART2->SR & SR_TXE)) {}

	USART2->DR =(ch & 0xFF);
}
char usart2_read(void)
{
	while(!(USART2->SR & SR_RXE)) {}
	return USART2->DR;
}
void delay(int x)
{
	for(int i=0;i<=x;i++);
}







#endif /* UART_C_ */
