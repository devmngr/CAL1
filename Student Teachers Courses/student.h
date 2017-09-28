/**
@param  A class responsible for students

*/#pragma once
//! A constructor that takes two parametes "student_number" and "student_first_name"
typedef struct student_t {
	int student_number;
	char * student_first_name;
} student_t;

/*
Param: This method is responsible for creating a student
Takes as argument student_number and first_name
Returns a temp
*/
student_t * create_student(int student_number, char * first_name);

/*
Param: This method is responsible for deleting a student
Takes as argument student_t

*/
void destroy_student(student_t * student);

/*
Param: This method is responsible for printing student information
Takes as argument student_t

*/
void print_student_info(student_t * student);
