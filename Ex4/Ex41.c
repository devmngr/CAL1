#pragma once
#include "MyString.h"


int my_strdiff(char* a, char* b) {
	int n = 0;
	while (*a == *b && *a !=0 && *b!=0) {
		n++;
		a++;
		b++;
	}
	if (*a != *b)
		return n;
	return -1;
}
int my_strlen(char* a) {
	
	int count = 0;
	while (*a != 0)
	{	count++;
	a++;
}
	return count;
}

char * my_strcpy(char *dest, char * src) {
	char * temp = dest;
	while (*src != '\0') {
		*dest = *src;
		dest++;
		src++;
	}
	*dest = *src;
	return temp;
}
char* my_strdup(const char * str1) {
	char  *dest = (char *)malloc((my_strlen(str1) + 1) * sizeof(char));
	if (dest != 0)
		my_strcpy(dest, str1);

	return dest;


}