/* Adapted from CPython v2.1 Python/traceback.c and its frame ABI headers.
 * License: reference/cpython-2.1/LICENSE. */
#include "object.h"

typedef void (*destructor)(PyObject *);
typedef PyObject *(*getattrfunc)(PyObject *, char *);
typedef int (*setattrfunc)(PyObject *, char *, PyObject *);
typedef PyObject *(*reprfunc)(PyObject *);
typedef int (*cmpfunc)(PyObject *, PyObject *);
typedef int (*inquiry)(PyObject *);
typedef PyObject *(*binaryfunc)(PyObject *, PyObject *);
typedef PyObject *(*intargfunc)(PyObject *, int);
typedef PyObject *(*intintargfunc)(PyObject *, int, int);
typedef int (*objobjproc)(PyObject *, PyObject *);
typedef PyObject *(*PyCFunction)(PyObject *, PyObject *);
typedef struct { char *ml_name; PyCFunction ml_meth; int ml_flags; char *ml_doc; } PyMethodDef;
struct memberlist { char *name; int type; int offset; int readonly; };
typedef struct {
    inquiry sq_length; binaryfunc sq_concat; intargfunc sq_repeat, sq_item;
    intintargfunc sq_slice; void *sq_ass_item, *sq_ass_slice;
    objobjproc sq_contains; void *sq_inplace_concat, *sq_inplace_repeat;
} PySequenceMethods;
struct _typeobject {
    PyObject_VAR_HEAD
    char *tp_name; int tp_basicsize, tp_itemsize;
    destructor tp_dealloc; void *tp_print; getattrfunc tp_getattr; setattrfunc tp_setattr;
    cmpfunc tp_compare; reprfunc tp_repr;
    void *tp_as_number, *tp_as_sequence, *tp_as_mapping;
    void *tp_hash, *tp_call, *tp_str, *tp_getattro, *tp_setattro, *tp_as_buffer;
    long tp_flags; char *tp_doc; void *tp_traverse, *tp_clear, *tp_richcompare, *tp_weaklistoffset;
};
#define PyObject_HEAD_INIT(type) 1, type,
#define Py_TPFLAGS_DEFAULT 0x6b
#define METH_VARARGS 1
#define T_LONG 2
#define RO 1
#define offsetof(t, m) ((int)&((t *)0)->m)
#define INT_MAX 2147483647
#define PyInt_AS_LONG(o) (((PyIntObject *)(o))->ob_ival)
typedef struct { PyObject_HEAD long ob_ival; } PyIntObject;
#undef Py_DECREF
#define Py_DECREF(op) if (--(op)->ob_refcnt != 0) ; else (*(op)->ob_type->tp_dealloc)((PyObject *)(op))
#define PyObject_NEW(t, tp) ((t *)PyObject_Init((PyObject *)malloc((tp)->tp_basicsize), (tp)))
#define PyObject_DEL free
typedef struct { PyObject_VAR_HEAD PyObject *ob_ref; } PyCellObject;
typedef int (*visitproc)(PyObject *, void *);
typedef int (*traverseproc)(PyObject *, visitproc, void *);
#define PyCell_Check(op) ((op)->ob_type == &PyCell_Type)
#define PyCell_GET(op) (((PyCellObject *)(op))->ob_ref)
#define PyCell_SET(op, v) (((PyCellObject *)(op))->ob_ref = v)
#define Py_XINCREF(op) if ((op) == NULL) ; else Py_INCREF(op)
#define Py_XDECREF(op) if ((op) == NULL) ; else Py_DECREF(op)
#define PyObject_New(type, tp) ((type *)_PyObject_New(tp))
#define PyObject_Del(op) _PyObject_Del((PyObject *)(op))
#define PyObject_GC_Init(op)
#define PyObject_GC_Fini(op)
#define PyGC_HEAD_SIZE 0
#define Py_TPFLAGS_GC 0
#define PyErr_BadInternalCall() _PyErr_BadInternalCall(__FILE__, __LINE__)
extern PyTypeObject PyCell_Type, PyType_Type;
extern PyObject *_PyObject_New(PyTypeObject *);
extern void _PyObject_Del(PyObject *);
extern int PyObject_Compare(PyObject *, PyObject *);
extern PyObject *PyString_FromString(const char *);
extern int sprintf(char *, const char *, ...);
extern void _PyErr_BadInternalCall(const char *, int);


