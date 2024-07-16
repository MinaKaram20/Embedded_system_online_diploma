/*
 * Ex.c
 *
 *  Created on: 9 Jul 2024
 *      Author: minak
 */


#include <stdio.h>
#include <string.h>

struct Sstudent{
	char name[30];
	int roll;
	float marks;
};

int main(){
	struct Sstudent s;
	printf("Enter information of students: \n\n");
	printf("Enter name: ");
	fflush(stdout);
	gets(s.name);
	printf("Enter roll number: ");
	fflush(stdout);
	scanf("%d",&s.roll);
	printf("Enter marks: ");
	fflush(stdout);
	scanf("%f",&s.marks);
	printf("\nDisplaying Information\n");
	printf("name: %s\n",s.name);
	printf("Roll: %d\n",s.roll);
	printf("Marks: %.2f\n",s.marks);
	return 0;
}


