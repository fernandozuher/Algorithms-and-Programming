#include <stdio.h>

int main() {

	int comprimento_palavras[21];
	for(int i = 0; i < 21; ++i)
		comprimento_palavras[i] = 0;

	int c, j = -1, maior = 0, temp = 0;
	char string[] = "a aa aa aaa aaa aaa aaaa aaaa aaaa aaaa aaaaa aaaaa aaaaa aaaaaa aaaaaa aaaaaaa", last_char = 's';
	while ((c = string[++j]) != '\0')
		
		if (c != ' ' && c != '\n' && c != '\t') {
			++temp;
			last_char = 'n';
		}
		else if (last_char == 'n') {
			comprimento_palavras[temp] += 1;
		
			if (comprimento_palavras[temp] > maior)
				maior = comprimento_palavras[temp];
			temp = 0;
			last_char = 's';
		}
	comprimento_palavras[temp] += 1;

	while (maior > 0) {
		printf("\n");
		for (int j = 1; j < 21; ++j)
			if(comprimento_palavras[j] == maior) {
				printf(" |");
				--comprimento_palavras[j];
			}
			else
				printf("  ");

		--maior;
	}

	printf("\n");
	for(int i = 1; i < 21; ++i)
		printf(" %d", i);

	printf("\n");
	return 0;	
}