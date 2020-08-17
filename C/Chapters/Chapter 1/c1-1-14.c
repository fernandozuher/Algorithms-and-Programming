// Calcula a frequência de caracteres quaisquer da tabela ASCII, não considerando espaços em branco e caracteres especiais.
#include <stdio.h>

#define N_CARACTERES 94
#define CARACT_MAX 126
#define CARACT_MIN 33

int main() {

	int frequencia_caracteres[N_CARACTERES];
	for(int i = 0; i < N_CARACTERES; ++i)
		frequencia_caracteres[i] = 0;

	int c, i = -1, maior = 0;
	char string[] = "Lorem ipsum dolor sit amet, consectetur adipisicing elit, sed do eiusmod tempor incididunt ut labore et dolore magna aliqua. Ut enim ad minim veniam, quis nostrud exercitation ullamco laboris nisi ut aliquip ex ea commodo consequat. Duis aute irure dolor in reprehenderit in voluptate velit esse cillum dolore eu fugiat nulla pariatur. Excepteur sint occaecat cupidatat non proident, sunt in culpa qui officia deserunt mollit anim id est laborum.", last_char = 's';
	while ((c = string[++i]) != '\0')
		if ((c >= CARACT_MIN && c <= CARACT_MAX) && (++frequencia_caracteres[c - '!'] > maior))
			maior = ++frequencia_caracteres[c - '!'];
	
	while (maior > 0) {
		printf("\n");
		
		for (int i = 0; i < N_CARACTERES; ++i)
			if(frequencia_caracteres[i] == maior) {
				printf(" |");
				--frequencia_caracteres[i];
			}
			else
				printf("  ");

		--maior;
	}

	printf("\n");
	for(char i = 33; i <= CARACT_MAX; ++i)
		printf(" %c", i);

	printf("\n");
	return 0;	
}