/*
 * Ex.c
 *
 *  Created on: 9 Jul 2024
 *      Author: minak
 */


#include <stdio.h>



int main(){
	int arr[5];
	printf("Input 5 number of elements in the array :\n");
	for(int i=0;i<5;i++){
		printf("element - %d :",i+1);
		fflush(stdout);
		scanf("%d",&arr[i]);
	}
	int* ptr=&arr[4];
	printf("\nThe elements of array in reverse order are :\n");
	int i=5;
	do{
		printf("element - %d : %d\n",i,*ptr);
		i--,ptr--;
	}while(i!=0);
	return 0;
}


