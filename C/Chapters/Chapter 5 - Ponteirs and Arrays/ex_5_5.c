/*
Author: Fernando Zuher
Place: Brazil
Date: 26/03/2020
Book: The C programming language, second edition. Authors: BRIAN W KERNIGHAN and DENNIS M. RITCHIE
About: Exercise, Chapter 5 - Pointers and Arrays
*/

/*
Exercise 5-5. Write versions of the library functions strncpy, strncat, and
strncmp; which operate on at most the first n characters of their argument
strings. For example, strncpy (s, t, n) copies at most n characters of t to s.
Full descriptions are in Appendix B.
*/

#include <stdio.h>
#include <string.h> // strlen()

char* strncpy2 (char* s, const char* t, size_t n);
char* strncat2 (char* s, const char* t, size_t n);
int strncmp2 (const char* s, const char* t, size_t n);

int main()
{
	char s1[50] = "Lorem ipsum...";
	char s2[50] = "Lorem ipsum...";
	char *s3 = "Lorem ipsum...";
	char *s4 = "Lorem ipsum...";
	char *s5 = "Lorem jpsum...";
	char *s6 = "Lorem ipsum...";
	const char* t = "until hereNot from here.";
	size_t n = 10;
	
	printf("\nOriginal-destination string, s = %s", s1);
	printf("\nConstant-source string, t = %s", t);
	printf("\nn = %ld", n);

	printf("\n\nstrncpy: %s", strncpy2(s1, t, n));
	printf("\nstrncat: %s", strncat2(s2, t, n));

	printf("\n\ns3 = %s\ns4 = %s", s3, s4);
	printf("\n\tstrncmp: %d", strncmp2(s3, s4, n));
	
	printf("\n\ns4 = %s\ns5 = %s", s4, s5);
	printf("\n\tstrncmp: %d", strncmp2(s4, s5, n));
	
	printf("\n\ns5 = %s\ns6 = %s", s5, s6);
	printf("\n\tstrncmp: %d", strncmp2(s5, s6, n));

	printf("\n");
	return 0;
}

char* strncpy2 (char* s, const char* t, size_t n)
{
	int count = 0;
	while (n-- > 0 && (*s++ = *t++)) // (*s++ = *t++) != '\0'
		count++; 
	*s = '\0';

	return s - count;
}

char* strncat2 (char* s, const char* t, size_t n)
{
	int count = 0, size_s = strlen(s);
	s = s + size_s;

	while (n-- > 0 && (*s++ = *t++)) // (*s++ = *t++) != '\0'
		count++;
	*s = '\0';

	return s - size_s - count;
}

int strncmp2 (const char* s, const char* t, size_t n)
{
	for ( ; n-- > 0 && *s == *t; s++, t++)
		if (*s == '\0')
			return 0;
		
	return *s - *t;
}