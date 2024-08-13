#include "Platform_Types.h"

void Reset_Handler();
extern int main(void);

void Default_Handler() {
	Reset_Handler();
}

void NMI_Handler() __attribute__((weak, alias("Default_Handler")));;
void H_fault_Handler() __attribute__((weak, alias("Default_Handler")));;

static uint32 stack_top[256];

void (* const g_p_func_vectors[])() __attribute__((section(".vectors"))) =
{
	(void (*)()) ((unsigned long)stack_top + sizeof(stack_top)),
	&Reset_Handler,
	&NMI_Handler,
	&H_fault_Handler
};

extern uint32 _E_TEXT;
extern uint32 _S_DATA;
extern uint32 _E_DATA;
extern uint32 _S_BSS;
extern uint32 _E_BSS;

void Reset_Handler() {
	uint32 DATA_size = (uint16 *)&_E_DATA - (uint16 *)&_S_DATA;
	uint16* P_src = (uint16*)&_E_TEXT;
	uint16* P_dst = (uint16*)&_S_DATA;
	for (uint32 i = 0; i < DATA_size; i++) {
		*((uint16*)P_dst++) = *((uint16*)P_src++);
	}

	P_dst = (uint16*)&_S_BSS;
	DATA_size = (uint16*)&_E_BSS - (uint16*)&_S_BSS;
	for (uint32 i = 0; i < DATA_size; i++) {
		*((uint16*)P_dst++) = (uint16)0;
	}
	main();
}