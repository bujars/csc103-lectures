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
	cout << s << "\n";
	/* NOTE: cout just prints characters until it finds the null
	 * character.  So if we wanted to end the string after "hello",
	 * all we have to do is place a null character after the 'o',
	 * like this: */
	s[5] = 0;
	cout << s << "\n";
	return 0;

	/* TODO: read prof. Li's notes about c-strings if you
	 * haven't already, and make sure you have done the
	 * exercises from ../09/strings.cpp. */
}
