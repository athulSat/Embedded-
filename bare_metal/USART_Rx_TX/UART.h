#ifndef UART_H_
#define UART_H_

#include <stdint.h>
#include "stm32f4xx.h"

void USART2_INTI(void);
void uart2_write(int ch);
void delay(int x);


#endif
