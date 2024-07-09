/*
 * Ex1.c
 *
 *  Created on: 9 Jul 2024
 *      Author: minak
 */

#include <stdio.h>

int main(){
	int row,col;
	int a[10][10];
	printf("Enter rows and column of matrix: ");
	fflush(stdout);
	scanf("%d %d",&row,&col);
	if(row>10||col>10){
		printf("To much data!!!");
	}
	else{
		printf("Enter the elements of matrix:\n");
		for(int i=0;i<row;i++){
			for(int j=0;j<col;j++){
				printf("Enter element a%d%d: ",i+1,j+1);
				fflush(stdout);
				scanf("%d",&a[i][j]);
			}
		}
		printf("Entered Matrix\n");
		for(int i=0;i<row;i++){
			for(int j=0;j<col;j++){
				printf("%d ",a[i][j]);
			}
			printf("\n");
		}
		printf("Transpose of Matrix\n");
		for(int i=0;i<col;i++){
			for(int j=0;j<row;j++){
				printf("%d ",a[i][j]);
			}
			printf("\n");
		}
	}
	return 0;
}
