/*
Author: Fernando Zuher
Place: Brazil
Date: 04 May 2020
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
#include <stdlib.h> // exit()

#define MAX 50

int minscanf(char *fmt, ...);

int main()
{
// TEST INPUT /////////////////////////////////////////////////////

// Ctrl C + Ctrl V in the input 1:
// 1 2 3 075 075 0xfe 7 8 9.98765 10.98765 11.5 f zuher fernando

// Ctrl C + Ctrl V in the input 2:
// day/month/year
	
	short hd;
	int d, i;
	unsigned int o, x, u;
	long int ld;

	float f;
	double lf;
	
	char c;
	char s[MAX], s3[MAX];

	printf("\nreading: %%hd %%d %%*d %%i %%o %%x %%u %%ld %%f %%*f %%lf %%c %%s %%3s");
	printf("\ninput: ");
	int num;
	num = minscanf("%hd %d %*d %i %o %x %u %ld %f %*f %lf %c %s %3s", &hd, &d, &d, &i, &o, &x, &u, &ld, &f, &f, &lf, &c, &s, &s3);

	printf("Read items = %d", num);
	printf("\n\t%%hd = %hd", hd);
	printf("\n\t%%d = %d", d);
	printf("\n\t%%i = %i", i);
	printf("\n\t%%o = %o", o);
	printf("\n\t%%x = %x", x);
	printf("\n\t%%u = %u", u);
	printf("\n\t%%ld = %ld", ld);
	printf("\n\t%%f = %f", f);
	printf("\n\t%%lf = %lf", lf);
	printf("\n\t%%c = %c", c);
	printf("\n\t%%s = %s", s);
	printf("\n\t%%3s = %s", s3);

	while(getchar() != '\n');
	int day, month, year;

	printf("\n\nreading: %%d/%%d/%%d");
	printf("\ninput: ");
	num = minscanf("%d/%d/%d", &day, &month, &year);

	printf("Read items = %d", num);
	printf("\n\t%d/%d/%d", day, month, year);

	printf("\n\n");
	return 0;
}

#include <stdarg.h>
#define FORMAT_LIM 20
void int_to_str_then_strcat(int num, char *concatenate);

int minscanf(char *fmt, ...)
{
	va_list ap; // points to each unnamed arg in turn
	int read_items = 0;

	char *p;
	int width = 0, width_flag = 0;

	char temp[FORMAT_LIM] = {""}, c_temp[2] = {""};

	int skip = 0, h = 0, l = 0, conversion = 0; // skip -> *, h -> short, l -> long
	
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

	va_start(ap, fmt); // make ap point to 1st unnamed arg
	for (p = fmt; *p; p++) {

		// Blanks or tabs, which are ignored.
		// !conversion is here to avoid going on in formats like "% d", instead "%d"
		if (isspace(*p) && !conversion) continue;

		// else '%' is not activate, so character is just a literal to be matched in the input.
		// Herein, '%' is a literal not considered to be used out of conversion scope
		else if (*p != '%' && !conversion) {
			c_temp[0] = p[0], strcat(temp, c_temp);
			continue;
		}

		// Conversion specifications, consisting of the character %, an optional assignment
		// suppression character *, an optional number specifying a maximum field width, an
		// optional h, l, or L indicating the width of the target, and a conversion character.
		switch (*p) {

			case '%':
				strcat(temp, "%");
				conversion = 1;
				break;

			case '*':
				strcat(temp, "*");
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

				width_flag ? int_to_str_then_strcat(width, temp) : 0;
				h ? strcat(temp, "h") : (l ? strcat(temp, "l") : 0);
				c_temp[0] = p[0], strcat(temp, c_temp); // Current case

				if (*p == 'd' || *p == 'i') {
					if (h) {
						h_ival = va_arg(ap, short*);
						if (scanf(temp, h_ival))
							read_items++;
					}
					else if (l) {
						l_ival = va_arg(ap, long int*);
						if (scanf(temp, l_ival))
							read_items++;
					}
					else {
						ival = va_arg(ap, int*);
						if (scanf(temp, ival))
							read_items++;
					}
				}
				else {
					if (h) {
						u_h_ival = va_arg(ap, unsigned short int*);
						if (scanf(temp, u_h_ival))
							read_items++;
					}
					else if (l) {
						u_l_ival = va_arg(ap, unsigned long int*);
						if (scanf(temp, u_l_ival))
							read_items++;
					}
					else {
						u_ival = va_arg(ap, unsigned int*);
						if (scanf(temp, u_ival))
							read_items++;
					}
				}

				strcpy(temp, ""), skip = h = l = width = width_flag = conversion = 0;
				break;

			case 'c':
				if (skip) {
					while (isspace(getchar()));
					skip = 0;
				}
				else {
					cval = va_arg(ap, char*);
					while (isspace(*cval = getchar()));
					read_items++;
				}

				strcpy(temp, ""), conversion = 0;
				break;

			case 's':
				width_flag ? int_to_str_then_strcat(width, temp) : 0;
				c_temp[0] = p[0], strcat(temp, c_temp); // Current case

				// To remove potential white space added by previous inputs
				while (isspace(*cval = getchar()));
				ungetc(*cval, stdin);

				sval = va_arg(ap, char*);
				if (scanf(temp, sval))
					read_items++;

				strcpy(temp, ""), skip = width = width_flag = conversion = 0;
				break;

			case 'e': case 'E': case 'f':
				width_flag ? int_to_str_then_strcat(width, temp) : 0;

				if (l) {
					strcat(temp, "l");					
					c_temp[0] = p[0], strcat(temp, c_temp); // Current case

					l_fval = va_arg(ap, double*);
					if (scanf(temp, l_fval))
						read_items++;
				}
				else {
					c_temp[0] = p[0], strcat(temp, c_temp); // Current case
					
					fval = va_arg(ap, float*);
					if (scanf(temp, fval))
						read_items++;
				}

				strcpy(temp, ""), skip = l = conversion = 0;
				break;

			//case 'g':
			//case 'G':
			//	dval = va_arg(ap, double);
			//	printf ("%g", dval);
			//	break;

			default:
				printf("\nError:\n Not expected character '%c'"
				"\n  into format specifier of minscanf(char *format, ...)"
				"\n   =/\n", *p);
			 	exit(1);
		}
	}
	va_end(ap); // clean up when done
	return read_items;
}

void int_to_str_then_strcat(int num, char *concatenate) {
	
	char str[50];
	sprintf(str, "%d", num);
	strcat(concatenate, str);
}
