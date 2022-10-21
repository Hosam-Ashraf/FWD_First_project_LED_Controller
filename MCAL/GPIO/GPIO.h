

#ifndef GPIO_H
#define GPIO_H

#include "Utils.h"
#include "STD_Types.h"

typedef struct
{
	volatile uint32 CRL;       /*!< GPIO port mode CONTROL LOW register,     Address offset: 0x00      */
  volatile uint32 CRH;       /*!< GPIO port mode CONTROL HIGH register,    Address offset: 0x04      */
	volatile uint32 IDR;       /*!< GPIO port input data register,           Address offset: 0x08      */
	volatile uint32 ODR;       /*!< GPIO port output data register,          Address offset: 0x0C      */
	volatile uint16 BSRR;      /*!< GPIO port bit set/reset low register,    Address offset: 0x10      */
	volatile uint16 BRR;       /*!< GPIO port bit set/reset high register,   Address offset: 0x14      */
	volatile uint32 LCKR;      /*!< GPIO port configuration lock register,   Address offset: 0x18      */
}GPIO_TypeDef;

/* Peripheral base address in the alias region */
#define PERIPH_BASE           ((uint32)0x40000000)

/* GPIO Base */
#define GPIOE_BASE          (PERIPH_BASE + 0x11800)
#define GPIOD_BASE          (PERIPH_BASE + 0x11400)
#define GPIOC_BASE          (PERIPH_BASE + 0x11000)
#define GPIOB_BASE          (PERIPH_BASE + 0x10C00)
#define GPIOA_BASE          (PERIPH_BASE + 0x10800)

#define GPIOA               ((GPIO_TypeDef *) GPIOA_BASE)
#define GPIOB               ((GPIO_TypeDef *) GPIOB_BASE)
#define GPIOC               ((GPIO_TypeDef *) GPIOC_BASE)
#define GPIOD               ((GPIO_TypeDef *) GPIOD_BASE)
#define GPIOE               ((GPIO_TypeDef *) GPIOE_BASE)

#endif
