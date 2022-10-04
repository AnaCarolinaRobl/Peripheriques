#include "stm32f10x.h"
#include "Driver_GPIO.h"
/*
– configure le poussoir en floating input;
– configure la LED en output push pull;
– fasse en sorte que lorsque le bouton est appuyé, la LED s’allume.
*/

void Config(void);

int main (void)
{
	MyGPIO_Struct_TypeDef test;
	Config();
	
	test.GPIO_Pin = 2;
	test.GPIO = GPIOA;
	test.GPIO_Conf = Out_Ppull;
	
	MyGPIO_Init ( &test );
	
	do
	{

			
	}while(1);
}

void Config(void)
{
	RCC->APB2ENR |= (0x01 << 2) | (0x01 << 3) | (0x01 << 4);
	
}
