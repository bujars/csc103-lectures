#include <iostream>
using std::cout;
using std::cin;

int main()
{
	int x; /* make space for an integer, and label it 'x' */
	cout << x << "\n"; /* NOTE: no guarantee x will be 0! */
	x = 7; /* assignment statement: store 7 into x */
	cout << x << "\n";

	/* how many bytes does x require? */
	cout << "size of int:" << sizeof(x) << "\n";
	/* other types: */
	char c = 'x';
	cout << "size of char: " << sizeof(c) << "\n";
	double d = 100000000000000000000000000.0;
	cout << "size of double: " << sizeof(d) << "\n";
	/* NOTE: because double does not have arbitrary precision,
	 * some algebraic laws will not work!  Example:
	 * if d+a == d+e, then a should be equal to e, but behold:*/
	double a = 0.0;
	double e = 0.0000000000000001;
	if (d+e == d+a) {
		cout << "e was equal to a\n";
		/* TODO: note that *two* equals signs tests for equality.
		 * Take one of them out, try to compile, and see if you can
		 * understand the error message.  It will be a little mysterious. */
	} else {
		cout << "e was not equal to a\n";
	}
	return 0;
	/* NOTE: the return 0 gives a value back to *the shell*
	 * Convention: 0 means "everything was OK",
	 * and any other value means "something went wrong".
	 * You can get this value from the shell using 'echo $?'
	 * */
}

/* TODO:
 * 1. again, make sure you can compile this on the command line.
 * 2. experiment with it.  make a change that doesn't compile and
 *    try to make sense out of the resulting error messages.
 * 3  make sure you have streamlined the process of editing,
 *    compiling, and testing your program.
 * 4. play with git.  see the tutorial.  be sure to get
 *    familiar with 'git diff' and 'git log -p'. */

/* TODO: write a small program that reads 3 integers (from stdin, using
 * cin), and prints the *average* of the 3 to stdout (using cout).
 * TODO: do the same for 5 integers, but ONLY USE TWO VARIABLES! */
