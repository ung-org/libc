#if 0

#include <sys/types.h>
#include <pwd.h>
#include <string.h>
#include "_pwd.h"

struct passwd * getpwnam(const char * name)
{
	struct passwd *pwd = NULL;
	setpwent();

	while ((pwd = getpwent()) != NULL) {
		if (strcmp(name, pwd->pw_name) == 0) {
			endpwent();
			return pwd;
		}
	}
	
	endpwent();
	return NULL;
}

/*
POSIX(1)
*/


#endif
