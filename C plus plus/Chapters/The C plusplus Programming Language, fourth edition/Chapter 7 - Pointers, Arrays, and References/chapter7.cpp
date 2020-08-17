/*
Author: Fernando Zuher
Place: Brazil
Date: 24/03/2020
Book: The C++ Programming Language, fourth edition. Author: Bjarne Stroustrup.
About: A summary* of code explained in the Chapter 7
                                          - Pointers, Arrays, and References

* Most of the written is taken literally from the chapter.

*/

#include <iostream>
#include <vector>
using namespace std;

int a1[10]; // 40 ints on the free store

int main()
{
////// Basic stuff
	char c = 'a'; // char
	char* p = &c; // ponteir to char that receives address of c;
				  // & is the address-of operator
	char c2 = *p; // c2 == 'a'; * is the dereference operator

	cout << c2 << endl;

	int* pi; // pointer to int
	char** ppc; // pointer to pointer to char
	int* ap[15]; // array of 15 pointers to ints
	int (*fp)(char*); // pointer to function taking a char* argument; returns an int
	int* f(char*); // function taking a char* argument; returns a pointer to int

	
////// nullptr
	pi = nullptr;
	double* pd = nullptr;
	// int i = nullptr; // error: i is not a pointer


////// Arrays
	int n;
	cout << "Input an integer number: ";
	cin >> n;
	int v1[n]; // error: array size not a constant expression
	vector<int> v2(n); // OK: vector with n int elements

	// above main(): int a1[10]; // 40 ints on the free store
	int a2 [20]; // 20 ints on the stack
	int* p2 = new int[40]; // 40 ints on the free store

	
////// Array Initializers
	int v1_b[] = {1, 2, 3, 4};
	char v2_b[] = {'a', 'b', 'c', 0};
	int v5[8] = {1, 2, 3, 4}; // is equivalent to
							  // int v5[] = {1, 2, 3, 4 , 0, 0, 0, 0};

	// int v6[8] = v5; // error: can’t copy an array (cannot assign an int* to an array)
	// v6 = v5; // error: no array assignment


////// String Literals
	char alpha[] = "abcdefghijklmnopqrstuvwxyz"
					"ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	// it is the same "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";


////// Raw Character Strings
	string s = "\\w\\\\w";
	string s2 = R"(\w\\w)";

	string counts {R"(1
	22
	333)"};
		// is equivalent to
		string x {"1\n22\n333"};


////// Pointers into Arrays
	int v[] = {1, 2, 3, 4};
	int* p1 = v; // pointer to initial element (implicit conversion)
	int* p2_b = &v[0]; // pointer to initial element
	int* p3 = v+4; // pointer to one-beyond-last element


////// Navigating Arrays
	char v_char[] = "teste";
	for (int i = 0; v_char[i]!=0; ++i)
		cout << " " << i[v_char];
	cout << "\n";
	// "There is no inherent reason why one version should be faster than
	// the other. With modern compilers, identical code should be
	// (and usually is) generated for both examples. Programmers can
	// choose between the versions on logical and aesthetic grounds."
	for (char* p = v_char; *p!=0; ++p)
		cout << " " << *p;
	cout << "\n";

	// a[j] == *(&a[0]+j) == *(a+j) == *(j+a) == j[a]


////// Pointers and const
	char *p_b;

	char s_b[] = "Gorm";
	const char* pc = s_b; // pointer to constant
	// pc[3] = 'g'; // error: pc points to constant
	pc = p_b; // OK
	
	char *const cp = s_b; // constant pointer
	cp[3] = 'a'; // OK
	// cp = p_b; // error: cp is constant
	
	const char *const cpc = s_b; // const pointer to const
	// cpc[3] = 'a'; // error: cpc points to constant
	// cpc = p_b; // error: cpc is constant
	
	char *const cp_b = p_b; // const pointer to char
	char const* pc_b = "teste"; // pointer to const char
	const char* pc2; // pointer to const char

	return 0;
}