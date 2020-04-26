/*
Author: Fernando Zuher
Place: Brazil
Date: 24 April 2020
Book: The C programming language, second edition. Authors: BRIAN W KERNIGHAN and DENNIS M. RITCHIE
About: Exercise, Chapter 7 - Input and Output
*/

/*
PDF 167, Page 153

Exercise 7-1. Write a program that converts upper case to lower or lower case
to upper, depending on the name it is invoked with, as found in argv[0].

*/

#include <stdio.h>
#include <ctype.h>

int main(int argc, char const *argv[])
{
	for (int i = 0; *argv[0] != '\0'; ++argv[0])
		if (**argv >=65 && **argv <=90)
			putchar(tolower(**argv));

		else if (**argv >=97 && **argv <=122)
			putchar(toupper(**argv));

		else
			putchar(**argv);

	printf("\n");
	return 0;
}