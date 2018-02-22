#include <iostream>
using std::cin;
using std::cout;
#include <vector>
using std::vector;

int main()
{
	/* Exercise: read a list of integers from standard input and print
	 * it back to standard output in reverse order. */
	/* NOTE: vector is a template!  Think of it like
	 * a machine that accepts a datatype T, and produces
	 * a new datatype "vector of T's" */
	// vector V; /* won't compile!  vector is not a type! */
	vector<int> V; /* store entirety of input */
	int n; /* hold single input */
	while (cin >> n) {
		V.push_back(n);
	}
	/* How to access the elements of V?  Use square brackets
	 * and an index, and the first one has index 0.
	 * How to know how many elements are in V?  Use V.size(). */
	for (int i = V.size() - 1; i >= 0; i--) {
		cout << V[i] << "\n";
	}
	return 0;
}

/* NOTE: there is a makefile target for this, so you just have to run 'make'
 * to compile it.  The program will be named 'reverse', and you can test it
 * as follows:
 * $ echo {1..10} | ./reverse
 * above should print 10,9,... etc., each on a new line. */

/* TODO: write a function that takes a vector and searches
 * for a particular value x, returning true <==> x is found.
 * NOTE: you should think carefully about how to pass the parameters,
 * especially for the vector.  (By value, reference, const reference?) */

/* TODO: write a *binary search* on a sorted vector.  The idea is to
 * kind of emulate the process you use to find a particular page in a book:
 * 1. open the book to some page in the middle.
 * 2. if the page number was too high, open to the middle of the pages to the
 *    left; if it was too low, open to the middle of the pages to the right
 * 3. continue as above until you found the right page.
 *
 * This might be a little challenging.  Ask questions if you get stuck.
 * */

/* TODO: write a function that takes a vector and places the elements
 * in sorted order.  Warning: this could be kind of challenging. */
