#include "linked_list.h"
#include <stddef.h>
#include <stdlib.h>

typedef struct node {
	void * content;
	struct node * next;
} node_t;
void list_create(list_p * head)
{
	* head = NULL;
}
void list_destroy(list_p * head) {

	node_t * current = * head;
	node_t * next;
	while (current!=NULL) {	
		next = current->next;
		free(current);
		current = next;
	}
	* head = NULL;
}
int add_item(list_p * head, void * item)
{
	node_t * temp = (node_t *)malloc(sizeof(struct node));
	if (temp == NULL) {
		return -1;
	}
	temp->content = item;
	temp->next = * head;
	* head = temp;

	return 0;
}
int remove_item(list_p * head, void * item) {
	node_t * current = * head;
	node_t * previous = * head;
	while (has_next(head)) {
		if (current->content == item) {

			if (current == * head)
			{
				previous = current;
				* head = current->next;
			}
			else {
				previous->next = current->next;
			}
			free(current);
			return 0;
		}
		else {
			previous = current;
			current = current->next;
		}
	}
	return 1;
}
int no_of_items(list_p * head)
{
	int count = 0;
	node_t * iterator = *head;

	while (iterator != NULL)
	{
		count++;
		iterator = iterator->next;
	}

	return count;
}
list_p get_iterator(list_p * head) {
	return * head;
}
int has_next(list_p * iterator) {

	if (iterator == NULL)
		return NULL;
	return (* iterator != NULL);
}
void * next(list_p * iterator) {

	if (*iterator != NULL) {
		void * temp = (*iterator)->content;
			* iterator = (*iterator)->next;
			return temp;
	}
	return NULL;
}
void print_list(list_p * head) {
	node_t * iterator = *head;
	if (iterator == NULL)
		printf("List is empty!\n");
	while (iterator !=NULL)
	{

		printf("%d \n", iterator->content);
		iterator = iterator->next;
	}
}
void * get_item(list_p * head, int index) {
	node_t * iterator = * head;
	int count = 0;
	while (iterator != NULL && count<index)
	{
		iterator = iterator->next;
		count++;
	}
	if (iterator == NULL)
		return NULL;
	return iterator->content;
}







