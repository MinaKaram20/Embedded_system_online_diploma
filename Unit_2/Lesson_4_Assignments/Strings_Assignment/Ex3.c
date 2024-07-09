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
	char revstr[100];
	for(int i=len-1;i>=0;i--){
		revstr[len-i-1]=str[i];
	}
	revstr[len]=0;
	printf("Reverse string is : %s",revstr);
	return 0;
}
