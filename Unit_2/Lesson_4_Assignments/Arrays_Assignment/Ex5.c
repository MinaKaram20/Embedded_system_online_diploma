/*
 * Ex1.c
 *
 *  Created on: 9 Jul 2024
 *      Author: minak
 */

#include <stdio.h>

int main(){
	int arr[100]={0};
	int num;
	printf("Enter no of elements: ");
	fflush(stdout);
	scanf("%d",&num);
	if(num>100){
		printf("Too much data!!!");
	}
	else{
		for(int i=0;i<num;i++){
			arr[i]=(i+1)*11;
			printf("%d ",arr[i]);
		}
		int ele,loc=0;
		printf("\nEnter the elements to be searched: ");
		fflush(stdout);
		scanf("%d",&ele);
		for(int i=0;i<num;i++){
			if(arr[i]==ele){
				loc=i+1;
				break;
			}
		}
		if(loc==0){
			printf("Element not found");
		}
		else{
			printf("Number found at the location = %d",loc);
		}
	}
	return 0;
}
