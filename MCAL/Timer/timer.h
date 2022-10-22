#ifndef TIMER_H_
#define TIMER_H_

#include "TM4C123GH6PM.h"
#include "STD_Types.h"


void SYS_OVF_Interrupt_Init(void(*TimerInterrptFunctionPtr)(void));
extern uint32 seconds;
extern uint8 state;




#endif