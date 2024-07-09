/*
 * Ex6.c
 *
 *  Created on: 8 Jul 2024
 *      Author: minak
 */

#include <stdio.h>

int main(){
	char letter;
	printf("Enter an alphabet: ");
	fflush(stdout);
	scanf("%c",&letter);
	switch(letter){
	case 'a':
	case 'A':
	case 'e':
	case 'E':
	case 'i':
	case 'I':
	case 'o':
	case 'O':
	case 'u':
	case 'U':
		printf("%c is a vowel",letter);
		break;
	default:
		printf("%c is a consonant",letter);
	}
	return 0;
}
