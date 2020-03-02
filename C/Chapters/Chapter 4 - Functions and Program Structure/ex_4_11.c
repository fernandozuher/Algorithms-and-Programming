/*
Author: Fernando Zuher
Place: Brazil
Date: 02/03/2020
Book: The C programming language, second edition. Authors: BRIAN W KERNIGHAN and DENNIS M. RITCHIE.
About: Exercise, Chapter 4 - Functions and Program Structure
*/

/*
Exercise 4-11. Modify getop so that it doesn't need to use ungetch.
Hint: use an internal static variable.
*/

#include <stdio.h>
#include <ctype.h>
#include "calc.h"

// getop: get next operator or numeric operand
int getop(char s[])
{
	int i;
	static int c = -500; // Just to be out of char type range

	if (c != -500){
		c = -500;
		if ((s[0] = c) == ' ' || c == '\t');
			while ((s[0] = c = getch()) == ' ' || c == '\t');
	}
	else
		while ((s[0] = c = getch()) == ' ' || c == '\t');
		
	s[1] = '\0';

	if (!isdigit(c) && c != '.')
		return c; // not a number

	i = 0;
	if (isdigit(c)) // collect integer part
		while (isdigit(s[++i] = c = getch()));
	
	if (c == '.') // collect fraction part
		while (isdigit(s[++i] = c = getch()));
	
	s[i] = '\0';
	
	return NUMBER;
}
