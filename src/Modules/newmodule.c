/* Object-construction module in the Kalisto CPython runtime, GSQE78.
 * Derived from CPython 2.1 Modules/newmodule.c and its public headers.
 * Copyright (c) 2001 Python Software Foundation; all rights reserved.
 * Upstream license: reference/cpython-2.1/LICENSE.
 */

/* Module new -- create new objects of various types */

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


#define DL_IMPORT(t) t
#define DL_EXPORT(t) t
#define PYTHON_API_VERSION 1010
#define Py_XINCREF(op) if ((op) == NULL) ; else Py_INCREF(op)
#define PyDict_Check(op) ((op)->ob_type == &PyDict_Type)
#define PyInstance_Check(op) ((op)->ob_type == &PyInstance_Type)
typedef struct { int cf_nested_scopes; } PyCompilerFlags;
extern PyTypeObject PyTuple_Type, PyDict_Type, PyClass_Type, PyInstance_Type;
extern PyObject *PyTuple_New(int), *PyModule_New(char *);
extern int PyCallable_Check(PyObject *);
extern PyObject *PyInstance_NewRaw(PyObject *, PyObject *);
extern PyObject *PyMethod_New(PyObject *, PyObject *, PyObject *);
extern PyObject *PyClass_New(PyObject *, PyObject *, PyObject *);
extern PyObject *Py_InitModule4(char *, PyMethodDef *, char *, PyObject *, int);

/* Function object interface */

#ifndef Py_FUNCOBJECT_H
#define Py_FUNCOBJECT_H
#ifdef __cplusplus
extern "C" {
#endif

typedef struct {
    PyObject_HEAD
    PyObject *func_code;
    PyObject *func_globals;
    PyObject *func_defaults;
    PyObject *func_closure;
    PyObject *func_doc;
    PyObject *func_name;
    PyObject *func_dict;
    PyObject *func_weakreflist;
} PyFunctionObject;

extern DL_IMPORT(PyTypeObject) PyFunction_Type;

#define PyFunction_Check(op) ((op)->ob_type == &PyFunction_Type)

extern DL_IMPORT(PyObject *) PyFunction_New(PyObject *, PyObject *);
extern DL_IMPORT(PyObject *) PyFunction_GetCode(PyObject *);
extern DL_IMPORT(PyObject *) PyFunction_GetGlobals(PyObject *);
extern DL_IMPORT(PyObject *) PyFunction_GetDefaults(PyObject *);
extern DL_IMPORT(int) PyFunction_SetDefaults(PyObject *, PyObject *);
extern DL_IMPORT(PyObject *) PyFunction_GetClosure(PyObject *);
extern DL_IMPORT(int) PyFunction_SetClosure(PyObject *, PyObject *);

/* Macros for direct access to these values. Type checks are *not*
   done, so use with care. */
#define PyFunction_GET_CODE(func) \
        (((PyFunctionObject *)func) -> func_code)
#define PyFunction_GET_GLOBALS(func) \
	(((PyFunctionObject *)func) -> func_globals)
#define PyFunction_GET_DEFAULTS(func) \
	(((PyFunctionObject *)func) -> func_defaults)
#define PyFunction_GET_CLOSURE(func) \
	(((PyFunctionObject *)func) -> func_closure)

#ifdef __cplusplus
}
#endif
#endif /* !Py_FUNCOBJECT_H */

/* Definitions for bytecode */

