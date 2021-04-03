#pragma once
#include <iostream>
#include <vector>
#include <string>


#define SUCCESS		0

using namespace std;

class MyClass_Q3 {
public:
	// Returns true if s is a number else false
	// Methods
	bool isSizable(int k)
	{
		// Check if "k" is subject to constraints:
		//    a) 1 <= | s | <= 100
		//    b) 1 <= | t | <= 100
		//    c) 1 <= k <= 100
		if (k >= 1 && k <= 100)
			return true;
		else
			return false;
	};
	bool isLowercasePortuguese(string s)
	{ // Check if "k" is subject to the constraint:
	  //    d) s and t consists of lowercase letters of the Portuguese alphabet, ascii[a - z]
		for (int i = 0; i < s.length(); i++)
			if ( ((int)(s[i])) < 97 || ((int)(s[i])) > 122)
				return false;

		return true;
	};

	bool check_string(string s) {
		// check if the string is subject to all the constraints.
		if (!isSizable((int)s.size())) {
			cout << "\n" << "ERROR - string length";
			exit(1);
		}

		if (!isLowercasePortuguese(s)) {
			cout << "\n" << "ERROR - not lowercase";
			exit(1);
		}
		return true;
	};

	bool check_integer(int k) {
		// check if the integer "k" is subject to all the constraints.
		if (!isSizable(k)) {
			cout << "\n" << "ERROR - 1 <= k <= 100";
			exit(1);
		}
		return true;
	};

	void InitialTexts() {
		//Constrains
		//    a) 1 <= | s | <= 100
		//    b) 1 <= | t | <= 100
		//    c) 1 <= k <= 100
		//    d) sand t consists of lowercase letters of the Portuguese alphabet, ascii[a - z]
		// Interface with the user 
		cout << "Given an integer k and two strings s and t, determine if you can" << "\n"
			<< "convert s to t using exactly k operations described above on s." << "\n"
			<< "If possible, the program prints 'yes', otherwise it prints 'no'." << "\n" << endl;

		// Interface with the user 
		cout << "The first line contains the string s, the starting string." << "\n"
			<< "The second line contains the string t, the desired string." << "\n"
			<< "The third line contains an integer k, the number of operations." "\n" << endl;


		cout << "Constrains \n" << "\n"
			<< "a) 1 <= | s | <= 100" << "\n"
			<< "b) 1 <= | t | <= 100" << "\n"
			<< "c) 1 <= k <= 100" << "\n"
			<< "d) s and t consists of lowercase letters of the Portuguese alphabet, ascii[a - z]" "\n" << endl;


	};

	string ConcatRemove(string str1, string str2, int k) {
	//// This code is devide in 3 stages:
	//	1) Calculate the number of chars from "str1" interesting for "str2"
	//	2) define the minimum number of operations "vmin" and compare with "k"
	//	3) Print output

		//Stage 1
		int iMaxKeep = min(str1.size(), str2.size());
		int ikeep = 0;                              // keep index

		while (ikeep < iMaxKeep && str1[ikeep] == str2[ikeep])
			++ikeep; // Updating the number of characters that str1 can keep   

			//Stage 2
		int vmin;
		if (k % 2 == ((str1.size() + str2.size()) % 2)) {
			vmin = str1.size() + str2.size();
			vmin -= 2 * ikeep;
		}
		else
			vmin = str1.size() + str2.size() + 1;
		string sOut;
		if (k < vmin)
			sOut = "no";
		else
			sOut = "yes";

		cout << sOut << "\n";
		return sOut;

	};
};
