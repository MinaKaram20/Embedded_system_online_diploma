/*
 * Keypad.c
 *
 *  Created on: 22 Sept 2024
 *      Author: minak
 */

#include "Keypad.h"
#include "Stm32_F103C6_GPIO_Driver.h"

int Keypad_row[] = {R0,R1,R2,R3};
int Keypad_col[] = {C0,C1,C2,C3};

void Keypad_init(void){
	GPIO_PINConfig_t KeyPad_PIN;

	KeyPad_PIN.GPIO_PIN_Number = R0;
	KeyPad_PIN.GPIO_MODE = GPIO_MODE_OUTPUT_PP;
	KeyPad_PIN.GPIO_OUTPUT_SPEED = GPIO_OUTPUT_SPEED_10MHz;
	MCAL_GPIO_Init(KeypadPORT, &KeyPad_PIN);

	KeyPad_PIN.GPIO_PIN_Number = R1;
	KeyPad_PIN.GPIO_MODE = GPIO_MODE_OUTPUT_PP;
	KeyPad_PIN.GPIO_OUTPUT_SPEED = GPIO_OUTPUT_SPEED_10MHz;
	MCAL_GPIO_Init(KeypadPORT, &KeyPad_PIN);

	KeyPad_PIN.GPIO_PIN_Number = R2;
	KeyPad_PIN.GPIO_MODE = GPIO_MODE_OUTPUT_PP;
	KeyPad_PIN.GPIO_OUTPUT_SPEED = GPIO_OUTPUT_SPEED_10MHz;
	MCAL_GPIO_Init(KeypadPORT, &KeyPad_PIN);

	KeyPad_PIN.GPIO_PIN_Number = R3;
	KeyPad_PIN.GPIO_MODE = GPIO_MODE_OUTPUT_PP;
	KeyPad_PIN.GPIO_OUTPUT_SPEED = GPIO_OUTPUT_SPEED_10MHz;
	MCAL_GPIO_Init(KeypadPORT, &KeyPad_PIN);

	KeyPad_PIN.GPIO_PIN_Number = C0;
	KeyPad_PIN.GPIO_MODE = GPIO_MODE_OUTPUT_PP;
	KeyPad_PIN.GPIO_OUTPUT_SPEED = GPIO_OUTPUT_SPEED_10MHz;
	MCAL_GPIO_Init(KeypadPORT, &KeyPad_PIN);

	KeyPad_PIN.GPIO_PIN_Number = C1;
	KeyPad_PIN.GPIO_MODE = GPIO_MODE_OUTPUT_PP;
	KeyPad_PIN.GPIO_OUTPUT_SPEED = GPIO_OUTPUT_SPEED_10MHz;
	MCAL_GPIO_Init(KeypadPORT, &KeyPad_PIN);

	KeyPad_PIN.GPIO_PIN_Number = C2;
	KeyPad_PIN.GPIO_MODE = GPIO_MODE_OUTPUT_PP;
	KeyPad_PIN.GPIO_OUTPUT_SPEED = GPIO_OUTPUT_SPEED_10MHz;
	MCAL_GPIO_Init(KeypadPORT, &KeyPad_PIN);

	KeyPad_PIN.GPIO_PIN_Number = C3;
	KeyPad_PIN.GPIO_MODE = GPIO_MODE_OUTPUT_PP;
	KeyPad_PIN.GPIO_OUTPUT_SPEED = GPIO_OUTPUT_SPEED_10MHz;
	MCAL_GPIO_Init(KeypadPORT, &KeyPad_PIN);

	MCAL_GPIO_WritePort(KeypadPORT, 0xFF);
}
char Keypad_getKey(void){
	for(int i=0;i<4;i++){
		MCAL_GPIO_WritePin(KeypadPORT, C0, GPIO_PIN_SET);
		MCAL_GPIO_WritePin(KeypadPORT, C1, GPIO_PIN_SET);
		MCAL_GPIO_WritePin(KeypadPORT, C2, GPIO_PIN_SET);
		MCAL_GPIO_WritePin(KeypadPORT, C3, GPIO_PIN_SET);

		MCAL_GPIO_WritePin(KeypadPORT, Keypad_col[i], GPIO_PIN_RESET);

		for(int j =0;j<4;j++){
			if(MCAL_GPIO_ReadPin(KeypadPORT, Keypad_row[j]) == GPIO_PIN_RESET){
				while(MCAL_GPIO_ReadPin(KeypadPORT, Keypad_row[j]) == GPIO_PIN_RESET);
				switch(i){
				case(0) :
						if(j==0){
							return '7';
						}
						else if(j==1){
							return '4';
						}
						else if(j==2){
							return '1';
						}
						else if(j==3){
							return '!';
						}
				break;
				case(1) :
						if(j==0){
							return '8';
						}
						else if(j==1){
							return '5';
						}
						else if(j==2){
							return '2';
						}
						else if(j==3){
							return '0';
						}
				break;
				case(2) :
						if(j==0){
							return '9';
						}
						else if(j==1){
							return '6';
						}
						else if(j==2){
							return '3';
						}
						else if(j==3){
							return '=';
						}
				break;
				case(3) :
						if(j==0){
							return '/';
						}
						else if(j==1){
							return '*';
						}
						else if(j==2){
							return '-';
						}
						else if(j==3){
							return '+';
						}
				break;
				}
			}
		}
	}
	return 'N';
}
