#include <stdio.h>
#include <string.h>

void expand(char s1[], char s2[]) {

	short temp, size = strlen(s1) - 2, j = 0, k = 0;
	
	for (short i = 0; i < size; i++){
		
		if (s1[i] != '-'){
			
			if (//It is a digit
				(((temp = s1[i] - '0') >= 0 && temp <= 9)
				&& (s1[i+1] == '-')
				&& ((temp = s1[i+2] - '0') >= 0 && temp <= 9))
				||//It is character. It approaches from A (uppercase) to z (lowercase).
				(((temp = s1[i] - 'A') >= 0 && temp <= 'z')
				&& (s1[i+1] == '-')
				&& ((temp = s1[i+2] - 'A') >= 0 && temp <= 'z')))
			{

				j = (k-1 >= 0 && s2[k-1] == s1[i]) ? s1[i] + 1: s1[i];

				while (j <= s1[i+2])
					s2[k++] = j++;
			}
		}
	}
	s2[k] = '\0';
}	

int main() {

	char s1[10], s2[100];

	strcpy(s1, "a-z");
	expand(s1, s2);
	printf("\ns1: %s", s1);
	printf("\ns2: %s\n", s2);

	strcpy(s1, "0-9");
	expand(s1, s2);
	printf("\ns1: %s", s1);
	printf("\ns2: %s\n", s2);

	strcpy(s1, "a-b-c");
	expand(s1, s2);
	printf("\ns1: %s", s1);
	printf("\ns2: %s\n", s2);

	strcpy(s1, "a-z0-9");
	expand(s1, s2);
	printf("\ns1: %s", s1);
	printf("\ns2: %s\n", s2);
	
	strcpy(s1, "-a-z");
	expand(s1, s2);
	printf("\ns1: %s", s1);
	printf("\ns2: %s\n", s2);

	return 0;
}