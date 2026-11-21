/* Marshal serialization in the Kalisto CPython runtime, GSQE78.
 * Derived from CPython 2.1 Python/marshal.c and its public headers.
 * Copyright (c) 2001 Python Software Foundation; all rights reserved.
 * Upstream license: reference/cpython-2.1/LICENSE.
 */

/* Write Python objects to files and read them back.
   This is intended for writing and reading compiled Python code only;
   a true persistent storage facility would be much harder, since
   it would have to take circular links and sharing into account. */

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


#define DL_IMPORT(type) type
#define stderr (&__files[2])
extern FILE __files[];
extern int fprintf(FILE *, const char *, ...);
#define SIZEOF_LONG 4
#define Py_SAFE_DOWNCAST(v,wide,narrow) ((narrow)(v))
#define PyFPE_START_PROTECT(err,ret)
#define PyFPE_END_PROTECT(v)
#define PyMem_NEW(type,n) ((type *)malloc(1+(n)*sizeof(type)))
#define PyMem_DEL(p) free(p)
#define Py_Ellipsis (&_Py_EllipsisObject)
#define PyFloat_Check(op) ((op)->ob_type == &PyFloat_Type)
#define PyComplex_Check(op) ((op)->ob_type == &PyComplex_Type)
#define PyUnicode_Check(op) ((op)->ob_type == &PyUnicode_Type)
#define PyTuple_Check(op) ((op)->ob_type == &PyTuple_Type)
#define PyDict_Check(op) ((op)->ob_type == &PyDict_Type)
#define PyInt_AS_LONG(op) (((PyIntObject *)(op))->ob_ival)
#define PyTuple_GET_SIZE(op) (((PyTupleObject *)(op))->ob_size)
#define PyTuple_GET_ITEM(op,i) (((PyTupleObject *)(op))->ob_item[i])
#define PyTuple_SET_ITEM(op,i,v) (((PyTupleObject *)(op))->ob_item[i]=(v))
#define PyType_HasFeature(t,f) (((t)->tp_flags & (f)) != 0)
#define Py_TPFLAGS_HAVE_GETCHARBUFFER (1L<<0)
#define Py_InitModule(name,methods) Py_InitModule4(name,methods,NULL,NULL,1010)
#define putc(c,fp) (fwide(fp,-1)>=0 ? EOF : ((fp)->buffer_len-- ? (*(fp)->buffer_ptr++=(unsigned char)(c)) : __putc(c,fp)))
typedef struct { PyObject_HEAD long ob_ival; } PyIntObject;
typedef struct { PyObject_HEAD double ob_fval; } PyFloatObject;
typedef struct { PyObject_VAR_HEAD PyObject *ob_item[1]; } PyTupleObject;
typedef struct _longobject PyLongObject;
typedef struct { double real, imag; } Py_complex;
typedef struct { int cf_nested_scopes; } PyCompilerFlags;
extern int __putc(int, FILE *), feof(FILE *), ungetc(int, FILE *);
extern double atof(const char *);
extern size_t strlen(const char *);
extern PyTypeObject PyFloat_Type, PyComplex_Type, PyUnicode_Type, PyTuple_Type, PyDict_Type;
extern PyObject _Py_EllipsisObject;
extern PyObject *PyErr_NoMemory(void);
extern void PyErr_SetObject(PyObject *, PyObject *);
extern PyObject *PySys_GetObject(char *);
extern int PyFile_WriteString(char *, PyObject *);
extern FILE *PyFile_AsFile(PyObject *);
extern PyObject *PyFloat_FromDouble(double), *PyComplex_FromCComplex(Py_complex);
extern double PyComplex_RealAsDouble(PyObject *), PyComplex_ImagAsDouble(PyObject *);
extern int PyString_Size(PyObject *);
extern PyObject *PyTuple_New(int), *PyTuple_GetItem(PyObject *, int);
extern PyObject *PyDict_New(void);
extern int PyDict_Next(PyObject *, int *, PyObject **, PyObject **);
extern int PyDict_SetItem(PyObject *, PyObject *, PyObject *);
extern PyObject *PyUnicode_DecodeUTF8(const char *, int, const char *);
extern PyObject *PyUnicode_AsUTF8String(PyObject *);
extern PyObject *Py_InitModule4(char *, PyMethodDef *, char *, PyObject *, int);
#ifndef Py_LONGINTREPR_H
#define Py_LONGINTREPR_H
#ifdef __cplusplus
extern "C" {
#endif


/* This is published for the benefit of "friend" marshal.c only. */

/* Parameters of the long integer representation.
   These shouldn't have to be changed as C should guarantee that a short
   contains at least 16 bits, but it's made changeable anyway.
   Note: 'digit' should be able to hold 2*MASK+1, and 'twodigits'
   should be able to hold the intermediate results in 'mul'
   (at most MASK << SHIFT).
   Also, x_sub assumes that 'digit' is an unsigned type, and overflow
   is handled by taking the result mod 2**N for some N > SHIFT.
   And, at some places it is assumed that MASK fits in an int, as well. */

typedef unsigned short digit;
typedef unsigned int wdigit; /* digit widened to parameter size */
#define BASE_TWODIGITS_TYPE long
typedef unsigned BASE_TWODIGITS_TYPE twodigits;
typedef BASE_TWODIGITS_TYPE stwodigits; /* signed variant of twodigits */

#define SHIFT	15
#define BASE	((digit)1 << SHIFT)
#define MASK	((int)(BASE - 1))

/* Long integer representation.
   The absolute value of a number is equal to
   	SUM(for i=0 through abs(ob_size)-1) ob_digit[i] * 2**(SHIFT*i)
   Negative numbers are represented with ob_size < 0;
   zero is represented by ob_size == 0.
   In a normalized number, ob_digit[abs(ob_size)-1] (the most significant
   digit) is never zero.  Also, in all cases, for all valid i,
   	0 <= ob_digit[i] <= MASK.
   The allocation function takes care of allocating extra memory
   so that ob_digit[0] ... ob_digit[abs(ob_size)-1] are actually available. */

struct _longobject {
	PyObject_HEAD
	int ob_size;
	digit ob_digit[1];
};

DL_IMPORT(PyLongObject *) _PyLong_New(int);

#ifdef __cplusplus
}
#endif
#endif /* !Py_LONGINTREPR_H */

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

