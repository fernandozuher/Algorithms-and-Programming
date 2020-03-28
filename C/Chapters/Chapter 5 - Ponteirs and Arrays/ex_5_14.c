/*
Author: Fernando Zuher
Place: Brazil
Date: 28/03/2020
Book: The C programming language, second edition. Authors: BRIAN W KERNIGHAN and DENNIS M. RITCHIE
About: Exercise, Chapter 5 - Pointers and Arrays
*/

/*
Page 121, PDF 135

Exercise 5-14. Modify the sort program to handle a -r flag, which indicates
sorting in reverse (decreasing) order. Be sure that -r works with -n
*/

#include <stdio.h>
#include <string.h>

#define MAXLINES 5000 // max #lines to be sorted
char *lineptr[MAXLINES]; // pointers to text lines

int readlines(char *lineptr[], int nlines);
void writelines(char *lineptr[], int nlines);

void qsort2(void *lineptr[], int left, int right,
			int (*comp) (void *, void *), int reverse);

int numcmp(char *, char *);

// int strcmp ( const char * str1, const char * str2 );

// sort input lines
int main(int argc, char* argv[])
{
	int nlines; // number of input lines read
	int numeric = 0; // 1 if numeric sort
	int reverse = 0;

	// ***I changed here to reverse
	while (argc-- > 1)

		if (strcmp(*++argv, "-n") == 0)
			numeric = 1;
		else if (strcmp(*argv, "-r") == 0)
			reverse = 1;

	if ((nlines = readlines(lineptr, MAXLINES)) >= 0) {
		
		qsort2((void **) lineptr, 0, nlines-1, 
		(int (*)(void*, void*))(numeric ? numcmp : strcmp), reverse);
		
		printf("sorted:\n");
		writelines(lineptr, nlines);
		return 0;

	} else {
		printf("input too big to sort\n");
		return 1;
	}
}

// qsort2: sort v[left] •..v[right] into increasing order
void qsort2(void *v[], int left, int right, int (*comp)(void *, void *), int reverse)
{
	int i, last;
	void swap(void *v[], int, int);
	
	if (left >= right) // do nothing if array contains
		return; // fewer than two elements
	
	swap(v, left, (left + right)/2);
	last = left;

	for (i = left+1; i <= right; i++)
		// ***I changed here to reverse
		if ((*comp)((!reverse ? v[i] : v[left]), (!reverse ? v[left] : v[i])) < 0)
			swap(v, ++last, i);
	
	swap(v, left, last);
	qsort2(v, left, last-1, comp, reverse);
	qsort2(v, last+1, right, comp, reverse);
}

#include <stdlib.h>
// numcmp: compare s1 and s2 numerically
int numcmp(char *s1, char *s2)
{
	double v1, v2;
	
	v1 = atof(s1);
	v2 = atof(s2);

	if (v1 < v2)
		return -1;
	else if (v1 > v2)
		return 1;
	else
		return 0;
}

void swap(void *v[], int i, int j)
{
	void *temp;
	
	temp = v[i];
	v[i] = v[j];
	v[j] = temp;
}

#define MAXLEN 1000 // max length of any input line

char *alloc(int);

// readlines: read input lines
int readlines(char *lineptr[], int maxlines)
{
	int len, nlines;
	char *p, line[MAXLEN];
	nlines = 0;

	while ((len = strlen(fgets(line, MAXLEN, stdin))) > 1) // \n
		if (nlines >= maxlines || (p = alloc(len)) == NULL)
			return -1;
		else {
			line[len-1] = '\0'; // delete newline
			strcpy(p, line);
			lineptr[nlines++] = p;
		}

	return nlines;
}

// writelines: write output lines
void writelines(char *lineptr[], int nlines)
{
	int i;
	while (nlines-- > 0)
		printf ("%s\n", *lineptr++);
}

#define ALLOCSIZE 10000 // size of available space
static char allocbuf[ALLOCSIZE]; // storage for alloc
static char *allocp = allocbuf; // next free position

char *alloc(int n) // return pointer to n characters
{
	if (allocbuf + ALLOCSIZE - allocp >= n) { // it fits
		allocp += n;
		return allocp - n; // old p

	} else // not enough room
		return 0;
}