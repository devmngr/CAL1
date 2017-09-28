#include <stdio.h>
#include "linked_list.h"
#include "minunit.h"


int tests_run = 0;
static char * test_size0() {

	int result = no_of_items();
	mu_assert("error, size() != 0", result == 0);
	return 0;
}
static char * test_size1() {

	int result = no_of_items();
	mu_assert("error, size() != 1", result == 1);
	return 0;
}
static char * test_size2() {

	int result = no_of_items();
	mu_assert("error, size() != 2", result == 2);
	return 0;
}
static char * test_size3() {

	int result = no_of_items();
	mu_assert("error, size() != 3", result == 3);
	return 0;
}
static char * test_add1() {

	int result = add_item(1);
		mu_assert("error, add(1) != 0", result == 0);
	return 0;
}
static char * test_add2() {

	int result = add_item(2);
	mu_assert("error, add(2) != 0", result == 0);
	return 0;
}
static char * test_add3() {

	int result = add_item(3);
	mu_assert("error, add(3) != 0", result == 0);
	return 0;
}

static char * test_remove1() {

	int result = remove_item(1);
	mu_assert("error, remove(1) != 0", result == 0);
	return 0;
}
static char * test_remove2() {

	int result = remove_item(2);
	mu_assert("error, remove(2) != 0", result == 0);
	return 0;
}
static char * test_remove3() {

	int result = remove_item(3);
	mu_assert("error, remove(3) != 0", result == 0);
	return 0;
}

static char * all_tests() {
//add
	mu_run_test(test_size0);
	
	mu_run_test(test_add1);
	mu_run_test(test_size1);
	
	mu_run_test(test_add2);
	mu_run_test(test_size2);

	mu_run_test(test_add3);
	mu_run_test(test_size3);

//remove
	mu_run_test(test_remove1);
	mu_run_test(test_size2);

	mu_run_test(test_remove2);
	mu_run_test(test_size1);
	
	mu_run_test(test_remove3);
	mu_run_test(test_size0);

	return 0;
}


int main() {

	char *result = all_tests();
	if (result != 0) {
		printf("%s\n", result);
	}
	else {
		printf("ALL TESTS PASSED\n");
	}
	printf("Tests run: %d\n", tests_run);
	return result != 0;
}