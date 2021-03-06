Building
--------
First run `configure` to set up the standards conformance. It has help when run
with -h, which will always be more up-to-date than anything that could be put
in this document.

Then run `make`.

Code Organization
-----------------
Every identifier is placed in its own .c file. Every single one. Every function
(with two types of exceptions), every extern variable, every #define, every
typedef, every struct and union definition. This facilitates generating man
pages, 1 per, as well has header generation.

The two exceptions are math functions (in `<math.h>`, `<complex.h>`, and
`<tgmath.h>`) that are defined identically for all three floating point types,
and Curses functions (in `<curses.h>`) that include `w` and possible `mv` and
`mvw` prefixed versions. Those use macros inside those files to define the
alternate versions, and the man page and header file generation scripts treat
them specially.

As for paths, files are in `src/<primary header name without.h>/<identifier>.c`.
For example, `printf()` is at `src/stdio/printf.c`. The tags file should also
be generally up-to-date, so `vi -t printf` should work, too.

Compiler Requirements
---------------------
The compiler must define exactly one of `__LP32__`, `__ILP32__`, `__ILP64__`,
`__LLP64__`, or `__LP64__`, describing the relative sizes of `int`, `long`,
`long long`, and pointer types as described in this table (underscores remove
for clarity):

|		| LP32	| ILP32	| ILP64	| LLP64	| LP64	|
| -------------	| -----	| -----	| -----	| -----	| -----	|
| char		| 8	| 8	| 8	| 8	| 8	|
| short		| 16	| 16	| 16	| 16	| 16 	|
| int		| 16	| 32	| 64	| 32	| 32	|
| long		| 32	| 32	| 64	| 32	| 64	|
| long long	| 64	| 64	| 64	| 64	| 64	|
| pointer	| 32	| 32	| 64	| 64	| 64	|

The aformentioned symbol is used, among other places, for the proper definition
of `size_t`, `ssize_t`, and `intptr_t`.

Coding Style
------------
Start with K&R. Indents are tabs. Tabs are 8 spaces.
