/* strings.cpp
 * More examples working with strings...
 * */
#include <iostream>
using std::cin;
using std::cout; 
using std::endl;
#include <string>
using std::string;

const string teststring = "lolololol";

/* TODO:  write a function that takes a string and a character
 * and returns the number of occurences of the character in the string.
 * */
size_t countChars(const string& s, char c)
{
	/* TODO: remove the const modifier and try to run this function
	 * on teststring above.  Take note of the compiler error in case
	 * you see it again later (the message from g++ might not be all
	 * that easy to read/understand). */
	return 0;
}

/* TODO: write the following function which converts all lower
 * case letters to upper case.  NOTE: there are library functions
 * that will convert a single character (see 'man 3 toupper'),
 * but it might be more instructive to do it without using those.
 * If doing it without the help of toupper, note that the offset
 * between lower/upper cases is simply 'A' - 'a' (remember, this
 * is a number...).  See the ascii-test.cpp as well.
 * */
void YELL(string& s) {
	/* make all lower case chars upper case. */
}

/* TODO: write a function that takes a string and returns a boolean
 * indicating whether or not it was a palindrome.
 * */

/* TODO: write a function that takes a string by reference and reverses it.
 * */

/* TODO: write a function that takes two strings and returns an integer value
 * indicating whether or not the first was a substring of the second.  Remember
 * that the return value should be the index at which the string was found, or
 * -1 to indicate that the string was not found.  NOTE: this might be a little
 * tough.  Maybe do it last.
 * */
int isSubstring(const string& s1, const string& s2) {
	return -1;
}

/* NOTE: there is a built-in string function for this (find(str,pos)).
 * TODO: try it out (but don't use it to solve the above, of course!).
 * */

int main() {
	/* TODO: write test code for all of the functions you wrote above */
	return 0;
}
