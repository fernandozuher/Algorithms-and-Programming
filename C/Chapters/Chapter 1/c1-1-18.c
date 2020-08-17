#include <stdio.h>

#define MAXLINE 1000

void remove_some_blanks(char line[]);

int main()
{
	char line[MAXLINE];

	while (1) {
		remove_some_blanks(line);
		printf("Filtered: %s", line);
	}
	
	return 0;
}

void remove_some_blanks(char s[])
{
	char c;
	int i = 0;
	while((c = getchar()) != EOF && c!='\0' && c!='\n')
		if(c != '\t')
			s[i++] = c;

	if (c == '\n') {
		
		s[i] = '\n';
		int j = i - 1;
		while (j >= 0 && s[j--] == ' ')
			s[--i] = '\n';
	}

	s[i+1] = '\0';
}