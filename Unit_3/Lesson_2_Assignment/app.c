#include "uart.h"

unsigned char str[100] = "learn-in-depth:<Mina Karam>";

void main(void) {
	uart_send_string(str);
}