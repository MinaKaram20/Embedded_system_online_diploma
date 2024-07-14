/*
 * Ex.c
 *
 *  Created on: 9 Jul 2024
 *      Author: minak
 */


#include <stdio.h>
#include <string.h>

void Reverse_str(char a[],int len,int loc);

int main(){
	char str[100];
	printf("Enter a sentence: ");
	fflush(stdout);
	gets(str);
	Reverse_str(str,strlen(str),0);
	printf("%s",str);
	return 0;
}

void Reverse_str(char a[],int len,int loc){
	if(len<=loc){
		return;
	}
	else{
		char temp=a[len-1];
		a[len-1]=a[loc];
		a[loc]=temp;
		Reverse_str(a,len-1,loc+1);
	}
}
