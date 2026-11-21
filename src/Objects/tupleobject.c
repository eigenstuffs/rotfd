/***********************************************************
Copyright 1991-1995 by Stichting Mathematisch Centrum, Amsterdam,
The Netherlands.

                        All Rights Reserved

Permission to use, copy, modify, and distribute this software and its
documentation for any purpose and without fee is hereby granted,
provided that the above copyright notice appear in all copies and that
both that copyright notice and this permission notice appear in
supporting documentation, and that the names of Stichting Mathematisch
Centrum or CWI or Corporation for National Research Initiatives or
CNRI not be used in advertising or publicity pertaining to
distribution of the software without specific, written prior
permission.

While CWI is the initial source for this software, a modified version
is made available by the Corporation for National Research Initiatives
(CNRI) at the Internet address ftp://ftp.python.org.

STICHTING MATHEMATISCH CENTRUM AND CNRI DISCLAIM ALL WARRANTIES WITH
REGARD TO THIS SOFTWARE, INCLUDING ALL IMPLIED WARRANTIES OF
MERCHANTABILITY AND FITNESS, IN NO EVENT SHALL STICHTING MATHEMATISCH
CENTRUM OR CNRI BE LIABLE FOR ANY SPECIAL, INDIRECT OR CONSEQUENTIAL
DAMAGES OR ANY DAMAGES WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR
PROFITS, WHETHER IN AN ACTION OF CONTRACT, NEGLIGENCE OR OTHER
TORTIOUS ACTION, ARISING OUT OF OR IN CONNECTION WITH THE USE OR
PERFORMANCE OF THIS SOFTWARE.

******************************************************************/

#include "object.h"
#include "tupleobject.h"

/* Objects/tupleobject.c - GSQE78 tuple implementation.
 *
 * Matched .text 0x80163D7C..0x80164EF8, its type/sequence tables, strings,
 * and free-list storage. CPython 2.1 confirms the later APIs and rich-compare
 * behavior; see reference/cpython-2.1/LICENSE for that reference's license.
 * The definition order follows the linked executable. Keep -pool off so
 * references retain their individual data addresses.
 */

#define MAXSAVESIZE 20
#define MAXSAVEDTUPLES 2000
#define PyTrash_UNWIND_LEVEL 50
#define Py_LT 0
#define Py_LE 1
#define Py_EQ 2
#define Py_NE 3
#define Py_GT 4
#define Py_GE 5

typedef struct {
    int (*sq_length)(PyObject *);
    PyObject *(*sq_concat)(PyObject *, PyObject *);
    PyObject *(*sq_repeat)(PyObject *, int);
    PyObject *(*sq_item)(PyObject *, int);
    PyObject *(*sq_slice)(PyObject *, int, int);
    void *sq_ass_item, *sq_ass_slice;
    int (*sq_contains)(PyObject *, PyObject *);
    void *sq_inplace_concat, *sq_inplace_repeat;
} PySequenceMethods;

struct _typeobject {
    PyObject_VAR_HEAD
    char *tp_name;
    int tp_basicsize, tp_itemsize;
    void (*tp_dealloc)(PyObject *);
    int (*tp_print)(PyObject *, void *, int);
    void *tp_getattr, *tp_setattr, *tp_compare;
    PyObject *(*tp_repr)(PyObject *);
    void *tp_as_number;
    PySequenceMethods *tp_as_sequence;
    void *tp_as_mapping;
    long (*tp_hash)(PyObject *);
    void *tp_call, *tp_str, *tp_getattro, *tp_setattro, *tp_as_buffer;
    long tp_flags;
    char *tp_doc;
    int (*tp_traverse)(PyObject *, int (*)(PyObject *, void *), void *);
    void *tp_clear;
    PyObject *(*tp_richcompare)(PyObject *, PyObject *, int);
    long tp_weaklistoffset;
};

extern PyObject *PyExc_IndexError;
extern PyObject *PyExc_TypeError;
extern PyTypeObject PyTuple_Type;
extern char tuple_concat_error[]; /* tuple concatenation type error */
extern char tuple_index_error[]; /* "tuple index out of range" */
extern char tuple_repr_open[2]; /* "(" */
extern char tuple_repr_separator[3]; /* ", " */
extern char tuple_repr_single[2]; /* "," */
extern char tuple_repr_close[2]; /* ")" */

