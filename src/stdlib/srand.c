#include "_stdlib.h"

/** seed the pseudo-random number generator **/

void srand(unsigned int seed)
{
	__stdlib.rand = seed;
}

/***
seeds the pseudo-random number generator with ARGUMENT(seed). The
sequence of pseudo-random numbers generated by a single seed is repeatable.
Program execution begins with a seed of 1.
***/

/*
STDC(1)
*/
