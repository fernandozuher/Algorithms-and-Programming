/*
Author: Fernando Zuher
Place: Brazil
Date: 02/03/2020
Book: The C programming language, second edition. Authors: BRIAN W KERNIGHAN and
															 DENNIS M. RITCHIE
About: Exercises from 4.3 to 4.10, Chapter 4 - Functions and Program Structure
*/

/*
Exercise 4-3. Given the basic framework, it's straightforward to extend the
calculator. Add the modulus (%) operator and provisions for negative numbers.

Exercise 4-4. Add commands to print the top element of the stack without
popping, to duplicate it, and to swap the top two elements. Add a command to
clear the stack.

Exercise 4-5. Add access to library functions like sin, exp, and pow. See
<math.hh> in Appendix B, Section 4.

Exercise 4-6. Add commands for handling variables. (It's easy to provide
twenty-six variables with single-letter names.) Add a variable for the most
recently printed value.

Exercise 4-7. Write a routine ungets (s) that will push back an entire string
onto the input. Should ungets know about buf and bufp, or should it just
use ungetch?

Exercise 4-8. Suppose that there will never be more than one character
pushback. Modify getch and ungetch accordingly.

Exercise 4-9. Our getch and ungetch do not handle a pushed-back EOF
correctly. Decide what their properties ought to be if an EOFis pushed back,
then implement your design.

Exercise 4-10. An alternate organization uses getline to read an entire input
line; this makes getch and ungetch unnecessary. Revise the calculator to use
this approach.
*/

#include <stdio.h>
#include <stdlib.h> // atof()
#include <math.h> // sin(), exp(), pow()

#define MAXOP 100 // max size of operand or operator
#define NUMBER '0' // signal that a number was found

int getop(char []);

// Exercise 4-10
int getop2(char []);

void push(double);
double pop(void);

// reverse Polish calculator
int main()
{
	int type;
	double op2, last_printed;
	char s[MAXOP];
	
	while ((type = getop2(s)) != EOF) {

		switch (type) {
		
			case NUMBER:
				push(atof(s));
				break;
		
			case '+':
				push(pop() + pop());
				break;
		
			case '*':
				push(pop() * pop());
				break;
		
			case '-':
				op2 = pop();
				push(pop() - op2);
				break;
			
			case '/':
				op2 = pop();
				if (op2 != 0.0)
					push(pop() / op2);
				else
					printf("error: zero divisor\n");
				break;

			// Exercise 4-3. Given the basic framework,
			// it's straightforward to extend the calculator.
			// Add the modulus (%) operator and provisions for negative numbers.
			case '%':
				op2 = pop();
				if (op2 != 0.0)
					push(fmod(pop(), op2));
				else
					printf("error: zero divisor\n");
				break;

			// Exercise 4-5. Add access to library functions like sin, exp, and
			// pow. See <math.h> in Appendix B, Section 4.0.
			case 's': // sin()
				push(sin(pop()));
				break;
			
			case 'e': // exp()
				push(exp(pop()));
				break;

			case 'p': // pow()
				op2 = pop();
				push(pow(pop(), op2));
				break;
			////////////////////////////////////////////////////////////////////

			// Exercise 4-6. Add commands for handling variables. (It's easy to
			// provide twenty-six variables with single-letter names.) Add a
			// variable for the most recently printed value.
			case '\n':
				printf("\t= %.8g\n", last_printed = pop());
				break;
			
			default:
				printf("error: unknown command %s\n", s);
				break;
		}
	}
	return 0;
}

#define MAXVAL 100 // maximum depth of val stack
int sp = 0; // next free stack position
double val[MAXVAL]; // value stack

///////////////////////////////////////////////////////////////////////////////
// Exercise 4-4. Add commands to print the top element of the stack without pop-
// ping, to duplicate it, and to swap the top two elements. Add a command to
// clear the stack.

void print_top()
{
	if (sp > 0) 
		printf("\nStack top = %.8g", val[sp-1]);
	else
		printf("Stack empty.\n");
}

void duplicate_top()
{
	if (sp > 0) {
		val[sp] = val[sp-1];
		sp++;
	}
	else
		printf("Stack empty.\n");
}

void swap_two_top()
{
	if (sp > 1) {	
		double temp = val[sp-1];
		val[sp-1] = val[sp-2];
		val[sp-2] = temp;
	}
	else
		printf("Stack has less than 2 elements. It is not possible to swap.\n");
}

void clear_stack()
{
	if (sp > 0) {
		sp = 0;
		printf("\nCleared stack.\n");
	}
	else
		printf("Nothing to clear in stack.\n");	
}

