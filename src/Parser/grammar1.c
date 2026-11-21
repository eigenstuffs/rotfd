/* CPython 2.1 grammar lookup; see reference/cpython-2.1/LICENSE. */
#include "parser_abi.h"
#include "parser_assert.h"

/* Grammar subroutines needed by parser */


/* Return the DFA for the given type */

dfa *
PyGrammar_FindDFA(grammar *g, register int type)
{
	register dfa *d;
#if 1
	/* Massive speed-up */
	d = &g->g_dfa[type - NT_OFFSET];
	assert(d->d_type == type);
	return d;
#else
	/* Old, slow version */
	register int i;
	
	for (i = g->g_ndfas, d = g->g_dfa; --i >= 0; d++) {
		if (d->d_type == type)
			return d;
	}
	assert(0);
	/* NOTREACHED */
#endif
}
