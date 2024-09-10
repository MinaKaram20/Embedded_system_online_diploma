/*
 * main.c
 *
 *  Created on: 10 Sept 2024
 *      Author: minak
 */

#include <avr/interrupt.h>
#include <util/delay.h>
#include <avr/io.h>

int main(void){
	DDRD = 0b11100000;
	MCUCR = 0b1101;
	MCUCSR &= ~(1<<ISC2);
	GICR |= (0b111<<5);
	SREG |= 1<<7;
	PORTD &= ~(0b111<<5);

	while(1){

	}

}
ISR(INT0_vect){
	PORTD ^= 1<<5;
	_delay_ms(1000);
	PORTD ^= 1<<5;
}
ISR(INT1_vect){
	PORTD ^= 1<<6;
	_delay_ms(1000);
	PORTD ^= 1<<6;
}
ISR(INT2_vect){
	PORTD ^= 1<<7;
	_delay_ms(1000);
	PORTD ^= 1<<7;
}
