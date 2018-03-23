#include <iostream>
using std::cout;
using std::cin;
#include <set>
using std::set;
#include <vector>
using std::vector;

void  sortVector(vector<int>& v);
set<int> intersect(const set<int>& S1, const set<int>& S2);
void intTest();
void removeIth(vector<int>& v, int i);

int main()
{
	#if 0
	/* you declare them similarly to vector: you have to
	 * supply a datatype. */
	set<int> S;
	/* let's fill S with squares of integers: */
	for (size_t i = 1; i <= 100; i++) {
		S.insert(i*i);
	}
	/* now run some searches: */
	int n;
	while (cin >> n) {
		/* NOTE: this also works, and is a little simpler:
		 * if (S.count(n)) {...} */
		if (S.find(n) != S.end()) {
			cout << n << " is a square <= 100\n";
		}
	}
	/* how to just print everything in a set? */
	/* first look at this strange way to print an array: */
	int A[10] = {0,1,2,3,4,5,6,7,8,9};
	cout << "printing A:\n";
	for (int* i = &A[0]; i != &A[10]; i++) {
		cout << *i << "\n";
	}
	/* the above approach illustrates the concept of "iterators".
	 * Think of iterators as pointers to elements of a container
	 * like an array, vector, or set.  They support the * operator
	 * (dereference) as well as the ++ operator which moves the
	 * pointer to the next element of the container.
	 * */
	/* to go through a set, we do much the same thing, where
	 * S.begin() is like &A[0], and S.end() is like &A[10], which
	 * is *not* a valid element (array was only of size 10), but
	 * instead is just past the end.  Anyway, here is how to go
	 * through all elements of a set.  Note that they will always
	 * be printed in sorted order: */
	cout << "printing contents of S:\n";
	for (set<int>::iterator i = S.begin(); i != S.end(); i++) {
		cout << *i << "\n";
	}
	#endif

	vector<int> v = {0, 3, 8, 2, 7, 45, 5, 4, 3};
	for(int i = 0; i < v.size(); i++){
			cout << v[i] << " ";
		}
	cout<< "\n";
	//sortVector(v);
	removeIth(v, 3);
	for(int i = 0; i < v.size(); i++){
		cout << v[i] << " ";
	}
	cout << "\n";
	/*const set<int> S1 = {2, 3, 4, 5, 6, 7};
	const set<int> S2 = {1, 2, 4, 7, 11, 44};
	set<int> I = intersect(S1, S2);
	for (set<int>::iterator i = S1.begin(); i != S1.end(); i++) {
				cout << *i << " ";
	}
	cout << "\n";
	for (set<int>::iterator i = S2.begin(); i != S2.end(); i++) {
			cout << *i << " ";
	}
	cout << "\n";
	for (set<int>::iterator i = I.begin(); i != I.end(); i++) {
				cout << *i << " ";
	}*/
	intTest();
	return 0;
}

/* TODO: you can use sets to sort a vector or an array.  Try it maybe. */
	void sortVector(vector<int>& v){
		set<int> s;
		for(int i = 0; i < v.size(); i++){
				s.insert(v[i]);
		}
		int z = 0;
		for(set<int>::iterator i = s.begin(); i != s.end(); i++){
				cout << *i << "\n";
				v[z] = *i;
				z++;
			}
		for(z; z < v.size(); z++){
			v.pop_back();
		}
	}


/* TODO: compute the intersection of two sets.
 * Recall that the intersection of two sets is the set
 * consisting of the elements they have in common.  E.g.,
 * intersection of {2,3,4,5,6,7} and {1,2,4,7,11,44} is
 * {2,4,7}.  Here's a start: */
	set<int> intersect(const set<int>& S1, const set<int>& S2) {
		set<int> I;
		bool bF = false;
		set<int>::iterator begin = S1.begin();
		set<int>::iterator end = S1.end();
		if(S2.size()< S1.size()){
			end = S2.end();
			begin = S2.begin();
			bF = true;
		}
		for(begin; begin != end; begin++){
			if(bF && (S1.find(*begin) != S1.end())){
				I.insert( *begin);
			}
			else if(S2.find(*begin) != S2.end()){
				I.insert(*begin);
			}
		}
			/* code goes here... */
		return I;
	}
/* TODO: write a function that returns the union of two sets */
set<int> Union(const set<int>& S1, const set<int>& S2){
	set<int> U; 
	for (set<int>::iterator i = S1.begin(); i != S1.end(); i++) {
		U.insert( *i);
	}
	for (set<int>::iterator i = S2.begin(); i != S2.end(); i++) {
		U.insert(*i);
	}
	return U;	
}


/* TODO: write a function that takes an index i and a vector
 * V and removes the i-th element.  If you don't have to
 * preserve the order, how could you do this with only a
 * constant number of steps?  (Say, using one call to pop_back()?)
 * */

void removeIth(vector<int>& v, int i){
	if(i < v.size()){
		v[i] = v[v.size()-1];
		v.pop_back();
	}
}



/* Some test code for your intersect function: */
void intTest() {
	set<int> s1 = {2,3,4,5,6,7};
	set<int> s2 = {1,2,4,7,11,44};
	set<int> s3 = intersect(s1,s2);
	cout << "intersection contained: ";
	for (set<int>::iterator i = s3.begin(); i != s3.end(); i++) {
		cout << *i << " ";
	}
	cout << "\n";
	set<int> s4 = Union(s1, s2);
	cout << "union: ";
	for (set<int>::iterator i = s4.begin(); i != s4.end(); i++) {
		cout << *i << " ";
	}
	cout << "\n";
}

/* NOTE: you'll have to prototype these above main() if you want to
 * call them from main(). */
