#include<iostream>
using std::cin;
using std::cout;
using std::endl;
#include <cstdio>

/* Let's revisit our example from last class: */
void f(int n) {
	if (n == 0) {
		cout << 0 << "\n";
		return;
	}
	f(n-1);
	cout << n << "\n";
	//f(n-1); //The switch from below
	/* TODO: make sure you can trace the sequence of recursive calls that
	 * would result from calling say, f(3).  Flip the order of the cout
	 * statement and the recursive call, and make sure you understand
	 * the output in both cases. */

	/*Tested --> Prints 3 2 1 0. */
}

// TODO: write a recursive function that prints the base 10 digits of n
// vertically to cout.  for example, printVertically(2358) would print
// 2
// 3
// 5
// 8
// Rules: you can't use any loops.  You can't use vectors or arrays.
// Just let the recursive function calls do the work for you.
void printVertically(unsigned long n)
{
	// your code goes here.
	if(n < 10){
		cout << n << "\n";
		return;
	}
	printVertically(n/10);
	cout << (n%10) << "\n";
}

bool search(int* A, int size, int x)
{
	/* TODO: try to turn the following "plain-English" procedure into
	 * a recursive program:
	 * 1. if the array is empty (size < 1) return false.
	 * 2. if x is less than the value in the middle, recursively search
	 *    the left subarray, else recursively search the right subarray.
	 * Test out your program, and try to prove (by induction) that it works.
	 * (There are some subtle points about making sure the size is always
	 * decreasing...)
	 * */

	//[1, 2, 3, 4, 5, 6]

	if(size < 1)
		return false;
	if(A[size/2] == x)
		return true;
	else if(x > A[size/2])
		A = A + (size/2);
	size = size/2;
	return(A, size, x);
	//else if(x < V[])
	//int mid = size - *A
	/*A = A + 0;
	cout << A << endl;
	cout << *(A+1) << endl;*/




	/*int mid = (*A + size)/2;
	if(size < 1)
		return false;
	//cout << A[size/2 - 1] << endl;
	if(A[size/2-1] == x){
		//cout << A[size/2 - 1] << endl;
		return true;
		}
	else if(x > A[size/2-1]){
			//cout << x << endl;
			//cout << A[(size/2) - 1] << endl;
			//cout << *A << "A" << endl;
			A = A + (size)/2;
			//cout << size << "S" << endl;
			size = (mid + 1);
	}
		else{
			size = mid-1;
		}*/
  /* Maybe do some (A + A size)/2 or some shit and keep doing this?????.........
	else{
		size = size / 2;
		//cout << "AA" << endl;
		//A = 0;
	}
	return search(A, size, x);
	/*else if(x < A[size-1])
		size = size / 2;
	else
		size = size + (size/2);*/
	return search(A, size, x);
}

/* TODO: try to write down that recursive sorting algorithm we outlined
 * during class.  This might not be easy, but it's a good exercise.  To
 * help you get started, here are some plausible prototypes:
 * */

/* merge L and R (which are both sorted, and of sizes nL,nR respectively)
 * into the array S (which you can assume has enough space). */
void merge(int* L, size_t nL, int* R, size_t nR, int* S)
{
	int iL = 0, iR = 0, iS = 0;
	while(iL < nL && iR < nR){
		if(L[iL] < R[iR]){
			S[iS++] = L[iL++];
		}
		else{
			S[iS++] = R[iR++];
		}
	}
	while(iL < nL) S[iS++] = L[iL++];
	while(iR < nR) S[iS++] = R[iR++];
	iR = 0, iL = 0, iS = 0;
	while(iL < nL){
		L[iL++] = S[iS++];
	}
	while(iR < nR){
		R[iR++] = S[iS++];
	}
}

//#if 0
/* Sort the array A (of size n) using the array aux (which should
 * also have at least n elements) as auxillary storage for the
 * merge operations (see merge(...) above).  */
void mergeSort(int* A, size_t n, int* aux)
{
	/* IDEA: take care of a base case (like, say n < 2), and
	 * then break array in two equal(-ish) pieces and recursively
	 * sort both.  Then use the merge function to recombine them
	 * into a completely sorted array.  See example call from main().
	 * */
	if(n < 2)
		return;
	int* L = A;
	int* R = (A+(n/2)+1);
	mergeSort(L, n/2, aux);
	mergeSort(R, n/2, aux);
	
	
	merge(L, n/2, R, n/2, aux);
}
//#endif


int main()
{
	//f(3);
	//printVertically(2358);
	int B[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
	bool b = search(B, 6, 1);
	cout << b << endl;
	cout << search(B, 10, 2) << endl;
	cout << search(B, 10, 3) << endl;
	cout << search(B, 10, 4) << endl;
	cout << search(B, 10, 5) << endl;
	cout << search(B, 10, 6) << endl;
	cout << search(B, 10, 7) << endl;
	cout << search(B, 10, 8) << endl;
	cout << search(B, 10, 9) << endl;
	cout << search(B, 10, 10) << endl;


	/* how to call merge sort: */
	int A[10] = {33,2,19,6,7,3,22,71,18,49};
	int aux[10]; /* auxillary space for merging. */
	int C[10];
		for (size_t i = 0; i < 10; i++) {
					printf("A[%lu] = %i\n",i,A[i]);
						}
	//merge(A, 5, (A+5), 5, C);
	mergeSort(A,10,aux);
	for (size_t i = 0; i < 10; i++) {
		printf("A[%lu] = %i\n",i,A[i]);
	}
	return 0;
}
