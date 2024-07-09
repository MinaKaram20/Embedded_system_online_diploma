/*
 * Ex6.c
 *
 *  Created on: 8 Jul 2024
 *      Author: minak
 */

#include <stdio.h>

int main(){
	int num;
	printf("Enter an integer: ");
	fflush(stdout);
	scanf("%d",&num);
	printf("Sum = %d",((num+1)*num)/2);
	return 0;
}
