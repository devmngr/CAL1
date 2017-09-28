#include <stdio.h>

#include "subtraction.h"
#include "multiplication.h"
#include "power.h"
#include "multiSwap.h"

int main (void) {
  int a = 10;
  int b = -2;


  int x = 2;
  int y = 5;
  int z = 7;

  printf ("\nHere, we add, subtract and multiply....\n\n");
  printf ("%d\t+\t%d\t=\t%d\n", a, b, cal_add(a,b));
  printf ("%d\t-\t%d\t=\t%d\n", a, b, cal_subtract(a,b));
  printf ("%d\t*\t%d\t=\t%d\n", a, b, cal_multiply(a,b));
  printf("%d\t ^\t  %d\t =\t %d\n\n\n", x, y, power(x, y));
  printf("%d\t %d\t %d\t\n", x, y, z);
  multiSwap(&x, &y, &z);
  printf("%d\t %d\t %d\t\n", x, y, z);

}


