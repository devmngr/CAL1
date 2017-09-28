#pragma once

typedef struct student_t {
	int student_id;
	char * student_first_name;
	char * student_last_name;
	char * student_nationality;
	struct student_t * next;
} student_t;

int add_student(student_t * student);											// Return 0 if item added else -1
int remove_student(student_t *student);										// Return 0 if item removed else -1
char print_student_info(student_t* student);						//print the information about one student.
int no_of_students( student_t * student);									//returns the number of students in the list using recursion
struct student_t search_by_studend_id(int * id);					//searches a linked list for a given VIA Student ID.
struct student_t search_by_student_last_name(char * last_name);		//searches a linked list for a given student by last name




