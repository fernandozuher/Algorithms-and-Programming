/*
Author: Fernando Zuher
Place: Brazil
Date: 29/03/2020
Book: The C programming language, second edition. Authors: BRIAN W KERNIGHAN and DENNIS M. RITCHIE
About: Exercises, Chapter 5 - Pointers and Arrays
*/

/*
Page 121, PDF 135

OBS: The sorted text is displayed after inputing an empty input (just 'enter', '\n').

Exercise 5-14. Modify the sort program to handle a -r flag, which indicates
sorting in reverse (decreasing) order. Be sure that -r works with -n

Exercise 5-15. Add the option -f to fold upper and lower case together, so that
case distinctions are not made during sorting; for example, a and A compare
equal.

Exercise 5-16. Add the -d ("directory order") option, which makes comparis-
ons only on letters, numbers and blanks. Make sure it works in conjunction
with -f.

Exercise 5-17. Add a field-handling capability, so sorting may be done on fields
within lines, each field sorted according to an independent set of options. (The
index for this book was sorted with -df for the index category and -n for the
page numbers.)
*/

/*
// The command-line arguments can be input as '-r -n', not '-rn'.
// But that example is the only way handled in the field-handling inside the lines.
Look a test sample:
./main -r -n

input:
9
10
8
-df
Fernando Zuher; xyz 4
Fernando zuher, xyz 3
-n
10
9
8
-d
Fernando zuher, xyz 1
Fernando Zuher; xyz 2
-rn
8
9
10


*/

#include <stdio.h> // fgets()
#include <string.h> // strlen()
#include <ctype.h> // tolower(), isalpha(), isdigit()

#define MAXLINES 5000 // max #lines to be sorted
char *lineptr[MAXLINES]; // pointers to text lines

static int options[4];
	// [0] = 'n'umeric
	// [1] = 'r'everse
	// [2] = 'f'old
	// [3] = 'd'irectory order

int readlines(char *lineptr[], int nlines, int argc, char* argv[]);
void writelines(char *lineptr[], int nlines);

void qsort2(void *lineptr[], int left, int right,
			int (*comp) (void *, void *));

int numcmp(char *, char *);

int strcmp_case_insensitive(const char* s1, const char* s2); // Exercise 5-15
int strcmp_d(const char* s1, const char* s2); // Exercise 5-16
void options_f(int* argc, char* argv[], char* line);

// sort input lines
int main(int argc, char* argv[])
{
	int nlines; // number of input lines read

	if (argc > 1)
		options_f(&argc, argv, NULL);

	if ((nlines = readlines(lineptr, MAXLINES, argc, argv)) >= 0) {
		printf("Sorted:\n");
		writelines(lineptr, nlines);
		return 0;

	} else {
		printf("input too big to sort\n");
		return 1;
	}
}

// qsort2: sort v[left] •..v[right] into increasing order
void qsort2(void *v[], int left, int right, int (*comp)(void *, void *))
{
	int i, last;
	void swap(void *v[], int, int);
	
	if (left >= right) // do nothing if array contains
		return; // fewer than two elements
	
	swap(v, left, (left + right)/2);
	last = left;

	for (i = left+1; i <= right; i++) {
		
		// Exercise 5-14. Modify the sort program to handle a -r flag, which indicates
		// sorting in reverse (decreasing) order. Be sure that -r works with -n
		if (!*(options+1)) {
			if ((*comp)(v[i], v[left]) < 0)
				swap(v, ++last, i);
		}
		else
			if ((*comp)(v[i], v[left]) > 0)
				swap(v, ++last, i);
	}
	
	swap(v, left, last);
	qsort2(v, left, last-1, comp);
	qsort2(v, last+1, right, comp);
}

#include <stdlib.h> // atof()
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
int readlines(char *lineptr[], int maxlines, int argc, char* argv[])
{
	int len, nlines, temp_lines = 0;
	char *p, line[MAXLEN];
	nlines = 0;

	while ((len = strlen(fgets(line, MAXLEN, stdin))) > 1) // \n
		if (nlines >= maxlines || (p = alloc(len)) == NULL)
			return -1;
		else {
			line[len-1] = '\0'; // delete newline

			// Field-handling is considered when it is found in the beginning
			// of a line starting by '-'.
			if(line[0] == '-') {

				qsort2((void **) lineptr, 0, nlines-1, 
				(int (*)(void*, void*))(options[3] ? strcmp_d :
								options[2] ? strcmp_case_insensitive :
								options[0] ? numcmp : strcmp));

				options_f(&argc, argv, line);

				lineptr += nlines;
				nlines = 0;
			}
			else {
				strcpy(p, line);
				lineptr[nlines++] = p;
				temp_lines++;
			}
		}

	qsort2((void **) lineptr, 0, nlines-1, 
				(int (*)(void*, void*))(options[3] ? strcmp_d :
								options[2] ? strcmp_case_insensitive :
								options[0] ? numcmp : strcmp));
	return temp_lines;
}

// writelines: write output lines
void writelines(char *lineptr[], int nlines)
{
	int i;
	while (nlines-- > 0)
		printf ("\t%s\n", *lineptr++);
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

// Exercise 5-15. Add the option -f to fold upper and lower case together, so that
// case distinctions are not made during sorting; for example, a and A compare
// equal.
int strcmp_case_insensitive(const char* s1, const char* s2)
{
	for ( ; tolower(*s1) == tolower(*s2); s1++, s2++)
		if (*s1 == '\0')
			return 0;
	
	return *s1 - *s2;
}

// Exercise 5-16. Add the -d ("directory order") option, which makes comparis-
// ons only on letters, numbers and blanks. Make sure it works in conjunction
// with -f.
int strcmp_d(const char* s1, const char* s2)
{
	int temp_s1, temp_s2;

	for ( ; ; s1++, s2++)
		if (

			(isalpha(*s1) || isdigit(*s1) || *s1 == ' ' || *s1 == '\0')
			&&
			(isalpha(*s2) || isdigit(*s2) || *s2 == ' ' || *s2 == '\0')

			) {
				// if -f ('f'old)
				temp_s1 = *(options+2) ? tolower(*s1) : *s1;
				temp_s2 = *(options+2) ? tolower(*s2) : *s2;

				if (temp_s1 == temp_s2) {
					if (*s1 == '\0')
						return 0;
				}
				else
					break;
			}

	return *s1 - *s2;
}

void options_f(int* argc, char* argv[], char* line) {

	// start to initial values
	for (int i = 0; i < 4; i++)
		options[i] = 0;

	while (*argc > 1) {
		
		(*argc)--;
		*++argv;

		if (strcmp( (*argv), "-n") == 0) // numeric
			options[0] = 1;
		else if (strcmp( (*argv), "-r") == 0) // reverse
			options[1] = 1;
		else if (strcmp( (*argv), "-f") == 0) // fold
			options[2] = 1;
		else if (strcmp( (*argv), "-d") == 0) // directory order
			options[3] = 1;
	}
	
	// If line is not NULL. Exercise 5-17.
	// Even if the user inputs in the command-line arguments, the fields found in
	// the lines will overwrite them.
	if (line && *line == '-') {

		// line != '\0' -->> line != 0 -->> line
		while (*++line) {
			if (*line == 'n') // numeric
				options[0] = 1;
			else if (*line == 'r') // reverse
				options[1] = 1;
			else if (*line == 'f') // fold
				options[2] = 1;
			else if (*line == 'd') // directory order
				options[3] = 1;
		}
	}
}