#line 8 "marshal.c"




/* High water mark to determine when the marshalled object is dangerously deep
 * and risks coring the interpreter.  When the object stack gets this deep,
 * raise an exception instead of continuing.
 */
#define MAX_MARSHAL_STACK_DEPTH 5000

#define TYPE_NULL	'0'
#define TYPE_NONE	'N'
#define TYPE_ELLIPSIS   '.'
#define TYPE_INT	'i'
#define TYPE_INT64	'I'
#define TYPE_FLOAT	'f'
#define TYPE_COMPLEX	'x'
#define TYPE_LONG	'l'
#define TYPE_STRING	's'
#define TYPE_TUPLE	'('
#define TYPE_LIST	'['
#define TYPE_DICT	'{'
#define TYPE_CODE	'c'
#define TYPE_UNICODE	'u'
#define TYPE_UNKNOWN	'?'

typedef struct {
	FILE *fp;
	int error;
	int depth;
	/* If fp == NULL, the following are valid: */
	PyObject *str;
	char *ptr;
	char *end;
} WFILE;

#define w_byte(c, p) if (((p)->fp)) putc((c), (p)->fp); \
		      else if ((p)->ptr != (p)->end) *(p)->ptr++ = (c); \
			   else w_more(c, p)

static inline void
w_more(int c, WFILE *p)
{
	int size, newsize;
	if (p->str == NULL)
		return; /* An error already occurred */
	size = PyString_Size(p->str);
	newsize = size + 1024;
	if (_PyString_Resize(&p->str, newsize) != 0) {
		p->ptr = p->end = NULL;
	}
	else {
		p->ptr = PyString_AS_STRING((PyStringObject *)p->str) + size;
		p->end =
			PyString_AS_STRING((PyStringObject *)p->str) + newsize;
		*p->ptr++ = Py_SAFE_DOWNCAST(c, int, char);
	}
}

static inline void
w_string(char *s, int n, WFILE *p)
{
	if (p->fp != NULL) {
		fwrite(s, 1, n, p->fp);
	}
	else {
		while (--n >= 0) {
			w_byte(*s, p);
			s++;
		}
	}
}

static void
w_short(int x, WFILE *p)
{
	w_byte( x      & 0xff, p);
	w_byte((x>> 8) & 0xff, p);
}

static void
w_long(long x, WFILE *p)
{
	w_byte((int)( x      & 0xff), p);
	w_byte((int)((x>> 8) & 0xff), p);
	w_byte((int)((x>>16) & 0xff), p);
	w_byte((int)((x>>24) & 0xff), p);
}

