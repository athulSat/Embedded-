#include"stm32f4xx.h"
#include"adc.h"
#include <stdint.h>
//ADC123_IN1 PA1
#define ADC1EN (1U<<8)
#define GPIOAEN (1U<<0)
#define ADC1_CH1  1
#define ADC1_SEQ_LEN 0x00
#define ADCON (1U<<0)
#define SWSTART (1U<<30)
#define SR_EOC (1U<<1)

void adc_inti(void)
{
	/*CLOCK ACCESS*/
	RCC->AHB1ENR |=GPIOAEN;
	RCC->APB2ENR |=ADC1EN;

	/*ANALOG MODE*/
	GPIOA->MODER |=(1U<<3);
	GPIOA->MODER |= (1U<<2);

	/*channel*/
	ADC1->CR1 &= ~(1U<<4);
	ADC1->CR1 &= ~(1U<<3);
	ADC1->CR1 &= ~(1U<<2);
	ADC1->CR1 |= (1U<<1);
	ADC1->CR1 &= ~(1U<<0);

	/*Resolution*/
	ADC1->CR1 &= ~(1U<<24);
	ADC1->CR1 |= (1U<<25);

	/*channel 1*/
	ADC1->SQR3 |=ADC1_CH1;

	ADC1->SQR1 |= ADC1_SEQ_LEN;

	ADC1->CR2 |= ADCON;
}
void adc_SOC(void)
{
	ADC1->CR2 |=SWSTART;

}
uint32_t adc_read(void)
{
	while(!(ADC1->SR & SR_EOC)){}
	return ADC1->DR;
}
