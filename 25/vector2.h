/* home-brew vector from scratch (plain arrays). */
/* NOTE: here in the header file, we just describe
 * what things a vector can do, but nothing about *how*
 * it does it.  The reason for separating them is that
 * the implementation might change later on, and it would
 * be nice to not have to re-compile everything that
 * uses this.
 * The header file should contain the information that
 * another programmer would need to USE the vector class
 * we're making. */
#pragma once /* stops duplicate declarations of our vector (that is,
				stops it from being #included more than once). */

#include <stddef.h> /* for size_t */

class vector2 {
public:
	/* important stuff: *every* class that uses dynamic
	 * memory should implement the following: */
	/* (1) constructor and copy constructor. */
	vector2(size_t initCapacity = 16);
	vector2(const vector2& V); /* this is the copy constructor.
	    it will be called automatically when you pass vectors
		by value, as well as returning vectors by value, and
		possibly in other situations with intermediate rvalues. */
	/* NOTE: constructors (in general) put a newly created variable
	 * in a consistent state. */
	/* (2) Destructor. This is to free any dynamically allocated
	 * memory when the object goes out of scope or is destroyed. */
	~vector2();
	/* (3) assignment operator */
	vector2& operator=(vector2 V);
	/* NOTE: return type is vector2 so we can do stuff like a = b = c; */

	void push_back(int);
	void pop_back(); /* remove last element */
	int back(); /* return last element */
private:
	/* "under the hood" stuff.  can only be accessed
	 * by other member functions.  Prevents users of
	 * our vector class from putting the variables
	 * in an inconsistent state. */
	size_t size; /* number of elements in vector */
	size_t capacity; /* size of data array */
	int* data; /* dynamically allocated storage for elements */
	/* NOTE: capacity and data are *linked* in that capacity
	 * should always contain the number of elements that've been
	 * allocated for the data array.  They have to be kept
	 * in sync.  Hence we make these guys *private*.  Changing
	 * them independently could result in an inconsistent state
	 * for the vector. */
};
