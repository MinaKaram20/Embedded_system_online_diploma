/*
 * Stm32_F103C6_GPIO_Driver.c
 *
 *  Created on: Sep 24, 2024
 *      Author: minak
 */

//-----------------------------
//Includes
//-----------------------------

#include "Stm32_F103C6_GPIO_Driver.h"

uint8_t Get_CRLH_Position(uint16_t PIN_Number){
	switch(PIN_Number){
	case(GPIO_PIN_0) :
											return 0;
	break;
	case(GPIO_PIN_1) :
											return 4;
	break;
	case(GPIO_PIN_2) :
											return 8;
	break;
	case(GPIO_PIN_3) :
											return 12;
	break;
	case(GPIO_PIN_4) :
											return 16;
	break;
	case(GPIO_PIN_5) :
											return 20;
	break;
	case(GPIO_PIN_6) :
											return 24;
	break;
	case(GPIO_PIN_7) :
											return 28;
	break;
	case(GPIO_PIN_8) :
											return 0;
	break;
	case(GPIO_PIN_9) :
											return 4;
	break;
	case(GPIO_PIN_10) :
											return 8;
	break;
	case(GPIO_PIN_11) :
											return 12;
	break;
	case(GPIO_PIN_12) :
											return 16;
	break;
	case(GPIO_PIN_13) :
											return 20;
	break;
	case(GPIO_PIN_14) :
											return 24;
	break;
	case(GPIO_PIN_15) :
											return 28;
	break;
	}
	return 0;
}

/**================================================================
 * @Fn				-MCAL_GPIO_Init
 * @brief 			-Initialize the specified GPIO PIN to the specified configuration in the PinConfig
 * @param [in] 		-GPIOx : where x can be (A...E) to select the GPIO Peripheral
 * @param [in] 		-PinConfig is a pointer points to the struct that holds the configuration of the PIN
 * @retval 			-none
 * Note				-
 */

void MCAL_GPIO_Init(GPIO_TypeDef * GPIOx, GPIO_PINConfig_t * PinConfig){
	volatile uint32_t * ConfigRegister =NULL;
	ConfigRegister = (PinConfig->GPIO_PIN_Number < GPIO_PIN_8)? &GPIOx->CRL : &GPIOx->CRH;
	(*ConfigRegister) &= ~(0xf<<Get_CRLH_Position(PinConfig->GPIO_PIN_Number));
	if((PinConfig->GPIO_MODE == GPIO_MODE_OUTPUT_AF_OD) || (PinConfig->GPIO_MODE == GPIO_MODE_OUTPUT_AF_PP) || (PinConfig->GPIO_MODE == GPIO_MODE_OUTPUT_OD) || (PinConfig->GPIO_MODE == GPIO_MODE_OUTPUT_PP) )
	{
		(*ConfigRegister) |= ((PinConfig->GPIO_MODE - 4)<<(Get_CRLH_Position(PinConfig->GPIO_PIN_Number) + 2));
		(*ConfigRegister) |= ((PinConfig->GPIO_OUTPUT_SPEED)<<Get_CRLH_Position(PinConfig->GPIO_PIN_Number));
	}
	else
	{
		if((PinConfig->GPIO_MODE == GPIO_MODE_INPUT_FLO) || (PinConfig->GPIO_MODE == GPIO_MODE_Analog))
		{
			(*ConfigRegister) |= ((PinConfig->GPIO_MODE)<<(Get_CRLH_Position(PinConfig->GPIO_PIN_Number) + 2));
		}
		else if(PinConfig->GPIO_MODE == GPIO_MODE_INPUT_PD)
		{
			(*ConfigRegister) |= ((PinConfig->GPIO_MODE - 1)<<(Get_CRLH_Position(PinConfig->GPIO_PIN_Number) + 2));
			GPIOx->ODR &= ~(PinConfig->GPIO_PIN_Number);
		}
		else
		{
			(*ConfigRegister) |= ((PinConfig->GPIO_MODE)<<(Get_CRLH_Position(PinConfig->GPIO_PIN_Number) + 2));
			GPIOx->ODR |= PinConfig->GPIO_PIN_Number;
		}
	}
}

/**================================================================
 * @Fn				-MCAL_GPIO_DeInit
 * @brief 			-Reset the GPIO port to its reset value
 * @param [in] 		-GPIOx : where x can be (A...E) to select the GPIO Peripheral
 * @retval 			-none
 * Note				-
 */
void MCAL_GPIO_DeInit(GPIO_TypeDef * GPIOx){
	if(GPIOx==GPIOA){
		RCC->APB2RSTR |= 1<<2;
		RCC->APB2RSTR &= ~(1<<2);
	}
	else if(GPIOx==GPIOB)
	{
		RCC->APB2RSTR |= 1<<3;
		RCC->APB2RSTR &= ~(1<<3);
	}
	else if(GPIOx==GPIOC)
	{
		RCC->APB2RSTR |= 1<<4;
		RCC->APB2RSTR &= ~(1<<4);
	}
	else if(GPIOx==GPIOD)
	{
		RCC->APB2RSTR |= 1<<5;
		RCC->APB2RSTR &= ~(1<<5);
	}
	else if(GPIOx==GPIOE)
	{
		RCC->APB2RSTR |= 1<<6;
		RCC->APB2RSTR &= ~(1<<6);
	}
}