#ifndef Py_COMPILE_H
#define Py_COMPILE_H
#ifdef __cplusplus
extern "C" {
#endif

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

extern DL_IMPORT(PyTypeObject) PyCode_Type;

#define PyCode_Check(op) ((op)->ob_type == &PyCode_Type)

#define CO_MAXBLOCKS 20 /* Max static block nesting within a function */

/* Public interface */
struct _node; /* Declare the existence of this type */
DL_IMPORT(PyCodeObject *) PyNode_Compile(struct _node *, char *);
DL_IMPORT(PyCodeObject *) PyCode_New(
	int, int, int, int, PyObject *, PyObject *, PyObject *, PyObject *,
	PyObject *, PyObject *, PyObject *, PyObject *, int, PyObject *); 
        /* same as struct above */
DL_IMPORT(int) PyCode_Addr2Line(PyCodeObject *, int);

/* Future feature support */

typedef struct {
    int ff_found_docstring;
    int ff_last_lineno;
    int ff_nested_scopes;
} PyFutureFeatures;

DL_IMPORT(PyFutureFeatures *) PyNode_Future(struct _node *, char *);
DL_IMPORT(PyCodeObject *) PyNode_CompileFlags(struct _node *, char *,
					      PyCompilerFlags *);

#define NESTED_SCOPES_DEFAULT 0
#define FUTURE_NESTED_SCOPES "nested_scopes"

/* for internal use only */
#define _PyCode_GETCODEPTR(co, pp) \
	((*(co)->co_code->ob_type->tp_as_buffer->bf_getreadbuffer) \
	 ((co)->co_code, 0, (void **)(pp)))

#ifdef __cplusplus
}
#endif
#endif /* !Py_COMPILE_H */

#line 5 "newmodule.c"


static char new_instance_doc[] =
"Create an instance object from (CLASS [, DICT]) without calling its\n\
__init__() method.  DICT must be a dictionary or None.";

static PyObject *
new_instance(PyObject* unused, PyObject* args)
{
	PyObject *klass;
	PyObject *dict = NULL;

	if (!PyArg_ParseTuple(args, "O!|O:instance",
			      &PyClass_Type, &klass, &dict))
		return NULL;

	if (dict == Py_None)
		dict = NULL;
	else if (dict == NULL)
		/* do nothing */;
	else if (!PyDict_Check(dict)) {
		PyErr_SetString(PyExc_TypeError,
		      "new.instance() second arg must be dictionary or None");
		return NULL;
	}
	return PyInstance_NewRaw(klass, dict);
}

static char new_im_doc[] =
"Create a instance method object from (FUNCTION, INSTANCE, CLASS).";

static PyObject *
new_instancemethod(PyObject* unused, PyObject* args)
{
	PyObject* func;
	PyObject* self;
	PyObject* classObj;

	if (!PyArg_ParseTuple(args, "OOO!:instancemethod",
			      &func,
			      &self,
			      &PyClass_Type, &classObj))
		return NULL;
	if (!PyCallable_Check(func)) {
		PyErr_SetString(PyExc_TypeError,
				"first argument must be callable");
		return NULL;
	}
	if (self == Py_None)
		self = NULL;
	else if (!PyInstance_Check(self)) {
		PyErr_SetString(PyExc_TypeError,
				"second argument must be instance or None");
		return NULL;
	}
	return PyMethod_New(func, self, classObj);
}

static char new_function_doc[] =
"Create a function object from (CODE, GLOBALS, [NAME [, ARGDEFS]]).";

static PyObject *
new_function(PyObject* unused, PyObject* args)
{
	PyObject* code;
	PyObject* globals;
	PyObject* name = Py_None;
	PyObject* defaults = Py_None;
	PyFunctionObject* newfunc;

	if (!PyArg_ParseTuple(args, "O!O!|OO!:function",
			      &PyCode_Type, &code,
			      &PyDict_Type, &globals,
			      &name,
			      &PyTuple_Type, &defaults))
		return NULL;
	if (name != Py_None && !PyString_Check(name)) {
		PyErr_SetString(PyExc_TypeError,
				"arg 3 (name) must be None or string");
		return NULL;
	}

	newfunc = (PyFunctionObject *)PyFunction_New(code, globals);
	if (newfunc == NULL)
		return NULL;

	if (name != Py_None) {
		Py_XINCREF(name);
		Py_XDECREF(newfunc->func_name);
		newfunc->func_name = name;
	}
	if (defaults != Py_None) {
		Py_XINCREF(defaults);
		Py_XDECREF(newfunc->func_defaults);
		newfunc->func_defaults  = defaults;
	}

	return (PyObject *)newfunc;
}

