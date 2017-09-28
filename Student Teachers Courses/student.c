#include "student.h"
#include <stdio.h>
#include <string.h>

student_t * create_student(int student_number, char * first_name){
	student_t * temp = (student_t*)malloc(sizeof(student_t));
	if (temp == NULL)	
		return NULL;
		temp->student_number = student_number;
		temp->student_first_name = strdup(first_name);
		return temp;
}
void destroy_student(student_t *student){
	free(student->student_first_name);
	free(student);
}

void print_student_info(student_t * student){
	printf("\t%d\t%s\n", student->student_number, student->student_first_name);
}