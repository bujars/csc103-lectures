#include <iostream>
using std::cout;
using std::cin;
#include <string>
using std::string;

int main()
{
	/* IF STATEMENTS */
	/* IDEA: execute a piece of code 0 or 1 times, conditioned upon a
	 * boolean expression.
	 * */

	#if 0
	cout << "how is MTA treating you?\n";
	string response;
	cin >> response;
	if (response == "terrible") {
		cout << "i know right T_T\n";
	} else {
		cout << "interesting...\n";
	}
	#endif
	/* IF STATEMENT: GENERAL FORM
	 * if (<boolean expression>) {
	 *     any statements can go here!
	 * } else if (<some other boolean expression>) {
	 *     do these if second boolean is true
	 * } <potentially more else ifs...> {
	 * } else {
	 *     do these if all other conditions failed.
	 * }
	 * NOTE: at most one block of statements will happen.
	 * (Precisely one if there is an else clause.)
	 * */
	int x = 9;
	cout << (x = 99) << "\n";
	/* NOTE: one equals sign is assignment, not a boolean!  However,
	 * since an assignment statement has a value (like any other expression)
	 * and since integers can be treated as booleans (0 === false, anything
	 * else === true), the following cout will *always* happen!  (Also it
	 * will set x to 23.) */
	if (x = 23) {
		cout << "x was 23\n";
	}
	/* TODO: make sure you understand what is going on here.
	 * TODO: compile with the flag -Wall and take note of the warning
	 * message you get for the line above. */

	/* NOTE: Boolean expressions are expressions that can evaluate to either
	 * true or false.  For example, x == 3, or response != "yes".
	 * other (binary) boolean operators:
	 * ==
	 * !=
	 * <
	 * >
	 * <=
	 * >=
	 * The above work on integers, strings, chars, and lots more.
	 * Furthermore, we have the following operators on booleans:
	 * && -- this gives the logical "and"
	 * || -- this gives the logical "or"
	 * !  -- this gives the logical negation
	 * */

	/* LOOPS */
	#if 0
	while (true) {
		cout << "@_@  ";
	}
	#endif
	/* example: sum integers from 1 to 100 */
	int sum = 0; /* sum of all values of i so far */
	int i = 1; /* run through integers 1..100 */
	while (i <= 100) {
		sum = sum + i; /* shorthand: sum += i; */
		i = i+1; /* shorthand: i++ */
	}
	cout << "1+2+...+100 = " << sum << "\n";
	/* TODO: predict the value of i at this point in the program. */

	/* FOR LOOPS */
	/* more commonly used when you know the "bounds" */
	sum = 0;
	for (int j = 1;      j <= 100;         j++) {
		// ^once@start   ^check each time  ^happens at end of each iteration
		sum += j;
	}
	cout << "1+2+...+100 = " << sum << "\n";

	/* TODO: read a list of integers from stdin and print the *product* of
	 * them all.  NOTE: to read integers from stdin, you can use a loop
	 * like this: while (cin >> n) {...}.  Then run the program with
	 * integers fed to stdin like this: echo 8 2 3 | ./a.out
	 * and you should get 8*2*3 = 48
	 * */

	/* TODO: read those notes I gave you (l1.pdf was the file name) and
	 * try to do the exercises at the end. */

	/* TODO: given an integer n, find exponent of the largest power of two that
	 * divides n.  Example: if n = r*8 with r odd, then you should output 3
	 * since 8 = 2^3.  (You are just recovering the exponent of the 2 in the
	 * number's factorization into primes.) */
	/* IDEA: keep on dividing n by two until we can't,
	 * and keep track of how many times it worked. */



	return 0;
}
