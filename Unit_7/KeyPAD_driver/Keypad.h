/*
 * Keypad.h
 *
 *  Created on: 22 Sept 2024
 *      Author: minak
 */

#ifndef KEYPAD_H_
#define KEYPAD_H_

#include <avr/io.h>
#include <util/delay.h>

#define R0	0
#define R1	1
#define R2	2
#define R3	3
#define C0	4
#define C1	5
#define C2	6
#define C3	7

#define KeypadPORT	PORTD
#define KeypadPIN	PIND
#define KeypadDDR	DDRD

void Keypad_init(void);
char Keypad_getKey(void);

#endif /* KEYPAD_H_ */
