/*
 * Ex.c
 *
 *  Created on: 9 Jul 2024
 *      Author: minak
 */


#include <stdio.h>



int main(){
	char alpha[27];
	for(int i=0;i<26;i++){
		alpha[i]='A'+i;
	}
	char* ptr=alpha;
	printf("The Alphabets are :\n");
	while(*ptr!='\0'){
		printf("%c ",*ptr);
		ptr++;
	}
	return 0;
}


