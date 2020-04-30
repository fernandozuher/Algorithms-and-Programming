/*
Author: Fernando Zuher
Place: Brazil
Date: 25 April 2020
Book: The C programming language, second edition. Authors: BRIAN W KERNIGHAN and DENNIS M. RITCHIE
About: Exercise, Chapter 7 - Input and Output
*/

/*
PDF 170, Page 156

Exercise 7-3. Revise minprintf to handle more of the other facilities of printf.

I wrote down:
	• A minus sign, which specifies left adjustment of the converted argument.
	• A number that specifies the minimum field width. The converted argument will be 
	printed in a field at least this wide. If necessary it will be padded on the left (or
	right, if left adjustment is called for) to make up the field width.
	• A period, which separates the field width from the precision.
	• A number, the precision, that specifies the maximum number of characters to be
	printed from a string, or the number of digits after the decimal point of a floating-
	point value, or the minimum number of digits for an integer. For: %d, i, %c, %s, %f
	• Other default formats: o, x, X, u, e, E, p
*/

#include <stdio.h>
#include <string.h> // strlen

#define SPACE(LEN) {for (int i = 0; i < (LEN); i++) putchar(' ');}

void minprintf(char *fmt, ...);

int main()
{
// INPUT TEST /////////////////////////////////////////////////////
	minprintf("int integer = %i", 010); printf("\n");
	minprintf("int decimal = %-3d", 10); printf("\n");
	minprintf("float real = %-5.2f.", 9.87654); printf("\n");
	minprintf("int octal = %o", 010); printf("\n");
	minprintf("int hexadecimal = %x", 0xaf); printf("\n");
	minprintf("unsigned int = %-3u.", 7); printf("\n");
	minprintf("double real = %e", 12e5); printf("\n");
	minprintf("char character = %-1c", 'f'); printf("\n");
	minprintf("char string = %5.3s.", "fernando"); printf("\n");
	int pointer_int;
	minprintf("void *address = %p", &pointer_int); printf("\n");
	return 0;
}

#include <stdarg.h>
// minprintf: minimal printf with variable argument list
void minprintf(char *fmt, ...)
{
	va_list ap; // points to each unnamed arg in turn
	
	char *p, *sval, temp[51];
	int ival, cval, width1 = 0, width2 = 0, num;
	unsigned int u_ival, u_num, left_adjustment = 0, dot = 0;
	double dval;
	void *pval;
	
	va_start(ap, fmt); // make ap point to 1st unnamed arg
	for (p = fmt; *p; p++) {

		if (*p != '%' && !left_adjustment && !width1 && !dot && !width2) {
			putchar(*p);
			fflush(stdout);
			continue;
		}

		if (width1 || left_adjustment || dot)
			--p;

		switch (*++p) {

			case '-':
				left_adjustment = 1;
				break;

			case '.':
				dot = 1;
				break;

			case '0': case '1': case '2': case '3': case '4':
			case '5': case '6': case '7': case '8': case '9':
				
				if (!dot) { // if it is width (before dot)

					width1 = width1 * 10 + (*p - '0');
					// To handle the potential case user inputs '0', e.g., %0d
					width1 += (width1 == 0 ? -1 : 0);
				}
				else {
					width2 = width2 * 10 + (*p - '0');
					// To handle the potential case user inputs '0', e.g., %.0f.
					width2 += (width2 == 0 ? -1 : 0);
				}

				break;

			case 'c':
				// warning: ‘char’ is promoted to ‘int’ when passed through ‘...’
				cval = va_arg(ap, int);

				if (width1 && !left_adjustment)
					SPACE(width1-1);

				putchar(cval);
				if (width1 && left_adjustment)
					SPACE(width1-1);
					
				width1 = left_adjustment = 0;
				break;

			case 'd':
			case 'i':
				ival = va_arg(ap, int);
				int ival2 = ival;

				for (num = 0; ival2; ival2/=10)
					num++;

				int tam;
				if (width1) {
					tam = width1 - ((width2 >= num) ? width2 : num);
					
					if (!left_adjustment)
						SPACE(tam);
				}
				
				if (width2)
					for (int i = 0; i < width2-num; i++)
						putchar('0');
	
				*p == 'd' ? printf("%d", ival) : printf("%i", ival);
				if (width1 && left_adjustment)
					SPACE(tam);

				dot = width2 = width1 = left_adjustment = 0;
				break;

			case 'o':
				ival = va_arg(ap, unsigned int);
				printf("%o", ival);
				break;

			case 'x':
			case 'X':
				ival = va_arg(ap, unsigned int);
				printf("%x", ival);
				break;

			case 'u':
				u_ival = va_arg(ap, unsigned int);
				unsigned int u_ival2 = u_ival;

				for (u_num = 0; u_ival2; u_ival2/=10)
					u_num++;

				int u_tam;
				if (width1) {
					u_tam = width1 - ((width2 >= u_num) ? width2 : u_num);

					if (!left_adjustment)
						SPACE(u_tam);
				}
				
				if (width2)
					for (int i = 0; i < width2-u_num; i++)
						putchar('0');

				printf("%u", u_ival);
				if (width1 && left_adjustment)
					SPACE(u_tam);

				dot = width2 = width1 = left_adjustment = 0;
				break;

			case 'f':
				if (!dot) {
					dval = va_arg(ap, double);
					printf("%f", dval);
				}
				else {
					dval = va_arg(ap, double);
					sprintf(temp, "%f", dval);

					int size_float = strlen(temp);

					int i = 0;
					while(temp[i] && temp[i++] != '.');
					int fract = 0;
					for (int j = i; temp[j]; j++)
						fract++; // Default is 6.

					fract -= width2;

					int f_tam;
					if (width1) {
						f_tam = width1 - (size_float - fract);

						if (!left_adjustment)
							SPACE(f_tam);
					}

					i = 0;
					while(temp[i] && temp[i] != '.')
						putchar(temp[i++]);

					// To handle the potential case user inputs just '.', e.g., %.f.
					if (width2>0)
						for (int j = i; j < i+width2+1 && temp[j]; j++)
							putchar(temp[j]);
					
					if (width1 && left_adjustment)
						SPACE(f_tam);

					dot = width2 = width1 = left_adjustment = 0;
				}
				break;

			case 'e':
			case 'E':
				dval = va_arg(ap, double);
				printf ("%e", dval);
				break;

			//case 'g':
			//case 'G':
			//	dval = va_arg(ap, double);
			//	printf ("%g", dval);
			//	break;

			case 'p':
				pval = va_arg(ap, void*);
				printf ("%p", pval);
				break;

			case 's':
				sval = va_arg(ap, char *);
				int len_sval = strlen(sval);
				int final_len;

				if (dot)
					final_len = width2 <= len_sval ? width2 : len_sval;
				else
					final_len = len_sval;

				int s_tam;
				if (width1) {
					
					if (dot && (width2 <= len_sval))
						s_tam = width1 - width2;
					else
						s_tam = width1 - len_sval;

					if (!left_adjustment)
						SPACE(s_tam);
				}

				int i;
				for (i = 0; i < final_len; i++, sval++)
					putchar(*sval);
				
				if (width1 && left_adjustment)
					SPACE(s_tam);
				
				dot = width2 = width1 = left_adjustment = 0;
				break;

			default:
				putchar(*p);
				break;
		}
	}
	va_end(ap); // clean up when done
}