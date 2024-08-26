/*
 * Presure_Sensor_Driver.c
 *
 *      Author: Mina Karam 
 */

#include "Presure_Sensor_Driver.h"

//variables
uint32_t Pval;


//APIs definition

void get_Pval(){
	Pval=getPressureVal(); //read from sensor
	Send_Pval(Pval); //send the value to High_Presure_Detection_main
}

void Send_Pval(uint32_t val){
	Recieve_Pval(val);
}