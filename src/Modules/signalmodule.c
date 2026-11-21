/* Signal handling in the Kalisto CPython runtime, GSQE78.
 * Derived from CPython 2.1 Modules/signalmodule.c and its public headers.
 * Copyright (c) 2001 Python Software Foundation; all rights reserved.
 * Upstream license: reference/cpython-2.1/LICENSE.
 */

/* Signal module -- many thanks to Lance Ellinghaus */

/* XXX Signals should be recorded per thread, now we have thread state. */

#define NULL 0
#define PyObject_HEAD int ob_refcnt; struct _typeobject *ob_type;
#define PyObject_VAR_HEAD PyObject_HEAD int ob_size;
#define PyObject_HEAD_INIT(type) 1, type,
typedef unsigned int size_t;
typedef struct {
    unsigned char reserved_00[10];
    unsigned char error;
    unsigned char reserved_0b[25];
    unsigned char *buffer_ptr;
    unsigned int buffer_len;
    unsigned char reserved_2c[36];
} FILE;
typedef struct _object {
	PyObject_HEAD
} PyObject;
typedef struct {
	PyObject_VAR_HEAD
} PyVarObject;
typedef PyObject * (*unaryfunc)(PyObject *);
typedef PyObject * (*binaryfunc)(PyObject *, PyObject *);
typedef PyObject * (*ternaryfunc)(PyObject *, PyObject *, PyObject *);
typedef int (*inquiry)(PyObject *);
typedef int (*coercion)(PyObject **, PyObject **);
typedef PyObject *(*intargfunc)(PyObject *, int);
typedef PyObject *(*intintargfunc)(PyObject *, int, int);
typedef int(*intobjargproc)(PyObject *, int, PyObject *);
typedef int(*intintobjargproc)(PyObject *, int, int, PyObject *);
typedef int(*objobjargproc)(PyObject *, PyObject *, PyObject *);
typedef int (*getreadbufferproc)(PyObject *, int, void **);
typedef int (*getwritebufferproc)(PyObject *, int, void **);
typedef int (*getsegcountproc)(PyObject *, int *);
typedef int (*getcharbufferproc)(PyObject *, int, const char **);
typedef int (*objobjproc)(PyObject *, PyObject *);
typedef int (*visitproc)(PyObject *, void *);
typedef int (*traverseproc)(PyObject *, visitproc, void *);
typedef struct {
	binaryfunc nb_add;
	binaryfunc nb_subtract;
	binaryfunc nb_multiply;
	binaryfunc nb_divide;
	binaryfunc nb_remainder;
	binaryfunc nb_divmod;
	ternaryfunc nb_power;
	unaryfunc nb_negative;
	unaryfunc nb_positive;
	unaryfunc nb_absolute;
	inquiry nb_nonzero;
	unaryfunc nb_invert;
	binaryfunc nb_lshift;
	binaryfunc nb_rshift;
	binaryfunc nb_and;
	binaryfunc nb_xor;
	binaryfunc nb_or;
	coercion nb_coerce;
	unaryfunc nb_int;
	unaryfunc nb_long;
	unaryfunc nb_float;
	unaryfunc nb_oct;
	unaryfunc nb_hex;
	binaryfunc nb_inplace_add;
	binaryfunc nb_inplace_subtract;
	binaryfunc nb_inplace_multiply;
	binaryfunc nb_inplace_divide;
	binaryfunc nb_inplace_remainder;
	ternaryfunc nb_inplace_power;
	binaryfunc nb_inplace_lshift;
	binaryfunc nb_inplace_rshift;
	binaryfunc nb_inplace_and;
	binaryfunc nb_inplace_xor;
	binaryfunc nb_inplace_or;
} PyNumberMethods;
typedef struct {
	inquiry sq_length;
	binaryfunc sq_concat;
	intargfunc sq_repeat;
	intargfunc sq_item;
	intintargfunc sq_slice;
	intobjargproc sq_ass_item;
	intintobjargproc sq_ass_slice;
	objobjproc sq_contains;
	binaryfunc sq_inplace_concat;
	intargfunc sq_inplace_repeat;
} PySequenceMethods;
typedef struct {
	inquiry mp_length;
	binaryfunc mp_subscript;
	objobjargproc mp_ass_subscript;
} PyMappingMethods;
typedef struct {
	getreadbufferproc bf_getreadbuffer;
	getwritebufferproc bf_getwritebuffer;
	getsegcountproc bf_getsegcount;
	getcharbufferproc bf_getcharbuffer;
} PyBufferProcs;
typedef void (*destructor)(PyObject *);
typedef int (*printfunc)(PyObject *, FILE *, int);
typedef PyObject *(*getattrfunc)(PyObject *, char *);
typedef PyObject *(*getattrofunc)(PyObject *, PyObject *);
typedef int (*setattrfunc)(PyObject *, char *, PyObject *);
typedef int (*setattrofunc)(PyObject *, PyObject *, PyObject *);
typedef int (*cmpfunc)(PyObject *, PyObject *);
typedef PyObject *(*reprfunc)(PyObject *);
typedef long (*hashfunc)(PyObject *);
typedef PyObject *(*richcmpfunc) (PyObject *, PyObject *, int);
typedef struct _typeobject {
	PyObject_VAR_HEAD
	char *tp_name; 
	int tp_basicsize, tp_itemsize; 
	destructor tp_dealloc;
	printfunc tp_print;
	getattrfunc tp_getattr;
	setattrfunc tp_setattr;
	cmpfunc tp_compare;
	reprfunc tp_repr;
	PyNumberMethods *tp_as_number;
	PySequenceMethods *tp_as_sequence;
	PyMappingMethods *tp_as_mapping;
	hashfunc tp_hash;
	ternaryfunc tp_call;
	reprfunc tp_str;
	getattrofunc tp_getattro;
	setattrofunc tp_setattro;
	PyBufferProcs *tp_as_buffer;
	long tp_flags;
	char *tp_doc; 
	traverseproc tp_traverse;
	inquiry tp_clear;
	richcmpfunc tp_richcompare;
	long tp_weaklistoffset;
#ifdef COUNT_ALLOCS
	int tp_alloc;
	int tp_free;
	int tp_maxalloc;
	struct _typeobject *tp_next;
#endif
} PyTypeObject;



