//Learn-in-depth
//Mina Karam
//Mastering Embedded System online diploma


typedef volatile unsigned int vuint32_t ;
#include <stdint.h>
#include <stdlib.h>
#include <stdio.h>
// register address
#define RCC_BASE	0x40021000
#define RCC_CFGR	 *(volatile uint32_t *)(RCC_BASE + 0x04)
void Clock_init(){
	RCC_CFGR |= 0b1011<<10;
}
int main(void)
{
	Clock_init();
	while(1)
	{

	}
}
