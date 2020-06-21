#include <iostream>

[[ noreturn ]] void func();

int main()
{
	func();
	return 0;
}

[[ noreturn ]] void func()
{
	exit(1);
	// or infinite loop: while(1);
	// or throw: throw "something"
}

/*
https://stackoverflow.com/questions/10538291/what-is-the-point-of-noreturn

The noreturn attribute is supposed to be used for functions that don't return to the caller.
That doesn't mean void functions (which do return to the caller - they just don't return
a value), but functions where the control flow will not return to the calling function
after the function finishes (e.g. functions that exit the application, loop forever
or throw exceptions as in your example).

This can be used by compilers to make some optimizations and generate better warnings.
For example if f has the noreturn attribute, the compiler could warn you about g()
being dead code when you write f(); g();. Similarly the compiler will know not to
warn you about missing return statements after calls to f().
*/