#define Py_INCREF(op) ((op)->ob_refcnt++)
#define Py_DECREF(op) if (--(op)->ob_refcnt != 0) ; else (*(op)->ob_type->tp_dealloc)((PyObject *)(op))
#define Py_XDECREF(op) if ((op) == NULL) ; else Py_DECREF(op)
#define Py_None (&_Py_NoneStruct)
#define PyInt_Check(op) ((op)->ob_type == &PyInt_Type)
#define PyLong_Check(op) ((op)->ob_type == &PyLong_Type)
#define PyFile_Check(op) ((op)->ob_type == &PyFile_Type)
#define PyList_Check(op) ((op)->ob_type == &PyList_Type)
#define PyString_Check(op) ((op)->ob_type == &PyString_Type)
#define PyObject_MALLOC(n) malloc(n)
#define PyObject_DEL(p) free(p)
#define PyObject_NEW(type,t) ((type *)PyObject_Init((PyObject *)PyObject_MALLOC((t)->tp_basicsize),t))
#define Py_BEGIN_ALLOW_THREADS {
#define Py_END_ALLOW_THREADS }
#define Py_BLOCK_THREADS
#define Py_PRINT_RAW 1
#define assert(x) ((void)0)
#define PyArg_NoArgs(v) PyArg_Parse(v, "")
#define METH_VARARGS 1
#define METH_OLDARGS 0
#define HAVE_SETVBUF
#define DONT_HAVE_SYS_TYPES_H
#define DONT_HAVE_ERRNO_H
#define INT_MAX 2147483647
#define SIZEOF_INT 4
#define SIZEOF_FPOS_T 4
#define BUFSIZ 4096
#define _IONBF 0
#define _IOLBF 1
#define _IOFBF 2
#define EOF (-1)
#define SEEK_SET 0
#define SEEK_CUR 1
#define SEEK_END 2
#define offsetof(type,member) ((int)&((type *)0)->member)
#define T_INT 1
#define T_OBJECT 6
#define RO 1
#define ferror(fp) ((fp)->error)
#define getc(fp) (fwide(fp, -1) >= 0 ? EOF : ((fp)->buffer_len-- ? *(fp)->buffer_ptr++ : __getc(fp)))
typedef long off_t;
typedef struct { PyObject_VAR_HEAD long ob_shash; PyObject *ob_sinterned; char ob_sval[1]; } PyStringObject;
typedef struct { PyObject_VAR_HEAD PyObject **ob_item; } PyListObject;
typedef PyObject *(*PyCFunction)(PyObject *, PyObject *);
typedef struct PyMethodDef { char *ml_name; PyCFunction ml_meth; int ml_flags; char *ml_doc; } PyMethodDef;
struct memberlist { char *name; int type; int offset; int readonly; };
#define PyString_AS_STRING(op) (((PyStringObject *)(op))->ob_sval)
#define PyString_GET_SIZE(op) (((PyStringObject *)(op))->ob_size)
#define PyList_GET_SIZE(op) (((PyListObject *)(op))->ob_size)
#define PyList_GET_ITEM(op,i) (((PyListObject *)(op))->ob_item[i])
#define PyList_SET_ITEM(op,i,v) (((PyListObject *)(op))->ob_item[i] = (v))
extern PyTypeObject PyType_Type, PyList_Type, PyString_Type, PyInt_Type, PyLong_Type, PyFile_Type;
extern PyObject _Py_NoneStruct;
extern PyObject *PyExc_TypeError, *PyExc_ValueError, *PyExc_IOError, *PyExc_OverflowError, *PyExc_SystemError, *PyExc_IndexError, *PyExc_AttributeError, *PyExc_EOFError;
extern int errno;
extern void *malloc(size_t);
extern void free(void *);
extern void *memset(void *, int, size_t);
extern void *memcpy(void *, const void *, size_t);
extern void *memmove(void *, const void *, size_t);
extern void *memchr(const void *, int, size_t);
extern char *strchr(const char *, int);
extern int strcmp(const char *, const char *);
extern PyObject *PyObject_Init(PyObject *, PyTypeObject *);
extern void PyErr_SetString(PyObject *, const char *);
extern PyObject *PyErr_Format(PyObject *, const char *, ...);
extern void _PyErr_BadInternalCall(const char *, int);
#define PyErr_BadInternalCall() _PyErr_BadInternalCall(__FILE__, __LINE__)
extern PyObject *PyErr_Occurred(void);
extern int PyErr_CheckSignals(void);
extern int PyErr_ExceptionMatches(PyObject *);
extern PyObject *PyErr_SetFromErrno(PyObject *);
extern PyObject *PyErr_SetFromErrnoWithFilename(PyObject *, const char *);
extern void PyErr_Clear(void);
extern PyObject *PyString_FromString(const char *);
extern PyObject *PyString_FromStringAndSize(const char *, int);
extern void PyString_Concat(PyObject **, PyObject *);
extern char *PyString_AsString(PyObject *);
extern int _PyString_Resize(PyObject **, int);
extern PyObject *PyInt_FromLong(long);
extern long PyInt_AsLong(PyObject *);
extern long PyLong_AsLong(PyObject *);
extern PyObject *PyList_New(int);
extern int PyList_SetItem(PyObject *, int, PyObject *);
extern int PyList_Append(PyObject *, PyObject *);
extern PyObject *PyList_GetSlice(PyObject *, int, int);
extern int PyArg_Parse(PyObject *, const char *, ...);
extern int PyArg_ParseTuple(PyObject *, const char *, ...);
extern PyObject *Py_FindMethod(PyMethodDef *, PyObject *, char *);
extern PyObject *Py_BuildValue(const char *, ...);
extern int PyObject_Print(PyObject *, FILE *, int);
extern PyObject *PyObject_Repr(PyObject *);
extern PyObject *PyObject_Str(PyObject *);
extern PyObject *PyObject_GetAttrString(PyObject *, const char *);
extern int PyObject_SetAttrString(PyObject *, const char *, PyObject *);
extern PyObject *PyObject_CallFunction(PyObject *, const char *, ...);
extern int PyObject_AsReadBuffer(PyObject *, const void **, int *);
extern int PyObject_AsCharBuffer(PyObject *, const char **, int *);
extern PyObject *PyImport_ImportModule(const char *);
extern PyObject *PyEval_CallObjectWithKeywords(PyObject *, PyObject *, PyObject *);
#define PyEval_CallObject(op,args) PyEval_CallObjectWithKeywords(op,args,NULL)
extern int PySequence_Check(PyObject *);
extern PyObject *PySequence_GetItem(PyObject *, int);
extern PyObject *PyMember_Get(char *, struct memberlist *, const char *);
extern int PyMember_Set(char *, struct memberlist *, const char *, PyObject *);
extern int sprintf(char *, const char *, ...);
extern int fputs(const char *, FILE *);
extern FILE *fopen(const char *, const char *);
extern int fseek(FILE *, long, int);
extern long ftell(FILE *);
extern int fflush(FILE *);
extern void clearerr(FILE *);
extern int fileno(FILE *);
extern int isatty(int);
extern int setvbuf(FILE *, char *, int, size_t);
extern size_t fread(void *, size_t, size_t, FILE *);
extern size_t fwrite(const void *, size_t, size_t, FILE *);
extern char *fgets(char *, int, FILE *);
extern int __getc(FILE *);
extern int fwide(FILE *, int);


