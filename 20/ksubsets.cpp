#include <iostream>
using std::cout;
#include <vector>
using std::vector;
#include <set>
using std::set;

/* TODO: write a function to compute all *k-subsets* of a given set.
 * Recall that k-subsets are subsets with *precisely* k elements.
 * Below are some function prototypes you could use.  See the notes
 * for the intuition and an outline. */

/* with sets: */
set<set<int> > ksubsets(set<int>& S, size_t k);
/* or with vectors: */
vector<vector<int> > ksubsets(vector<int>& V, size_t k);

int main()
{
	/* TODO: write some test code. */
	return 0;
}
