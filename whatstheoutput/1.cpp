#include <iostream>
using std::cout;
using std::endl;

/* TODO: predict the output of this program *without* running it!
 * Then compile and run it to check your answers and make sure you
 * understand what is going on if any of your guesses were wrong. */

int main() {
    int x = 10, y = 3; //Stores 10 in x and 3 in y
    double d = 4, e = 2; //stores 4 in d and 2 in e -- note its a double
    cout << --x << endl; //x = x-1 ==> 10 = 10-1= 9
    cout << x-- << endl;  // print 9, then change x to 8.
    cout << y/x << endl; // y/x = 3/8 = 0.375 ==> 0 (int not double)
    y = e; //y becomes the value of e, so 2
    cout << y/x << endl; //2/8 ==> 0 (again this is a int)
    cout << x%y << endl;  //8/2 ==4, no remainder thus ==> 0
    cout << (x-d)/y << endl; // (8-4.0)/2 ==> 4/2 ==> 2
    return 0;
}


/* In order of what gets printed.
 * 9
 * 8
 * 0
 * 0
 * 0
 * 2
 * NOTE these are my assumtions.   -- After compiling its all correct.
 */