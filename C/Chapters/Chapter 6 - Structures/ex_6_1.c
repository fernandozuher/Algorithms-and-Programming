/*
Author: Fernando Zuher
Place: Brazil
Date: 16/04/2020
Book: The C programming language, second edition. Authors: BRIAN W KERNIGHAN and DENNIS M. RITCHIE
About: Exercise, Chapter 6 - Structures
*/

/*
PDF 150, Page 136

Exercise 6-1. Our version of getword does not properly handle underscores,
string constants, comments, or preprocessor control lines. Write a better version.

OBS: The exercise is not clear what it means with "...does not properly handle underscores,
string constants, comments, or preprocessor control lines". Whether it is to be used
inside the keytab array, whether the keywords may be found inside those things...

Herein is considered those things as individual elements inside the keytab array.

*/

#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include "getch.h"

#define MAXWORD 100
#define NKEYS (sizeof keytab / sizeof keytab[0])

// 44 keywords until C18
struct key {
	char *word;
	int count;
} keytab[] = {
	"\"string constant\"", 0,
	"#preprocessor control line", 0,
	"/* multiline comment */", 0,
	"// single line comment", 0,
	"_Alignas", 0,
	"_Alignof", 0,
	"_Atomic", 0,
	"_Bool", 0,
	"_Complex", 0,
	"_Generic", 0,
	"_Imaginary", 0,
	"_Noreturn", 0,
	"_Static_assert", 0,
	"_Thread_local", 0,
	"auto", 0,
	"break", 0,
	"case", 0,
	"char", 0,
	"const", 0,
	"continue", 0,
	"default", 0,
	"do", 0,
	"double", 0,
	"else", 0,
	"enum", 0,
	"extern", 0,
	"float", 0,
	"for", 0,
	"goto", 0,
	"if", 0,
	"inline", 0,
	"int", 0,
	"long", 0,
	"register", 0,
	"restrict", 0,
	"return", 0,
	"short", 0,
	"signed", 0,
	"sizeof", 0,
	"static", 0,
	"struct", 0,
	"switch", 0,
	"typedef", 0,
	"union", 0,
	"unsigned", 0,
	"void", 0,
	"volatile", 0,
	"while", 0
};

int getword(char *, int);
int binsearch(char *, struct key *, int);

void print_keytab();
int isalpha2(int c);

/* count C keywords */
int main()
{
	int n;
	char word[MAXWORD];
	while (getword(word, MAXWORD) != EOF)
		if (isalpha2(word[0]))
			if ((n = binsearch(word, keytab, NKEYS)) >= 0)
				keytab[n].count++;
	
	print_keytab();		
	return 0;
}

/* binsearch: find word in tab[0] ...tab[n-1] */
int binsearch(char *word, struct key tab[], int n)
{
	int cond;
	int low, high, mid;
	
	low = 0;
	high = n - 1;
	while (low <= high) {
		mid = (low+high) / 2;
		if ((cond = strcmp(word, tab[mid].word)) < 0)
			high = mid - 1;
		else if (cond > 0)
			low = mid + 1;
		else
			return mid;
	}
	return -1;
}

/* getword: get next word or character from input */
int getword(char *word, int lim)
{
	int c;
	char *w = word;
	while (isspace(c = getch()));

	if (c != EOF)
		*w++ = c;

	if (!isalpha2(c)) {
		*w = '\0';
		return c;
	}
	
	for ( ; --lim > 0; w++)
		if (!isalnum(*w = getch()) && !isalpha2(*w)) {
			ungetch(*w);
			break;
		}
	*w = '\0';
	
	if (word[0] == '"' && *--w == '"') // if word is string constant
		strcpy(word, "\"string constant\"");

	else if (word[0] == '/' && word[1] == '/') // if word is single line comment
		strcpy(word, "// single line comment");

	else if (word[0] == '/' && word[1] == '*') // if word is a multiline comment
		strcpy(word, "/* multiline comment */");

	else if (word[0] == '#') // if word is a preprocessor control line
		strcpy(word, "#preprocessor control line");
	
	return word[0];
}

void print_keytab() {

	for (int n = 0; n < NKEYS; n++)
		if (keytab[n].count > 0)
			printf ("\n%d %s", keytab[n].count, keytab[n].word);

	printf("\n");
}

int isalpha2(int c){

	if (isalpha(c) || c == '_' || c == '"' || c == '/' || c == '*' || c == '#')
		return 1;
	return 0;
}