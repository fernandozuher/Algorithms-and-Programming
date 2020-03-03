/*
Author: Fernando Zuher
Place: Brazil
Date: 03/03/2020
Book: The C programming language, second edition. Authors: BRIAN W KERNIGHAN and DENNIS M. RITCHIE.
About: Exercise, Chapter 4 - Functions and Program Structure
*/

/*
Exercise 4-12. Adapt the ideas of printd to write a recursive version of itoa;
that is, convert an integer into a string by calling a recursive routine.
*/
#include <stdio.h>

#define MAX_DIGITS_NUMBER 15

void itoa_recursive(int n, char s[]);

int main() {

	char number_in_string[MAX_DIGITS_NUMBER];
	int number = -316;
	
	itoa_recursive(number, number_in_string);
	printf("\n%s\n", number_in_string);
	
	return 0;
}

/* itoa: convert n to characters in s */
void itoa_recursive(int n, char s[])
{
	static int i = 0, len = 0;

	if (!i && n < 0) { // record a sign
		s[i++] = '-';
		n = -n;
		len++;
	}

	len++;
	if (n / 10)
		itoa_recursive(n / 10, s);
	else
		s[len] = '\0';

	s[i++] = n % 10 + '0';
}