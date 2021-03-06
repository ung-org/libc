#include <limits.h>
#ifdef __CHAR_IS_UNSIGNED__
#define CHAR_MIN                                                             (0)
#else
#define CHAR_MIN                                                          (-128)
#endif

/** char minimum **/

/***
is the minimum value representable as a TYPE(char).
***/

/*
VALUE_SELECT(LITERAL(0), on systems where TYPE(char) is default TYPE(unsigned))
VALUE_SELECT(CONSTANT(SCHAR_MIN), on systems where TYPE(char) is default TYPE(signed))
*/
/*
STDC(1)
*/
