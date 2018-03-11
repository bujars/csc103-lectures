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

	size_t count = 0; //Look at return type
	for(size_t i = 0; i < s.length(); i++){ /*Want to start at 0 and go through the whole length*/
    	if(s[i] == c){ /*If that specific character in the string is equal to the char */
     		count++; /*then add it to the total of count (ie the number of apperances found)*/
     }
   }
   return count;
 // return 0;
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
   for(size_t i = 0; i < s.length(); i++){
    int j = (int)s[i];
    char c = (char)(j - 32);
    s[i] = c;
    }
 }

/* TODO: write a function that takes a string and returns a boolean
 * indicating whether or not it was a palindrome.
 * */

 /* NOTE NOTE NOET : There are two ways I see this being  handled
  * 1. Reverse the string and check if its equal to original
  * 2. Check the first and last letter and keep moving as long its
  *    is equal. (Since our reverse method doesn't return we will
  *    the second method.)
  */


 bool isPalindrome(const string& s){
  bool tF = true;
  for(size_t i = 0; i < s.length()/2; i++){
   if(s[i] != s[s.length()-1 - i]){
     tF = false;
     break;
   }
   }
   return tF;
  }

/* TODO: write a function that takes a string by reference and reverses it.
 * */
void reverseString(string& s){
	//Want to go through half of the string, and swap it with the other half
 	//If you go through the full string you are basically re-reversing everything
  	//NOTE ---- forgot thought...
  	for(int i = 0; i < s.length()/2; i++){
    	 char temp = s[i]; //notice how we use a char instead of a string. This is because in terms of space and stuff a char is better to be used.
    	s[i] = s[s.length()-1-i]; //Noitce how we are going back by i, ie the reverse position from the end. Also notice the -1 because we are in terms of indexes not size.
   		s[s.length()-1-i] = temp; //we used a temp in order to not lose one of the values.
  }
}

/* TODO: write a function that takes two strings and returns an integer value
 * indicating whether or not the first was a substring of the second.  Remember
 * that the return value should be the index at which the string was found, or
 * -1 to indicate that the string was not found.  NOTE: this might be a little
 * tough.  Maybe do it last.
 * */
int isSubstring(const string& s1, const string& s2) {
	int index = -1; //Start with -1 as it is not found
	bool b = false;
 if(s2.length() > s1.length())
    	return index; //Stop program right away else error
	else{
   	/* Im going to loop throguth each first value, until the first value is found,
	 * then im going to check the remaining values and keep starting over until we
	 * found all values -- note for later we mght need to watch out that we aren't
	 * going out of the bounds when looking for other charcters, that is if the
	 * first character of s2 is in the last position  --- so maybe we need to keep
	 * decreasing the length of conditional?? and keep saying if the s2 is less
	 * than that length -- so use a while loop??*/
   //int s1Len = s1.len(); //Not needed
  	 for(int i = 0; i < s1.length(); i++){
		if(s1[i] == s2[i]){
    		 for(int j = i+1; j < s1.length(); j++){
				 /* start from position i+1 to keep checking the rest of
				  * the characters*/
       			if(!(s1[j] == s2[j]))
        			 b = false;
      			else
         			b = true;
			 }
    		if(b == true)
       			index = i;
     		}
   		}
	}

  return index;
}

/* NOTE: there is a built-in string function for this (find(str,pos)).
 * TODO: try it out (but don't use it to solve the above, of course!).
 * */

int main() {
	/* TODO: write test code for all of the functions you wrote above */
  size_t cCount = countChars(teststring, 'l');
  cout << cCount << "\n";
   string s = teststring;
  YELL(s);
  for(size_t i = 0; i < s.length(); i++){
   cout << s[i];
   }
   cout << "\n";
   string b = "bujar";
   reverseString(b);
   for(size_t i = 0; i < b.length(); i++){
   cout << b[i];
   }
   cout << "\n";
   string pal = "madem";
   bool tF = isPalindrome(pal);
   cout << tF << "\n";
	return 0;
}
