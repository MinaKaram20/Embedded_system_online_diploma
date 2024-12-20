/*
 * FIFO.h
 *
 *  Created on: 15 Aug 2024
 *      Author: minak
 */

#ifndef FIFO_H_
#define FIFO_H_
#include "Platform_types.h"
//Element type of FIFO
#define element_type uint32_t

//FIFO variable
typedef struct{
	uint32_t length;
	uint32_t count;
	element_type* base;
	element_type* first;
	element_type* last;
} fifo_buf_t;

typedef enum{
	FIFO_no_error,
	FIFO_empty,
	FIFO_full,
	FIFO_null
} fifo_status;

//APIs
fifo_status fifo_init(fifo_buf_t* queue,element_type* buf,uint32_t length);
fifo_status fifo_enqueue(fifo_buf_t* queue, element_type item);
fifo_status fifo_dequeue(fifo_buf_t* queue,element_type* value);
fifo_status fifo_is_empty(fifo_buf_t* queue);
fifo_status fifo_is_full(fifo_buf_t* queue);
#endif /* FIFO_H_ */
