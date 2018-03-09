#include <iostream>
using std::cin;
using std::cout;
#include <string>
using std::string;

size_t substring(const string& s1, const string& s2)
{
	size_t l1 = s1.length();
	size_t l2 = s2.length();
	for (size_t i = 0; i <= l1 - l2; i++) {
		/* IDEA: check for match starting at i */
		size_t j; /* TODO: understand why I put j outside the loop. */
		for (j = 0; j < l2; j++) {
			if (s2[j] != s1[i+j])
				break; /* no match starting @i */
			/* TODO: think about your prime test project.  The "shape" of
			 * this program should be similar.  This is perhaps unsurprising,
			 * since in both cases we needed to evaluate a big, parameterized
			 * conjunction (a bunch of booleans combined with '&&'). */
		}
		if (j == l2) return i;
	}
	return -1;
}

/* TODO: make sure you understand the above.  Maybe try to write it
 * over from scratch. */

/* TODO: make sure you have done all the exercises from lecture 09/ */

int main()
{
	string s1,s2;
	cin >> s1 >> s2;
	int i = substring(s1,s2);
	if (i >= 0) {
		cout << "match found at " << i << "\n";
	} else {
		cout << "no match found.\n";
	}
	return 0;
}
