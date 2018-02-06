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
		/* NOTE NOTE NOTE. So, I tried out the to do. WHat prints out is
		 * error lvalue required as left operand of assignment
		 * StackOverflow: this basically means you cannot do d+e without
		 * either storing that value somewhere, or comparing it to in our case
		 * of d+a. If this doesn't come to mind, go back to stackoverflow.
		 */

	} else {
		cout << "e was not equal to a\n";
	}
	/* NOTE NOTE NOTE --- need to place this at end to do the to do questions
	 * return 0; */
	/* NOTE: the return 0 gives a value back to *the shell*
	 * Convention: 0 means "everything was OK",
	 * and any other value means "something went wrong".
	 * You can get this value from the shell using 'echo $?'
	 * */


	/* TODO:
	 * 1. again, make sure you can compile this on the command line.
	 * 2. experiment with it.  make a change that doesn't compile and
	 *    try to make sense out of the resulting error messages.
	 * 3  make sure you have streamlined the process of editing,
	 *    compiling, and testing your program.
	 * 4. play with git.  see the tutorial.  be sure to get
	 *    familiar with 'git diff' and 'git log -p'. */


	/* NOTE NOTE NOTE TODO. In lecture 2, the last question says,
 	* what will out outpiut be if a = 2.55. What I am trying to figure
 	* out is, is it still the value of a that is printed.
 	* NOTE NOTE -- Before coding, I relooked at the question,
 	* this did not answer what I had above, but i realized we initialize
	* * a to a double, not an int. So what I now assume is that the value of
 	* a will be casted and infact it will just be 2.*/
	//renamed aa since a already defined before
	int aa;
	aa = 2.55;
	cout << "Lecture two sample excersize: " << aa << "\n";
	//NOTE NOTE NOTE --- this inface does work, it just prints
	//the value of 2. So infact it does cast it.




	/* TODO: write a small program that reads 3 integers (from stdin, using
 	* cin), and prints the *average* of the 3 to stdout (using cout).
 	*/
	int one, two, three;
	double avg; //note average can be a decimal value
	cout << "We will caclulate the average of 3 numbers.\n"
		<< "Please insert the first number. ";
	cin >> one;
	cout << "\nPlease insert the second number. ";
	cin >> two;
	cout << "\nPlease insert the third number. ";
	cin >> three;
	avg = (one + two + three)/3;
	cout << "\nThe average is " << avg << ".\n";

	/* *TODO: do the same for 5 integers, but ONLY USE TWO VARIABLES! */

	int inputtedInteger;
	double sum; /*So my attempt is to add the ints into inputtedIntegers. The second varible I would use as maybe as the value to calculate it all?? --Want to understand how to do this more.*/
	cout << "Welcome to the 5 integer average calulator.\n";
	cout << "The very first thing I am going to do is record each of your numbers.\n";
	cout << "Please enter your first integer. ";
	cin >> inputtedInteger; //Stores user int into inputtedInteger
	sum+= inputtedInteger; //THis means sum is the value of sum plus inputtedInteger.
	cout << "Please enter your second integer. ";
	cin >> inputtedInteger; //Notice, the value of inputtedInteger becomes this new value;
	sum+= inputtedInteger;
 	cout << "Please enter your third integer. ";
	cin >> inputtedInteger;
	sum+= inputtedInteger;
	cout << "Please enter your fourth integer. ";
	cin >> inputtedInteger;
	sum+= inputtedInteger;
	cout << "Please enter your fifth and final integer. ";
	cin >> inputtedInteger;
	sum+= inputtedInteger;
	cout << "The average of the integers you inputted is "
		<< (sum)/5.0 << ".\n";
	return 0;
}


