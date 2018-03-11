#include <iostream>
using std::cin;
using std::cout;
#include <vector>
using std::vector;

bool isInVector(const vector<int> V, int x);
bool binarySearch(const vector<int>& V, int x);
//size_t findIndexOfSmallest(const vector<int>& V, size_t start);
//void selectionSort(vector<int>& V);
int smallestIndex(const vector<int>& V, int start);
void selectionSort(vector<int>& V);

int main()
{
	/* Exercise: read a list of integers from standard input and print
	 * it back to standard output in reverse order. */
	/* NOTE: vector is a template!  Think of it like
	 * a machine that accepts a datatype T, and produces
	 * a new datatype "vector of T's" */
	// vector V; /* won't compile!  vector is not a type! */
	vector<int> V; /* store entirety of input */
	int n; /* hold single input */
	while (cin >> n) {
		V.push_back(n);
	}

	/* NOTE NOTE NOTE did this before reversing the order just to check if im ding it right. */
	int x = 5;
	//cin >> x;


	//bool xInV = isInVector(V, x);
	//cout << xInV << "\n";


	selectionSort(V);
	//Prints the New Sorted Array
	for(size_t i = 0; i < V.size(); i++){
		cout << V[i] << "\n";
	}


#if 0 //Reverse
	/* How to access the elements of V?  Use square brackets
	 * and an index, and the first one has index 0.
	 * How to know how many elements are in V?  Use V.size(). */
	for (int i = V.size() - 1; i >= 0; i--) {
		cout << V[i] << "\n"; /* NOTE This reverses teh arrays order */
	}
#endif

	/* NOTE  NOTE to check binarySearch */
	/*bool bS = binarySearch(V, x);
	cout << bS << "\n";*/


	return 0;
}

/* NOTE: there is a makefile target for this, so you just have to run 'make'
 * to compile it.  The program will be named 'reverse', and you can test it
 * as follows:
 * $ echo {1..10} | ./reverse
 * above should print 10,9,... etc., each on a new line. */

/* TODO: write a function that takes a vector and searches
 * for a particular value x, returning true <==> x is found.
 * NOTE: you should think carefully about how to pass the parameters,
 * especially for the vector.  (By value, reference, const reference?) */

	bool isInVector(const vector<int>& V, int x){
		bool isInV = false;
		for(size_t i = 0; i < V.size(); i++){
			if(x == V[i]){
				isInV = true;
				break;
			}
		}
		return isInV;
	}



/* TODO: write a *binary search* on a sorted vector.  The idea is to
 * kind of emulate the process you use to find a particular page in a book:
 * 1. open the book to some page in the middle.
 * 2. if the page number was too high, open to the middle of the pages to the
 *    left; if it was too low, open to the middle of the pages to the right
 * 3. continue as above until you found the right page.
 *
 * This might be a little challenging.  Ask questions if you get stuck.
 * */

	bool binarySearch(const vector<int>& V, int x){
		bool isInV = false;
		int start = 0;
		int end = V.size()-1;
		while(start <= end){
			int mid = (start+end)/ 2;
			if(V[mid] == x){
				isInV = true;
				break;
			}
			else if(V[mid] > x)
				end = mid - 1;
			else
				start = mid + 1;
		}
		return isInV;
	}





#if 0
/* TODO: write a function that takes a vector and places the elements
 * in sorted order.  Warning: this could be kind of challenging. */

	/* Helper Method */
	size_t findIndexOfSmallest(const vector<int>& V, size_t start){
		size_t smallest = start;
		for(size_t i = start+1; i < V.size(); i++){ //NOTE WE WANT TO CHECK EVERY VALUE SO WE DONT RESTRICT THIS
			if(V[i] < V[start]){ /* NOTE We are checking the next value to the current because we are looking for the smaller value...*/
				smallest = i;
			}
		}
		return smallest;
	}


	void selectionSort(vector<int>& V){
		for(size_t i = 0; i < V.size()-1; i++){ //Note its v.size()-1 because we want to look at the indexes up to, and the last value will be sorted by the end.
			size_t j = findIndexOfSmallest(V, i); //Gets us the index of smallest value
			int temp = V[j]; //Now temporarily holds the values at the smallest indext
			V[j] = V[i]; //Turns the smallest value into the larger value
			V[i] = temp; //Turns the larger value into the smaller value
		}
	}

	/*int secondSmallest(vector<int>& v){
		int smallest = v[0];
		int largest;
		for(int i = 1; i < v.size(); i++){
			if(v[i] < smallest){
				largest = smallest;
				smallest = v[i];
			}

			}
		}*/

#endif

void selectionSort(vector<int>& v){
	for(int i = 0; i < v.size()-1; i++){
		int beg = i;
		int smallest = smallestIndex(v, i);
		int temp = v[smallest];
		v[smallest] = v[beg];
		v[beg] = temp;
	}
}

int smallestIndex(const vector<int>& v, int a){
	int smallest = a;
	for(int i = a; i < v.size()-1; i++){
		//if(v[i] < v[i+1]){
			//smallest = i;
		//}
		if(v[i] < v[a]){
			smallest = i+1;
		}
	}
	return smallest;
}
