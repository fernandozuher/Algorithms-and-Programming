#include <stdio.h>
#include <ctype.h>
#include "calc.h"

// getop: get next operator or numeric operand
int getop(char s[])
{
	int i, c;
	while ((s[0] = c = getch()) == ' ' || c == '\t');
	s[1] = '\0';

	// '-' for negative numbers, exercise 4-3
	if (!isdigit(c) && c != '.' && c != '-')
		return c; // not a number

	else if (c == '-') { // '-' for negative numbers, exercise 4-3
		if (isdigit(c = getch())) // is digit, not space
			c = -c;
		else {
			ungetch(c);
			return '-';
		}
	}

	i = 0;
	
	if (isdigit(c)) // collect integer part
		while (isdigit(s[++i] = c = getch()));
	
	if (c == '.') // collect fraction part
		while (isdigit(s[++i] = c = getch()));
	
	s[i] = '\0';
	
	// Exercise 4-9. Our getch and ungetch do not handle a pushed-back EOF
	// correctly. Decide what their properties ought to be if an EOF is pushed
	// back, then implement your design.
	// if (c != EOF) // <-- original version
	ungetch(c);
	
	return NUMBER;
}