#define DL_EXPORT(t) t
#define SIGABRT 1
#define SIGFPE 2
#define SIGILL 3
#define SIGINT 4
#define SIGSEGV 5
#define SIGTERM 6
#define SIG_DFL ((PyOS_sighandler_t)0)
#define SIG_IGN ((PyOS_sighandler_t)1)
typedef void (*PyOS_sighandler_t)(int);
extern PyOS_sighandler_t PyOS_getsig(int), PyOS_setsig(int, PyOS_sighandler_t);
extern PyObject *PyExc_KeyboardInterrupt, *PyExc_RuntimeError;
extern void PyErr_SetNone(PyObject *);
extern int PyCallable_Check(PyObject *);
extern int Py_AddPendingCall(int (*)(void *), void *);
extern PyObject *PyEval_GetFrame(void), *_PyImport_FixupExtension(char *, char *);
extern PyObject *PyModule_GetDict(PyObject *), *PyLong_FromVoidPtr(void *);
extern PyObject *PyDict_GetItemString(PyObject *, char *);
extern int PyDict_SetItemString(PyObject *, char *, PyObject *);
extern PyObject *Py_InitModule4(char *, PyMethodDef *, char *, PyObject *, int);
#define Py_InitModule3(name,methods,doc) Py_InitModule4(name,methods,doc,NULL,1010)

