#include <iostream>
using namespace std;

auto teste(int a) -> void;

int main()
{
	teste(5);
	return 0;
}

auto teste(int a) -> void
{
	cout << ++a << endl;
}
