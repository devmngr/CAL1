#include<stdio.h>
#include "teacher.h"
#include <string.h>

teacher_t * create_teacher(int teacher_number, char * first_name) {
	teacher_t * temp = (teacher_t*)malloc(sizeof(teacher_t));
	if (temp == NULL)
		return NULL;
	temp->teacher_number = teacher_number;
	temp->teacher_first_name = strdup(first_name);
	return temp;
}
void destroy_teacher(teacher_t * teacher){
	free(teacher->teacher_first_name);
	free(teacher);
}
void print_teacher_info(teacher_t * teacher) {
	printf("\t%d\t%s\n", teacher->teacher_number, teacher->teacher_first_name);
}