#line 6 "signalmodule.c"


#ifdef MS_WIN32
#include <process.h>
#endif

#ifdef HAVE_UNISTD_H
#include <unistd.h>
#endif



#ifndef SIG_ERR
#define SIG_ERR ((PyOS_sighandler_t)(-1))
#endif

#if defined(PYOS_OS2)
#define NSIG 12
#include <process.h>
#endif

#ifndef NSIG
# if defined(_NSIG)
#  define NSIG _NSIG		/* For BSD/SysV */
# elif defined(_SIGMAX)
#  define NSIG (_SIGMAX + 1)	/* For QNX */
# elif defined(SIGMAX)
#  define NSIG (SIGMAX + 1)	/* For djgpp */
# else
#  define NSIG 64		/* Use a reasonable default value */
# endif
#endif


/*
   NOTES ON THE INTERACTION BETWEEN SIGNALS AND THREADS

   When threads are supported, we want the following semantics:

   - only the main thread can set a signal handler
   - any thread can get a signal handler
   - signals are only delivered to the main thread

   I.e. we don't support "synchronous signals" like SIGFPE (catching
   this doesn't make much sense in Python anyway) nor do we support
   signals as a means of inter-thread communication, since not all
   thread implementations support that (at least our thread library
   doesn't).

   We still have the problem that in some implementations signals
   generated by the keyboard (e.g. SIGINT) are delivered to all
   threads (e.g. SGI), while in others (e.g. Solaris) such signals are
   delivered to one random thread (an intermediate possibility would
   be to deliver it to the main thread -- POSIX?).  For now, we have
   a working implementation that works in all three cases -- the
   handler ignores signals if getpid() isn't the same as in the main
   thread.  XXX This is a hack.

   GNU pth is a user-space threading library, and as such, all threads
   run within the same process. In this case, if the currently running
   thread is not the main_thread, send the signal to the main_thread.
*/

#ifdef WITH_THREAD
#include <sys/types.h> /* For pid_t */
#include "pythread.h"
static long main_thread;
static pid_t main_pid;
#endif

static struct {
        int tripped;
        PyObject *func;
} Handlers[NSIG];

static int is_tripped = 0; /* Speed up sigcheck() when none tripped */

static PyObject *DefaultHandler;
static PyObject *IgnoreHandler;
static PyObject *IntHandler;

/* On Solaris 8, gcc will produce a warning that the function
   declaration is not a prototype. This is caused by the definition of
   SIG_DFL as (void (*)())0; the correct declaration would have been
   (void (*)(int))0. */

static PyOS_sighandler_t old_siginthandler = SIG_DFL;


static PyObject *
signal_default_int_handler(PyObject *self, PyObject *args)
{
	PyErr_SetNone(PyExc_KeyboardInterrupt);
	return NULL;
}

