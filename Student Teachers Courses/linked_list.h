#pragma once


typedef struct node * list_p;

void list_create(list_p *list);
void list_destroy(list_p * list);
int add_item(list_p * head, void * item);
int remove_item(list_p * head, void * item);
int no_of_items(list_p * head);
list_p get_iterator(list_p * head);
int has_next(list_p * iterator);
void * next(list_p* head);
void * get_item(list_p * head, int index);
void print_list(list_p * head);