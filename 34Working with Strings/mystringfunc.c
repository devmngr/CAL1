/* readline: read a line into s, return length */
#include <stdio.h>
#include "mystringfunc.h"
#include <ctype.h>

int readline(char s[], int lim)
{
	int c, i;
	for (i = 0; i < lim - 1 && (c = getchar()) != EOF && c != '\n'; ++i)
		s[i] = c;
	if (c == '\n') {
		s[i] = c;
		++i;
	}
	s[i] = '\0';
	return i;
}
void to_upper(char *str_in, char *str_out)
{
	char c_in, c_out;
	/* You must implement your own version of to_upper using the two
	strings str_in and str_out and c_in and c_out. Loop over the str_in (as
	long as it "contains" something). Look at the "current" character and
	check if its a lowercase letter. If it is, convert it to the upper
	case version and add that to the str_out character array */
	int i = 0;
	//int size = str_in;
	while (str_in[i]) {
		c_in = c_out = str_in[i];
		if (islower(c_in))
			c_out = toupper(c_in);
		str_out[i] = c_out;
		i++;
	}

	/*for (int i=0; i<str_in; i++)
	{
	c_in = c_out= str_in[i];

	if (islower(c_in))
	c_out = toupper(c_in);

	str_out[i] = c_out;
	}*/




}