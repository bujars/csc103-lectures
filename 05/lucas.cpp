/* Lucas sequences. */

// the usual stuff:
#include <iostream>
using std::cin;
using std::cout;
using std::endl;

int main()
{
	/* Lucas sequences (of the first kind).  For numbers P,Q, set
	 * U_n = P*U_{n-1} - Q*U_{n-2}.
	 * The first two terms are defined as 0 and 1, respectively.
	 * NOTE: this is a generalization of the fibonacci sequence
	 * (fibonacci is the special case of P==1,Q==-1).
	 * */
	/* TODO: finish our fibonacci code from class, and generalize
	 * to lucas sequences (see above). */
	int n;
	int p = 1;
	int q = 0;
	int i = 0;
	while(cin >> n){
		if(n < 1)
			p = 0;
		while(n > i){
			int temp = q;
			q = p;
			p =  q + temp;
			i++;
		}
		cout << "The Licas sequence of " << n << " is " << p << ".\n";
		p = 1;
		q = 0;
		i = 0;
	}


	
	
	return 0;
}

// vim:foldlevel=1
