/*
 * CA.h
 *
 *  Created on: 20 Aug 2024
 *      Author: minak
 */

#ifndef CA_H_
#define CA_H_

#include "state.h"

//Declare state func CA

_State_define(CA_waiting);
_State_define(CA_driving);

//Declare pointer to func

extern void  (*CA_pointer)();

#endif /* CA_H_ */
