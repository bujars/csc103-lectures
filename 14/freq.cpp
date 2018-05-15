#include <iostream>
using std::cout;
using std::cin;
#include <vector>
using std::vector;
#include <string>
using std::string;
#include <map>  // also known as an "associative array"
using std::map; // you can think of maps kind of like arrays,
				// but the indexes no longer have to be integers...
				// e.g., we could do A["a string"] = 100;

/* print a frequency table of strings given on stdin */
int main(){
	
#if 0 
	map<string,int> F; /* store frequency table */
	string s; /* hold an input */
	while (cin >> s) F[s];
	/* NOTE: it is crucial that integers are initialized
	 * to 0 here.  (Remember: integers that aren't part of a map
	 * are not initialized to 0 for you.) */
	/* now just print F... */
	for (map<string,int>::iterator i = F.begin(); i != F.end(); i++) {
		cout << (*i).first << ":\t" << (*i).second << "\n";
	}
	/* NOTE: each node has two parts (the key, and the associated
	 * value).  The .first and .second give you those two parts,
	 * respectively. */


#endif
/* TODO: try to solve the same problem *WITHOUT* using maps!  Can you do
 *  * it with just vectors?  How about just sets?  */
		
	string s;
	vector<string> F;
	vector<int> count;
	bool bF = true;
	while(cin >> s){
	//	cout << s << "\n";
		for(int i = 0; i < F.size(); i++){
			//cout << "here1" << "\n";
			if(F[i] == s){
				//cout << "here2\n";
				count[i] = count[i] + 1;
				bF = false;
			}
		}
		if(bF){			
			F.push_back(s);
			count.push_back(1);
		}
		bF = true;
	}
	for(int i = 0; i < F.size(); i++){
		cout << F[i] << ": " << count[i] << "\n";
	}




	return 0;
}

/* TODO: re-write the above from scratch and make sure you understand
 * why it works. */
#if 0
	map<string, int> F; /*makes the map for where the frequency table will be*/
	string s; //where the input string is stored
	while(cin >> s){
		F[s]++; //Not to insert into the first spot in the map, you do the F[s] and the ++ increments the int component to it
		//I initially did insert() as thats what a set does, but that is incorrect. 
		//So the way to insert stuff into a map is... mapName[first thing]secondthing;
	}
	for(map<string, int>::iterator i = F.begin(); i != F.end(); i++){
		cout << (*i).first << ": " << (*i).second << "\n"; //Note the *i is how you access whats in F, and first refers to whats on the left, second whats on the right
	}

#endif
	

/* TODO: try to solve the same problem *WITHOUT* using maps!  Can you do
 * it with just vectors?  How about just sets?  */
	
#if 0
//put in main
	string s;
	vector<string> F;
	vector<int> count;
	bool bF = tF;
	while(cin >> s){
		for(int i = 0; i < F.size(); i++){
			if(F[i] == s){
				count[i] = cout[i]++;
				bF = false;
			}
		}
		if(bF){
			F.pop_back(s);
			count.pop_back(1);
			bF = true;
		}
	}
#endif

/* TODO: if you managed to solve the above, estimate the number of
 * instructions your program will require to run on an input of n strings.
 * Then compare this with the solution using maps.  Note that M[s]++ takes
 * approximately log(n) steps if the map has n different strings. */
/* TODO: Compare/contrast vector<int> with map<int,int>. */
