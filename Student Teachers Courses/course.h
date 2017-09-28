#pragma once/*
@param  A class responsible for courses

*/

/*
//!A structure declaration for course_t variable

*/
typedef struct course_t {
	int course_number;
	char * course_name;
	int course_semester_number;
}  course_t;


/*
Param: This method is responsible for creating a course
Takes as argument course_number ,course_name and semester_number
Returns a temp

*/
course_t * create_course(int course_number, char * course_name, int semester_number);

/*
Param: This method is responsible for deleting a course
Takes as argument course

*/
void destroy_course(course_t * course);

/*
Param: This method is responsible for printing course information
Takes as argument student_t

*/
void print_course_info(course_t * course);