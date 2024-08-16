/*
 * LIFO.c
 *
 *  Created on: 15 Aug 2024
 *      Author: minak
 */

#include "LIFO.h"
//APIs
lifo_status lifo_init(lifo_buf_t* stack, element_type* buf,uint32_t length){
	if(!buf)
		return LIFO_null;
	stack->base=buf;
	stack->top=buf;
	stack->length=length;
	stack->count=0;
	return LIFO_no_error;
}
lifo_status lifo_push(lifo_buf_t* stack,element_type item){
	if(!stack->base || !stack->top)
		return LIFO_null;
	if(lifo_is_full(stack)==LIFO_full)
		return LIFO_full;
	*(stack->top) = item;
	stack->count++;
	stack->top++;
	return LIFO_no_error;
}
lifo_status lifo_pop(lifo_buf_t* stack,element_type* value){
	if(!stack->base || !stack->top)
		return LIFO_null;
	if(lifo_is_empty(stack) == LIFO_empty)
		return LIFO_empty;
	stack->top--;
	*value = *(stack->top);
	stack->count--;
	return LIFO_no_error;
}
lifo_status lifo_is_full(lifo_buf_t* stack){
	if(!stack->base || !stack->top)
		return LIFO_null;
	if(stack->count == stack->length)
		return LIFO_full;
	return LIFO_no_error;
}
lifo_status lifo_is_empty(lifo_buf_t* stack){
	if(!stack->base || !stack->top)
			return LIFO_null;
		if(stack->count == 0)
			return LIFO_empty;
		return LIFO_no_error;
}