extern void PyErr_SetString(PyObject *, const char *);
extern void PyErr_Format(PyObject *, const char *, ...);
extern PyObject *PyErr_NoMemory(void);
extern PyObject *PyTuple_New(int);
extern int PyObject_RichCompareBool(PyObject *, PyObject *, int);
extern long PyObject_Hash(PyObject *);
extern PyObject *PyString_FromString(const char *);
extern void PyString_Concat(PyObject **, PyObject *);
extern void PyString_ConcatAndDel(PyObject **, PyObject *);
extern PyObject *PyObject_Repr(PyObject *);
extern int PyObject_Print(PyObject *, void *, int);
extern int fprintf(void *, const char *, ...);

#undef Py_DECREF
#define Py_DECREF(op) \
	if (--(op)->ob_refcnt != 0) ; \
	else (*(op)->ob_type->tp_dealloc)((PyObject *)(op))

extern int numfree[MAXSAVESIZE];
extern PyTupleObject *free_tuples[MAXSAVESIZE];
extern void free(void *);
extern void *realloc(void *, unsigned int);
extern char tuple_filename[];
extern void _PyErr_BadInternalCall(const char *, int);
#define Py_XDECREF(op) if ((op) == NULL) ; else {Py_DECREF(op);}

void PyTuple_Fini(void)
{
    int i;
    Py_XDECREF(free_tuples[0]);
    free_tuples[0] = NULL;
    for (i = 1; i < MAXSAVESIZE; i++) {
        PyTupleObject *p, *q;
        p = free_tuples[i];
        free_tuples[i] = NULL;
        while (p) {
            q = p;
            p = (PyTupleObject *)p->ob_item[0];
            free(q);
        }
    }
}

int _PyTuple_Resize(pv, newsize, last_is_sticky)
    PyObject **pv;
    int newsize;
    int last_is_sticky;
{
    register PyTupleObject *v;
    register PyTupleObject *sv;
    int i;
    int sizediff;
    v = (PyTupleObject *)*pv;
    if (v == NULL || v->ob_type != &PyTuple_Type || v->ob_refcnt != 1 || last_is_sticky) {
        *pv = 0;
        Py_XDECREF(v);
        _PyErr_BadInternalCall(tuple_filename, 506);
        return -1;
    }
    sizediff = newsize - v->ob_size;
    if (sizediff == 0)
        return 0;
    for (i = newsize; i < v->ob_size; i++) {
        Py_XDECREF(v->ob_item[i]);
        v->ob_item[i] = NULL;
    }
    sv = (PyTupleObject *)realloc((char *)v,
        sizeof(PyTupleObject) + newsize * sizeof(PyObject *));
    if (sv == NULL) {
        *pv = NULL;
        free(v);
        PyErr_NoMemory();
        return -1;
    }
    sv->ob_refcnt = 1;
    for (i = sv->ob_size; i < newsize; i++)
        sv->ob_item[i] = NULL;
    sv->ob_size = newsize;
    *pv = (PyObject *)sv;
    return 0;
}
typedef struct { PyObject_HEAD long ob_ival; } PyIntObject;
extern PyObject _Py_NotImplementedStruct;
extern PyIntObject _Py_ZeroStruct, _Py_TrueStruct;
extern PyObject *PyObject_RichCompare(PyObject *, PyObject *, int);

