/*
 * Ex1.c
 *
 *  Created on: 9 Jul 2024
 *      Author: minak
 */

#include <stdio.h>

int main(){
	int num;
	float data[100]={0};
	printf("Enter the numbers of data: ");
	fflush(stdout);
	scanf("%d",&num);
	if(num>100){
		printf("Too much data!!!");
	}
	else{
		float sum=0;
		for(int i=0;i<num;i++){
			printf("%d. Enter number: ",i+1);
			fflush(stdout);
			scanf("%f",&data[i]);
			sum+=data[i];
		}
		printf("Average = %.2f",sum/num);
	}
	return 0;
}
