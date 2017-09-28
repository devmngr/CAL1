#include "multiSwap.h"

void multiSwap(int *x, int *y, int *z) {

	int temp = *x;
	*x = *y;
	*y = *z;
	*z = temp;
}