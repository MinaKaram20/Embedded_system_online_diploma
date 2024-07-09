/*
 * Ex6.c
 *
 *  Created on: 8 Jul 2024
 *      Author: minak
 */

#include <stdio.h>

int main(){
	char c;
	printf("Enter a character: ");
	fflush(stdout);
	scanf("%c",&c);
	if(c>='A' && c<='z'){
		printf("%c is an alphabet",c);
	}
	else{
		printf("%c is not an alphabet",c);
	}
	return 0;
}
