/*
 * Ex.c
 *
 *  Created on: 9 Jul 2024
 *      Author: minak
 */


#include <stdio.h>



int main(){
	int m=29;
	printf("Address of m : 0x%x\n",&m);
	printf("Value of m : %d\n\n",m);
	int* ab=&m;
	printf("Now ab is assigned with the address of m.\n");
	printf("Address of pointer ab : 0x%x\n",ab);
	printf("Content of pointer ab : %d\n\n",*ab);
	m=34;
	printf("The value of m assigned to 34 now.\n");
	printf("Address of pointer ab : 0x%x\n",ab);
	printf("Content of pointer ab : %d\n\n",*ab);
	*ab=7;
	printf("The pointer variable ab is assigned with the value 7 now.\n");
	printf("Address of m : 0x%x\n",&m);
	printf("Value of m : %d\n\n",m);
	return 0;
}


