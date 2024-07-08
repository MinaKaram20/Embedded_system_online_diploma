/*
 * Ex6.c
 *
 *  Created on: 8 Jul 2024
 *      Author: minak
 */

#include <stdio.h>

int main(){
	int num;
	printf("Enter an integer you want to check: ");
	fflush(stdout);
	scanf("%d",&num);
	if(num%2==0){
		printf("%d is even",num);
	}
	else{
		printf("%d is odd",num);
	}
	return 0;
}
