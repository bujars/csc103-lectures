#include "vector2.h"
#include <iostream>
using std::cout;

void fn(vector2 W) {
	W.push_back(111);
	cout << W.back() << "\n";
	return;
	/* NOTE: this function is nonsense.  It is just here to demonstrate
	 * what goes wrong without a proper copy constructor. */
}
/* TODO: comment out the copy constructor (including the prototype
 * in the .h file) and see if you can figure out why calling this
 * function breaks things. */

int main()
{
	vector2 V;
	size_t i = 0;
	for (i = 0; i < 1000; i++) {
		V.push_back(i);
	}
	/* V.pop_back(); 
	 * Aborted core dumped. The assertion that size > 0 had failed. 
	 * */
	fn(V);
	for (; i < 2000; i++) {
		V.push_back(i);
	}
	return 0;
}
