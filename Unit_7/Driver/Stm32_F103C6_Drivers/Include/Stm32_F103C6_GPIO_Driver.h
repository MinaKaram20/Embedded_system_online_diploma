/*
 * Stm32_F103C6_GPIO_Driver.h
 *
 *  Created on: Sep 24, 2024
 *      Author: minak
 */

#ifndef INCLUDE_STM32_F103C6_GPIO_DRIVER_H_
#define INCLUDE_STM32_F103C6_GPIO_DRIVER_H_

//-----------------------------
//Includes
//-----------------------------

#include "Stm32f103x6.h"

//-----------------------------
//User type definitions (structures)
//-----------------------------

typedef struct{
	uint16_t GPIO_PIN_Number; 	// Specifies the GPIO pins to be configured
							  	// This Parameter must be a value of @ref GPIO_PIN_define
	uint8_t GPIO_MODE; 		  	// Specifies the GPIO pins mode to be configured
							  	// This Parameter must be a value of @ref GPIO_MODE_define
	uint8_t GPIO_OUTPUT_SPEED;	// Specifies the GPIO pin output speed
								// This Parameter must be a value of @ref GPIO_OUTPUT_SPEED_define
}GPIO_PINConfig_t;

//==================================================================================


//-----------------------------
//Macros Configuration References
//-----------------------------

// @ref GPIO_PIN_define

#define GPIO_PIN_0			((uint16_t)(0x0001))
#define GPIO_PIN_1			((uint16_t)(0x0002))
#define GPIO_PIN_2			((uint16_t)(0x0004))
#define GPIO_PIN_3			((uint16_t)(0x0008))
#define GPIO_PIN_4			((uint16_t)(0x0010))
#define GPIO_PIN_5			((uint16_t)(0x0020))
#define GPIO_PIN_6			((uint16_t)(0x0040))
#define GPIO_PIN_7			((uint16_t)(0x0080))
#define GPIO_PIN_8			((uint16_t)(0x0100))
#define GPIO_PIN_9			((uint16_t)(0x0200))
#define GPIO_PIN_10			((uint16_t)(0x0400))
#define GPIO_PIN_11			((uint16_t)(0x0800))
#define GPIO_PIN_12			((uint16_t)(0x1000))
#define GPIO_PIN_13			((uint16_t)(0x2000))
#define GPIO_PIN_14			((uint16_t)(0x4000))
#define GPIO_PIN_15			((uint16_t)(0x8000))
#define GPIO_ALL_PINS		((uint16_t)(0xFFFF))


// @ref GPIO_MODE_define

//0: Analog mode
//1: Floating input (reset state)
//2: Input with pull-up
//3: Input with pull-down
//4: General purpose output push-pull
//5: General purpose output Open-drain
//6: Alternate function output Push-pull
//7: Alternate function output Open-drain

#define GPIO_MODE_Analog		((uint8_t)(0x00))
#define GPIO_MODE_INPUT_FLO		((uint8_t)(0x01))
#define GPIO_MODE_INPUT_PU		((uint8_t)(0x02))
#define GPIO_MODE_INPUT_PD		((uint8_t)(0x03))
#define GPIO_MODE_OUTPUT_PP		((uint8_t)(0x04))
#define GPIO_MODE_OUTPUT_OD		((uint8_t)(0x05))
#define GPIO_MODE_OUTPUT_AF_PP	((uint8_t)(0x06))
#define GPIO_MODE_OUTPUT_AF_OD	((uint8_t)(0x07))

// @ref GPIO_OUTPUT_SPEED_define

//1: Output mode, max speed 10 MHz.
//2: Output mode, max speed 2 MHz.
//3: Output mode, max speed 50 MHz

#define GPIO_OUTPUT_SPEED_10MHz		((uint8_t)(0x01))
#define GPIO_OUTPUT_SPEED_2MHz		((uint8_t)(0x02))
#define GPIO_OUTPUT_SPEED_50MHz		((uint8_t)(0x03))

// @ref PIN_STATE

#define GPIO_PIN_SET		1
#define GPIO_PIN_RESET		0

// @ref PIN_RETURN_LOCK

#define GPIO_PIN_RETURN_LOCK_ENABLED		1
#define GPIO_PIN_RETURN_LOCK_ERROR			0

//=============================================================

/*
* ===============================================
* APIs Supported by "MCAL GPIO DRIVER"
* ===============================================
*/

void MCAL_GPIO_Init(GPIO_TypeDef * GPIOx, GPIO_PINConfig_t * PinConfig);
void MCAL_GPIO_DeInit(GPIO_TypeDef * GPIOx);
uint8_t MCAL_GPIO_ReadPin(GPIO_TypeDef * GPIOx,uint16_t PIN_Number);
uint16_t MCAL_GPIO_ReadPort(GPIO_TypeDef * GPIOx);
void MCAL_GPIO_TogglePin(GPIO_TypeDef * GPIOx,uint16_t PIN_Number);
void MCAL_GPIO_WritePin(GPIO_TypeDef * GPIOx,uint16_t PIN_Number, uint8_t value);
void MCAL_GPIO_WritePort(GPIO_TypeDef * GPIOx,uint8_t value);
uint8_t MCAL_GPIO_LockPin(GPIO_TypeDef * GPIOx,uint16_t PIN_Number);


#endif /* INCLUDE_STM32_F103C6_GPIO_DRIVER_H_ */
