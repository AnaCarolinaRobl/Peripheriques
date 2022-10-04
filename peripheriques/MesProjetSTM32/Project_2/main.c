#include "stm32f10x.h"
 
int compteur ;
int main(void)
{
	
    RCC->APB2ENR |= 0x04; /// port a
	  // GPIOA->CRL   = 0x00003000;  // led 

    RCC->APB1ENR |=0x1;// timer2 
    TIM2->ARR = 0xffff; 
    TIM2->PSC = 0x36;  // 10hz 
		TIM2->CR1 |=1 ;
	
	// configurer la diode
	
		while(1)
    {
			//compteur = TIM2->CNT ;
			if ((TIM2->SR & 1<<0) == 1)
			{
				// toggle DIODE
				TIM2->SR &= ~(1<<0);
			}
        
    }
}
