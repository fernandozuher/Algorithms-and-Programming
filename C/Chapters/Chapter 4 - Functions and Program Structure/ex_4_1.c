/*
Author: Fernando Zuher
Place: Brazil
Date: 25/02/2020
Book: The C programming language, second edition. Authors: BRIAN W KERNIGHAN and DENNIS M. RITCHIE
About: Exercise, Chapter 4 - Functions and Program Structure
*/

/*
Exercise 4-1. Write the function strrindex(s, t),
which returns the position of the rightmost
occurrence of t in s, or -1 if there is none.
Input sampĺe:
	abcdefouldabcdefouldabc
	abcdefouldabcdefouldaould
	Lorem ipsum dolor sit amet, consectetur adipisicing elit, sed do eiusmod
	proident, sunt in couldulpa qui officia deserunt mollit anim id est laborum.
*/

#include <stdio.h>
#define MAXLINE 1000 /* maximum input line length */

int getline2(char line[], int max);
int strindex2(char source[], char searchfor[]);
char pattern[] = "ould"; /* pattern to search for */

/* find all lines matching pattern */
int main()
{
	char line[MAXLINE];
	int found = 0, index;
	
	while (getline2(line, MAXLINE) > 0)		
		if ((index = strindex2(line, pattern)) >= 0) {
			printf("\tRightmost occurence of pattern (\"%s\") found in index: %d.\n\n", pattern, index);
			found++;
		}
		else printf("\tNot found pattern (\"%s\").\n\n", pattern);

	return found;
}

/* getline: get line into s, return length */
int getline2(char s[], int lim)
{
	int c, i;
	
	i =	0;
	while (--lim> 0 && (c=getchar()) !=	EOF && c!= '\n')
		s[i++] = c;
	
	if (c == '\n')
		s[i++] = c;
	
	s[i] = '\0';
	return i;
}

/* strindex: return the position of the rightmost
occurrence of t in s, or -1 if there is none. */
int strindex2(char s[], char t[])
{
	int i, j, k, index = -1;

	for (i = 0; s[i] != '\0'; i++) {
		for (j=i, k=0; t[k]!='\0' && s[j]==t[k]; j++, k++);
		
		if (k > 0 && t[k] == '\0')
			index = i;
	}
	return index;
}