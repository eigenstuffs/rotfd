/* Import machinery in the Kalisto CPython runtime, GSQE78.
 * Derived from CPython 2.1 Python/import.c and its public headers.
 * Copyright (c) 2001 Python Software Foundation; all rights reserved.
 * Upstream license: reference/cpython-2.1/LICENSE.
 */

/* Module definition and import implementation */

#define NULL 0
#define PyObject_HEAD int ob_refcnt; struct _typeobject *ob_type;
#define PyObject_VAR_HEAD PyObject_HEAD int ob_size;
#define PyObject_HEAD_INIT(type) 1, type,
typedef unsigned long size_t;
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


#define DL_IMPORT(type) type
#define Py_XINCREF(op) if ((op) == NULL) ; else Py_INCREF(op)
#define PYTHON_API_VERSION 1010
typedef struct { int cf_nested_scopes; } PyCompilerFlags;
#define PyMem_NEW(type,n) ((type *)malloc(1+(n)*sizeof(type)))
#define PyMem_RESIZE(p,type,n) if ((p)==NULL) (p)=(type *)malloc(1+(n)*sizeof(type)); else (p)=(type *)realloc(p,1+(n)*sizeof(type))
#define PyMem_DEL(p) free(p)
#define PyModule_Check(op) ((op)->ob_type == &PyModule_Type)
#define PyDict_Check(op) ((op)->ob_type == &PyDict_Type)
#define PyCode_Check(op) ((op)->ob_type == &PyCode_Type)
#define Py_InitModule(name,methods) Py_InitModule4(name,methods,NULL,NULL,1010)
#define Py_InitModule3(name,methods,doc) Py_InitModule4(name,methods,doc,NULL,1010)
#define SIZEOF_TIME_T 4
#define Py_file_input 257
#define S_IFMT 0170000
#define S_IFDIR 0040000
typedef long time_t;
struct stat { int st_mode; };
extern PyTypeObject PyModule_Type, PyDict_Type, PyCode_Type;
extern PyObject *PyString_InternFromString(const char *);
extern PyObject *PyObject_GetItem(PyObject *, PyObject *), *PyObject_GetAttr(PyObject *, PyObject *);
extern FILE *PyFile_AsFile(PyObject *);
extern PyObject *PyFile_FromFile(FILE *, char *, char *, int (*)(FILE *));
extern PyObject *PyExc_ImportError, *PyExc_RuntimeError;
extern int Py_VerboseFlag, Py_OptimizeFlag, Py_UnicodeFlag;
extern void *realloc(void *, size_t);
extern size_t strlen(const char *);
extern char *strcpy(char *, const char *), *strncpy(char *, const char *, size_t), *strcat(char *, const char *), *strrchr(const char *, int);
extern int strncmp(const char *, const char *, size_t);
extern int fclose(FILE *), unlink(const char *);
extern void Py_FatalError(const char *);
extern PyObject *PyErr_NoMemory(void);
extern void PyErr_SetObject(PyObject *, PyObject *);
extern PyObject *PyDict_New(void), *PyDict_Copy(PyObject *);
extern PyObject *PyDict_GetItem(PyObject *, PyObject *), *PyDict_GetItemString(PyObject *, const char *);
extern int PyDict_SetItem(PyObject *, PyObject *, PyObject *), PyDict_SetItemString(PyObject *, const char *, PyObject *);
extern int PyDict_DelItemString(PyObject *, const char *);
extern int PyDict_Next(PyObject *, int *, PyObject **, PyObject **);
extern void PyDict_Clear(PyObject *);
extern PyObject *PyModule_New(char *), *PyModule_GetDict(PyObject *);
extern char *PyModule_GetName(PyObject *);
extern void _PyModule_Clear(PyObject *);
extern PyObject *PySys_GetObject(char *);
extern void PySys_WriteStderr(const char *, ...);
extern PyObject *PyEval_GetBuiltins(void), *PyEval_GetGlobals(void);
extern PyObject *PyObject_CallMethod(PyObject *, const char *, const char *, ...);
extern int PyObject_HasAttrString(PyObject *, const char *);
extern int PyString_Size(PyObject *), PyList_Size(PyObject *);
extern PyObject *PyList_GetItem(PyObject *, int);
extern PyObject *Py_InitModule4(char *, PyMethodDef *, char *, PyObject *, int);
struct _ts;
struct _is;
typedef struct _is {
    struct _is *next;
    struct _ts *tstate_head;
    PyObject *modules;
    PyObject *sysdict;
    PyObject *builtins;
    int checkinterval;
} PyInterpreterState;
struct _frame;
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
} PyThreadState;
PyThreadState * PyThreadState_Get(void);
PyThreadState * PyThreadState_Swap(PyThreadState *);
extern PyThreadState * _PyThreadState_Current;

/* Parse tree node interface */

#ifndef Py_NODE_H
#define Py_NODE_H
#ifdef __cplusplus
extern "C" {
#endif

typedef struct _node {
    short		n_type;
    char		*n_str;
    int			n_lineno;
    int			n_nchildren;
    struct _node	*n_child;
} node;

extern DL_IMPORT(node *) PyNode_New(int type);
extern DL_IMPORT(int) PyNode_AddChild(node *n, int type,
                                      char *str, int lineno);
extern DL_IMPORT(void) PyNode_Free(node *n);

/* Node access functions */
#define NCH(n)		((n)->n_nchildren)
#define CHILD(n, i)	(&(n)->n_child[i])
#define TYPE(n)		((n)->n_type)
#define STR(n)		((n)->n_str)

/* Assert that the type of a node is what we expect */
#ifndef Py_DEBUG
#define REQ(n, type) { /*pass*/ ; }
#else
#define REQ(n, type) \
	{ if (TYPE(n) != (type)) { \
	    fprintf(stderr, "FATAL: node type %d, required %d\n", \
		    TYPE(n), type); \
	    abort(); \
	} }
#endif

extern DL_IMPORT(void) PyNode_ListTree(node *);

#ifdef __cplusplus
}
#endif
#endif /* !Py_NODE_H */

/* Token types */

#ifndef Py_TOKEN_H
#define Py_TOKEN_H
#ifdef __cplusplus
extern "C" {
#endif

#define ENDMARKER	0
#define NAME		1
#define NUMBER		2
#define STRING		3
#define NEWLINE		4
#define INDENT		5
#define DEDENT		6
#define LPAR		7
#define RPAR		8
#define LSQB		9
#define RSQB		10
#define COLON		11
#define COMMA		12
#define SEMI		13
#define PLUS		14
#define MINUS		15
#define STAR		16
#define SLASH		17
#define VBAR		18
#define AMPER		19
#define LESS		20
#define GREATER		21
#define EQUAL		22
#define DOT		23
#define PERCENT		24
#define BACKQUOTE	25
#define LBRACE		26
#define RBRACE		27
#define EQEQUAL		28
#define NOTEQUAL	29
#define LESSEQUAL	30
#define GREATEREQUAL	31
#define TILDE		32
#define CIRCUMFLEX	33
#define LEFTSHIFT	34
#define RIGHTSHIFT	35
#define DOUBLESTAR	36
#define PLUSEQUAL	37
#define MINEQUAL	38
#define STAREQUAL	39
#define SLASHEQUAL	40
#define PERCENTEQUAL	41
#define AMPEREQUAL	42
#define VBAREQUAL	43
#define CIRCUMFLEXEQUAL	44
#define LEFTSHIFTEQUAL	45
#define RIGHTSHIFTEQUAL	46
#define DOUBLESTAREQUAL	47
/* Don't forget to update the table _PyParser_TokenNames in tokenizer.c! */
#define OP		48
#define ERRORTOKEN	49
#define N_TOKENS	50

/* Special definitions for cooperation with parser */

#define NT_OFFSET		256

#define ISTERMINAL(x)		((x) < NT_OFFSET)
#define ISNONTERMINAL(x)	((x) >= NT_OFFSET)
#define ISEOF(x)		((x) == ENDMARKER)


extern DL_IMPORT(char *) _PyParser_TokenNames[]; /* Token names */
extern DL_IMPORT(int) PyToken_OneChar(int);
extern DL_IMPORT(int) PyToken_TwoChars(int, int);
extern DL_IMPORT(int) PyToken_ThreeChars(int, int, int);

#ifdef __cplusplus
}
#endif
#endif /* !Py_TOKEN_H */
#ifndef Py_ERRCODE_H
#define Py_ERRCODE_H
#ifdef __cplusplus
extern "C" {
#endif


/* Error codes passed around between file input, tokenizer, parser and
   interpreter.  This is necessary so we can turn them into Python
   exceptions at a higher level.  Note that some errors have a
   slightly different meaning when passed from the tokenizer to the
   parser than when passed from the parser to the interpreter; e.g.
   the parser only returns E_EOF when it hits EOF immediately, and it
   never returns E_OK. */

#define E_OK		10	/* No error */
#define E_EOF		11	/* End Of File */
#define E_INTR		12	/* Interrupted */
#define E_TOKEN		13	/* Bad token */
#define E_SYNTAX	14	/* Syntax error */
#define E_NOMEM		15	/* Ran out of memory */
#define E_DONE		16	/* Parsing complete */
#define E_ERROR		17	/* Execution error */
#define E_TABSPACE	18	/* Inconsistent mixing of tabs and spaces */
#define E_OVERFLOW      19	/* Node had too many children */
#define E_TOODEEP	20	/* Too many indentation levels */
#define E_DEDENT	21	/* No matching outer block for dedent */

#ifdef __cplusplus
}
#endif
#endif /* !Py_ERRCODE_H */

/* Interface for marshal.c */

#ifndef Py_MARSHAL_H
#define Py_MARSHAL_H
#ifdef __cplusplus
extern "C" {
#endif

DL_IMPORT(void) PyMarshal_WriteLongToFile(long, FILE *);
DL_IMPORT(void) PyMarshal_WriteShortToFile(int, FILE *);
DL_IMPORT(void) PyMarshal_WriteObjectToFile(PyObject *, FILE *);
DL_IMPORT(PyObject *) PyMarshal_WriteObjectToString(PyObject *);

DL_IMPORT(long) PyMarshal_ReadLongFromFile(FILE *);
DL_IMPORT(int) PyMarshal_ReadShortFromFile(FILE *);
DL_IMPORT(PyObject *) PyMarshal_ReadObjectFromFile(FILE *);
DL_IMPORT(PyObject *) PyMarshal_ReadLastObjectFromFile(FILE *);
DL_IMPORT(PyObject *) PyMarshal_ReadObjectFromString(char *, int);

#ifdef __cplusplus
}
#endif
#endif /* !Py_MARSHAL_H */

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

/* Interface to execute compiled code */

