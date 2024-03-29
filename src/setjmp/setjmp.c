#if 0

#include <setjmp.h>
#include <string.h>

/** save program state **/

int setjmp(jmp_buf env)
{
	extern int __setjmp(jmp_buf);
	memset(env, 0, sizeof(jmp_buf));
	return __setjmp(env);
}

/***
saves the current state of the calling environment
in the TYPEDEF(jmp_buf) ARGUMENT(env).
***/

/*
RETURN(0, the environment has been saved by THIS())
RETURN(NONZERO, the environment has been restored by FUNCTION(longjmp))

CONSTRAINT: entire controlling expression of a selection or iteration statement
CONSTRAINT: one operand of a relational or equality operator which is the entire controlling expression of a selction or iteration statement
CONSTRAINT: the operand of a unary ! as the entire controlling expression of a selection or iteration statement
CONSTRAINT: an entire expression statement

UNSPECIFIED(Whether THIS() is a macro or identifier with external linkage)

UNDEFINED(A macro definition of THIS() is suppressed in order to access an actual function)
UNDEFINED(A program defines an external identifier named LITERAL(setjmp))

STDC(1)
*/


#endif
