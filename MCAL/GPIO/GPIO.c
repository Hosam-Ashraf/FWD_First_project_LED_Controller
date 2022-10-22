#include "GPIO.h"

void GPIO_Init(enGPIO_Clock_Gating_Control port,enGPIO_PIN pin,enDIR direction)
{
	switch(port)
	{
		case PORT_A_CLK_EN:
			SYSCTL->RCGCGPIO |= 0x01;
			switch(direction)
					{
						case INPUT:
						  CLEAR_BIT(GPIOA->DIR,pin);// make specified pin input
							break;
						case OUTPUT:
							SET_BIT(GPIOA->DIR,pin);// make specified pin output
							break;
					}
			SET_BIT(GPIOA->DEN,pin);// Enable pin as a digital pin
			break;
		case PORT_B_CLK_EN:
			SYSCTL->RCGCGPIO |= 0x02;
			switch(direction)
					{
						case INPUT:
						  CLEAR_BIT(GPIOB->DIR,pin);// make specified pin input
							break;
						case OUTPUT:
							SET_BIT(GPIOB->DIR,pin);// make specified pin output
							break;
					}
			SET_BIT(GPIOB->DEN,pin);// Enable pin as a digital pin
			break;
		case PORT_C_CLK_EN:
			SYSCTL->RCGCGPIO |= 0x04;
			switch(direction)
					{
						case INPUT:
						  CLEAR_BIT(GPIOC->DIR,pin);// make specified pin input
							break;
						case OUTPUT:
							SET_BIT(GPIOC->DIR,pin);// make specified pin output
							break;
					}
			SET_BIT(GPIOC->DEN,pin);// Enable pin as a digital pin
			break;
		case PORT_D_CLK_EN:
			SYSCTL->RCGCGPIO |= 0x08;
			switch(direction)
					{
						case INPUT:
						  CLEAR_BIT(GPIOD->DIR,pin);// make specified pin input
							break;
						case OUTPUT:
							SET_BIT(GPIOD->DIR,pin);// make specified pin output
							break;
					}
			SET_BIT(GPIOD->DEN,pin);// Enable pin as a digital pin
			break;
		case PORT_E_CLK_EN:
			SYSCTL->RCGCGPIO |= 0x10;
			switch(direction)
					{
						case INPUT:
						  CLEAR_BIT(GPIOE->DIR,pin);// make specified pin input
							break;
						case OUTPUT:
							SET_BIT(GPIOE->DIR,pin);// make specified pin output
							break;
					}
			SET_BIT(GPIOE->DEN,pin);// Enable pin as a digital pin
			break;
		case PORT_F_CLK_EN:
			SYSCTL->RCGCGPIO |= 0x20;
			switch(direction)
					{
						case INPUT:
						  CLEAR_BIT(GPIOF->DIR,pin);// make specified pin input
							break;
						case OUTPUT:
							SET_BIT(GPIOF->DIR,pin);// make specified pin output
							break;
					}
					SET_BIT(GPIOF->DEN,pin);// Enable pin as a digital pin
			break;
	}
	
}



void GPIO_SET_BIT(enGPIO_Clock_Gating_Control port,enGPIO_PIN pin,enSTATUS status)
{
	switch(port)
	{
		case PORT_A_CLK_EN:
			
			switch(status)
					{
						case LOW:
						  CLEAR_BIT(GPIOA->DATA,pin);// make specified pin LOW
							break;
						case HIGH:
							SET_BIT(GPIOA->DATA,pin);// make specified pin HIGH
							break;
						case TOGGLE:
							TOG_BIT(GPIOA->DATA,pin);// make specified pin toggle
							break;
					}
			break;
		case PORT_B_CLK_EN:
			switch(status)
					{
						case LOW:
						  CLEAR_BIT(GPIOB->DATA,pin);// make specified pin LOW
							break;
						case HIGH:
							SET_BIT(GPIOB->DATA,pin);// make specified pin HIGH
							break;
						case TOGGLE:
							TOG_BIT(GPIOB->DATA,pin);// make specified pin toggle
							break;
					}
			break;
					
		case PORT_C_CLK_EN:
			switch(status)
					{
						case LOW:
						  CLEAR_BIT(GPIOC->DATA,pin);// make specified pin LOW
							break;
						case HIGH:
							SET_BIT(GPIOC->DATA,pin);// make specified pin HIGH
							break;
						case TOGGLE:
							TOG_BIT(GPIOC->DATA,pin);// make specified pin toggle
							break;
					}
			break;
					
		case PORT_D_CLK_EN:
			switch(status)
					{
						case LOW:
						  CLEAR_BIT(GPIOD->DATA,pin);// make specified pin LOW
							break;
						case HIGH:
							SET_BIT(GPIOD->DATA,pin);// make specified pin HIGH
							break;
					}
			break;
					
		case PORT_E_CLK_EN:
			switch(status)
					{
						case LOW:
						  CLEAR_BIT(GPIOE->DATA,pin);// make specified pin LOW
							break;
						case HIGH:
							SET_BIT(GPIOE->DATA,pin);// make specified pin HIGH
							break;
						case TOGGLE:
							TOG_BIT(GPIOE->DATA,pin);// make specified pin toggle
							break;
					}
			break;
					
					
		case PORT_F_CLK_EN:
			switch(status)
					{
						case LOW:
						  CLEAR_BIT(GPIOF->DATA,pin);// make specified pin LOW
							break;
						case HIGH:
							SET_BIT(GPIOF->DATA,pin);// make specified pin HIGH
							break;
						case TOGGLE:
							TOG_BIT(GPIOF->DATA,pin);// make specified pin toggle
							break;
					}
			break;
	}
}
