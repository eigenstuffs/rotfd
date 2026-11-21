/* Symbol-table entry objects in the Kalisto CPython runtime, GSQE78.
 * Derived from CPython 2.1 Python/symtable.c and its public headers.
 * Copyright (c) 2001 Python Software Foundation; all rights reserved.
 * Upstream license: reference/cpython-2.1/LICENSE.
 */
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
#define PyObject_New(type,tp) ((type *)_PyObject_New(tp))
#define PyObject_Del(op) _PyObject_Del((PyObject *)(op))
#define Py_TPFLAGS_DEFAULT 0x6B
#define READONLY 1
typedef struct { PyObject_HEAD long ob_ival; } PyIntObject;
#define PyInt_AS_LONG(op) (((PyIntObject *)(op))->ob_ival)
typedef struct { int cf_nested_scopes; } PyCompilerFlags;
extern PyObject *PyDict_New(void), *PyDict_GetItem(PyObject *, PyObject *);
extern int PyDict_SetItem(PyObject *, PyObject *, PyObject *);
extern PyObject *_PyObject_New(PyTypeObject *);
extern void _PyObject_Del(PyObject *);

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
#ifndef Py_SYMTABLE_H
#define Py_SYMTABLE_H
#ifdef __cplusplus
extern "C" {
#endif

/* A symbol table is constructed each time PyNode_Compile() is
   called.  The table walks the entire parse tree and identifies each
   use or definition of a variable. 

   The symbol table contains a dictionary for each code block in a
   module: The symbol dictionary for the block.  They keys of these
   dictionaries are the name of all variables used or defined in the
   block; the integer values are used to store several flags,
   e.g. DEF_PARAM indicates that a variable is a parameter to a
   function. 
*/

struct _symtable_entry;

struct symtable {
	int st_pass;             /* pass == 1 or 2 */
	int st_nested_scopes;    /* true if nested scopes are enabled */
	char *st_filename;       /* name of file being compiled */
	struct _symtable_entry *st_cur; /* current symbol table entry */
	PyObject *st_symbols;    /* dictionary of symbol table entries */
        PyObject *st_stack;      /* stack of namespace info */
	PyObject *st_global;     /* borrowed ref to MODULE in st_symbols */
	int st_nscopes;          /* number of scopes */
	int st_errors;           /* number of errors */
	char *st_private;        /* name of current class or NULL */
	int st_tmpname;          /* temporary name counter */
	PyFutureFeatures *st_future; /* module's future features */
};

typedef struct _symtable_entry {
	PyObject_HEAD
	PyObject *ste_id;        /* int: key in st_symbols) */
	PyObject *ste_symbols;   /* dict: name to flags) */
	PyObject *ste_name;      /* string: name of scope */
	PyObject *ste_varnames;  /* list of variable names */
	PyObject *ste_children;  /* list of child ids */
	int ste_type;            /* module, class, or function */
	int ste_lineno;          /* first line of scope */
	int ste_optimized;       /* true if namespace can't be optimized */
	int ste_nested;          /* true if scope is nested */
	int ste_child_free;      /* true if a child scope has free variables,
				    including free refs to globals */
	int ste_opt_lineno;      /* lineno of last exec or import * */
	struct symtable *ste_table;
} PySymtableEntryObject;

extern DL_IMPORT(PyTypeObject) PySymtableEntry_Type;

#define PySymtableEntry_Check(op) ((op)->ob_type == &PySymtableEntry_Type)

extern DL_IMPORT(PyObject *) PySymtableEntry_New(struct symtable *,
						 char *, int, int);

DL_IMPORT(struct symtable *) PyNode_CompileSymtable(struct _node *, char *);
DL_IMPORT(void) PySymtable_Free(struct symtable *);


#define TOP "global"

/* Flags for def-use information */

#define DEF_GLOBAL 1           /* global stmt */
#define DEF_LOCAL 2            /* assignment in code block */
#define DEF_PARAM 2<<1         /* formal parameter */
#define USE 2<<2               /* name is used */
#define DEF_STAR 2<<3          /* parameter is star arg */
#define DEF_DOUBLESTAR 2<<4    /* parameter is star-star arg */
#define DEF_INTUPLE 2<<5       /* name defined in tuple in parameters */
#define DEF_FREE 2<<6          /* name used but not defined in nested scope */
#define DEF_FREE_GLOBAL 2<<7   /* free variable is actually implicit global */
#define DEF_FREE_CLASS 2<<8    /* free variable from class's method */
#define DEF_IMPORT 2<<9        /* assignment occurred via import */

#define DEF_BOUND (DEF_LOCAL | DEF_PARAM | DEF_IMPORT)

#define TYPE_FUNCTION 1
#define TYPE_CLASS 2
#define TYPE_MODULE 3

#define LOCAL 1
#define GLOBAL_EXPLICIT 2
#define GLOBAL_IMPLICIT 3
#define FREE 4
#define CELL 5

#define OPT_IMPORT_STAR 1
#define OPT_EXEC 2
#define OPT_BARE_EXEC 4

#ifdef __cplusplus
}
#endif
#endif /* !Py_SYMTABLE_H */
#define single_input 256
#define file_input 257
#define eval_input 258
#define funcdef 259
#define parameters 260
#define varargslist 261
#define fpdef 262
#define fplist 263
#define stmt 264
#define simple_stmt 265
#define small_stmt 266
#define expr_stmt 267
#define augassign 268
#define print_stmt 269
#define del_stmt 270
#define pass_stmt 271
#define flow_stmt 272
#define break_stmt 273
#define continue_stmt 274
#define return_stmt 275
#define raise_stmt 276
#define import_stmt 277
#define import_as_name 278
#define dotted_as_name 279
#define dotted_name 280
#define global_stmt 281
#define exec_stmt 282
#define assert_stmt 283
#define compound_stmt 284
#define if_stmt 285
#define while_stmt 286
#define for_stmt 287
#define try_stmt 288
#define except_clause 289
#define suite 290
#define test 291
#define and_test 292
#define not_test 293
#define comparison 294
#define comp_op 295
#define expr 296
#define xor_expr 297
#define and_expr 298
#define shift_expr 299
#define arith_expr 300
#define term 301
#define factor 302
#define power 303
#define atom 304
#define listmaker 305
#define lambdef 306
#define trailer 307
#define subscriptlist 308
#define subscript 309
#define sliceop 310
#define exprlist 311
#define testlist 312
#define dictmaker 313
#define classdef 314
#define arglist 315
#define argument 316
#define list_iter 317
#define list_for 318
#define list_if 319