PyObject *tuplerichcompare(vv, ww, op)
    PyObject *vv;
    PyObject *ww;
    int op;
{
    PyTupleObject *v, *w;
    int i;
    if (vv->ob_type != &PyTuple_Type || ww->ob_type != &PyTuple_Type) {
        Py_INCREF(&_Py_NotImplementedStruct);
        return &_Py_NotImplementedStruct;
    }
    v = (PyTupleObject *)vv;
    w = (PyTupleObject *)ww;
    if (v->ob_size != w->ob_size && (op == Py_EQ || op == Py_NE)) {
        PyObject *res;
        if (op == Py_EQ)
            res = (PyObject *)&_Py_ZeroStruct;
        else
            res = (PyObject *)&_Py_TrueStruct;
        Py_INCREF(res);
        return res;
    }
    for (i = 0; i < v->ob_size && i < w->ob_size; i++) {
        int k = PyObject_RichCompareBool(v->ob_item[i], w->ob_item[i], Py_EQ);
        if (k < 0)
            return NULL;
        if (!k)
            break;
    }
    if (i >= v->ob_size || i >= w->ob_size) {
        int vs = v->ob_size;
        int ws = w->ob_size;
        int cmp;
        PyObject *res;
        switch (op) {
        case Py_LT: cmp = vs < ws; break;
        /* Original CPython 2.1 typo: comparing ws with itself is intentional
         * here because this is a matching reconstruction. */
        case Py_LE: cmp = ws <= ws; break;
        case Py_EQ: cmp = vs == ws; break;
        case Py_NE: cmp = vs != ws; break;
        case Py_GT: cmp = vs > ws; break;
        case Py_GE: cmp = vs >= ws; break;
        default: return NULL;
        }
        if (cmp)
            res = (PyObject *)&_Py_TrueStruct;
        else
            res = (PyObject *)&_Py_ZeroStruct;
        Py_INCREF(res);
        return res;
    }
    if (op == Py_EQ) {
        Py_INCREF(&_Py_ZeroStruct);
        return (PyObject *)&_Py_ZeroStruct;
    }
    if (op == Py_NE) {
        Py_INCREF(&_Py_TrueStruct);
        return (PyObject *)&_Py_TrueStruct;
    }
    return PyObject_RichCompare(v->ob_item[i], w->ob_item[i], op);
}

int
tupletraverse(o, visit, arg)
	PyTupleObject *o;
	int (*visit)(PyObject *, void *);
	void *arg;
{
	int i;
	for (i = o->ob_size; --i >= 0; ) {
		if (o->ob_item[i] != NULL) {
			int err = visit(o->ob_item[i], arg);
			if (err)
				return err;
		}
	}
	return 0;
}

PyObject *
tuplerepeat(a, n)
	PyTupleObject *a;
	int n;
{
	int i, j;
	int size;
	PyTupleObject *np;
	PyObject **p;
	if (n < 0)
		n = 0;
	if (a->ob_size == 0 || n == 1) {
		Py_INCREF(a);
		return (PyObject *)a;
	}
	size = a->ob_size * n;
	if (size / a->ob_size != n)
		return PyErr_NoMemory();
	np = (PyTupleObject *)PyTuple_New(size);
	if (np == NULL)
		return NULL;
	p = np->ob_item;
	for (i = 0; i < n; i++) {
		for (j = 0; j < a->ob_size; j++) {
			*p = a->ob_item[j];
			Py_INCREF(*p);
			p++;
		}
	}
	return (PyObject *)np;
}

PyObject *
tupleconcat(a, bb)
	register PyTupleObject *a;
	register PyObject *bb;
{
	register int size;
	register int i;
	PyTupleObject *np;
	if (bb->ob_type != &PyTuple_Type) {
		PyErr_Format(PyExc_TypeError, tuple_concat_error,
			bb->ob_type->tp_name);
		return NULL;
	}
#define b ((PyTupleObject *)bb)
	size = a->ob_size + b->ob_size;
	np = (PyTupleObject *)PyTuple_New(size);
	if (np == NULL)
		return NULL;
	for (i = 0; i < a->ob_size; i++) {
		PyObject *v = a->ob_item[i];
		Py_INCREF(v);
		np->ob_item[i] = v;
	}
	for (i = 0; i < b->ob_size; i++) {
		PyObject *v = b->ob_item[i];
		Py_INCREF(v);
		np->ob_item[i + a->ob_size] = v;
	}
	return (PyObject *)np;
#undef b
}

PyObject *
tupleslice(a, ilow, ihigh)
	register PyTupleObject *a;
	register int ilow, ihigh;
{
	register PyTupleObject *np;
	register int i;
	if (ilow < 0)
		ilow = 0;
	if (ihigh > a->ob_size)
		ihigh = a->ob_size;
	if (ihigh < ilow)
		ihigh = ilow;
	if (ilow == 0 && ihigh == a->ob_size) {
		Py_INCREF(a);
		return (PyObject *)a;
	}
	np = (PyTupleObject *)PyTuple_New(ihigh - ilow);
	if (np == NULL)
		return NULL;
	for (i = ilow; i < ihigh; i++) {
		PyObject *v = a->ob_item[i];
		Py_INCREF(v);
		np->ob_item[i - ilow] = v;
	}
	return (PyObject *)np;
}

