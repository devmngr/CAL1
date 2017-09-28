#include "linked_list.h"
#include <stdio.h>
#include "student.h"
#include "database.h"


void main() {
	initialize_lists();
	read_from_file();
	

	print_all_students();
	print_all_teachers();
	print_all_courses();
	print_all_assignments();
	print_all_enrollments();

}