#include <iostream>
using namespace std;

void array_reference(int (&array)[4]);
void array_pointer(int* array);

int main()
{
	int array[4];
	for (int i = 0; i < 4; ++i)
		array[i] = 5;

	cout << "function main:" << endl;
	cout << "\tcout << array: " << array << endl;
	cout << "\tcout << *array: " << *array << endl;
	cout << "\tcout << &array: " << &array << endl;

	array_reference(array);
	array_pointer(array);

	return 0;
}

void array_reference(int (&array)[4])
{
	cout << "function array_reference:" << endl;
	cout << "\tcout << array: " << array << endl;
	cout << "\tcout << *array: " << *array << endl;
	cout << "\tcout << &array: " << &array << endl;

	for (int i = 0; i < 4; ++i)
		cout << " " << array[i];
	cout << endl;
}

void array_pointer(int* array)
{
	cout << "function array_pointer:" << endl;
	cout << "\tcout << array: " << array << endl;
	cout << "\tcout << *array: " << *array << endl;
	cout << "\tcout << &array: " << &array << endl;

	for (int i = 0; i < 4; ++i)
		cout << " " << array[i];
	cout << endl;
}