PyObject *
tupleitem(a, i)
	register PyTupleObject *a;
	register int i;
{
	if (i < 0 || i >= a->ob_size) {
		PyErr_SetString(PyExc_IndexError, tuple_index_error);
		return NULL;
	}
	Py_INCREF(a->ob_item[i]);
	return a->ob_item[i];
}

int
tuplecontains(a, el)
	PyTupleObject *a;
	PyObject *el;
{
	int i;
	for (i = 0; i < a->ob_size; i++) {
		int cmp = PyObject_RichCompareBool(el, a->ob_item[i], Py_EQ);
		if (cmp > 0)
			return 1;
		if (cmp < 0)
			return -1;
	}
	return 0;
}

int
tuplelength(a)
	PyTupleObject *a;
{
	return a->ob_size;
}

long
tuplehash(v)
	register PyTupleObject *v;
{
	register long x, y;
	register int len = v->ob_size;
	register PyObject **p;
	x = 0x345678L;
	p = v->ob_item;
	while (--len >= 0) {
		y = PyObject_Hash(*p++);
		if (y == -1)
			return -1;
		x = (1000003*x) ^ y;
	}
	x ^= v->ob_size;
	if (x == -1)
		x = -2;
	return x;
}

PyObject *
tuplerepr(v)
	PyTupleObject *v;
{
	PyObject *s, *comma;
	int i;
	s = PyString_FromString(tuple_repr_open);
	comma = PyString_FromString(tuple_repr_separator);
	for (i = 0; i < v->ob_size && s != NULL; i++) {
		if (i > 0)
			PyString_Concat(&s, comma);
		PyString_ConcatAndDel(&s, PyObject_Repr(v->ob_item[i]));
	}
	Py_DECREF(comma);
	if (v->ob_size == 1)
		PyString_ConcatAndDel(&s, PyString_FromString(tuple_repr_single));
	PyString_ConcatAndDel(&s, PyString_FromString(tuple_repr_close));
	return s;
}

int
tupleprint(op, fp, flags)
	PyTupleObject *op;
	void *fp;
	int flags;
{
	int i;
	fprintf(fp, tuple_repr_open);
	for (i = 0; i < op->ob_size; i++) {
		if (i > 0)
			fprintf(fp, tuple_repr_separator);
		if (PyObject_Print(op->ob_item[i], fp, 0) != 0)
			return -1;
	}
	if (op->ob_size == 1)
		fprintf(fp, tuple_repr_single);
	fprintf(fp, tuple_repr_close);
	return 0;
}
extern int _PyTrash_delete_nesting;
extern PyObject *_PyTrash_delete_later;
extern void _PyTrash_deposit_object(PyObject *);
extern void _PyTrash_destroy_chain(void);
extern void *malloc(unsigned int);
extern char tuple_ass_index_error[];

void tupledealloc(op)
    register PyTupleObject *op;
{
    register int i;
    register int len = op->ob_size;
    if (++_PyTrash_delete_nesting < PyTrash_UNWIND_LEVEL) {
        if (len > 0) {
            i = len;
            while (--i >= 0)
                Py_XDECREF(op->ob_item[i]);
            if (len < MAXSAVESIZE && numfree[len] < MAXSAVEDTUPLES) {
                op->ob_item[0] = (PyObject *)free_tuples[len];
                numfree[len]++;
                free_tuples[len] = op;
                goto done;
            }
        }
        free((void *)op);
    done:;
    } else {
        _PyTrash_deposit_object((PyObject *)op);
    }
    --_PyTrash_delete_nesting;
    if (_PyTrash_delete_later && _PyTrash_delete_nesting <= 0)
        _PyTrash_destroy_chain();
}

int PyTuple_SetItem(op, i, newitem)
    register PyObject *op;
    register int i;
    PyObject *newitem;
{
    register PyObject *olditem;
    register PyObject **p;
    if (op->ob_type != &PyTuple_Type || op->ob_refcnt != 1) {
        Py_XDECREF(newitem);
        _PyErr_BadInternalCall(tuple_filename, 123);
        return -1;
    }
    if (i < 0 || i >= ((PyTupleObject *)op)->ob_size) {
        Py_XDECREF(newitem);
        PyErr_SetString(PyExc_IndexError, tuple_ass_index_error);
        return -1;
    }
    p = ((PyTupleObject *)op)->ob_item + i;
    olditem = *p;
    *p = newitem;
    Py_XDECREF(olditem);
    return 0;
}

