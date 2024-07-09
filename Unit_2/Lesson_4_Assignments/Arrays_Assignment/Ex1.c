/*
 * Ex1.c
 *
 *  Created on: 9 Jul 2024
 *      Author: minak
 */

#include <stdio.h>

int main(){
	float a[2][2]={0};
	float b[2][2]={0};
	printf("Enter the elements of 1st matrix \n");
	fflush(stdout);
	for(int i=0;i<2;i++){
		for(int j=0;j<2;j++){
			printf("Enter a%d%d: ",i+1,j+1);
			fflush(stdout);
			scanf("%f",&a[i][j]);
		}
	}
	printf("Enter the elements of 2nd matrix \n");
	fflush(stdout);
	for(int i=0;i<2;i++){
		for(int j=0;j<2;j++){
			printf("Enter b%d%d: ",i+1,j+1);
			fflush(stdout);
			scanf("%f",&b[i][j]);
		}
	}
	float sum[2][2]={0};
	for(int i=0;i<2;i++){
		for(int j=0;j<2;j++){
			sum[i][j] = a[i][j] + b[i][j];
		}
	}
	printf("\nSum Of Matrix:\n");
	fflush(stdout);
	printf("%.1f\t%.1f\n%.1f\t%.1f",sum[0][0],sum[0][1],sum[1][0],sum[1][1]);
	return 0;
}
