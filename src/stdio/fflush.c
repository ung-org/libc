#include <stdio.h>
#include "_stdio.h"

#ifdef _POSIX_SOURCE
#include <sys/types.h>
#include <unistd.h>
#else
#include "_syscall.h"
#define write(_fd, _buf, _size) __syscall(__syscall_lookup(write), _fd, _buf, _size)
#endif

/** flush buffered writes **/

int fflush(FILE *stream)
{
	int ret = 0;

	if (stream == NULL) {
		size_t i;
		for (i = 0; i < FOPEN_MAX; i++) {
			fflush(&(__stdio.FILES[i]));
		}
		return 0;
	}

	flockfile(stream);
	if (write(stream->fd, stream->buf, stream->bpos) == -1) {
		/* errno is set */
		ret = EOF;
		stream->err = 1;
	} else {
		stream->bpos = 0;
	}
	funlockfile(stream);

	/*
	RETURN_SUCCESS(0);
	RETURN_FAILURE(CONSTANT(EOF));
	*/

	return ret;
}

/***
function flushes any buffered write operations on ARGUMENT(stream) to
the underlying file.

If ARGUMENT(stream) is CONSTANT(NULL), THIS() will flush all open streams.
***/

/*
UNDEFINED(ARGUMENT(stream) is not an output stream)
UNDEFINED(ARGUMENT(stream) is an update stream in which the most recent operation was input)
*/
/*
STDC(1)
*/
