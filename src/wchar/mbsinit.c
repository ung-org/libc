#if 0

#include <wchar.h>

int mbsinit(const mbstate_t * ps)
{
	if (ps == NULL || *ps == 0) {
		return 1;
	}

	return 0;
}

/*
STDC(199409)
*/


#endif
