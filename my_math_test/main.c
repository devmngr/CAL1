#include "my_math.h"
#include <stdio.h>
#include "minunit.h"
 int tests_run = 0;

static char * test_add1() {
	int result = add(4, 5);
	mu_assert("error, add(4,5) != 9", result == 9);
	return 0;
}
static char * test_add2() {
	int result = add(-4, 5);
	mu_assert("error, add(-4,5) != 1", result == 1);
	return 0;
}
static char * test_add3() {
	int result = add(250, 10);
	mu_assert("error, add(250,10) != 260", result == 260);
	return 0;
}
static char * test_add4() {

	int result = add(20, 23);
	mu_assert("error, add(20,23) != 260", result == 43);
	return 0;
}

static char * all_tests() {
	mu_run_test(test_add1);
	mu_run_test(test_add2);
	mu_run_test(test_add3);
	mu_run_test(test_add4);
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