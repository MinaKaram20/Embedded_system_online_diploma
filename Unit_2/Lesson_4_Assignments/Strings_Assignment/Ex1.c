/*
 * Ex1.c
 *
 *  Created on: 9 Jul 2024
 *      Author: minak
 */

#include <stdio.h>
#include <string.h>

int main(){
	char str[100];
	char ch;
	printf("Enter a string: ");
	fflush(stdout);
	gets(str);
	printf("Enter a character to find frequency: ");
	fflush(stdout);
	scanf("%c",&ch);
	int freq=0;
	for(int i=0;str[i]!='\0';i++){
		if(str[i]==ch){
			freq++;
		}
	}
	printf("Frequency of %c = %d",ch,freq);
	return 0;
}
