#include <Q3_header.h>



int main()
{  // Declaring variables
	MyClass_Q3 q3;
	string s, t;
	int k;

	q3.InitialTexts();

	// cin - receiving user inputs

	cout << "\n" << "Type s - The starting string: ";
	cin >> s;
	
	q3.check_string(s);

	cout << "\n" << "Type t - The desired string: ";
	cin >> t;
	q3.check_string(t);

	cout << "\n" << "Type k - An integer that represents the number of operations: ";
	cin >> k;
	q3.check_integer(k);

	// function ConcatRemove
	string Answer = q3.ConcatRemove(s, t, k);

	return 0;
};