#if SIZEOF_LONG > 4
static void
w_long64(long x, WFILE *p)
{
	w_long(x, p);
	w_long(x>>32, p);
}
#endif

static void
w_object(PyObject *v, WFILE *p)
{
	int i, n;
	PyBufferProcs *pb;

	p->depth++;

	if (p->depth > MAX_MARSHAL_STACK_DEPTH) {
		p->error = 2;
	}
	else if (v == NULL) {
		w_byte(TYPE_NULL, p);
	}
	else if (v == Py_None) {
		w_byte(TYPE_NONE, p);
	}
	else if (v == Py_Ellipsis) {
	        w_byte(TYPE_ELLIPSIS, p);
	}
	else if (PyInt_Check(v)) {
		long x = PyInt_AS_LONG((PyIntObject *)v);
#if SIZEOF_LONG > 4
		long y = Py_ARITHMETIC_RIGHT_SHIFT(long, x, 31);
		if (y && y != -1) {
			w_byte(TYPE_INT64, p);
			w_long64(x, p);
		}
		else
#endif
			{
			w_byte(TYPE_INT, p);
			w_long(x, p);
		}
	}
	else if (PyLong_Check(v)) {
		PyLongObject *ob = (PyLongObject *)v;
		w_byte(TYPE_LONG, p);
		n = ob->ob_size;
		w_long((long)n, p);
		if (n < 0)
			n = -n;
		for (i = 0; i < n; i++)
			w_short(ob->ob_digit[i], p);
	}
	else if (PyFloat_Check(v)) {
		extern void PyFloat_AsString(char *, PyFloatObject *);
		char buf[256]; /* Plenty to format any double */
		PyFloat_AsString(buf, (PyFloatObject *)v);
		n = strlen(buf);
		w_byte(TYPE_FLOAT, p);
		w_byte(n, p);
		w_string(buf, n, p);
	}
#ifndef WITHOUT_COMPLEX
	else if (PyComplex_Check(v)) {
		extern void PyFloat_AsString(char *, PyFloatObject *);
		char buf[256]; /* Plenty to format any double */
		PyFloatObject *temp;
		w_byte(TYPE_COMPLEX, p);
		temp = (PyFloatObject*)PyFloat_FromDouble(
			PyComplex_RealAsDouble(v));
		PyFloat_AsString(buf, temp);
		Py_DECREF(temp);
		n = strlen(buf);
		w_byte(n, p);
		w_string(buf, n, p);
		temp = (PyFloatObject*)PyFloat_FromDouble(
			PyComplex_ImagAsDouble(v));
		PyFloat_AsString(buf, temp);
		Py_DECREF(temp);
		n = strlen(buf);
		w_byte(n, p);
		w_string(buf, n, p);
	}
#endif
	else if (PyString_Check(v)) {
		w_byte(TYPE_STRING, p);
		n = PyString_GET_SIZE(v);
		w_long((long)n, p);
		w_string(PyString_AS_STRING(v), n, p);
	}
	else if (PyUnicode_Check(v)) {
	        PyObject *utf8;
		utf8 = PyUnicode_AsUTF8String(v);
		if (utf8 == NULL) {
			p->depth--;
			p->error = 1;
			return;
		}
		w_byte(TYPE_UNICODE, p);
		n = PyString_GET_SIZE(utf8);
		w_long((long)n, p);
		w_string(PyString_AS_STRING(utf8), n, p);
		Py_DECREF(utf8);
	}
	else if (PyTuple_Check(v)) {
		w_byte(TYPE_TUPLE, p);
		n = PyTuple_Size(v);
		w_long((long)n, p);
		for (i = 0; i < n; i++) {
			w_object(PyTuple_GET_ITEM(v, i), p);
		}
	}
	else if (PyList_Check(v)) {
		w_byte(TYPE_LIST, p);
		n = PyList_GET_SIZE(v);
		w_long((long)n, p);
		for (i = 0; i < n; i++) {
			w_object(PyList_GET_ITEM(v, i), p);
		}
	}
	else if (PyDict_Check(v)) {
		int pos;
		PyObject *key, *value;
		w_byte(TYPE_DICT, p);
		/* This one is NULL object terminated! */
		pos = 0;
		while (PyDict_Next(v, &pos, &key, &value)) {
			w_object(key, p);
			w_object(value, p);
		}
		w_object((PyObject *)NULL, p);
	}
	else if (PyCode_Check(v)) {
		PyCodeObject *co = (PyCodeObject *)v;
		w_byte(TYPE_CODE, p);
		w_short(co->co_argcount, p);
		w_short(co->co_nlocals, p);
		w_short(co->co_stacksize, p);
		w_short(co->co_flags, p);
		w_object(co->co_code, p);
		w_object(co->co_consts, p);
		w_object(co->co_names, p);
		w_object(co->co_varnames, p);
		w_object(co->co_freevars, p);
		w_object(co->co_cellvars, p);
		w_object(co->co_filename, p);
		w_object(co->co_name, p);
		w_short(co->co_firstlineno, p);
		w_object(co->co_lnotab, p);
	}
	else if ((pb = v->ob_type->tp_as_buffer) != NULL &&
		 pb->bf_getsegcount != NULL &&
		 pb->bf_getreadbuffer != NULL &&
		 (*pb->bf_getsegcount)(v, NULL) == 1)
	{
		/* Write unknown buffer-style objects as a string */
		char *s;
		w_byte(TYPE_STRING, p);
		n = (*pb->bf_getreadbuffer)(v, 0, (void **)&s);
		w_long((long)n, p);
		w_string(s, n, p);
	}
	else {
		w_byte(TYPE_UNKNOWN, p);
		p->error = 1;
	}

	p->depth--;
}

