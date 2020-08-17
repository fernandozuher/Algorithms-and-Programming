#include <stdio.h>

void itoa(int n, char s[], int min) {
	
	int i, sign;

	if ((sign = n) < 0)
		n = -n;
	
	i = 0;
	do
		s[i++] = n % 10 + '0';
	while ((n /= 10) > 0);

	if (sign < 0)
		s[i++] = '-';
	s[i] = '\0';
	int size = i;
	
	//Reverse number
	int j, temp;
	for (j = 0, i = i-1; j < i; i--, j++)
		temp = s[i], s[i] = s[j], s[j] = temp;

	//Add or not blanks
	int blanks = min - size;
	if (blanks > 0) {
		for (i = size + blanks, j = 0; i > blanks - 1; i--, j++)
			s[i] = s[size - j];

		//Blanks
		for (i = 0; i < blanks; s[i++] = '_');
	}
}

int main() {
	
	char s[15];
	int n = 123;

	itoa(n, s, 1);
	printf("\nMin width 1: %s", s);

	itoa(n, s, 3);
	printf("\nMin width 3: %s", s);

	itoa(n, s, 5);
	printf("\nMin width 5: %s", s);

	itoa(n, s, 8);
	printf("\nMin width 8: %s", s);

	printf("\n");
	return 0;
}