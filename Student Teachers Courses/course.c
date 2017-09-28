#include "course.h"
#include <stddef.h>
#include <string.h>

course_t * create_course(int course_number, char * course_name, int semester_number){
	course_t * temp = (course_t *)malloc(sizeof(course_t));
	if (temp == NULL)
		return NULL;
		temp->course_number = course_number;
		temp->course_name = strdup(course_name);
		temp->course_semester_number = semester_number;
		return temp;
}
void destroy_course(course_t * course){
	free(course->course_name);
	free(course->course_semester_number);
	free(course);
}
void print_course_info(course_t * course) {
	printf("\t%d\t%s\t%d\n", course->course_number,course->course_name, course->course_semester_number);
}