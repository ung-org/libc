#include <threads.h>
#include <pthread.h>

int cnd_broadcast(cnd_t *cond)
{
	return pthread_cond_broadcast(cond);
}
