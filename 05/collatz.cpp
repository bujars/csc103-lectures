/* More about loops.
 * See lectures 4,5,6 from Prof. Li.,
 * and chapters 3,4 in the book. */

// the usual stuff:
#include <iostream>
using std::cin;
using std::cout;

int main()
{
	/* Collatz conjecture: for all integers n, the following process
	 * will terminate in a finite number of steps:
	 *    if n == 1, stop;
	 *    if n is even, divide by 2;
	 *    if n is odd, multiply by 3 and add 1;
	 *    repeat using this new value of n.
	 * */
	/* TODO: write a program that tests the conjecture for arbitrarily
	 * many integers, provided on standard input.  (Just print the input
	 * and the number of steps it required before terminating.) */

	int n;
	int original;
	int steps = 0; 
	int maxN;
	while(cin >> n){
		original = n;
		maxN = n;
		if(n == 1){
			steps++;
			//cout << "The integer is " << original << ". The number of steps it took was " << steps << ".\n";
			//return 0;
			//break;
		}
		else {
			while(n > 1){
				if(n > maxN)
					maxN = n;
				if(n % 2 == 0){
					n = n / 2;
					steps++;
				}
				else{
					n = (n *3) +1;
					steps++;
				}
			}
		}
		cout << "The integer is " << original << ". The number of steps it took is " << steps << ". The maximal intermediate value is "<< maxN << ".\n";
		steps = 0;
	}
	
	return 0;
}

/* TODO: keep track of the maximal intermediate value and print that out
 * along with the result. */
 /* NOTE NOTE NOTE I added this between */
// vim:foldlevel=1
