#include "read_write_to_file.h"
#include "linked_list.h"
#include <stdio.h>
#include"student.h"
FILE * std;

student_t  read_students() {
	std = std = fopen("std.txt", "r");
	char buffer[255];
	int student_nr = 0;
	char *student_first_name = NULL;
	student_t * p_student_list = (struct student_t*) malloc(sizeof(struct student_t));
	if (p_student_list != NULL) {
		while (fgets(buffer, sizeof(buffer), std) != NULL) {
			if (fscanf(std, "S %d %s", &student_nr, student_first_name)) {
				//	printf("Student: %d %s\n", student_nr, student_first_name);
				student_t * temp = (struct student_t*) malloc(sizeof(struct student_t));
				if (temp != NULL) {
					temp->student_number = student_nr;
					temp->student_first_name = student_first_name;
					add_item(temp);
					p_student_list = &temp;
				}
			}
		}
	}
	fclose(std);
	return p_student_list;
}
	/*void read_teachers(void * teachers) {

	}
	void read_courses(void *) {
		
	}
	void read_student_enrollments(void *) {


}
void read_teacher_assignments(void *){
}
*/
