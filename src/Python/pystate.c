
/* Thread and interpreter state structures and their interfaces */

/* Adapted from CPython 2.1, Python/pystate.c.
 * Copyright (c) 2001 Python Software Foundation; All Rights Reserved.
 * License: reference/cpython-2.1/LICENSE (retained with the reference source).
 * Changes: self-contained recovered ABI, disabled native-thread locks,
 * and inline-only un-emitted thread deletion helpers.
 * Original text: 0x8019FBA0..0x801A01C8.
 */
typedef struct _typeobject PyTypeObject;
typedef struct _object {
    int ob_refcnt;
    PyTypeObject *ob_type;
} PyObject;

typedef int (*visitproc)(PyObject *, void *);
typedef void (*destructor)(PyObject *);
typedef PyObject *(*getattrfunc)(PyObject *, char *);
typedef int (*setattrfunc)(PyObject *, char *, PyObject *);
typedef PyObject *(*reprfunc)(PyObject *);
struct _typeobject {
    int ob_refcnt;
    PyTypeObject *ob_type;
    int ob_size;
    char *tp_name;
    int tp_basicsize, tp_itemsize;
    destructor tp_dealloc;
    void *tp_print;
    getattrfunc tp_getattr;
    setattrfunc tp_setattr;
    void *tp_compare;
    reprfunc tp_repr;
    void *tp_as_number, *tp_as_sequence, *tp_as_mapping;
    void *tp_hash, *tp_call, *tp_str, *tp_getattro, *tp_setattro;
    void *tp_as_buffer;
    long tp_flags;
    char *tp_doc;
    int (*tp_traverse)(PyObject *, visitproc, void *);
    void *tp_clear, *tp_richcompare;
    long tp_weaklistoffset;
};

struct _ts; /* Forward */
struct _is; /* Forward */

typedef struct _is {

    struct _is *next;
    struct _ts *tstate_head;

    PyObject *modules;
    PyObject *sysdict;
    PyObject *builtins;

    int checkinterval;

} PyInterpreterState;


/* State unique per thread */

struct _frame; /* Avoid including frameobject.h */

typedef struct _ts {

    struct _ts *next;
    PyInterpreterState *interp;

    struct _frame *frame;
    int recursion_depth;
    int ticker;
    int tracing;

    PyObject *sys_profilefunc;
    PyObject *sys_tracefunc;

    PyObject *curexc_type;
    PyObject *curexc_value;
    PyObject *curexc_traceback;

    PyObject *exc_type;
    PyObject *exc_value;
    PyObject *exc_traceback;

    PyObject *dict;

    /* XXX signal handlers should also be here */

} PyThreadState;


#define NULL 0
#define Py_DECREF(op) if (--(op)->ob_refcnt != 0) ; else (*(op)->ob_type->tp_dealloc)((PyObject *)(op))
#define Py_XDECREF(op) if ((op) == NULL) ; else Py_DECREF(op)
#define PyMem_NEW(type, n) ((type *)malloc(1 + (n)*sizeof(type)))
#define PyMem_DEL(op) free(op)
typedef struct { char contents[80]; } FILE;
extern FILE __files[];
#define stderr (&__files[2])
extern void *malloc(unsigned int);
extern void free(void *);
extern int fprintf(FILE *, const char *, ...);
extern int Py_VerboseFlag;
extern void Py_FatalError(const char *);
extern PyObject *PyDict_New(void);
void PyThreadState_Clear(PyThreadState *);
static inline void PyThreadState_Delete(PyThreadState *);


/* Preserve the linked diagnostic-string order independently of inlining. */
static char thread_getdict_error[] = "PyThreadState_GetDict: no current thread";
static char thread_get_error[] = "PyThreadState_Get: no current thread";
static char thread_delete_current_error[] = "PyThreadState_Delete: tstate is still current";
static char thread_delete_null_error[] = "PyThreadState_Delete: NULL tstate";
static char thread_delete_interp_error[] = "PyThreadState_Delete: NULL interp";
static char thread_delete_invalid_error[] = "PyThreadState_Delete: invalid tstate";
static char thread_clear_warning[] = "PyThreadState_Clear: warning: thread still has a frame\n";
static char interp_delete_invalid_error[] = "PyInterpreterState_Delete: invalid interp";
static char interp_delete_threads_error[] = "PyInterpreterState_Delete: remaining threads";

#define ZAP(x) { \
	PyObject *tmp = (PyObject *)(x); \
	(x) = NULL; \
	Py_XDECREF(tmp); \
}


#ifdef WITH_THREAD
#include "pythread.h"
static PyThread_type_lock head_mutex = NULL; /* Protects interp->tstate_head */
#define HEAD_INIT() (void)(head_mutex || (head_mutex = PyThread_allocate_lock()))
#define HEAD_LOCK() PyThread_acquire_lock(head_mutex, WAIT_LOCK)
#define HEAD_UNLOCK() PyThread_release_lock(head_mutex)
#else
#define HEAD_INIT() /* Nothing */
#define HEAD_LOCK() /* Nothing */
#define HEAD_UNLOCK() /* Nothing */
#endif

static PyInterpreterState *interp_head = NULL;

PyThreadState *_PyThreadState_Current = NULL;


