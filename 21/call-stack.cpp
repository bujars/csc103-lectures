#include <cstdio>
#include <string.h> /* for strcmp */

void pwdcheck();

int main()
{
	printf("Checking password...\n");
	pwdcheck();
	return 0;
}

/* to illustrate the potential badness of static arrays: */
void pwdcheck() {
	int authenticated = 0;
	char pwd[10];
	/* read password from standard input into the array */
	printf("enter password: ");
	scanf("%s",pwd); /* the C version of cin >> pwd. */
	if (strcmp(pwd,"lololol") == 0) {
		authenticated = 1;
	} // else if (...) { maybe check other passwords... }
	/* Ok, now see if the flag was set: */
	if (authenticated) {
		printf("Authenticated!\n");
		/* and maybe allow access to some resource... */
	} else {
		printf("Wrong password, sorry!\n");
	}
}

/* TODO: play with this example, and make sure you understand what is
 * happening.  Entering a longer password than what fits in the pwd buffer will
 * eventually overwrite the authenticated flag.  Refer back to the call stack
 * diagrams from lecture to figure it out.
 * NOTE: compile this with the makefile!  Else the optimizer will mangle your
 * code sufficiently that the example won't work as you expect.
 * NOTE: if you write too far of the end, you will overwrite the return
 * address, and the program will crash, likely with a seg fault.
 * NOTE: the ability to overwrite the return address has been (ab)used to great
 * effect in the past.  The idea is to use as your password a string containing
 * *machine code* for some (probably malicious!) program.  By carefully setting
 * the return address (lots of other trickery is also needed...), you can
 * convince the pwdcheck function to execute it!  You can also try to set the
 * return address to a library function, maybe to start a shell (this is called
 * the "return to libc" attack).
 * NOTE: as of 2017, the approach I mentioned above is not particularly viable,
 * but far more dangerous things (imho) have evolved in response.  See for
 * example this: https://en.wikipedia.org/wiki/Return-oriented_programming
 * */

/* TODO: read this:
 * HOW TO AVOID SUCH SECURITY ISSUES
 * 
 * Usually, these stem from using C string manipulation routines like `strcpy`
 * on fixed length buffers allocated on the runtime stack.  In general, you
 * should *never* do this.  Also, you should always prefer functions like
 * `strncpy` which accept a parameter for the length of the buffer, and won't
 * copy more characters than would fit (as long as you supply the right
 * length!).  See `man strcpy` for more, and always pay attention to your
 * compiler warnings (and enable them with -Wall).
 * Lastly, if using gcc, there is a compiler flag -fstack-protector that works
 * well at defending against overflow on the stack.  Try it out!  In recent
 * gcc versions it is enabled by default, so all you have to do is open the
 * Makefile and comment out the flag disabling it (-fno-stack-protector).  If
 * the protection mechanism is triggered, you'll see a message about "stack
 * smashing detected" when the program crashes.  To read more about how it
 * works, run `info gcc` and search for it, or search for "stack canaries"
 * using your favorite search engine.
 * */

/* TODO: (only if you are feeling REALLY adventurous...) generate the assembly
 * file for your program using
 * $ make call-stack.s
 * (I left a makefile target there for it) and see if you can't teach yourself
 * a bit of assembly!  Much googling will probably be involved, but I think if
 * you're motivated, you'll be able to more or less decipher the relevant
 * pieces.  You can also try comparing the assembly code that has the stack
 * canary and the one that doesn't, but it takes a bit of work to understand
 * what is going on...
 * */
