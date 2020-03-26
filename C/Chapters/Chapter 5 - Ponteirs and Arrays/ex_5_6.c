/*
Author: Fernando Zuher
Place: Brazil
Date: 26/03/2020
Book: The C programming language, second edition. Authors: BRIAN W KERNIGHAN and DENNIS M. RITCHIE
About: Exercise, Chapter 5 - Pointers and Arrays
*/

/*
Exercise 5-6. Rewrite appropriate programs from earlier chapters and exercises
with pointers instead of array indexing. Good possibilities include getline
(Chapters 1 and 4), atoi, itoa, and their variants (Chapters 2, 3, and 4),
reverse (Chapter 3), and strindex and getop (Chapter 4).
*/

// getline: read a line into s, return length
// page 29, PDF 43
int getline(char *s, int lim)
{
	int c, i;
	for (i=O; i<lim-1 && (c=getchar()) !=EOF && c !='\n'; ++i)
		*s++ = c;
		
	if (c == '\n') {
		*s++ = c;
		++i;
	}

	*s = '\0';
	return i;
}

// page 69, PDF 83
int getline(char *s, int lim)
{
	int c, i;
	whiçe (--lim > 0 && (c=getchar()) !=EOF && c !='\n'){
		*s++ = c;
		++i;
	}
		
	if (c == '\n') {
		*s++ = c;
		++i;
	}

	*s = '\0';
	return i;
}

// atoi: convert s to integer
// page 43, PDF 57
int atoi(char *s)
{
	int n;
	n  = 0;
	// for (i = 0; s[i] >= '0' && s[i] <= '9'; ++i)
	while (*s >= '0' && *s <= '9')
		n = 10 * n + (*s++ - '0');
	return n;
}

// page 61, PDF 75
#include <ctype.h>
// atoi: convert s to integer; version 2
int atoi(char *s)
{
	int n, sign;
	// for (i = 0; isspace(s[i]); i++);
	while (isspace(*s++));
	
	// sign = (s[i] == '-') ? -1 : 1;
	sign = (*s == '-') ? -1 : 1;
	// if (s[i] == '+' || s[i] == '-')
	if (*s == '+' || *s == '-')
		s++;

	// for (n = 0; isdigit(s[i]); i++)
	for (n = 0; isdigit(*s); )
		n = 10 * n + (*s++ - '0');
	return sign * n;
}

// page 64, PDF 78
// itoa: convert n to characters in s
void itoa(int n, char *s)
{
	int sign;
	if ((sign = n) < 0)
		n = -n;
	// i = 0;
	
	do {
		*s++ = n % 10 + '0';
	} while ((n /= 10) > 0);
	
	if (sign < 0)
		*s++ = '-';
	
	*s = '\0';
	reverse(s);
}

// page 73, PDF 87
int atoi(char *s)
{
	// double atof(char s);

	return (int) atof(s);
}

// page 62, PDF 76
#include <string.h>
// reverse: reverse string s in place
void reverse(char *s)
{
	int c;
	char *si = s;
	char *sj = s + strlen(s) - 1;

	// for (i = 0, j = strlen(s)-1; i < j; i++, j--) {
	while (si < sj) {
		c = *si;
		*si++ = *sj;
		*sj-- = c;
	}
}

// Page 69, PDF 83
// strindex: return index of t in s, -1 if none
int strindex(char *s, char *t)
{
	char* s2;
	char* t2;
	// for (i = 0; s[i] != '\0'; i++) {
	for (; *s != '\0'; s++) {

		// for (j=i, k=O; t[k] !='\0' && s[j]==t[k]; j++, k++);
		for (s2=s, t2=t; *t2 !='\0' && *s2==*t2; s2++, t2++);
		
		// if (k > 0 && t[k] == '\0')
		if (t2 > t && *t2 == '\0')
			return i;
	}
	return -1;
}

// Page 78, PDF 92
// getop: get next operator or numeric operand
int getop(char *s)
{
	int c;
	
	while ((*s = c = getch()) == ' ' || c == '\t');
	*(++s) = '\0';

	if (!isdigit(c) && c != '.')
		return c; // not a number
	
	// i = 0;
	s--;
	if (isdigit(c)) // collect integer part
		while (isdigit(*(++s) = c = getch()));
	
	if (c == '.')
		while (isdigit(*(++s) = c = getch()));
	*s = '\0';
	
	if (c != EOF)
		ungetch(c);

	return NUMBER;
}