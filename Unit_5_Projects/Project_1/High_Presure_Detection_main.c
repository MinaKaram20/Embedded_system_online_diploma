/*
 * High_Presure_Detection_main.c
 *
 *      Author: Mina Karam 
 */
 
#include "High_Presure_Detection_main.h"

//variables
static const uint8_t P_threshold = 20; // Presure threshold is 20 bar

//APIs definition

void Recieve_Pval(uint32_t val){
	check_presure(val); //check on the presure sensed
}

void check_presure(uint32_t val){
	if(val<P_threshold){
		Alarm_Off();
		Delay(100000); //wait for next recieve (on the design it was 100s)
	}
	else{
		Alarm_On();
	}
}