#include <stdio.h>
#include <stdlib.h> // atof()
#include <calc.h>

#define MAXOP 100 // max size of operand or operator

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