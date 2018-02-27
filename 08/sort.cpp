#include <iostream>
using std::cin;
using std::cout;
#include <vector>
using std::vector;

/* TODO: without reading any of the code below, try to write this
 * program on your own. */
/* TODO: as you are reinventing this program, try to think through
 * the invariants for your variables. */

/* input: vector V and an index start for where to start
 * output: index of smallest element in V. */
size_t findIndexOfSmallest(const vector<int>& V, size_t start)
{
	size_t i = start; /* index of the smallest thing we've seen so far. */
	/* NOTE: size_t is a machine-dependent type to store unsigned
	 * integers.  It will be as large as machine registers.  On my
	 * computer size_t is the same as uint64_t, or unsigned long. */
	for (size_t j = start+1; j < V.size(); j++) {
		/* preserve the meaning of i. */
		if (V[j] < V[i])
			i = j;
	}
	return i;
}

/* input: vector V
 * output: none, but rearrange V's elements to be in ascending order. */
void selectionSort(vector<int>& V)
{
	/* for i=0..size-2, repeatedly swap the ith element with the smallest
	 * element in V[i..size-1] */
	for (size_t i = 0; i < V.size()-1; i++) {
		size_t smallest = findIndexOfSmallest(V,i);
		/* swap V[i] <--> V[smallest] */
		int temp = V[smallest];
		V[smallest] = V[i];
		V[i] = temp;
	}
}

int main()
{
	vector<int> V;
	int n;
	while(cin >> n) V.push_back(n);
	selectionSort(V);
	for (size_t i = 0; i < V.size(); i++) {
		cout << V[i] << "\n";
	}
	return 0;
}

/* NOTE: to test this, compile with the makefile and then
 * you could do something like this:
 * $ echo {10..1} | ./sort
 * or if you want to be fancy:
 * $ head -c 60 /dev/urandom | xxd -p -c 3 | tr 'a-f' '1-6' | ./sort
 * and see if the numbers come out in order.
 * */
