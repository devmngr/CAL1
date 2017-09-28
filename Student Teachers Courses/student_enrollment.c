#include <stdio.h>
#include "student_enrollment.h"

student_enrollment_t * create_student_enrollment(int student_number, int course_number) {
	student_enrollment_t * temp = (student_enrollment_t*)malloc(sizeof(student_enrollment_t));
	if (temp == NULL)
		return NULL;
	temp->student_number = student_number;
	temp->course_number = course_number;
	return temp;

}
void destroy_student_enrollment(student_enrollment_t * enrollment) {
	free(enrollment);
}
void print_student_enrollment_info(student_enrollment_t * student_enrolment) {
	printf("\t%d\t%d\n", student_enrolment->student_number, student_enrolment->course_number);
}