/*
Author: Fernando Zuher
Place: Brazil
Date: 6 May 2020
Book: The C programming language, second edition. Authors: BRIAN W KERNIGHAN and DENNIS M. RITCHIE
About: Exercise, Chapter 7 - Input and Output
*/

/*
PDF 182, Page 168

Exercise 7-9. Functions like isupper can be implemented to save space or to
save time. Explore both possibilities.

	Exercise not clear.
	Implementing as macro saves time because it decreases the overhead
		in calling a function to each character of a string.
	Implementing as function saves space?
*/

#include <stdio.h>

#define isupper(c) ((c) >= 'A' && (c) <= 'Z')
int isupper2(int c);

int main(int argc, char const *argv[])
{
	int c = 'F';
	printf("isupper() macro: %d\n", isupper(c));
	printf("isupper() function: %d\n", isupper2(c));
	
	return 0;
}

int isupper2(int c) { return c >= 'A' && c <= 'Z'; }
