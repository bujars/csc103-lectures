/* More about loops.
 * See lectures 4,5,6 from Prof. Li.,
 * and chapters 3,4 in the book. */

// the usual stuff:
#include <iostream>
using std::cin;
using std::cout;
using std::endl;
#include <cstdio>

int main()
{
	/* BIG PICTURE IDEAS WITH LOOPS.
	 * 1. "Brute force" -- leverage the speed of the computer to explicitly
	 *    run through an entire space of potential solutions, checking
	 *    each candidate for validity.  This is usually pretty trivial.
	 * 2. Maintaining invariants -- when computing some aggregate function
	 *    of a long list of inputs, initialize a variable to be something
	 *    like "the right answer so far" and then read new inputs one by
	 *    one, *updating your candidate answer* so that after each iteration
	 *    of the loop, it is ALWAYS the "right answer so far".
	 * NOTE: even brute force typically has an invariant hiding somewhere, but
	 * it usually isn't all that interesting.
	 * Let's see some examples: */

	/* exercise: compute the min of integers supplied via stdin. */
	#if 0
	int n; /* store input */
	int min; /* minimum of what we've seen *so far*. */
	cin >> n;
	min = n; /* NOTE: at this point, min's value is
				consistent with the meaning we gave it! */
	while (cin >> n) {
		if (n < min) min = n;
		/* NOTE: the *invariant* for this loop is that
		 * min is the smallest value we've read so far.
		 * Initialize min to have this property before the
		 * loop, and then at the end of each iteration, make
		 * sure this property remains true (that is to say,
		 * it's *invariant*!!).
		 * */
	}
	cout << min << "\n";
	return 0;
	#endif

	/* TODO: if you haven't already, be sure you can do this on your own,
	 * as well as similar things like the min, the sum, the product, the
	 * average...  Try to take the following very high level steps:
	 * 1. First, think about how many variables you will need, and for what
	 *    purposes.
	 * 2. Declare the variables, and in comments, state the meaning of each
	 *    variable.
	 * 3. Loop through the input and make sure the meaning of each of your
	 *    variables is preserved at the end of each iteration of the loop.
	 * 4. Finally, print the results.
	 * */

	/* exercise: brute force gcd.  Compute the greatest common
	 * divisor of n and k by an exhaustive search.  */
	/* IDEA: start with the largest possible value that the gcd
	 * could have, then walk *backwards* until you find the first
	 * value that divides both inputs. */
	/* Range of possibilities for a valid answer: {min{a,b}...1} */

	/* TODO: brute force test for perfect cubes.  Check if
	 * n = k^3 for some integer k.  */

	/* TODO: write a loop that prints the sum of the first n odd cubes. */

	/* TODO: write code that gets an integer n from the user and prints out
	 * the n-th term of the fibonacci sequence. */

	/* TODO: a slight generalization of an earlier exercise: for integers
	 * n and k, determine the largest power of k that divides n.
	 * NOTE: see if you can formalize the invariant you used to solve this.
	 * */

	/* TODO: write a program that reads (arbitrarily many) integers from
	 * stdin and outputs the *second* smallest one.  NOTE: you don't need
	 * to store many numbers (all at once, that is) to do this!  You'll
	 * only need a few integer variables.  Think about invariants! */

	/* TODO: this is really basic, but good to be aware of: if you put
	 * the arrows going the wrong way, like "cin << x" or "cout >> x",
	 * you will get some very long, nasty, confusing error messages
	 * from the compiler.  Write code with this mistake on purpose, try to
	 * compile it, and take note of those error messages so you know where
	 * to look if you ever see errors like that again in the future. */

	return 0;
}

// vim:foldlevel=1