/* Bytecode object */
typedef struct {
    PyObject_HEAD
    int co_argcount;		/* #arguments, except *args */
    int co_nlocals;		/* #local variables */
    int co_stacksize;		/* #entries needed for evaluation stack */
    int co_flags;		/* CO_..., see below */
    PyObject *co_code;		/* instruction opcodes */
    PyObject *co_consts;	/* list (constants used) */
    PyObject *co_names;		/* list of strings (names used) */
    PyObject *co_varnames;	/* tuple of strings (local variable names) */
    PyObject *co_freevars;	/* tuple of strings (free variable names) */
    PyObject *co_cellvars;      /* tuple of strings (cell variable names) */
    /* The rest doesn't count for hash/cmp */
    PyObject *co_filename;	/* string (where it was loaded from) */
    PyObject *co_name;		/* string (name, for reference) */
    int co_firstlineno;		/* first source line number */
    PyObject *co_lnotab;	/* string (encoding addr<->lineno mapping) */
} PyCodeObject;

/* Masks for co_flags above */
#define CO_OPTIMIZED	0x0001
#define CO_NEWLOCALS	0x0002
#define CO_VARARGS	0x0004
#define CO_VARKEYWORDS	0x0008
#define CO_NESTED       0x0010

extern PyTypeObject PyCode_Type;

#define PyCode_Check(op) ((op)->ob_type == &PyCode_Type)

#define CO_MAXBLOCKS 20 /* Max static block nesting within a function */


/* State shared between threads */

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



typedef struct {
    int b_type;			/* what kind of block this is */
    int b_handler;		/* where to jump to find handler */
    int b_level;		/* value stack level to pop to */
} PyTryBlock;

typedef struct _frame {
    PyObject_HEAD
    struct _frame *f_back;	/* previous frame, or NULL */
    PyCodeObject *f_code;	/* code segment */
    PyObject *f_builtins;	/* builtin symbol table (PyDictObject) */
    PyObject *f_globals;	/* global symbol table (PyDictObject) */
    PyObject *f_locals;		/* local symbol table (PyDictObject) */
    PyObject **f_valuestack;	/* points after the last local */
    PyObject *f_trace;		/* Trace function */
    PyObject *f_exc_type, *f_exc_value, *f_exc_traceback;
    PyThreadState *f_tstate;
    int f_lasti;		/* Last instruction if called */
    int f_lineno;		/* Current line number */
    int f_restricted;		/* Flag set if restricted operations
				   in this scope */
    int f_iblock;		/* index in f_blockstack */
    PyTryBlock f_blockstack[CO_MAXBLOCKS]; /* for try and loop blocks */
    int f_size;                 /* size of localsplus */
    int f_nlocals;		/* number of locals */
    int f_ncells;
    int f_nfreevars;
    int f_stacksize;		/* size of value stack */
    PyObject *f_localsplus[1];	/* locals+stack, dynamically sized */
} PyFrameObject;



#define PyTrash_UNWIND_LEVEL 50

#define Py_TRASHCAN_SAFE_BEGIN(op) \
	{ \
		++_PyTrash_delete_nesting; \
		if (_PyTrash_delete_nesting < PyTrash_UNWIND_LEVEL) { \

#define Py_TRASHCAN_SAFE_END(op) \
		;} \
		else \
			_PyTrash_deposit_object((PyObject*)op);\
		--_PyTrash_delete_nesting; \
		if (_PyTrash_delete_later && _PyTrash_delete_nesting <= 0) \
			_PyTrash_destroy_chain(); \
	} \

