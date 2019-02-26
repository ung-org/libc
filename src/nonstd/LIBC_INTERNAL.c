#include <nonstd/internal.h>

typedef enum {
	ERRNO,
	THREAD_LOCALE,
	GLOBAL_LOCALE,
	SYSCALL_LOOKUP,
	PRINTF,
	SCANF,
	FOPEN,
	CTYPE,
	TOLOWER,
	TOUPPER,
	FILE_TAIL,
	ATEXIT,
	RAND
} LIBC_INTERNAL;
