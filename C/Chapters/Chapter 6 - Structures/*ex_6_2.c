/*
Author: Fernando Zuher
Place: Brazil
Date: 16/04/2020
Book: The C programming language, second edition. Authors: BRIAN W KERNIGHAN and DENNIS M. RITCHIE
About: Exercise, Chapter 6 - Structures
*/

/*
PDF 157, Page 143

Exercise 6-2. Write a program that reads a C program and prints in alphabetical
order each group of variable names that are identical in the first 6 characters,
but different somewhere thereafter. Don't count words within strings and
comments. Make 6 a parameter that can be set from the command line.
*/

#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include "getch.h"

#define MAXWORD 100
struct tnode *addtree(struct tnode *, char *);
void treeprint(struct tnode *);
int getword(char *, int);

struct tnode {
	char *word;
	int count;
	struct tnode *left;
	struct tnode *right;
};

int main()
{
	struct tnode *root;
	char word[MAXWORD];
	
	root = NULL;
	while (getword(word, MAXWORD) != EOF)
		if (isalpha(word[0]))
			root = addtree(root, word);
	
	treeprint(root);
	return 0;
}

struct tnode *talloc(void);
char *strdup2(char *);

struct tnode *addtree(struct tnode *p, char *w)
{
	int cond;
	if (p == NULL) {

		p = talloc();
		p->word = strdup2(w);
		p->count = 1;
		p->left = p->right = NULL;
	
	} else if ((cond = strcmp(w, p->word)) == 0)
		p->count++;
	
	else if (cond < 0)
		p->left = addtree(p->left, w);
	
	else
		p->right = addtree(p->right, w);
	
	return p;
}

void treeprint(struct tnode *p)
{
	if (p != NULL) {
		treeprint(p->left);
		printf("%4d %s\n", p->count, p->word);
		treeprint(p->right);
	}
}

#include <stdlib.h>
struct tnode *talloc(void)
{
	return (struct tnode *) malloc(sizeof(struct tnode));
}

char *strdup2(char *s)
{
	char *p;

	p = (char *) malloc(strlen(s)+1);
	if (p != NULL)
		strcpy(p, s);
	return p;
}

int isalpha2(int c);
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
	
	return word[0];
}

int isalpha2(int c){

	if (isalpha(c) || c == '_' || c == '"' || c == '/' || c == '*' || c == '#')
		return 1;
	return 0;
}