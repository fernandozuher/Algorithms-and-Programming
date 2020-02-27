/*
Author: Fernando Zuher
Place: Brazil
Date: 24/02/2020
Book: The C++ Programming Language, fourth edition. Author: Bjarne Stroustrup.
About: A homemade exercise just to practice issues
approached in the Chapter 6 - Types and Declaration.
*/

#include <iostream>
#include <typeinfo> // typeid()
using namespace std;

int i;
int main() {

	// Common types
	bool bool_0;
	
	char char_0;

	short short_0;
	int int_0;
	long long_0;
	long long long_long_0;

	float float_0;
	double double_0;

	cout << "\nDefault variables' values:\n"
		<< "bool: " << bool_0 << "\n" <<
		"char: " << char_0 << "\n" <<

		"short: " << short_0 << "\n" <<
		"int: " << int_0 << "\n" <<
		"long: " << long_0 << "\n" <<
		"long long: " << long_long_0 << "\n" <<

		"float: " << float_0 << "\n" <<
		"double: " << double_0 << "\n";


	// Common initialized types 
	bool bool_1 {};
	
	char char_1 {};

	short short_1 {};
	int int_1 {};
	long long_1 {};
	long long long_long_1 {};

	float float_1 {};
	double double_1 {};


	cout << "\nINITIALIZED variables:\n"
		<< "bool: " << bool_1 << "\n" <<
		"char: " << char_1 << "\n" <<

		"short: " << short_1 << "\n" <<
		"int: " << int_1 << "\n" <<
		"long: " << long_1 << "\n" <<
		"long_long: " << long_long_1 << "\n" <<

		"float: " << float_1 << "\n" <<
		"double: " << double_1 << "\n";

	cout << "\nBuilt-in types SIZE in this implementation:\n"
		<< "bool: " << sizeof(bool_1) << "\n" <<
		"char: " << sizeof(char_1) << "\n" <<

		"short: " << sizeof(short_1) << "\n" <<
		"int: " << sizeof(int_1) << "\n" <<
		"long: " << sizeof(long_1) << "\n" <<
		"long_long: " << sizeof(long_long_1) << "\n" <<

		"float: " << sizeof(float_1) << "\n" <<
		"double: " << sizeof(double_1) << "\n";

	int temp1 = sizeof(int_1);
	size_t temp2 = sizeof(int_1);
	cout << "\nint_1 size using INT as variable: " << temp1;
	cout << "\nint_1 size using SIZE_T as variable: " << temp2 << "\n";

	auto char_2 = 'a';
	auto int_2 = 123;
	auto float_2 = 12.3f;
	auto double_2 = 12.3;

	cout << "\nThe type of the varaibles declared as auto are:" <<
		"\nchar_2: " << typeid(char_2).name() <<
		"\nint_2: " << typeid(int_2).name() << 
		"\nfloat_2: " << typeid(float_2).name() << 
		"\ndouble_2: " << typeid(double_2).name() << endl;

	if (!i) { // outmost i
		int i = 3; // local i
		cout << "\ni local: " << i; // local i
		cout << "\ni global: " << ::i << endl; // outmost ii
	}

	return 0;
}