extern void _PyTrash_deposit_object(PyObject*);
extern void _PyTrash_destroy_chain(void);

extern int _PyTrash_delete_nesting;
extern PyObject * _PyTrash_delete_later;


#define T_OBJECT 6
#define T_INT 1
#define PyFrame_Check(o) ((o)->ob_type == &PyFrame_Type)
#define PyDict_Check(o) ((o)->ob_type == &PyDict_Type)
#define PyModule_Check(o) ((o)->ob_type == &PyModule_Type)
#define PyTuple_Check(o) ((o)->ob_type == &PyTuple_Type)
#define PyTuple_GET_SIZE(o) (((PyVarObject *)(o))->ob_size)
#define PyObject_MALLOC malloc
#define PyObject_REALLOC realloc
#define PyObject_INIT(o, tp) ( (o)->ob_type = (tp), (o)->ob_refcnt = 1, (o) )
#define Py_None (&_Py_NoneStruct)
extern PyTypeObject PyFrame_Type, PyDict_Type, PyModule_Type, PyTuple_Type;
extern PyObject _Py_NoneStruct;
extern void PyFrame_FastToLocals(PyFrameObject *);
extern int strcmp(const char *, const char *);
extern void *malloc(unsigned int), *realloc(void *, unsigned int);
extern void free(void *);
extern PyObject *PyMember_Get(char *, struct memberlist *, char *);
extern int PyMember_Set(char *, struct memberlist *, char *, PyObject *);
extern PyObject *PyString_InternFromString(const char *);
extern PyObject *PyDict_GetItem(PyObject *, PyObject *);
extern PyObject *PyModule_GetDict(PyObject *);
extern PyObject *PyErr_NoMemory(void), *PyDict_New(void);
extern int PyDict_SetItemString(PyObject *, const char *, PyObject *);
extern int PyDict_SetItem(PyObject *, PyObject *, PyObject *);
extern int PyDict_DelItem(PyObject *, PyObject *);
extern void Py_FatalError(const char *);
extern int PyTuple_Size(PyObject *), PyCell_Set(PyObject *, PyObject *);
extern PyObject *PyTuple_GetItem(PyObject *, int);
extern void PyErr_Clear(void), PyErr_Fetch(PyObject **, PyObject **, PyObject **);
extern void PyErr_Restore(PyObject *, PyObject *, PyObject *);


#define SEP '/'
#define MAXPATHLEN 1024
#define PyTraceBack_Check(o) ((o)->ob_type == &PyTraceBack_Type)
#define PyList_Check(o) ((o)->ob_type == &PyList_Type)
#define PyString_Check(o) ((o)->ob_type == &PyString_Type)
#define PyInt_Check(o) ((o)->ob_type == &PyInt_Type)
typedef struct FILE FILE;
typedef unsigned long size_t;
extern PyTypeObject PyTraceBack_Type, PyList_Type, PyString_Type, PyInt_Type;
extern int Py_OptimizeFlag;
extern FILE *fopen(const char *, const char *);
extern int fclose(FILE *);
extern char *fgets(char *, int, FILE *);
extern char *strrchr(const char *, int), *strchr(const char *, int), *strcpy(char *, const char *);
extern unsigned long strlen(const char *);
extern PyObject *PySys_GetObject(const char *), *PyList_GetItem(PyObject *, int);
extern int PyList_Size(PyObject *), PyString_Size(PyObject *);
extern char *PyString_AsString(PyObject *);
extern long PyInt_AsLong(PyObject *);
extern int PyErr_CheckSignals(void), PyFile_WriteString(const char *, PyObject *);
extern int PyCode_Addr2Line(PyCodeObject *, int);
extern PyObject *PyObject_Init(PyObject *, PyTypeObject *);

