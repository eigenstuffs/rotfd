/* Codec registry in the Kalisto CPython runtime, GSQE78.
 * Derived from CPython 2.1 Python/codecs.c and its public headers.
 * Upstream license: reference/cpython-2.1/LICENSE.
 */
/* ------------------------------------------------------------------------

   Python Codec Registry and support functions

Written by Marc-Andre Lemburg (mal@lemburg.com).

Copyright (c) Corporation for National Research Initiatives.

   ------------------------------------------------------------------------ */

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


#define PyTuple_Check(op) ((op)->ob_type == &PyTuple_Type)
#define PyTuple_GET_SIZE(op) (((PyTupleObject *)(op))->ob_size)
#define PyTuple_GET_ITEM(op,i) (((PyTupleObject *)(op))->ob_item[i])
#define PyTuple_SET_ITEM(op,i,v) (((PyTupleObject *)(op))->ob_item[i]=(v))
typedef struct { PyObject_VAR_HEAD PyObject *ob_item[1]; } PyTupleObject;
extern PyTypeObject PyTuple_Type;
extern PyObject *PyExc_ImportError, *PyExc_LookupError;
extern const unsigned char __lower_map[];
static inline int tolower(int c) { return c == -1 ? -1 : __lower_map[(unsigned char)c]; }
extern size_t strlen(const char *);
extern PyObject *PyTuple_New(int), *PyDict_New(void);
extern int PyList_Size(PyObject *), PyCallable_Check(PyObject *), PyErr_BadArgument(void);
extern PyObject *PyList_GetItem(PyObject *, int), *PyDict_GetItem(PyObject *, PyObject *);
extern int PyDict_SetItem(PyObject *, PyObject *, PyObject *);
extern void Py_FatalError(const char *), PyString_InternInPlace(PyObject **);

#line 12 "codecs.c"


/* --- Globals ------------------------------------------------------------ */

static PyObject *_PyCodec_SearchPath;
static PyObject *_PyCodec_SearchCache;

/* Flag used for lazy import of the standard encodings package */
static int import_encodings_called = 0;

/* --- Codec Registry ----------------------------------------------------- */

/* Import the standard encodings package which will register the first
   codec search function. 

   This is done in a lazy way so that the Unicode implementation does
   not downgrade startup time of scripts not needing it.

   ImportErrors are silently ignored by this function. Only one try is
   made.

*/

static inline int import_encodings(void)
{
    PyObject *mod;
    
    import_encodings_called = 1;
    mod = PyImport_ImportModule("encodings");
    if (mod == NULL) {
	if (PyErr_ExceptionMatches(PyExc_ImportError)) {
	    /* Ignore ImportErrors... this is done so that
	       distributions can disable the encodings package. Note
	       that other errors are not masked, e.g. SystemErrors
	       raised to inform the user of an error in the Python
	       configuration are still reported back to the user. */
	    PyErr_Clear();
	    return 0;
	}
	return -1;
    }
    Py_DECREF(mod);
    return 0;
}

int PyCodec_Register(PyObject *search_function)
{
    if (!import_encodings_called) {
	if (import_encodings())
	    goto onError;
    }
    if (search_function == NULL) {
	PyErr_BadArgument();
	goto onError;
    }
    if (!PyCallable_Check(search_function)) {
	PyErr_SetString(PyExc_TypeError,
			"argument must be callable");
	goto onError;
    }
    return PyList_Append(_PyCodec_SearchPath, search_function);

 onError:
    return -1;
}

/* Convert a string to a normalized Python string: all characters are
   converted to lower case, spaces are replaced with underscores. */

static inline PyObject *normalizestring(const char *string)
{
    register size_t i;
    size_t len = strlen(string);
    char *p;
    PyObject *v;
    
	if (len > INT_MAX) {
		PyErr_SetString(PyExc_OverflowError, "string is too large");
		return NULL;
	}
	
    v = PyString_FromStringAndSize(NULL, (int)len);
    if (v == NULL)
	return NULL;
    p = PyString_AS_STRING(v);
    for (i = 0; i < len; i++) {
        register char ch = string[i];
        if (ch == ' ')
            ch = '-';
        else
            ch = tolower(ch);
	p[i] = ch;
    }
    return v;
}

