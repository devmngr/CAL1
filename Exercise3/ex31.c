#include <stdio.h>

void main() {

	int a = 7;
	int b = 3;
	float result = a / b;

	printf("Division \n");
	printf("%d\t / \t%d\t = \t%d\n\n", a, b, (a / b));
	printf("Reminder \n");
	printf("%d\t % \t%d\t = \t%d\n", a, b, a%b);


	printf("As float:\n");
	printf("%d\t / \t%d\t = \t%g\n\n", a,b,result);
}