/*
 * FIFO.c
 *
 *  Created on: 15 Aug 2024
 *      Author: minak
 */
#include "FIFO.h"
//APIs
fifo_status fifo_init(fifo_buf_t* queue,element_type* buf,uint32_t length){
	if(!buf)
		return FIFO_null;
	queue->base=buf;
	queue->first=buf;
	queue->last=buf;
	queue->length=length;
	queue->count=0;
	return FIFO_no_error;
}
fifo_status fifo_enqueue(fifo_buf_t* queue, element_type item){
	if(!queue->base || !queue->last || !queue->first)
		return FIFO_null;
	if(fifo_is_full(queue)==FIFO_full)
		return FIFO_full;
	queue->count++;
	*(queue->last)=item;
	if((queue->last + 1) >= (queue->base + queue->length))
		queue->last=queue->base;
	else
		queue->last++;
	return FIFO_no_error;
}
fifo_status fifo_dequeue(fifo_buf_t* queue,element_type* value){
	if(!queue->base || !queue->last || !queue->first)
		return FIFO_null;
	if(fifo_is_empty(queue)==FIFO_empty)
		return FIFO_empty;
	queue->count--;
	*value = *(queue->first);
	if((queue->first + 1) >= (queue->base + queue->length))
			queue->first=queue->base;
		else
			queue->first++;
		return FIFO_no_error;
}
fifo_status fifo_is_full(fifo_buf_t* queue){
	if(!queue->base || !queue->last || !queue->first)
		return FIFO_null;
	if(queue->count == queue->length)
		return FIFO_full;
	return FIFO_no_error;
}
fifo_status fifo_is_empty(fifo_buf_t* queue){
	if(!queue->base || !queue->last || !queue->first)
			return FIFO_null;
		if(queue->count == 0)
			return FIFO_empty;
		return FIFO_no_error;
}