#ifndef Py_EVAL_H
#define Py_EVAL_H
#ifdef __cplusplus
extern "C" {
#endif

DL_IMPORT(PyObject *) PyEval_EvalCode(PyCodeObject *, PyObject *, PyObject *);

#ifdef __cplusplus
}
#endif
#endif /* !Py_EVAL_H */
#ifndef Py_OSDEFS_H
#define Py_OSDEFS_H
#ifdef __cplusplus
extern "C" {
#endif


/* Operating system dependencies */

#ifdef macintosh
#define SEP ':'
#define MAXPATHLEN 256
/* Mod by Jack: newline is less likely to occur in filenames than space */
#define DELIM '\n'
#endif

/* Mod by chrish: QNX has WATCOM, but isn't DOS */
#if !defined(__QNX__)
#if defined(MS_WINDOWS) || defined(__BORLANDC__) || defined(__WATCOMC__) || defined(__DJGPP__) || defined(PYOS_OS2)
#define SEP '\\'
#define ALTSEP '/'
#define MAXPATHLEN 256
#define DELIM ';'
#endif
#endif

#ifdef RISCOS
#define SEP '.'
#define MAXPATHLEN 256
#define DELIM ','
#endif


/* Filename separator */
#ifndef SEP
#define SEP '/'
#endif

/* Max pathname length */
#ifndef MAXPATHLEN
#define MAXPATHLEN 1024
#endif

/* Search path entry delimiter */
#ifndef DELIM
#define DELIM ':'
#endif

#ifdef __cplusplus
}
#endif
#endif /* !Py_OSDEFS_H */

/* Module definition and import interface */

#ifndef Py_IMPORT_H
#define Py_IMPORT_H
#ifdef __cplusplus
extern "C" {
#endif

DL_IMPORT(long) PyImport_GetMagicNumber(void);
DL_IMPORT(PyObject *) PyImport_ExecCodeModule(char *name, PyObject *co);
DL_IMPORT(PyObject *) PyImport_ExecCodeModuleEx(
	char *name, PyObject *co, char *pathname);
DL_IMPORT(PyObject *) PyImport_GetModuleDict(void);
DL_IMPORT(PyObject *) PyImport_AddModule(char *name);
DL_IMPORT(PyObject *) PyImport_ImportModule(char *name);
DL_IMPORT(PyObject *) PyImport_ImportModuleEx(
	char *name, PyObject *globals, PyObject *locals, PyObject *fromlist);
DL_IMPORT(PyObject *) PyImport_Import(PyObject *name);
DL_IMPORT(PyObject *) PyImport_ReloadModule(PyObject *m);
DL_IMPORT(void) PyImport_Cleanup(void);
DL_IMPORT(int) PyImport_ImportFrozenModule(char *);

extern DL_IMPORT(PyObject *)_PyImport_FindExtension(char *, char *);
extern DL_IMPORT(PyObject *)_PyImport_FixupExtension(char *, char *);

struct _inittab {
    char *name;
    void (*initfunc)(void);
};

extern DL_IMPORT(struct _inittab *) PyImport_Inittab;

extern DL_IMPORT(int) PyImport_AppendInittab(char *name, void (*initfunc)(void));
extern DL_IMPORT(int) PyImport_ExtendInittab(struct _inittab *newtab);

struct _frozen {
    char *name;
    unsigned char *code;
    int size;
};

/* Embedding apps may change this pointer to point to their favorite
   collection of frozen modules: */

extern DL_IMPORT(struct _frozen *) PyImport_FrozenModules;

#ifdef __cplusplus
}
#endif
#endif /* !Py_IMPORT_H */
#ifndef Py_IMPORTDL_H
#define Py_IMPORTDL_H

#ifdef __cplusplus
extern "C" {
#endif


/* Definitions for dynamic loading of extension modules */
enum filetype {
	SEARCH_ERROR,
	PY_SOURCE,
	PY_COMPILED,
	C_EXTENSION,
	PY_RESOURCE, /* Mac only */
	PKG_DIRECTORY,
	C_BUILTIN,
	PY_FROZEN,
	PY_CODERESOURCE /* Mac only */
};

struct filedescr {
	char *suffix;
	char *mode;
	unsigned char type;
};
extern struct filedescr * _PyImport_Filetab;
extern const struct filedescr _PyImport_DynLoadFiletab[];

extern PyObject *_PyImport_LoadDynamicModule(char *name, char *pathname,
					     FILE *);

/* Max length of module suffix searched for -- accommodates "module.slb" */
#define MAXSUFFIXSIZE 12

#ifdef MS_WINDOWS
#include <windows.h>
typedef FARPROC dl_funcptr;
#else
#ifdef PYOS_OS2
typedef int (* APIENTRY dl_funcptr)();
#else
typedef void (*dl_funcptr)(void);
#endif
#endif


#ifdef __cplusplus
}
#endif
#endif /* !Py_IMPORTDL_H */

extern node *PyParser_SimpleParseFile(FILE *, char *, int);

#line 5 "import.c"









#ifdef macintosh
#include "macglue.h"
#endif

#ifdef HAVE_UNISTD_H
#include <unistd.h>
#endif

#ifdef HAVE_FCNTL_H
#include <fcntl.h>
#endif

#if defined(PYCC_VACPP)
/* VisualAge C/C++ Failed to Define MountType Field in sys/stat.h */
#define S_IFMT (S_IFDIR|S_IFCHR|S_IFREG)
#endif

#ifndef S_ISDIR
#define S_ISDIR(mode) (((mode) & S_IFMT) == S_IFDIR)
#endif

extern time_t PyOS_GetLastModificationTime(char *, FILE *);
						/* In getmtime.c */

/* Magic word to reject .pyc files generated by other Python versions */
/* Change for each incompatible change */
/* The value of CR and LF is incorporated so if you ever read or write
   a .pyc file in text mode the magic number will be wrong; also, the
   Apple MPW compiler swaps their values, botching string constants */
/* XXX Perhaps the magic number should be frozen and a version field
   added to the .pyc file header? */
/* New way to come up with the magic number: (YEAR-1995), MONTH, DAY */
#define MAGIC (60202 | ((long)'\r'<<16) | ((long)'\n'<<24))

/* Magic word as global; note that _PyImport_Init() can change the
   value of this global to accommodate for alterations of how the
   compiler works which are enabled by command line switches. */
static long pyc_magic = MAGIC;

/* See _PyImport_FixupExtension() below */
static PyObject *extensions = NULL;

/* This table is defined in config.c: */
extern struct _inittab _PyImport_Inittab[];

struct _inittab *PyImport_Inittab = _PyImport_Inittab;

/* these tables define the module suffixes that Python recognizes */
struct filedescr * _PyImport_Filetab;

#ifdef RISCOS
static const struct filedescr _PyImport_StandardFiletab[] = {
	{"/py", "r", PY_SOURCE},
	{"/pyc", "rb", PY_COMPILED},
	{0, 0}
};
#else
static const struct filedescr _PyImport_StandardFiletab[] = {
	{".py", "r", PY_SOURCE},
	{".pyc", "rb", PY_COMPILED},
	{0, 0}
};
#endif

/* Initialize things */

void
_PyImport_Init(void)
{
	const struct filedescr *scan;
	struct filedescr *filetab;
	int countD = 0;
	int countS = 0;

	/* prepare _PyImport_Filetab: copy entries from
	   _PyImport_DynLoadFiletab and _PyImport_StandardFiletab.
	 */
	for (scan = _PyImport_DynLoadFiletab; scan->suffix != NULL; ++scan)
		++countD;
	for (scan = _PyImport_StandardFiletab; scan->suffix != NULL; ++scan)
		++countS;
	filetab = PyMem_NEW(struct filedescr, countD + countS + 1);
	memcpy(filetab, _PyImport_DynLoadFiletab,
	       countD * sizeof(struct filedescr));
	memcpy(filetab + countD, _PyImport_StandardFiletab,
	       countS * sizeof(struct filedescr));
	filetab[countD + countS].suffix = NULL;

	_PyImport_Filetab = filetab;

	if (Py_OptimizeFlag) {
		/* Replace ".pyc" with ".pyo" in _PyImport_Filetab */
		for (; filetab->suffix != NULL; filetab++) {
#ifndef RISCOS
			if (strcmp(filetab->suffix, ".pyc") == 0)
				filetab->suffix = ".pyo";
#else
			if (strcmp(filetab->suffix, "/pyc") == 0)
				filetab->suffix = "/pyo";
#endif
		}
	}

	if (Py_UnicodeFlag) {
		/* Fix the pyc_magic so that byte compiled code created
		   using the all-Unicode method doesn't interfere with
		   code created in normal operation mode. */
		pyc_magic = MAGIC + 1;
	}
}

void
_PyImport_Fini(void)
{
	Py_XDECREF(extensions);
	extensions = NULL;
	PyMem_DEL(_PyImport_Filetab);
	_PyImport_Filetab = NULL;
}


/* Locking primitives to prevent parallel imports of the same module
   in different threads to return with a partially loaded module.
   These calls are serialized by the global interpreter lock. */

#ifdef WITH_THREAD

#include "pythread.h"

static PyThread_type_lock import_lock = 0;
static long import_lock_thread = -1;
static int import_lock_level = 0;

static void
lock_import(void)
{
	long me = PyThread_get_thread_ident();
	if (me == -1)
		return; /* Too bad */
	if (import_lock == NULL)
		import_lock = PyThread_allocate_lock();
	if (import_lock_thread == me) {
		import_lock_level++;
		return;
	}
	if (import_lock_thread != -1 || !PyThread_acquire_lock(import_lock, 0)) {
		PyThreadState *tstate = PyEval_SaveThread();
		PyThread_acquire_lock(import_lock, 1);
		PyEval_RestoreThread(tstate);
	}
	import_lock_thread = me;
	import_lock_level = 1;
}

static void
unlock_import(void)
{
	long me = PyThread_get_thread_ident();
	if (me == -1)
		return; /* Too bad */
	if (import_lock_thread != me)
		Py_FatalError("unlock_import: not holding the import lock");
	import_lock_level--;
	if (import_lock_level == 0) {
		import_lock_thread = -1;
		PyThread_release_lock(import_lock);
	}
}

#else

#define lock_import()
#define unlock_import()

#endif

/* Helper for sys */

static inline PyObject *
PyImport_GetModuleDict(void)
{
	PyInterpreterState *interp = PyThreadState_Get()->interp;
	if (interp->modules == NULL)
		Py_FatalError("PyImport_GetModuleDict: no module dictionary!");
	return interp->modules;
}


/* List of names to clear in sys */
static char* sys_deletes[] = {
	"path", "argv", "ps1", "ps2", "exitfunc",
	"exc_type", "exc_value", "exc_traceback",
	"last_type", "last_value", "last_traceback",
	NULL
};

static char* sys_files[] = {
	"stdin", "__stdin__",
	"stdout", "__stdout__",
	"stderr", "__stderr__",
	NULL
};


