/**
 ******************************************************************************
 * @file           : main.c
 * @author         : Auto-generated by STM32CubeIDE
 * @brief          : Main program body
 ******************************************************************************
 * @attention
 *
 * <h2><center>&copy; Copyright (c) 2024 STMicroelectronics.
 * All rights reserved.</center></h2>
 *
 * This software component is licensed by ST under BSD 3-Clause license,
 * the "License"; You may not use this file except in compliance with the
 * License. You may obtain a copy of the License at:
 *                        opensource.org/licenses/BSD-3-Clause
 *
 ******************************************************************************
 */

#include "Platform_Types.h"

//clock
#define RCC_BASE		0x40021000
#define RCC_APB2ENR		(*(volatile uint32_t *)(RCC_BASE + 0x18))

//PORTA
#define GPIOA_BASE		0x40010800
#define GPIOA_CRL		(*(volatile uint32_t *)(GPIOA_BASE + 0x00))
#define GPIOA_CRH		(*(volatile uint32_t *)(GPIOA_BASE + 0x04))
#define GPIOA_IDR		(*(volatile uint32_t *)(GPIOA_BASE + 0x08))
#define GPIOA_ODR		(*(volatile uint32_t *)(GPIOA_BASE + 0x0C))

//PORTB
#define GPIOB_BASE		0x40010C00
#define GPIOB_CRL		(*(volatile uint32_t *)(GPIOB_BASE + 0x00))
#define GPIOB_CRH		(*(volatile uint32_t *)(GPIOB_BASE + 0x04))
#define GPIOB_IDR		(*(volatile uint32_t *)(GPIOB_BASE + 0x08))
#define GPIOB_ODR		(*(volatile uint32_t *)(GPIOB_BASE + 0x0C))


void Clock_Init(void){
	//Enable clock for port A and port B
	RCC_APB2ENR |= 0b11<<2;
}

void GPIO_Init(void){
	//Set Pin B1 to output push-pull
	GPIOB_CRL = 0;
	GPIOB_CRL |= 1<<4;
	//Set Pin B13 to output push-pull
	GPIOB_CRH =0;
	GPIOB_CRH |= 1<<20;
}

int main(void)
{
    Clock_Init();
    GPIO_Init();
    while(1){
    	if((GPIOA_IDR & (1<<1)) == 0){
    		GPIOB_ODR ^= 1<<1;
    		while((GPIOA_IDR & (1<<1)) == 0);
    	}
    	if(((GPIOA_IDR & (1<<13)) >>13) == 1){
    		GPIOB_ODR ^= 1<<13;
    	}
    	for(int i=0;i<255;i++);
    }
}
