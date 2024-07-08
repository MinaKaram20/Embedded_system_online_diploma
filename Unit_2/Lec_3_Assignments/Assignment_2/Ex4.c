/*
 * Ex6.c
 *
 *  Created on: 8 Jul 2024
 *      Author: minak
 */

#include <stdio.h>

int main(){
	float num;
	printf("Enter a numbers: ");
	fflush(stdout);
	scanf("%f",&num);
	if(num>0){
		printf("%.2f is positive.",num);
	}
	else if(num<0){
		printf("%.2f is negative.",num);
	}
	else{
		printf("You entered zero.");
	}
	return 0;
}
