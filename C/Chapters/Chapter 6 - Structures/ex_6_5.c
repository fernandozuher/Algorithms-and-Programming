/*
Author: Fernando Zuher
Place: Brazil
Date: 17/04/2020
Book: The C programming language, second edition. Authors: BRIAN W KERNIGHAN and DENNIS M. RITCHIE
About: Exercise, Chapter 6 - Structures
*/

/*
PDF 159, Page 145

Exercise 6-5. Write a function undef that will remove a name and definition
from the table maintained by lookup and install.
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct nlist {           /* table entry: */
	struct nlist *next;  /* next entry in chain */
	char *name;          /* defined name */
	char *defn;          /* replacement text */
};

#define HASHSIZE 101
static struct nlist *hashtab[HASHSIZE]; /* pointer table */

void initialize_sample();
struct nlist *install(char *name, char *defn);
struct nlist *lookup(char *s);
int undef(char *s);
void print_hashtable();

int main(int argc, char const *argv[])
{
	struct nlist *p;

	initialize_sample();


// TESTING //////////////////////////////////////////
	print_hashtable();
	printf("\n\n");

	if (p = lookup("Lorem"))
		printf("FOUND: %s %s\n", p->name, p->defn);
	else
		printf("NOT FOUND: %s\n", "Lorem");

	int index;
	if ((index = undef("Lorem")) != -1) {
		printf("REMOVED: %s from index %d: ", "Lorem", index);

		struct nlist *walker = hashtab[index];
		while (walker) {
		printf("%s %s ---> ", walker->name, walker->defn);
			walker = walker->next;
		}
		printf("NULL\n");
	}
	else
		printf("NOT FOUND to be REMOVED: %s\n", "Lorem");

	if (p = lookup("Lorem"))
		printf("FOUND: %s %s\n", p->name, p->defn);
	else
		printf("NOT FOUND: %s\n", "Lorem");
/////////////////////////////////////////////////////
	
	printf("\n");
	return 0;
}

void initialize_sample()
{
	install("Lorem", "KEY_Lorem");
	install("ipsum", "KEY_ipsum");
	install("dolor", "KEY_dolor");
	install("sit", "KEY_sit");
	install("amet", "KEY_amet");
	install("consectetur", "KEY_consectetur");
	install("adipisicing", "KEY_adipisicing");
	install("elit", "KEY_elit");
	install("sed", "KEY_sed");
	install("do", "KEY_do");
	install("eiusmod", "KEY_eiusmod");
	install("incididunt", "KEY_incididunt");
	install("ut", "KEY_ut");
	install("labore", "KEY_labore");
	install("et", "KEY_et");
	install("dolore", "KEY_dolore");
	install("magna", "KEY_magna");
	install("aliqua", "KEY_aliqua");
	install("Ut", "KEY_Ut");
	install("enim", "KEY_enim");
	install("ad", "KEY_ad");
	install("minim", "KEY_minim");
	install("veniam", "KEY_veniam");
	install("nostrud", "KEY_nostrud");
	install("exercitation", "KEY_exercitation");
	install("ullamco", "KEY_ullamco");
	install("laboris", "KEY_laboris");
	install("nisi", "KEY_nisi");
	install("ut", "KEY_ut");
	install("aliquip", "KEY_aliquip");
	install("ex", "KEY_ex");
	install("ea", "KEY_ea");
	install("commodo", "KEY_commodo");
	install("Duis", "KEY_Duis");
	install("aute", "KEY_aute");
	install("irure", "KEY_irure");
	install("dolor", "KEY_dolor");
	install("in", "KEY_in");
	install("reprehenderit", "KEY_reprehenderit");
	install("in", "KEY_in");
	install("voluptate", "KEY_voluptate");
	install("velit", "KEY_velit");
	install("esse", "KEY_esse");
	install("dolore", "KEY_dolore");
	install("eu", "KEY_eu");
	install("fugiat", "KEY_fugiat");
	install("nulla", "KEY_nulla");
	install("pariatur", "KEY_pariatur");
	install("Excepteur", "KEY_Excepteur");
	install("sint", "KEY_sint");
	install("occaecat", "KEY_occaecat");
	install("cupidatat", "KEY_cupidatat");
	install("non", "KEY_non");
	install("sunt", "KEY_sunt");
	install("in", "KEY_in");
	install("culpa", "KEY_culpa");
	install("qui", "KEY_qui");
	install("officia", "KEY_officia");
	install("deserunt", "KEY_deserunt");
	install("mollit", "KEY_mollit");
	install("anim", "KEY_anim");
	install("id", "KEY_id");
	install("est", "KEY_est");
	install("laborum", "KEY_laborum");
}

void print_hashtable() {

	struct nlist *walker;
	
	printf("\nHASH TABLE:");
	for (int i = 0; i < HASHSIZE; ++i) 
		
		if (walker = hashtab[i]) {
			printf("\n\t%d: ", i);

			while (walker) {
				printf("%s %s ---> ", walker->name, walker->defn);
				walker = walker->next;
			}
			printf("NULL");
		}
}

unsigned hash(char *s);

int undef(char *s)
{
	struct nlist *prev, *np;

	for (prev = np = hashtab[hash(s)]; np != NULL; np = np->next) {

		if (strcmp(s, np->name) == 0) {
			
			// It may be clearer if was written: if (np != hashtab[hash(s)])
			// but it was written the following in order to avoid the cost of calling
			// again hash(s)

			// If it is not the first struct pointed by the hash(s) index array
			if (prev != np)
				prev->next = np->next;
			else
				hashtab[hash(s)] = NULL; // if so

			free((void *) np->name);
			free((void *) np->defn);
			free((void *) np);

			return hash(s);
		}
		prev = np;
	}
	return -1; /* not found */
}

/* hash: form hash value for string s */
unsigned hash(char *s)
{
	unsigned hashval;
	for (hashval = 0; *s != '\0'; s++)
		hashval = *s + 31 * hashval;
	return hashval % HASHSIZE;
}

/* lookup: look for s in hashtab */
struct nlist *lookup(char *s)
{
	struct nlist *np;

	for (np = hashtab[hash(s)]; np != NULL; np = np->next)
		if (strcmp(s, np->name) == 0)
			return np; /* found */
	return NULL; /* not found */
}

struct nlist *lookup(char *);
char *strdup2(char *);

/* install: put (name, defn) in hashtab */
struct nlist *install(char *name, char *defn)
{
	struct nlist *np;
	unsigned hashval;
	if ((np = lookup(name)) == NULL) { /* not found */
		
		np = (struct nlist *) malloc(sizeof(*np));
		
		if (np == NULL || (np->name = strdup(name)) == NULL)
			return NULL;
		
		hashval = hash(name);
		np->next = hashtab[hashval];
		hashtab[hashval] = np;
	}
	else /* already there */
		free((void *) np->defn); /* free previous defn */
	
	if ((np->defn = strdup(defn)) == NULL)
		return NULL;
	
	return np;
}

char *strdup2(char *s)
{
	char *p;

	p = (char *) malloc(strlen(s)+1);
	if (p != NULL)
		strcpy(p, s);
	return p;
}