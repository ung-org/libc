#include "sys/types.h"
#include <sys/stat.h>
#include "../../_syscall.h"

int mkdir(const char *path, mode_t mode)
{
	(void)path; (void)mode;
	return -1;
}

/*
POSIX(1)
*/
