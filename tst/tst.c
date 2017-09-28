#include <stdio.h>

struct person
{
	int age;
	int height;
}person_t;

int area(struct person * pers) {
	return pers->age * pers->height;
}
void pointer(void)
{
	struct person persons[10];
	struct person * person_p = persons;
	for (int i = 0; i < 10; i++)
	{
		persons[i].age = i + 20;
		persons[i].height = i + 175;
	}
	person_p = person_p + 5;
	printf("Person age : %d Height: %d\n", person_p->age, person_p->height);
}


void main() {
	pointer();
	person_t * pers1 = malloc(sizeof(struct person));
	pers1->age = 10;
	pers1->height = 2;
	int i = area(pers1);
	printf("\narea: %d\n", i);
}