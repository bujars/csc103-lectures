/* More about loops.
 * See lectures 4,5,6 from Prof. Li.,
 * and chapters 3,4 in the book. */

// the usual stuff:
#include <iostream>
using std::cin;
using std::cout;
using std::endl;
#include <cstdio>

int main()
{
	/* BIG PICTURE IDEAS WITH LOOPS.
	 * 1. "Brute force" -- leverage the speed of the computer to explicitly
	 *    run through an entire space of potential solutions, checking
	 *    each candidate for validity.  This is usually pretty trivial.
	 * 2. Maintaining invariants -- when computing some aggregate function
	 *    of a long list of inputs, initialize a variable to be something
	 *    like "the right answer so far" and then read new inputs one by
	 *    one, *updating your candidate answer* so that after each iteration
	 *    of the loop, it is ALWAYS the "right answer so far".
	 * NOTE: even brute force typically has an invariant hiding somewhere, but
	 * it usually isn't all that interesting.
	 * Let's see some examples: */

	/* exercise: compute the min of integers supplied via stdin. */
	#if 0
	int n; /* store input */
	int min; /* minimum of what we've seen *so far*. */
	cin >> n;
	min = n; /* NOTE: at this point, min's value is
				consistent with the meaning we gave it! */
	while (cin >> n) {
		if (n < min) min = n;
		/* NOTE: the *invariant* for this loop is that
		 * min is the smallest value we've read so far.
		 * Initialize min to have this property before the
		 * loop, and then at the end of each iteration, make
		 * sure this property remains true (that is to say,
		 * it's *invariant*!!).
		 * */
	}
	cout << min << "\n";
	return 0;
	#endif

	/* TODO: if you haven't already, be sure you can do this on your own,
	 * as well as similar things like the min, the sum, the product, the
	 * average...  Try to take the following very high level steps:
	 * 1. First, think about how many variables you will need, and for what
	 *    purposes.
	 * 2. Declare the variables, and in comments, state the meaning of each
	 *    variable.
	 * 3. Loop through the input and make sure the meaning of each of your
	 *    variables is preserved at the end of each iteration of the loop.
	 * 4. Finally, print the results.
	 * */

	/* NOTE NOTE NOTE 
	 * My attempt at calculating the Max. Refer to looseleaf notes. (Similar to what I have typed) --2/12/18
	 * 
	 * */
#if 0
	int n; //inputted value
	int max; //where max val will be stored
	cin >> n; //take first input.
	max = n; //Set max to first value
	while(cin >> n){ //As long as input occurs
		if(n > max) //Over new value is larger
			max = n; //Set new max value
	}
	cout << max << endl;
#endif

	/* NOTE NOTE NOTE 
	 * My attempt at calculating the sum. Refer to looseleaf notes. (Similar to what I've typed) --2/12/18
	 * */
#if 0
	int n; //used to store the current inputted value.
	int sum; //used for accumulating sum.
	cin >> n; //input value into n.
	sum = n; //store first sum to n.
	while(cin >> n){
		sum+= n; //Accumulate sum, ie, sum = sum+n;
	}
	cout << sum << endl;
#endif


	/* NOTE NOTE NOTE 
	 * My attemot at calculating the product. Refer to notes. (Similar to what I've typed) --2/12/18
	 * */
#if 0
	int n; //used to store current inputted value.
	int product; //used to store product
	cin >> n; //input first value into n
	product = n; //store first value in product.
	while(cin >> n){ //as long as values are entered
		product*=n; //make the product equal the current product times the new value
	}
	cout << product << endl;

#endif

	/* NOTE NOTE NOTE
	 *My attmept at calculating the average. Refer to notes. (Similar to what I've typed) --2/12/18
	 * */
#if 0
	int n; //where current input value lives
	double sum; //note this is a double because it will be divided at the end. 
	int count = 1; //this is to keep track of the number of values we've added used for division
	cin >> n; //take first input and store in n.
	sum = n; //store first input in sum. Note this still works as it converts the int to a double.
	while(cin >> n){
		sum+=n; //accumulate sum.
		++count; //accumulate the number of times values were added.
	}
	cout << (sum/count) << endl;
#endif

	/* exercise: brute force gcd.  Compute the greatest common
	 * divisor of n and k by an exhaustive search.  */
	/* IDEA: start with the largest possible value that the gcd
	 * could have, then walk *backwards* until you find the first
	 * value that divides both inputs. */
	/* Range of possibilities for a valid answer: {min{a,b}...1} */
	
	/* NOTE NOTE NOTE
	 * IDEA: This is my attmept to the above. 
	 * */
#if 0
	int n; //To store first inputted value
	int k; //To store second inputted value
	cin >> n; //input first value
	cin >> k; //input second value
	int gcd = 1; //Keep at one as there then isn't a divisor. 
	if(n ==k){ /* Check to see if these values are equal. */
		gcd = n; //or k it doesnt matter
	}
	else if(n < k){ /* Check to see if the smaller integer is n and set that to the gcd. */
		gcd = n;
	}
	else{ /* Check to see if the smaller integer is k and set that to the gcd. */
		gcd = k;
	}
	while((gcd != 0) && !(n%gcd == 0 && k%gcd == 0)) /* This makes sure that our greatest common factor is not 0 and isnt already a divisor. */
		--gcd; //This keeps lowering the value of the gcd until it finds it. 
	/*if(gcd == 1) // NOTE this was to say there is no divisor if one is the only divisor but technically, 1 is still a divisor between the two.  
		cout << "There is no gcd." << end; */
	cout << gcd << endl;
#endif

	/* TODO: brute force test for perfect cubes.  Check if
	 * n = k^3 for some integer k.  */
	/* NOTE NOTE NOTE
	 * Basically the thinking is, 
	 * given a value n and given a value k. 
	 * We then multiply k by itself 3 times, 
	 * and compare that value in n.
	 * */
#if 0 //Note this code works, but only works once. The main point is for it to loop. 
	int n, k;
	cin >> n >> k;
	if(n == (k*k*k))
		cout << "It's a perfect cube!" << endl;
	else
		cout << "Not a perfect cube." << endl; 
#endif


#if 0 /* NOTE NOTE NOTE that's my final answer. Check looseleaf for why I put this. */
	int n, k;
	while(cin >> n >> k){
		n = n;
		k = k;
		if(n == (k*k*k))
			cout << "It's a perfect cube!" << endl;
		else
			cout << "Not a perfect cube!" << endl;

	}
	cout << "End of program." << endl; 
#endif

	/* TODO: write a loop that prints the sum of the first n odd cubes. */
	
#if 0
	int n;
	int sum = 0;
	while(cin >> n){
		n = n;
		if(n % 2 != 0)
			sum+=n;
	}
	cout << sum << endl;
#endif


	/* TODO: write code that gets an integer n from the user and prints out
	 * the n-th term of the fibonacci sequence. */

	/* TODO: a slight generalization of an earlier exercise: for integers
	 * n and k, determine the largest power of k that divides n.
	 * NOTE: see if you can formalize the invariant you used to solve this.
	 * */

#if 0 /* NOTE NOTE NOTE : This isnt complete. Check notes on the thoughts I put around it, and maybe you can piece it together later on. */
	int n, k; //Two variables to store values of n and k;
	cin >> n >> k; //input n and k.
	int power = 0;
	while(((n%k) == 0) && (k!=1)){ //If you enter the value 1 for k, the code seems to break and go into some wierd loop where you can type just about anything. 
		++power;
		n = n / k; 
	}
	cout << power << endl; 
#endif


	/* TODO: write a program that reads (arbitrarily many) integers from
	 * stdin and outputs the *second* smallest one.  NOTE: you don't need
	 * to store many numbers (all at once, that is) to do this!  You'll
	 * only need a few integer variables.  Think about invariants! */
	
	/* 
	 * NOTE NOTE NOTE
	 * IDEA: The way I'm  approaching this is using 3 variables, one that will store the smallest, the other the second smallest, and the last thaat we will compare the both to, and replace the largest with such value. 
	 *
	 *
	 * */

	int s, n, l; //The variables where we will store our values. Designate: s for smallest, l for largest (second smallest), and n for the new value we keep checking
	cin >> s >> l; //input the valies
	if(s > l){ //Here, we exchange the two inputted values to make sure that s represents the current smallest, and l represetns the current largest. 
		n = l; 
		l = s;
		s = n;
	}
	while(cin >> n){ //as long as we input a value
		if(s < n && n < l){ //if the new value is greater than the smallest, and less than the current second smallest, make it the new second smallest
			l = n;
		}
		else if(n < s){ //if the new number is less than the smallest
			l = s; //make the largest(second smallest), the old smallest
			s = n; //make the smallest now equal to the new smallest value.
		}
	}
	cout << l << endl; //return the largest (second smallest)



	/* TODO: this is really basic, but good to be aware of: if you put
	 * the arrows going the wrong way, like "cin << x" or "cout >> x",
	 * you will get some very long, nasty, confusing error messages
	 * from the compiler.  Write code with this mistake on purpose, try to
	 * compile it, and take note of those error messages so you know where
	 * to look if you ever see errors like that again in the future. */
	
	/* NOTE NOTE NOTE 
	 * Basically what it does is tell you that that certain operation doesn't exist. It will pinpoint you exactly to where the mistake is, which is helpful.
	 * But note, its a long compiling error message tha tyou wont really forget. 
	 * I didn't take any more detailed notes besides the above...So realize that. 
	 *
	 * */	
	/*int randomInt = 0;
	cin << randomInt;
	cout >> randomInt; 
	*/
	
	
	return 0;
}

// vim:foldlevel=1
