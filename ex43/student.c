#include "Student.h"
#include <stdio.h>

static student_t * head = NULL;

/*Adds an element as the head of the linked list structure*/
int add_student(student_t * student) {
	
	student_t * temp = (struct student_t*) malloc(sizeof(struct student_t));
	if (temp == NULL){
		return -1;
	}
	temp->student_id = student->student_id;
	temp->student_first_name = student->student_first_name;
	temp->student_last_name = student->student_last_name;
	temp->student_nationality = student->student_nationality;
	temp->next = head;
	head = temp;
	return 0;
}


/*removes the node*/
int remove_student(student_t *student) {
	student_t * current = head;
	student_t * previous = &head;
	while (current != NULL) {
		if (current->student_id == student->student_id) {
			if (previous = &head){
				previous = current->next;
				free(current);
			}
			else {
				previous->next = current->next;
				free(current);
			}
		}
		previous = current;
		current = current->next;
	}
	return -1;
}
char print_student_info(student_t* student){
	printf("%d\t %s\t %s\t %s\n", student->student_id, student->student_first_name, student->student_last_name, student->student_nationality);
}


int no_of_students(student_t * student) {
	return no_of_students(student->next);

}
struct student_t search_by_studend_id(int * id) {





}
struct student_t search_by_student_last_name(char * last_name) {






}