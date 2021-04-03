#include "pch.h"
#include "CppUnitTest.h"
#include "Q3_header.h";
#include <random>

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

std::string random_string()
{
	// Generates a randon string containing only allowed characters

	std::string str("abcdefghijklmnopqrstuvwxyz"); // All possible Lowercase portuguese characters

	std::random_device rd;
	std::mt19937 generator(rd());

	std::shuffle(str.begin(), str.end(), generator);

	return str.substr(0, rand() % 8);    // assumes str in the range 1 to 100       
}



namespace SIEMENSQ4
{
	TEST_CLASS(SIEMENSQ4)
	{
	public:

		TEST_METHOD(isSizable)
		{
			// Assure  1<= k <= 100
			MyClass_Q3 q4;

			// test1 _Range of feasible integers
			{
				for (int k = 1; k < 100; k++)
					Assert::AreEqual(true, q4.isSizable(k));
			}
			// test2 _Range of unfeasible lower integers
			{
				for (int k = -10000; k < 1; k++)
					Assert::AreEqual(false, q4.isSizable(k));

				for (int k = 101; k < 10000; k++)
					Assert::AreEqual(false, q4.isSizable(k));
			}
		}

		TEST_METHOD(isLowercasePortuguese)
		{
			// Assure  that all chars from strings are LowercasePortuguese
			MyClass_Q3 q4;

			// test1 _Check if the string is LowercasePortuguese
			{
				for (int k = 97; k < 122; k++) {

					char cAux = (char)k;
					string sAux;
					sAux += cAux;
					Assert::AreEqual(true, q4.isLowercasePortuguese(sAux));
				}
			}
			// test2 _Check if the string is not LowercasePortuguese
			{
				for (int k = -128; k < 97; k++) {
					char cAux = (char)k;
					string sAux;
					sAux += cAux;
					Assert::AreEqual(false, q4.isLowercasePortuguese(sAux));
				}

				for (int k = 123; k < 127; k++) {
					char cAux = (char)k;
					string sAux;
					sAux += cAux;
					Assert::AreEqual(false, q4.isLowercasePortuguese(sAux));
				}
			}

		}

		TEST_METHOD(check_integer)
		{
			/*	Actually, the function "checkInteger" is similar to "isSizable".
But it is important to test this function, just in case more integer
constraints become necessary for the code. in the future. */
			MyClass_Q3 q4;

			// test1 _Range of feasible integers
			{
				for (int k = 1; k < 100; k++)
					Assert::AreEqual(true, q4.isSizable(k));
			}
			// test2 _Range of unfeasible lower integers
			{
				for (int k = -10000; k < 1; k++)
					Assert::AreEqual(false, q4.isSizable(k));

				for (int k = 101; k < 10000; k++)
					Assert::AreEqual(false, q4.isSizable(k));
			}
		}

		TEST_METHOD(check_string)
		{
			MyClass_Q3 q4;
			//   Constraint:
			// d) s and t consists of lowercase letters of the Portuguese alphabet, ascii [a-z]
			string s1,	// abcABC123	size == 16
				s2,		// abcABC		size == 16
				s3,		// ABC123		size == 16
				s4,		// 123			size == 16
				s5,		// ABC;			size == 16
				s6;		// abc			size == 16

			s1 = "pYkhr2fw3CAmEflq";
			s2 = "qQlvnzXLDzUQAaNr";
			s3 = "IEKBU0YNS4UEIR53";
			s4 = "6834253190000030";
			s5 = "AGPKTXNYTOIKUEAH";
			s6 = "gvddtelzjckxerib";

			// string abcABC123	- NOK
			Assert::AreEqual(false, q4.check_string(s1));
			// string abcABC	- NOK
			Assert::AreEqual(false, q4.check_string(s2));
			// string ABC123	- OK
			Assert::AreEqual(true, q4.check_string(s3));
			// string 123		- OK
			Assert::AreEqual(true, q4.check_string(s4));
			// string ABC		- OK
			Assert::AreEqual(true, q4.check_string(s5));
			// string abc		- OK
			Assert::AreEqual(true, q4.check_string(s6));

			// sizability

			//    a) 1 <= | s | <= 100 
			//    b) 1 <= | t | <= 100
			string sz1,		// str = "abc...",		size == 200
				sz2,		// str = "abc...",		size == 101
				sz3,		// str = "abc...",		size == 100
				sz4,		// str = "abc...",		size == 10
				sz5;		// str[1:1] = "a"		size == 1


			sz1 = "ftgofkqwwpbduwwwrivckdbpqvvepzeygceynfztdaykqzkhdgbhydpthqbrhpxzfapzbpmeaqtbddjczlxqjlteapsowddpfvuhltfymcsiaxnwtodikudrtxzqjypjfftybgrkqtzbqshciuibyujxnresaattrixrobjgbgoqglhcgqzqybovqgbfdkjwfoyfvefu";
			sz2 = "hnjribzqqoscdmvotdwqatismlbrzryurgskewhfdsdyaklwsqejmuvuopnojxqkhityaecwnftacmagrrygbkgopyuvlzlwvqdtd";
			sz3 = "oksojkzakbeycmazhrwfydwonqyeqavarfwaiqfzksioncafhcfeabbuvsclqurhhwxexzhylwlpbkqlyyswdjzqosbstcklpbeu";
			sz4 = "ktctdtocuc";
			sz5 = "a";

			// string too long - NOK
			Assert::AreEqual(false, q4.check_string(sz1));
			// string 101 chars - NOK
			Assert::AreEqual(false, q4.check_string(sz2));
			// string 100 chars - OK
			Assert::AreEqual(true, q4.check_string(sz3));
			// string 10 chars - OK
			Assert::AreEqual(true, q4.check_string(sz4));
			// string 1 chars - OK
			Assert::AreEqual(true, q4.check_string(sz5));

		}

		TEST_METHOD(ConcatRemove)
		{
			// Assure that independent from the integer "k" and the lowercase string inserted into "s" or "t"
			// the code respect the constraints and its output is consistent, as well as expected.
			{
				string 	r1 = "yes";
				string	r2 = "no";
				string s, t, res;

				for (int j = 1; j < 100; j++) { // test 100 different couple of strings
					s = random_string();
					t = random_string();

					int p = 0;
					while (p < min(size(s), size(t)) && s[p] == t[p])
						++p;


					for (int k = 1; k < 100; k++) { // for k variating from 1 to 100
						int vmin;
						if (k % 2 == (size(s) + size(t)) % 2) {
							vmin = size(s) + size(t);
							vmin += -2 * p;
						}
						else
							vmin = size(s) + size(t) + 1;

						if (k < vmin)
							res = r2; //	"expected result - no"				
						else
							res = r1; //	"expected result - yes"

						MyClass_Q3 q4;
						Assert::AreEqual (res, q4.ConcatRemove(s, t, k));
					}
				}
			}

		}
	};
}