#line 2 "symtable.c"





PyObject *
PySymtableEntry_New(struct symtable *st, char *name, int type, int lineno)
{
	PySymtableEntryObject *ste = NULL;
	PyObject *k, *v;

	k = PyInt_FromLong(st->st_nscopes++);
	if (k == NULL)
		goto fail;
	v = PyDict_GetItem(st->st_symbols, k);
	if (v) /* XXX could check that name, type, lineno match */ {
		Py_INCREF(v);
		return v;
	}
	
	ste = (PySymtableEntryObject *)PyObject_New(PySymtableEntryObject,
						    &PySymtableEntry_Type);
	ste->ste_table = st;
	ste->ste_id = k;

	v = PyString_FromString(name);
	if (v == NULL)
		goto fail;
	ste->ste_name = v;
	
	v = PyDict_New();
	if (v == NULL)
	    goto fail;
	ste->ste_symbols = v;

	v = PyList_New(0);
	if (v == NULL)
	    goto fail;
	ste->ste_varnames = v;

	v = PyList_New(0);
	if (v == NULL)
	    goto fail;
	ste->ste_children = v;

	ste->ste_optimized = 0;
	ste->ste_lineno = lineno;
	switch (type) {
	case funcdef:
	case lambdef:
		ste->ste_type = TYPE_FUNCTION;
		break;
	case classdef:
		ste->ste_type = TYPE_CLASS;
		break;
	case single_input:
	case eval_input:
	case file_input:
		ste->ste_type = TYPE_MODULE;
		break;
	}

	if (st->st_cur == NULL)
		ste->ste_nested = 0;
	else if (st->st_cur->ste_nested 
		 || st->st_cur->ste_type == TYPE_FUNCTION)
		ste->ste_nested = 1;
	else
		ste->ste_nested = 0;
	ste->ste_child_free = 0;

	if (PyDict_SetItem(st->st_symbols, ste->ste_id, (PyObject *)ste) < 0)
	    goto fail;
	
	return (PyObject *)ste;
 fail:
	Py_XDECREF(ste);
	return NULL;
}

static PyObject *
ste_repr(PySymtableEntryObject *ste)
{
	char buf[256];

	sprintf(buf, "<symtable entry %.100s(%ld), line %d>",
		PyString_AS_STRING(ste->ste_name),
		PyInt_AS_LONG(ste->ste_id),
		ste->ste_lineno);
	return PyString_FromString(buf);
}

static void
ste_dealloc(PySymtableEntryObject *ste)
{
	ste->ste_table = NULL;
	Py_XDECREF(ste->ste_id);
	Py_XDECREF(ste->ste_name);
	Py_XDECREF(ste->ste_symbols);
	Py_XDECREF(ste->ste_varnames);
	Py_XDECREF(ste->ste_children);
	PyObject_Del(ste);
}

#define OFF(x) offsetof(PySymtableEntryObject, x)

static struct memberlist ste_memberlist[] = {
	{"id",       T_OBJECT, OFF(ste_id), READONLY},
	{"name",     T_OBJECT, OFF(ste_name), READONLY},
	{"symbols",  T_OBJECT, OFF(ste_symbols), READONLY},
	{"varnames", T_OBJECT, OFF(ste_varnames), READONLY},
	{"children", T_OBJECT, OFF(ste_children), READONLY},
	{"type",     T_INT,    OFF(ste_type), READONLY},
	{"lineno",   T_INT,    OFF(ste_lineno), READONLY},
	{"optimized",T_INT,    OFF(ste_optimized), READONLY},
	{"nested",   T_INT,    OFF(ste_nested), READONLY},
	{NULL}
};

static PyObject *
ste_getattr(PySymtableEntryObject *ste, char *name)
{
	return PyMember_Get((char *)ste, ste_memberlist, name);
}

PyTypeObject PySymtableEntry_Type = {
	PyObject_HEAD_INIT(&PyType_Type)
	0,
	"symtable entry",
	sizeof(PySymtableEntryObject),
	0,
	(destructor)ste_dealloc,                /* tp_dealloc */
	0,                                      /* tp_print */
	(getattrfunc)ste_getattr,               /* tp_getattr */
	0,					/* tp_setattr */
	0,			                /* tp_compare */
	(reprfunc)ste_repr,			/* tp_repr */
	0,					/* tp_as_number */
	0,			                /* tp_as_sequence */
	0,					/* tp_as_mapping */
	0,					/* tp_hash */
	0,					/* tp_call */
	0,					/* tp_str */
	0,					/* tp_getattro */
	0,					/* tp_setattro */
	0,					/* tp_as_buffer */
	Py_TPFLAGS_DEFAULT,	                /* tp_flags */
 	0,					/* tp_doc */
};
