/*
Author: Fernando Zuher
Place: Brazil
Date: 05/03/2020
Book: The C programming language, second edition. Authors: BRIAN W KERNIGHAN and DENNIS M. RITCHIE.
About: Exercise, Chapter 4 - Functions and Program Structure
*/

// Exercise 4-14. Define a macro swap(t,x,y) of type t. (Block structure will help.)
#include <stdio.h>

#define swap(t, x, y) {t temp = x; x = y; y = temp;}

int main(int argc, char const *argv[])
{
	int a = 1, b = 2, temp;
	
	printf("\na = %d; b = %d\n", a, b);
	swap(int, a, b)
	printf("\na = %d; b = %d\n", a, b);

	return 0;
}