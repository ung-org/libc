#include <stdio.h>
#include <wchar.h>

int vfwprintf_s(FILE * restrict stream, const wchar_t * restrict format, va_list arg)
{
	struct io_options opt = {
		.fnname = __func__,
		.stream = stream,
	};
	return __printf(&opt, format, arg);
}

/*
CEXT1(201112)
*/
