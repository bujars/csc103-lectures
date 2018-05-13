/* implementation of home brew vector. */
#include "vector2.h"
#include <cassert>

/* give vector an initial capacity of initCapacity */
vector2::vector2(size_t initCapacity)
{
	this->size = 0;
	this->capacity = initCapacity;
	/* make sure invariant holds: */
	this->data = new int[this->capacity];
	/* NOTE: datatype of 'this' is vector2*
	 * */
}

/* destructor */
vector2::~vector2() {
	delete[] data;
	/* don't care about class invariant anymore, since *this
	 * is going out of scope / being deleted */
}

#if 0
/* examples of when destructor would be called */
// Ex1:
int f() {
	vector2 V;
	/* do stuff with V... */
} // <-- V goes out of scope and its destructor is called.

// Ex2: (a bit contrived)
vector2* p = new vector2;
/* do stuff with (*p)... */
delete p; /* destructor called for (*p) */
#endif

void vector2::push_back(int x)
{
	/* first, make sure we have enough capacity: */
	/* NOTE: this assumes that the capacity is never 0. */
	if (size == capacity) {
		/* need to expand the array: */
		capacity *= 2;
		int* larger = new int[capacity];
		for (size_t i = 0; i < size; i++)
			larger[i] = this->data[i];
		delete [] this->data;
		this->data = larger;
	}
	/* for a moment, pretend we have enough capacity: */
	this->data[size] = x;
	size++;
}

vector2::vector2(const vector2& V)
{
	/* IDEA: make *this a copy of V */
	/* give *this it's own array, and don't just
	 * copy the pointers. */
	this->size = V.size;
	this->capacity = this->size; /* kind of arbitrary... anything
	                                >= than size would work. */
	this->data = new int[this->capacity];
	for (size_t i=0; i<this->size; i++)
		this->data[i] = V.data[i];
}

/* assignment operator.  there's a neat trick you can do to re-use the
 * copy constructor to do most of the work.  TODO: see if you can
 * explain what is going on below / why it works.  We'll go through it
 * in detail next class. */
vector2& vector2::operator=(vector2 V) /* V set to a copy of RHS */
{
	int* tmp = this->data;
	this->data = V.data;
	V.data = tmp;
	this->size = V.size;
	this->capacity = V.capacity;
	return (*this);
} /* V goes out of scope and it's destructor will clean up
     the old this->data !!! :D */
/* regarding the return type:  it is so you can do this:
 * U = V = W    is the same as
 * U = (V = W)  which is like
 * U.operator=((V=W))
 * */

/* TODO: if you haven't already, re-write the assignment
 * operator using the following prototype: */
// vector2& operator=(const vector2& V);
/* the const by reference seems more plausible, but it will complicate
 * the implementation a good bit.  NOTE: you will have to modify the
 * header as well. */

/* remove last element */
void vector2::pop_back() {
	assert(size > 0);
	/* as long as vector isn't empty, just do this: */
	size--;
	/* TODO: try popping elements from an empty vector and see
	 * what happens.  Then try again after adding -DNDEBUG to the
	 * compiler flags (see the makefile). */
}

/* return last element */
int vector2::back() {
	assert(size > 0);
	return data[size-1];
}

size_t vector2::getsize() {
	return size;
}

int& vector2::operator[](size_t i) {
	assert(i < size);
	return data[i];
}

/* TODO: make your vector class more like the mathematical type
 * by adding a function for the inner product (dot product), and
 * the norm (the euclidean distance from the origin), as well as
 * operators for addition and scalar multiplication.
 * */
