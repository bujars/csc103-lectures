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
set<set<int> > ksubsets(set<int>& S, size_t k){

	set<set<int> >K;/*the set of ksets that will be returned for the program. Notice that S is returned in */
	if(S.size()==0){
		K.insert(S);/*Insert an empty set that will be returned*/
		return K;
	}

	/*Since the set is by reference, we need to make a clone to not alter the original*/
	set<int> clone(S);
	for(set<int>::iterator i = clone.begin(); i!=clone.end(); i++){
		int ith = *i; /*Holds the i value that will be used to add to each set...i = 1 ->  {2}{3}{4}  -> {1,2}{1,3}{1,4}*/
		clone.erase(*i); /*Remove the ith term from the set so that each one can get to {1}, {..}*/
		/*Note, the last one doesn't need to get to {last} because it gets added to each set*/

		/*Here's trouble that I'm spotting, what this is currrenly going to do is just make powersets. with restricted sizes, its not going to be computing each subset because we won't have enough subsets to be able to fill, nor pic and choose how they fill back up*/

		/*Thoughts? Maybe check and see if they are already filled up before adding back into them. So if its like {1,2, 3} {2, 3, } the four would go in the second one...Not sure if this is actually needed....Keep trying to finish the problem and then go back and see if you can refine*/

		set<set<int> > P = ksubsets(clone, k);
		K = P; /*As stated above, S is the one that is going to be returned and this the one that gets split needs to come back and update K*/
		set<set<int> >::iterator kPos = K.begin();
		for(int j = 0; j < k-1; j++){
		/*Note its k-1 because you don't want to add in the value if K is already fillded. 
		 * Maybe here is where I should check if its filled up?????? As I've noted I might need to look for from beforehand?*/
			if(kPos != K.end()){
				set<int> H = *kPos;
				H.insert(ith); /*I don't think this will actually work. This is inevideably just going to add last Up until K many times into each set...*/
				K.insert(H);
				kPos++;
			}
		}
		
	}

}
/* or with vectors: */
vector<vector<int> > ksubsets(vector<int>& V, size_t k);

int main()
{
	/* TODO: write some test code. */
	set<int>S;
	S.insert(0);
	S.insert(1);
	S.insert(2);
	set<set<int> >B = ksubsets(S, 2);
	for(set<set<int> >::iterator i = B.begin(); i != B.end(); i++){
		set<int> I = *i;
		for(set<int>::iterator j = I.begin(); j != I.end(); j++){
			cout << *j << " ";
		}
		cout << "\n";
	}
	return 0;
}
