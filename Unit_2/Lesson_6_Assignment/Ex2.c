/*
 * Ex.c
 *
 *  Created on: 9 Jul 2024
 *      Author: minak
 */


#include <stdio.h>
#include <string.h>

struct Sdistance{
	int feet;
	float inch;
};

void add(struct Sdistance a,struct Sdistance b){
	float val=a.inch+b.inch;
	int feet;
	float inch;
	if(val>=12){
		feet=val/12;
		inch=(val/12-feet)*12;
		feet+=a.feet+b.feet;
	}
	else{
		feet=a.feet+b.feet;
		inch=val;
	}
	printf("Sum of distances=%d'%.2f\"",feet,inch);
}

int main(){
	struct Sdistance d1,d2;
	printf("Enter information for 1st distance: \n");
	printf("Enter feet: ");
	fflush(stdout);
	scanf("%d",&d1.feet);
	printf("Enter inch: ");
	fflush(stdout);
	scanf("%f",&d1.inch);
	printf("\nEnter information for 2nd distance: \n");
	printf("Enter feet: ");
	fflush(stdout);
	scanf("%d",&d2.feet);
	printf("Enter inch: ");
	fflush(stdout);
	scanf("%f",&d2.inch);
	add(d1,d2);
	return 0;
}


