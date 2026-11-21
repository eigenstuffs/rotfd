/* Future-statement processing in the GSQE78 Python runtime.
 * Derived from CPython 2.1 Python/future.c and its public headers.
 * Copyright (c) 2001 Python Software Foundation; all rights reserved.
 * License: reference/cpython-2.1/LICENSE.
 * Complete linked text: 0x80193318..0x8019376C.
 */
typedef unsigned int size_t;
typedef struct _object PyObject;
typedef struct { int ff_found_docstring, ff_last_lineno, ff_nested_scopes; } PyFutureFeatures;
extern int strcmp(const char *, const char *);
extern void PyErr_SetString(PyObject *, const char *);
extern void PyErr_SyntaxLocation(char *, int);
extern PyObject *PyErr_Format(PyObject *, const char *, ...);
extern PyObject *PyExc_SyntaxError;
extern void *PyMem_Malloc(size_t);
extern void PyMem_Free(void *);
typedef struct _node {
    short n_type;
    char *n_str;
    int n_lineno;
    int n_nchildren;
    struct _node *n_child;
} node;
extern char * _PyParser_TokenNames[];


#define CHILD(n,i) (&(n)->n_child[i])
#define ENDMARKER 0
#define FUTURE_NESTED_SCOPES "nested_scopes"
#define NAME 1
#define NCH(n) ((n)->n_nchildren)
#define NEWLINE 4
#define NULL 0
#define REQ(n,type) { ; }
#define STAR 16
#define STR(n) ((n)->n_str)
#define STRING 3
#define TYPE(n) ((n)->n_type)
#define and_expr 298
#define and_test 292
#define arith_expr 300
#define assert_stmt 283
#define atom 304
#define comparison 294
#define compound_stmt 284
#define del_stmt 270
#define dotted_as_name 279
#define dotted_name 280
#define exec_stmt 282
#define expr 296
#define expr_stmt 267
#define factor 302
#define file_input 257
#define flow_stmt 272
#define global_stmt 281
#define import_as_name 278
#define import_stmt 277
#define not_test 293
#define pass_stmt 271
#define power 303
#define print_stmt 269
#define shift_expr 299
#define simple_stmt 265
#define single_input 256
#define small_stmt 266
#define stmt 264
#define term 301
#define test 291
#define testlist 312
#define xor_expr 297

#define UNDEFINED_FUTURE_FEATURE "future feature %.100s is not defined"
#define FUTURE_IMPORT_STAR "future statement does not support import *"

#define FUTURE_POSSIBLE(FF) ((FF)->ff_last_lineno == -1)

static inline int
future_check_features(PyFutureFeatures *ff, node *n, char *filename)
{
	int i;
	char *feature;
	node *ch;

	REQ(n, import_stmt); /* must by from __future__ import ... */

	for (i = 3; i < NCH(n); i += 2) {
		ch = CHILD(n, i);
		if (TYPE(ch) == STAR) {
			PyErr_SetString(PyExc_SyntaxError,
					FUTURE_IMPORT_STAR);
			PyErr_SyntaxLocation(filename, ch->n_lineno);
			return -1;
		}
		REQ(ch, import_as_name);
		feature = STR(CHILD(ch, 0));
		if (strcmp(feature, FUTURE_NESTED_SCOPES) == 0) {
			ff->ff_nested_scopes = 1;
		} else if (strcmp(feature, "braces") == 0) {
			PyErr_SetString(PyExc_SyntaxError,
					"not a chance");
			PyErr_SyntaxLocation(filename, CHILD(ch, 0)->n_lineno);
			return -1;
		} else {
			PyErr_Format(PyExc_SyntaxError,
				     UNDEFINED_FUTURE_FEATURE, feature);
			PyErr_SyntaxLocation(filename, CHILD(ch, 0)->n_lineno);
			return -1;
		}
	}
	return 0;
}

static inline void
future_error(node *n, char *filename)
{
	PyErr_SetString(PyExc_SyntaxError,
			"from __future__ imports must occur at the "
			"beginning of the file");
	PyErr_SyntaxLocation(filename, n->n_lineno);
	/* XXX set filename and lineno */
}

/* Relevant portions of the grammar:

single_input: NEWLINE | simple_stmt | compound_stmt NEWLINE
file_input: (NEWLINE | stmt)* ENDMARKER
stmt: simple_stmt | compound_stmt
simple_stmt: small_stmt (';' small_stmt)* [';'] NEWLINE
small_stmt: expr_stmt | print_stmt  | del_stmt | pass_stmt | flow_stmt 
    | import_stmt | global_stmt | exec_stmt | assert_stmt
import_stmt: 'import' dotted_as_name (',' dotted_as_name)* 
    | 'from' dotted_name 'import' ('*' | import_as_name (',' import_as_name)*)
import_as_name: NAME [NAME NAME]
dotted_as_name: dotted_name [NAME NAME]
dotted_name: NAME ('.' NAME)*
*/

