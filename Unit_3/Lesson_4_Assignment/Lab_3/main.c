/*Learn In Depth
Eng. Mina Karam
LAB 3
*/
#include "Platform_Types.h"

#define SYSCTL_RCGC2_R		(*((volatile uint32 *)0x400FE108))
#define GPIO_PORTF_DIR_R	(*((volatile uint32 *)0x400253FC))
#define GPIO_PORTF_DEN_R	(*((volatile uint32 *)0x40025400))
#define GPIO_PORTF_DATA_R	(*((volatile uint32 *)0x4002551C))

int main(void) {
	SYSCTL_RCGC2_R = 0x00000020;
	GPIO_PORTF_DIR_R |= 1 << 3;
	GPIO_PORTF_DEN_R |= 1 << 3;
	volatile uint32 delay;
	while (1) {
		GPIO_PORTF_DATA_R ^= 1 << 3;
		for (delay = 0; delay < 200000; delay++);
	}
	return 0;
}