///////////////////////////////////////////////////////////////////////////////

// push: push f onto value stack
void push(double f)
{
	if (sp < MAXVAL)
		val[sp++] = f;
	else
		printf("error: stack full, can't push %g\n", f);
}

// pop: pop and return top value from stack
double pop(void)
{
	if (sp > 0)
		return val[--sp];
	else {
		printf("stack empty\n");
		return 0.0;
	}
}

// Exercise 4-10. An alternate organization uses getline to read an entire input
// line; this makes getch and ungetch unnecessary. Revise the calculator to use
// this approach.
#include <ctype.h> // isdigit()
#include <string.h> // strlen()

#define SIZE_EXPRESSION 100
char read_expression[SIZE_EXPRESSION]; // array for string read from getline2
// next free position to read in read_expression, length of the read string
int read_expression_index, len_read_line;

int getop2(char s[])
{
	int i = 0, c;
	char *fim;

	// if read string index is in the first position, not read yet
	if (read_expression_index == len_read_line) {
		// Using this method just to avoid copying the old one provided in
		// the chapter
		fim = fgets(read_expression, SIZE_EXPRESSION, stdin);
		len_read_line = strlen(read_expression);
		read_expression_index = 0;
	}

	// if EOF
	if (fim == NULL)
		return EOF;
	
	while (
	  (s[0] = c = read_expression[read_expression_index++]) == ' ' || c == '\t')
		;
	
	s[1] = '\0';

	// '-' for negative numbers, exercise 4-3
	if (!isdigit(c) && c != '.' && c != '-')
		return c; // not a number

	// '-' for negative numbers, exercise 4-3
	else if (c == '-') {
		
		// is digit, not space
		if (isdigit(s[++i] = c = read_expression[read_expression_index++])){}

		else {
			read_expression_index--;
			return '-';
		}
	}
	
	if (isdigit(c)) // collect integer part
		while (isdigit(s[++i] = c = read_expression[read_expression_index++]));
	
	if (c == '.') // collect fraction part
		while (isdigit(s[++i] = c = read_expression[read_expression_index++]));
	
	read_expression_index--;

	s[i] = '\0';

	return NUMBER;
}
///////////////////////////////////////////////////////////////////////////////

int getch(void);
void ungetch(int);

// getop: get next operator or numeric operand
int getop(char s[])
{
	int i, c;
	while ((s[0] = c = getch()) == ' ' || c == '\t');
	s[1] = '\0';

	// '-' for negative numbers, exercise 4-3
	if (!isdigit(c) && c != '.' && c != '-')
		return c; // not a number

	else if (c == '-') { // '-' for negative numbers, exercise 4-3
		if (isdigit(c = getch())) // is digit, not space
			c = -c;
		else {
			ungetch(c);
			return '-';
		}
	}

	i = 0;
	
	if (isdigit(c)) // collect integer part
		while (isdigit(s[++i] = c = getch()));
	
	if (c == '.') // collect fraction part
		while (isdigit(s[++i] = c = getch()));
	
	s[i] = '\0';
	
	// Exercise 4-9. Our getch and ungetch do not handle a pushed-back EOF
	// correctly. Decide what their properties ought to be if an EOF is pushed
	// back, then implement your design.
	// if (c != EOF) // <-- original version
	ungetch(c);
	
	return NUMBER;
}

#define BUFSIZE 100
char buf[BUFSIZE]; // buffer for ungetch
int bufp = 0; // next free position in buf

int getch(void) // get a (possibly pushed back) character
{
	return (bufp > 0) ? buf[--bufp] : getchar();
}

void ungetch(int c) // push character back on input
{
	if (bufp >= BUFSIZE)
		printf("ungetch: too many characters\n");
	else
		buf[bufp++] = c;
}

/* Exercise 4-7. Write a routine ungets(s) that will push back an entire string
onto the input. Should ungets know about buf and bufp, or should it just
use ungetch? Answer: Just use ungetch(). */
void ungets(char s[])
{
	for (int i = 0; s[i] != '\0'; ungetch(s[i++]));
}

// Exercise 4-8. Suppose that there will never be more than one character
// pushback. Modify getch and ungetch accordingly.
char buf2; // 'buffer'. 0 by default since it is global.

int getch2() // get a (possibly pushed back) character
{
	if (buf2) {
		char temp = buf2;
		buf2 = 0;
		return temp;
	}
	return getchar();
}

void ungetch2(int c) // push character back on input
{
	buf2 = c;
}
///////////////////////////////////////////////////////////////////////////////