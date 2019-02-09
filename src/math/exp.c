# define TGSOURCE "exp.c"
#include <math.h>
#include "nonstd/tgmath.h"
#include "errno.h"

/** exponential function **/
TYPE TGFN(exp)(TYPE x)
{
	int MAXLOOPS = 10;
	int i;
	int factorial = 1;
	TYPE exponent = 1.0;
	TYPE power = 1.0;

	if (0) {
		errno = ERANGE; /* The magnitude of ARGUMENT(x) is too large */
		/* RETURN_FAILURE(CONSTANT(HUGE_VAL), A range error occurred); */
		return TGHUGE;
	}

	/* TODO: tweak max loops */

	/* exp x = 1 + x + x^2/2! + x^3/3! + x^4/4! ... */
	for (i = 1; i < MAXLOOPS; i++) {
		power *= x;
		factorial *= i;
		exponent += power / factorial;
	}

	/* RETURN_SUCCESS(the exponential function of ARGUMENT(x)); */
	return exponent;
}

/***
compute the exponential function of ARGUMENT(x).
***/

/*
IMPLEMENTATION(The value returned on a domain error, CONSTANT(HUGE_VAL))
LINK(m)
*/
/*
STDC(1)
*/