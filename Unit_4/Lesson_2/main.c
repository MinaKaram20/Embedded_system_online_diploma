/*
 * main.c
 *
 *  Created on: 20 Aug 2024
 *      Author: minak
 */


#include "CA.h"
void setup(){
	CA_pointer= _STATE(CA_waiting);
}
int main(){
	setup();
	volatile int i;
	while(1){
		CA_pointer();
		for(i=0;i<1000;i++);
	}
	return 0;
}
