#include<iostream>
using std::cin;
using std::cout;
using std::endl;
#include <cstdio>

/* TODO: write the recursive GCD function from lecture and make sure you
 * understand how it works.  In fact, make sure you can *prove* it works.
 * (Keep mind how we defined the size of the input as the size of the
 * second parameter.)
 * */
int gcd(int a, int b)
{
	return 1;
}

/* TODO: write the *extended* GCD algorithm, which returns gcd(a,b), but
 * also sets u and v such that ua + vb = gcd(a,b) Warning: this might take a
 * little bit of thinking (if you don't just look up the answer online).  Save
 * it for last. */
int xgcd(int a, int b, int& u, int& v)
{
	return 0;
}

void gcdTest()
{
	int a,b,d;
	cout << "Enter pairs of integers a,b for gcd test: ";
	while(cin >> a >> b) {
		d = gcd(a,b);
		printf("gcd(%i,%i) = %i\n",a,b,d);
	}
}

int main()
{
	gcdTest();
	return 0;
}

/* TODO: if you haven't already, write merge sort from last time. */
