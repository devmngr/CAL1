#include "list.h"
#include <stddef.h>
#include <stdlib.h>
/*head is global to the whole module, but not accessible from other modules*/


static node_t * head = NULL;
static int count = 0;

/*Adds an element as the head of the linked list structure*/
int add_item(void * element) {

	node_t * temp = (struct node_t*) malloc(sizeof(struct node_t));
	if (temp == NULL) {
		return -1;
	}
	temp->content = element;
	temp->next = head;
	head = temp;
	count++;
	return 0;
}

/*removes the node*/
int remove_item(void * element) {
	node_t * current = head;
	node_t * previous = NULL;
	while (current != NULL) {
		if (current->content == element) {

			if (previous == NULL)
			{
				previous = current;
				current = current->next;
			}
			else {
				previous->next = current->next;
			}
			count--;
			free(current);
			return 0;
		}
		else {
			previous = current;
			current = current->next;
		}

	}
	return -1;
}
int no_of_items() {
	return count;
}

void print_list() {
	node_t * current = head;
	while (current != NULL) {
		printf("%d \n", current->content);
		current = current->next;
	}
}
