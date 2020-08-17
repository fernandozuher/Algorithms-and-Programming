#include <stdio.h>

#define MAXLINE 1000

void reverse(char line[]);

int main()
{
	char line[MAXLINE];

	while (1) {
		reverse(line);
		printf("Reversed: %s\n", line);
	}
	
	return 0;
}

void reverse(char s[])
{
	char c;
	int i;

	printf("Entry: ");
	for(i = 0; (c = getchar()) != EOF && c!='\0' && c!='\n'; (s[i++] = c));

	char temp;
	for(int j = 0; j <= (i/2 - 1); ++j){
		temp = s[j];
		s[j] = s[i-j-1];
		s[i-j-1] = temp;
	}

	if (c == '\n')
		s[i] = '\n';
	s[++i] = '\0';
}