static char new_code_doc[] =
"Create a code object from (ARGCOUNT, NLOCALS, STACKSIZE, FLAGS, CODESTRING,\n"
"CONSTANTS, NAMES, VARNAMES, FILENAME, NAME, FIRSTLINENO, LNOTAB, FREEVARS,\n"
"CELLVARS).";

static PyObject *
new_code(PyObject* unused, PyObject* args)
{
	int argcount;
	int nlocals;
	int stacksize;
	int flags;
	PyObject* code;
	PyObject* consts;
	PyObject* names;
	PyObject* varnames;
	PyObject* freevars = NULL;
	PyObject* cellvars = NULL;
	PyObject* filename;
	PyObject* name;
	int firstlineno;
	PyObject* lnotab;
	PyBufferProcs *pb;

	if (!PyArg_ParseTuple(args, "iiiiSO!O!O!SSiS|O!O!:code",
			      &argcount, &nlocals, &stacksize, &flags,
			      &code,
			      &PyTuple_Type, &consts,
			      &PyTuple_Type, &names,
			      &PyTuple_Type, &varnames,
			      &filename, &name,
			      &firstlineno, &lnotab,
			      &PyTuple_Type, &freevars,
			      &PyTuple_Type, &cellvars))
		return NULL;

	if (freevars == NULL || cellvars == NULL) {
		PyObject *empty = PyTuple_New(0);
		if (empty == NULL)
		    return NULL;
		if (freevars == NULL) {
		    freevars = empty;
		    Py_INCREF(freevars);
		}
		if (cellvars == NULL) {
		    cellvars = empty;
		    Py_INCREF(cellvars);
		}
		Py_DECREF(empty);
	}

	pb = code->ob_type->tp_as_buffer;
	if (pb == NULL ||
	    pb->bf_getreadbuffer == NULL ||
	    pb->bf_getsegcount == NULL ||
	    (*pb->bf_getsegcount)(code, NULL) != 1)
	{
		PyErr_SetString(PyExc_TypeError,
		  "bytecode object must be a single-segment read-only buffer");
		return NULL;
	}

	return (PyObject *)PyCode_New(argcount, nlocals, stacksize, flags,
				      code, consts, names, varnames,
				      freevars, cellvars, filename, name,
				      firstlineno, lnotab); 
}

static char new_module_doc[] =
"Create a module object from (NAME).";

static PyObject *
new_module(PyObject* unused, PyObject* args)
{
	char *name;
  
	if (!PyArg_ParseTuple(args, "s:module", &name))
		return NULL;
	return PyModule_New(name);
}

static char new_class_doc[] =
"Create a class object from (NAME, BASE_CLASSES, DICT).";

static PyObject *
new_class(PyObject* unused, PyObject* args)
{
	PyObject * name;
	PyObject * classes;
	PyObject * dict;
  
	if (!PyArg_ParseTuple(args, "SO!O!:class", &name, &PyTuple_Type, &classes,
			      &PyDict_Type, &dict))
		return NULL;
	return PyClass_New(classes, dict, name);
}

static PyMethodDef new_methods[] = {
	{"instance",		new_instance,		
	 METH_VARARGS, new_instance_doc},
	{"instancemethod",	new_instancemethod,	
	 METH_VARARGS, new_im_doc},
	{"function",		new_function,		
	 METH_VARARGS, new_function_doc},
	{"code",		new_code,		
	 METH_VARARGS, new_code_doc},
	{"module",		new_module,		
	 METH_VARARGS, new_module_doc},
	{"classobj",		new_class,		
	 METH_VARARGS, new_class_doc},
	{NULL,			NULL}		/* sentinel */
};

char new_doc[] =
"Functions to create new objects used by the interpreter.\n\
\n\
You need to know a great deal about the interpreter to use this!";

DL_EXPORT(void)
initnew(void)
{
	Py_InitModule4("new", new_methods, new_doc, (PyObject *)NULL,
		       PYTHON_API_VERSION);
}
