#include <iostream>
using namespace std;

void func(int a, int b, int);

int main()
{
	func(3, 2, 1);
	return 0;
}

void func(int a, int b, int)
{
	cout << a << endl << b << endl;
}