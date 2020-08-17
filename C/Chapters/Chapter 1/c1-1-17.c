#include <stdio.h>

#define MINLINE 80
#define MAXLINE 1000

int printmin80characters(char line[], int min);

int main()
{
	char line[MAXLINE];
	int len;

	while (len = printmin80characters(line, MINLINE))
		if(len >= 80)
			printf("\nLength: %d\nLine: %s\n", len, line);
	
	return 0;
}

int printmin80characters(char s[], int min)
{
	char c;
	int i;
	for(i = 0; (c = getchar()) != EOF && c!='\n' && c!='\0'; (s[i++] = c));

	if (c == '\n')
		s[i++] = '\n';

	s[i] = '\0';

	return i;
}