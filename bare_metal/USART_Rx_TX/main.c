#include "stm32f4xx.h"
#include <stdint.h>
#include "UART.h"



int main(void)
{
	USART2_INTI();

	while(1)
	{
		uart2_write('E');
		delay(10);
		uart2_write('V');
		delay(10);
		uart2_write('A');
		delay(10);

	}

}
