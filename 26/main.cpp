#include "vector2.h"
#include <iostream>
using std::cout;
using std::endl;

#define such cout
#define wow endl

/* some approximation of assert: */
// #ifndef NDEBUG
// if (!boolean) exit(1);
// #endif

int main()
{
	vector2 V;
	for (size_t i = 0; i < 10; i++) {
		V.push_back(i*i);
	}
	such << V[5] << wow;
	V[12] = 99999;
	for (size_t i = 0; i < V.getsize(); i++)
		printf("V[%lu] = %i\n",i,V[i]);
}
