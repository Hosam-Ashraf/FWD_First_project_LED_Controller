/*******  GPIO.c   */
#include "GPIO.h"

int GPIO_Init(St_GPIO* gpio_Str)
{
    if(gpio_Str != NULL)
    {
        switch(gpio_Str->gpio)
        {
            case GPIOA1:
                if(gpio_Str->direction == INPUT)
                {
                    GPIOA_DirectionReg &= ~(1 << gpio_Str->pin);
                }
                else 
                {
                    GPIOA_DirectionReg |= (1 << gpio_Str->pin);
                }
                break;
            case GPIOB2:
                break;
            case GPIOC3:
                break;
            default:
                break;
        }
        return true;
    }
    else
    {
        return false;
    }
}
