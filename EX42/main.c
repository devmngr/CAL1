#include "list.h"
#include<stdio.h>
void main() {

	int a = 1;
	int b = 2;
	int c = 3;
	int d = 6;

	printf("initial size %d  \n", no_of_items());
	add_item(a);
	printf("add  %d  \n", no_of_items());
	add_item(b);
	printf("add  %d  \n", no_of_items());
	add_item(c);
	printf("add  %d \n", no_of_items());
	remove_item(a);
	printf("remove: %d \n", no_of_items());
	print_list();
}