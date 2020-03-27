/*
Author: Fernando Zuher
Place: Brazil
Date: 26/03/2020
Book: The C programming language, second edition. Authors: BRIAN W KERNIGHAN and DENNIS M. RITCHIE
About: Exercise, Chapter 5 - Pointers and Arrays
*/

/*
Exercise 5-7. Rewrite readlines to store lines in an array supplied by main,
rather than calling alloc to maintain storage. How much faster is the pro-
gram?
	In the current computer generation, there is not clear difference.
*/

#include <stdio.h>
#include <string.h>

#define ALLOCSIZE 10000 // size of available space

#define MAXLINES 5000 // max lines to be sorted
char *lineptr[MAXLINES]; // pointers to text lines

int readlines(char *lineptr[], int nlines, char* allocbuf, char* allocp);
int readlines_alloc(char *lineptr[], int nlines);
void writelines(char *lineptr[], int nlines);
void qsort(char *lineptr[], int left, int right);

int main()
{
	char allocbuf[ALLOCSIZE];
	char* allocp = allocbuf;

	int nlines; // number of input lines read

	// if ((nlines = readlines(lineptr, MAXLINES, allocbuf, allocp)) >= 0) {
	if ((nlines = readlines_alloc(lineptr, MAXLINES)) >= 0) {
		qsort(lineptr, 0, nlines-1);
		writelines(lineptr, nlines);
		return 0;
	}
	else {
		printf("error: input too big to sort\n");
		return 1;
	}
}

#define MAXLEN 1000 // max length of any input line

// readlines: read input lines
int readlines(char *lineptr[], int maxlines, char* allocbuf, char* allocp)
{
	int len, nlines;
	char line[MAXLEN];

	nlines = 0;
	while ((len = strlen(fgets(line, MAXLEN, stdin))) > 1)
									// bigger than just \n
		if (nlines >= maxlines)
			return -1;

		else if (allocbuf + ALLOCSIZE - allocp >= len) {
			allocp += len;
			line[len-1] = '\0'; // delete newline

			strcpy(allocp - len, line);
			lineptr[nlines++] = allocp - len;
		}
		else
			return -1;

	return nlines;
}

#define ALLOCSIZE 10000 // size of available space
char allocbuf[ALLOCSIZE]; // storage for alloc
char *allocp = allocbuf; // next free position

char* alloc(int n) // return pointer to n characters
{
	if (allocbuf + ALLOCSIZE - allocp >= n) { // it fits
		allocp += n;
		return allocp - n; // old p
	}
	else // not enough room
		return 0;
}

// readlines: read input lines
int readlines_alloc(char *lineptr[], int maxlines)
{
	int len, nlines;
	char *p, line[MAXLEN];

	nlines = 0;
	while ((len = strlen(fgets(line, MAXLEN, stdin))) > 1)
									// bigger than just \n
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
	while (nlines-- > 0)
		printf ("%s\n", *lineptr++);
}

// qsort: sort v[left] ...v[rightl into increasing order
void qsort(char *v[], int left, int right)
{
	int i, last;
	void swap(char *v[], int i, int j);

	if (left >= right) // do nothing if array contains
		return; // fewer than two elements
	
	swap(v, left, (left + right)/2);
	last = left;
	for (i = left+1; i <= right; i++)
		if (strcmp(v[i], v[left]) < 0)
			swap(v, ++last, i);
	
	swap(v, left, last);
	qsort(v, left, last-1);
	qsort(v, last+1, right);
}

// swap: interchange v[i] and v[j]
void swap(char *v[], int i, int j)
{
	char *temp;
	temp = v[i];
	v[i] = v[j];
	v[j] = temp;
}