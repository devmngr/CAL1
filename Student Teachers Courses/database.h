#pragma once
#include "linked_list.h"
#include "student.h"
#include"teacher.h"
#include "course.h"
#include "student_enrollment.h"
#include "teacher_assignment.h"

void initialize_lists();
void read_from_file();
//void write_to_file();


//ADD
int add_student(int student_number, char * first_name);
int add_teacher(int teacher_number, char * first_name);
int add_course(int course_number, char * name, int semester_number);
int add_student_enrollment(int student_number, int course_number);
int add_teacher_assignment(int course_number,int teacher_number);


//REMOVE
int remove_student(int student_number);
int remove_teacher(int teacher_number);
int remove_course(int course_number);
int remove_enrollment_of_student(int student_number);
int remove_enrollment_of_course(int course_number);
int remove_assignment_of_teacher(int teacher_number);
int remove_assignment_of_course(int course_number);


//FIND
student_t * find_student_by_student_number(int student_number);
teacher_t * find_teacher_by_teacher_number(int teacher_number);
course_t * find_course_by_course_number(int course_number);
student_enrollment_t * find_enrollment(int student_number, int course_number);
student_enrollment_t * find_enrollment_of_student(int student_number);
student_enrollment_t * find_enrollment_of_course(int course_number);
teacher_assignment_t * find_assignment(int teacher_number, int course_number);
teacher_assignment_t * find_assignment_of_teacher(int teacher_number);
teacher_assignment_t * find_assignment_of_course(int course_number);

//NUMBER OF...
int no_of_students();
int no_of_teachers();
int no_of_courses();
int no_of_student_enrollments();
int no_of_teacher_assignments();

//PRINT
void print_all_students();
void print_all_teachers();
void print_all_courses();
void print_all_enrollments();
void print_all_assignments();
void courses_of_student(int student_number);
void courses_of_teacher(int teacher_number);
void students_of_course(int course_number);

//Destroy Lists
void destroy_students_list();
void destroy_teachers_list();
void destroy_courses_list();
void destroy_enrollments_list();
void destroy_assignments_list();
void destroy_all_lists();
void courses_of_student(int student_number);