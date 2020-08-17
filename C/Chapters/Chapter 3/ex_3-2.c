#include <stdio.h>
#include <string.h>

void escape(char s[], char t[]) {

	int tam = strlen(t), j = 0;
	for(int i = 0; i < tam; ++i) {

		switch (t[i]) {

				case '\n':
					s[j++] = '\\';
					s[j++] = 'n';
					break;
				case '\t':
					s[j++] = '\\';
					s[j++] = 't';
					break;
				case '\a':
					s[j++] = '\\';
					s[j++] = 'a';
					break;
				case '\\':
					s[j++] = '\\';
					s[j++] = '\\';
					break;
				case '\'':
					s[j++] = '\\';
					s[j++] = '\'';
					 break;
				case '\"':
					s[j++] = '\\';
					s[j++] = '\"';
					 break;
			default:
				s[j++] = t[i];
		}
	}
	s[j] = '\0';
}

void escape_reverse(char s[], char t[]) {

	int tam = strlen(t), j = 0;
	for(int i = 0; i < tam; ++i) {
		
		if (t[i] == '\\') {

			switch (t[++i]) {

				case 'n':
					s[j++] = '\n';
					break;
				case 't':
					s[j++] = '\t';
					break;
				case 'a':
					s[j++] = '\a';
					break;
				case '\'':
					s[j++] = '\'';
					 break;
				case '\"':
					s[j++] = '\"';
					 break;
				default:
					s[j++] = '\\';
			}
		}
		else
			s[j++] = t[i];
	}
	s[j] = '\0';
}

int main() {

	char s[1000], t[] = "Lorem ipsum dolor sit amet, consectetur\a adipisicing\\ elit, sed \'do\' eiusmod\n\ttempor incididunt ut \"labore\" et dolore magna aliqua. Ut enim ad minim veniam,\n\tquis nostrud exercitation ullamco laboris nisi ut aliquip ex ea commodo\n\tconsequat. Duis aute irure dolor in reprehenderit in voluptate velit esse\n\tcillum dolore eu fugiat nulla pariatur. Excepteur sint occaecat cupidatat non\n\tproident, sunt in culpa qui officia deserunt mollit anim id est laborum.";

	printf("\nescape():\n");
	escape(s, t);
	printf("\noriginal[]: %s\n", t);
	printf("\nmodified[]: %s\n", s);

	printf("\nescape_reverse():\n");
	escape_reverse(t, s);
	printf("\noriginal[]: %s\n", s);
	printf("\nmodified[]: %s\n", t);
	
	return 0;
}