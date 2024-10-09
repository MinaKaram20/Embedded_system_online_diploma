/*
 * Stm32_F103C6_EXTI_Driver.c
 *
 *  Created on: 30 Sep 2024
 *      Author: minak
 */

//-----------------------------
//Includes
//-----------------------------

#include "Stm32_F103C6_EXTI_Driver.h"

//========================================================================

#define AFIO_GPIO_EXTI_Mapping(x)	((x==GPIOA)? 0 : (x==GPIOB)? 1 :	(x==GPIOC)? 2 :	(x==GPIOD)? 3 : 0)

//==========================================================

void (*GPtr_IRQ_CallBack[15])(void);

//==========================================================

void NVIC_Enable(EXTI_PIN_Config_t * PIN_Conf)
{
	switch(PIN_Conf->EXTI_PORT_PIN.EXTI_INPUT_LINE_NUM)
	{
	case(0) :
			NVIC_IRQ6_EXTI0_Enable;
	break;
	case(1) :
			NVIC_IRQ7_EXTI1_Enable;
	break;
	case(2) :
			NVIC_IRQ8_EXTI2_Enable;
	break;
	case(3) :
			NVIC_IRQ9_EXTI3_Enable;
	break;
	case(4) :
			NVIC_IRQ10_EXTI4_Enable;
	break;
	case(5) :
	case(6) :
	case(7) :
	case(8) :
	case(9) :
			NVIC_IRQ23_EXTI5_9_Enable;
	break;
	case(10) :
	case(11) :
	case(12) :
	case(13) :
	case(14) :
	case(15) :
			NVIC_IRQ40_EXTI10_15_Enable;
	break;
	}
}

void NVIC_Disable(EXTI_PIN_Config_t * PIN_Conf)
{
	switch(PIN_Conf->EXTI_PORT_PIN.EXTI_INPUT_LINE_NUM)
	{
	case(0) :
			NVIC_IRQ6_EXTI0_Disable;
	break;
	case(1) :
			NVIC_IRQ7_EXTI1_Disable;
	break;
	case(2) :
			NVIC_IRQ8_EXTI2_Disable;
	break;
	case(3) :
			NVIC_IRQ9_EXTI3_Disable;
	break;
	case(4) :
			NVIC_IRQ10_EXTI4_Disable;
	break;
	case(5) :
	case(6) :
	case(7) :
	case(8) :
	case(9) :
			NVIC_IRQ23_EXTI5_9_Disable;
	break;
	case(10) :
	case(11) :
	case(12) :
	case(13) :
	case(14) :
	case(15) :
			NVIC_IRQ40_EXTI10_15_Disable;
	break;
	}
}

void Update_EXTI(EXTI_PIN_Config_t * PIN_Conf)
{
	//1-AFIO init
	GPIO_PINConfig_t GPIO_conf;
	GPIO_conf.GPIO_PIN_Number = PIN_Conf->EXTI_PORT_PIN.PIN_NUM;
	GPIO_conf.GPIO_MODE = GPIO_MODE_INPUT_FLO;
	MCAL_GPIO_Init(PIN_Conf->EXTI_PORT_PIN.GPIOx, &GPIO_conf);

	//2-AFIO Position and index
	uint8_t AFIO_EXTI_index = PIN_Conf->EXTI_PORT_PIN.EXTI_INPUT_LINE_NUM/4;
	uint8_t AFIO_EXTI_Position = (PIN_Conf->EXTI_PORT_PIN.EXTI_INPUT_LINE_NUM % 4) * 4;

	//3-Clear 4 bits of AFIO_EXTI
	AFIO->EXTICR[AFIO_EXTI_index] &= ~(0xF << AFIO_EXTI_Position) ;
	AFIO->EXTICR[AFIO_EXTI_index] |= AFIO_GPIO_EXTI_Mapping(PIN_Conf->EXTI_PORT_PIN.GPIOx) << AFIO_EXTI_Position;

	//4-set the trigger action
	if(PIN_Conf->EXTI_Trigger == EXTI_Trigger_RISING)
	{
		EXTI->RTSR |= 1 << PIN_Conf->EXTI_PORT_PIN.EXTI_INPUT_LINE_NUM;
	}
	else if(PIN_Conf->EXTI_Trigger == EXTI_Trigger_FALLING)
	{
		EXTI->FTSR |= 1 << PIN_Conf->EXTI_PORT_PIN.EXTI_INPUT_LINE_NUM;
	}
	else if(PIN_Conf->EXTI_Trigger == EXTI_Trigger_RISING_FALLING)
	{
		EXTI->RTSR |= 1 << PIN_Conf->EXTI_PORT_PIN.EXTI_INPUT_LINE_NUM;
		EXTI->FTSR |= 1 << PIN_Conf->EXTI_PORT_PIN.EXTI_INPUT_LINE_NUM;
	}

	//5- Enable or disable the Inter mask
	if(PIN_Conf->IRQ_EN == EXTI_IRQ_ENABLE)
	{
		EXTI->IMR |= 1<<PIN_Conf->EXTI_PORT_PIN.EXTI_INPUT_LINE_NUM;
		NVIC_Enable(PIN_Conf);
	}
	else if(PIN_Conf->IRQ_EN == EXTI_IRQ_DISABLE)
	{
		EXTI->IMR &= ~(1<<PIN_Conf->EXTI_PORT_PIN.EXTI_INPUT_LINE_NUM);
		NVIC_Disable(PIN_Conf);
	}

	//6-Update IRQ Handle CallBack
	GPtr_IRQ_CallBack[PIN_Conf->EXTI_PORT_PIN.EXTI_INPUT_LINE_NUM] = PIN_Conf->Ptr_IRQ_CallBack;

}

