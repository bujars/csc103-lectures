#include <iostream>
using std::cout;

size_t f(size_t m, size_t n)
{
	if (m == 0) return n+1;
	if (n == 0) return f(m-1,1);
	return f(m-1,f(m,n-1));
}

int main()
{
	cout << f(3,2) << "\n";
	/* NOTE: increasing the 3 to a 4 will make this
	 * run a long time and produce a value that doesn't
	 * fit in a size_t! */
	return 0;
}
