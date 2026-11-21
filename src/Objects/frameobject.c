/* Adapted from CPython v2.1 Objects/frameobject.c and its ABI headers.
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

#line 2 "frameobject.c"

/* Frame object implementation */

/* Declared by the recovered ABI above. */

/* Declared by the recovered ABI above. */
/* Declared by the recovered ABI above. */
/* Declared by the recovered ABI above. */
/* Declared by the recovered ABI above. */

#define OFF(x) offsetof(PyFrameObject, x)

static struct memberlist frame_memberlist[] = {
	{"f_back",	T_OBJECT,	OFF(f_back),	RO},
	{"f_code",	T_OBJECT,	OFF(f_code),	RO},
	{"f_builtins",	T_OBJECT,	OFF(f_builtins),RO},
	{"f_globals",	T_OBJECT,	OFF(f_globals),	RO},
	{"f_locals",	T_OBJECT,	OFF(f_locals),	RO},
	{"f_lasti",	T_INT,		OFF(f_lasti),	RO},
	{"f_lineno",	T_INT,		OFF(f_lineno),	RO},
	{"f_restricted",T_INT,		OFF(f_restricted),RO},
	{"f_trace",	T_OBJECT,	OFF(f_trace)},
	{"f_exc_type",	T_OBJECT,	OFF(f_exc_type)},
	{"f_exc_value",	T_OBJECT,	OFF(f_exc_value)},
	{"f_exc_traceback", T_OBJECT,	OFF(f_exc_traceback)},
	{NULL}	/* Sentinel */
};

static PyObject *
frame_getattr(PyFrameObject *f, char *name)
{
	if (strcmp(name, "f_locals") == 0)
		PyFrame_FastToLocals(f);
	return PyMember_Get((char *)f, frame_memberlist, name);
}

static int
frame_setattr(PyFrameObject *f, char *name, PyObject *value)
{
	return PyMember_Set((char *)f, frame_memberlist, name, value);
}

/* Stack frames are allocated and deallocated at a considerable rate.
   In an attempt to improve the speed of function calls, we maintain a
   separate free list of stack frames (just like integers are
   allocated in a special way -- see intobject.c).  When a stack frame
   is on the free list, only the following members have a meaning:
	ob_type		== &Frametype
	f_back		next item on free list, or NULL
	f_nlocals	number of locals
	f_stacksize	size of value stack
        f_size          size of localsplus
   Note that the value and block stacks are preserved -- this can save
   another malloc() call or two (and two free() calls as well!).
   Also note that, unlike for integers, each frame object is a
   malloc'ed object in its own right -- it is only the actual calls to
   malloc() that we are trying to save here, not the administration.
   After all, while a typical program may make millions of calls, a
   call depth of more than 20 or 30 is probably already exceptional
   unless the program contains run-away recursion.  I hope.
*/

static PyFrameObject *free_list = NULL;

static void
frame_dealloc(PyFrameObject *f)
{
	int i, slots;
	PyObject **fastlocals;

	Py_TRASHCAN_SAFE_BEGIN(f)
	/* Kill all local variables */
	slots = f->f_nlocals + f->f_ncells + f->f_nfreevars;
	fastlocals = f->f_localsplus;
	for (i = slots; --i >= 0; ++fastlocals) {
		Py_XDECREF(*fastlocals);
	}

	Py_XDECREF(f->f_back);
	Py_XDECREF(f->f_code);
	Py_XDECREF(f->f_builtins);
	Py_XDECREF(f->f_globals);
	Py_XDECREF(f->f_locals);
	Py_XDECREF(f->f_trace);
	Py_XDECREF(f->f_exc_type);
	Py_XDECREF(f->f_exc_value);
	Py_XDECREF(f->f_exc_traceback);
	f->f_back = free_list;
	free_list = f;
	Py_TRASHCAN_SAFE_END(f)
}

PyTypeObject PyFrame_Type = {
	PyObject_HEAD_INIT(&PyType_Type)
	0,
	"frame",
	sizeof(PyFrameObject),
	0,
	(destructor)frame_dealloc, /*tp_dealloc*/
	0,		/*tp_print*/
	(getattrfunc)frame_getattr, /*tp_getattr*/
	(setattrfunc)frame_setattr, /*tp_setattr*/
	0,		/*tp_compare*/
	0,		/*tp_repr*/
	0,		/*tp_as_number*/
	0,		/*tp_as_sequence*/
	0,		/*tp_as_mapping*/
};

