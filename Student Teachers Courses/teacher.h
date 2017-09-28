#pragma once
/*
@param: A class responsible for Teacher
*/
typedef struct teacher_t {
	int teacher_number;
	char * teacher_first_name;
}  teacher_t;

/*
@param Afunction that creates a teacher
Takes as argument teacher_number and first_name
@return new teacher
*/
teacher_t * create_teacher(int teacher_number, char * first_name);
/*
@param
A function that deletes teacher
Takes as argument teacher_t
*/
void destroy_teacher(teacher_t * teacher);
/*
@param
A function that prints out teacher
Takes as argument teacher_t
*/
void print_teacher_info(teacher_t * teacher);