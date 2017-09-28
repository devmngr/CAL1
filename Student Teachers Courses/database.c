#include <stdio.h>
#include "student_enrollment.h"
#include"teacher_assignment.h"
#include"database.h"
#include <stddef.h>
#include <stdlib.h>

//static  char * file_name = "Input.txt";
static list_p students;
static list_p teachers;
static list_p courses;
static list_p teacher_assignments;
static list_p student_enrollments;
static list_p iterator;


void initialize_lists() {
	list_create(&students);
	list_create(&teachers);
	list_create(&courses);
	list_create(&student_enrollments);
	list_create(&teacher_assignments);
	list_create(&iterator);
}
void read_from_file() {
	FILE * input;
	input = fopen("Input.txt", "r");
	char buffer[255];
	int id = 0;
	int id2 = 0;
	int semester = 0;

	while (!feof(input)) {
		if (fscanf(input, "S %d %s\n", &id, buffer) == 2)
			add_student(id, buffer);
		else if (fscanf(input, "T %d %s\n", &id, buffer) == 2)
			add_teacher(id, buffer);
		else if (fscanf(input, "C %d %s %d\n", &id, buffer, &semester) == 3)
			add_course(id, buffer, semester);
		else if (fscanf(input, "E %d %d\n", &id, &id2) == 2)
			add_student_enrollment(id, id2);
		else if (fscanf(input, "A %d %d\n", &id, &id2) == 2)
			add_teacher_assignment(id, id2);
		else
			fgets(buffer, sizeof(buffer), input);
	}
	fclose(input);
}
//ADD
int add_student(int student_number, char * first_name) {
	student_t * temp = find_student_by_student_number(student_number);
	if (temp == NULL){
		temp = create_student(student_number, first_name);
		if (temp == NULL){
			printf("ERROR: Not enough memmory to add a new Student!\n");
			return -1;
		}
		else
			return add_item(&students, temp);
	}
	else 
		printf("Student already exists!\n");
		return -2;
	
}
int add_teacher(int teacher_number, char * first_name) {
	teacher_t * temp = find_teacher_by_teacher_number(teacher_number);
	if (temp == NULL){
		temp = create_teacher(teacher_number, first_name);
		if (temp == NULL){
			printf("ERROR: Not enough memmory to add a new Teacher!\n");
			return -1;
		}
		else
			return add_item(&teachers, temp);
	}
	else 
		printf("Teacher already exists!\n");
		return -2;
}
int add_course(int course_number, char * name, int semester_number) {
	course_t * temp = find_course_by_course_number(course_number);
	if (temp == NULL) {
		temp = create_teacher(course_number, name, semester_number);
		if (temp == NULL) {
			printf("ERROR: Not enough memmory to add a new Course!\n");
			return -1;
		}
		else
			return add_item(&courses, temp);
	}
	else
		printf("Course already exists!\n");
	return -2;
}
int add_student_enrollment(int student_number, int course_number) {
	student_t * student = find_student_by_student_number(student_number);
	course_t * course = find_course_by_course_number(course_number);
	if (student != NULL && course != NULL) {
		student_enrollment_t * temp = find_enrollment(student_number, course_number);
		if (temp == NULL) {
			temp = create_student_enrollment(student_number, course_number);
			if (temp == NULL) {
				printf("ERROR: Not enough memmory to add a new Enrollment!\n");
				return -1;
			}
			else
				return add_item(&student_enrollments, temp);
		}
		else
			printf("Enrollment already exists!\n");
		return -2;
	}
	else if(student ==NULL || course==NULL)
		printf("ERROR: Student or/and Course Not Valid\n");
	return -3;
	
}
int add_teacher_assignment( int teacher_number, int course_number) {
	teacher_t * teacher = find_teacher_by_teacher_number(teacher_number);
	course_t * course = find_course_by_course_number(course_number);
	if(teacher !=NULL && course != NULL){
		teacher_assignment_t * temp = find_assignment(teacher_number,course_number);
	if (temp == NULL) {
		temp = create_teacher_assignment(teacher_number, course_number);
		if (temp == NULL) {
			printf("ERROR: Not enough memmory to add a new Enrollment!\n");
			return -1;
		}
		else
			return add_item(&teacher_assignments, temp);
	}
	else
		printf("Enrollment already exists!\n");
	return -2;
}
	else if (teacher == NULL || course == NULL)
		printf("ERROR: Teacher or/and Course Not Valid\n");
		return -3;
}

