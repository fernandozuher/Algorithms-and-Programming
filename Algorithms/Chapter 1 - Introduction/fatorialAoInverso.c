#include <stdio.h>

int main(){
	
	unsigned long int fat=1, i=1;
	for(i = 2; fat <= 1000000; ++i)
		fat *= i;
	printf("\nN para 1.000.000: %lu", i-2);

	for(; fat <= 60000000; ++i)
		fat *= i;
	printf("\nN para 60.000.000: %lu", i-2);

	for(; fat <= 3600000000; ++i)
		fat *= i;
	printf("\nN para 3600000000: %lu", i-2);

	for(; fat <= 86400000000; ++i)
		fat *= i;
	printf("\nN para 86400000000: %lu", i-2);

	for(; fat <= 2592000000000; ++i)
		fat *= i;
	printf("\nN para 2592000000000: %lu", i-2);

	for(; fat <= 946080000000000; ++i)
		fat *= i;
	printf("\nN para 946080000000000: %lu", i-2);

	for(; fat <= 94608000000000000; ++i)
		fat *= i;
	printf("\nN para 94608000000000000: %lu\n", i);

	return 0;
}