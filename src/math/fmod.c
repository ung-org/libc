# define TGSOURCE "fmod.c"
#include <math.h>
#include "nonstd/tgmath.h"
#include "errno.h"

/** floating-point remainder **/
TYPE TGFN(fmod)(TYPE x, TYPE y)
{
	if (y == 0) {
		return 0;
	}

	if (0) {
		errno = ERANGE; /* The result cannot be represented */
		/* RETURN_FAILURE(CONSTANT(HUGE_VAL), A range error occurred); */
		return TGHUGE;
	}

	/* RETURN_SUCCESS(ARGUMENT(x) - VAR(i) * ARGUMENT(y)); */
	return x - x / y;
}

/***
compute the floating-point remainder of ARGUMENT(x)/ARGUMENT(y).
FIXME: I am not sure I understand this.
***/

/*
IMPLEMENTATION(The value returned on a domain error, CONSTANT(HUGE_VAL))
IMPLEMENTATION(Whether ARGUMENT(y) being LITERAL(0) results in a domain error or THIS() returning LITERAL(0))
LINK(m)
*/
/*
STDC(1)
*/