PyInterpreterState *
PyInterpreterState_New(void)
{
	PyInterpreterState *interp = PyMem_NEW(PyInterpreterState, 1);

	if (interp != NULL) {
		HEAD_INIT();
		interp->modules = NULL;
		interp->sysdict = NULL;
		interp->builtins = NULL;
		interp->checkinterval = 10;
		interp->tstate_head = NULL;

		HEAD_LOCK();
		interp->next = interp_head;
		interp_head = interp;
		HEAD_UNLOCK();
	}

	return interp;
}


void
PyInterpreterState_Clear(PyInterpreterState *interp)
{
	PyThreadState *p;
	HEAD_LOCK();
	for (p = interp->tstate_head; p != NULL; p = p->next)
		PyThreadState_Clear(p);
	HEAD_UNLOCK();
	ZAP(interp->modules);
	ZAP(interp->sysdict);
	ZAP(interp->builtins);
}


static inline void
zapthreads(PyInterpreterState *interp)
{
	PyThreadState *p;
	/* No need to lock the mutex here because this should only happen
	   when the threads are all really dead (XXX famous last words). */
	while ((p = interp->tstate_head) != NULL) {
		PyThreadState_Delete(p);
	}
}


void
PyInterpreterState_Delete(PyInterpreterState *interp)
{
	PyInterpreterState **p;
	zapthreads(interp);
	HEAD_LOCK();
	for (p = &interp_head; ; p = &(*p)->next) {
		if (*p == NULL)
			Py_FatalError(
				interp_delete_invalid_error);
		if (*p == interp)
			break;
	}
	if (interp->tstate_head != NULL)
		Py_FatalError(interp_delete_threads_error);
	*p = interp->next;
	HEAD_UNLOCK();
	PyMem_DEL(interp);
}


PyThreadState *
PyThreadState_New(PyInterpreterState *interp)
{
	PyThreadState *tstate = PyMem_NEW(PyThreadState, 1);

	if (tstate != NULL) {
		tstate->interp = interp;

		tstate->frame = NULL;
		tstate->recursion_depth = 0;
		tstate->ticker = 0;
		tstate->tracing = 0;

		tstate->dict = NULL;

		tstate->curexc_type = NULL;
		tstate->curexc_value = NULL;
		tstate->curexc_traceback = NULL;

		tstate->exc_type = NULL;
		tstate->exc_value = NULL;
		tstate->exc_traceback = NULL;

		tstate->sys_profilefunc = NULL;
		tstate->sys_tracefunc = NULL;

		HEAD_LOCK();
		tstate->next = interp->tstate_head;
		interp->tstate_head = tstate;
		HEAD_UNLOCK();
	}

	return tstate;
}


void
PyThreadState_Clear(PyThreadState *tstate)
{
	if (Py_VerboseFlag && tstate->frame != NULL)
		fprintf(stderr,
		  thread_clear_warning);

	ZAP(tstate->frame);

	ZAP(tstate->dict);

	ZAP(tstate->curexc_type);
	ZAP(tstate->curexc_value);
	ZAP(tstate->curexc_traceback);

	ZAP(tstate->exc_type);
	ZAP(tstate->exc_value);
	ZAP(tstate->exc_traceback);

	ZAP(tstate->sys_profilefunc);
	ZAP(tstate->sys_tracefunc);
}


/* Common code for PyThreadState_Delete() and PyThreadState_DeleteCurrent() */
static inline void
tstate_delete_common(PyThreadState *tstate)
{
	PyInterpreterState *interp;
	PyThreadState **p;
	if (tstate == NULL)
		Py_FatalError(thread_delete_null_error);
	interp = tstate->interp;
	if (interp == NULL)
		Py_FatalError(thread_delete_interp_error);
	HEAD_LOCK();
	for (p = &interp->tstate_head; ; p = &(*p)->next) {
		if (*p == NULL)
			Py_FatalError(
				thread_delete_invalid_error);
		if (*p == tstate)
			break;
	}
	*p = tstate->next;
	HEAD_UNLOCK();
	PyMem_DEL(tstate);
}


static inline void
PyThreadState_Delete(PyThreadState *tstate)
{
	if (tstate == _PyThreadState_Current)
		Py_FatalError(thread_delete_current_error);
	tstate_delete_common(tstate);
}


#ifdef WITH_THREAD
void
PyThreadState_DeleteCurrent()
{
	PyThreadState *tstate = _PyThreadState_Current;
	if (tstate == NULL)
		Py_FatalError(
			"PyThreadState_DeleteCurrent: no current tstate");
	_PyThreadState_Current = NULL;
	tstate_delete_common(tstate);
	PyEval_ReleaseLock();
}
#endif /* WITH_THREAD */


PyThreadState *
PyThreadState_Get(void)
{
	if (_PyThreadState_Current == NULL)
		Py_FatalError(thread_get_error);

	return _PyThreadState_Current;
}


PyThreadState *
PyThreadState_Swap(PyThreadState *new)
{
	PyThreadState *old = _PyThreadState_Current;

	_PyThreadState_Current = new;

	return old;
}

/* An extension mechanism to store arbitrary additional per-thread state.
   PyThreadState_GetDict() returns a dictionary that can be used to hold such
   state; the caller should pick a unique key and store its state there.  If
   PyThreadState_GetDict() returns NULL, an exception has been raised (most
   likely MemoryError) and the caller should pass on the exception. */

PyObject *
PyThreadState_GetDict(void)
{
	if (_PyThreadState_Current == NULL)
		Py_FatalError(thread_getdict_error);

	if (_PyThreadState_Current->dict == NULL)
		_PyThreadState_Current->dict = PyDict_New();
	return _PyThreadState_Current->dict;
}