PyFrameObject *
PyFrame_New(PyThreadState *tstate, PyCodeObject *code, PyObject *globals, 
	    PyObject *locals)
{
	PyFrameObject *back = tstate->frame;
	static PyObject *builtin_object;
	PyFrameObject *f;
	PyObject *builtins;
	int extras, ncells, nfrees;

	if (builtin_object == NULL) {
		builtin_object = PyString_InternFromString("__builtins__");
		if (builtin_object == NULL)
			return NULL;
	}
	if ((back != NULL && !PyFrame_Check(back)) ||
	    code == NULL || !PyCode_Check(code) ||
	    globals == NULL || !PyDict_Check(globals) ||
	    (locals != NULL && !PyDict_Check(locals))) {
		PyErr_BadInternalCall();
		return NULL;
	}
	ncells = PyTuple_GET_SIZE(code->co_cellvars);
	nfrees = PyTuple_GET_SIZE(code->co_freevars);
	extras = code->co_stacksize + code->co_nlocals + ncells + nfrees;
	if (back == NULL || back->f_globals != globals) {
		builtins = PyDict_GetItem(globals, builtin_object);
		if (builtins != NULL && PyModule_Check(builtins))
			builtins = PyModule_GetDict(builtins);
	}
	else {
		/* If we share the globals, we share the builtins.
		   Save a lookup and a call. */
		builtins = back->f_builtins;
	}
	if (builtins != NULL && !PyDict_Check(builtins))
		builtins = NULL;
	if (free_list == NULL) {
		/* PyObject_New is inlined */
		f = (PyFrameObject *)
			PyObject_MALLOC(sizeof(PyFrameObject) +
					extras*sizeof(PyObject *));
		if (f == NULL)
			return (PyFrameObject *)PyErr_NoMemory();
		PyObject_INIT(f, &PyFrame_Type);
		f->f_size = extras;
	}
	else {
		f = free_list;
		free_list = free_list->f_back;
		if (f->f_size < extras) {
			f = (PyFrameObject *)
				PyObject_REALLOC(f, sizeof(PyFrameObject) +
						 extras*sizeof(PyObject *));
			if (f == NULL)
				return (PyFrameObject *)PyErr_NoMemory();
			f->f_size = extras;
		}
		else
			extras = f->f_size;
		PyObject_INIT(f, &PyFrame_Type);
	}
	if (builtins == NULL) {
		/* No builtins!  Make up a minimal one. */
		builtins = PyDict_New();
		if (builtins == NULL || /* Give them 'None', at least. */
		    PyDict_SetItemString(builtins, "None", Py_None) < 0) {
			Py_DECREF(f);
			return NULL;
		}
	}
	else
		Py_XINCREF(builtins);
	f->f_builtins = builtins;
	Py_XINCREF(back);
	f->f_back = back;
	Py_INCREF(code);
	f->f_code = code;
	Py_INCREF(globals);
	f->f_globals = globals;
	if (code->co_flags & CO_NEWLOCALS) {
		if (code->co_flags & CO_OPTIMIZED)
			locals = NULL; /* Let fast_2_locals handle it */
		else {
			locals = PyDict_New();
			if (locals == NULL) {
				Py_DECREF(f);
				return NULL;
			}
		}
	}
	else {
		if (locals == NULL)
			locals = globals;
		Py_INCREF(locals);
	}
	f->f_locals = locals;
	f->f_trace = NULL;
	f->f_exc_type = f->f_exc_value = f->f_exc_traceback = NULL;
	f->f_tstate = tstate;

	f->f_lasti = 0;
	f->f_lineno = code->co_firstlineno;
	f->f_restricted = (builtins != tstate->interp->builtins);
	f->f_iblock = 0;
	f->f_nlocals = code->co_nlocals;
	f->f_stacksize = code->co_stacksize;
	f->f_ncells = ncells;
	f->f_nfreevars = nfrees;

	while (--extras >= 0)
		f->f_localsplus[extras] = NULL;

	f->f_valuestack = f->f_localsplus + (f->f_nlocals + ncells + nfrees);

	return f;
}

/* Block management */

void
PyFrame_BlockSetup(PyFrameObject *f, int type, int handler, int level)
{
	PyTryBlock *b;
	if (f->f_iblock >= CO_MAXBLOCKS)
		Py_FatalError("XXX block stack overflow");
	b = &f->f_blockstack[f->f_iblock++];
	b->b_type = type;
	b->b_level = level;
	b->b_handler = handler;
}

PyTryBlock *
PyFrame_BlockPop(PyFrameObject *f)
{
	PyTryBlock *b;
	if (f->f_iblock <= 0)
		Py_FatalError("XXX block stack underflow");
	b = &f->f_blockstack[--f->f_iblock];
	return b;
}

/* Convert between "fast" version of locals and dictionary version */

