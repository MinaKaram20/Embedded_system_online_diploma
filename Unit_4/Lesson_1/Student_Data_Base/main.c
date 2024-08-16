/*
 * main.c
 *
 *  Created on: 15 Aug 2024
 *      Author: minak
 */

#include <stdio.h>
#include <stdlib.h>
#include "Platform_Types.h"
#define DPRINTF(...) {fflush(stdout); \
		fflush(stdin); \
		printf(__VA_ARGS__); \
		fflush(stdout); \
		fflush(stdin);}

typedef struct {
	uint32_t ID;
	uint8_t name[40];
	float32_t height;
}SData;

struct SStudent {
	SData data;
	struct SStudent* next;
};

//APIs
struct SStudent* my_list;
int Addstudent(struct SStudent** list);
int Delete_Student(struct SStudent** list);
void view_students(struct SStudent** list);
void DeleteAll(struct SStudent** list);
void Nth_Student(struct SStudent** list);
int Length_of_list(struct SStudent** list);
void Nth_Student_from_End(struct SStudent** list);
void Middle_of_List(struct SStudent** list);
void Reverse_List(struct SStudent** list);
//main
int main() {
	uint8_t option;
	while (1) {
		char temp_text[4];
		char exit=0;
		DPRINTF("==================\n");
		DPRINTF("\t choose one of the following options\n\n");
		DPRINTF("1: Addstudent\n");
		DPRINTF("2: Delete_Student\n");
		DPRINTF("3: view_students\n");
		DPRINTF("4: DeleteAll\n");
		DPRINTF("5: Nth_Student\n");
		DPRINTF("6: Length_of_list\n");
		DPRINTF("7: Nth_Student_from_End\n");
		DPRINTF("8: Middle_of_List\n");
		DPRINTF("9: Reverse_List\n");
		DPRINTF("10: Exit\n");
		DPRINTF("Enter Option Number: ");
		gets(temp_text);
		option = atoi(temp_text);
		DPRINTF("==================\n");
		switch (option) {
		case 1:
			Addstudent(&my_list);
			break;
		case 2:
			Delete_Student(&my_list);
			break;
		case 3:
			view_students(&my_list);
			break;
		case 4:
			DeleteAll(&my_list);
			break;
		case 5:
			Nth_Student(&my_list);
			break;
		case 6:
			DPRINTF("Number of Student in List is : %d\n",Length_of_list(&my_list));
			break;
		case 7:
			Nth_Student_from_End(&my_list);
			break;
		case 8:
			Middle_of_List(&my_list);
			break;
		case 9:
			Reverse_List(&my_list);
			break;
		case 10:
			exit=1;
			break;
		default:
			DPRINTF("No Such Option\n");
		}
		if(exit)
			break;
	}
	return 0;
}

