#include <iostream> /* this helps us print things
                       to a terminal window. */
/* NOTE: iostream is just a file, and #include basically
 * copy + pastes it.
 * NOTE: between slash-* and *-slash are "comments" and
 * are ignored by the compiler. */

int main() /* this is where your program starts */
{
	/* we took std::cout from iostream. */
	std::cout << "hello world.\n"; /* print message to stdout */

	/* NOTE NOTE NOTE bujar's self trial */
	std::cout << "Bujar\n"; 
	std::cout << "Sefa\n";
	std::cout << "Basically trying to get the hang of cout\n";
	
	
	
	return 0;
	/* NOTE: this return value is how our program communicates
	 * back to the shell that started it.  In this context, 0 means
	 * the program "worked" (didn't encounter any errors). */
}

/* To run this on our computer, we have to first translate it into those tiny
 * instructions the cpu understands.  Do this with the help of g++:
 * $ g++ hello.cpp
 * Then run it with
 * $ ./a.out
 * */

/* TODO: follow the tutorial on "building on the command line" from our
 * homepage.  Then just spend some time experimenting and see what you
 * can learn.  */

/* TODO: take a look at what's really involved in running this
 * program (the tiny instructions I mentioned).  Try this:
 * $ gdb a.out
 * (gdb) break main
 * (gdb) tui enable
 * (gdb) layout asm
 * (gdb) run
 * (gdb) si
 * <then just keep hitting enter until you're bored...>
 * */

/* NOTE: a few takeaways from our first lecture:
 * 1. There is a huge gap in abstraction levels that must be bridged.
 * 2. The compiler is your friend, but you still need to give it a
 *    seemingly unnatural amount of detail...
 * */
