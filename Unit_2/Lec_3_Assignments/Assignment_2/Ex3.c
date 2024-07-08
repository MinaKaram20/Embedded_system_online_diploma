/*
 * Ex6.c
 *
 *  Created on: 8 Jul 2024
 *      Author: minak
 */

#include <stdio.h>

int main(){
	float x,y,z;
	printf("Enter three numbers: ");
	fflush(stdout);
	scanf("%f %f %f",&x,&y,&z);
	float max= (x>y) ? x : y;
	printf("Largest number = %.2f",(max>z) ? max : z);
	return 0;
}
