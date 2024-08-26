/*
 * High_Presure_Detection_main.h
 *
 *      Author: Mina Karam 
 */
 
#ifndef HIGH_PRESURE_DETECTION_MAIN_H_
#define HIGH_PRESURE_DETECTION_MAIN_H_
//Includes
#include "driver.h"
#include "Alarm_Driver.h"


//APIs
void Recieve_Pval(uint32_t val);
void check_presure(uint32_t val);

#endif /* HIGH_PRESURE_DETECTION_MAIN_H_ */