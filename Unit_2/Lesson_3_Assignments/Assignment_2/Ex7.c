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
	if(num<0){
		printf("Error!!! Factorial of negative number doesn't exist.");
	}
	else{
		int fact=1;
		for(int i=1;i<=num;i++){
			fact *= i;
		}
		printf("Factorial = %d",fact);
	}
	return 0;
}
