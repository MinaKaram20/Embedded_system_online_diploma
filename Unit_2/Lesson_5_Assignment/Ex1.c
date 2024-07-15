/*
 * Ex.c
 *
 *  Created on: 9 Jul 2024
 *      Author: minak
 */


#include <stdio.h>

int Is_prime(int a);

int main(){
	int num1,num2;
	printf("Enter two numbers(intervals): ");
	fflush(stdout);
	scanf("%d %d",&num1,&num2);
	printf("Prime numbers between %d and %d are: ",num1,num2);
	for(int i=num1;i<=num2;i++){
		if(Is_prime(i)){
			printf("%d ",i);
		}
	}
	return 0;
}

int Is_prime(int a){
	if(a<1)
		return 0;
	for(int i=2;i<=a/2;i++){
		if(a%i==0)
			return 0;
	}
	return 1;
}
