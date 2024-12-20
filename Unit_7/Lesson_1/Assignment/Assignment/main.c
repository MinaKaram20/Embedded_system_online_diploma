/*
 * main.c
 *
 *  Created on: 16 Sept 2024
 *      Author: minak
 */

#include "MemMap.h"
#include "Utils.h"
#include <util/delay.h>

int main(void){
	DDRD=0b11111000;
	while(1){
		if(ReadBit(PIND,0)==1){
			for(unsigned char count=1;count<4;count++){
				SetBit(PORTD,(count+4)); //the LED are on PIN 5,6,7 so first press will be 1+4=5 and so on
				_delay_ms(3000);
			}
			for(unsigned char count=3;count>=1;count--){
				ClearBit(PORTD,(count+4));
				_delay_ms(3000);
			}
		}
		if(ReadBit(PIND,1)==1){
			for(unsigned char count=1;count<4;count++){
				SetBit(PORTD,(count+4));
				//to read single press
				while(ReadBit(PIND,1)==1);
				while(ReadBit(PIND,1)==0);
			}
			ClearBit(PORTD,7);
			ClearBit(PORTD,6);
			ClearBit(PORTD,5);
			_delay_ms(3000);
		}
		if(ReadBit(PIND,2)==1){
			ToggleBit(PORTD,5);
			_delay_ms(4000);
			ToggleBit(PORTD,5);
			ToggleBit(PORTD,6);
			_delay_ms(4000);
			ToggleBit(PORTD,6);
			ToggleBit(PORTD,7);
			_delay_ms(4000);
			SetBit(PORTD,4);
			_delay_ms(4000);
			ToggleBit(PORTD,4);
			ToggleBit(PORTD,7);
		}
	}
}