//Definition
int Addstudent(struct SStudent** list) {
	struct SStudent* temp = *list;
	char temp_text[8];
	if (!(*list)) {
		*list = (struct SStudent*)malloc(sizeof(struct SStudent));
		temp = *list;
	}
	else {
		while (temp->next)
			temp = temp->next;
		temp->next = (struct SStudent*)malloc(sizeof(struct SStudent));
		temp = temp->next;
	}
	DPRINTF("Enter the ID : ");
	gets(temp_text);
	temp->data.ID = atoi(temp_text);
	DPRINTF("Enter Student Full Name : ");
	gets(temp->data.name);
	DPRINTF("Enter height : ");
	gets(temp_text);
	temp->data.height=atof(temp_text);
	return 1;
}
int Delete_Student(struct SStudent** list) {
	if (!(*list)) {
		DPRINTF("The List is Empty.\n");
		return 0;
	}
	else {
		uint32_t target;
		char temp_text[8];
		DPRINTF("Enter Student ID to be Deleted : ");
		gets(temp_text);
		target = atoi(temp_text);
		struct SStudent* prev, * curr;
		prev = NULL;
		curr = *list;
		while (curr) {
			if (curr->data.ID == target) {
				if (curr == *list) {
					(*list) = (*list)->next;
					free(curr);
					return 1;
				}
				else {
					prev->next = curr->next;
					free(curr);
					return 1;
				}
			}
			else {
				if (!prev) {
					prev = curr;
					curr = curr->next;
				}
				else {
					prev = prev->next;
					curr = curr->next;
				}
			}
		}
		DPRINTF("No Such ID.\n");
		return 0;
	}
}
void view_students(struct SStudent** list) {
	if(!(*list)){
		DPRINTF("The List is Empty.\n");
	}
	else{
		struct SStudent* curr = *list;
		int count = 0;
		while (curr) {
			DPRINTF("Record Number %d\n",++count);
			DPRINTF("ID: %d\n", (int)curr->data.ID);
			DPRINTF("Name: %s\n", curr->data.name);
			DPRINTF("Height: %f\n\n", curr->data.height);
			curr = curr->next;
		}
	}
}
void DeleteAll(struct SStudent** list) {
	struct SStudent* temp, * curr;
	curr = *list;
	while (curr) {
		temp = curr;
		curr = curr->next;
		free(temp);
	}
	*list = NULL;
}
void Nth_Student(struct SStudent** list){
	if(!(*list)){
		DPRINTF("The List is Empty.\n");
	}
	else{
		char temp_text[8];
		DPRINTF("Enter the Student number : ");
		gets(temp_text);
		struct SStudent* curr = *list;
		int count=1;
		while(curr){
			if(count==atoi(temp_text)){
				DPRINTF("Record Number %d\n", count);
				DPRINTF("ID: %d\n", (int)curr->data.ID);
				DPRINTF("Name: %s\n", curr->data.name);
				DPRINTF("Height: %f\n\n", curr->data.height);
				return;
			}
			else{
				count++;
				curr=curr->next;
			}
		}
		DPRINTF("No Such Student.\n");
	}
}
int Length_of_list(struct SStudent** list){
	if(!(*list))
		return 0;
	return 1+Length_of_list(&((*list)->next));
}
void Nth_Student_from_End(struct SStudent** list){
	if(!(*list)){
		DPRINTF("The List is Empty.\n");
	}
	else{
		struct SStudent *slow,*fast;
		char temp_text[8];
		DPRINTF("Enter the Student Node : ");
		gets(temp_text);
		int count=1;
		slow=*list;
		fast=*list;
		while(fast->next){
			if(count>=atoi(temp_text))
				slow=slow->next;
			fast=fast->next;
			count++;
		}
		if(count>=atoi(temp_text)){
			DPRINTF("ID: %d\n", (int)slow->data.ID);
			DPRINTF("Name: %s\n", slow->data.name);
			DPRINTF("Height: %f\n\n", slow->data.height);
		}
		else{
			DPRINTF("No Such Student\n");
		}
	}
}
void Middle_of_List(struct SStudent** list){
	if(!(*list)){
		DPRINTF("The List is Empty.\n");
	}
	else{
		struct SStudent *slow,*fast;
		slow=fast=*list;
		while(fast->next){
			slow=slow->next;
			fast=fast->next;
			if(fast->next)
				fast=fast->next;
		}
		DPRINTF("ID: %d\n", (int)slow->data.ID);
		DPRINTF("Name: %s\n", slow->data.name);
		DPRINTF("Height: %f\n\n", slow->data.height);
	}
}
void Reverse_List(struct SStudent** list){
	if(!(*list)){
		DPRINTF("The List is Empty.\n");
	}
	else{
		struct SStudent *prev,*curr;
		prev=NULL;
		curr=*list;
		while(curr->next){
			struct SStudent* temp = curr;
			curr=curr->next;
			temp->next=prev;
			prev=temp;
		}
		curr->next=prev;
		*list = curr;
	}
}
