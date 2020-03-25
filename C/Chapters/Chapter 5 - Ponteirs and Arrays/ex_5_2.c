/*
Author: Fernando Zuher
Place: Brazil
Date: 25/03/2020
Book: The C programming language, second edition. Authors: BRIAN W KERNIGHAN and DENNIS M. RITCHIE
About: Exercise, Chapter 5 - Pointers and Arrays
*/

/*
Exercise 5-2. Write getfloat, the floating-point analog of getint. What
type does getfloat return as its function value?
	int as well.
*/

#include <stdio.h>
#include <ctype.h> // isspace(), isdigit()
#define SIZE 50 /* maximum input line length */

int getch(void);
void ungetch(int);
int getfloat(float *pn);

int main()
{
	int n;
	float array[SIZE];

	for (n = 0; n < SIZE && getfloat(&array[n]) != EOF; n++);

	for (int i = 0; i < n; i++)
		printf("\nnumber %d: %f", i+1, array[i]);
	printf("\n");

	return 0;
}

int getfloat(float *pn)
{
	float power;
	int c, sign;
	
	while (isspace(c = getch())); // skip white space 
	
	if (!isdigit(c) && c != EOF && c != '+' && c != '-') {
		ungetch(c); // it's not a number
		return 0;
	}

	sign = (c == '-') ? -1 : 1;
	if (c == '+' || c == '-')
		c = getch();

	for (*pn = 0.0; isdigit(c); c = getch())
		*pn = 10.0 * *pn + (c - '0');
	
	if (c == '.')
		c = getch();

	for (power = 1.0; isdigit(c); c = getch()) {
		*pn = 10.0 * *pn + (c - '0');
		power *= 10.0;
	}

	*pn = sign * *pn / power;

	if (c != EOF)
		ungetch(c);

	return c;
}

#define BUFSIZE 100
char buf[BUFSIZE]; // buffer for ungetch
int bufp = 0; // next free position in buf

int getch(void) // get a (possibly pushed back) character
{
	return (bufp > 0) ? buf[--bufp] : getchar();
}

void ungetch(int c) // push character back on input
{
	if (bufp >= BUFSIZE)
		printf("ungetch: too many characters\n");
	else
		buf[bufp++] = c;
}
