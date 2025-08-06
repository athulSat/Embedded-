#include "stm32f4xx.h"
#include <stdint.h>
#include "UART.h"
#include "systck.h"
#include "tim.h"
#include <stdio.h>



int main(void)
{

	tim2_pa5_output_capture();
}
