# define TGSOURCE "cosh.c"
#include <math.h>
#include "nonstd/tgmath.h"
#include "errno.h"

/** hyperbolic cosine **/
TYPE TGFN(cosh)(TYPE x)
{
	if (0) {
		errno = ERANGE; /* The magnitude of ARGUMENT(x) is too large */
		/* RETURN_FAILURE(CONSTANT(HUGE_VAL), A range error occurred); */
		return TGHUGE;
	}

	/* RETURN_SUCCESS(the hyperbolic cosine of ARGUMENT(x)); */
	return x;
}

/***
compute the hyperbolic cosine of ARGUMENT(x).
***/

/*
IMPLEMENTATION(The value returned on a domain error, CONSTANT(HUGE_VAL))
LINK(m)
*/
/*
STDC(1)
*/