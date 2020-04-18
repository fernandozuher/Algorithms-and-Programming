/*
Author: Fernando Zuher
Place: Brazil
Date: 17/04/2020
Book: The C programming language, second edition. Authors: BRIAN W KERNIGHAN and DENNIS M. RITCHIE
About: Exercise, Chapter 6 - Structures
*/

/*
PDF 157, Page 143

Exercise 6-4. Write a program that prints the distinct words in its input sorted
into decreasing order of frequency of occurrence. Precede each word by its
count.

Sample input:
	Abc, abc abc... Def def
	Abc abc, abc: Def, def
	Abc abc. abc Def def?
	za za za 123; 123, 123
	a b c 1 2 3.
	Ctrl + D (EOF)
*/

#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include "getch.h"

#define MAXWORD 100
#define MAXLINES 100

int getword(char *, int);
struct tnode *addtree(struct tnode *, char *);

void tree_to_array(struct tnode *p);
int isalnum2(int c);
void array_print();

struct tnode {
	char *word;
	int count;
	struct tnode *left;
	struct tnode *right;
	struct tnode *list;
};

int main()
{
	struct tnode *root;
	char word[MAXWORD];
	
	root = NULL;
	while (getword(word, MAXWORD) != EOF)
		if (isalnum2(word[0]))
			root = addtree(root, word);

	tree_to_array(root);
	printf("\n");	
	array_print();
	return 0;
}

int getword(char *word, int lim)
{
	int c;
	char *w = word;
	while (isspace(c = getch()));

	if (c != EOF)
		*w++ = c;

	if (!isalnum2(c)) {
		*w = '\0';
		return c;
	}

	for ( ; --lim > 0; w++)
		if (!isalnum2(*w = getch())) {
			ungetch(*w);
			break;
		}
	*w = '\0';
	
	return word[0];
}

int isalnum2(int c){

	if (isalnum(c) || c == '_' || c == '"' || c == '/' || c == '*' || c == '#')
		return 1;
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
		p->list = NULL;
		p->left = p->right = NULL;
	
	} else if ((cond = strcmp(w, p->word)) == 0)
		p->count++;

	else if (cond < 0)
		p->left = addtree(p->left, w);
	
	else
		p->right = addtree(p->right, w);
	
	return p;
}

static struct tnode *array[MAXLINES];

void tree_to_array(struct tnode *p)
{	
	if (p != NULL) {
		tree_to_array(p->left);

		if (array[p->count] == NULL) // if it is not NULL
		 	array[p->count] = p;

		else {
			struct tnode *ptr = array[p->count];
			while(ptr->list)
				ptr = ptr->list;

			ptr->list = p;
		}
		tree_to_array(p->right);
	}
}

void array_print() {

	struct tnode *ptr;
	for (int i = MAXLINES-1; i > 0; --i)
		
		if (array[i]) {
			ptr = array[i];
			printf("%d:", ptr->count);
			
			while (ptr) {
				printf(" %s", ptr->word);
				ptr = ptr->list;
			}
			printf("\n");
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
