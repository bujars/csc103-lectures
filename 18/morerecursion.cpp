#include<iostream>
using std::cin;
using std::cout;
using std::endl;

/* TODO: write the *extended* GCD algorithm, which returns gcd(a,b), but
 * also sets x and y such that ax + by = gcd(a,b).  We did this in lecture,
 * but try to do it here from scratch (don't look at the notes unless you
 * have to). */
int xgcd(int a, int b, int& x, int& y)
{
	if(b == 0){
		x = 1;
		y = 0;
		return a;
	}
	int xx, yy, q= a/b, r= a%b;
	cout << q << endl << r << endl;
	int d = xgcd(b, r, xx, yy);
	x = yy;
	cout << x << endl;
	y = xx - q*yy;
	cout << y << endl;
	return d;
}

void xgcdTest()
{
	/* TODO: write some test code for xgcd. */
}

int main(int argc, char** argv)
{
	int a = 1;
	int b = 2;
	int x = xgcd(18, 12, a, b);
	cout << x << endl;
	cout << a << endl;
	cout << b << endl;
	return 0;
}
