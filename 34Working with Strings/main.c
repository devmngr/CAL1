#include <stdio.h>
#include "mystringfunc.h"


#define MAX_LENGTH 1000
int main()
{
	char line[MAX_LENGTH];
	char upper[10];
	int linelength;
	/* Use a while loop to read input lines as long as there are any. For
	each input line,
	print the length of the line as well as the upper case version of
	the line */
	while (line) {
		/* And here */
		if (line)
		{
			linelength = readline(line, MAX_LENGTH);
			printf("Entered text %s", line);
			to_upper(line, upper);
			printf("To upper: %s\n", upper);
			//printf("Length: %d\t%s", linelength, upper);
		}
	}
	return 0;
}