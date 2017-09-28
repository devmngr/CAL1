#include <stdio.h>
#include "MyString.h"

void main() {
	char msg1[] = "hello World";
	char msg2[] = "hello";
/*	Can be also used like this
	char* a = msg1;
	char* b = msg2;
	int w = my_strdiff(a, b);
	*/

	printf("%d\n", my_strdiff(msg1, msg2));
	printf("%d\n", my_strlen(msg1));
	printf("%s\n", my_strdup(msg2));

	my_strcpy(msg1, msg2);
		printf("%s \n", msg1);
		printf("%s \n", msg2);
}