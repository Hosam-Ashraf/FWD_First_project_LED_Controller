#ifndef GPIO_H_
#define GPIO_H_

#include "TM4C123GH6PM.h"
#include "Utils.h"

typedef enum{
	PORT_A_CLK_EN=0,
	PORT_B_CLK_EN,
	PORT_C_CLK_EN,
	PORT_D_CLK_EN,
	PORT_E_CLK_EN,
	PORT_F_CLK_EN
}enGPIO_Clock_Gating_Control;

typedef enum{
	PIN0=0,
	PIN1,
	PIN2,
	PIN3,
	PIN4,
	PIN5,
	PIN6,
	PIN7
}enGPIO_PIN;
typedef enum
{
	INPUT=0,
	OUTPUT
}enDIR;


typedef enum
{
	LOW=0,
	HIGH,
	TOGGLE
}enSTATUS;

void GPIO_Init(enGPIO_Clock_Gating_Control port,enGPIO_PIN pin,enDIR direction);
void GPIO_SET_BIT(enGPIO_Clock_Gating_Control port,enGPIO_PIN pin,enSTATUS status);


#endif