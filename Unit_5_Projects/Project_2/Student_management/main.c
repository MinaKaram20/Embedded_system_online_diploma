/*
 * main.c
 *
 *  Created on: 27 Aug 2024
 *      Author: Mina Karam
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "FIFO.h"
#define DPRINTF(...) {fflush(stdout); \
		fflush(stdin); \
		printf(__VA_ARGS__); \
		fflush(stdout); \
		fflush(stdin);}

element_type st[50]; //Initialize the list
fifo_buf_t my_queue; // Initialize the queue


//APIs
void add_student_file();
void add_student_manually();
void find_rl();
void find_fn();
void find_c();
void tot_s();
void del_s();
void up_s();
void show_s();

int main(){
	fifo_init(&my_queue,st,50);
	uint8_t option;
	DPRINTF("Welcome to the Student Management System\n");
	while(1){
		char temp_text[4];
		char exit=0;
		DPRINTF("Choose The Task that you want  to perform\n");
		DPRINTF("1. Add the Student Details Manually\n");
		DPRINTF("2. Add the Student Details From Text File\n");
		DPRINTF("3. Find the Student Details By Roll Number\n");
		DPRINTF("4. Find the Student Details By First Name\n");
		DPRINTF("5. Find the Student Details By Course ID\n");
		DPRINTF("6. Find the Total number of Students\n");
		DPRINTF("7. Delete the Student Details By Roll Number\n");
		DPRINTF("8. Update the Student Details By Roll Number\n");
		DPRINTF("9. Show all information\n");
		DPRINTF("10. To Exit\n");
		DPRINTF("Enter your choice to perform the task: ");
		gets(temp_text);
		option = atoi(temp_text);
		DPRINTF("------------------------\n");
		switch (option) {
		case 1:
			DPRINTF("Add the Student Details\n");
			DPRINTF("------------------------\n");
			add_student_manually();
			tot_s();
			break;
		case 2:
			add_student_file();
			tot_s();
			break;
		case 3:
			find_rl();
			break;
		case 4:
			find_fn();
			break;
		case 5:
			find_c();
			break;
		case 6:
			tot_s();
			break;
		case 7:
			del_s();
			break;
		case 8:
			up_s();
			break;
		case 9:
			show_s();
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
void add_student_file(){
	element_type temp;
	FILE *file;
	char file_name[]="data.txt";//name of file

	file=fopen(file_name,"r");//give access to only read the file

	if(file==NULL){
		DPRINTF("Could not open the file\n");
		DPRINTF("------------------------\n");
	}
	else{
		while(fscanf(file,"%d %s %s %f %d %d %d %d %d",&temp.roll,temp.fname,temp.lname,&temp.GPA,
				&temp.cid[0],&temp.cid[1],&temp.cid[2],&temp.cid[3],&temp.cid[4])!=EOF){
			int taken=0;
			for(int i=0;i<my_queue.count;i++){
				if(st[i].roll==temp.roll)//check if the roll number is taken
				{
					DPRINTF("[ERROR] Roll Number %d is already taken\n",temp.roll);
					taken=1;
					break;
				}
			}
			if(taken==0){
				if(fifo_enqueue(&my_queue,temp) == FIFO_no_error){
					DPRINTF("[INFO] Roll Number %d saved Successfully\n",temp.roll);
				}
				else{
					DPRINTF("[ERROR] Failed to save Roll Number %d Details\n",temp.roll);
				}
			}
		}
		DPRINTF("------------------------\n");
	}
}
void add_student_manually(){
	element_type temp;
	char ch[15];
	DPRINTF("Enter the Roll Number: ");
	gets(ch);
	for(int i=0;i<my_queue.count;i++){
		if(st[i].roll==atoi(ch))//check if the roll number is taken
		{
			DPRINTF("[ERROR] Roll Number %d is already taken\n",atoi(ch));
			DPRINTF("------------------------\n");
			return;
		}
	}
	temp.roll=atoi(ch);
	DPRINTF("Enter the first name of student: ");
	gets(temp.fname);
	DPRINTF("Enter the last name of student: ");
	gets(temp.lname);
	DPRINTF("Enter the GPA of student: ");
	gets(ch);
	temp.GPA=atof(ch);
	DPRINTF("Enter the ID of each course\n");
	DPRINTF("Course 1 ID: ");
	gets(ch);
	temp.cid[0]=atoi(ch);
	DPRINTF("Course 2 ID: ");
	gets(ch);
	temp.cid[1]=atoi(ch);
	DPRINTF("Course 3 ID: ");
	gets(ch);
	temp.cid[2]=atoi(ch);
	DPRINTF("Course 4 ID: ");
	gets(ch);
	temp.cid[3]=atoi(ch);
	DPRINTF("Course 5 ID: ");
	gets(ch);
	temp.cid[4]=atoi(ch);
	if(fifo_enqueue(&my_queue,temp) == FIFO_no_error){
		DPRINTF("[INFO] Student Details is added Successfully\n");
	}
	else{
		DPRINTF("[ERROR] Failed to add Student Details\n");
	}
	DPRINTF("------------------------\n");
}
void find_rl(){
	int roll;
	DPRINTF("Enter the Roll Number of Student: ");
	scanf("%d",&roll);
	for(int i=0;i<my_queue.count;i++){
		if(st[i].roll==roll){
			DPRINTF("The Student Details are\n");
			DPRINTF("Student First name is %s\n",st[i].fname);
			DPRINTF("Student Last name is %s\n",st[i].lname);
			DPRINTF("Student GPA is %.2f\n",st[i].GPA);
			DPRINTF("Course 1 ID is %d\n",st[i].cid[0]);
			DPRINTF("Course 2 ID is %d\n",st[i].cid[1]);
			DPRINTF("Course 3 ID is %d\n",st[i].cid[2]);
			DPRINTF("Course 4 ID is %d\n",st[i].cid[3]);
			DPRINTF("Course 5 ID is %d\n",st[i].cid[4]);
			DPRINTF("------------------------\n");
			return;
		}
	}
	DPRINTF("[ERROR] Roll Number %d not found\n",roll);
	DPRINTF("------------------------\n");
}
void find_fn(){
	char name[10];
	DPRINTF("Enter the First Name of the Student: ");
	gets(name);
	int found=0;
	for(int i=0;i<my_queue.count;i++){
		if(strcasecmp(st[i].fname,name)==0){
			DPRINTF("The Student Details are\n");
			DPRINTF("Student First name is %s\n",st[i].fname);
			DPRINTF("Student Last name is %s\n",st[i].lname);
			DPRINTF("Student Roll Number is %d\n",st[i].roll);
			DPRINTF("Student GPA is %.2f\n",st[i].GPA);
			DPRINTF("Course 1 ID is %d\n",st[i].cid[0]);
			DPRINTF("Course 2 ID is %d\n",st[i].cid[1]);
			DPRINTF("Course 3 ID is %d\n",st[i].cid[2]);
			DPRINTF("Course 4 ID is %d\n",st[i].cid[3]);
			DPRINTF("Course 5 ID is %d\n",st[i].cid[4]);
			DPRINTF("------------------------\n");
			found=1;
		}
	}
	if(found==0){
		DPRINTF("[ERROR] First Name %s not found\n",name);
		DPRINTF("------------------------\n");
	}
}
void find_c(){
	int ID;
	DPRINTF("Enter the Course ID: ");
	scanf("%d",&ID);
	int found=0;
	int count=0;
	for(int i=0;i<my_queue.count;i++){
		for(int j=0;j<5;j++){
			if(st[i].cid[j]==ID){
				DPRINTF("The Student Details are\n");
				DPRINTF("Student First name is %s\n",st[i].fname);
				DPRINTF("Student Last name is %s\n",st[i].lname);
				DPRINTF("Student Roll Number is %d\n",st[i].roll);
				DPRINTF("Student GPA is %.2f\n",st[i].GPA);
				DPRINTF("------------------------\n");
				found=1;
				count++;
				break;
			}
		}
	}
	if(found==0){
		DPRINTF("[ERROR] Course ID %d not found\n",ID);
		DPRINTF("------------------------\n");
	}
	else{
		DPRINTF("[INFO] Total Number of Students Enrolled: %d\n",count);
		DPRINTF("------------------------\n");
	}
}
void tot_s(){
	DPRINTF("[INFO] The Total Number of Students is %d\n",my_queue.count);
	DPRINTF("[INFO] You can add up to %d Students\n",my_queue.length);
	DPRINTF("[INFO] You can add %d more Students\n",my_queue.length - my_queue.count);
	DPRINTF("------------------------\n");
}
void del_s(){
	int roll;
	int found=0;
	DPRINTF("Enter the Roll Number which you want to delete: ");
	scanf("%d",&roll);
	for(int i=0;i<my_queue.count;i++){
		if(st[i].roll==roll){
			for(int j = i;j < my_queue.count - 1;j++){
				st[j]=st[j+1];//push all data to take the empty space
			}
			my_queue.count--;//remove one element
			my_queue.last=&st[my_queue.count];//make the last pointer of the queue to look to the next element will be pushed
			found=1;
			break;
		}
	}
	if(found==1){
		DPRINTF("[INFO] The Roll Number is removed Successfully\n");
		DPRINTF("------------------------\n");
	}
	else{
		DPRINTF("[ERROR] Roll Number %d not found\n",roll);
		DPRINTF("------------------------\n");
	}
}
void up_s(){
	int roll;
	DPRINTF("Enter the Roll Number to update the entry: ");
	scanf("%d",&roll);
	int found=0;
	for(int i=0;i<my_queue.count;i++){
		if(st[i].roll==roll){
			int ro_n;//for new roll
			int taken=0;//to check if the new roll is taken or not
			char ch[10];//for new courses
			found=1;
			int option;
			DPRINTF("Choose what option you want to update: ");
			DPRINTF("1. First Name\n");
			DPRINTF("2. Last Name\n");
			DPRINTF("3. Roll Number\n");
			DPRINTF("4. GPA\n");
			DPRINTF("5. Courses\n");
			DPRINTF("Your option: \n");
			scanf("%d",&option);
			switch(option){
			case 1:
				DPRINTF("Enter the new First Name: ");
				gets(st[i].fname);
				DPRINTF("[INFO] Updated Successfully\n");
				break;
			case 2:
				DPRINTF("Enter the new Last Name: ");
				gets(st[i].lname);
				DPRINTF("[INFO] Updated Successfully\n");
				break;
			case 3:
				DPRINTF("Enter the new Roll Number: ");
				scanf("%d",&ro_n);
				//Must check first if the new roll is taken or not
				for(int j=0;j<my_queue.count;j++){
					if(st[j].roll==ro_n){
						DPRINTF("[ERROR] The New Roll Number is already taken\n");
						taken=1;
						break;
					}
				}
				if(taken==1){
					DPRINTF("[ERROR] Failed to Update\n");
				}
				else{
					st[i].roll=ro_n;
					DPRINTF("[INFO] Updated Successfully\n");
				}
				break;
			case 4:
				DPRINTF("Enter the new GPA: ");
				scanf("%f",&st[i].GPA);
				DPRINTF("[INFO] Updated Successfully\n");
				break;
			case 5:
				DPRINTF("Enter the new Courses:\n");
				DPRINTF("Course 1 ID: ");
				gets(ch);
				st[i].cid[0]=atoi(ch);
				DPRINTF("Course 2 ID: ");
				gets(ch);
				st[i].cid[1]=atoi(ch);
				DPRINTF("Course 3 ID: ");
				gets(ch);
				st[i].cid[2]=atoi(ch);
				DPRINTF("Course 4 ID: ");
				gets(ch);
				st[i].cid[3]=atoi(ch);
				DPRINTF("Course 5 ID: ");
				gets(ch);
				st[i].cid[4]=atoi(ch);
				DPRINTF("[INFO] Updated Successfully\n");
				break;
			default:
				DPRINTF("No Such Option\n");
			}
			DPRINTF("------------------------\n");
			break;
		}
	}
	if(found==0){
		DPRINTF("[ERROR] Roll Number %d not found\n",roll);
		DPRINTF("------------------------\n");
	}
}
void show_s(){
	if(fifo_is_empty(&my_queue)==FIFO_empty){//check if the queue is empty
		DPRINTF("[ERROR] No Students to Show\n");
		DPRINTF("------------------------\n");
	}
	else{
		for(int i=0;i<my_queue.count;i++){
			DPRINTF("Student First Name: %s\n",st[i].fname);
			DPRINTF("Student Last Name: %s\n",st[i].lname);
			DPRINTF("Student Roll Number: %d\n",st[i].roll);
			DPRINTF("Student GPA Number: %.2f\n",st[i].GPA);
			DPRINTF("Course 1 ID is %d\n",st[i].cid[0]);
			DPRINTF("Course 2 ID is %d\n",st[i].cid[1]);
			DPRINTF("Course 3 ID is %d\n",st[i].cid[2]);
			DPRINTF("Course 4 ID is %d\n",st[i].cid[3]);
			DPRINTF("Course 5 ID is %d\n",st[i].cid[4]);
			DPRINTF("------------------------\n");
		}
	}
}
