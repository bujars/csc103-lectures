#include <iostream>
using std::cout;

/* TODO: predict the output of this program *without* running it!
 * Then compile and run it to check your answers and make sure you
 * understand what is going on if any of your guesses were wrong. */

int main()
{
	int x = 16;
	while (x > 0) {
		cout << "x == " << x << "\n";
		x /= 2;
	}
	cout << "x == " << x << "\n";
	return 0;
}

/* NOTE NOTE NOTE once you get to 1, when you divide by 2 again, it will go to 1/2, or 0 since it is int division. Last value of x woild be stored as 0 and then printed. */


 /* What gets printed assumtions:
 * x == 16
 * x == 8
 * x == 4
 * x == 2
 * x == 1
 * x == 0
 */
//--Yes your assumptions were correct.