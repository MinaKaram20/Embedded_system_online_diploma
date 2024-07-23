/*
 * Ex.c
 *
 *  Created on: 9 Jul 2024
 *      Author: minak
 */


#include <stdio.h>



int main(){
	char str[30];
	printf("Input a string : ");
	fflush(stdout);
	gets(str);
	char* ptr=str;
	while(*ptr!='\0')
		ptr++;
	printf("Reverse of the string is : ");
	ptr--;
	while(ptr!=str){
		printf("%c",*ptr);
		ptr--;
	}
	printf("%c",*ptr);
	return 0;
}


