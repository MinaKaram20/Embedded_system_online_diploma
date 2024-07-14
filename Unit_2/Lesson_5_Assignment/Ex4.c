/*
 * Ex.c
 *
 *  Created on: 9 Jul 2024
 *      Author: minak
 */


#include <stdio.h>
#include <string.h>

int Power(int base,int pow);

int main(){
	int b,p;
	printf("Enter base number: ");
	fflush(stdout);
	scanf("%d",&b);
	printf("Enter power number(positive integer): ");
	fflush(stdout);
	scanf("%d",&p);
	if(p<0){
		printf("Error You Enterd a Negative Power!!!");
	}
	else{
		printf("%d^%d = %d",b,p,Power(b,p));
	}
	return 0;
}

int Power(int base,int pow){
	if(pow==0)
		return 1;
	return base*Power(base,pow-1);
}
