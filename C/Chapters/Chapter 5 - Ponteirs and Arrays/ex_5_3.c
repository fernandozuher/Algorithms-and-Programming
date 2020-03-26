/*
Author: Fernando Zuher
Place: Brazil
Date: 25/03/2020
Book: The C programming language, second edition. Authors: BRIAN W KERNIGHAN and DENNIS M. RITCHIE
About: Exercise, Chapter 5 - Pointers and Arrays
*/

/*
Exercise 5-3. Write a pointer version of the function strcat that we showed
in Chapter 2: strcat(s, t) copies the string t to the end of s.
*/

#include <stdio.h>

void strcat2(char *s, char *t)
{
	while (*s++ != '\0');
	s--;
	while (*s++ = *t++);	
}

int main()
{
	char temp[60] = "First part of the string... ";
	
	strcat2(temp, "second part of the string!");
	printf("\ntemp = %s", temp);
	
	printf("\n");
	return 0;
}