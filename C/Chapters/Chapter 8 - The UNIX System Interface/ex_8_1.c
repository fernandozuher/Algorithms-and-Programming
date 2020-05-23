/*
Author: Fernando Zuher
Place: Brazil
Date: 22 May 2020
Book: The C programming language, second edition. Authors: BRIAN W KERNIGHAN and DENNIS M. RITCHIE
About: Exercise, Chapter 8 - The UNIX System Interface
*/

/*
PDF 188, Page 174

Exercise 8-1. Rewrite the program cat from Chapter 7 using read, write,
open and close instead of their standard library equivalents. Perform experi-
ments to determine the relative speeds of the two versions.
*/

#include <stdio.h>
#include <stdlib.h> // exit()
#include <fcntl.h> // O_RDONLY, O_WRONLY, O_RDWR, open()
#include <unistd.h> // read(), write(), close()

int main(int argc, char *argv[])
{
	int fd;
	void filecopy(int, int);
	char *prog = argv[0]; /* program name for errors */
	
	if (argc == 1) /* no args; copy standard input */
		filecopy(0, 1);
	else
		while (--argc > 0)
			if ((fd = open(*++argv, O_RDONLY, 0)) == -1) {
				fprintf(stderr, "%s: can't open %s\n", prog, *argv);
				exit(1);
			}
			else {
				filecopy(fd, 1);
				close(fd);
			}
	
	if (ferror(stdout)) {
		fprintf(stderr, "%s: error writing stdout\n", prog);
		exit(2);
	}
	exit(0);
}

/* filecopy: copy file ifp to file ofp */
void filecopy(int ifd, int ofd)
{
	int c;
	while (read(ifd, &c, 1) == 1)
		write(ofd, &c, 1);
}