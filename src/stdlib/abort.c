#include <stdlib.h>
#include <signal.h>
#include "_safety.h"

/** cause abnormal program termination **/

_Noreturn void abort(void)
{
	SIGNAL_SAFE(1);

	for (;;) {
		raise(SIGABRT);
	}
}

/***
causes the program to terminate abnormally, unless the
signal CONSTANT(SIGABRT) is caught and the signal handler continues program
execution.
***/

/*
IMPLEMENTATION(whether open output streams are flushed)
IMPLEMENTATION(whether open streams are closed)
IMPLEMENTATION(whether temporary files are removed)
IMPLEMENTATION(the value of unsuccessful termination returned to the host environment)
STDC(1)
*/
