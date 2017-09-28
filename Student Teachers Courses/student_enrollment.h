#pragma once
/*Param :
A class responsible for Student Enrollments
*/
typedef struct student_enrollment_t {
	int student_number;
	int course_number;
} student_enrollment_t;


/*
A function that creates a studentEnrollment
Takes as argument student_number and course_number
@return new student enrollment
*/
student_enrollment_t * create_student_enrollment(int student_number, int course_number);
/*
A function that deletes student enrollment
Takes as argument student_number
*/
void destroy_student_enrollment(student_enrollment_t * enrollment);
/*
A function that prints out a specific student enrollment
Takes as argument student_number
*/
void print_student_enrollment_info(student_enrollment_t * student_enrolment);