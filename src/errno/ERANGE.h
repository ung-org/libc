#define ERANGE                                                               (2)

/** out of range **/

/***
is used to indicated that the result of an operation is too large or too small.
***/

/*
STDC(1)
*/


#ifdef __linux__
#undef ERANGE
#define ERANGE 34
#endif
