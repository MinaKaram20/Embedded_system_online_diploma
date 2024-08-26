/*
 * Presure_Sensor_Driver.h
 *
 *      Author: Mina Karam 
 */

#ifndef PRESURE_SENSOR_DRIVER_H_
#define PRESURE_SENSOR_DRIVER_H_

//Includes
#include "driver.h"
#include "High_Presure_Detection_main.h"

//Variables
extern uint32_t Pval;

//APIs
void get_Pval();
void Send_Pval(uint32_t val);

#endif /* PRESURE_SENSOR_DRIVER_H_ */