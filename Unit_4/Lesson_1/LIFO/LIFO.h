/*
 * LIFO.h
 *
 *  Created on: 15 Aug 2024
 *      Author: minak
 */

#ifndef LIFO_H_
#define LIFO_H_

#include "Platform_Types.h"
//Element type of LIFO
#define element_type uint32_t

//variables

typedef struct {
	uint32_t length;
	uint32_t count;
	element_type* top;
	element_type* base;
} lifo_buf_t;

typedef enum{
	LIFO_no_error,
	LIFO_empty,
	LIFO_full,
	LIFO_null
} lifo_status;

//APIs
lifo_status lifo_init(lifo_buf_t* stack, element_type* buf,uint32_t length);//Initialize a satck
lifo_status lifo_push(lifo_buf_t* stack,element_type item);					//add an item in the stack
lifo_status lifo_pop(lifo_buf_t* stack,element_type* value);				//pop an item from the stack
lifo_status lifo_is_full(lifo_buf_t* stack);								//check if the stack is full
lifo_status lifo_is_empty(lifo_buf_t* stack);								//check if the stack is empty

#endif /* LIFO_H_ */