/* Lookup the given encoding and return a tuple providing the codec
   facilities.

   The encoding string is looked up converted to all lower-case
   characters. This makes encodings looked up through this mechanism
   effectively case-insensitive.

   If no codec is found, a LookupError is set and NULL returned. 

   As side effect, this tries to load the encodings package, if not
   yet done. This is part of the lazy load strategy for the encodings
   package.

*/

PyObject *_PyCodec_Lookup(const char *encoding)
{
    PyObject *result, *args = NULL, *v;
    int i, len;

    if (encoding == NULL) {
	PyErr_BadArgument();
	goto onError;
    }
    if (_PyCodec_SearchCache == NULL || 
	_PyCodec_SearchPath == NULL) {
	PyErr_SetString(PyExc_SystemError,
			"codec module not properly initialized");
	goto onError;
    }
    if (!import_encodings_called) {
	if (import_encodings())
	    goto onError;
    }

    /* Convert the encoding to a normalized Python string: all
       characters are converted to lower case, spaces and hyphens are
       replaced with underscores. */
    v = normalizestring(encoding);
    if (v == NULL)
	goto onError;
    PyString_InternInPlace(&v);

    /* First, try to lookup the name in the registry dictionary */
    result = PyDict_GetItem(_PyCodec_SearchCache, v);
    if (result != NULL) {
	Py_INCREF(result);
	Py_DECREF(v);
	return result;
    }
    
    /* Next, scan the search functions in order of registration */
    args = PyTuple_New(1);
    if (args == NULL)
	goto onError;
    PyTuple_SET_ITEM(args,0,v);

    len = PyList_Size(_PyCodec_SearchPath);
    if (len < 0)
	goto onError;
    if (len == 0) {
	PyErr_SetString(PyExc_LookupError,
			"no codec search functions registered: "
			"can't find encoding");
	goto onError;
    }

    for (i = 0; i < len; i++) {
	PyObject *func;
	
	func = PyList_GetItem(_PyCodec_SearchPath, i);
	if (func == NULL)
	    goto onError;
	result = PyEval_CallObject(func, args);
	if (result == NULL)
	    goto onError;
	if (result == Py_None) {
	    Py_DECREF(result);
	    continue;
	}
	if (!PyTuple_Check(result) || PyTuple_GET_SIZE(result) != 4) {
	    PyErr_SetString(PyExc_TypeError,
			    "codec search functions must return 4-tuples");
	    Py_DECREF(result);
	    goto onError;
	}
	break;
    }
    if (i == len) {
	/* XXX Perhaps we should cache misses too ? */
	PyErr_SetString(PyExc_LookupError,
			"unknown encoding");
	goto onError;
    }

    /* Cache and return the result */
    PyDict_SetItem(_PyCodec_SearchCache, v, result);
    Py_DECREF(args);
    return result;

 onError:
    Py_XDECREF(args);
    return NULL;
}

static inline PyObject *args_tuple(PyObject *object,
		     const char *errors)
{
    PyObject *args;
    
    args = PyTuple_New(1 + (errors != NULL));
    if (args == NULL)
	return NULL;
    Py_INCREF(object);
    PyTuple_SET_ITEM(args,0,object);
    if (errors) {
	PyObject *v;
	
	v = PyString_FromString(errors);
	if (v == NULL) {
	    Py_DECREF(args);
	    return NULL;
	}
	PyTuple_SET_ITEM(args, 1, v);
    }
    return args;
}

/* Build a codec by calling factory(stream[,errors]) or just
   factory(errors) depending on whether the given parameters are
   non-NULL. */

static inline PyObject *build_stream_codec(PyObject *factory,
			     PyObject *stream,
			     const char *errors)
{
    PyObject *args, *codec;

    args = args_tuple(stream, errors);
    if (args == NULL)
	return NULL;
    
    codec = PyEval_CallObject(factory, args);
    Py_DECREF(args);
    return codec;
}

/* Convenience APIs to query the Codec registry. 
   
   All APIs return a codec object with incremented refcount.
   
 */

static inline PyObject *PyCodec_Encoder(const char *encoding)
{
    PyObject *codecs;
    PyObject *v;

    codecs = _PyCodec_Lookup(encoding);
    if (codecs == NULL)
	goto onError;
    v = PyTuple_GET_ITEM(codecs,0);
    Py_INCREF(v);
    return v;

 onError:
    return NULL;
}