PyObject *PyTuple_GetItem(op, i)
    register PyObject *op;
    register int i;
{
    if (op->ob_type != &PyTuple_Type) {
        _PyErr_BadInternalCall(tuple_filename, 106);
        return NULL;
    }
    if (i < 0 || i >= ((PyTupleObject *)op)->ob_size) {
        PyErr_SetString(PyExc_IndexError, tuple_index_error);
        return NULL;
    }
    return ((PyTupleObject *)op)->ob_item[i];
}

int PyTuple_Size(op)
    register PyObject *op;
{
    if (op->ob_type != &PyTuple_Type) {
        _PyErr_BadInternalCall(tuple_filename, 95);
        return -1;
    } else
        return ((PyTupleObject *)op)->ob_size;
}

PyObject *PyTuple_New(size)
    register int size;
{
    register int i;
    register PyTupleObject *op;
    if (size < 0) {
        _PyErr_BadInternalCall(tuple_filename, 32);
        return NULL;
    }
    if (size == 0 && free_tuples[0]) {
        op = free_tuples[0];
        Py_INCREF(op);
        return (PyObject *)op;
    }
    if (0 < size && size < MAXSAVESIZE && (op = free_tuples[size]) != NULL) {
        free_tuples[size] = (PyTupleObject *)op->ob_item[0];
        numfree[size]--;
        op->ob_refcnt = 1;
    } else {
        int nbytes = size * sizeof(PyObject *);
        if (nbytes / sizeof(PyObject *) != (unsigned)size ||
            (nbytes += sizeof(PyTupleObject) - sizeof(PyObject *)) <= 0)
            return PyErr_NoMemory();
        op = (PyTupleObject *)malloc(nbytes);
        if (op == NULL)
            return PyErr_NoMemory();
        op->ob_size = size;
        op->ob_type = &PyTuple_Type;
        op->ob_refcnt = 1;
    }
    for (i = 0; i < size; i++)
        op->ob_item[i] = NULL;
    if (size == 0) {
        free_tuples[0] = op;
        numfree[0]++;
        Py_INCREF(op);
    }
    return (PyObject *)op;
}
/* Original type and sequence tables; unused slots are retained verbatim. */
extern PyTypeObject PyType_Type;
char tuple_name[6] = "tuple";
char tuple_repr_open[2] = "(";
char tuple_repr_separator[3] = ", ";
char tuple_repr_single[2] = ",";
char tuple_repr_close[2] = ")";

PySequenceMethods tuple_as_sequence = {
    (int (*)(PyObject *))tuplelength,
    (PyObject *(*)(PyObject *, PyObject *))tupleconcat,
    (PyObject *(*)(PyObject *, int))tuplerepeat,
    (PyObject *(*)(PyObject *, int))tupleitem,
    (PyObject *(*)(PyObject *, int, int))tupleslice,
    0,
    0,
    (int (*)(PyObject *, PyObject *))tuplecontains,
    0,
    0,
};

PyTypeObject PyTuple_Type = {
    1, &PyType_Type, 0,
    tuple_name,
    sizeof(PyTupleObject) - sizeof(PyObject *),
    sizeof(PyObject *),
    (void (*)(PyObject *))tupledealloc,
    (int (*)(PyObject *, void *, int))tupleprint,
    0, 0, 0,
    (PyObject *(*)(PyObject *))tuplerepr,
    0, &tuple_as_sequence, 0,
    (long (*)(PyObject *))tuplehash,
    0, 0, 0, 0, 0,
    0x6B, 0,
    (int (*)(PyObject *, int (*)(PyObject *, void *), void *))tupletraverse,
    0,
    tuplerichcompare,
    0,
};

char tuple_filename[] = "tupleobject.c";
char tuple_concat_error[] = "can only concatenate tuple (not \"%.200s\") to tuple";
char tuple_index_error[] = "tuple index out of range";
char tuple_ass_index_error[] = "tuple assignment index out of range";
PyTupleObject *free_tuples[MAXSAVESIZE];
int numfree[MAXSAVESIZE];
