#include "timer.h"

uint32 seconds=0;
uint8 state=0;
static void (*TIMER0_OVF_Func_Ptr) (void)=NULLPTR;
void SYS_OVF_Interrupt_Init(void(*TimerInterrptFunctionPtr)(void))
{
	TIMER0_OVF_Func_Ptr=TimerInterrptFunctionPtr;
	SysTick->LOAD = 15999999; // one second delay relaod value
	SysTick->CTRL = 7 ; // enable counter, interrupt and select system bus clock 
	SysTick->VAL  = 0; //initialize current value register 	
}
// this routine will execute after every one second

void SysTick_Handler(void)
{
	seconds++;
	TIMER0_OVF_Func_Ptr();
}
