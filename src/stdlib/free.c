#if 0

#include <stdlib.h>

/** deallocate memory **/

void free(void * ptr)
{
	if (ptr == NULL) {
		return;
	}

	realloc(ptr, 0);
}

/***
deallocates the memory at ARGUMENT(ptr). Specifying CONSTANT(NULL)
causes nothing to happen.
***/

/*
UNDEFINED(ARGUMENT(ptr) was not returned by a previous call to FUNCTION(calloc), FUNCTION(malloc), or FUNCTION(realloc))
STDC(1)
*/


#endif
