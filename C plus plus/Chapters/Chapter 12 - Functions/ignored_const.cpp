#include <iostream>
using namespace std;

void teste(int a);
void teste(const int a);

int main()
{
	teste(5);
	return 0;
}

void teste(int a)
{
	cout << ++a << endl;
}

void teste(const int a)
{
	cout << a << endl;
}