static char default_int_handler_doc[] =
"default_int_handler(...)\n\
\n\
The default handler for SIGINT instated by Python.\n\
It raises KeyboardInterrupt.";


static int
checksignals_witharg(void * unused)
{
	return PyErr_CheckSignals();
}

static void
signal_handler(int sig_num)
{
#ifdef WITH_THREAD
#ifdef WITH_PTH
	if (PyThread_get_thread_ident() != main_thread) {
		pth_raise(*(pth_t *) main_thread, sig_num);
		return;
	}
#endif
	/* See NOTES section above */
	if (getpid() == main_pid) {
#endif
		is_tripped++;
		Handlers[sig_num].tripped = 1;
		Py_AddPendingCall(checksignals_witharg, NULL);
#ifdef WITH_THREAD
	}
#endif
#ifdef SIGCHLD
	if (sig_num == SIGCHLD) {
		/* To avoid infinite recursion, this signal remains
		   reset until explicit re-instated.
		   Don't clear the 'func' field as it is our pointer
		   to the Python handler... */
		return;
	}
#endif
#ifdef HAVE_SIGINTERRUPT
	siginterrupt(sig_num, 1);
#endif
	PyOS_setsig(sig_num, signal_handler);
}


#ifdef HAVE_ALARM
static PyObject *
signal_alarm(PyObject *self, PyObject *args)
{
	int t;
	if (!PyArg_Parse(args, "i", &t))
		return NULL;
	/* alarm() returns the number of seconds remaining */
	return PyInt_FromLong(alarm(t));
}

static char alarm_doc[] =
"alarm(seconds)\n\
\n\
Arrange for SIGALRM to arrive after the given number of seconds.";
#endif

#ifdef HAVE_PAUSE
static PyObject *
signal_pause(PyObject *self, PyObject *args)
{
	if (!PyArg_NoArgs(args))
		return NULL;

	Py_BEGIN_ALLOW_THREADS
	(void)pause();
	Py_END_ALLOW_THREADS
	/* make sure that any exceptions that got raised are propagated
	 * back into Python
	 */
	if (PyErr_CheckSignals())
		return NULL;

	Py_INCREF(Py_None);
	return Py_None;
}
static char pause_doc[] =
"pause()\n\
\n\
Wait until a signal arrives.";

#endif


static PyObject *
signal_signal(PyObject *self, PyObject *args)
{
	PyObject *obj;
	int sig_num;
	PyObject *old_handler;
	void (*func)(int);
	if (!PyArg_Parse(args, "(iO)", &sig_num, &obj))
		return NULL;
#ifdef WITH_THREAD
	if (PyThread_get_thread_ident() != main_thread) {
		PyErr_SetString(PyExc_ValueError,
				"signal only works in main thread");
		return NULL;
	}
#endif
	if (sig_num < 1 || sig_num >= NSIG) {
		PyErr_SetString(PyExc_ValueError,
				"signal number out of range");
		return NULL;
	}
	if (obj == IgnoreHandler)
		func = SIG_IGN;
	else if (obj == DefaultHandler)
		func = SIG_DFL;
	else if (!PyCallable_Check(obj)) {
		PyErr_SetString(PyExc_TypeError,
"signal handler must be signal.SIG_IGN, signal.SIG_DFL, or a callable object");
		return NULL;
	}
	else
		func = signal_handler;
#ifdef HAVE_SIGINTERRUPT
	siginterrupt(sig_num, 1);
#endif
	if (PyOS_setsig(sig_num, func) == SIG_ERR) {
		PyErr_SetFromErrno(PyExc_RuntimeError);
		return NULL;
	}
	old_handler = Handlers[sig_num].func;
	Handlers[sig_num].tripped = 0;
	Py_INCREF(obj);
	Handlers[sig_num].func = obj;
	return old_handler;
}

static char signal_doc[] =
"signal(sig, action) -> action\n\
\n\
Set the action for the given signal.  The action can be SIG_DFL,\n\
SIG_IGN, or a callable Python object.  The previous action is\n\
returned.  See getsignal() for possible return values.\n\
\n\
*** IMPORTANT NOTICE ***\n\
A signal handler function is called with two arguments:\n\
the first is the signal number, the second is the interrupted stack frame.";


static PyObject *
signal_getsignal(PyObject *self, PyObject *args)
{
	int sig_num;
	PyObject *old_handler;
	if (!PyArg_Parse(args, "i", &sig_num))
		return NULL;
	if (sig_num < 1 || sig_num >= NSIG) {
		PyErr_SetString(PyExc_ValueError,
				"signal number out of range");
		return NULL;
	}
	old_handler = Handlers[sig_num].func;
	Py_INCREF(old_handler);
	return old_handler;
}

