#if 0

#include <threads.h>
#include <pthread.h>

int tss_set(tss_t key, void *val)
{
	return pthread_setspecific(key, val) == 0 ? thrd_success : thrd_error;
}

/*
STDC(201112)
*/


#endif
