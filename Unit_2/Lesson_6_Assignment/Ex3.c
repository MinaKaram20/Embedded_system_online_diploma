/*
 * Ex.c
 *
 *  Created on: 9 Jul 2024
 *      Author: minak
 */


#include <stdio.h>
#include <string.h>

struct Scomplex{
	float real;
	float imag;
};

void add(struct Scomplex a,struct Scomplex b){
	printf("Sum=%.1f+%.1fi",a.real+b.real,a.imag+b.imag);
}

int main(){
	struct Scomplex c1,c2;
	printf("For 1st complex number: \n");
	printf("Enter real and imaginary respectively: ");
	fflush(stdout);
	scanf("%f %f",&c1.real,&c1.imag);
	printf("\nFor 2nd complex number: \n");
	printf("Enter real and imaginary respectively: ");
	fflush(stdout);
	scanf("%f %f",&c2.real,&c2.imag);
	add(c1,c2);
	return 0;
}


