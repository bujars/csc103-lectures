#include <iostream>
using std::cin;
using std::cout;

int fac(int n)
{
	/* explicitly solve problem for small value of n: */
	if (n == 0) return 1;
	/* now assuming we get the right answer *on smaller inputs*,
	 * build the answer for n: */
	return fac(n-1) * n;
}
/* NOTE: the above would be better suited as a loop, but it
 * is an easy example to demonstrate the basics of recursion. */

int main()
{
	int n;
	while (cin >> n) {
		cout << fac(n) << "\n";
	}
	return 0;
}

/* TODO: WITHOUT compiling and running this, see if you can predict
 * the output of f(4). */
void f(int n) {
	if (n == 0) {
		cout << 0 << " ";
		return;
	}
	cout << n << " ";
	f(n-1);
	cout << n << " ";
}

/* TODO: review mathematical induction, and if possible practice
 * some proofs.  */
/* TODO: write a recursive function to compute x^n (x to the n power)
 * where n is an integer. */
/* TODO: write a function that recursively computes terms of the
 * fibonacci sequence.  Be careful -- it will likely be quite
 * slow on large inputs!  See if you can understand why.  */
