/*
Author: Fernando Zuher
Place: Brazil
Date: 17/04/2020
Book: The C programming language, second edition. Authors: BRIAN W KERNIGHAN and DENNIS M. RITCHIE
About: Exercise, Chapter 6 - Structures
*/

/*
Exercise 6-3. Write a cross-referencer that prints a list of all words in a docu-
ment, and, for each word, a list of the line numbers on which it occurs. Remove
noise words like "the," "and," and so on.

Sample input:
	Lorem ipsum dolor sit amet, consectetur adipisicing elit, sed do eiusmod
	tempor incididunt ut labore et dolore magna aliqua. Ut enim ad minim veniam,
	quis nostrud exercitation ullamco laboris nisi ut aliquip ex ea commodo
	consequat. Duis aute irure dolor in reprehenderit in voluptate velit esse
	cillum dolore eu fugiat nulla pariatur. Excepteur sint occaecat cupidatat non
	proident, sunt in culpa qui officia deserunt mollit anim id est laborum.
	Ctrl + D (EOF)
*/

#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include "getch.h"

#define MAXWORD 100
#define MAXLINES 100

struct tnode *addtree(struct tnode *, char *);
void treeprint(struct tnode *);
int getword(char *, int);

struct tnode {
	int n_lines;
	short lines[MAXLINES];
	char *word;

	struct tnode *left;
	struct tnode *right;
};

static int total_lines = 0;

int main()
{
	struct tnode *root;
	char word[MAXWORD];
	
	root = NULL;
	while (getword(word, MAXWORD) != EOF)
		if (isalpha(word[0]))
			root = addtree(root, word);

	printf("\n");	
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
		p->n_lines = 0;
		p->lines[p->n_lines++] = total_lines;
		p->left = p->right = NULL;
	
	} else if ((cond = strcmp(w, p->word)) == 0) {
		if (p->lines[p->n_lines-1] != total_lines)
			p->lines[p->n_lines++] = total_lines;
	}

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
		printf("%s: ", p->word);

		for (int i = 0; i < p->n_lines-1; i++)
			printf("%d, ", p->lines[i]+1);
		
		printf("%d\n", p->lines[p->n_lines-1]+1);

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
	while (isspace(c = getch()))
		if (c == '\n')
			total_lines++;

	if (c != EOF)
		*w++ = c;

	if (!isalpha2(c)) {
		*w = '\0';
		return c;
	}

	for ( ; --lim > 0; w++)
		if (!isalnum(*w = getch())) {
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