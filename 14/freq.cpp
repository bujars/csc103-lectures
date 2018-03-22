#include <iostream>
using std::cout;
using std::cin;
#include <string>
using std::string;
#include <map>  // also known as an "associative array"
using std::map; // you can think of maps kind of like arrays,
				// but the indexes no longer have to be integers...
				// e.g., we could do A["a string"] = 100;

/* print a frequency table of strings given on stdin */
int main()
{
	map<string,int> F; /* store frequency table */
	string s; /* hold an input */
	while (cin >> s) F[s]++;
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
	return 0;
}

/* TODO: re-write the above from scratch and make sure you understand
 * why it works. */

/* TODO: try to solve the same problem *WITHOUT* using maps!  Can you do
 * it with just vectors?  How about just sets?  */
/* TODO: if you managed to solve the above, estimate the number of
 * instructions your program will require to run on an input of n strings.
 * Then compare this with the solution using maps.  Note that M[s]++ takes
 * approximately log(n) steps if the map has n different strings. */
/* TODO: Compare/contrast vector<int> with map<int,int>. */
