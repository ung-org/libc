#include <stdarg.h>

/** copy a va_list **/

#define va_copy(__dest, __src)                  __builtin_va_copy(__dest, __src)

/***
copies the TYPE(va_list) ARGUMENT(src) to ARGUMENT(dest), including the current
state of the list.
***/

/*
PROTOTYPE(void va_copy(va_list dest, va_list src);)

STDC(199901)
*/