//REMOVE
int remove_student(int student_number) {
	student_t  * temp= find_student_by_student_number(student_number);
	if (temp != NULL) {
		remove_enrollment_of_student(student_number);
		if (remove_item(&students, temp) == 0) {
			destroy_student(temp);
			return 0;
		}
	}
	return 1;
}
int remove_teacher(int teacher_number) {
	teacher_t  * temp = find_teacher_by_teacher_number(teacher_number);
	if (temp != NULL) {
		remove_assignment_of_teacher(temp->teacher_number);
		if (remove_item(&teachers, temp) == 0) {
			destroy_teacher(temp);
			return 0;
		}
	}
	return 1;
}
int remove_course(int course_number) {
	course_t  * temp = find_course_by_course_number(course_number);
	if (temp != NULL) {
		remove_enrollment_of_course(course_number);
		remove_assignment_of_course(course_number);
		if (remove_item(&courses, temp) == 0) {
			destroy_course(temp);
			return 0;
		}
	}
	return 1;
}
int remove_enrollment_of_student(int student_number) {
	student_enrollment_t  * temp = find_enrollment_of_student(student_number);
	if (temp != NULL) {
		if (remove_item(&student_enrollments, temp) == 0) {
			destroy_student_enrollment(temp);
			return 0;
		}
	}
	return 1;
}
int remove_enrollment_of_course(int course_number) {
	student_enrollment_t  * temp = find_enrollment_of_course(course_number);
	if (temp != NULL) {
		if (remove_item(&student_enrollments, temp) == 0) {
			destroy_student_enrollment(temp);
			return 0;
		}
	}
	return 1;

}
int remove_assignment_of_teacher(int teacher_number) {
	teacher_assignment_t  * temp = find_assignment_of_teacher(teacher_number);
	if (temp != NULL) {
		if (remove_item(&teacher_assignments, temp) == 0) {
			destroy_teacher_assignment(temp);
			return 0;
		}
	}
	return 1;
}
int remove_assignment_of_course(int course_number) {
	teacher_assignment_t  * temp = find_assignment_of_course(course_number);
	if (temp != NULL) {
		if (remove_item(&teacher_assignments, temp) == 0) {
			destroy_teacher_assignment(temp);
			return 0;
		}
	}
	return 1;
}


//FIND
student_t * find_student_by_student_number(int student_number) {
	iterator = get_iterator(&students);
	student_t * temp;
	while (has_next(&iterator))
	{
		temp = (student_t *)next(&iterator);
		if (temp->student_number == student_number)
		{
			return temp;
		}
	}
	return NULL;
}
teacher_t * find_teacher_by_teacher_number(int teacher_number) {
	iterator = get_iterator(&teachers);
	teacher_t * temp;
	while (has_next(&iterator))
	{
		temp = (teacher_t *)next(&iterator);
		if (temp->teacher_number == teacher_number)
		{
			return temp;
		}
	}
	return NULL;
}
course_t  * find_course_by_course_number(int course_number) {
	iterator = get_iterator(&courses);
	course_t * temp;
	while (has_next(&iterator))
	{
		temp = (course_t *)next(&iterator);
		if (temp->course_number == course_number)
		{
			return temp;
		}
	}
	return NULL;
}
student_enrollment_t * find_enrollment(int student_number, int course_number) {
	iterator = get_iterator(&student_enrollments);
	student_enrollment_t * temp;
	while (has_next(&iterator))
	{
		temp = (student_enrollment_t *)next(&iterator);
		if (temp->student_number == student_number && temp->course_number == course_number)
		{
			return temp;
		}
	}
	return NULL;
}
student_enrollment_t * find_enrollment_of_student(int student_number) {
	iterator = get_iterator(&student_enrollments);
	student_enrollment_t * temp;
	while (has_next(&iterator))
	{
		temp = (student_enrollment_t *)next(&iterator);
		if (temp->student_number == student_number)
		{
			return temp;
		}
	}
	return NULL;

}
student_enrollment_t * find_enrollment_of_course(int course_number) {
	iterator = get_iterator(&student_enrollments);
	student_enrollment_t * temp;
	while (has_next(&iterator))
	{
		temp = (student_enrollment_t *)next(&iterator);
		if (temp->course_number == course_number)
		{
			return temp;
		}
	}
	return NULL;
}
teacher_assignment_t * find_assignment(int teacher_number, int course_number) {
	iterator = get_iterator(&teacher_assignments);
	teacher_assignment_t * temp;
	while (has_next(&iterator))
	{
		temp  = (teacher_assignment_t *)next(&iterator);
		if (temp->course_number == course_number && temp->teacher_number == teacher_number)
		{
			return temp;
		}
	}
	return NULL;
}
teacher_assignment_t * find_assignment_of_teacher(int teacher_number) {
	iterator = get_iterator(&teacher_assignments);
	teacher_assignment_t * temp;
	while (has_next(&iterator))
	{
		temp = (teacher_assignment_t *)next(&iterator);
		if (temp->teacher_number == teacher_number)
		{
			return temp;
		}
	}
	return NULL;

}
teacher_assignment_t * find_assignment_of_course(int course_number) {

	iterator = get_iterator(&teacher_assignments);
	teacher_assignment_t * temp;
	while (has_next(&iterator))
	{
		temp = (teacher_assignment_t *)next(&iterator);
		if (temp->course_number == course_number)
		{
			return temp;
		}
	}
	return NULL;

}

