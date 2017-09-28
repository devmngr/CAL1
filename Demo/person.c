#pragma once

#include "person.h"


void construct_person(person_t *per, int age, int height) {
	per->age = age;
	per->height = height;
}

void inc_age(person_t *per)
{
	per->age++;
}


void set_height(person_t *per, int height)
{
	per->height = height;
}


int get_height(person_t *per)
{
	return per->height;
}


int get_age(person_t *per)
{
	return per->age;
}