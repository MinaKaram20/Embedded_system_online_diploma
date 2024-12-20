/*
 * Keypad.c
 *
 *  Created on: 22 Sept 2024
 *      Author: minak
 */

#include "Keypad.h"

int Keypad_row[] = {R0,R1,R2,R3};
int Keypad_col[] = {C0,C1,C2,C3};

void Keypad_init(void){
	KeypadDDR &= ~(1<<R0 | 1<<R1 | 1<<R2 | 1<<R3);
	KeypadDDR |= (1<<C0) | (1<<C1) | (1<<C2) | (1<<C3);
	KeypadPORT = 0xFF;
}
char Keypad_getKey(void){
	for(int i=0;i<4;i++){
		KeypadPORT |= (1<<C0) | (1<<C1) | (1<<C2) | (1<<C3);
		KeypadPORT &= ~(1<<Keypad_col[i]);

		for(int j =0;j<4;j++){
			if(!(KeypadPIN & (1<<Keypad_row[j]))){
				while(!(KeypadPIN & (1<<Keypad_row[j])));
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
