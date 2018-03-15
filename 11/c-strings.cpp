#include <iostream>
using std::cin;
using std::cout;

/* testing out c-style strings */
int main()
{
	/* c-strings are just arrays of characters with a null character
	 * at the end.  The "null character" is simply the char with
	 * (integer) value 0.  (See the file ../09/ascii-test.cpp) */
	char s[10] = "hello :D";
	/* NOTE: the c-string "hello :D" is actually 9 characters!
	 * TODO: change the length of s to 8, and try to compile
	 * this program.  The compiler will get mad. */
			//It tells you that the length isn't long enough to allocate all those charcters.
	cout << s << "\n";
	/* NOTE: cout just prints characters until it finds the null
	 * character.  So if we wanted to end the string after "hello",
	 * all we have to do is place a null character after the 'o',
	 * like this: */

	//Lets say we dont have length -- but note, this doesn't consider the \0. It doesn't have to when looking through the integers because thats a null char.
	char b[] = "bujar";
	int i = 0;

		/*char cc[3] = "ma";
		int h = 0;
		while(cc[h] != '\0'){
			cout << cc[h] << "\n";
			h++;
			cout << h;

		}*/
		//for(int i = 0; i < 5; i++){
			//cout << b[i] << "\n";
			//}
		while(b[i] != '\0'){ //aka, the end character representation
		i++;

	}
	cout << i << "\n";
	s[5] = 0;
	cout << s << "\n";

	char name[] = {'A', 'm', 'y', '\0'}; //A Cstring
	char name2[] = {'A', 'm', 'y'}; //Not a cstring
	cout << name;
	cout << "\n";
	cout << name2;
	cout 	<< "\n";
	return 0;

	/* TODO: read prof. Li's notes about c-strings if you
	 * haven't already, and make sure you have done the
	 * exercises from ../09/strings.cpp. */
	//Look at above where I'm trying to print name. What I don't understand is that in Li's notes, the same thing isn't printed for both name, name2. But in this example it is? Why is that? --3/12/18


	}