static inline void
map_to_dict(PyObject *map, int nmap, PyObject *dict, PyObject **values,
	    int deref)
{
	int j;
	for (j = nmap; --j >= 0; ) {
		PyObject *key = PyTuple_GetItem(map, j);
		PyObject *value = values[j];
		if (deref)
			value = PyCell_GET(value);
		if (value == NULL) {
			PyErr_Clear();
			if (PyDict_DelItem(dict, key) != 0)
				PyErr_Clear();
		}
		else {
			if (PyDict_SetItem(dict, key, value) != 0)
				PyErr_Clear();
		}
	}
}

static inline void
dict_to_map(PyObject *map, int nmap, PyObject *dict, PyObject **values,
	    int deref, int clear)
{
	int j;
	for (j = nmap; --j >= 0; ) {
		PyObject *key = PyTuple_GetItem(map, j);
		PyObject *value = PyDict_GetItem(dict, key);
		Py_XINCREF(value);
		if (deref) {
			if (value) {
				if (PyCell_Set(values[j], value) < 0)
					PyErr_Clear();
			} else if (clear) {
				Py_XDECREF(values[j]);
				values[j] = value;
			}
		} else if (value != NULL || clear) {
			Py_XDECREF(values[j]);
			values[j] = value;
		}
	}
}

void
PyFrame_FastToLocals(PyFrameObject *f)
{
	/* Merge fast locals into f->f_locals */
	PyObject *locals, *map;
	PyObject **fast;
	PyObject *error_type, *error_value, *error_traceback;
	int j;
	if (f == NULL)
		return;
	locals = f->f_locals;
	if (locals == NULL) {
		locals = f->f_locals = PyDict_New();
		if (locals == NULL) {
			PyErr_Clear(); /* Can't report it :-( */
			return;
		}
	}
	if (f->f_nlocals == 0)
		return;
	map = f->f_code->co_varnames;
	if (!PyDict_Check(locals) || !PyTuple_Check(map))
		return;
	PyErr_Fetch(&error_type, &error_value, &error_traceback);
	fast = f->f_localsplus;
	j = PyTuple_Size(map);
	if (j > f->f_nlocals)
		j = f->f_nlocals;
	map_to_dict(map, j, locals, fast, 0);
	if (f->f_ncells || f->f_nfreevars) {
		if (!(PyTuple_Check(f->f_code->co_cellvars)
		      && PyTuple_Check(f->f_code->co_freevars))) {
			Py_DECREF(locals);
			return;
		}
		map_to_dict(f->f_code->co_cellvars, 
			    PyTuple_GET_SIZE(f->f_code->co_cellvars),
			    locals, fast + f->f_nlocals, 1);
		map_to_dict(f->f_code->co_freevars, 
			    PyTuple_GET_SIZE(f->f_code->co_freevars),
			    locals, fast + f->f_nlocals + f->f_ncells, 1);
	}
	PyErr_Restore(error_type, error_value, error_traceback);
}

void
PyFrame_LocalsToFast(PyFrameObject *f, int clear)
{
	/* Merge f->f_locals into fast locals */
	PyObject *locals, *map;
	PyObject **fast;
	PyObject *error_type, *error_value, *error_traceback;
	int j;
	if (f == NULL)
		return;
	locals = f->f_locals;
	map = f->f_code->co_varnames;
	if (locals == NULL || f->f_code->co_nlocals == 0)
		return;
	if (!PyDict_Check(locals) || !PyTuple_Check(map))
		return;
	PyErr_Fetch(&error_type, &error_value, &error_traceback);
	fast = f->f_localsplus;
	j = PyTuple_Size(map);
	if (j > f->f_nlocals)
		j = f->f_nlocals;
	dict_to_map(f->f_code->co_varnames, j, locals, fast, 0, clear);
	if (f->f_ncells || f->f_nfreevars) {
		if (!(PyTuple_Check(f->f_code->co_cellvars)
		      && PyTuple_Check(f->f_code->co_freevars)))
			return;
		dict_to_map(f->f_code->co_cellvars, 
			    PyTuple_GET_SIZE(f->f_code->co_cellvars),
			    locals, fast, 1, clear);
		dict_to_map(f->f_code->co_freevars, 
			    PyTuple_GET_SIZE(f->f_code->co_freevars),
			    locals, fast, 1, clear);
	}
	PyErr_Restore(error_type, error_value, error_traceback);
}

/* Clear out the free list */

void
PyFrame_Fini(void)
{
	while (free_list != NULL) {
		PyFrameObject *f = free_list;
		free_list = free_list->f_back;
		PyObject_DEL(f);
	}
}
