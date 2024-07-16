/*
 * Ex.c
 *
 *  Created on: 9 Jul 2024
 *      Author: minak
 */


#include <stdio.h>
#include <string.h>

#define PI 3.14159

int main(){
	int r;
	printf("Enter the radius: ");
	fflush(stdout);
	scanf("%d",&r);
	printf("Area=%.2f",PI*r*r);
	return 0;
}


