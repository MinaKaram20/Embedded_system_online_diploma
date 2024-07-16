/*
 * Ex.c
 *
 *  Created on: 9 Jul 2024
 *      Author: minak
 */


#include <stdio.h>
#include <string.h>

struct Sstudent{
	char name[20];
	int roll;
	float marks;
};

int main(){
	struct Sstudent s[10];
	printf("Enter information of students: \n");
	for(int i=0;i<10;i++){
		s[i].roll=i+1;
		printf("\nFor roll number %d\n",i+1);
		fflush(stdout);
		printf("Enter name: ");
		fflush(stdout);
		gets(s[i].name);
		printf("Enter marks: ");
		fflush(stdout);
		scanf("%f",&s[i].marks);
		while(getchar()!='\n');
	}
	printf("\nDisplaying Information\n\n");
	for(int i=0;i<10;i++){
		printf("Information for roll number %d:\n",s[i].roll);
		printf("Name: %s\n",s[i].name);
		printf("Marks: %.2f\n",s[i].marks);
	}
	return 0;
}


