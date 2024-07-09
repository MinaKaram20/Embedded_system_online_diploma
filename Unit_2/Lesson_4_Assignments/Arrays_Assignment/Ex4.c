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
	if(num>99){
		printf("Too much data!!!");
	}
	else{
		for(int i=0;i<num;i++){
			arr[i]=i+1;
			printf("%d ",arr[i]);
		}
		int ele,loc;
		printf("\nEnter the element to be inserted: ");
		fflush(stdout);
		scanf("%d",&ele);
		printf("Enter the location: ");
		fflush(stdout);
		scanf("%d",&loc);
		for(int i=num-1;i>=loc-1;i--){
			arr[i+1]=arr[i];
		}
		num++;
		arr[loc-1]=ele;
		for(int i=0;i<num;i++){
			printf("%d ",arr[i]);
		}
	}
	return 0;
}
