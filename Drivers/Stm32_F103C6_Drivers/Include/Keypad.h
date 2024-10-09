/*
 * Keypad.h
 *
 *  Created on: 22 Sept 2024
 *      Author: minak
 */

#ifndef KEYPAD_H_
#define KEYPAD_H_

#include "Stm32f103x6.h"
#include "Stm32_F103C6_GPIO_Driver.h"

#define R0	GPIO_PIN_0
#define R1	GPIO_PIN_1
#define R2	GPIO_PIN_3
#define R3	GPIO_PIN_4
#define C0	GPIO_PIN_5
#define C1	GPIO_PIN_6
#define C2	GPIO_PIN_7
#define C3	GPIO_PIN_8

#define KeypadPORT	GPIOB


void Keypad_init(void);
char Keypad_getKey(void);

#endif /* KEYPAD_H_ */
