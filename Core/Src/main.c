#include "stm32f103xb.h"


	uint32_t Timingdelay;
	void delay1ms(void)
	{
	 SysTick->LOAD = 8000000-1;
	 SysTick->CTRL = 0x5; /* Enable the timer and choose sysclk as the clock
	source */
	 while((SysTick->CTRL & 0x10000) == 0) /* wait until the COUNT flag is set */
	 { }
	 SysTick->CTRL = 0; /* Stop the timer (Enable = 0) */
	}



	int main()
	{
			RCC->APB2ENR |= 0xFC;
			GPIOC->CRH = (1<<20)|(1<<21);
			while(1)
			{
				GPIOC->ODR ^= (1<<13); //toggle PC13
				delay1ms();
			}
	}
