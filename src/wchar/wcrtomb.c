#include <wchar.h>
#include "limits.h"

size_t wcrtomb(char * restrict s, wchar_t wc, mbstate_t * restrict ps)
{
	char buf[MB_LEN_MAX+1];
	if (s == NULL) {
		s = buf;
		wc = L'\0';
	}
	(void)wc; (void)ps;

	/* do stuff */
	return 0;
}

/*
STDC(199409)
*/
