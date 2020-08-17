/*
Author: Fernando Zuher
Place: Brazil
Date: 25/02/2020
Book: The C programming language, second edition. Authors: BRIAN W KERNIGHAN and DENNIS M. RITCHIE
About: Exercise, Chapter 4 - Functions and Program Structure
*/

/*
Exercise 4-2. Extend atof to handle scientific notation of the form
123.45e-6 
where a floating-point number may be followed by e or E and an optionally
signed exponent.
*/

#include <stdio.h>
#include <ctype.h> // isspace(), isdigit()
#define MAXNUMBER 15 /* maximum input line length */

int getline2(char s[], int lim);
double atof(char s[]);

int main()
{
	char number[MAXNUMBER];
	
	while (getline2(number, MAXNUMBER) > 0)		
		printf("\tConverted to double: %f\n", atof(number));
	return 0;
}

// atof: convert string s to double
double atof(char s[])
{
	double val, power;
	int i, sign;
	
	for (i = 0; isspace(s[i]); i++); // skip white space 
	
	sign = (s[i] == '-') ? -1 : 1;
	if (s[i] == '+' || s[i] == '-')
		i++;

	for (val = 0.0; isdigit(s[i]); i++)
		val = 10.0 * val + (s[i] - '0');
	
	if (s[i] == '.')
		i++;

	for (power = 1.0; isdigit(s[i]); i++) {
		val = 10.0 * val + (s[i] - '0');
		power *= 10.0;
	}
	
	// to handle scientific notation ///////////////////////////
	if (s[i] == 'e' || s[i] == 'E'){
		
		int sign2 = (s[++i] == '-') ? -1 : 1;

		if (s[i] == '+' || s[i] == '-')
			++i;
		
		double val2;
		for (val2 = 0.0; isdigit(s[i]); i++)
			val2 = 10.0 * val2 + (s[i] - '0');

		int j;
		double power2;
		for (j = 0, power2 = 1.0; j < val2; j++)
			power2 *= 10.0;

		power = (sign2 == 1) ? power / power2 : power * power2;
	}
	////////////////////////////////////////////////////////////

	return sign * val / power;
}

// getline: get line into s, return length
int getline2(char s[], int lim)
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