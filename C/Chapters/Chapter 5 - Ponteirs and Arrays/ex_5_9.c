/*
Author: Fernando Zuher
Place: Brazil
Date: 27/03/2020
Book: The C programming language, second edition. Authors: BRIAN W KERNIGHAN and DENNIS M. RITCHIE
About: Exercise, Chapter 5 - Pointers and Arrays
*/

/*
Exercise 5-9. Rewrite the routines day_of_year and month_day with pointers
instead of indexing.

OBS: I did this exercise thanks to the study of
	Book: The C++ Programming Language, fourth edition. Author: Bjarne Stroustrup.
	About: Chapter 7 - Pointers, Arrays, and References

	:P
*/

#include <stdio.h>

int day_of_year(int year, int month, int day);
void month_day(int year, int yearday, int *pmonth, int *pday);
char* month_name(int n);

static char daytab[2][13] = {
	{0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},
	{0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}
};

int main()
{
	int pmonth, pday;

	printf("\nday of the year: %d", day_of_year(2020, 3, 27));
	
	month_day(2020, day_of_year(2020, 3, 27), &pmonth, &pday);
	printf("\nmonth and day: %s, %d", month_name(pmonth), pday);

	printf("\n");
	return 0;
}

// day_of_year: set day of year from month & day
int day_of_year(int year, int month, int day)
{
	int i, leap;
	
	leap = year%4 == 0 && year%100 != 0 || year%400 == 0;
	for (i = 1; i < month; i++)
		day += *(*daytab + leap*13 + i);
		// equal to day += *(daytab[0] + leap*13 + i);
		// equal to day += *(&daytab[0][0] + leap*13 + i);
		// but not day += *(daytab + leap*13 + i); WRONG
		// Learned thanks C++ book.

	return day;
}

// month_day: set month, day from day of year
void month_day(int year, int yearday, int *pmonth, int *pday)
{
	int i, leap;

	leap = year%4 == 0 && year%100 != 0 || year%400 == 0;
	for (i = 1; yearday > *(*daytab + leap*13 + i); i++)
		yearday -= *(*daytab + leap*13 + i);
	
	*pmonth = i;
	*pday = yearday;
}

// month_name: return name of n-th month
char* month_name(int n)
{
	static char *name[] = {
		"Illegal month",
		"January", "February", "March",
		"April", "May", "June",
		"July", "August", "September",
		"October", "November", "December"
	};
	return (n < 1 || n > 12) ? name[0] : name[n];
}