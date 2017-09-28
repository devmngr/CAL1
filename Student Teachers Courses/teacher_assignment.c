#include <stdio.h>
#include "teacher_assignment.h"

teacher_assignment_t * create_teacher_assignment(int teacher_number, int course_number) {
	teacher_assignment_t * temp = (teacher_assignment_t*)malloc(sizeof(teacher_assignment_t));
	if (temp == NULL)
		return NULL;
	temp->course_number = course_number;
	temp->teacher_number = teacher_number;
	return temp;
}
void destroy_teacher_assignment(teacher_assignment_t * assignment) {
	free(assignment);
}
void print_teacher_assignment_info(teacher_assignment_t * teacher_assignment) {
	printf("\t%d\t%d\n", teacher_assignment->teacher_number, teacher_assignment->course_number);
}