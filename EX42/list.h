#pragma once


typedef struct  node_t {

	void * content;
	struct node_t * next;
}node_t;
int add_item(void *); // Return 0 if item added else -1
int remove_item(void *); // Return 0 if item removed else -1
int no_of_items(); // Return number of items in list
void print_list();