#include "Driver_GPIO.h"
#include "stm32f10x.h"

void MyGPIO_Init ( MyGPIO_Struct_TypeDef * GPIOStructPtr ) 
{
	RCC->APB2ENR |= RCC_APB2ENR_IOPAEN |RCC_APB2ENR_IOPBEN| RCC_APB2ENR_IOPCEN | RCC_APB2ENR_IOPDEN ;
	if(GPIOStructPtr->GPIO_Pin < 8){
	(GPIOStructPtr->GPIO)->CRL &=  ~(0xF<<(4*GPIOStructPtr->GPIO_Pin)); 
	(GPIOStructPtr->GPIO)->CRL |=  ((GPIOStructPtr->GPIO_Conf ) << (4*(GPIOStructPtr->GPIO_Pin))); 
	}
	
	else {
	(GPIOStructPtr->GPIO)->CRH &=  ~(0xF<<(4*GPIOStructPtr->GPIO_Pin)); 
	(GPIOStructPtr->GPIO)->CRH |=  ((GPIOStructPtr->GPIO_Conf ) << (4*(GPIOStructPtr->GPIO_Pin))); 
	}
	
}

int MyGPIO_Read ( GPIO_TypeDef * GPIO , char GPIO_Pin )
{
	int res = 0;
	MyGPIO_Struct_TypeDef _test;
	
	_test.GPIO_Pin = GPIO_Pin;
	_test.GPIO = GPIO;
	_test.GPIO_Conf = In_Floating;
	
	MyGPIO_Init ( &_test );
	
	
	if ((_test.GPIO->IDR & 1<<10) == 1<<10)
			res = 1;
	
	return res;
}

void MyGPIO_Set ( GPIO_TypeDef * GPIO , char GPIO_Pin )
{
	MyGPIO_Struct_TypeDef _test;
	
	_test.GPIO_Pin = GPIO_Pin;
	_test.GPIO = GPIO;
	_test.GPIO_Conf = Out_Ppull;
	
	MyGPIO_Init ( &_test );

	// (GPIOStructPtr->GPIO)->ODR &= (0x00 << GPIO_Pin) ;
	(_test.GPIO)->ODR |= (0x01 << GPIO_Pin) ;

}

// (1 || x) == 1
// (0 || x) == x
// (1 & x) == x
// (0 & x) == 0

void MyGPIO_Reset ( GPIO_TypeDef * GPIO , char GPIO_Pin ){
	MyGPIO_Struct_TypeDef _test;
	
	_test.GPIO_Pin = GPIO_Pin;
	_test.GPIO = GPIO;
	_test.GPIO_Conf = Out_Ppull;
	
	MyGPIO_Init ( &_test );

	(_test.GPIO)->ODR &= ~(0x01 << GPIO_Pin) ;
	// (GPIOStructPtr->GPIO)->ODR != (0x01 << GPIO_Pin) ;

}

void MyGPIO_Toggle ( GPIO_TypeDef * GPIO , char GPIO_Pin ){

	
	if( ((GPIO)->ODR & 1<<GPIO_Pin) == 1<<GPIO_Pin )
		{
		GPIO->ODR &= ~(0x01 << GPIO_Pin) ;
		}
	else 
	{
		GPIO->ODR |= (0x01 << GPIO_Pin) ;
	}

}