/* Un-initialize things, as good as we can */

void
PyImport_Cleanup(void)
{
	int pos, ndone;
	char *name;
	PyObject *key, *value, *dict;
	PyInterpreterState *interp = PyThreadState_Get()->interp;
	PyObject *modules = interp->modules;

	if (modules == NULL)
		return; /* Already done */

	/* Delete some special variables first.  These are common
	   places where user values hide and people complain when their
	   destructors fail.  Since the modules containing them are
	   deleted *last* of all, they would come too late in the normal
	   destruction order.  Sigh. */

	value = PyDict_GetItemString(modules, "__builtin__");
	if (value != NULL && PyModule_Check(value)) {
		dict = PyModule_GetDict(value);
		if (Py_VerboseFlag)
			PySys_WriteStderr("# clear __builtin__._\n");
		PyDict_SetItemString(dict, "_", Py_None);
	}
	value = PyDict_GetItemString(modules, "sys");
	if (value != NULL && PyModule_Check(value)) {
		char **p;
		PyObject *v;
		dict = PyModule_GetDict(value);
		for (p = sys_deletes; *p != NULL; p++) {
			if (Py_VerboseFlag)
				PySys_WriteStderr("# clear sys.%s\n", *p);
			PyDict_SetItemString(dict, *p, Py_None);
		}
		for (p = sys_files; *p != NULL; p+=2) {
			if (Py_VerboseFlag)
				PySys_WriteStderr("# restore sys.%s\n", *p);
			v = PyDict_GetItemString(dict, *(p+1));
			if (v == NULL)
				v = Py_None;
			PyDict_SetItemString(dict, *p, v);
		}
	}

	/* First, delete __main__ */
	value = PyDict_GetItemString(modules, "__main__");
	if (value != NULL && PyModule_Check(value)) {
		if (Py_VerboseFlag)
			PySys_WriteStderr("# cleanup __main__\n");
		_PyModule_Clear(value);
		PyDict_SetItemString(modules, "__main__", Py_None);
	}

	/* The special treatment of __builtin__ here is because even
	   when it's not referenced as a module, its dictionary is
	   referenced by almost every module's __builtins__.  Since
	   deleting a module clears its dictionary (even if there are
	   references left to it), we need to delete the __builtin__
	   module last.  Likewise, we don't delete sys until the very
	   end because it is implicitly referenced (e.g. by print).

	   Also note that we 'delete' modules by replacing their entry
	   in the modules dict with None, rather than really deleting
	   them; this avoids a rehash of the modules dictionary and
	   also marks them as "non existent" so they won't be
	   re-imported. */

	/* Next, repeatedly delete modules with a reference count of
	   one (skipping __builtin__ and sys) and delete them */
	do {
		ndone = 0;
		pos = 0;
		while (PyDict_Next(modules, &pos, &key, &value)) {
			if (value->ob_refcnt != 1)
				continue;
			if (PyString_Check(key) && PyModule_Check(value)) {
				name = PyString_AS_STRING(key);
				if (strcmp(name, "__builtin__") == 0)
					continue;
				if (strcmp(name, "sys") == 0)
					continue;
				if (Py_VerboseFlag)
					PySys_WriteStderr(
						"# cleanup[1] %s\n", name);
				_PyModule_Clear(value);
				PyDict_SetItem(modules, key, Py_None);
				ndone++;
			}
		}
	} while (ndone > 0);

	/* Next, delete all modules (still skipping __builtin__ and sys) */
	pos = 0;
	while (PyDict_Next(modules, &pos, &key, &value)) {
		if (PyString_Check(key) && PyModule_Check(value)) {
			name = PyString_AS_STRING(key);
			if (strcmp(name, "__builtin__") == 0)
				continue;
			if (strcmp(name, "sys") == 0)
				continue;
			if (Py_VerboseFlag)
				PySys_WriteStderr("# cleanup[2] %s\n", name);
			_PyModule_Clear(value);
			PyDict_SetItem(modules, key, Py_None);
		}
	}

	/* Next, delete sys and __builtin__ (in that order) */
	value = PyDict_GetItemString(modules, "sys");
	if (value != NULL && PyModule_Check(value)) {
		if (Py_VerboseFlag)
			PySys_WriteStderr("# cleanup sys\n");
		_PyModule_Clear(value);
		PyDict_SetItemString(modules, "sys", Py_None);
	}
	value = PyDict_GetItemString(modules, "__builtin__");
	if (value != NULL && PyModule_Check(value)) {
		if (Py_VerboseFlag)
			PySys_WriteStderr("# cleanup __builtin__\n");
		_PyModule_Clear(value);
		PyDict_SetItemString(modules, "__builtin__", Py_None);
	}

	/* Finally, clear and delete the modules directory */
	PyDict_Clear(modules);
	interp->modules = NULL;
	Py_DECREF(modules);
}


/* Helper for pythonrun.c -- return magic number */

static inline long
PyImport_GetMagicNumber(void)
{
	return pyc_magic;
}


/* Magic for extension modules (built-in as well as dynamically
   loaded).  To prevent initializing an extension module more than
   once, we keep a static dictionary 'extensions' keyed by module name
   (for built-in modules) or by filename (for dynamically loaded
   modules), containing these modules.  A copy od the module's
   dictionary is stored by calling _PyImport_FixupExtension()
   immediately after the module initialization function succeeds.  A
   copy can be retrieved from there by calling
   _PyImport_FindExtension(). */

PyObject *
_PyImport_FixupExtension(char *name, char *filename)
{
	PyObject *modules, *mod, *dict, *copy;
	if (extensions == NULL) {
		extensions = PyDict_New();
		if (extensions == NULL)
			return NULL;
	}
	modules = PyImport_GetModuleDict();
	mod = PyDict_GetItemString(modules, name);
	if (mod == NULL || !PyModule_Check(mod)) {
		PyErr_Format(PyExc_SystemError,
		  "_PyImport_FixupExtension: module %.200s not loaded", name);
		return NULL;
	}
	dict = PyModule_GetDict(mod);
	if (dict == NULL)
		return NULL;
	copy = PyObject_CallMethod(dict, "copy", "");
	if (copy == NULL)
		return NULL;
	PyDict_SetItemString(extensions, filename, copy);
	Py_DECREF(copy);
	return copy;
}

static inline PyObject *
_PyImport_FindExtension(char *name, char *filename)
{
	PyObject *dict, *mod, *mdict, *result;
	if (extensions == NULL)
		return NULL;
	dict = PyDict_GetItemString(extensions, filename);
	if (dict == NULL)
		return NULL;
	mod = PyImport_AddModule(name);
	if (mod == NULL)
		return NULL;
	mdict = PyModule_GetDict(mod);
	if (mdict == NULL)
		return NULL;
	result = PyObject_CallMethod(mdict, "update", "O", dict);
	if (result == NULL)
		return NULL;
	Py_DECREF(result);
	if (Py_VerboseFlag)
		PySys_WriteStderr("import %s # previously loaded (%s)\n",
			name, filename);
	return mod;
}


/* Get the module object corresponding to a module name.
   First check the modules dictionary if there's one there,
   if not, create a new one and insert in in the modules dictionary.
   Because the former action is most common, THIS DOES NOT RETURN A
   'NEW' REFERENCE! */

PyObject *
PyImport_AddModule(char *name)
{
	PyObject *modules = PyImport_GetModuleDict();
	PyObject *m;

	if ((m = PyDict_GetItemString(modules, name)) != NULL &&
	    PyModule_Check(m))
		return m;
	m = PyModule_New(name);
	if (m == NULL)
		return NULL;
	if (PyDict_SetItemString(modules, name, m) != 0) {
		Py_DECREF(m);
		return NULL;
	}
	Py_DECREF(m); /* Yes, it still exists, in modules! */

	return m;
}


/* Execute a code object in a module and return the module object
   WITH INCREMENTED REFERENCE COUNT */

PyObject *
PyImport_ExecCodeModule(char *name, PyObject *co)
{
	return PyImport_ExecCodeModuleEx(name, co, (char *)NULL);
}

PyObject *
PyImport_ExecCodeModuleEx(char *name, PyObject *co, char *pathname)
{
	PyObject *modules = PyImport_GetModuleDict();
	PyObject *m, *d, *v;

	m = PyImport_AddModule(name);
	if (m == NULL)
		return NULL;
	d = PyModule_GetDict(m);
	if (PyDict_GetItemString(d, "__builtins__") == NULL) {
		if (PyDict_SetItemString(d, "__builtins__",
					 PyEval_GetBuiltins()) != 0)
			return NULL;
	}
	/* Remember the filename as the __file__ attribute */
	v = NULL;
	if (pathname != NULL) {
		v = PyString_FromString(pathname);
		if (v == NULL)
			PyErr_Clear();
	}
	if (v == NULL) {
		v = ((PyCodeObject *)co)->co_filename;
		Py_INCREF(v);
	}
	if (PyDict_SetItemString(d, "__file__", v) != 0)
		PyErr_Clear(); /* Not important enough to report */
	Py_DECREF(v);

	v = PyEval_EvalCode((PyCodeObject *)co, d, d);
	if (v == NULL)
		return NULL;
	Py_DECREF(v);

	if ((m = PyDict_GetItemString(modules, name)) == NULL) {
		PyErr_Format(PyExc_ImportError,
			     "Loaded module %.200s not found in sys.modules",
			     name);
		return NULL;
	}

	Py_INCREF(m);

	return m;
}


/* Given a pathname for a Python source file, fill a buffer with the
   pathname for the corresponding compiled file.  Return the pathname
   for the compiled file, or NULL if there's no space in the buffer.
   Doesn't set an exception. */

static inline char *
make_compiled_pathname(char *pathname, char *buf, size_t buflen)
{
	size_t len;

	len = strlen(pathname);
	if (len+2 > buflen)
		return NULL;
	strcpy(buf, pathname);
	strcpy(buf+len, Py_OptimizeFlag ? "o" : "c");

	return buf;
}


/* Given a pathname for a Python source file, its time of last
   modification, and a pathname for a compiled file, check whether the
   compiled file represents the same version of the source.  If so,
   return a FILE pointer for the compiled file, positioned just after
   the header; if not, return NULL.
   Doesn't set an exception. */

static inline FILE *
check_compiled_module(char *pathname, long mtime, char *cpathname)
{
	FILE *fp;
	long magic;
	long pyc_mtime;

	fp = fopen(cpathname, "rb");
	if (fp == NULL)
		return NULL;
	magic = PyMarshal_ReadLongFromFile(fp);
	if (magic != pyc_magic) {
		if (Py_VerboseFlag)
			PySys_WriteStderr("# %s has bad magic\n", cpathname);
		fclose(fp);
		return NULL;
	}
	pyc_mtime = PyMarshal_ReadLongFromFile(fp);
	if (pyc_mtime != mtime) {
		if (Py_VerboseFlag)
			PySys_WriteStderr("# %s has bad mtime\n", cpathname);
		fclose(fp);
		return NULL;
	}
	if (Py_VerboseFlag)
		PySys_WriteStderr("# %s matches %s\n", cpathname, pathname);
	return fp;
}


