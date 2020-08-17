#include <stdio.h>
#include <limits.h>
#include <float.h>

int main()
{
	printf("char MIN: %d", CHAR_MIN);
	printf("\nchar MAX: %d", CHAR_MAX);
	printf("\nunsigned char: %d", UCHAR_MAX);

	printf("\n\nshort MIN: %d", SHRT_MIN);
	printf("\nshort MAX: %d", SHRT_MAX);
	printf("\nunsigned short: %d", USHRT_MAX);

	printf("\n\nint MIN: %d", INT_MIN);
	printf("\nint MAX: %d", INT_MAX);
	printf("\nunsigned int: %u", UINT_MAX);

	printf("\n\nlong MIN: %ld", LONG_MIN);
	printf("\nlong MAX: %ld", LONG_MAX);
	printf("\nunsigned long: %lu", ULONG_MAX);

	printf("\n\nfloat MIN: %.10e", FLT_MIN);
	printf("\nfloat MAX: %.10e", FLT_MAX);
	printf("\nfloat MAX: %f", FLT_MAX);
	
	printf("\n\ndouble MIN: %.10e", DBL_MIN);
	printf("\ndouble MAX: %.10e", DBL_MAX);
	printf("\ndouble MAX: %lf", DBL_MAX);

	printf("\n");
	return 0;
}