#line 1 "traceback.c"

/* Traceback implementation */

/* Declared by the recovered ABI above. */

/* Declared by the recovered ABI above. */
/* Declared by the recovered ABI above. */
/* Declared by the recovered ABI above. */
/* Declared by the recovered ABI above. */

typedef struct _tracebackobject {
	PyObject_HEAD
	struct _tracebackobject *tb_next;
	PyFrameObject *tb_frame;
	int tb_lasti;
	int tb_lineno;
} tracebackobject;

#define OFF(x) offsetof(tracebackobject, x)

static struct memberlist tb_memberlist[] = {
	{"tb_next",	T_OBJECT,	OFF(tb_next)},
	{"tb_frame",	T_OBJECT,	OFF(tb_frame)},
	{"tb_lasti",	T_INT,		OFF(tb_lasti)},
	{"tb_lineno",	T_INT,		OFF(tb_lineno)},
	{NULL}	/* Sentinel */
};

static PyObject *
tb_getattr(tracebackobject *tb, char *name)
{
	return PyMember_Get((char *)tb, tb_memberlist, name);
}

static void
tb_dealloc(tracebackobject *tb)
{
	Py_TRASHCAN_SAFE_BEGIN(tb)
	Py_XDECREF(tb->tb_next);
	Py_XDECREF(tb->tb_frame);
	PyObject_DEL(tb);
	Py_TRASHCAN_SAFE_END(tb)
}

#define Tracebacktype PyTraceBack_Type
#define is_tracebackobject PyTraceBack_Check

PyTypeObject Tracebacktype = {
	PyObject_HEAD_INIT(&PyType_Type)
	0,
	"traceback",
	sizeof(tracebackobject),
	0,
	(destructor)tb_dealloc, /*tp_dealloc*/
	0,		/*tp_print*/
	(getattrfunc)tb_getattr, /*tp_getattr*/
	0,		/*tp_setattr*/
	0,		/*tp_compare*/
	0,		/*tp_repr*/
	0,		/*tp_as_number*/
	0,		/*tp_as_sequence*/
	0,		/*tp_as_mapping*/
};

static inline tracebackobject *
newtracebackobject(tracebackobject *next, PyFrameObject *frame, int lasti,
		   int lineno)
{
	tracebackobject *tb;
	if ((next != NULL && !is_tracebackobject(next)) ||
			frame == NULL || !PyFrame_Check(frame)) {
		PyErr_BadInternalCall();
		return NULL;
	}
	tb = PyObject_NEW(tracebackobject, &Tracebacktype);
	if (tb != NULL) {
		Py_XINCREF(next);
		tb->tb_next = next;
		Py_XINCREF(frame);
		tb->tb_frame = frame;
		tb->tb_lasti = lasti;
		tb->tb_lineno = lineno;
	}
	return tb;
}

int
PyTraceBack_Here(PyFrameObject *frame)
{
	PyThreadState *tstate = frame->f_tstate;
	tracebackobject *oldtb = (tracebackobject *) tstate->curexc_traceback;
	tracebackobject *tb = newtracebackobject(oldtb,
				frame, frame->f_lasti, frame->f_lineno);
	if (tb == NULL)
		return -1;
	tstate->curexc_traceback = (PyObject *)tb;
	Py_XDECREF(oldtb);
	return 0;
}