/**================================================================
 * @Fn				-MCAL_EXTI_Deinit
 * @brief 			-Reset all registers in EXTI
 * @param [in] 		-none
 * @retval 			-none
 * Note				-
 */

void MCAL_EXTI_Deinit(void)
{
	EXTI->IMR   = 0x00000000;
	EXTI->EMR   = 0x00000000;
	EXTI->RTSR  = 0x00000000;
	EXTI->FTSR  = 0x00000000;
	EXTI->SWIER = 0x00000000;
	EXTI->PR	= 0xFFFFFFFF;

	//reset NVIC

	NVIC_IRQ6_EXTI0_Disable;
	NVIC_IRQ7_EXTI1_Disable;
	NVIC_IRQ8_EXTI2_Disable;
	NVIC_IRQ9_EXTI3_Disable;
	NVIC_IRQ10_EXTI4_Disable;
	NVIC_IRQ23_EXTI5_9_Disable;
	NVIC_IRQ40_EXTI10_15_Disable;
}

/**================================================================
 * @Fn				-MCAL_EXTI_Init
 * @brief 			-Initialize an Interupt as Configured in PIN_Conf
 * @param [in] 		-PIN_Conf is a Pointer to a structure contains all configurations needed
 * @retval 			-none
 * Note				-
 */

void MCAL_EXTI_Init(EXTI_PIN_Config_t * PIN_Conf)
{
	Update_EXTI(PIN_Conf);
}

/**================================================================
 * @Fn				-MCAL_EXTI_Update
 * @brief 			-Update an Interupt as Configured in PIN_Conf
 * @param [in] 		-PIN_Conf is a Pointer to a structure contains all configurations needed
 * @retval 			-none
 * Note				-
 */

void MCAL_EXTI_Update(EXTI_PIN_Config_t * PIN_Conf)
{
	Update_EXTI(PIN_Conf);
}

//=================================================================================
//IRQ_Handle

void EXTI0_IRQHandler(void)
{
	EXTI->PR |= 1<<0;
	GPtr_IRQ_CallBack[0]();
}

void EXTI1_IRQHandler(void)
{
	EXTI->PR |= 1<<1;
	GPtr_IRQ_CallBack[1]();
}

void EXTI2_IRQHandler(void)
{
	EXTI->PR |= 1<<2;
	GPtr_IRQ_CallBack[2]();
}

void EXTI3_IRQHandler(void)
{
	EXTI->PR |= 1<<3;
	GPtr_IRQ_CallBack[3]();
}

void EXTI4_IRQHandler(void)
{
	EXTI->PR |= 1<<4;
	GPtr_IRQ_CallBack[4]();
}

void EXTI9_5_IRQHandler(void)
{
	if((EXTI->PR) & 1<<5){	EXTI->PR |= 1<<5; GPtr_IRQ_CallBack[5]();}
	if((EXTI->PR) & 1<<6){	EXTI->PR |= 1<<6; GPtr_IRQ_CallBack[6]();}
	if((EXTI->PR) & 1<<7){	EXTI->PR |= 1<<7; GPtr_IRQ_CallBack[7]();}
	if((EXTI->PR) & 1<<8){	EXTI->PR |= 1<<8; GPtr_IRQ_CallBack[8]();}
	if((EXTI->PR) & 1<<9){	EXTI->PR |= 1<<9; GPtr_IRQ_CallBack[9]();}
}

void EXTI15_10_IRQHandler(void)
{
	if((EXTI->PR) & 1<<10){	EXTI->PR |= 1<<10; GPtr_IRQ_CallBack[10]();}
	if((EXTI->PR) & 1<<11){	EXTI->PR |= 1<<11; GPtr_IRQ_CallBack[11]();}
	if((EXTI->PR) & 1<<12){	EXTI->PR |= 1<<12; GPtr_IRQ_CallBack[12]();}
	if((EXTI->PR) & 1<<13){	EXTI->PR |= 1<<13; GPtr_IRQ_CallBack[13]();}
	if((EXTI->PR) & 1<<14){	EXTI->PR |= 1<<14; GPtr_IRQ_CallBack[14]();}
	if((EXTI->PR) & 1<<15){	EXTI->PR |= 1<<15; GPtr_IRQ_CallBack[15]();}
}


