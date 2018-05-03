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

/* TODO: erase the push_back implementation and write it from scratch */
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
	/* Goal: make *this a copy of V. */
	/* here's the default copy constructor: */
	this->size = V.size;
	this->capacity = V.capacity;
	this->data = V.data;
	/* it will end in disaster!  TODO: make sure you understand why.
	 * Imagine what will happen if a vector were passed *by value* to a
	 * function.  Draw pictures, and keep in mind what the destructor does.
	 * */
	/* TODO: write a proper copy constructor that allocates a new array. */
}

/* assignment operator.  there's a neat trick you can do to re-use the
 * copy constructor to do most of the work.  TODO: see if you can
 * explain what is going on below / why it works.  We'll go through it
 * in detail next class. */
vector2& vector2::operator=(vector2 V)
{
	int* tmp = data;
	data = V.data;
	V.data = tmp;
	size = V.size;
	capacity = V.capacity;
	return (*this);
}

/* TODO: re-write the assignment operator using the following prototype: */
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
	 * what happens. */
}

/* return last element */
int vector2::back() {
	assert(size > 0);
	return data[size-1];
}