//NUMBER OF...
int no_of_students() {
	return no_of_items(&students);
}
int no_of_teachers() {
	return no_of_items(&teachers);
}
int no_of_courses() {
	return no_of_items(&courses);
}
int no_of_student_enrollments() {
	return no_of_items(&student_enrollments);
}
int no_of_teacher_assignments() {
	return no_of_items(&teacher_assignments);
}

//PRINT
void print_all_students()
{
	printf("Students\n");
	iterator = get_iterator(&students);
	student_t * temp;
	while (has_next(&iterator))
	{
		temp = (student_t *)next(&iterator);
		print_student_info(temp);
	}
}
void print_all_teachers() {
	printf("Teachers\n");
	iterator = get_iterator(&teachers);
	teacher_t * temp;
	while (has_next(&iterator))
	{
		temp = (teacher_t *)next(&iterator);
		print_teacher_info(temp);
	}
}
void print_all_courses() {
	printf("Courses\n");
	iterator = get_iterator(&courses);
	course_t * temp;
	while (has_next(&iterator))
	{
		temp = (course_t *)next(&iterator);
		print_course_info(temp);
	}
}
void print_all_enrollments() {

	printf("Student Enrollments\n");
	iterator = get_iterator(&student_enrollments);
	student_enrollment_t * temp;
	while (has_next(&iterator))
	{
		temp = (student_enrollment_t *)next(&iterator);
		print_student_enrollment_info(temp);
	}
}
void print_all_assignments() {

		printf("Teacher Assignments\n");
		iterator = get_iterator(&teacher_assignments);
		teacher_assignment_t * temp;
		while (has_next(&iterator))
		{
			temp = (teacher_assignment_t *)next(&iterator);
			print_teacher_assignment_info(temp);
		}
}


//Destroy Lists
void destroy_students_list() {
	list_destroy(&students);
	printf("All students were deleted !!!\n");
}
void destroy_teachers_list() {
	list_destroy(&teachers);
	printf("All teachers were deleted !!!\n");
}
void destroy_courses_list() {
	list_destroy(&courses);
	printf("All courses were deleted !!!\n");
}
void destroy_enrollments_list() {
	list_destroy(&student_enrollments);
	printf("All enrollments were deleted !!!\n");
}
void destroy_assignments_list() {
	list_destroy(&teacher_assignments);
	printf("All assignments were deleted !!!\n");
}
void destroy_all_lists() {
	destroy_students_list();
	destroy_teachers_list();
	destroy_courses_list();
	destroy_enrollments_list();
	destroy_assignments_list();
}


void courses_of_student(int student_number) {

	iterator = get_iterator(&student_enrollments);
	student_t * student = find_student_by_student_number(student_number);
	student_enrollment_t * temp;
	course_t * course;
	if (student != NULL) {
		printf("Courses of student:\t%d\t%s\n", student->student_number, student->student_first_name);
		while (has_next(&iterator)) {
			temp = (student_enrollment_t *)next(&iterator);
			if (temp->student_number == student_number) {
				course = find_course_by_course_number(temp->course_number);
				printf("Course Number: %d\t Course Name: %s\t Semester: %d\t\n", course->course_number, course->course_name, course->course_semester_number);
			}
		}
	}
	else
		printf("ERROR: Student does not exist or does not have any course assigned\n");

}
void courses_of_teacher(int teacher_number) {
	iterator = get_iterator(&teacher_assignments);
	teacher_t * teacher = find_teacher_by_teacher_number(teacher_number);
	teacher_assignment_t * temp;
	course_t * course;
	if (teacher != NULL) {
		printf("Courses of teachers:\t%d\t%s\n", teacher->teacher_number, teacher->teacher_number);
		while (has_next(&iterator)) {
			temp = (teacher_assignment_t *)next(&iterator);
			if (temp->teacher_number == teacher_number) {
				course = find_course_by_course_number(temp->course_number);
				printf("Course Number: %d\t Course Name: %s\t Semester: %d\t\n", course->course_number, course->course_name, course->course_semester_number);
			}
		}
	}
	else
		printf("ERROR: Teacher does not exist or does not have any course assigned\n");

}
void students_of_course(int course_number){

	iterator = get_iterator(&student_enrollments);
	student_t * student;
	student_enrollment_t * temp;
	course_t * course = find_course_by_course_number(course_number);
	if (course != NULL) {
		printf("Students in course:\t%d\t%s\t%d\n",course->course_number, course->course_name, course->course_semester_number);
		while (has_next(&iterator)) {
			temp = (student_enrollment_t *)next(&iterator);
			if (temp->course_number == course_number) {
				student = find_student_by_student_number(temp->student_number);
				printf("Student number: %d\t Student name: %s\t\n",student->student_number,student->student_first_name);
			}
		}
	}
	else
		printf("ERROR: Course does not exist or does not have any students assigned\n");


}