void
PyMarshal_WriteLongToFile(long x, FILE *fp)
{
	WFILE wf;
	wf.fp = fp;
	wf.error = 0;
	wf.depth = 0;
	w_long(x, &wf);
}

void
PyMarshal_WriteObjectToFile(PyObject *x, FILE *fp)
{
	WFILE wf;
	wf.fp = fp;
	wf.error = 0;
	wf.depth = 0;
	w_object(x, &wf);
}

typedef WFILE RFILE; /* Same struct with different invariants */

#define rs_byte(p) (((p)->ptr != (p)->end) ? (unsigned char)*(p)->ptr++ : EOF)

#define r_byte(p) ((p)->fp ? getc((p)->fp) : rs_byte(p))

static inline int
r_string(char *s, int n, RFILE *p)
{
	if (p->fp != NULL)
		return fread(s, 1, n, p->fp);
	if (p->end - p->ptr < n)
		n = p->end - p->ptr;
	memcpy(s, p->ptr, n);
	p->ptr += n;
	return n;
}

static inline int
r_short(RFILE *p)
{
	register short x;
	x = r_byte(p);
	x |= r_byte(p) << 8;
	/* Sign-extension, in case short greater than 16 bits */
	x |= -(x & 0x8000);
	return x;
}

static inline long
r_long(RFILE *p)
{
	register long x;
	register FILE *fp = p->fp;
	if (fp) {
		x = getc(fp);
		x |= (long)getc(fp) << 8;
		x |= (long)getc(fp) << 16;
		x |= (long)getc(fp) << 24;
	}
	else {
		x = rs_byte(p);
		x |= (long)rs_byte(p) << 8;
		x |= (long)rs_byte(p) << 16;
		x |= (long)rs_byte(p) << 24;
	}
#if SIZEOF_LONG > 4
	/* Sign extension for 64-bit machines */
	x |= -(x & 0x80000000L);
#endif
	return x;
}

static long
r_long64(RFILE *p)
{
	register long x;
	x = r_long(p);
#if SIZEOF_LONG > 4
	x = (x & 0xFFFFFFFFL) | (r_long(p) << 32);
#else
	if (r_long(p) != 0) {
		PyObject *f = PySys_GetObject("stderr");
		if (f != NULL)
			(void) PyFile_WriteString(
			    "Warning: un-marshal 64-bit int in 32-bit mode\n",
			    f);
	}
#endif
	return x;
}

