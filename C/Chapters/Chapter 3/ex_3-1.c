//The difference in run-time between both the functions is negligible.
#include <stdio.h>
#include <time.h>

int binsearch2(int x, int v[], int n);
int binsearch1(int x, int v[], int n);

int main() {

	int x = 0, index;
	int v[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
	
	// From: https://stackoverflow.com/questions/5248915/execution-time-of-c-program/41959179#41959179
	struct timespec begin, end;
    clock_gettime(CLOCK_MONOTONIC_RAW, &begin);
	index = binsearch2(x, v, 10);
	clock_gettime(CLOCK_MONOTONIC_RAW, &end);
	printf("\nIndex MODIFIED binsearch: %d", index);
	printf ("\nTime to be searched 2 = %.17f seconds\n",
            (end.tv_nsec - begin.tv_nsec) / 1000000000.0 +
            (end.tv_sec  - begin.tv_sec));
	
    clock_gettime(CLOCK_MONOTONIC_RAW, &begin);
	index = binsearch1(x, v, 10);
	clock_gettime(CLOCK_MONOTONIC_RAW, &end);
	printf("\nIndex ORIGINAL binsearch: %d", index);
	printf ("\nTime to be searched 1 = %.17f seconds\n",
            (end.tv_nsec - begin.tv_nsec) / 1000000000.0 +
            (end.tv_sec  - begin.tv_sec));

	return 0;
}

int binsearch2(int x, int v[], int n) {

	int low, high, mid;
	low = 0;
	high = n - 1;
	mid = (low + high) / 2;
	
	while (low <= high && x != v[mid]) {
		
		if (x < v[mid])
			high = mid - 1;
		else
			low = mid + 1;

		mid = (low + high) / 2;
	}

	if (x == v[mid])
		return mid;

	return -1;
}

int binsearch1(int x, int v[], int n) {

	int low, high, mid;
	low = 0;
	high = n - 1;
	
	while (low <= high) {	
		
		mid = (low + high) / 2;
		
		if (x < v[mid])
			high = mid - 1;
		else if (x > v[mid])
			low = mid + 1;
		else
			return mid;
	}
	
	return -1;
}