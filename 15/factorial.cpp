#include <iostream>
using std::cin;
using std::cout;

void f(int n);
int xPower(int x, int n);
int fib(int n);

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
		//f(n);
		cout << fac(n) << "\n";
	}

	int x = 2;
	int xPowe = xPower(x, n);
	cout << xPowe << "\n";
	cout << fib(n) << "\n";
	return 0;
}

/* TODO: WITHOUT compiling and running this, see if you can predict
 * the output of f(4). */
void f(int n) {
	if (n == 0) {
		cout << 0 << " ";
		return;
	}
	cout << n << " "; //prints n first
	f(n-1); //then gets the number less all the way to zero
	cout << n << " "; // then prints everything back in reverse, as the function will hold off the original number before going onto the next function.

}

/* TODO: review mathematical induction, and if possible practice
 * some proofs.  */
/* TODO: write a recursive function to compute x^n (x to the n power)
 * where n is an integer. */

	/* NOTE did this on paper so look over notes. I made sure its postiive as 0 and negative can mess things up. -- Actually 0 would just return 0, but negative wouldn't make sense....*/
	int xPower(int x, int n){
		if(n == 1)
			return x;
		return xPower(x, n-1) * x;

		}

/* TODO: write a function that recursively computes terms of the
 * fibonacci sequence.  Be careful -- it will likely be quite
 * slow on large inputs!  See if you can understand why.  */
	/* NOTE we did this in class so some of it was from memory, but I do understand the concept of it number wise... meaning in class Skeith provided the formula for determining the number of steps, and what I gathered from my own understanding of why this takes so long is because it's just adding together a bunch of 1's over and over and over....etc
		*/

		int fib(int n){
			if(n<2) //this is the base case, ie what gets the function from keep on going - or something.
				return 1;
			return fib(n-1) + fib(n-2); //notice this is basically the function for calculating fib sequence
			}




