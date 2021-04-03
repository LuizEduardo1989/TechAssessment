#pragma once

#include <iostream>
#include <vector>
#include <string>
using namespace std;

//Write a C / C++ or Java program that prints each number from 1 to 100 on a new line.
//
//For each multiple of 3, print "Foo" instead of the number.
//For each multiple of 5, print "Baa" instead of the number.
//For multiple numbers simultaneously of 3 and 5, print "FooBaa", instead of the number.



class FOOBAA_LIST
{
private:
	int iMax;				// range limit
	int iDiv1;				// Divisor 1 related to Foo
	int iDiv2;				// Divisor 2 related to Baa
	string sFoo;			// string sFoo
	string sBaa;			// string sBaa
public:	
	vector <int> vFoo, vBaa, vFooBaa, vInum;	//	Declaring index vector results
	vector <string> vPrint;						//	Declaring print vector
	void fillResults(
		int iCounter,			/**<	iterator from 1 to 100		*/
		vector<int>* vInt,		/**<	vFoo,		vector containing all values divisible per 3
										vBaa,		vector containing all values divisible per 5
										vFooBaa,	vector containing all values divisible per 5
										vInum,		vector containing all values non-divisible per 3 or 5		*/
		vector<string>* vStr,	/**<	vPrint,		vector containing printable strings, e.g. "1","2","Foo",...	*/
		string str1);			/*<		string that will be printed on each line, e.g. "Foo", "Baa", "FooBaa", "1", "2", ... */

	// Constructor
	FOOBAA_LIST(int max, int i1, int i2, string s1, string s2) {
		// Filling the private variables 
		iMax = max;					
		iDiv1 = i1;					
		iDiv2 = i2;					
		sFoo = s1;
		sBaa = s2;

		// Inserting the print codes
		for (int ii = 1; ii <= iMax; ii++) {
			if ((ii % iDiv1 == 0) && (ii % iDiv2 == 0)) // divisible per both divisors
				FOOBAA_LIST::fillResults(ii, &vFooBaa, &vPrint, sFoo + sBaa);	// call function
			else if (ii % iDiv1 == 0)					// divisible per divisor 1
				FOOBAA_LIST::fillResults(ii, &vFoo, &vPrint, sFoo);				// call function
			else if (ii % iDiv2 == 0)					// divisible per divisor 2
				FOOBAA_LIST::fillResults(ii, &vBaa, &vPrint, sBaa);				// call function
			else										// non-divisible per no divisors
				FOOBAA_LIST::fillResults(ii, &vInum, &vPrint, to_string(ii));	// call function
		}
	}

};

void FOOBAA_LIST::fillResults(int iCounter, vector<int>* vInt, vector<string>* vStr, string str1)
{
	(*vInt).push_back(iCounter);				//	Store integer values on each vector depending on its category
	(*vStr).push_back(str1);					//	Store values as strings to be printed, e.g. "1","2","Foo",...
	std::cout << (*vStr).back() << "\n";		//  Print "1","2","Foo","4","Baa", ...
};

