#include <stdio.h>

void itob(int n, char s[], int b) {

	if (b != 2 && b != 8 && b != 16) {
		printf("\nNot recognized base.");
		return;
	}

	//Convert decimal to other bases
	int temp = n, i = 0;
	while (temp + '0' > '0') {
		s[i++] = (temp % b) + '0';
		temp /= b;
	}
	s[i] = '\0';

	//Convert properly to hexa
	int j;
	if (b == 16)
		for (int j = 0; j < i; j++)
			if (s[j] > '9')
				s[j] = s[j] - '9' - 1 + 'A';

	//Reverse number
	for (j = 0, i = i-1; j < i; i--, j++)
		temp = s[i], s[i] = s[j], s[j] = temp;
}

int main() {
	
	char s[15];
	int n = 587;

	printf("\nDecimal number: %d", n);

	itob(n, s, 2);
	printf("\n\tIn binary: %s", s);

	itob(n, s, 8);
	printf("\n\tIn octal: %s", s);

	itob(n, s, 16);
	printf("\n\tIn hexa: %s", s);

	printf("\n");
	return 0;
}