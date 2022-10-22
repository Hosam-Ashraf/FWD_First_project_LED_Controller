//#include "../MCAL/GPIO.h"
//#include "../MCAL/timer.h"
#include "GPIO.h"

#define ON_TIME 1
#define OFF_TIME 2
uint8 state=0;

void LED();
int main()
{
	
	GPIO_Init(PORT_F_CLK_EN,PIN3,OUTPUT);
	
	
	GPIO_SET_BIT(PORT_F_CLK_EN,PIN3,LOW);//OFF PF3 pin
	SYS_OVF_Interrupt_Init(LED);
	
	while (1)
	{
		//do nothing here
		
	}
}

void LED()
{
	switch(state)
	{
		case 0:
			if (seconds>=ON_TIME){state=1;}
			break;
		case 1:
			if (seconds>=OFF_TIME){seconds=0;state=0;}
			break;
	}
	seconds++;
	
}
