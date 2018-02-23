/* introduction to functions.
 * reading: Prof. Li's notes, lectures 7 -- 10 */
#include <iostream>
#include <cstdio>
using std::cin;
using std::cout;
using std::endl;

/* syntax:
 * datatype function_name(parameterlist) { c++ statements...}
 * think of f(x) from your calculus days... remember this notation?
 * f:R ---> R
 * Breaking it down, it says there is a function named f, which has domain R
 * and range R.  The C++ equivalent would be something like:
 * double f(double);
 * NOTE: thing above is called a "function prototype"
 */

/* example: x --> 2x + 1, for integers x.
 * */
int f(int x) {
	/* rules go here: */
	return 2*x + 1;
}

/* TERMINOLOGY: the variable used in the parameter
 * list (like x in fn2 or fn1) is called the *formal
 * parameter*.  When you actually make a call, like
 * fn(a) in main, the variable a is the *actual parameter*.
 * Again, for by value parameters, the formal parameter
 * is a COPY of the actual, and for by reference, it is
 * a SYNONYM for the actual.
 * */

/* Question: what is the relationship (in main memory)
 * of the actual parameter and formal parameter?  That
 * is, does the formal parameter have its own memory?
 * Or is it just another name for the actual parameter? */

int test1(int x)
{
	/* NOTE: the default relationship between formal and actual parameter
	 * is called "call by value", and the formal parameter is A COPY of
	 * the actual parameter. */
	x = 999;
	return 0;
}

int test2(int& x)
{
	/* NOTE: if we put an ampersand after the type, this denotes
	 * "call by reference".  For call by reference parameters, the formal
	 * parameter is JUST ANOTHER NAME FOR THE ACTUAL PARAMETER.  Changes
	 * made to the formal parameter here will be reflected in the
	 * actual parameter.  See the example below. */
	x = 999;
	return 0;
}

int main()
{
	int y = 0;
	test1(y); /* NOTE: this is how you call functions.  It should remind you
	                   a lot of calculus. */
	cout << "y == " << y << "\n";
	test2(y);
	cout << "y == " << y << "\n";
	return 0;
}

/* NOTE: we can have multi-parameter functions -- just separate each with
 * a comma, like this:
 * int f(int x, int y, int z) {...}
 * */

/* TODO: write a function that takes 3 integers and returns
 * the maximal value */
/* TODO: write a function that takes 3 doubles and returns the
 * average value */
/* TODO: write a function that takes two integer parameters and
 * swaps the contents, i.e., if x=2 and y=5, then after calling
 * swap(x,y), y=2 and x=5 */
/* TODO: write an isPrime function that takes an integer and returns a boolean
 * value indicating whether or not it is prime.  */
/* TODO: write a *function* that takes an integer n and returns the
 * nth term in the Fibonacci sequence. */
/* TODO: write test code for all the above exercises. */
/* TODO: (WARNING: THIS IS NOT EASY. Only attempt this if you are bored.)
 * The previous exercise asked for you to compute the nth term of the
 * Fibonacci sequence.  Try to estimate approximately how many steps (number
 * of C++ statements, roughly) that your function takes to evaluate the input
 * n.  You will probably find that it is close to some constant multiple of n.
 * It turns out that there is a very clever way to do this in approximately
 * log(n) steps!  To find it, you'll probably need a hint or two to even get
 * started.  Ask me if you're interested.
 * */
