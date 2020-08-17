#include <iostream>
using namespace std;

void print_int(int);
void (*ptr_func)(int);

int main()
{
	ptr_func = &print_int;
	ptr_func(5);

	return 0;
}

void print_int(int a)
{
	cout << a << endl;
}