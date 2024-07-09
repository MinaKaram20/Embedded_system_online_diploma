/*
 * Ex1.c
 *
 *  Created on: 9 Jul 2024
 *      Author: minak
 */

#include <stdio.h>

int main(){
	char str[100];
	printf("Enter a string: ");
	fflush(stdout);
	gets(str);
	int len=0;
	for(int i=0;str[i]!='\0';i++){
			len++;
	}
	printf("Length of string: %d",len);
	return 0;
}
