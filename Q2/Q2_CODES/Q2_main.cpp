#include <Q2_header.h>
/*
Write a C / C++ or Java program that prints each number from 1 to 100 on a new line.
//
//For each multiple of 3, print "Foo" instead of the number.
//For each multiple of 5, print "Baa" instead of the number.
//For multiple numbers simultaneously of 3 and 5, print "FooBaa", instead of the number.
//
//Your solution should be using as few lines of code as possible, but you should produce efficient code.
*/

int main() {

	FOOBAA_LIST list(		// 
		100,				// range limit
		3,					// Divisor 1 related to Foo
		5,					// Divisor 2 related to Baa
		"Foo",				// string sFoo
		"Baa");				// string sBaa		

	return 0;
};