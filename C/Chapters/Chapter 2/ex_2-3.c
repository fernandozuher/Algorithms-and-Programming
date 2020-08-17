#include <stdio.h> //printf
#include <string.h> //strlen
#include <ctype.h> //tolower, isdigit
#include <math.h> //pow

int htoi(const char s[]);

int main()
{
	int num;
	char string[10];

	strcpy(string, "");
	if( (num = htoi(string)) >= 0 )
		printf("\n%s = %d\n", string, num);

	strcpy(string, "0");
	if( (num = htoi(string)) >= 0 )
		printf("\n%s = %d\n", string, num);

	strcpy(string, "0x");
	if( (num = htoi(string)) >= 0 )
		printf("\n%s = %d\n", string, num);

	strcpy(string, "0x0");
	if( (num = htoi(string)) >= 0 )
		printf("\n%s = %d\n", string, num);

	strcpy(string, "0x1");
	if( (num = htoi(string)) >= 0 )
		printf("\n%s = %d\n", string, num);

	strcpy(string, "0x1o");
	if( (num = htoi(string)) >= 0 )
		printf("\n%s = %d\n", string, num);

	strcpy(string, "g0x4");
	if( (num = htoi(string)) >= 0 )
		printf("\n%s = %d\n", string, num);

	strcpy(string, "0x32");
	if( (num = htoi(string)) >= 0 )
		printf("\n%s = %d\n", string, num);

	return 0;
}

int htoi(const char s[]){

	int i, lim = strlen(s);
	if ( lim == 0 ) 
		i = -1; //if the string is empty
	else if ( lim == 2 && (s[0] == '0' && tolower(s[1]) == 'x') )
		i = -2; //if there is only the prefix 0x(X)
	else if ( lim > 2 && s[0] == '0' && tolower(s[1]) == 'x' )
		i = 2; //if there is the prefix 0x(X)
	else
		i = 0; //else there is not the prefix

	int total = 0, j = 0;
	if ( i >= 0 ) {

		for(j = lim-1; j >= i; --j)
		
			if ( isdigit(s[j]) )
				total += (s[j] - '0') * pow(16, lim - 1 - j);

			else if( tolower(s[j]) >= 'a' && tolower(s[j]) <= 'f' )
				total += (tolower(s[j]) - 'a' + 10) * pow(16, lim - 1 - j);

			else{
				i = -3; //else there is a non-hexadecimal digit in the string
				break;
			}
	}

	if (i == -1){
		printf("\nEmpty string.\n");
		return i;
	}
	else if ( i < -1 ){
		printf("\nYour hexadecimal number is not in a proper format.");
		printf("\nThe allowable digits are 0 through 9, a through f, A through F,");
		printf(" including an optional Ox or ox.\n");
		return i;
	}
	else
		return total;
}