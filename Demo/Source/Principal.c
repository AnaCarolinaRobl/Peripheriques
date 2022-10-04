#include "stm32f10x.h"

/*
– configure le poussoir en floating input;
– configure la LED en output push pull;
– fasse en sorte que lorsque le bouton est appuyé, la LED s’allume.
*/

void Config(void);

int main (void)
{
	Config();
	do
	{

		if ((GPIOA->IDR & 1<<10) == 1<<10)				//READING BUTTON
		{
			GPIOA->ODR |= (0x01 << 5) ;						//LED ON
			GPIOB->ODR &= (0x00 << 5) ;						//LED ON
		}
		
		else 
		{
			GPIOA->ODR &= (0x00 << 5) ;						//LED OFF
			GPIOB->ODR |= (0x01 << 5) ;						//LED OFF
		}
			
	}while(1);
}

void Config(void)
{
	RCC->APB2ENR |= (0x01 << 2) | (0x01 << 3) | (0x01 << 4);
	
	//GPIOA pin 10 => INPUT FLOATING 0100
	GPIOA->CRH &= (0x00 << 8) & (0x00 << 9) & (0x00 << 11); //força o 0
	GPIOA->CRH |= (0x01 << 10) ; //força o 1
			
	//GPIOA pin 5 => OUTPUT PUSHPULL 0001
	GPIOA->CRL &= (0x00 << 21) & (0x00 << 22) & (0x00 << 23); //força o 0
	GPIOA->CRL |= (0x01 << 20) ; //força o 1
	
	//GPIOB pin 5 => OUTPUT OPEN DRAIN 0101
	//GPIOB->CRL &=  ~(0xF<<(4*5)); 
	//GPIOB->CRL |= 5<<(4*5) ; 
	GPIOB->CRL &= ~(0x01 << 21) & ~(0x01 << 23); //força o 0
	GPIOB->CRL |= (0x01 << 20) | (0x01 << 22); //força o 1
}