/* future_parse() return values:
   -1 indicates an error occurred, e.g. unknown feature name
   0 indicates no feature was found
   1 indicates a feature was found
*/

static int
future_parse(PyFutureFeatures *ff, node *n, char *filename)
{
	int i, r;
 loop:

	switch (TYPE(n)) {

	case single_input:
		if (TYPE(CHILD(n, 0)) == simple_stmt) {
			n = CHILD(n, 0);
			goto loop;
		}
		return 0;

	case file_input:
		for (i = 0; i < NCH(n); i++) {
			node *ch = CHILD(n, i);
			if (TYPE(ch) == stmt) {
				r = future_parse(ff, ch, filename);
				if (!FUTURE_POSSIBLE(ff))
					return r;
			}
		}
		return 0;

	case simple_stmt:
		if (NCH(n) == 2) {
			REQ(CHILD(n, 0), small_stmt);
			n = CHILD(n, 0);
			goto loop;
		} else {
			/* Deal with the special case of a series of
			   small statements on a single line.  If a
			   future statement follows some other
			   statement, the SyntaxError is raised here.
			   In all other cases, the symtable pass
			   raises the exception.
			*/
			int found = 0, end_of_future = 0;

			for (i = 0; i < NCH(n); i += 2) {
				if (TYPE(CHILD(n, i)) == small_stmt) {
					r = future_parse(ff, CHILD(n, i), 
							 filename);
					if (r < 1)
						end_of_future = 1;
					else {
						found = 1;
						if (end_of_future) {
							future_error(n, 
								     filename);
							return -1;
						}
					}
				}
			}

			/* If we found one and only one, then the
			   current lineno is legal. 
			*/
			if (found)
				ff->ff_last_lineno = n->n_lineno + 1;
			else
				ff->ff_last_lineno = n->n_lineno;

			if (end_of_future && found)
				return 1;
			else 
				return 0;
		}
	
	case stmt:
		if (TYPE(CHILD(n, 0)) == simple_stmt) {
			n = CHILD(n, 0);
			goto loop;
		} else if (TYPE(CHILD(n, 0)) == expr_stmt) {
			n = CHILD(n, 0);
			goto loop;
		} else {
			REQ(CHILD(n, 0), compound_stmt);
			ff->ff_last_lineno = n->n_lineno;
			return 0;
		}

	case small_stmt:
		n = CHILD(n, 0);
		goto loop;

	case import_stmt: {
		node *name;

		if (STR(CHILD(n, 0))[0] != 'f') { /* from */
			ff->ff_last_lineno = n->n_lineno;
			return 0;
		}
		name = CHILD(n, 1);
		if (strcmp(STR(CHILD(name, 0)), "__future__") != 0)
			return 0;
		if (future_check_features(ff, n, filename) < 0)
			return -1;
		ff->ff_last_lineno = n->n_lineno + 1;
		return 1;
	}

	/* The cases below -- all of them! -- are necessary to find
	   and skip doc strings. */
	case expr_stmt:
	case testlist:
	case test:
	case and_test:
	case not_test:
	case comparison:
	case expr:
	case xor_expr:
	case and_expr:
	case shift_expr:
	case arith_expr:
	case term:
	case factor:
	case power:
		if (NCH(n) == 1) {
			n = CHILD(n, 0);
			goto loop;
		}
		break;

	case atom:
		if (TYPE(CHILD(n, 0)) == STRING 
		    && ff->ff_found_docstring == 0) {
			ff->ff_found_docstring = 1;
			return 0;
		}
		ff->ff_last_lineno = n->n_lineno;
		return 0;

	default:
		ff->ff_last_lineno = n->n_lineno;
		return 0;
	}
	return 0;
}

PyFutureFeatures *
PyNode_Future(node *n, char *filename)
{
	PyFutureFeatures *ff;

	ff = (PyFutureFeatures *)PyMem_Malloc(sizeof(PyFutureFeatures));
	if (ff == NULL)
		return NULL;
	ff->ff_found_docstring = 0;
	ff->ff_last_lineno = -1;
	ff->ff_nested_scopes = 0;

	if (future_parse(ff, n, filename) < 0) {
		PyMem_Free((void *)ff);
		return NULL;
	}
	return ff;
}

