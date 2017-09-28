#include "Student.h"
#include <stdio.h>

void main() {

	student_t s1;
	s1.student_id = 1;
	s1.student_first_name = "Bogdan";
	s1.student_last_name = " Mitrache";
	s1.student_nationality = "Romanian";
	print_student_info(&s1);
	
	student_t s2;
	s2.student_id = 2;
	s2.student_first_name = "Denisa";
	s2.student_last_name = " Farcas";
	s2.student_nationality = "Danish";
	print_student_info(&s2);
	student_t s3;
	s3.student_id = 3;
	s3.student_first_name = "Roxana";
	s3.student_last_name = " Florina";
	s3.student_nationality = "German";
	print_student_info(&s3);


	printf("%d\n",	add_student(&s1));
	add_student(&s2);
	add_student(&s3);
	//printf("%d", no_of_students(&s1));
	//print_student_info(s1.next);
	printf("%s\n", s1.student_first_name);

}