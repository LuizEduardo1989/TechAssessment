This folder cointains all the files necessary to run the code related to Question 3 (Q3) and Question 4 (Q4).

Such files contains usefull information:
Q34_DEMAND.docx 		- Task definition;
Q34_README.txt			- How to run the code;
Q3_CODES			- codes folder.
Q4_CODES			- codes folder.

There are two main files on Q3_CODES folder.
On SIEMENS Q3:
Q3_header.h		- The header file, containing all the functions;
Q3_main.cpp		- The main file, containing the principal function call;

In Q4_CODES:

pch.h			- The header file containing test functions;
pch.cpp			- Cpp file containing test functions;
Q4_main.cpp		- The main file, containing the principal function call;

~~~~~~~~
GDB link:
https://onlinegdb.com/ByQvYxSS_

=========================================================================

SOLUTION Q3:
If we can obtain string by performing operations, then we can also obtain it in x+2.i operations for any i>=1 by repeatedly deleting and re‐appending the last character. Thus, it’s sufficient to find some minimal even and minimal odd v such that t can be obtained in operations.
We denote the length of the longest common prefix of s and t to be p. Because we know that the first p characters in s and t are the same in both strings, that tells us the minimum number of operations we must perform is d = |s| + |t| -2.p. If d is of the same parity as k, we can simply
check that k>=d.
If d and k do not have the same parity, the only way we can change the parity of the length of the string after k steps is to perform a deletion on an empty word. This means we must erase s, perform
an additional delete operation, and then append each character in t for a total of f=|s| + |t|+1 operations. Then we print Yes if and only if k>=f.

=========================================================================

SOLUTION Q4:
 Taking into account that GBD online has no test library, Microsoft Visual Studio lybrary was used to allow carry out the tests proposed on Q4. So, the code is not testable in GBD online, however in Microsoft Studio it is possible to test the entire solution.

GDB link
https://onlinegdb.com/-EEpnF4Vm

========================================================================