/* Read a code object from a file and check it for validity */

static inline PyCodeObject *
read_compiled_module(char *cpathname, FILE *fp)
{
	PyObject *co;

	co = PyMarshal_ReadLastObjectFromFile(fp);
	/* Ugly: rd_object() may return NULL with or without error */
	if (co == NULL || !PyCode_Check(co)) {
		if (!PyErr_Occurred())
			PyErr_Format(PyExc_ImportError,
			    "Non-code object in %.200s", cpathname);
		Py_XDECREF(co);
		return NULL;
	}
	return (PyCodeObject *)co;
}


/* Load a module from a compiled file, execute it, and return its
   module object WITH INCREMENTED REFERENCE COUNT */

static inline PyObject *
load_compiled_module(char *name, char *cpathname, FILE *fp)
{
	long magic;
	PyCodeObject *co;
	PyObject *m;

	magic = PyMarshal_ReadLongFromFile(fp);
	if (magic != pyc_magic) {
		PyErr_Format(PyExc_ImportError,
			     "Bad magic number in %.200s", cpathname);
		return NULL;
	}
	(void) PyMarshal_ReadLongFromFile(fp);
	co = read_compiled_module(cpathname, fp);
	if (co == NULL)
		return NULL;
	if (Py_VerboseFlag)
		PySys_WriteStderr("import %s # precompiled from %s\n",
			name, cpathname);
	m = PyImport_ExecCodeModuleEx(name, (PyObject *)co, cpathname);
	Py_DECREF(co);

	return m;
}

/* Parse a source file and return the corresponding code object */

static inline PyCodeObject *
parse_source_module(char *pathname, FILE *fp)
{
	PyCodeObject *co;
	node *n;

	n = PyParser_SimpleParseFile(fp, pathname, Py_file_input);
	if (n == NULL)
		return NULL;
	co = PyNode_Compile(n, pathname);
	PyNode_Free(n);

	return co;
}


/* Helper to open a bytecode file for writing in exclusive mode */

static inline FILE *
open_exclusive(char *filename)
{
#if defined(O_EXCL)&&defined(O_CREAT)&&defined(O_WRONLY)&&defined(O_TRUNC)
	/* Use O_EXCL to avoid a race condition when another process tries to
	   write the same file.  When that happens, our open() call fails,
	   which is just fine (since it's only a cache).
	   XXX If the file exists and is writable but the directory is not
	   writable, the file will never be written.  Oh well.
	*/
	int fd;
	(void) unlink(filename);
	fd = open(filename, O_EXCL|O_CREAT|O_WRONLY|O_TRUNC
#ifdef O_BINARY
				|O_BINARY   /* necessary for Windows */
#endif

			, 0666);
	if (fd < 0)
		return NULL;
	return fdopen(fd, "wb");
#else
	/* Best we can do -- on Windows this can't happen anyway */
	return fopen(filename, "wb");
#endif
}


/* Write a compiled module to a file, placing the time of last
   modification of its source into the header.
   Errors are ignored, if a write error occurs an attempt is made to
   remove the file. */

static inline void
write_compiled_module(PyCodeObject *co, char *cpathname, long mtime)
{
	FILE *fp;

	fp = open_exclusive(cpathname);
	if (fp == NULL) {
		if (Py_VerboseFlag)
			PySys_WriteStderr(
				"# can't create %s\n", cpathname);
		return;
	}
	PyMarshal_WriteLongToFile(pyc_magic, fp);
	/* First write a 0 for mtime */
	PyMarshal_WriteLongToFile(0L, fp);
	PyMarshal_WriteObjectToFile((PyObject *)co, fp);
	if (ferror(fp)) {
		if (Py_VerboseFlag)
			PySys_WriteStderr("# can't write %s\n", cpathname);
		/* Don't keep partial file */
		fclose(fp);
		(void) unlink(cpathname);
		return;
	}
	/* Now write the true mtime */
	fseek(fp, 4L, 0);
	PyMarshal_WriteLongToFile(mtime, fp);
	fflush(fp);
	fclose(fp);
	if (Py_VerboseFlag)
		PySys_WriteStderr("# wrote %s\n", cpathname);
#ifdef macintosh
	PyMac_setfiletype(cpathname, 'Pyth', 'PYC ');
#endif
}


/* Load a source module from a given file and return its module
   object WITH INCREMENTED REFERENCE COUNT.  If there's a matching
   byte-compiled file, use that instead. */

static PyObject *
load_source_module(char *name, char *pathname, FILE *fp)
{
	time_t mtime;
	FILE *fpc;
	char buf[MAXPATHLEN+1];
	char *cpathname;
	PyCodeObject *co;
	PyObject *m;

	mtime = PyOS_GetLastModificationTime(pathname, fp);
	if (mtime == (time_t)(-1))
		return NULL;
#if SIZEOF_TIME_T > 4
	/* Python's .pyc timestamp handling presumes that the timestamp fits
	   in 4 bytes. This will be fine until sometime in the year 2038,
	   when a 4-byte signed time_t will overflow.
	 */
	if (mtime >> 32) {
		PyErr_SetString(PyExc_OverflowError,
			"modification time overflows a 4 byte field");
		return NULL;
	}
#endif
	cpathname = make_compiled_pathname(pathname, buf, 
					   (size_t)MAXPATHLEN + 1);
	if (cpathname != NULL &&
	    (fpc = check_compiled_module(pathname, mtime, cpathname))) {
		co = read_compiled_module(cpathname, fpc);
		fclose(fpc);
		if (co == NULL)
			return NULL;
		if (Py_VerboseFlag)
			PySys_WriteStderr("import %s # precompiled from %s\n",
				name, cpathname);
		pathname = cpathname;
	}
	else {
		co = parse_source_module(pathname, fp);
		if (co == NULL)
			return NULL;
		if (Py_VerboseFlag)
			PySys_WriteStderr("import %s # from %s\n",
				name, pathname);
		write_compiled_module(co, cpathname, mtime);
	}
	m = PyImport_ExecCodeModuleEx(name, (PyObject *)co, pathname);
	Py_DECREF(co);

	return m;
}


/* Forward */
static PyObject *load_module(char *, FILE *, char *, int);
static struct filedescr *find_module(char *, PyObject *,
				     char *, size_t, FILE **);
static inline struct _frozen *find_frozen(char *name);

/* Load a package and return its module object WITH INCREMENTED
   REFERENCE COUNT */

static PyObject *
load_package(char *name, char *pathname)
{
	PyObject *m, *d, *file, *path;
	int err;
	char buf[MAXPATHLEN+1];
	FILE *fp = NULL;
	struct filedescr *fdp;

	m = PyImport_AddModule(name);
	if (m == NULL)
		return NULL;
	if (Py_VerboseFlag)
		PySys_WriteStderr("import %s # directory %s\n",
			name, pathname);
	d = PyModule_GetDict(m);
	file = PyString_FromString(pathname);
	if (file == NULL)
		return NULL;
	path = Py_BuildValue("[O]", file);
	if (path == NULL) {
		Py_DECREF(file);
		return NULL;
	}
	err = PyDict_SetItemString(d, "__file__", file);
	if (err == 0)
		err = PyDict_SetItemString(d, "__path__", path);
	if (err != 0) {
		m = NULL;
		goto cleanup;
	}
	buf[0] = '\0';
	fdp = find_module("__init__", path, buf, sizeof(buf), &fp);
	if (fdp == NULL) {
		if (PyErr_ExceptionMatches(PyExc_ImportError)) {
			PyErr_Clear();
		}
		else
			m = NULL;
		goto cleanup;
	}
	m = load_module(name, fp, buf, fdp->type);
	if (fp != NULL)
		fclose(fp);
  cleanup:
	Py_XDECREF(path);
	Py_XDECREF(file);
	return m;
}


/* Helper to test for built-in module */

static inline int
is_builtin(char *name)
{
	int i;
	for (i = 0; PyImport_Inittab[i].name != NULL; i++) {
		if (strcmp(name, PyImport_Inittab[i].name) == 0) {
			if (PyImport_Inittab[i].initfunc == NULL)
				return -1;
			else
				return 1;
		}
	}
	return 0;
}


/* Search the path (default sys.path) for a module.  Return the
   corresponding filedescr struct, and (via return arguments) the
   pathname and an open file.  Return NULL if the module is not found. */

#ifdef MS_COREDLL
extern FILE *PyWin_FindRegisteredModule(const char *, struct filedescr **,
					char *, int);
#endif

static inline int case_ok(char *, int, int, char *);
static int find_init_module(char *); /* Forward */

