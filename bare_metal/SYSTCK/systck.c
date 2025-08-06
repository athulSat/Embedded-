#include"stm32f4xx.h"
#include "systck.h"

#define SYSTCK_LOAD_VALUE  16000-1
#define EN (1U<<0)
#define CTRl_CLK_SOURCE (1U<<2)
#define COUNTFLAG (1U<<16)

void systckdelayms(int n)
{
	SysTick->LOAD =SYSTCK_LOAD_VALUE;

	SysTick->VAL=0;

	SysTick->CTRL = (EN | CTRl_CLK_SOURCE);

    for(int i=0;i<n;i++)
    {
    	while(!(SysTick->CTRL & COUNTFLAG)) {}
    }
	SysTick->CTRL = 0;

}
