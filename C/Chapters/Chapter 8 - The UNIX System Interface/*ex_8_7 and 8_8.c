/*
Author: Fernando Zuher
Place: Brazil
Date: 23 May 2020
Book: The C programming language, second edition. Authors: BRIAN W KERNIGHAN and DENNIS M. RITCHIE
About: Exercise, Chapter 8 - The UNIX System Interface
*/

/*
PDF 203, Page 189

Exercise 8-7. malloc accepts a size request without checking its plausibility;
free believes that the block it is asked to free contains a valid size field.
Improve these routines so they take more pains with error checking.

Exercise 8-8 Write a routine bfree(p, n) that will free an arbitrary block p
of n characters into the free list maintained by mal10c and free. By using
bfree, a user can add a static or external array to the free list at any time.

	Nope, annoying.
*/
