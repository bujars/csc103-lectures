#include <iostream>
using std::cout;

/* TODO: predict the output of this program *without* running it!
 * Then compile and run it to check your answers and make sure you
 * understand what is going on if any of your guesses were wrong. */

int fn1(int& a, int b, int& c)
{
    cout << "a" << a << "\n";
    cout << "b" << b << "\n";
    a = b++;//Here we have a = (b) + 1 ;
    cout << "a" << a << "\n";
    cout << "b" << b << "\n";
    //x =  (5) + 1; so a is 1, and b becomes 6
    b += 10;
    cout << "b" << b << "\n";
    //6+10 = 16
    cout << "c" << c << "\n";
    c = ++a;
    cout << "a" << a << "\n";
    cout << "c" << c << "\n";
    //a, which is 5, one gets added, to 6, then c becomes 6
    return b;
}
    //note b doesnt change in this scope

int main()
{
    int x=3, y=5, z=13;
    cout << x << " " << y << " " << z << "\n"; //3 5 13
    int r = fn1(x,y,z);
    cout << x << " " << y << " " << z << "\n"; //5 16 6
	  cout << r << "\n"; //value of b, 6

    //cout << (x = y++) << "\n";
    //x = 3;
   // cout << (x = ++y) << "\n";



    return 0;
}
