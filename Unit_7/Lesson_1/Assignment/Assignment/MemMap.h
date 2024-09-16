/*
 * MemMap.h
 *
 *  Created on: 16 Sept 2024
 *      Author: minak
 */

#ifndef MEMMAP_H_
#define MEMMAP_H_

#define PORTD	(*(volatile unsigned char *)(0x32))
#define DDRD	(*(volatile unsigned char *)(0x31))
#define PIND	(*(volatile unsigned char *)(0x30))

#endif /* MEMMAP_H_ */
