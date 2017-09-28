#include "person.h"
#include <stdio.h>

int main() {

	person_t me;
	person_t you;

	construct_person(&me, 61, 187);
	construct_person(&you, 20, 160);

	printf("My data: Age: %d Height: %d\n", get_age(&me), get_height(&me));
	printf("My data: Age: %d Height: %d\n", get_age(&you), get_height(&you));


}