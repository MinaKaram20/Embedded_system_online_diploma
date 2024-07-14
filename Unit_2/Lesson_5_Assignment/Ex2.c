/*
 * Ex.c
 *
 *  Created on: 9 Jul 2024
 *      Author: minak
 */


#include <stdio.h>

int fact(int a);

int main(){
	int num;
	printf("Enter a positive integer: ");
	fflush(stdout);
	scanf("%d",&num);
	if(num<0){
		printf("Error You Entered a Negative Number!!");
	}
	else{
		printf("Factorial of %d = %d ",num,fact(num));
	}
	return 0;
}

int fact(int a){
	if(a<=1)
		return 1;
	return a*fact(a-1);
}
