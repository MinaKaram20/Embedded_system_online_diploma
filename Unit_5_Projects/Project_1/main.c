/*
 * main.c
 *
 *      Author: Mina Karam 
 */
 
#include <stdint.h>
#include <stdio.h>

#include "driver.h"
#include "Presure_Sensor_Driver.h"

int main (void){
	GPIO_INITIALIZATION();
	while (1)
	{
		get_Pval();
	}

}
