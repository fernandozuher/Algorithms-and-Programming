/*
Author: Fernando Zuher
Place: Brazil
Date: 6 May 2020
Book: The C programming language, second edition. Authors: BRIAN W KERNIGHAN and DENNIS M. RITCHIE
About: Exercise, Chapter 7 - Input and Output
*/

/*
PDF 179, Page 165

Exercise 7-7. Modify the pattern finding program of Chapter 5 to take its input
from a set of named files or, if no files are named as arguments, from the stand-
ard input. Should the file name be printed when a matching line is found?
*/

#include <stdio.h>
#include <string.h> // strstr()
#define MAXLINE 1000

int getline2(char *s, int lim);

/* find: print lines that match pattern from 1st arg */
int main(int argc, char *argv[])
{
	char line[MAXLINE];
	int found = 0;

	if (argc == 1)
		printf ("Usage: find pattern\n");

	else if (argc == 2) {
		while (getline2(line, MAXLINE) > 0)
			if (strstr(line, argv[1]) != NULL) {
				printf("%s", line);
				found++;
			}
	}

	else {
		int i = 2;
		while (--argc > 1) {

			FILE *fp;
			if (fp = fopen(argv[i++], "r")) {
				
				printf("\nFile: %s\n", argv[i-1]);
				while (fgets(line, MAXLINE, fp))
					if (strstr(line, argv[1]) != NULL) {
						printf("\t- %s", line);
						found++;
					}

				fclose(fp);
			}
			else
				printf("\nError opening file: %s\n", argv[i-1]);
		}
	}
	printf("\n");

	return found;
}

// getline: get line into s, return length
int getline2(char *s, int lim)
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