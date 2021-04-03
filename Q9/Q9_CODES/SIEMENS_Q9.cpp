// SIEMENS_Q9.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <stdio.h>
#include <iostream>
using namespace std;
int main() {
    { // every variable char ends with '\0', so it is just to count character by character untill reach '\0'
        int i;
        char s[] = "Programming is fun";
        for (i = 0; s[i] != '\0'; ++i);

        printf("Length of the string: %d \n", i);
    }
    ///////////
    // Another way
    {
        // After every variable std::string there is a 'NULL' value, so it is just to count character by character untill reach '\0'
        int ii = 0;

        string ss = "Programming is fun";
        while (ss[ii] != NULL)        
            ++ii;
        
        cout << "Length of the string: "<< ii << endl;
    }


    return 0;
}

