/*
Author: Fernando Zuher
Place: Brazil
Date: 28/03/2020
Book: The C programming language, second edition. Authors: BRIAN W KERNIGHAN and DENNIS M. RITCHIE
About: Exercise, Chapter 5 - Pointers and Arrays
*/

/*
Exercise 5-13. Write the program tail, which prints the last n lines of its
input. By default, n is 10, let us say, but it can be changed by an optional
argument, so that

tail -n

prints the last n lines. The program should behave rationally no matter how
unreasonable the input or the value of n. Write the program so it makes the
best use of available storage; lines should be stored as in the sorting program of
Section 5.6, not in a two-dimensional array of fixed size.
*/

#include <stdio.h>
#include <stdlib.h> // atoi()
#include <string.h> // strlen()
#include <ctype.h> // isdigit()

int check_argument(int argc, char* argv[]);
void my_input();
int tail(int argc, char* argv[]);

int main(int argc, char* argv[])
{
	if (check_argument(argc, argv) >= 0) {
		my_input();
		tail(argc, argv);
		return 0;
	}
	else
		return 1;
}

static int n = 10;
int check_argument(int argc, char* argv[]) {

	if (argc > 2) {
		printf("\nUsage: 'tail -n' (n = number of last input lines to be printed) or just 'tail'.\n");
		return -1;
	}
	else if (argc == 2) {
		if (argv[1][0] == '-')
			++argv[1];

		if(!isdigit(*argv[1])) {
			printf("\nYour number of last lines to be printed doesn't "
						"seem to be a valid non-negative number. Check it.\n");
			return -1;
		}		
		return n = atoi(argv[1]);
	}
}

#define MAXSIZE 1000
static char* input[MAXSIZE];
static int lines = 0;
void my_input()
{
	char temp[1000], *line;
	printf("\nInput text. Control + D (EOF) to finish:\n");
	
	while(fgets(temp, MAXSIZE, stdin)) {
		line = (char*) malloc(sizeof(char) * strlen(temp));
		strcpy(line, temp);
		input[lines++] = line;
	}
}

int tail(int argc, char* argv[])
{
	int i = 0, n_set;

	if (lines-n < 0)
		printf("\nIt is required to print the last %d line(s) of your input, "
			"\nbut this has less lines than that (%d line(s)). There it goes:\n", n, n_set=lines);
	else if (!n) {
		printf("\tSo you want to print nothing? Last %d line? Como quiser...\n", n_set=n);
		i = lines; // lines - n = lines - 0 = lines
	}
	else {
		printf("\nLast %d line(s):\n", n_set=n);
		i = lines - n;
	}

	while (i < lines)
		printf("%s", input[i++]);

	return n_set;
}