static char getsignal_doc[] =
"getsignal(sig) -> action\n\
\n\
Return the current action for the given signal.  The return value can be:\n\
SIG_IGN -- if the signal is being ignored\n\
SIG_DFL -- if the default action for the signal is in effect\n\
None -- if an unknown handler is in effect\n\
anything else -- the callable Python object used as a handler\n\
";


/* List of functions defined in the module */
static PyMethodDef signal_methods[] = {
#ifdef HAVE_ALARM
	{"alarm",	        signal_alarm, METH_OLDARGS, alarm_doc},
#endif
	{"signal",	        signal_signal, METH_OLDARGS, signal_doc},
	{"getsignal",	        signal_getsignal, METH_OLDARGS, getsignal_doc},
#ifdef HAVE_PAUSE
	{"pause",	        signal_pause, METH_OLDARGS, pause_doc},
#endif
	{"default_int_handler", signal_default_int_handler, 
	 METH_OLDARGS, default_int_handler_doc},
	{NULL,			NULL}		/* sentinel */
};


static char module_doc[] =
"This module provides mechanisms to use signal handlers in Python.\n\
\n\
Functions:\n\
\n\
alarm() -- cause SIGALRM after a specified time [Unix only]\n\
signal() -- set the action for a given signal\n\
getsignal() -- get the signal action for a given signal\n\
pause() -- wait until a signal arrives [Unix only]\n\
default_int_handler() -- default SIGINT handler\n\
\n\
Constants:\n\
\n\
SIG_DFL -- used to refer to the system default handler\n\
SIG_IGN -- used to ignore the signal\n\
NSIG -- number of defined signals\n\
\n\
SIGINT, SIGTERM, etc. -- signal numbers\n\
\n\
*** IMPORTANT NOTICE ***\n\
A signal handler function is called with two arguments:\n\
the first is the signal number, the second is the interrupted stack frame.";

