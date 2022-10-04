#include "Driver_GPIO.h"
#include "stm32f10x.h"

void MyGPIO_Init ( MyGPIO_Struct_TypeDef * GPIOStructPtr ) 
{
	
	(GPIOStructPtr->GPIO)->CRL &=  ~(0xF<<(4*GPIOStructPtr->GPIO_Pin)); 
	(GPIOStructPtr->GPIO)->CRL |=  ((GPIOStructPtr->GPIO_Conf ) << (4*(GPIOStructPtr->GPIO_Pin))); 
	
}

int MyGPIO_Read ( GPIO_TypeDef * GPIO , char GPIO_Pin )
{
	
	MyGPIO_Struct_TypeDef _test;
	
	_test.GPIO_Pin = GPIO_Pin;
	_test.GPIO = GPIO;
	_test.GPIO_Conf = In_Floating;
	
	MyGPIO_Init ( &_test );
	
	if ((GPIO->IDR & 1<<10) == 1<<10)
		{
			GPIOA->ODR |= (0x01 << 5) ;						//LED ON
			GPIOB->ODR &= (0x00 << 5) ;						//LED ON
		}
		
		else 
		{
			GPIOA->ODR &= (0x00 << 5) ;						//LED OFF
			GPIOB->ODR |= (0x01 << 5) ;						//LED OFF
		}
	
	int res = 0;
	
	
	return res;
	
}
