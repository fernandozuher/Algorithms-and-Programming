/*
Author: Fernando Zuher
Place: Brazil
Date: 29 April 2020
Book: The C programming language, second edition. Authors: BRIAN W KERNIGHAN and DENNIS M. RITCHIE
About: Exercise, Chapter 7 - Input and Output
*/

/*
PDF 173, Page 159

Exercise 7-4. Write a private version of scanf analogous to minscanf from
the previous section.

The format string usually contains conversion specifications, which are used
to control conversionof input. The format string may contain:
	• Blanks or tabs, which are ignored.
	• Ordinary characters (not %), which are expected to match the next non-white space
	character of the input stream.
	• Conversion specifications, consisting of the character %, an optional assignment
	suppression character *, an optional number specifying a maximum field width, an
	optional h, l, or L indicating the width of the target, and a conversion character.
*/

#include <stdio.h>
#include <ctype.h> // isspace()
#include <string.h> // strcat()

#define MAX 50

void minscanf(char *fmt, ...);

int main()
{
// TEST INPUT /////////////////////////////////////////////////////
// Ctrl C + Ctrl V in the input:
// 1 2 3 075 075 0xfe 7 8 9.98765 10.98765 11.5 f zuher fernando
	
	short hd;
	int d, i;
	unsigned int o, x, u;
	long int ld;

	float f;
	double lf;
	
	char c;
	char s[MAX], s3[MAX];

	printf("\n%%hd %%d %%*d %%i %%o %%x %%u %%ld %%f %%*f %%lf %%c %%s %%3s");
	printf("\n: ");
	minscanf("%hd %d %*d %i %o %x %u %ld %f %*f %lf %c %s %3s", &hd, &d, &d, &i, &o, &x, &u, &ld, &f, &f, &lf, &c, &s, &s3);

	printf("\n%%hd = %hd", hd);
	printf("\n%%d = %d", d);
	printf("\n%%i = %i", i);
	printf("\n%%o = %o", o);
	printf("\n%%x = %x", x);
	printf("\n%%u = %u", u);
	printf("\n%%ld = %ld", ld);
	printf("\n%%f = %f", f);
	printf("\n%%lf = %lf", lf);
	printf("\n%%c = %c", c);
	printf("\n%%s = %s", s);
	printf("\n%%3s = %s", s3);

	printf("\n\n");
	return 0;
}

#include <stdarg.h>
void minscanf(char *fmt, ...)
{
	va_list ap; // points to each unnamed arg in turn
	
	char *p;
	int width = 0, width_flag = 0;

	char buffer[MAX];
	int size_buffer = 0;

	char temp[10] = {""}, temp_width[10], c_temp[2] = {""};

	int skip = 0, h = 0, l = 0; // skip -> *, h -> short, l -> long
	
// Variables receive addresses from va_arf() /////////////////
	char *cval, *sval;

	short *h_ival;
	unsigned short int *u_h_ival;
	int *ival;
	unsigned int *u_ival;
	long int *l_ival;
	unsigned long int *u_l_ival;

	float *fval;
	double *l_fval;
///////////////////////////////////////////////////

	printf("\n");
	va_start(ap, fmt); // make ap point to 1st unnamed arg
	for (p = fmt; *p; p++) {

		// Blanks or tabs, which are ignored.
		if (isspace(*p))
			continue;

		// Conversion specifications, consisting of the character %, an optional assignment
		// suppression character *, an optional number specifying a maximum field width, an
		// optional h, l, or L indicating the width of the target, and a conversion character.
		switch (*p) {

			case '*':

				skip = 1;
				break;

			case '0': case '1': case '2': case '3': case '4':
			case '5': case '6': case '7': case '8': case '9':

				width = width * 10 + (*p - '0');
				width_flag = 1;
				break;

			case 'h':
				h = 1;
				break;

			case 'l': case 'L':
				l = 1;
				break;

			case 'd': case 'i': case 'o': case 'x': case 'X': case 'u':

				strcat(temp, "%");

				if (skip)
					strcat(temp, "*");

				if (width_flag) {
					sprintf(temp_width, "%d", width);
					strcat(temp, temp_width);
				}

				if (h) // 'h' has higher priority than 'l'
					strcat(temp, "h");
				if (l) 
					strcat(temp, "l");
				
				c_temp[0] = p[0];
				strcat(temp, c_temp);

				if (*p == 'd' || *p == 'i') {
					if (h) {
						h_ival = va_arg(ap, short*);
						scanf(temp, h_ival);
					}
					else if (l) {
						l_ival = va_arg(ap, long int*);
						scanf(temp, l_ival);
					}
					else {
						ival = va_arg(ap, int*);
						scanf(temp, ival);
					}
				}
				else {
					if (h) {
						u_h_ival = va_arg(ap, unsigned short int*);
						scanf(temp, u_h_ival);
					}
					else if (l) {
						u_l_ival = va_arg(ap, unsigned long int*);
						scanf(temp, u_l_ival);
					}
					else {
						u_ival = va_arg(ap, unsigned int*);
						scanf(temp, u_ival);
					}
				}

				strcpy(temp, "");
				skip = h = l = 0;
				width = width_flag = 0;
				break;

			case 'c':

				if (skip) {
					while (isspace(getchar()));
					skip = 0;
				}
				else {
					cval = va_arg(ap, char*);
					while (isspace(*cval = getchar()));
				}

				break;

			case 's':

				strcat(temp, "%");

				if (skip)
					strcat(temp, "*");

				if (width_flag) {
					sprintf(temp_width, "%d", width);
					strcat(temp, temp_width);
				}

				c_temp[0] = p[0];
				strcat(temp, c_temp);

				// To remove potential white space added by previous inputs
				while (isspace(*cval = getchar()));
				ungetc(*cval, stdin);

				sval = va_arg(ap, char*);
				scanf(temp, sval);

				strcpy(temp, "");
				skip = width = width_flag = 0;
				break;

			case 'e': case 'E': case 'f':

				strcat(temp, "%");

				if (skip)
					strcat(temp, "*");

				if (width_flag) {
					sprintf(temp_width, "%d", width);
					strcat(temp, temp_width);
				}

				if (l) {
					strcat(temp, "l");
					
					c_temp[0] = p[0];
					strcat(temp, c_temp);

					l_fval = va_arg(ap, double*);
					scanf(temp, l_fval);
				}
				else {
					c_temp[0] = p[0];
					strcat(temp, c_temp);
					
					fval = va_arg(ap, float*);
					scanf(temp, fval);
				}

				skip = l = 0;
				strcpy(temp, "");
				break;

			//case 'g':
			//case 'G':
			//	dval = va_arg(ap, double);
			//	printf ("%g", dval);
			//	break;

			// default:
			// 	Ordinary characters (not %), which are expected to match
			// 	the next non-white space character of the input stream.
			// 	buffer[size_buffer++] = *p;
			// 	break;
		}
	}
	va_end(ap); // clean up when done
}