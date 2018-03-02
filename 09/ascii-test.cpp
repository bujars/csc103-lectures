#include <iostream>
using std::cout;

/* TODO: try to understand this and read a litle about ascii
 * on wikipedia or similar. */
int main() {
	/* print out part of an ascii table: */
	for (int i = 32; i < 128; i++) {
		// cout << i << " ";
		cout << (char)i << " ";
		/* NOTE: above is called "typecasting".
		 * The above is called a "c-style" cast.
		 * Another use-case: say you want to divide
		 * two integers, but not lose the fractional
		 * part.  Do this:  i1/(double)i2; */
	}
	cout << "\n";
	return 0;
}
