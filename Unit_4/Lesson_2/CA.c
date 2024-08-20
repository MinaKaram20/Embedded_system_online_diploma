/*
 * AC.c
 *
 *  Created on: 20 Aug 2024
 *      Author: minak
 */

#include "CA.h"
#include <stdio.h>
#include <stdlib.h>

//variables
unsigned int distance,speed,threshold=50;

//state
enum {
	waiting,
	driving
} CA_state;

static int Generate_random(int min,int max);
void (*CA_pointer)();

_State_define(CA_waiting){
	//state action
	CA_state= waiting;
	speed=0;
	distance = Generate_random(45,55);
	//check event
	(distance<=threshold)? (CA_pointer=_STATE(CA_waiting)) : (CA_pointer=_STATE(CA_driving));
	printf("Waiting state : distance =%d  speed =%d\n",distance,speed);
}
_State_define(CA_driving){
	//state action
	CA_state= driving;
	speed=30;
	distance = Generate_random(45,55);
	//check event
	(distance<=threshold)? (CA_pointer=_STATE(CA_waiting)) : (CA_pointer=_STATE(CA_driving));
	printf("Driving state : distance =%d  speed =%d\n",distance,speed);
}
int Generate_random(int min,int max){
	int rand_num= (rand()%(max-min+1))+min;
	return rand_num;
}