static struct filedescr *
find_module(char *realname, PyObject *path, char *buf, size_t buflen,
	    FILE **p_fp)
{
	int i, npath;
	size_t len, namelen;
	struct _frozen *f;
	struct filedescr *fdp = NULL;
	FILE *fp = NULL;
#ifndef RISCOS
	struct stat statbuf;
#endif
	static struct filedescr fd_frozen = {"", "", PY_FROZEN};
	static struct filedescr fd_builtin = {"", "", C_BUILTIN};
#ifdef HAVE_STAT
	static struct filedescr fd_package = {"", "", PKG_DIRECTORY};
#endif
	char name[MAXPATHLEN+1];

	if (strlen(realname) > MAXPATHLEN) {
		PyErr_SetString(PyExc_OverflowError, "module name is too long");
		return NULL;
	}
	strcpy(name, realname);

	if (path != NULL && PyString_Check(path)) {
		/* Submodule of "frozen" package:
		   Set name to the fullname, path to NULL
		   and continue as "usual" */
		if (PyString_Size(path) + 1 + strlen(name) >= (size_t)buflen) {
			PyErr_SetString(PyExc_ImportError,
					"full frozen module name too long");
			return NULL;
		}
		strcpy(buf, PyString_AsString(path));
		strcat(buf, ".");
		strcat(buf, name);
		strcpy(name, buf);
		path = NULL;
	}
	if (path == NULL) {
		if (is_builtin(name)) {
			strcpy(buf, name);
			return &fd_builtin;
		}
		if ((f = find_frozen(name)) != NULL) {
			strcpy(buf, name);
			return &fd_frozen;
		}

#ifdef MS_COREDLL
		fp = PyWin_FindRegisteredModule(name, &fdp, buf, buflen);
		if (fp != NULL) {
			*p_fp = fp;
			return fdp;
		}
#endif
		path = PySys_GetObject("path");
	}
	if (path == NULL || !PyList_Check(path)) {
		PyErr_SetString(PyExc_ImportError,
				"sys.path must be a list of directory names");
		return NULL;
	}
	npath = PyList_Size(path);
	namelen = strlen(name);
	for (i = 0; i < npath; i++) {
		PyObject *v = PyList_GetItem(path, i);
		if (!PyString_Check(v))
			continue;
		len = PyString_Size(v);
		if (len + 2 + namelen + MAXSUFFIXSIZE >= buflen)
			continue; /* Too long */
		strcpy(buf, PyString_AsString(v));
		if (strlen(buf) != len)
			continue; /* v contains '\0' */
#ifdef macintosh
#ifdef INTERN_STRINGS
		/*
		** Speedup: each sys.path item is interned, and
		** FindResourceModule remembers which items refer to
		** folders (so we don't have to bother trying to look
		** into them for resources).
		*/
		PyString_InternInPlace(&PyList_GET_ITEM(path, i));
		v = PyList_GET_ITEM(path, i);
#endif
		if (PyMac_FindResourceModule((PyStringObject *)v, name, buf)) {
			static struct filedescr resfiledescr =
				{"", "", PY_RESOURCE};

			return &resfiledescr;
		}
		if (PyMac_FindCodeResourceModule((PyStringObject *)v, name, buf)) {
			static struct filedescr resfiledescr =
				{"", "", PY_CODERESOURCE};

			return &resfiledescr;
		}
#endif
		if (len > 0 && buf[len-1] != SEP
#ifdef ALTSEP
		    && buf[len-1] != ALTSEP
#endif
		    )
			buf[len++] = SEP;
		strcpy(buf+len, name);
		len += namelen;

		/* Check for package import (buf holds a directory name,
		   and there's an __init__ module in that directory */
#ifdef HAVE_STAT
		if (stat(buf, &statbuf) == 0 &&
		    S_ISDIR(statbuf.st_mode) &&
		    find_init_module(buf)) {
			if (case_ok(buf, len, namelen, name))
				return &fd_package;
			else
				return NULL;
		}
#else
		/* XXX How are you going to test for directories? */
#ifdef RISCOS
		{
			static struct filedescr fd = {"", "", PKG_DIRECTORY};
			if (isdir(buf)) {
				if (find_init_module(buf))
					return &fd;
			}
		}
#endif
#endif
#ifdef macintosh
		fdp = PyMac_FindModuleExtension(buf, &len, name);
		if (fdp) {
#else
		for (fdp = _PyImport_Filetab; fdp->suffix != NULL; fdp++) {
			strcpy(buf+len, fdp->suffix);
			if (Py_VerboseFlag > 1)
				PySys_WriteStderr("# trying %s\n", buf);
#endif /* !macintosh */
			fp = fopen(buf, fdp->mode);
			if (fp != NULL) {
				if (case_ok(buf, len, namelen, name))
					break;
				else {	 /* continue search */
					fclose(fp);
					fp = NULL;
				}
			}
		}
		if (fp != NULL)
			break;
	}
	if (fp == NULL) {
		PyErr_Format(PyExc_ImportError,
			     "No module named %.200s", name);
		return NULL;
	}
	*p_fp = fp;
	return fdp;
}

/* case_ok(char* buf, int len, int namelen, char* name)
 * The arguments here are tricky, best shown by example:
 *    /a/b/c/d/e/f/g/h/i/j/k/some_long_module_name.py\0
 *    ^                      ^                   ^    ^
 *    |--------------------- buf ---------------------|
 *    |------------------- len ------------------|
 *                           |------ name -------|
 *                           |----- namelen -----|
 * buf is the full path, but len only counts up to (& exclusive of) the
 * extension.  name is the module name, also exclusive of extension.
 *
 * We've already done a successful stat() or fopen() on buf, so know that
 * there's some match, possibly case-insensitive.
 *
 * case_ok() is to return 1 if there's a case-sensitive match for
 * name, else 0.  case_ok() is also to return 1 if envar PYTHONCASEOK
 * exists.
 *
 * case_ok() is used to implement case-sensitive import semantics even
 * on platforms with case-insensitive filesystems.  It's trivial to implement
 * for case-sensitive filesystems.  It's pretty much a cross-platform
 * nightmare for systems with case-insensitive filesystems.
 */

/* First we may need a pile of platform-specific header files; the sequence
 * of #if's here should match the sequence in the body of case_ok().
 */
#if defined(MS_WIN32) || defined(__CYGWIN__)
#include <windows.h>
#ifdef __CYGWIN__
#include <sys/cygwin.h>
#endif

#elif defined(DJGPP)
#include <dir.h>

#elif defined(macintosh)
#include <TextUtils.h>
#ifdef USE_GUSI1
#include "TFileSpec.h"		/* for Path2FSSpec() */
#endif

#elif defined(__MACH__) && defined(__APPLE__) && defined(HAVE_DIRENT_H)
#include <sys/types.h>
#include <dirent.h>

#endif

static inline int
case_ok(char *buf, int len, int namelen, char *name)
{
/* Pick a platform-specific implementation; the sequence of #if's here should
 * match the sequence just above.
 */

/* MS_WIN32 || __CYGWIN__ */
#if defined(MS_WIN32) || defined(__CYGWIN__)
	WIN32_FIND_DATA data;
	HANDLE h;
#ifdef __CYGWIN__
	char tempbuf[MAX_PATH];
#endif

	if (getenv("PYTHONCASEOK") != NULL)
		return 1;

#ifdef __CYGWIN__
	cygwin32_conv_to_win32_path(buf, tempbuf);
	h = FindFirstFile(tempbuf, &data);
#else
	h = FindFirstFile(buf, &data);
#endif
	if (h == INVALID_HANDLE_VALUE) {
		PyErr_Format(PyExc_NameError,
		  "Can't find file for module %.100s\n(filename %.300s)",
		  name, buf);
		return 0;
	}
	FindClose(h);
	return strncmp(data.cFileName, name, namelen) == 0;

/* DJGPP */
#elif defined(DJGPP)
	struct ffblk ffblk;
	int done;

	if (getenv("PYTHONCASEOK") != NULL)
		return 1;

	done = findfirst(buf, &ffblk, FA_ARCH|FA_RDONLY|FA_HIDDEN|FA_DIREC);
	if (done) {
		PyErr_Format(PyExc_NameError,
		  "Can't find file for module %.100s\n(filename %.300s)",
		  name, buf);
		return 0;
	}
	return strncmp(ffblk.ff_name, name, namelen) == 0;

/* macintosh */
#elif defined(macintosh)
	FSSpec fss;
	OSErr err;

	if (getenv("PYTHONCASEOK") != NULL)
		return 1;

#ifndef USE_GUSI1
	err = FSMakeFSSpec(0, 0, Pstring(buf), &fss);
#else
	/* GUSI's Path2FSSpec() resolves all possible aliases nicely on
	   the way, which is fine for all directories, but here we need
	   the original name of the alias file (say, Dlg.ppc.slb, not
	   toolboxmodules.ppc.slb). */
	char *colon;
	err = Path2FSSpec(buf, &fss);
	if (err == noErr) {
		colon = strrchr(buf, ':'); /* find filename */
		if (colon != NULL)
			err = FSMakeFSSpec(fss.vRefNum, fss.parID,
					   Pstring(colon+1), &fss);
		else
			err = FSMakeFSSpec(fss.vRefNum, fss.parID,
					   fss.name, &fss);
	}
#endif
	if (err) {
		PyErr_Format(PyExc_NameError,
		     "Can't find file for module %.100s\n(filename %.300s)",
		     name, buf);
		return 0;
	}
	return fss.name[0] >= namelen &&
	       strncmp(name, (char *)fss.name+1, namelen) == 0;

/* new-fangled macintosh (macosx) */
#elif defined(__MACH__) && defined(__APPLE__) && defined(HAVE_DIRENT_H)
	DIR *dirp;
	struct dirent *dp;
	char dirname[MAXPATHLEN + 1];
	const int dirlen = len - namelen - 1; /* don't want trailing SEP */

	if (getenv("PYTHONCASEOK") != NULL)
		return 1;

	/* Copy the dir component into dirname; substitute "." if empty */
	if (dirlen <= 0) {
		dirname[0] = '.';
		dirname[1] = '\0';
	}
	else {
		assert(dirlen <= MAXPATHLEN);
		memcpy(dirname, buf, dirlen);
		dirname[dirlen] = '\0';
	}
	/* Open the directory and search the entries for an exact match. */
	dirp = opendir(dirname);
	if (dirp) {
		char *nameWithExt = buf + len - namelen;
		while ((dp = readdir(dirp)) != NULL) {
			const int thislen =
#ifdef _DIRENT_HAVE_D_NAMELEN
						dp->d_namlen;
#else
						strlen(dp->d_name);
#endif
			if (thislen >= namelen &&
			    strcmp(dp->d_name, nameWithExt) == 0) {
				(void)closedir(dirp);
				return 1; /* Found */
			}
		}
		(void)closedir(dirp);
	}
	return 0 ; /* Not found */

/* assuming it's a case-sensitive filesystem, so there's nothing to do! */
#else
	return 1;

#endif
}


#ifdef HAVE_STAT
/* Helper to look for __init__.py or __init__.py[co] in potential package */
static int
find_init_module(char *buf)
{
	size_t save_len = strlen(buf);
	size_t i = save_len;
	struct stat statbuf;

	if (save_len + 13 >= MAXPATHLEN)
		return 0;
	buf[i++] = SEP;
	strcpy(buf+i, "__init__.py");
	if (stat(buf, &statbuf) == 0) {
		buf[save_len] = '\0';
		return 1;
	}
	i += strlen(buf+i);
	if (Py_OptimizeFlag)
		strcpy(buf+i, "o");
	else
		strcpy(buf+i, "c");
	if (stat(buf, &statbuf) == 0) {
		buf[save_len] = '\0';
		return 1;
	}
	buf[save_len] = '\0';
	return 0;
}

#else

#ifdef RISCOS
static int
find_init_module(buf)
	char *buf;
{
	int save_len = strlen(buf);
	int i = save_len;

	if (save_len + 13 >= MAXPATHLEN)
		return 0;
	buf[i++] = SEP;
	strcpy(buf+i, "__init__/py");
	if (isfile(buf)) {
		buf[save_len] = '\0';
		return 1;
	}

	if (Py_OptimizeFlag)
		strcpy(buf+i, "o");
	else
		strcpy(buf+i, "c");
	if (isfile(buf)) {
		buf[save_len] = '\0';
		return 1;
	}
	buf[save_len] = '\0';
	return 0;
}
#endif /*RISCOS*/

#endif /* HAVE_STAT */


static inline int init_builtin(char *); /* Forward */

/* Load an external module using the default search path and return
   its module object WITH INCREMENTED REFERENCE COUNT */

static PyObject *
load_module(char *name, FILE *fp, char *buf, int type)
{
	PyObject *modules;
	PyObject *m;
	int err;

	/* First check that there's an open file (if we need one)  */
	switch (type) {
	case PY_SOURCE:
	case PY_COMPILED:
		if (fp == NULL) {
			PyErr_Format(PyExc_ValueError,
			   "file object required for import (type code %d)",
				     type);
			return NULL;
		}
	}

	switch (type) {

	case PY_SOURCE:
		m = load_source_module(name, buf, fp);
		break;

	case PY_COMPILED:
		m = load_compiled_module(name, buf, fp);
		break;

#ifdef HAVE_DYNAMIC_LOADING
	case C_EXTENSION:
		m = _PyImport_LoadDynamicModule(name, buf, fp);
		break;
#endif

#ifdef macintosh
	case PY_RESOURCE:
		m = PyMac_LoadResourceModule(name, buf);
		break;
	case PY_CODERESOURCE:
		m = PyMac_LoadCodeResourceModule(name, buf);
		break;
#endif

	case PKG_DIRECTORY:
		m = load_package(name, buf);
		break;

	case C_BUILTIN:
	case PY_FROZEN:
		if (buf != NULL && buf[0] != '\0')
			name = buf;
		if (type == C_BUILTIN)
			err = init_builtin(name);
		else
			err = PyImport_ImportFrozenModule(name);
		if (err < 0)
			return NULL;
		if (err == 0) {
			PyErr_Format(PyExc_ImportError,
				     "Purported %s module %.200s not found",
				     type == C_BUILTIN ?
						"builtin" : "frozen",
				     name);
			return NULL;
		}
		modules = PyImport_GetModuleDict();
		m = PyDict_GetItemString(modules, name);
		if (m == NULL) {
			PyErr_Format(
				PyExc_ImportError,
				"%s module %.200s not properly initialized",
				type == C_BUILTIN ?
					"builtin" : "frozen",
				name);
			return NULL;
		}
		Py_INCREF(m);
		break;

	default:
		PyErr_Format(PyExc_ImportError,
			     "Don't know how to import %.200s (type code %d)",
			      name, type);
		m = NULL;

	}

	return m;
}


/* Initialize a built-in module.
   Return 1 for succes, 0 if the module is not found, and -1 with
   an exception set if the initialization failed. */

static inline int
init_builtin(char *name)
{
	struct _inittab *p;
	PyObject *mod;

	if ((mod = _PyImport_FindExtension(name, name)) != NULL)
		return 1;

	for (p = PyImport_Inittab; p->name != NULL; p++) {
		if (strcmp(name, p->name) == 0) {
			if (p->initfunc == NULL) {
				PyErr_Format(PyExc_ImportError,
				    "Cannot re-init internal module %.200s",
				    name);
				return -1;
			}
			if (Py_VerboseFlag)
				PySys_WriteStderr("import %s # builtin\n", name);
			(*p->initfunc)();
			if (PyErr_Occurred())
				return -1;
			if (_PyImport_FixupExtension(name, name) == NULL)
				return -1;
			return 1;
		}
	}
	return 0;
}


/* Frozen modules */

static inline struct _frozen *
find_frozen(char *name)
{
	struct _frozen *p;

	for (p = PyImport_FrozenModules; ; p++) {
		if (p->name == NULL)
			return NULL;
		if (strcmp(p->name, name) == 0)
			break;
	}
	return p;
}

static inline PyObject *
get_frozen_object(char *name)
{
	struct _frozen *p = find_frozen(name);
	int size;

	if (p == NULL) {
		PyErr_Format(PyExc_ImportError,
			     "No such frozen object named %.200s",
			     name);
		return NULL;
	}
	size = p->size;
	if (size < 0)
		size = -size;
	return PyMarshal_ReadObjectFromString((char *)p->code, size);
}

/* Initialize a frozen module.
   Return 1 for succes, 0 if the module is not found, and -1 with
   an exception set if the initialization failed.
   This function is also used from frozenmain.c */

int
PyImport_ImportFrozenModule(char *name)
{
	struct _frozen *p = find_frozen(name);
	PyObject *co;
	PyObject *m;
	int ispackage;
	int size;

	if (p == NULL)
		return 0;
	size = p->size;
	ispackage = (size < 0);
	if (ispackage)
		size = -size;
	if (Py_VerboseFlag)
		PySys_WriteStderr("import %s # frozen%s\n",
			name, ispackage ? " package" : "");
	co = PyMarshal_ReadObjectFromString((char *)p->code, size);
	if (co == NULL)
		return -1;
	if (!PyCode_Check(co)) {
		Py_DECREF(co);
		PyErr_Format(PyExc_TypeError,
			     "frozen object %.200s is not a code object",
			     name);
		return -1;
	}
	if (ispackage) {
		/* Set __path__ to the package name */
		PyObject *d, *s;
		int err;
		m = PyImport_AddModule(name);
		if (m == NULL)
			return -1;
		d = PyModule_GetDict(m);
		s = PyString_InternFromString(name);
		if (s == NULL)
			return -1;
		err = PyDict_SetItemString(d, "__path__", s);
		Py_DECREF(s);
		if (err != 0)
			return err;
	}
	m = PyImport_ExecCodeModuleEx(name, co, "<frozen>");
	Py_DECREF(co);
	if (m == NULL)
		return -1;
	Py_DECREF(m);
	return 1;
}


/* Import a module, either built-in, frozen, or external, and return
   its module object WITH INCREMENTED REFERENCE COUNT */

PyObject *
PyImport_ImportModule(char *name)
{
	PyObject *pname;
	PyObject *result;

	pname = PyString_FromString(name);
	result = PyImport_Import(pname);
	Py_DECREF(pname);
	return result;
}

/* Forward declarations for helper routines */
static PyObject *get_parent(PyObject *globals, char *buf, int *p_buflen);
static PyObject *load_next(PyObject *mod, PyObject *altmod,
			   char **p_name, char *buf, int *p_buflen);
static inline int mark_miss(char *name);
static int ensure_fromlist(PyObject *mod, PyObject *fromlist,
			   char *buf, int buflen, int recursive);
static PyObject * import_submodule(PyObject *mod, char *name, char *fullname);

/* The Magnum Opus of dotted-name import :-) */

static PyObject *
import_module_ex(char *name, PyObject *globals, PyObject *locals,
		 PyObject *fromlist)
{
	char buf[MAXPATHLEN+1];
	int buflen = 0;
	PyObject *parent, *head, *next, *tail;

	parent = get_parent(globals, buf, &buflen);
	if (parent == NULL)
		return NULL;

	head = load_next(parent, Py_None, &name, buf, &buflen);
	if (head == NULL)
		return NULL;

	tail = head;
	Py_INCREF(tail);
	while (name) {
		next = load_next(tail, tail, &name, buf, &buflen);
		Py_DECREF(tail);
		if (next == NULL) {
			Py_DECREF(head);
			return NULL;
		}
		tail = next;
	}

	if (fromlist != NULL) {
		if (fromlist == Py_None || !PyObject_IsTrue(fromlist))
			fromlist = NULL;
	}

	if (fromlist == NULL) {
		Py_DECREF(tail);
		return head;
	}

	Py_DECREF(head);
	if (!ensure_fromlist(tail, fromlist, buf, buflen, 0)) {
		Py_DECREF(tail);
		return NULL;
	}

	return tail;
}

PyObject *
PyImport_ImportModuleEx(char *name, PyObject *globals, PyObject *locals,
			PyObject *fromlist)
{
	PyObject *result;
	lock_import();
	result = import_module_ex(name, globals, locals, fromlist);
	unlock_import();
	return result;
}

static PyObject *
get_parent(PyObject *globals, char *buf, int *p_buflen)
{
	static PyObject *pathstr;
	static PyObject *namestr;
	PyObject *modname, *modpath, *modules, *parent;

	if (globals == NULL || !PyDict_Check(globals))
		return Py_None;

	if (namestr == NULL) {
		namestr = PyString_InternFromString("__name__");
		if (namestr == NULL)
			return NULL;
	}
	if (pathstr == NULL) {
		pathstr = PyString_InternFromString("__path__");
		if (pathstr == NULL)
			return NULL;
	}

	*buf = '\0';
	*p_buflen = 0;
	modname = PyDict_GetItem(globals, namestr);
	if (modname == NULL || !PyString_Check(modname))
		return Py_None;

	modpath = PyDict_GetItem(globals, pathstr);
	if (modpath != NULL) {
		int len = PyString_GET_SIZE(modname);
		if (len > MAXPATHLEN) {
			PyErr_SetString(PyExc_ValueError,
					"Module name too long");
			return NULL;
		}
		strcpy(buf, PyString_AS_STRING(modname));
		*p_buflen = len;
	}
	else {
		char *start = PyString_AS_STRING(modname);
		char *lastdot = strrchr(start, '.');
		size_t len;
		if (lastdot == NULL)
			return Py_None;
		len = lastdot - start;
		if (len >= MAXPATHLEN) {
			PyErr_SetString(PyExc_ValueError,
					"Module name too long");
			return NULL;
		}
		strncpy(buf, start, len);
		buf[len] = '\0';
		*p_buflen = len;
	}

	modules = PyImport_GetModuleDict();
	parent = PyDict_GetItemString(modules, buf);
	if (parent == NULL)
		parent = Py_None;
	return parent;
	/* We expect, but can't guarantee, if parent != None, that:
	   - parent.__name__ == buf
	   - parent.__dict__ is globals
	   If this is violated...  Who cares? */
}

/* altmod is either None or same as mod */
static PyObject *
load_next(PyObject *mod, PyObject *altmod, char **p_name, char *buf,
	  int *p_buflen)
{
	char *name = *p_name;
	char *dot = strchr(name, '.');
	size_t len;
	char *p;
	PyObject *result;

	if (dot == NULL) {
		*p_name = NULL;
		len = strlen(name);
	}
	else {
		*p_name = dot+1;
		len = dot-name;
	}
	if (len == 0) {
		PyErr_SetString(PyExc_ValueError,
				"Empty module name");
		return NULL;
	}

	p = buf + *p_buflen;
	if (p != buf)
		*p++ = '.';
	if (p+len-buf >= MAXPATHLEN) {
		PyErr_SetString(PyExc_ValueError,
				"Module name too long");
		return NULL;
	}
	strncpy(p, name, len);
	p[len] = '\0';
	*p_buflen = p+len-buf;

	result = import_submodule(mod, p, buf);
	if (result == Py_None && altmod != mod) {
		Py_DECREF(result);
		/* Here, altmod must be None and mod must not be None */
		result = import_submodule(altmod, p, p);
		if (result != NULL && result != Py_None) {
			if (mark_miss(buf) != 0) {
				Py_DECREF(result);
				return NULL;
			}
			strncpy(buf, name, len);
			buf[len] = '\0';
			*p_buflen = len;
		}
	}
	if (result == NULL)
		return NULL;

	if (result == Py_None) {
		Py_DECREF(result);
		PyErr_Format(PyExc_ImportError,
			     "No module named %.200s", name);
		return NULL;
	}

	return result;
}

static inline int
mark_miss(char *name)
{
	PyObject *modules = PyImport_GetModuleDict();
	return PyDict_SetItemString(modules, name, Py_None);
}

static int
ensure_fromlist(PyObject *mod, PyObject *fromlist, char *buf, int buflen,
		int recursive)
{
	int i;

	if (!PyObject_HasAttrString(mod, "__path__"))
		return 1;

	for (i = 0; ; i++) {
		PyObject *item = PySequence_GetItem(fromlist, i);
		int hasit;
		if (item == NULL) {
			if (PyErr_ExceptionMatches(PyExc_IndexError)) {
				PyErr_Clear();
				return 1;
			}
			return 0;
		}
		if (!PyString_Check(item)) {
			PyErr_SetString(PyExc_TypeError,
					"Item in ``from list'' not a string");
			Py_DECREF(item);
			return 0;
		}
		if (PyString_AS_STRING(item)[0] == '*') {
			PyObject *all;
			Py_DECREF(item);
			/* See if the package defines __all__ */
			if (recursive)
				continue; /* Avoid endless recursion */
			all = PyObject_GetAttrString(mod, "__all__");
			if (all == NULL)
				PyErr_Clear();
			else {
				if (!ensure_fromlist(mod, all, buf, buflen, 1))
					return 0;
				Py_DECREF(all);
			}
			continue;
		}
		hasit = PyObject_HasAttr(mod, item);
		if (!hasit) {
			char *subname = PyString_AS_STRING(item);
			PyObject *submod;
			char *p;
			if (buflen + strlen(subname) >= MAXPATHLEN) {
				PyErr_SetString(PyExc_ValueError,
						"Module name too long");
				Py_DECREF(item);
				return 0;
			}
			p = buf + buflen;
			*p++ = '.';
			strcpy(p, subname);
			submod = import_submodule(mod, subname, buf);
			Py_XDECREF(submod);
			if (submod == NULL) {
				Py_DECREF(item);
				return 0;
			}
		}
		Py_DECREF(item);
	}

	/* NOTREACHED */
}

static PyObject *
import_submodule(PyObject *mod, char *subname, char *fullname)
{
	PyObject *modules = PyImport_GetModuleDict();
	PyObject *m;

	/* Require:
	   if mod == None: subname == fullname
	   else: mod.__name__ + "." + subname == fullname
	*/

	if ((m = PyDict_GetItemString(modules, fullname)) != NULL) {
		Py_INCREF(m);
	}
	else {
		PyObject *path;
		char buf[MAXPATHLEN+1];
		struct filedescr *fdp;
		FILE *fp = NULL;

		if (mod == Py_None)
			path = NULL;
		else {
			path = PyObject_GetAttrString(mod, "__path__");
			if (path == NULL) {
				PyErr_Clear();
				Py_INCREF(Py_None);
				return Py_None;
			}
		}

		buf[0] = '\0';
		fdp = find_module(subname, path, buf, MAXPATHLEN+1, &fp);
		Py_XDECREF(path);
		if (fdp == NULL) {
			if (!PyErr_ExceptionMatches(PyExc_ImportError))
				return NULL;
			PyErr_Clear();
			Py_INCREF(Py_None);
			return Py_None;
		}
		m = load_module(fullname, fp, buf, fdp->type);
		if (fp)
			fclose(fp);
		if (m != NULL && mod != Py_None) {
			if (PyObject_SetAttrString(mod, subname, m) < 0) {
				Py_DECREF(m);
				m = NULL;
			}
		}
	}

	return m;
}


/* Re-import a module of any kind and return its module object, WITH
   INCREMENTED REFERENCE COUNT */

PyObject *
PyImport_ReloadModule(PyObject *m)
{
	PyObject *modules = PyImport_GetModuleDict();
	PyObject *path = NULL;
	char *name, *subname;
	char buf[MAXPATHLEN+1];
	struct filedescr *fdp;
	FILE *fp = NULL;

	if (m == NULL || !PyModule_Check(m)) {
		PyErr_SetString(PyExc_TypeError,
				"reload() argument must be module");
		return NULL;
	}
	name = PyModule_GetName(m);
	if (name == NULL)
		return NULL;
	if (m != PyDict_GetItemString(modules, name)) {
		PyErr_Format(PyExc_ImportError,
			     "reload(): module %.200s not in sys.modules",
			     name);
		return NULL;
	}
	subname = strrchr(name, '.');
	if (subname == NULL)
		subname = name;
	else {
		PyObject *parentname, *parent;
		parentname = PyString_FromStringAndSize(name, (subname-name));
		if (parentname == NULL)
			return NULL;
		parent = PyDict_GetItem(modules, parentname);
		Py_DECREF(parentname);
		if (parent == NULL) {
			PyErr_Format(PyExc_ImportError,
			    "reload(): parent %.200s not in sys.modules",
			    name);
			return NULL;
		}
		subname++;
		path = PyObject_GetAttrString(parent, "__path__");
		if (path == NULL)
			PyErr_Clear();
	}
	buf[0] = '\0';
	fdp = find_module(subname, path, buf, MAXPATHLEN+1, &fp);
	Py_XDECREF(path);
	if (fdp == NULL)
		return NULL;
	m = load_module(name, fp, buf, fdp->type);
	if (fp)
		fclose(fp);
	return m;
}


/* Higher-level import emulator which emulates the "import" statement
   more accurately -- it invokes the __import__() function from the
   builtins of the current globals.  This means that the import is
   done using whatever import hooks are installed in the current
   environment, e.g. by "rexec".
   A dummy list ["__doc__"] is passed as the 4th argument so that
   e.g. PyImport_Import(PyString_FromString("win32com.client.gencache"))
   will return <module "gencache"> instead of <module "win32com">. */

PyObject *
PyImport_Import(PyObject *module_name)
{
	static PyObject *silly_list = NULL;
	static PyObject *builtins_str = NULL;
	static PyObject *import_str = NULL;
	PyObject *globals = NULL;
	PyObject *import = NULL;
	PyObject *builtins = NULL;
	PyObject *r = NULL;

	/* Initialize constant string objects */
	if (silly_list == NULL) {
		import_str = PyString_InternFromString("__import__");
		if (import_str == NULL)
			return NULL;
		builtins_str = PyString_InternFromString("__builtins__");
		if (builtins_str == NULL)
			return NULL;
		silly_list = Py_BuildValue("[s]", "__doc__");
		if (silly_list == NULL)
			return NULL;
	}

	/* Get the builtins from current globals */
	globals = PyEval_GetGlobals();
	if (globals != NULL) {
	        Py_INCREF(globals);
		builtins = PyObject_GetItem(globals, builtins_str);
		if (builtins == NULL)
			goto err;
	}
	else {
		/* No globals -- use standard builtins, and fake globals */
		PyErr_Clear();

		builtins = PyImport_ImportModuleEx("__builtin__",
						   NULL, NULL, NULL);
		if (builtins == NULL)
			return NULL;
		globals = Py_BuildValue("{OO}", builtins_str, builtins);
		if (globals == NULL)
			goto err;
	}

	/* Get the __import__ function from the builtins */
	if (PyDict_Check(builtins))
		import = PyObject_GetItem(builtins, import_str);
	else
		import = PyObject_GetAttr(builtins, import_str);
	if (import == NULL)
		goto err;

	/* Call the _import__ function with the proper argument list */
	r = PyObject_CallFunction(import, "OOOO",
				  module_name, globals, globals, silly_list);

  err:
	Py_XDECREF(globals);
	Py_XDECREF(builtins);
	Py_XDECREF(import);

	return r;
}


/* Module 'imp' provides Python access to the primitives used for
   importing modules.
*/

static PyObject *
imp_get_magic(PyObject *self, PyObject *args)
{
	char buf[4];

	if (!PyArg_ParseTuple(args, ":get_magic"))
		return NULL;
	buf[0] = (char) ((pyc_magic >>  0) & 0xff);
	buf[1] = (char) ((pyc_magic >>  8) & 0xff);
	buf[2] = (char) ((pyc_magic >> 16) & 0xff);
	buf[3] = (char) ((pyc_magic >> 24) & 0xff);

	return PyString_FromStringAndSize(buf, 4);
}

static PyObject *
imp_get_suffixes(PyObject *self, PyObject *args)
{
	PyObject *list;
	struct filedescr *fdp;

	if (!PyArg_ParseTuple(args, ":get_suffixes"))
		return NULL;
	list = PyList_New(0);
	if (list == NULL)
		return NULL;
	for (fdp = _PyImport_Filetab; fdp->suffix != NULL; fdp++) {
		PyObject *item = Py_BuildValue("ssi",
				       fdp->suffix, fdp->mode, fdp->type);
		if (item == NULL) {
			Py_DECREF(list);
			return NULL;
		}
		if (PyList_Append(list, item) < 0) {
			Py_DECREF(list);
			Py_DECREF(item);
			return NULL;
		}
		Py_DECREF(item);
	}
	return list;
}

static PyObject *
call_find_module(char *name, PyObject *path)
{
	extern int fclose(FILE *);
	PyObject *fob, *ret;
	struct filedescr *fdp;
	char pathname[MAXPATHLEN+1];
	FILE *fp = NULL;

	pathname[0] = '\0';
	if (path == Py_None)
		path = NULL;
	fdp = find_module(name, path, pathname, MAXPATHLEN+1, &fp);
	if (fdp == NULL)
		return NULL;
	if (fp != NULL) {
		fob = PyFile_FromFile(fp, pathname, fdp->mode, fclose);
		if (fob == NULL) {
			fclose(fp);
			return NULL;
		}
	}
	else {
		fob = Py_None;
		Py_INCREF(fob);
	}
	ret = Py_BuildValue("Os(ssi)",
		      fob, pathname, fdp->suffix, fdp->mode, fdp->type);
	Py_DECREF(fob);
	return ret;
}

static PyObject *
imp_find_module(PyObject *self, PyObject *args)
{
	char *name;
	PyObject *path = NULL;
	if (!PyArg_ParseTuple(args, "s|O:find_module", &name, &path))
		return NULL;
	return call_find_module(name, path);
}

static PyObject *
imp_init_builtin(PyObject *self, PyObject *args)
{
	char *name;
	int ret;
	PyObject *m;
	if (!PyArg_ParseTuple(args, "s:init_builtin", &name))
		return NULL;
	ret = init_builtin(name);
	if (ret < 0)
		return NULL;
	if (ret == 0) {
		Py_INCREF(Py_None);
		return Py_None;
	}
	m = PyImport_AddModule(name);
	Py_XINCREF(m);
	return m;
}

static PyObject *
imp_init_frozen(PyObject *self, PyObject *args)
{
	char *name;
	int ret;
	PyObject *m;
	if (!PyArg_ParseTuple(args, "s:init_frozen", &name))
		return NULL;
	ret = PyImport_ImportFrozenModule(name);
	if (ret < 0)
		return NULL;
	if (ret == 0) {
		Py_INCREF(Py_None);
		return Py_None;
	}
	m = PyImport_AddModule(name);
	Py_XINCREF(m);
	return m;
}

static PyObject *
imp_get_frozen_object(PyObject *self, PyObject *args)
{
	char *name;

	if (!PyArg_ParseTuple(args, "s:get_frozen_object", &name))
		return NULL;
	return get_frozen_object(name);
}

static PyObject *
imp_is_builtin(PyObject *self, PyObject *args)
{
	char *name;
	if (!PyArg_ParseTuple(args, "s:is_builtin", &name))
		return NULL;
	return PyInt_FromLong(is_builtin(name));
}

static PyObject *
imp_is_frozen(PyObject *self, PyObject *args)
{
	char *name;
	struct _frozen *p;
	if (!PyArg_ParseTuple(args, "s:is_frozen", &name))
		return NULL;
	p = find_frozen(name);
	return PyInt_FromLong((long) (p == NULL ? 0 : p->size));
}

static inline FILE *
get_file(char *pathname, PyObject *fob, char *mode)
{
	FILE *fp;
	if (fob == NULL) {
		fp = fopen(pathname, mode);
		if (fp == NULL)
			PyErr_SetFromErrno(PyExc_IOError);
	}
	else {
		fp = PyFile_AsFile(fob);
		if (fp == NULL)
			PyErr_SetString(PyExc_ValueError,
					"bad/closed file object");
	}
	return fp;
}

static PyObject *
imp_load_compiled(PyObject *self, PyObject *args)
{
	char *name;
	char *pathname;
	PyObject *fob = NULL;
	PyObject *m;
	FILE *fp;
	if (!PyArg_ParseTuple(args, "ss|O!:load_compiled", &name, &pathname,
			      &PyFile_Type, &fob))
		return NULL;
	fp = get_file(pathname, fob, "rb");
	if (fp == NULL)
		return NULL;
	m = load_compiled_module(name, pathname, fp);
	if (fob == NULL)
		fclose(fp);
	return m;
}

#ifdef HAVE_DYNAMIC_LOADING

static PyObject *
imp_load_dynamic(PyObject *self, PyObject *args)
{
	char *name;
	char *pathname;
	PyObject *fob = NULL;
	PyObject *m;
	FILE *fp = NULL;
	if (!PyArg_ParseTuple(args, "ss|O!:load_dynamic", &name, &pathname,
			      &PyFile_Type, &fob))
		return NULL;
	if (fob) {
		fp = get_file(pathname, fob, "r");
		if (fp == NULL)
			return NULL;
	}
	m = _PyImport_LoadDynamicModule(name, pathname, fp);
	return m;
}

#endif /* HAVE_DYNAMIC_LOADING */

static PyObject *
imp_load_source(PyObject *self, PyObject *args)
{
	char *name;
	char *pathname;
	PyObject *fob = NULL;
	PyObject *m;
	FILE *fp;
	if (!PyArg_ParseTuple(args, "ss|O!:load_source", &name, &pathname,
			      &PyFile_Type, &fob))
		return NULL;
	fp = get_file(pathname, fob, "r");
	if (fp == NULL)
		return NULL;
	m = load_source_module(name, pathname, fp);
	if (fob == NULL)
		fclose(fp);
	return m;
}

#ifdef macintosh
static PyObject *
imp_load_resource(PyObject *self, PyObject *args)
{
	char *name;
	char *pathname;
	PyObject *m;

	if (!PyArg_ParseTuple(args, "ss:load_resource", &name, &pathname))
		return NULL;
	m = PyMac_LoadResourceModule(name, pathname);
	return m;
}
#endif /* macintosh */

static PyObject *
imp_load_module(PyObject *self, PyObject *args)
{
	char *name;
	PyObject *fob;
	char *pathname;
	char *suffix; /* Unused */
	char *mode;
	int type;
	FILE *fp;

	if (!PyArg_ParseTuple(args, "sOs(ssi):load_module",
			      &name, &fob, &pathname,
			      &suffix, &mode, &type))
		return NULL;
	if (*mode && (*mode != 'r' || strchr(mode, '+') != NULL)) {
		PyErr_Format(PyExc_ValueError,
			     "invalid file open mode %.200s", mode);
		return NULL;
	}
	if (fob == Py_None)
		fp = NULL;
	else {
		if (!PyFile_Check(fob)) {
			PyErr_SetString(PyExc_ValueError,
				"load_module arg#2 should be a file or None");
			return NULL;
		}
		fp = get_file(pathname, fob, mode);
		if (fp == NULL)
			return NULL;
	}
	return load_module(name, fp, pathname, type);
}

static PyObject *
imp_load_package(PyObject *self, PyObject *args)
{
	char *name;
	char *pathname;
	if (!PyArg_ParseTuple(args, "ss:load_package", &name, &pathname))
		return NULL;
	return load_package(name, pathname);
}

static PyObject *
imp_new_module(PyObject *self, PyObject *args)
{
	char *name;
	if (!PyArg_ParseTuple(args, "s:new_module", &name))
		return NULL;
	return PyModule_New(name);
}

/* Doc strings */

static char doc_imp[] = "\
This module provides the components needed to build your own\n\
__import__ function.  Undocumented functions are obsolete.\n\
";

static char doc_find_module[] = "\
find_module(name, [path]) -> (file, filename, (suffix, mode, type))\n\
Search for a module.  If path is omitted or None, search for a\n\
built-in, frozen or special module and continue search in sys.path.\n\
The module name cannot contain '.'; to search for a submodule of a\n\
package, pass the submodule name and the package's __path__.\
";

static char doc_load_module[] = "\
load_module(name, file, filename, (suffix, mode, type)) -> module\n\
Load a module, given information returned by find_module().\n\
The module name must include the full package name, if any.\
";

static char doc_get_magic[] = "\
get_magic() -> string\n\
Return the magic number for .pyc or .pyo files.\
";

static char doc_get_suffixes[] = "\
get_suffixes() -> [(suffix, mode, type), ...]\n\
Return a list of (suffix, mode, type) tuples describing the files\n\
that find_module() looks for.\
";

static char doc_new_module[] = "\
new_module(name) -> module\n\
Create a new module.  Do not enter it in sys.modules.\n\
The module name must include the full package name, if any.\
";

static PyMethodDef imp_methods[] = {
	{"find_module",		imp_find_module,	1, doc_find_module},
	{"get_magic",		imp_get_magic,		1, doc_get_magic},
	{"get_suffixes",	imp_get_suffixes,	1, doc_get_suffixes},
	{"load_module",		imp_load_module,	1, doc_load_module},
	{"new_module",		imp_new_module,		1, doc_new_module},
	/* The rest are obsolete */
	{"get_frozen_object",	imp_get_frozen_object,	1},
	{"init_builtin",	imp_init_builtin,	1},
	{"init_frozen",		imp_init_frozen,	1},
	{"is_builtin",		imp_is_builtin,		1},
	{"is_frozen",		imp_is_frozen,		1},
	{"load_compiled",	imp_load_compiled,	1},
#ifdef HAVE_DYNAMIC_LOADING
	{"load_dynamic",	imp_load_dynamic,	1},
#endif
	{"load_package",	imp_load_package,	1},
#ifdef macintosh
	{"load_resource",	imp_load_resource,	1},
#endif
	{"load_source",		imp_load_source,	1},
	{NULL,			NULL}		/* sentinel */
};

static inline int
setint(PyObject *d, char *name, int value)
{
	PyObject *v;
	int err;

	v = PyInt_FromLong((long)value);
	err = PyDict_SetItemString(d, name, v);
	Py_XDECREF(v);
	return err;
}

void
initimp(void)
{
	PyObject *m, *d;

	m = Py_InitModule4("imp", imp_methods, doc_imp,
			   NULL, PYTHON_API_VERSION);
	d = PyModule_GetDict(m);

	if (setint(d, "SEARCH_ERROR", SEARCH_ERROR) < 0) goto failure;
	if (setint(d, "PY_SOURCE", PY_SOURCE) < 0) goto failure;
	if (setint(d, "PY_COMPILED", PY_COMPILED) < 0) goto failure;
	if (setint(d, "C_EXTENSION", C_EXTENSION) < 0) goto failure;
	if (setint(d, "PY_RESOURCE", PY_RESOURCE) < 0) goto failure;
	if (setint(d, "PKG_DIRECTORY", PKG_DIRECTORY) < 0) goto failure;
	if (setint(d, "C_BUILTIN", C_BUILTIN) < 0) goto failure;
	if (setint(d, "PY_FROZEN", PY_FROZEN) < 0) goto failure;
	if (setint(d, "PY_CODERESOURCE", PY_CODERESOURCE) < 0) goto failure;

  failure:
	;
}


/* API for embedding applications that want to add their own entries
   to the table of built-in modules.  This should normally be called
   *before* Py_Initialize().  When the table resize fails, -1 is
   returned and the existing table is unchanged.

   After a similar function by Just van Rossum. */

#if 0 /* Extension-table mutation APIs were not linked into GSQE78. */
static inline int
PyImport_ExtendInittab(struct _inittab *newtab)
{
	static struct _inittab *our_copy = NULL;
	struct _inittab *p;
	int i, n;

	/* Count the number of entries in both tables */
	for (n = 0; newtab[n].name != NULL; n++)
		;
	if (n == 0)
		return 0; /* Nothing to do */
	for (i = 0; PyImport_Inittab[i].name != NULL; i++)
		;

	/* Allocate new memory for the combined table */
	p = our_copy;
	PyMem_RESIZE(p, struct _inittab, i+n+1);
	if (p == NULL)
		return -1;

	/* Copy the tables into the new memory */
	if (our_copy != PyImport_Inittab)
		memcpy(p, PyImport_Inittab, (i+1) * sizeof(struct _inittab));
	PyImport_Inittab = our_copy = p;
	memcpy(p+i, newtab, (n+1) * sizeof(struct _inittab));

	return 0;
}

/* Shorthand to add a single entry given a name and a function */

static inline int
PyImport_AppendInittab(char *name, void (*initfunc)(void))
{
	struct _inittab newtab[2];

	memset(newtab, '\0', sizeof newtab);

	newtab[0].name = name;
	newtab[0].initfunc = initfunc;

	return PyImport_ExtendInittab(newtab);
}

#endif