DL_EXPORT(void)
initsignal(void)
{
	PyObject *m, *d, *x;
	int i;

#ifdef WITH_THREAD
	main_thread = PyThread_get_thread_ident();
	main_pid = getpid();
#endif

	/* Create the module and add the functions */
	m = Py_InitModule3("signal", signal_methods, module_doc);

	/* Add some symbolic constants to the module */
	d = PyModule_GetDict(m);

	x = DefaultHandler = PyLong_FromVoidPtr((void *)SIG_DFL);
        if (!x || PyDict_SetItemString(d, "SIG_DFL", x) < 0)
                goto finally;

	x = IgnoreHandler = PyLong_FromVoidPtr((void *)SIG_IGN);
        if (!x || PyDict_SetItemString(d, "SIG_IGN", x) < 0)
                goto finally;

        x = PyInt_FromLong((long)NSIG);
        if (!x || PyDict_SetItemString(d, "NSIG", x) < 0)
                goto finally;
        Py_DECREF(x);

	x = IntHandler = PyDict_GetItemString(d, "default_int_handler");
        if (!x)
                goto finally;
	Py_INCREF(IntHandler);

	Handlers[0].tripped = 0;
	for (i = 1; i < NSIG; i++) {
		void (*t)(int);
		t = PyOS_getsig(i);
		Handlers[i].tripped = 0;
		if (t == SIG_DFL)
			Handlers[i].func = DefaultHandler;
		else if (t == SIG_IGN)
			Handlers[i].func = IgnoreHandler;
		else
			Handlers[i].func = Py_None; /* None of our business */
		Py_INCREF(Handlers[i].func);
	}
	if (Handlers[SIGINT].func == DefaultHandler) {
		/* Install default int handler */
		Py_INCREF(IntHandler);
		Py_DECREF(Handlers[SIGINT].func);
		Handlers[SIGINT].func = IntHandler;
		old_siginthandler = PyOS_setsig(SIGINT, &signal_handler);
	}

#ifdef SIGHUP
	x = PyInt_FromLong(SIGHUP);
	PyDict_SetItemString(d, "SIGHUP", x);
        Py_XDECREF(x);
#endif
#ifdef SIGINT
	x = PyInt_FromLong(SIGINT);
	PyDict_SetItemString(d, "SIGINT", x);
        Py_XDECREF(x);
#endif
#ifdef SIGQUIT
	x = PyInt_FromLong(SIGQUIT);
	PyDict_SetItemString(d, "SIGQUIT", x);
        Py_XDECREF(x);
#endif
#ifdef SIGILL
	x = PyInt_FromLong(SIGILL);
	PyDict_SetItemString(d, "SIGILL", x);
        Py_XDECREF(x);
#endif
#ifdef SIGTRAP
	x = PyInt_FromLong(SIGTRAP);
	PyDict_SetItemString(d, "SIGTRAP", x);
        Py_XDECREF(x);
#endif
#ifdef SIGIOT
	x = PyInt_FromLong(SIGIOT);
	PyDict_SetItemString(d, "SIGIOT", x);
        Py_XDECREF(x);
#endif
#ifdef SIGABRT
	x = PyInt_FromLong(SIGABRT);
	PyDict_SetItemString(d, "SIGABRT", x);
        Py_XDECREF(x);
#endif
#ifdef SIGEMT
	x = PyInt_FromLong(SIGEMT);
	PyDict_SetItemString(d, "SIGEMT", x);
        Py_XDECREF(x);
#endif
#ifdef SIGFPE
	x = PyInt_FromLong(SIGFPE);
	PyDict_SetItemString(d, "SIGFPE", x);
        Py_XDECREF(x);
#endif
#ifdef SIGKILL
	x = PyInt_FromLong(SIGKILL);
	PyDict_SetItemString(d, "SIGKILL", x);
        Py_XDECREF(x);
#endif
#ifdef SIGBUS
	x = PyInt_FromLong(SIGBUS);
	PyDict_SetItemString(d, "SIGBUS", x);
        Py_XDECREF(x);
#endif
#ifdef SIGSEGV
	x = PyInt_FromLong(SIGSEGV);
	PyDict_SetItemString(d, "SIGSEGV", x);
        Py_XDECREF(x);
#endif
#ifdef SIGSYS
	x = PyInt_FromLong(SIGSYS);
	PyDict_SetItemString(d, "SIGSYS", x);
        Py_XDECREF(x);
#endif
#ifdef SIGPIPE
	x = PyInt_FromLong(SIGPIPE);
	PyDict_SetItemString(d, "SIGPIPE", x);
        Py_XDECREF(x);
#endif
#ifdef SIGALRM
	x = PyInt_FromLong(SIGALRM);
	PyDict_SetItemString(d, "SIGALRM", x);
        Py_XDECREF(x);
#endif
#ifdef SIGTERM
	x = PyInt_FromLong(SIGTERM);
	PyDict_SetItemString(d, "SIGTERM", x);
        Py_XDECREF(x);
#endif
#ifdef SIGUSR1
	x = PyInt_FromLong(SIGUSR1);
	PyDict_SetItemString(d, "SIGUSR1", x);
        Py_XDECREF(x);
#endif
#ifdef SIGUSR2
	x = PyInt_FromLong(SIGUSR2);
	PyDict_SetItemString(d, "SIGUSR2", x);
        Py_XDECREF(x);
#endif
#ifdef SIGCLD
	x = PyInt_FromLong(SIGCLD);
	PyDict_SetItemString(d, "SIGCLD", x);
        Py_XDECREF(x);
#endif
#ifdef SIGCHLD
	x = PyInt_FromLong(SIGCHLD);
	PyDict_SetItemString(d, "SIGCHLD", x);
        Py_XDECREF(x);
#endif
#ifdef SIGPWR
	x = PyInt_FromLong(SIGPWR);
	PyDict_SetItemString(d, "SIGPWR", x);
        Py_XDECREF(x);
#endif
#ifdef SIGIO
	x = PyInt_FromLong(SIGIO);
	PyDict_SetItemString(d, "SIGIO", x);
        Py_XDECREF(x);
#endif
#ifdef SIGURG
	x = PyInt_FromLong(SIGURG);
	PyDict_SetItemString(d, "SIGURG", x);
        Py_XDECREF(x);
#endif
#ifdef SIGWINCH
	x = PyInt_FromLong(SIGWINCH);
	PyDict_SetItemString(d, "SIGWINCH", x);
        Py_XDECREF(x);
#endif
#ifdef SIGPOLL
	x = PyInt_FromLong(SIGPOLL);
	PyDict_SetItemString(d, "SIGPOLL", x);
        Py_XDECREF(x);
#endif
#ifdef SIGSTOP
	x = PyInt_FromLong(SIGSTOP);
	PyDict_SetItemString(d, "SIGSTOP", x);
        Py_XDECREF(x);
#endif
#ifdef SIGTSTP
	x = PyInt_FromLong(SIGTSTP);
	PyDict_SetItemString(d, "SIGTSTP", x);
        Py_XDECREF(x);
#endif
#ifdef SIGCONT
	x = PyInt_FromLong(SIGCONT);
	PyDict_SetItemString(d, "SIGCONT", x);
        Py_XDECREF(x);
#endif
#ifdef SIGTTIN
	x = PyInt_FromLong(SIGTTIN);
	PyDict_SetItemString(d, "SIGTTIN", x);
        Py_XDECREF(x);
#endif
#ifdef SIGTTOU
	x = PyInt_FromLong(SIGTTOU);
	PyDict_SetItemString(d, "SIGTTOU", x);
        Py_XDECREF(x);
#endif
#ifdef SIGVTALRM
	x = PyInt_FromLong(SIGVTALRM);
	PyDict_SetItemString(d, "SIGVTALRM", x);
        Py_XDECREF(x);
#endif
#ifdef SIGPROF
	x = PyInt_FromLong(SIGPROF);
	PyDict_SetItemString(d, "SIGPROF", x);
        Py_XDECREF(x);
#endif
#ifdef SIGXCPU
	x = PyInt_FromLong(SIGXCPU);
	PyDict_SetItemString(d, "SIGXCPU", x);
        Py_XDECREF(x);
#endif
#ifdef SIGXFSZ
	x = PyInt_FromLong(SIGXFSZ);
	PyDict_SetItemString(d, "SIGXFSZ", x);
        Py_XDECREF(x);
#endif
        if (!PyErr_Occurred())
                return;

	/* Check for errors */
  finally:
        return;
}