/**================================================================
 * @Fn				-MCAL_GPIO_ReadPin
 * @brief 			-Read the value of a specific pin from port
 * @param [in] 		-GPIOx : where x can be (A...E) to select the GPIO Peripheral
 * @param [in] 		-PIN_Number is the number of pin that will be read
 * @retval 			-the value of pin
 * Note				-
 */
uint8_t MCAL_GPIO_ReadPin(GPIO_TypeDef * GPIOx,uint16_t PIN_Number){
	if(((GPIOx->IDR) & PIN_Number) > 0)
	{
		return GPIO_PIN_SET;
	}
	else
	{
		return GPIO_PIN_RESET;
	}
}

/**================================================================
 * @Fn				-MCAL_GPIO_ReadPort
 * @brief 			-Read the value of a specific port
 * @param [in] 		-GPIOx : where x can be (A...E) to select the GPIO Peripheral
 * @retval 			-the value of port
 * Note				-
 */
uint16_t MCAL_GPIO_ReadPort(GPIO_TypeDef * GPIOx){
	return (uint16_t)(GPIOx->IDR);
}

/**================================================================
 * @Fn				-MCAL_GPIO_TogglePin
 * @brief 			-Toggle a specific pin
 * @param [in] 		-GPIOx : where x can be (A...E) to select the GPIO Peripheral
 * @param [in] 		-PIN_Number is the number of pin that will be toggled
 * @retval 			-none
 * Note				-
 */
void MCAL_GPIO_TogglePin(GPIO_TypeDef * GPIOx,uint16_t PIN_Number){
	GPIOx->ODR ^= (PIN_Number);
}

/**================================================================
 * @Fn				-MCAL_GPIO_WritePin
 * @brief 			-set or reset a specific pin
 * @param [in] 		-GPIOx : where x can be (A...E) to select the GPIO Peripheral
 * @param [in] 		-PIN_Number is the number of pin that will be written on
 * @param [in] 		-value is the value that will be written on the the pin
 * @retval 			-none
 * Note				-
 */
void MCAL_GPIO_WritePin(GPIO_TypeDef * GPIOx,uint16_t PIN_Number,uint8_t value){
	if(value == GPIO_PIN_SET)
	{
		GPIOx->ODR |= PIN_Number;
	}
	else if(value == GPIO_PIN_RESET)
	{
		GPIOx->ODR &= ~(PIN_Number);
	}
}

/**================================================================
 * @Fn				-MCAL_GPIO_WritePort
 * @brief 			-set or reset a specific port
 * @param [in] 		-GPIOx : where x can be (A...E) to select the GPIO Peripheral
 * @param [in] 		-value is the value that will be written on the the port
 * @retval 			-none
 * Note				-
 */
void MCAL_GPIO_WritePort(GPIO_TypeDef * GPIOx,uint8_t value){
	if(value == GPIO_PIN_SET)
	{
		GPIOx->ODR |= GPIO_ALL_PINS;
	}
	else if(value == GPIO_PIN_RESET)
	{
		GPIOx->ODR &= ~(GPIO_ALL_PINS);
	}
}

/**================================================================
 * @Fn				-MCAL_GPIO_LockPin
 * @brief 			-Lock a specific pin so it can not be used till next reset
 * @param [in] 		-GPIOx : where x can be (A...E) to select the GPIO Peripheral
 * @param [in] 		-PIN_Number is the number of pin that will be locked
 * @retval 			-status to know if the MCU locked the pin successfully or not
 * Note				-
 */
uint8_t MCAL_GPIO_LockPin(GPIO_TypeDef * GPIOx,uint16_t PIN_Number){
//	 Bit 16 LCKK[16]: Lock key
//	 This bit can be read anytime. It can only be modified using the Lock Key Writing Sequence.
//	0: Port configuration lock key not active
//	 1: Port configuration lock key active. GPIOx_LCKR register is locked until the next reset.
//	 LOCK key writing sequence:
//	 Write 1
//	 Write 0
//	 Write 1
//	 Read 0
//	 Read 1 (this read is optional but confirms that the lock is active)
//	 Note: During the LOCK Key Writing sequence, the value of LCK[15:0] must not change.
//	 Any error in the lock sequence will abort the lock.
//	 Bits 15:0 LCKy: Port x Lock bit y (y= 0 .. 15)
//	 These bits are read write but can only be written when the LCKK bit is 0.
//	0: Port configuration not locked
//	1: Port configuration locked

	volatile uint32_t temp =1<<16;
	//write on the target pin 1 to lock
	GPIOx->LCKR |= PIN_Number;
	//	 Write 1 on bit 16
	GPIOx->LCKR |= temp;
	//	 Write 0
	GPIOx->LCKR &= ~(1<<16);
	//	 Write 1
	GPIOx->LCKR |= 1<<16;
	//	 Read 0
	temp = (GPIOx->LCKR >> 16) & 1;
	//	 Read 1 (this read is optional but confirms that the lock is active)
	if((GPIOx->LCKR >> 16) >0)
	{
		return GPIO_PIN_RETURN_LOCK_ENABLED;
	}
	else
	{
		return GPIO_PIN_RETURN_LOCK_ERROR;
	}

}
