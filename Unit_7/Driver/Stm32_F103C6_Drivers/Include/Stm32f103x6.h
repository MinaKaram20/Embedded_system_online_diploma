/*
 * Stm32f103x6.h
 *
 *  Created on: Sep 24, 2024
 *      Author: minak
 */

#ifndef INCLUDE_STM32F103X6_H_
#define INCLUDE_STM32F103X6_H_

//-----------------------------
//Includes
//-----------------------------

#include "stdlib.h"
#include <stdint.h>

//=========================================

//-----------------------------
//Base addresses for Memories
//-----------------------------
#define FLASH_MEMORY_BASE							0x08000000UL
#define SYSTEM_MEMORY_BASE							0x1FFFF000UL
#define SRAM_MEMORY_BASE							0x20000000UL


#define PERIPHERALS_MEMORY_BASE						0x40000000UL


#define Cortex_M3_INTERNAL_PERIPHERALS_MEMORY_BASE	0xE0000000UL

#define NVIC_BASE									0xE000E100UL

#define NVIC_ISER0									*(volatile uint32_t *)(NVIC_BASE + 0x000)
#define NVIC_ISER1									*(volatile uint32_t *)(NVIC_BASE + 0x004)
#define NVIC_ISER2									*(volatile uint32_t *)(NVIC_BASE + 0x008)

#define NVIC_ICER0									*(volatile uint32_t *)(NVIC_BASE + 0x080)
#define NVIC_ICER1									*(volatile uint32_t *)(NVIC_BASE + 0x084)
#define NVIC_ICER2									*(volatile uint32_t *)(NVIC_BASE + 0x088)



//======================================================================

//-----------------------------
//Base addresses for AHB Peripherals
//-----------------------------

//RCC
#define RCC_BASE	 0x40021000UL

//-----------------------------
//Base addresses for APB2 Peripherals
//-----------------------------


//GPIO
//NOTE: GPIO Port A,B are Fully included in LQFP48 Package
#define GPIOA_BASE	0x40010800UL
#define GPIOB_BASE	0x40010C00UL

//NOTE: GPIO Port C,D are Partially included in LQFP48 Package
#define GPIOC_BASE	0x40011000UL
#define GPIOD_BASE	0x40011400UL

//NOTE: GPIO Port E is Not included in LQFP48 Package
#define GPIOE_BASE	0x40011800UL


//EXTI
#define EXTI_BASE	0x40010400UL


//AFIO
#define AFIO_BASE	0x40010000UL

//=======================================================

//-*-*-*-*-*-*-*-*-*-*-*-*-*-*-
//Peripheral register : RCC
//-*-*-*-*-*-*-*-*-*-*-*-*-*-*-

typedef struct{
	volatile uint32_t CR;
	volatile uint32_t CFGR;
	volatile uint32_t CIR;
	volatile uint32_t APB2RSTR;
	volatile uint32_t APB1RSTR;
	volatile uint32_t AHBENR;
	volatile uint32_t APB2ENR;
	volatile uint32_t APB1ENR;
	volatile uint32_t BDCR;
}RCC_TypeDef;

//-*-*-*-*-*-*-*-*-*-*-*-*-*-*-
//Peripheral register : GPIO
//-*-*-*-*-*-*-*-*-*-*-*-*-*-*-

typedef struct{
	volatile uint32_t CRL;
	volatile uint32_t CRH;
	volatile uint32_t IDR;
	volatile uint32_t ODR;
	volatile uint32_t BSRR;
	volatile uint32_t BRR;
	volatile uint32_t LCKR;
}GPIO_TypeDef;

//-*-*-*-*-*-*-*-*-*-*-*-*-*-*-
//Peripheral register : EXTI
//-*-*-*-*-*-*-*-*-*-*-*-*-*-*-

typedef struct{
	volatile uint32_t IMR;
	volatile uint32_t EMR;
	volatile uint32_t RTSR;
	volatile uint32_t FTSR;
	volatile uint32_t SWIER;
	volatile uint32_t PR;
}EXTI_TypeDef;

//-*-*-*-*-*-*-*-*-*-*-*-*-*-*-
//Peripheral register : AFIO
//-*-*-*-*-*-*-*-*-*-*-*-*-*-*-