static void
finisignal(void)
{
	int i;
	PyObject *func;

	PyOS_setsig(SIGINT, old_siginthandler);
	old_siginthandler = SIG_DFL;

	for (i = 1; i < NSIG; i++) {
		func = Handlers[i].func;
		Handlers[i].tripped = 0;
		Handlers[i].func = NULL;
		if (i != SIGINT && func != NULL && func != Py_None &&
		    func != DefaultHandler && func != IgnoreHandler)
			PyOS_setsig(i, SIG_DFL);
		Py_XDECREF(func);
	}

	Py_XDECREF(IntHandler);
	IntHandler = NULL;
	Py_XDECREF(DefaultHandler);
	DefaultHandler = NULL;
	Py_XDECREF(IgnoreHandler);
	IgnoreHandler = NULL;
}


/* Declared in pyerrors.h */
int
PyErr_CheckSignals(void)
{
	int i;
	PyObject *f;

	if (!is_tripped)
		return 0;
#ifdef WITH_THREAD
	if (PyThread_get_thread_ident() != main_thread)
		return 0;
#endif
	if (!(f = PyEval_GetFrame()))
		f = Py_None;
	
	for (i = 1; i < NSIG; i++) {
		if (Handlers[i].tripped) {
			PyObject *result = NULL;
			PyObject *arglist = Py_BuildValue("(iO)", i, f);
			Handlers[i].tripped = 0;

			if (arglist) {
				result = PyEval_CallObject(Handlers[i].func,
							   arglist);
				Py_DECREF(arglist);
			}
			if (!result)
				return -1;

			Py_DECREF(result);
		}
	}
	is_tripped = 0;
	return 0;
}


/* Replacements for intrcheck.c functionality
 * Declared in pyerrors.h
 */
static inline void
PyErr_SetInterrupt(void)
{
	is_tripped++;
	Handlers[SIGINT].tripped = 1;
	Py_AddPendingCall((int (*)(void *))PyErr_CheckSignals, NULL);
}

void
PyOS_InitInterrupts(void)
{
	initsignal();
	_PyImport_FixupExtension("signal", "signal");
}

void
PyOS_FiniInterrupts(void)
{
	finisignal();
}

int
PyOS_InterruptOccurred(void)
{
	if (Handlers[SIGINT].tripped) {
#ifdef WITH_THREAD
		if (PyThread_get_thread_ident() != main_thread)
			return 0;
#endif
		Handlers[SIGINT].tripped = 0;
		return 1;
	}
	return 0;
}

static inline void
PyOS_AfterFork(void)
{
#ifdef WITH_THREAD
	PyEval_ReInitThreads();
	main_thread = PyThread_get_thread_ident();
	main_pid = getpid();
#endif
}
