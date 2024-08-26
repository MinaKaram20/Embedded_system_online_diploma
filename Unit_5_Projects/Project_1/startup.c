/*
 * startup.c
 *
 *      Author: Mina Karam 
 */

#include "Platform_Types.h"

extern uint32_t stack_top;
extern uint32_t _E_TEXT;
extern uint32_t _S_DATA;
extern uint32_t _E_DATA;
extern uint32_t _S_BSS;
extern uint32_t _E_BSS;

extern int main(void);

void Reset_Handler(void);
void Default_Handler(void) {
	Reset_Handler();
}

void NMI_Handler(void) __attribute__((weak, alias("Default_Handler")));
void H_fault_Handler(void) __attribute__((weak, alias("Default_Handler")));
void MM_Fault_Handler(void) __attribute__((weak, alias("Default_Handler")));
void Bus_Fault_Handler(void) __attribute__((weak, alias("Default_Handler")));
void Usage_Fault_Handler(void) __attribute__((weak, alias("Default_Handler")));

uint32_t vectors[] __attribute__((section(".vectors"))) = {
	(uint32_t)&stack_top,
	(uint32_t)&Reset_Handler,
	(uint32_t)&NMI_Handler,
	(uint32_t)&H_fault_Handler,
	(uint32_t)&MM_Fault_Handler,
	(uint32_t)&Bus_Fault_Handler,
	(uint32_t)&Usage_Fault_Handler
};
void Reset_Handler(void){
	uint32_t DATA_size = (uint8_t *)&_E_DATA - (uint8_t *)&_S_DATA;
	uint8_t* P_src = (uint8_t*)&_E_TEXT;
	uint8_t* P_dst = (uint8_t*)&_S_DATA;
	for (uint32_t i = 0; i < DATA_size; i++) {
		*((uint8_t*)P_dst++) = *((uint8_t*)P_src++);
	}

	P_dst = (uint8_t*)&_S_BSS;
	DATA_size = (uint8_t*)&_E_BSS - (uint8_t*)&_S_BSS;
	for (uint32_t i = 0; i < DATA_size; i++) {
		*((uint8_t*)P_dst++) = ((uint8_t)0);
	}
	main();
}