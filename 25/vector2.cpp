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
/* NOTE: This was my incorrect version. 
 * Was missing some aspects. 
 * Also note that I didn't take into consideration if size is less that zero or anything. 
 * I also only added one to the cacpatiy which isn't efficent -- refer to skeiths notes from the lesson. 
 * I also assumed that capcity and size are equal vales;
 *
 * Vector2 (should be int* because we are inside a Vector2 and one is just a pointer) ret = new int[this->capacity+1];
 * for(int i = 0; i < this->size; i++){
 *   	ret[i] = this->data[i];
 *  }
 * 	ret[this->size] = x;
 * 	this->capacity = this->capacity + 1; //should be capacity*2 //as its the most efficent way to incorperate more space.
 * 	this->size = this->capacity; //note this is not good if capactiy is far greater 
 *  //than one of size before setting it because it would then fill the vector with random things.
 *  delete[] this->data;
 *  this->data = ret; 
 * 
 */

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
vector2& vector2::operator=(vector2 V)
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

/* TODO: make sure you can explain why you need a copy constructor
 * and assignment operator when writing classes with dynamic memory.
 * You should be able to give explicit examples of how not writing
 * your own versions would cause trouble.
 * */
