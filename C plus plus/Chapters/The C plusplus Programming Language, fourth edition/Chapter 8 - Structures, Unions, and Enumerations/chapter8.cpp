/*
Author: Fernando Zuher
Place: Brazil
Date: 15/04/2020
Book: The C++ Programming Language, fourth edition. Author: Bjarne Stroustrup.
About: A summary* of code explained in the
       Chapter 8 - Structure, Unions, and Enumerations

* Most of the written is taken literally from the chapter.

*/

#include <iostream>
using namespace std;

//////// Just Struct
struct Address {
	const char* name;	// "Jim Dandy"
	int number;			// 61
	const char* street;	// "South St"
	const char* town;	// "New Providence"
	char state[2];		// 'N' 'J'
	const char* zip;	// "07974"
};

//////// Struct layout. Better declaring first larger types,
// than smaller ones.
// 8 bytes
struct Readout1 {
	int value; // 4 bytes
	char hour; // + 1 byte
	char seq; // + 1 byte (+ 2 bytes alignment) = 8 bytes
};

// 12 bytes
struct Readout2 {
	char hour; // 1 byte (+ 3 alignment)
	int value; // + 4 bytes
	char seq;  // 1 byte (+ 3 alignment)= 12 bytes
};

//////// Just Union
union Value {
	char c;
	int i;
};

//////// Just Enumeration
enum class Warning_INT : int { red, green, blue };
enum class Warning_CHAR : char { red, green, blue };

void print_addr(struct Address* p);

int main()
{
// Struct ///////////////////////////////
	cout << "// Struct //////////////////////////////\n";

	struct Address jd = {
		"Jim Dandy",
		61, "South St",
		"New Providence",
		{'N','J'}, "07974"
	};

	print_addr(&jd);

	cout << "\nsizeof(struct Readout1): " << sizeof(struct Readout1);
	cout << "\nsizeof(struct Readout2): " << sizeof(struct Readout2);


// Union ///////////////////////////////
	cout << "\n\n// Union //////////////////////////////" << endl;
	Value x;
	
	x.i = 5;
	x.c = 'a';
	cout << "x.i = 5;" << endl << "x.c = 'a';" << endl;
	cout << "\tx.c == " << x.c << endl;
	cout << "\tx.i == " << x.i << " ('a' in integer is 97)" << endl;

	x.c = 'a';
	x.i = 5;
	cout << "\nx.c = 'a';" << endl << "x.i = 5;" << endl;
	cout << "\tx.c == " << x.c << endl;
	cout << "\tx.i == " << x.i << endl;


// Enum ///////////////////////////////
	cout << "\n// Enumeration //////////////////////////////";
	// Warning_INT a1 = 7;				// error : no int->War ning conversion
	// int a2 = green;				// error : green not in scope
	// int a3 = Warning_INT::green;		// error : no War ning->int conversion
	Warning_INT a4 = Warning_INT::blue;		// OK

	cout << "\nsizeof(Warning_INT) == " << sizeof(Warning_INT);
	cout << "\nsizeof(Warning_CHAR) == " << sizeof(Warning_CHAR);

	cout << "\n\nstatic_cast<int>(Warning_INT::red) == " << static_cast<int>(Warning_INT::red);
	cout << "\nstatic_cast<int>(Warning_INT::green) == " << static_cast<int>(Warning_INT::green);
	cout << "\nstatic_cast<int>(Warning_INT::blue) == " << static_cast<int>(Warning_INT::blue);

	cout << endl;
	if (a4 == Warning_INT::red)
		cout << "\nRED\n";
	else
		cout << "\nstatic_cast<int>(a4): " << static_cast<int>(a4)
								<< " (a4 == WARNING_INT::blue)" << endl;

	cout << endl;
	return 0;
}

void print_addr(Address* p)
{
	cout << p->name << '\n'
	<< p->number << ' ' << p->street << '\n'
	<< p->town << '\n'
	<< p->state[0] << p->state[1] << ' ' << p->zip << '\n';
}
