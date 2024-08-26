/*
 * Alarm_Driver.c
 *
 *      Author: Mina Karam 
 */
 
#include "Alarm_Driver.h"

void Alarm_On(){
	Set_Alarm_actuator(0); //to set alarm on
	Delay(60000); // waiting for 60s
	Alarm_Off();
}

void Alarm_Off(){
	Set_Alarm_actuator(1); //to set alarm off
}