static inline PyObject *PyCodec_Decoder(const char *encoding)
{
    PyObject *codecs;
    PyObject *v;

    codecs = _PyCodec_Lookup(encoding);
    if (codecs == NULL)
	goto onError;
    v = PyTuple_GET_ITEM(codecs,1);
    Py_INCREF(v);
    return v;

 onError:
    return NULL;
}

static inline PyObject *PyCodec_StreamReader(const char *encoding,
			       PyObject *stream,
			       const char *errors)
{
    PyObject *codecs;

    codecs = _PyCodec_Lookup(encoding);
    if (codecs == NULL)
	goto onError;
    return build_stream_codec(PyTuple_GET_ITEM(codecs,2),stream,errors);

 onError:
    return NULL;
}

static inline PyObject *PyCodec_StreamWriter(const char *encoding,
			       PyObject *stream,
			       const char *errors)
{
    PyObject *codecs;

    codecs = _PyCodec_Lookup(encoding);
    if (codecs == NULL)
	goto onError;
    return build_stream_codec(PyTuple_GET_ITEM(codecs,3),stream,errors);

 onError:
    return NULL;
}

/* Encode an object (e.g. an Unicode object) using the given encoding
   and return the resulting encoded object (usually a Python string).

   errors is passed to the encoder factory as argument if non-NULL. */

PyObject *PyCodec_Encode(PyObject *object,
			 const char *encoding,
			 const char *errors)
{
    PyObject *encoder = NULL;
    PyObject *args = NULL, *result;
    PyObject *v;

    encoder = PyCodec_Encoder(encoding);
    if (encoder == NULL)
	goto onError;

    args = args_tuple(object, errors);
    if (args == NULL)
	goto onError;
    
    result = PyEval_CallObject(encoder,args);
    if (result == NULL)
	goto onError;

    if (!PyTuple_Check(result) || 
	PyTuple_GET_SIZE(result) != 2) {
	PyErr_SetString(PyExc_TypeError,
			"encoder must return a tuple (object,integer)");
	goto onError;
    }
    v = PyTuple_GET_ITEM(result,0);
    Py_INCREF(v);
    /* We don't check or use the second (integer) entry. */

    Py_DECREF(args);
    Py_DECREF(encoder);
    Py_DECREF(result);
    return v;
	
 onError:
    Py_XDECREF(args);
    Py_XDECREF(encoder);
    return NULL;
}

/* Decode an object (usually a Python string) using the given encoding
   and return an equivalent object (e.g. an Unicode object).

   errors is passed to the decoder factory as argument if non-NULL. */

PyObject *PyCodec_Decode(PyObject *object,
			 const char *encoding,
			 const char *errors)
{
    PyObject *decoder = NULL;
    PyObject *args = NULL, *result = NULL;
    PyObject *v;

    decoder = PyCodec_Decoder(encoding);
    if (decoder == NULL)
	goto onError;

    args = args_tuple(object, errors);
    if (args == NULL)
	goto onError;
    
    result = PyEval_CallObject(decoder,args);
    if (result == NULL)
	goto onError;
    if (!PyTuple_Check(result) || 
	PyTuple_GET_SIZE(result) != 2) {
	PyErr_SetString(PyExc_TypeError,
			"decoder must return a tuple (object,integer)");
	goto onError;
    }
    v = PyTuple_GET_ITEM(result,0);
    Py_INCREF(v);
    /* We don't check or use the second (integer) entry. */

    Py_DECREF(args);
    Py_DECREF(decoder);
    Py_DECREF(result);
    return v;
	
 onError:
    Py_XDECREF(args);
    Py_XDECREF(decoder);
    Py_XDECREF(result);
    return NULL;
}

void _PyCodecRegistry_Init(void)
{
    if (_PyCodec_SearchPath == NULL)
	_PyCodec_SearchPath = PyList_New(0);
    if (_PyCodec_SearchCache == NULL)
	_PyCodec_SearchCache = PyDict_New();
    if (_PyCodec_SearchPath == NULL || 
	_PyCodec_SearchCache == NULL)
	Py_FatalError("can't initialize codec registry");
}

void _PyCodecRegistry_Fini(void)
{
    Py_XDECREF(_PyCodec_SearchPath);
    _PyCodec_SearchPath = NULL;
    Py_XDECREF(_PyCodec_SearchCache);
    _PyCodec_SearchCache = NULL;
}
