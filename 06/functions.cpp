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

//NOTE this is the proper way to decalre the funtion.
int maxNum(int x, int y, int z);
double average(double x, double y, double z);
void swapTwo(int& x, int& y);
bool isPrime(int x);
int fibSeq(int n);



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

	int n = 3;
	int o = 5;
	int p = 2;
	int max = maxNum(n, o, p);
	cout << max << endl;
	double a = 0.1;
	double b = 4.7;
	double c = 9.2;
	double avg = average(a, b, c);
	cout << avg << endl;
	swapTwo(n, o);
	cout << n << endl << o << endl;
	int notPrime = 3;
	bool isPrimeCheck = isPrime(notPrime);
	cout << isPrimeCheck << endl;
	int fibSeqN = fibSeq(n); //Notice that n has been swapped and is 5 not 3. 
	cout << fibSeqN << endl; 
	return 0;
}

/* NOTE: we can have multi-parameter functions -- just separate each with
 * a comma, like this:
 * int f(int x, int y, int z) {...}
 * */

/* TODO: write a function that takes 3 integers and returns
 * the maximal value */
	int maxNum(int x, int y, int z){
		int max;
		if(x >= y && x >= z)
			max = x;
		else if (y>=x && y>=z)
			max = y;
		else
			max = z;
		return max;
	}



/* TODO: write a function that takes 3 doubles and returns the
 * average value */

	double average(double x, double y, double z){
		double average = (x + y + z)/3;
	}



/* TODO: write a function that takes two integer parameters and
 * swaps the contents, i.e., if x=2 and y=5, then after calling
 * swap(x,y), y=2 and x=5 */

	void swapTwo(int& x, int& y){ //notice the by reference, notice its a void function because you are only changing values. 
		int temp = y;
	 	y = x;
		x = temp; 
	}



/* TODO: write an isPrime function that takes an integer and returns a boolean
 * value indicating whether or not it is prime.  */

	bool isPrime(int x){
		bool primeRes = true;
		int divisor = x - 1;
		if(x <= 1 || x%divisor == 0){
			primeRes = false;
		}
		while((x%divisor != 0 && primeRes == true) && divisor > 1){
			--divisor;
			if(x%divisor == 0 && divisor > 1){
				primeRes = false;
			}
		}
		return primeRes;
	
	}




/* TODO: write a *function* that takes an integer n and returns the
 * nth term in the Fibonacci sequence. */
	int fibSeq(int n){
		if(n < 2){
			return 1; //This is because we are not looking into backward fib sequence and the first two terms we use are 1 and 1. 
		}
		int fT = 1; //First Term of Sequence is 1
		int sT = 1; //Second Term of Sequence is 1
		//int nT; //Incase someone inpputs a value less than second term
		int i = 1; //Start i at 2 since we dont want it to recompute the fT/sT start
		while(i < n){
			i++;
			int nT = fT + sT;
			fT = sT;
			sT = nT;
		}
		return sT; 
	}


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
