#include <stdio.h>

#define MAXLINE 1000

int getline2(char line[], int maxline);
void copy(char to[], char from[]);

int main()
{
	int len;
	int max;
	char line[MAXLINE];
	char longest[MAXLINE];

	max = 0;

	while ((len = getline2(line, MAXLINE)) > 0)
		if (len > max) {
			max = len;
			copy(longest, line);
		}

	if (max > 0)
			printf("\nLen: %d\nLine: %s\n", max, longest);
	
	return 0;
}

int getline2(char s[], int lim)
{
	int c, i = 0;
	while(i < lim-1 && (c = getchar()) != EOF && c!='\n' && c!='\0')
		s[i++] = c;

	if (c == '\n')
		s[i++] = c;

	s[i] = '\0';

	if (i == lim - 1)
		while ((c = getchar()) != EOF && c != '\n' && c != '\0')
			++i;

	return i;
}

void copy(char to[], char from[])
{
	for (int i = 0; (to[i] = from[i]) != '\0'; ++i);
}