static int
tb_displayline(PyObject *f, char *filename, int lineno, char *name)
{
	int err = 0;
	FILE *xfp;
	char linebuf[1000];
	int i;
	if (filename == NULL || name == NULL)
		return -1;
#ifdef MPW
	/* This is needed by MPW's File and Line commands */
#define FMT "  File \"%.900s\"; line %d # in %s\n"
#else
	/* This is needed by Emacs' compile command */
#define FMT "  File \"%.900s\", line %d, in %s\n"
#endif
	xfp = fopen(filename, "r");
	if (xfp == NULL) {
		/* Search tail of filename in sys.path before giving up */
		PyObject *path;
		char *tail = strrchr(filename, SEP);
		if (tail == NULL)
			tail = filename;
		else
			tail++;
		path = PySys_GetObject("path");
		if (path != NULL && PyList_Check(path)) {
			int npath = PyList_Size(path);
			size_t taillen = strlen(tail);
			char namebuf[MAXPATHLEN+1];
			for (i = 0; i < npath; i++) {
				PyObject *v = PyList_GetItem(path, i);
				if (v == NULL) {
					PyErr_Clear();
					break;
				}
				if (PyString_Check(v)) {
					size_t len;
					len = PyString_Size(v);
					if (len + 1 + taillen >= MAXPATHLEN)
						continue; /* Too long */
					strcpy(namebuf, PyString_AsString(v));
					if (strlen(namebuf) != len)
						continue; /* v contains '\0' */
					if (len > 0 && namebuf[len-1] != SEP)
						namebuf[len++] = SEP;
					strcpy(namebuf+len, tail);
					xfp = fopen(namebuf, "r");
					if (xfp != NULL) {
						filename = namebuf;
						break;
					}
				}
			}
		}
	}
	sprintf(linebuf, FMT, filename, lineno, name);
	err = PyFile_WriteString(linebuf, f);
	if (xfp == NULL || err != 0)
		return err;
	for (i = 0; i < lineno; i++) {
		char* pLastChar = &linebuf[sizeof(linebuf)-2];
		do {
			*pLastChar = '\0';
			if (fgets(linebuf, sizeof linebuf, xfp) == NULL)
				break;
			/* fgets read *something*; if it didn't get as
			   far as pLastChar, it must have found a newline
			   or hit the end of the file;	if pLastChar is \n,
			   it obviously found a newline; else we haven't
			   yet seen a newline, so must continue */
		} while (*pLastChar != '\0' && *pLastChar != '\n');
	}
	if (i == lineno) {
		char *p = linebuf;
		while (*p == ' ' || *p == '\t' || *p == '\014')
			p++;
		err = PyFile_WriteString("    ", f);
		if (err == 0) {
			err = PyFile_WriteString(p, f);
			if (err == 0 && strchr(p, '\n') == NULL)
				err = PyFile_WriteString("\n", f);
		}
	}
	fclose(xfp);
	return err;
}

static inline int
tb_printinternal(tracebackobject *tb, PyObject *f, int limit)
{
	int err = 0;
	int depth = 0;
	tracebackobject *tb1 = tb;
	while (tb1 != NULL) {
		depth++;
		tb1 = tb1->tb_next;
	}
	while (tb != NULL && err == 0) {
		if (depth <= limit) {
			if (Py_OptimizeFlag)
				tb->tb_lineno = PyCode_Addr2Line(
					tb->tb_frame->f_code, tb->tb_lasti);
			err = tb_displayline(f,
			    PyString_AsString(
				    tb->tb_frame->f_code->co_filename),
			    tb->tb_lineno,
			    PyString_AsString(tb->tb_frame->f_code->co_name));
		}
		depth--;
		tb = tb->tb_next;
		if (err == 0)
			err = PyErr_CheckSignals();
	}
	return err;
}

int
PyTraceBack_Print(PyObject *v, PyObject *f)
{
	int err;
	PyObject *limitv;
	int limit = 1000;
	if (v == NULL)
		return 0;
	if (!is_tracebackobject(v)) {
		PyErr_BadInternalCall();
		return -1;
	}
	limitv = PySys_GetObject("tracebacklimit");
	if (limitv && PyInt_Check(limitv)) {
		limit = PyInt_AsLong(limitv);
		if (limit <= 0)
			return 0;
	}
	err = PyFile_WriteString("Traceback (most recent call last):\n", f);
	if (!err)
		err = tb_printinternal((tracebackobject *)v, f, limit);
	return err;
}