typedef struct{
	volatile uint32_t EVCR;
	volatile uint32_t MAPR;
	volatile uint32_t EXTICR[4];
	volatile uint32_t RESERVED_1;
	volatile uint32_t MAPR2;
}AFIO_TypeDef;

//==========================================

//-*-*-*-*-*-*-*-*-*-*-*-*-*-
//Peripheral Instants: GPIO
//-*-*-*-*-*-*-*-*-*-*-*-*-*-

#define GPIOA	((GPIO_TypeDef *)(GPIOA_BASE))
#define GPIOB	((GPIO_TypeDef *)(GPIOB_BASE))
#define GPIOC	((GPIO_TypeDef *)(GPIOC_BASE))
#define GPIOD	((GPIO_TypeDef *)(GPIOD_BASE))
#define GPIOE	((GPIO_TypeDef *)(GPIOE_BASE))

//-*-*-*-*-*-*-*-*-*-*-*-*-*-
//Peripheral Instants: RCC
//-*-*-*-*-*-*-*-*-*-*-*-*-*-

#define RCC	((RCC_TypeDef *)(RCC_BASE))

//-*-*-*-*-*-*-*-*-*-*-*-*-*-
//Peripheral Instants: EXTI
//-*-*-*-*-*-*-*-*-*-*-*-*-*-

#define EXTI	((EXTI_TypeDef *)(EXTI_BASE))

//-*-*-*-*-*-*-*-*-*-*-*-*-*-
//Peripheral Instants: AFIO
//-*-*-*-*-*-*-*-*-*-*-*-*-*-

#define AFIO	((AFIO_TypeDef *)(AFIO_BASE))

//==============================================

//-*-*-*-*-*-*-*-*-*-*-*-
//clock enable Macros:
//-*-*-*-*-*-*-*-*-*-*-*-

#define RCC_GPIOA_CLK_EN()		(RCC->APB2ENR |= 1<<2)
#define RCC_GPIOB_CLK_EN()		(RCC->APB2ENR |= 1<<3)
#define RCC_GPIOC_CLK_EN()		(RCC->APB2ENR |= 1<<4)
#define RCC_GPIOD_CLK_EN()		(RCC->APB2ENR |= 1<<5)
#define RCC_GPIOE_CLK_EN()		(RCC->APB2ENR |= 1<<6)
#define RCC_AFIO_CLK_EN()		(RCC->APB2ENR |= 1<<0)

//==========================================================

#define NVIC_IRQ6_EXTI0_Enable			(NVIC_ISER0 |= 1<<6)
#define NVIC_IRQ7_EXTI1_Enable			(NVIC_ISER0 |= 1<<7)
#define NVIC_IRQ8_EXTI2_Enable			(NVIC_ISER0 |= 1<<8)
#define NVIC_IRQ9_EXTI3_Enable			(NVIC_ISER0 |= 1<<9)
#define NVIC_IRQ10_EXTI4_Enable			(NVIC_ISER0 |= 1<<10)
#define NVIC_IRQ23_EXTI5_9_Enable		(NVIC_ISER0 |= 1<<23)
#define NVIC_IRQ40_EXTI10_15_Enable		(NVIC_ISER1 |= 1<<8)

#define NVIC_IRQ6_EXTI0_Disable			(NVIC_ICER0 &= ~(1<<6))
#define NVIC_IRQ7_EXTI1_Disable			(NVIC_ICER0 &= ~(1<<7))
#define NVIC_IRQ8_EXTI2_Disable			(NVIC_ICER0 &= ~(1<<8))
#define NVIC_IRQ9_EXTI3_Disable			(NVIC_ICER0 &= ~(1<<9))
#define NVIC_IRQ10_EXTI4_Disable		(NVIC_ICER0 &= ~(1<<10))
#define NVIC_IRQ23_EXTI5_9_Disable		(NVIC_ICER0 &= ~(1<<23))
#define NVIC_IRQ40_EXTI10_15_Disable	(NVIC_ICER1 &= ~(1<<8))

//==============================================================

#endif /* INCLUDE_STM32F103X6_H_ */
