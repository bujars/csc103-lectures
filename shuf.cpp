#include <cstdio>   /* printf*/
#include <cstdlib>  /* rand*/
#include <time.h>   /* time*/
#include <getopt.h> /* to parse long arguments.*/
#include <stdlib.h>
#include <string>
using std::string;
#include <vector>
using std::vector;
#include <iostream>
using std::cin;
using std::cout;
#include <algorithm>
using std::swap;
using std::min;

static const char* usage =
"Usage: %s [OPTIONS]...\n"
"Limited clone of shuf.  Supported options:\n\n"
"   -e,--echo              treat each argument as an input line.\n"
"   -i,--input-range=LO-HI treat each number in [LO..HI] as an input line.\n"
"   -n,--head-count=N      output at most N lines.\n"
"   --help                 show this message and exit.\n";

void randPermString(vector<string>& v);
void randPermInt(vector<int>& v);

int main(int argc, char *argv[]) {
	/* define long options */
	static int echo=0, rlow=0, rhigh=0;
	static size_t count=-1;
	bool userange = false;
	static struct option long_opts[] = {
		{"echo",        no_argument,       0, 'e'},
		{"input-range", required_argument, 0, 'i'},
		{"head-count",  required_argument, 0, 'n'},
		{"help",        no_argument,       0, 'h'},
		{0,0,0,0}
	};
	/* process options:                   */
	char c;
	int opt_index = 0;
	/* NOTE: It is here that the options get saved by the command line 
	 * in which I can then use the variable above to filter the input/output */
	while ((c = getopt_long(argc, argv, "ei:n:h", long_opts, &opt_index)) != -1) {
		switch (c) {
			case 'e':
				echo = 1;
				break;
			case 'i':
				if (sscanf(optarg,"%i-%i",&rlow,&rhigh) != 2) {
					fprintf(stderr, "Format for --input-range is N-M\n");
					rlow=0; rhigh=-1;
				} else {
					userange = true;
				}
				break;
			case 'n':
				count = atol(optarg);
				break;
			case 'h':
				printf(usage,argv[0]);
				return 0;
			case '?':
				printf(usage,argv[0]);
				return 1;
		}
	}
	/* NOTE: the system's shuf does not read stdin *and* use -i or -e.
	 * Even -i and -e are mutally exclusive... */

	/* TODO: write me... */
	
	/* NOTE:s 
	 * Okay, on 4/3  I was confused about how the -i would work since its only integer inputs,
	 * whereas -e is any form of input. 
	 * From what I believe, I think the computer itself realizes that -e, -i is entered in the beginning, and 
	 * the variables are set to either true or false.
	 * This would then help because we can check which case is true and how to read in the input/output
	 * and how to send it out.
	 *
	 * So skeiths response to my confusion on -i:
	 * The -i excludes supplying other input. I already parsed out the range for you in the skeleton.
	 * If you see 'userange' set to true, you just print some permutation of low/high and exit.
	 * You can have a speical case, or you can fill a vector with the numbers written as strings
	 * see snprintf. It should be very simple. 
	 * 
	 * */


	/* Method 1 -- Try with the special cases as that will lead 
	 * to less problems in the future,
	 * or so I beleive.
	 *
	 * UPDATE:
	 * getting a bad alloc problem which has to do with short or over memory fill
	 * that can be from dumblicated methods and such, so i think i might 
	 * do the vector to int conversion?....
	 * 
	 *
	 * UPDATE 2:
	 * The memory allocation problem I believe was from my 
	 * original while loop ofr -i set as while(rlow < rhigh)
	 * the problem was I never had those variables change so
	 * it was constantly just adding into a vector.
	 * My switch was to use temporary variabes as 
	 * I dont want to change those in case I need them again.
	 *
	 *
	 * */
	
	vector<string> s; /*vector for everthing not -i */
	vector<int> I; /* vector of ints for -i*/
	string n;
	if(echo){
		while(optind < argc){
			s.push_back(argv[optind++]);
		}
		/*randPermString(s);
		for(size_t i = 0; i < s.size(); i++){
			cout << s[i] << "\n";
		}*/
	}
	else if(userange){
		int adder = rlow;
		int end = rhigh;
		while(adder <= end){
			I.push_back(adder++); 	
		}
	}
	else{
		while(getline(cin, n)){
			s.push_back(n);
		}
	}
	randPermString(s);
	randPermInt(I);
	int nC = count;
	if(nC > 0){
		if(userange){
			for(size_t i = 0; i < nC; i++)
				cout << I[i] << "\n";
		}
		else{
			for(size_t i = 0; i < nC; i++)
				cout << s[i] << "\n";
		}
	}
	else if(userange){
		for(size_t j = 0; j < I.size(); j++){
			cout << I[j] << "\n";
		}
	}
	else{
		for(size_t i = 0; i < s.size(); i++){
			cout << s[i] << "\n";
		}
	}
					
	return 0;
}



void randPermString(vector<string>& v){
	srand(time(0));	
	for(int i = v.size()-1; i > 0; --i){
		int random = rand();
		int randPos = random % (i+1); 
		string temp = v[randPos];
		v[randPos] = v[i];
		v[i] = temp;													
	}
}

void randPermInt(vector<int>& v){
	srand(time(0));	
	for(int i = v.size()-1; i > 0; --i){
		int random = rand();
		int randPos = random % (i+1); 
		int temp = v[randPos];
		v[randPos] = v[i];
		v[i] = temp;													
	}
}
