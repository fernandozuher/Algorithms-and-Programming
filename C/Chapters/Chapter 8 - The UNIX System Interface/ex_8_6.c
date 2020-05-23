/*
Author: Fernando Zuher
Place: Brazil
Date: 23 May 2020
Book: The C programming language, second edition. Authors: BRIAN W KERNIGHAN and DENNIS M. RITCHIE
About: Exercise, Chapter 8 - The UNIX System Interface
*/

/*
PDF 203, Page 189

Exercise 8-6. The standard library function calloc(n, size) returns a
pointer to n objects of size size, with the storage initialized to zero. Write
calloc, by calling malloc or by modifying it.
*/
#include <stdio.h>
#include <stdlib.h> // malloc

void* calloc2 (size_t num, size_t size) {
	
	char *temp;
	if (temp = malloc(num*size))
		for (int i = 0; i < num; temp[i++] = 0);
	return (void*) temp;
}

int main(int argc, char const *argv[])
{
	double *ptr = (double*) calloc2(3, sizeof(double));
	for (int i = 0; i < 3; i++)
		printf("%f ", ptr[i]);

	printf("\n");
	return 0;
}