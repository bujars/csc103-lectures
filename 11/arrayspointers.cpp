/* arrays and pointers. */
#include <iostream>
using std::cin;
using std::cout;
using std::endl;

int main() {
	/* ARRAYS: OVERVIEW
	 * Arrays in C/C++: kind of like a "dumb" version of std::vector.
	 * It has no concept of its size.  It has no fancy member functions
	 * like push_back, etc... */

	/* DECLARATION AND USE */
	const size_t size = 10;
	int A[size]; /* A is an array of 10 integers. */
	for (size_t i = 0; i < size; i++) {
		/* store list of cubes in the array: */
		A[i] = i*i*i; /* use the bracket operator to
		                  access elements, just like vectors */
	}

	/* WHAT'S *REALLY* IN AN ARRAY? */
	cout << "A == " << A << endl;
	/* A only contains a memory address!  This is the address
	 * of the first element A[0]
	 * NOTE: in reality, for static arrays there is no A, but for
	 * most intents and purposes you can think of every array as
	 * simply a pointer to its first element. */

	/* POINTERS: OVERVIEW
	 * They are just *variables that hold a memory address*.
	 * That's it!  Very simple!  E.g., our array A is a pointer.
	 * */

	/* POINTERS: MECHANICS
	 * What kinds of things might we want to do with pointers?
	 * Well the obvious ones are:
	 * 1.  declare them
	 * 2.  initialize them
	 * 3.  read to and write from the memory cell to which the pointer
	 *     points.
	 * */

	/* 1. declarations */
	int* p; /* declare a pointer.  Note the '*'.  Also acceptable
	           (and instructive) is to declare it as int *p;  In either
			   case, *p is of type int, and p is the address of that int. */
	#if 0
	/* NOTE: you could initialize the pointer by directly writing an address
	 * like this: */
	p = (int*) 4;
	/* and then try to write to that memory cell, like this: */
	*p = 17;
	/* TODO: change the above "#if 0" to "#if 1", compile, run, and take
	 * note of the error.  Sadly, it won't be the last time you see it... */
	#endif

	/* 2. initialization via "address-of"
	 * Much more useful than just writng a literal address, is storing the
	 * address of an existing variable.  This is done via the "address-of"
	 * operator, like so: */
	int x = 17;
	p = &x; /* read: "p gets the address of x." */
	/* NOTE: at this point, x and *p are synonyms.  Whatever happens to one
	 * will happen to the other: */
	cout << "p == " << p << "\tx == " << x << endl;

	/* 3. read/write using "dereference operator" */

	cout << "this is what's at the address stored in p: " << *p  << endl;
	(*p)++; /* NOTE: parens are actually important. */
	cout << "p == " << p << "\tx == " << x << endl;

	/* TODO: think carefully (and draw pictures!), and see if you can predict
	 * the output of the following code before you run it: */
	int y = 23;
	int* q = &y;
	cout << "p == " << p << "\tx == " << x << endl;
	cout << "q == " << q << "\ty == " << y << endl;
	cout << "::: setting p = q;\n";
	p = q;
	(*q)++;
	cout << "p == " << p << "\tx == " << x << endl;
	cout << "q == " << q << "\ty == " << y << endl;

	/* Back to arrays for a moment:  what does the bracket notation (A[i])
	 * actually mean?  It is simply an addition of pointers, followed by
	 * a dereference: A[i] is the same as *(A+i) as it turns out.  There are
	 * even funny consequences of this -- instead of A[i], you can instead
	 * write i[A] (but I don't recommend it!) */
	char B[10];
	for (size_t i = 0; i < 10; i++) {
		B[i] = 'a' + i;
	}
	for (size_t i = 0; i < 10; i++) {
		/* B[i] == *(B+i) == *(i+B) ==? i[B] */
		cout << i << "[B] == " << i[B] << endl;
	}

	return 0;
	/* TODO: declare another pointer (say p2) to a character, initialize it
	 * just as we did before, and print out (p+i) and then (p2+i) for small
	 * values of i. Notice that the difference in memory addresses changes. */
}

/* TODO: write a function that returns void, and takes two
 * POINTERS to integers, and swaps the contents of those two
 * memory locations.  Note: part of this exercise is understanding
 * what I'm asking for...
 * */

/* TODO: if the type of p is int*, can you guess what the
 * type of &p would be? */

void shift(int* A /* the array */,
		size_t len /* #elements of A */,
		size_t n /* shift amount */);
/* TODO: write a function that performs a "circular shift" on
 * an array of integers.  For example, if the input array
 * contained 0,1,2,3,4 and we shifted by 2, the new array would
 * contain 3,4,0,1,2.
 * NOTE: you can do this with a CONSTANT AMOUNT OF ADDITIONAL STORAGE.
 * That is, irrespective of the size of the array, your function should
 * allocate the same, fixed amount of storage.  No vectors.  No additional
 * arrays.  Just a few integers.  Try it!  (Kind of hard though.)
 * Moreover, do this without repeatedly shifting the array which will
 * take n*len steps.  You should be able to do this in c*len steps
 * for some small constant c, not depending on len.
 * */
