#include <stdio.h>

int main(){

	int c;
	char espaco = 'n';
	while ( (c = getchar()) != EOF){
		if(c==' ')
			espaco='s';
		else if(espaco=='s'){
			putchar(' ');
			putchar(c);
			espaco='n';
		}
		else
			putchar(c);
	}

	return 0;
}