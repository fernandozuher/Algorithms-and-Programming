#include <stdio.h>
#include <string.h>

void squeeze2(char s1[], const char s2[]);

int main()
{
	char s1[] = "Lorem ipsum dolor sit amet,";
	char s2[] = "otto,";
	
	printf("\nOriginal string 1: %s", s1);
	printf("\nOriginal string 2: %s\n", s2);
	
	squeeze2(s1, s2);
	printf("\nFiltered string 1: %s\n", s1);

	return 0;
}

void squeeze2(char s1[], const char s2[])
{
	//first deduplicate string s2
	int lim2 = strlen(s2);
	char s2_deduplicated[lim2];
	strcpy(s2_deduplicated, s2);
	
	for (int i = 0; i < lim2-1; ++i)
		if ( s2_deduplicated[i] != '\a' )
			for (int j = i+1; j < lim2; ++j)
				if ( s2_deduplicated[i] == s2_deduplicated[j] )
					s2_deduplicated[j] = '\a';
	
	printf("\nDeduplicated string 2: %s", s2_deduplicated);

	//then remove characters in string s1
	int lim1 = strlen(s1);
	for (int i = 0; i < lim1; ++i)
		for (int j = 0; j < lim2; ++j)
			if ( s2_deduplicated[j] != '\a' && s1[i] == s2_deduplicated[j] )
				s1[i] = '\a';

	//Remove blank spaces with '\a' in s1
	int j = 0;
	for (int i = 0; i < lim1; ++i)
		if (s1[i] != '\a')
			s1[j++] = s1[i];
	s1[j] = '\0';
}