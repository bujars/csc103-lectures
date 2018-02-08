#include <iostream>
using std::cout;

/* TODO: predict the output of this program *without* running it!
 * Then compile and run it to check your answers and make sure you
 * understand what is going on if any of your guesses were wrong. */

int main()
{
	int x = 9;
	while (x > 0) {
		if (x > 6 || x % 5)
			cout << "x == " << x << "\n";
		x -= 2;
	}
	cout << "x == " << x << "\n";
	return 0;
}

/* Assumptions:
* At first it was x == 9, 7, 5, 3.
* I then realized that the cout inside the if statement only prints when that is true, and that the x-=2 code isn't inside and still continues until x < 0.
* For the x%5 part of the code, it runs for 9, 7, 3, 1 but not 5, so I assume that that expression is true when there is a remainder.
* Hence then 5 is never actually printed.
The code again, stops at -1 because that is < 0.
* Corrected Assumptuions : 9, 7, 3, 1, -1 ---Which is what gets outputted.
*/