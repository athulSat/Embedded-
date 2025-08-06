#include "stm32f4xx.h"
#include <stdint.h>
#include "UART.h"
#include <stdio.h>
#include "adc.h"

#define GPIOAEN (1U<<0)
#define PIN5 (1U<<5)
#define LED PIN5

uint32_t sensorvalue;


int main(void)
{
	RCC->AHB1ENR |= GPIOAEN;



	USART2_TX();
	adc_inti();
	adc_SOC();

	while(1)
	{

		sensorvalue=adc_read();
		printf("Sensor value is %d \n \r",(int)sensorvalue);
	}



}


