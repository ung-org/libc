#if 0

#include <threads.h>
#include <pthread.h>

int cnd_signal(cnd_t *cond)
{
	return pthread_cond_signal(cond) == 0 ? thrd_success : thrd_error;
}

/*
STDC(201112)
*/


#endif
