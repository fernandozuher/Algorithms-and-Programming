/*
Author: Fernando Zuher
Place: Brazil
Date: 6 May 2020
Book: The C programming language, second edition. Authors: BRIAN W KERNIGHAN and DENNIS M. RITCHIE
About: Exercise, Chapter 7 - Input and Output
*/

/*
PDF 179, Page 165

Exercise 7-8. Write a program to print a set of files, starting each new one on a 
new page, with a title and a running page count for each file.
*/

#include <stdio.h>
#include <stdlib.h>
#define MAXLINE 1000

int main(int argc, char *argv[])
{
	if (argc == 1)
		printf ("Usage: file(s) to be printed");

	else {
		char line[MAXLINE];
		int i = 1, pages = 0;

		while (--argc > 0) {
			
			FILE *fp;
			pages++;
			if (fp = fopen(argv[i++], "r")) {
				printf("\nFile: %s. Page: %d.\n\n", argv[i-1], pages);

				while (fgets(line, MAXLINE, fp))
					printf("%s", line);
				fclose(fp);
			}
			else
				printf("\nError opening file: %s. Page: %d.", argv[i-1], pages);
			printf("\n\n------------------------------------\n");
		}
	}
	printf("\n");
}