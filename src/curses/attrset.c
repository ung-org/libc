#include <curses.h>
#include "_curses.h"

int wattrset(WINDOW * win, int attrs)
{
	return ERR;
}

CURSES_WFN1(int, attrset, int)

/*
XOPEN(4)
LINK(curses)
*/
