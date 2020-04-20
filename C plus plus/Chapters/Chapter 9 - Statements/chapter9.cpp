/*
Author: Fernando Zuher
Place: Brazil
Date: 20 April 2020
Book: The C++ Programming Language, fourth edition. Author: Bjarne Stroustrup.
About: A summary of code explained in the Chapter 9 - Statements

*/

#include <iostream>
using namespace std;

int main()
{
	cout << "A programmer is a machine for turning caffeine into code."
			" – A programmer" << endl;

	int array[10] {};

	cout << "\nInitialized array: ";
	for (int x : array)
		cout << x << " ";

	cout << "\n\nModified array passed as value in for loop : ";
	for (int x : array) {
		x += 1;
		cout << x << " ";
	}

	cout << "\n\nArray after 'for': ";
	for (int x : array)
		cout << x << " ";

	cout << "\n\nModified array passed as reference in for loop: ";
	for (int& x : array) {
		x += 1;
		cout << x << " ";
	}

	cout << "\n\nArray after 'for': ";
	for (int x : array)
		cout << x << " ";

	cout << "\n\nArray iterated by begin(), end(): ";
	for (int* i = begin(array); i != end(array); i++) {
		cout << *i << " ";
	}

	cout << endl;
	return 0;
}
