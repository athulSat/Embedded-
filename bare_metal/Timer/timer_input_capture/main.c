#include "stm32f4xx.h"
#include <stdint.h>
#include "UART.h"
#include "systck.h"
#include "tim.h"
#include <stdio.h>

int timestamp =0;

int main(void)
{

	tim2_pa5_output_capture();
	tim3_pa6_input_capture();
	while(1)
	{
		while(!(TIM3->SR & SR_CC1IF)){}



		timestamp =TIM3->CCR1;
	}
}