static PyObject *
r_object(RFILE *p)
{
	PyObject *v, *v2;
	long i, n;
	int type = r_byte(p);

	switch (type) {

	case EOF:
		PyErr_SetString(PyExc_EOFError,
				"EOF read where object expected");
		return NULL;

	case TYPE_NULL:
		return NULL;

	case TYPE_NONE:
		Py_INCREF(Py_None);
		return Py_None;

	case TYPE_ELLIPSIS:
		Py_INCREF(Py_Ellipsis);
		return Py_Ellipsis;

	case TYPE_INT:
		return PyInt_FromLong(r_long(p));

	case TYPE_INT64:
		return PyInt_FromLong(r_long64(p));

	case TYPE_LONG:
		{
			int size;
			PyLongObject *ob;
			n = r_long(p);
			size = n<0 ? -n : n;
			ob = _PyLong_New(size);
			if (ob == NULL)
				return NULL;
			ob->ob_size = n;
			for (i = 0; i < size; i++)
				ob->ob_digit[i] = r_short(p);
			return (PyObject *)ob;
		}

	case TYPE_FLOAT:
		{
			char buf[256];
			double dx;
			n = r_byte(p);
			if (r_string(buf, (int)n, p) != n) {
				PyErr_SetString(PyExc_EOFError,
					"EOF read where object expected");
				return NULL;
			}
			buf[n] = '\0';
			PyFPE_START_PROTECT("atof", return 0)
			dx = atof(buf);
			PyFPE_END_PROTECT(dx)
			return PyFloat_FromDouble(dx);
		}

#ifndef WITHOUT_COMPLEX
	case TYPE_COMPLEX:
		{
			char buf[256];
			Py_complex c;
			n = r_byte(p);
			if (r_string(buf, (int)n, p) != n) {
				PyErr_SetString(PyExc_EOFError,
					"EOF read where object expected");
				return NULL;
			}
			buf[n] = '\0';
			PyFPE_START_PROTECT("atof", return 0)
			c.real = atof(buf);
			PyFPE_END_PROTECT(c)
			n = r_byte(p);
			if (r_string(buf, (int)n, p) != n) {
				PyErr_SetString(PyExc_EOFError,
					"EOF read where object expected");
				return NULL;
			}
			buf[n] = '\0';
			PyFPE_START_PROTECT("atof", return 0)
			c.imag = atof(buf);
			PyFPE_END_PROTECT(c)
			return PyComplex_FromCComplex(c);
		}
#endif

	case TYPE_STRING:
		n = r_long(p);
		if (n < 0) {
			PyErr_SetString(PyExc_ValueError, "bad marshal data");
			return NULL;
		}
		v = PyString_FromStringAndSize((char *)NULL, n);
		if (v != NULL) {
			if (r_string(PyString_AS_STRING(v), (int)n, p) != n) {
				Py_DECREF(v);
				v = NULL;
				PyErr_SetString(PyExc_EOFError,
					"EOF read where object expected");
			}
		}
		return v;

	case TYPE_UNICODE:
	    {
		char *buffer;

		n = r_long(p);
		if (n < 0) {
			PyErr_SetString(PyExc_ValueError, "bad marshal data");
			return NULL;
		}
		buffer = PyMem_NEW(char, n);
		if (buffer == NULL)
			return PyErr_NoMemory();
		if (r_string(buffer, (int)n, p) != n) {
			PyMem_DEL(buffer);
			PyErr_SetString(PyExc_EOFError,
				"EOF read where object expected");
			return NULL;
		}
		v = PyUnicode_DecodeUTF8(buffer, n, NULL);
		PyMem_DEL(buffer);
		return v;
	    }

	case TYPE_TUPLE:
		n = r_long(p);
		if (n < 0) {
			PyErr_SetString(PyExc_ValueError, "bad marshal data");
			return NULL;
		}
		v = PyTuple_New((int)n);
		if (v == NULL)
			return v;
		for (i = 0; i < n; i++) {
			v2 = r_object(p);
			if ( v2 == NULL ) {
				Py_DECREF(v);
				v = NULL;
				break;
			}
			PyTuple_SET_ITEM(v, (int)i, v2);
		}
		return v;

	case TYPE_LIST:
		n = r_long(p);
		if (n < 0) {
			PyErr_SetString(PyExc_ValueError, "bad marshal data");
			return NULL;
		}
		v = PyList_New((int)n);
		if (v == NULL)
			return v;
		for (i = 0; i < n; i++) {
			v2 = r_object(p);
			if ( v2 == NULL ) {
				Py_DECREF(v);
				v = NULL;
				break;
			}
			PyList_SetItem(v, (int)i, v2);
		}
		return v;

	case TYPE_DICT:
		v = PyDict_New();
		if (v == NULL)
			return NULL;
		for (;;) {
			PyObject *key, *val;
			key = r_object(p);
			if (key == NULL)
				break; /* XXX Assume TYPE_NULL, not an error */
			val = r_object(p);
			if (val != NULL)
				PyDict_SetItem(v, key, val);
			Py_DECREF(key);
			Py_XDECREF(val);
		}
		return v;

	case TYPE_CODE:
		{
			int argcount = r_short(p);
			int nlocals = r_short(p);
			int stacksize = r_short(p);
			int flags = r_short(p);
			PyObject *code = NULL;
			PyObject *consts = NULL;
			PyObject *names = NULL;
			PyObject *varnames = NULL;
			PyObject *freevars = NULL;
			PyObject *cellvars = NULL;
			PyObject *filename = NULL;
			PyObject *name = NULL;
			int firstlineno = 0;
			PyObject *lnotab = NULL;

			code = r_object(p);
			if (code) consts = r_object(p);
			if (consts) names = r_object(p);
			if (names) varnames = r_object(p);
			if (varnames) freevars = r_object(p);
			if (freevars) cellvars = r_object(p);
			if (cellvars) filename = r_object(p);
			if (filename) name = r_object(p);
			if (name) {
				firstlineno = r_short(p);
				lnotab = r_object(p);
			}

			if (!PyErr_Occurred()) {
				v = (PyObject *) PyCode_New(
					argcount, nlocals, stacksize, flags,
					code, consts, names, varnames,
					freevars, cellvars, filename, name,
					firstlineno, lnotab);
			}
			else
				v = NULL;
			Py_XDECREF(code);
			Py_XDECREF(consts);
			Py_XDECREF(names);
			Py_XDECREF(varnames);
			Py_XDECREF(freevars);
			Py_XDECREF(cellvars);
			Py_XDECREF(filename);
			Py_XDECREF(name);
			Py_XDECREF(lnotab);

		}
		return v;

	default:
		/* Bogus data got written, which isn't ideal.
		   This will let you keep working and recover. */
		PyErr_SetString(PyExc_ValueError, "bad marshal data");
		return NULL;

	}
}

