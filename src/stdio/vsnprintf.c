#if 0

#include <stdio.h>
#include <stdarg.h>
#include "_stdio.h"

int vsnprintf(char * restrict s, size_t n, const char *format, va_list arg)
{
	struct io_options opt = {
		.fnname = __func__,
		.string = s,
		.maxlen = n,
	};

	return __printf(&opt, format, arg);
}

/*
STDC(199901)
*/


#endif
