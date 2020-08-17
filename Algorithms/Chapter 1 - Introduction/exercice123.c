#include <stdio.h>

int main(){
	
	unsigned int cemNQuadrado=0, doisN=0, i, potencia;

	for(i = 1; ; ++i){
		
		potencia = 1;
		for(int j=0; j<i; ++j)
			potencia *= 2;

		if(100*i*i<=potencia)
			break;
	}
	printf("N = %d", i);
	printf("\nPotencia = %d", potencia);
	printf("\n100N^2 = %d\n", 100*i*i);

	return 0;
}