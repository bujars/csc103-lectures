/* Examine how vector capacity grows... */

#include <iostream>
using std::cin;
using std::cout;
using std::endl;
#include <vector>
using std::vector;
#include <cstdio>

/* NOTE: Each vector keeps track of its *capacity*, which is the amount
 * of "slots" it has for the elements ("sub-variables").  The push_back
 * function will make new slots *if necessary*, but this doesn't happen
 * each time.  The following function can help you see what's going on:
 * */
void test() {
	/* watch how the vector grows: */
	printf("testing capacity growth...\n");
	vector<int> v;
	for (size_t i = 0; i < 20; i++) {
		printf("%lu\n",v.capacity());
		v.push_back(i);
	}
	/* TODO: figure out the pattern / rule for how capacity is
	 * updated, and then see if you can figure out *why* they chose
	 * to use that pattern... */
}

int main(void)
{
#if 1
	test();
#else
	/* TODO: as an alternative to using the above function, just
	 * run the code below under gdb.  Break on the main function, and
	 * then display the vector each time, which will print the size,
	 * capacity, and the contents after each step.
	 * NOTE: switching the #if 1 above to a #if 0 toggles between
	 * these two blocks of code. */
	int n;
	vector<int> V;
	while (cin >> n) {
		V.push_back(n);
	}
#endif
	return 0;
}

/* NOTE: here are the shell + gdb commands in case you need a reminder:
 * $ make
 * $ gdb capacity-test
 * (gdb) break main
 * (gdb) run <<< "2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2"
 * (gdb) display V
 * (gdb) n
 * (gdb) n
 * ...
 * */
