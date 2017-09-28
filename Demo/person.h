#pragma once
#ifndef PERSON_H_
#define PERSON_H_

typedef struct
{
	int age;
	int height;
}person_t;

void construct_person(person_t *per, int age, int height);
void inc_age(person_t *per);
void set_height(person_t *per, int height);
int get_height(person_t *per);
int get_age(person_t *per);

#endif