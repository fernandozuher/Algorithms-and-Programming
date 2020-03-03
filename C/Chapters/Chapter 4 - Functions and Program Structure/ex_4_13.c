/*
Author: Fernando Zuher
Place: Brazil
Date: 03/03/2020
Book: The C programming language, second edition. Authors: BRIAN W KERNIGHAN and DENNIS M. RITCHIE.
About: Exercise, Chapter 4 - Functions and Program Structure
*/

/*
Exercise 4-13. Write a recursive version of the function reverse(s), which
reverses the string s in place.
*/

#include <stdio.h>

void reverse(char s[]);

int main() {

	char string[] = "Fernando Zuher";
	
	printf("\nOriginal: %s", string);
	reverse(string);
	printf("\nReverse: %s", string);
	reverse(string);
	printf("\nReverse: %s\n", string);
	
	return 0;
}

/* itoa: convert n to characters in s */
void reverse(char s[])
{
	static int i = -1, len;

	if (s[++i] != '\0')
		reverse(s);
	else {
		len = i - 1;
		return;
	}
	
	if (--i > len / 2) {
		char temp;
		temp = s[i], s[i] = s[len-i], s[len-i] = temp;
	}
}