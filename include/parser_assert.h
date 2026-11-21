/* Active parser assertions from CPython 2.1 Parser/assert.h.
 * See reference/cpython-2.1/LICENSE. */
#ifndef ROTFD_PARSER_ASSERT_H
#define ROTFD_PARSER_ASSERT_H
#undef assert
int printf(const char *, ...);
void abort(void);
#define assert(e) { if (!(e)) { printf("Assertion failed\n"); abort(); } }
#endif