long
PyMarshal_ReadLongFromFile(FILE *fp)
{
	RFILE rf;
	rf.fp = fp;
	return r_long(&rf);
}

#ifdef HAVE_FSTAT
/* Return size of file in bytes; < 0 if unknown. */
static off_t
getfilesize(FILE *fp)
{
	struct stat st;
	if (fstat(fileno(fp), &st) != 0)
		return -1;
	else
		return st.st_size;
}
#endif

/* If we can get the size of the file up-front, and it's reasonably small,
 * read it in one gulp and delegate to ...FromString() instead.  Much quicker
 * than reading a byte at a time from file; speeds .pyc imports.
 * CAUTION:  since this may read the entire remainder of the file, don't
 * call it unless you know you're done with the file.
 */
PyObject *
PyMarshal_ReadLastObjectFromFile(FILE *fp)
{
/* 75% of 2.1's .pyc files can exploit SMALL_FILE_LIMIT.
 * REASONABLE_FILE_LIMIT is by defn something big enough for Tkinter.pyc.
 */
#define SMALL_FILE_LIMIT (1L << 14)
#define REASONABLE_FILE_LIMIT (1L << 18)
#ifdef HAVE_FSTAT
	off_t filesize;
#endif
	if (PyErr_Occurred()) {
		fprintf(stderr, "XXX rd_object called with exception set\n");
		return NULL;
	}
#ifdef HAVE_FSTAT
	filesize = getfilesize(fp);
	if (filesize > 0) {
		char buf[SMALL_FILE_LIMIT];
		char* pBuf = NULL;
		if (filesize <= SMALL_FILE_LIMIT)
			pBuf = buf;
		else if (filesize <= REASONABLE_FILE_LIMIT)
			pBuf = (char *)PyMem_MALLOC(filesize);
		if (pBuf != NULL) {
			PyObject* v;
			size_t n = fread(pBuf, 1, filesize, fp);
			v = PyMarshal_ReadObjectFromString(pBuf, n);
			if (pBuf != buf)
				PyMem_FREE(pBuf);
			return v;
		}

	}
#endif
	/* We don't have fstat, or we do but the file is larger than
	 * REASONABLE_FILE_LIMIT or malloc failed -- read a byte at a time.
	 */
	return PyMarshal_ReadObjectFromFile(fp);

#undef SMALL_FILE_LIMIT
#undef REASONABLE_FILE_LIMIT
}

