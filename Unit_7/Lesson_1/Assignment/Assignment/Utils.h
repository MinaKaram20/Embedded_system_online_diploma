/*
 * Utils.h
 *
 *  Created on: 16 Sept 2024
 *      Author: minak
 */

#ifndef UTILS_H_
#define UTILS_H_

#define SetBit(reg,bit)		(reg = reg | (1<<bit))
#define ClearBit(reg,bit)	(reg = reg & ~(1<<bit))
#define ToggleBit(reg,bit)	(reg = reg ^ (1<<bit))
#define ReadBit(reg,bit)	((reg>>bit)&1)

#endif /* UTILS_H_ */
