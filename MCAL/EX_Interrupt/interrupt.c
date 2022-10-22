#include "interrupt.h"

static void (*EXINT0) (void)=NULLPTR;

void Interrupt_GPIOF0_Init(void(*InterrptFunctionPtr)(void))
{
	EXINT0 =InterrptFunctionPtr;
  SYSCTL->RCGCGPIO |= (1<<5);   /* Set bit5 of RCGCGPIO to enable clock to PORTF*/
    
	 /* PORTF0 has special function, need to unlock to modify */
    GPIOF->LOCK = 0x4C4F434B;   /* unlock commit register */
    GPIOF->CR = 0x01;           /* make PORTF0 configurable */
    GPIOF->LOCK = 0;            /* lock commit register */
		
		CLEAR_BIT(GPIOF->DIR,0);/* Set  PF0 as a digital input pin */
		
	
		GPIOF->DEN |= (1<<0);             /* make PORTF0 digital pins */
    GPIOF->PUR |= (1<<0);             /* enable pull up for PORTF0 */
    
	/* configure PORTF0 for falling edge trigger interrupt */
    GPIOF->IS  &= ~(1<<0);        /* make bit 0 edge sensitive */
    GPIOF->IBE &= ~(1<<0);         /* trigger is controlled by IEV */
    GPIOF->IEV &= ~(1<<0);        /* falling edge trigger */
    GPIOF->ICR |= (1<<0);          /* clear any prior interrupt */
    GPIOF->IM  |= (1<<0);          /* unmask interrupt */
	
	/* enable interrupt in NVIC and set priority to 3 */
    NVIC->IP[30] = 3 << 5;     /* set interrupt priority to 3 */
    NVIC->ISER[0] |= (1<<30);  /* enable IRQ30 (D30 of ISER[0]) */
	
}

void GPIOF_Handler(void)
{	
 
  if (GPIOF->MIS & 0x01) /* check if interrupt causes by PF0/SW1 */
    {   
     EXINT0();
     GPIOF->ICR |= 0x01; /* clear the interrupt flag */
    }
}