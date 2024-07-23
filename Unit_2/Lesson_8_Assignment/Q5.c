/*
 * Ex.c
 *
 *  Created on: 9 Jul 2024
 *      Author: minak
 */


#include <stdio.h>

struct Semployee{
	char name[30];
	int id;
};

int main(){
	struct Semployee* arr[3];
	struct Semployee emp1={"Alex",1002},emp2={"Mina",1003},emp3={"hamada",1004};
	arr[0]=&emp1;
	arr[1]=&emp2;
	arr[2]=&emp3;
	struct Semployee* (*ptr)[]=&arr;
	printf("Employee Name: %s\n",(*ptr)[0]->name);
	printf("Employee ID : %d",(*ptr)[0]->id);
	return 0;
}


