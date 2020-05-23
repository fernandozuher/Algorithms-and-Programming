/*
Author: Fernando Zuher
Place: Brazil
Date: 23 May 2020
Book: The C programming language, second edition. Authors: BRIAN W KERNIGHAN and DENNIS M. RITCHIE
About: Exercise, Chapter 8 - The UNIX System Interface
*/

/*
PDF 192, Page 178

Exercise 8-2. Rewrite fopen and _fillbuf with fields instead of explicit bit
operations. Compare code size and execution speed.
*/

FILE *fopen(char *name, char *mode):
	...
	if ((fp->flag != _READ ||  fp->flag != _WRITE) == 0)
		break;


// DON'T KNOW. TO DO:
int _fillbuf(FILE *fp):

	if ((fp->flag&(_READ | _EOF | _ERR)) != _READ)
		return EOF;

	bufsize = (fp->flag & _UNBUF) ? 1 : BUFSIZ;

	if (fp->cnt == -1)
		fp->flag |= _EOF;
	else
		fp->flag |= _ERR;