static inline PyObject *
PyMarshal_ReadObjectFromFile(FILE *fp)
{
	RFILE rf;
	if (PyErr_Occurred()) {
		fprintf(stderr, "XXX rd_object called with exception set\n");
		return NULL;
	}
	rf.fp = fp;
	return r_object(&rf);
}

PyObject *
PyMarshal_ReadObjectFromString(char *str, int len)
{
	RFILE rf;
	if (PyErr_Occurred()) {
		fprintf(stderr, "XXX rds_object called with exception set\n");
		return NULL;
	}
	rf.fp = NULL;
	rf.str = NULL;
	rf.ptr = str;
	rf.end = str + len;
	return r_object(&rf);
}

PyObject *
PyMarshal_WriteObjectToString(PyObject *x) /* wrs_object() */
{
	WFILE wf;
	wf.fp = NULL;
	wf.str = PyString_FromStringAndSize((char *)NULL, 50);
	if (wf.str == NULL)
		return NULL;
	wf.ptr = PyString_AS_STRING((PyStringObject *)wf.str);
	wf.end = wf.ptr + PyString_Size(wf.str);
	wf.error = 0;
	wf.depth = 0;
	w_object(x, &wf);
	if (wf.str != NULL)
		_PyString_Resize(&wf.str,
		    (int) (wf.ptr -
			   PyString_AS_STRING((PyStringObject *)wf.str)));
	if (wf.error) {
		Py_XDECREF(wf.str);
		PyErr_SetString(PyExc_ValueError,
				(wf.error==1)?"unmarshallable object"
				:"object too deeply nested to marshal");
		return NULL;
	}
	return wf.str;
}

/* And an interface for Python programs... */

static PyObject *
marshal_dump(PyObject *self, PyObject *args)
{
	WFILE wf;
	PyObject *x;
	PyObject *f;
	if (!PyArg_ParseTuple(args, "OO:dump", &x, &f))
		return NULL;
	if (!PyFile_Check(f)) {
		PyErr_SetString(PyExc_TypeError,
				"marshal.dump() 2nd arg must be file");
		return NULL;
	}
	wf.fp = PyFile_AsFile(f);
	wf.str = NULL;
	wf.ptr = wf.end = NULL;
	wf.error = 0;
	wf.depth = 0;
	w_object(x, &wf);
	if (wf.error) {
		PyErr_SetString(PyExc_ValueError,
				(wf.error==1)?"unmarshallable object"
				:"object too deeply nested to marshal");
		return NULL;
	}
	Py_INCREF(Py_None);
	return Py_None;
}

static PyObject *
marshal_load(PyObject *self, PyObject *args)
{
	RFILE rf;
	PyObject *f;
	PyObject *v;
	if (!PyArg_ParseTuple(args, "O:load", &f))
		return NULL;
	if (!PyFile_Check(f)) {
		PyErr_SetString(PyExc_TypeError,
				"marshal.load() arg must be file");
		return NULL;
	}
	rf.fp = PyFile_AsFile(f);
	rf.str = NULL;
	rf.ptr = rf.end = NULL;
	PyErr_Clear();
	v = r_object(&rf);
	if (PyErr_Occurred()) {
		Py_XDECREF(v);
		v = NULL;
	}
	return v;
}

static PyObject *
marshal_dumps(PyObject *self, PyObject *args)
{
	PyObject *x;
	if (!PyArg_ParseTuple(args, "O:dumps", &x))
		return NULL;
	return PyMarshal_WriteObjectToString(x);
}

static PyObject *
marshal_loads(PyObject *self, PyObject *args)
{
	RFILE rf;
	PyObject *v;
	char *s;
	int n;
	if (!PyArg_ParseTuple(args, "s#:loads", &s, &n))
		return NULL;
	rf.fp = NULL;
	rf.str = args;
	rf.ptr = s;
	rf.end = s + n;
	PyErr_Clear();
	v = r_object(&rf);
	if (PyErr_Occurred()) {
		Py_XDECREF(v);
		v = NULL;
	}
	return v;
}

static PyMethodDef marshal_methods[] = {
	{"dump",	marshal_dump,	1},
	{"load",	marshal_load,	1},
	{"dumps",	marshal_dumps,	1},
	{"loads",	marshal_loads,	1},
	{NULL,		NULL}		/* sentinel */
};

void
PyMarshal_Init(void)
{
	(void) Py_InitModule("marshal", marshal_methods);
}
