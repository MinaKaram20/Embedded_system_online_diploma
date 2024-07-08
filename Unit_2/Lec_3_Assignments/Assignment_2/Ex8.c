/*
 * Ex6.c
 *
 *  Created on: 8 Jul 2024
 *      Author: minak
 */

#include <stdio.h>

int main(){
	char oper;
	float x,y;
	printf("Enter operator either + or - or * or divide: ");
	fflush(stdout);
	scanf("%c",&oper);
	printf("Enter two operands: ");
	fflush(stdout);
	scanf("%f %f",&x,&y);
	switch(oper){
	case '+':
		printf("%.1f + %.1f = %.1f",x,y,x+y);
		break;
	case '-':
		printf("%.1f - %.1f = %.1f",x,y,x-y);
		break;
	case '*':
		printf("%.1f * %.1f = %.1f",x,y,x*y);
		break;
	case '/':
		if(y==0){
			printf("Error!!! Dividing by zero");
		}
		else{
			printf("%.1f / %.1f = %.1f",x,y,x/y);
		}
		break;
	default:
		printf("Invalid operator!!!");
		break;
	}
	return 0;
}
