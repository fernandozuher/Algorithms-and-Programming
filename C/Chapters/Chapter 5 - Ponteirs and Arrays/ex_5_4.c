/*
Author: Fernando Zuher
Place: Brazil
Date: 25/03/2020
Book: The C programming language, second edition. Authors: BRIAN W KERNIGHAN and DENNIS M. RITCHIE
About: Exercise, Chapter 5 - Pointers and Arrays
*/

/*
Exercise 5-4. Write the function strend(s, t), which returns 1 if the string
t occurs at the end of the string s, and zero otherwise.
*/

#include <stdio.h>
#include <string.h> // strlen()

int strend(char *s, char *t)
{
	int s_size = strlen(s);
	int t_size = strlen(t);
	
	if (s_size < t_size)
		return 0;

	for (char *ptr = s + s_size - t_size; *ptr++ == *t++; )
		if (*ptr == '\0')
			return 1;

	return 0;
}

int main()
{
	printf("\n%d\n", strend("Lorem ipsum dolor", "dolor"));
	printf("\n%d\n", strend("Lorem ipsum dolor", "dolor "));
	printf("\n%d\n", strend("Lorem ipsum dolor", "dolor"));
	return 0;
}