#include <stdio.h>
int main(){

	int c;
	char last_putchar = EOF;

	while ((c = getchar()) != EOF)
		
		if (c != ' ' && c != '\n' && c != '\t')
			last_putchar = putchar(c);
		else if (last_putchar != '\n') {
			putchar('\n');
			last_putchar = '\n';
		}
	
	return 0;
}