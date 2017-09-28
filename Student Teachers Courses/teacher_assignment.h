#pragma once
/*
@param  A class responsible for Teacher Enrollments

*/

typedef struct teacher_assignment_t {
	int teacher_number;
	int course_number;
}teacher_assignment_t;
/*
@param A function that creates a new teacher assigment
Takes as argument teacher_assignment_t and course_number
return new teacher assigment
*/
teacher_assignment_t * create_teacher_assignment(int teacher_number, int course_number);
/*
@param A function that deletes teacher assigment
Takes as argument teacher_assignment_t
*/
void destroy_teacher_assignment(teacher_assignment_t * assignment);
/*
@param A function that prints out teacher assisgment information
Takes as argument teacher_assignment_t
*/
void print_teacher_assignment_info(teacher_assignment_t * teacher_assignment);