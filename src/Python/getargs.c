/* Argument parsing in the Kalisto CPython runtime, GSQE78.
 * Derived from CPython 2.1 Python/getargs.c and its public headers.
 * Copyright (c) 2001 Python Software Foundation; all rights reserved.
 * Upstream license: reference/cpython-2.1/LICENSE.
 */

/* New getargs implementation */
static char getargs_bad_format[] = "impossible<bad format char>";
static char getargs_expected_tuple[] = "new style getargs format but argument is not a tuple";
static char getargs_at_least[] = "at least";
static char getargs_argument_count[] = "%s%s takes %s %d argument%s (%d given)";
static char getargs_function[] = "function";
static char getargs_type_mismatch[] = "must be %.50s, not %.50s";
static char getargs_argument_index[] = "argument %d";
static char getargs_item_index[] = ", item %d";
static char getargs_argument[] = "argument";
static char getargs_empty[] = "";
static char getargs_plural[] = "s";
static char getargs_exactly[] = "exactly";
static char getargs_at_most[] = "at most";
static char getargs_parentheses[] = "()";
static char getargs_none[] = "None";
static char getargs_function_prefix[] = "%s() ";
static char getargs_message_suffix[] = " %s";


/* XXX There are several unchecked sprintf or strcat calls in this file.
   XXX The only way these can become a danger is if some C code in the
   XXX Python source (or in an extension) uses ridiculously long names
   XXX or ridiculously deep nesting in format strings. */

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
#define PyArg_NoArgs(v) PyArg_Parse(v, getargs_empty)
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
extern int PyArg_Parse(PyObject *, char *, ...);
extern int PyArg_ParseTuple(PyObject *, char *, ...);
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


#define HAVE_LONG_LONG
#define LONG_LONG long long
#define VA_LIST_IS_ARRAY
#define UCHAR_MAX 255U
#define SCHAR_MIN (-128)
#define SHRT_MIN (-32768)
#define SHRT_MAX 32767
#define USHRT_MAX 65535U
#define INT_MIN (-2147483647-1)
#define Py_CHARMASK(c) ((c)&0xff)
#define isalpha(c) (__ctype_map[(unsigned char)(c)] & 0xC0)
#define PyTuple_Check(op) ((op)->ob_type == &PyTuple_Type)
#define PyDict_Check(op) ((op)->ob_type == &PyDict_Type)
#define PyUnicode_Check(op) ((op)->ob_type == &PyUnicode_Type)
#define PyUnicode_AS_UNICODE(op) (((PyUnicodeObject *)(op))->str)
#define PyUnicode_GET_SIZE(op) (((PyUnicodeObject *)(op))->length)
#define PyUnicode_GET_DATA_SIZE(op) (((PyUnicodeObject *)(op))->length*sizeof(Py_UNICODE))
#define PyType_HasFeature(t,f) (((t)->tp_flags & (f)) != 0)
#define Py_TPFLAGS_HAVE_GETCHARBUFFER (1L<<0)
#define PyMem_NEW(type,n) ((type *)malloc(1+(n)*sizeof(type)))
#define PyMem_DEL(p) free(p)
typedef unsigned short Py_UNICODE;
typedef struct { PyObject_HEAD int length; Py_UNICODE *str; long hash; PyObject *defenc; } PyUnicodeObject;
typedef struct { double real, imag; } Py_complex;
typedef struct { char gpr; char fpr; char reserved[2]; char *input_arg_area; char *reg_save_area; } va_list[1];
extern void __builtin_va_info(void *);
extern void *__va_arg(va_list, unsigned char);
#define va_start(ap,fmt) ((void)fmt,__builtin_va_info(&ap))
#define va_arg(ap,t) (*((t *)__va_arg(ap,_var_arg_typeof(t))))
#define va_end(ap) ((void)0)
extern unsigned char __ctype_map[];
extern PyTypeObject PyTuple_Type, PyUnicode_Type, PyDict_Type;
extern double PyFloat_AsDouble(PyObject *);
extern Py_complex PyComplex_AsCComplex(PyObject *);
extern long long PyLong_AsLongLong(PyObject *);
extern size_t strlen(const char *);
extern char *strcpy(char *, const char *), *strcat(char *, const char *);
extern void Py_FatalError(const char *);
extern PyObject *PyErr_NoMemory(void);
extern int PyString_Size(PyObject *), PyTuple_Size(PyObject *), PySequence_Size(PyObject *);
extern PyObject *PyTuple_GetItem(PyObject *, int);
extern PyObject *PyDict_GetItemString(PyObject *, const char *);
extern int PyDict_Next(PyObject *, int *, PyObject **, PyObject **);
extern int PyDict_Size(PyObject *);
extern const char *PyUnicode_GetDefaultEncoding(void);
extern PyObject *PyMapping_GetItemString(PyObject *, char *);
extern PyObject *PyUnicode_FromObject(PyObject *);
extern PyObject *PyUnicode_AsEncodedString(PyObject *, const char *, const char *);

#line 10 "getargs.c"




int PyArg_Parse(PyObject *, char *, ...);
int PyArg_ParseTuple(PyObject *, char *, ...);
static inline int PyArg_VaParse(PyObject *, char *, va_list);

static inline int PyArg_ParseTupleAndKeywords(PyObject *, PyObject *,
				char *, char **, ...);

/* Forward */
static int vgetargs1(PyObject *, char *, va_list *, int);
static inline void seterror(int, char *, int *, char *, char *);
static inline char *convertitem(PyObject *, char **, va_list *, int *, char *);
static char *converttuple(PyObject *, char **, va_list *,
			  int *, char *, int);
static inline char *convertsimple(PyObject *, char **, va_list *, char *);
static char *convertsimple1(PyObject *, char **, va_list *);

static inline int vgetargskeywords(PyObject *, PyObject *,
			    char *, char **, va_list *);
static inline char *skipitem(char **, va_list *);

int PyArg_Parse(PyObject *args, char *format, ...)
{
	int retval;
	va_list va;
	
	va_start(va, format);
	retval = vgetargs1(args, format, &va, 1);
	va_end(va);
	return retval;
}


int PyArg_ParseTuple(PyObject *args, char *format, ...)
{
	int retval;
	va_list va;
	
	va_start(va, format);
	retval = vgetargs1(args, format, &va, 0);
	va_end(va);
	return retval;
}


static inline int
PyArg_VaParse(PyObject *args, char *format, va_list va)
{
	va_list lva;

#ifdef VA_LIST_IS_ARRAY
	memcpy(lva, va, sizeof(va_list));
#else
	lva = va;
#endif

	return vgetargs1(args, format, &lva, 0);
}


static int
vgetargs1(PyObject *args, char *format, va_list *p_va, int compat)
{
	char msgbuf[256];
	int levels[32];
	char *fname = NULL;
	char *message = NULL;
	int min = -1;
	int max = 0;
	int level = 0;
	char *formatsave = format;
	int i, len;
	char *msg;
	
	assert(compat || (args != (PyObject*)NULL));

	for (;;) {
		int c = *format++;
		if (c == '(' /* ')' */) {
			if (level == 0)
				max++;
			level++;
		}
		else if (/* '(' */ c == ')') {
			if (level == 0)
				Py_FatalError(/* '(' */
				      "excess ')' in getargs format");
			else
				level--;
		}
		else if (c == '\0')
			break;
		else if (c == ':') {
			fname = format;
			break;
		}
		else if (c == ';') {
			message = format;
			break;
		}
		else if (level != 0)
			; /* Pass */
		else if (c == 'e')
			; /* Pass */
		else if (isalpha(c))
			max++;
		else if (c == '|')
			min = max;
	}
	
	if (level != 0)
		Py_FatalError(/* '(' */ "missing ')' in getargs format");
	
	if (min < 0)
		min = max;
	
	format = formatsave;
	
	if (compat) {
		if (max == 0) {
			if (args == NULL)
				return 1;
			sprintf(msgbuf, "%s%s takes no arguments",
				fname==NULL ? getargs_function : fname,
				fname==NULL ? getargs_empty : getargs_parentheses);
			PyErr_SetString(PyExc_TypeError, msgbuf);
			return 0;
		}
		else if (min == 1 && max == 1) {
			if (args == NULL) {
				sprintf(msgbuf,
					"%s%s takes at least one argument",
					fname==NULL ? getargs_function : fname,
					fname==NULL ? getargs_empty : getargs_parentheses);
				PyErr_SetString(PyExc_TypeError, msgbuf);
				return 0;
			}
			msg = convertitem(args, &format, p_va, levels, msgbuf);
			if (msg == NULL)
				return 1;
			seterror(levels[0], msg, levels+1, fname, message);
			return 0;
		}
		else {
			PyErr_SetString(PyExc_SystemError,
			    "old style getargs format uses new features");
			return 0;
		}
	}
	
	if (!PyTuple_Check(args)) {
		PyErr_SetString(PyExc_SystemError,
		    getargs_expected_tuple);
		return 0;
	}
	
	len = PyTuple_Size(args);
	
	if (len < min || max < len) {
		if (message == NULL) {
			sprintf(msgbuf,
				getargs_argument_count,
				fname==NULL ? getargs_function : fname,
				fname==NULL ? getargs_empty : getargs_parentheses,
				min==max ? getargs_exactly
				         : len < min ? getargs_at_least : getargs_at_most,
				len < min ? min : max,
				(len < min ? min : max) == 1 ? getargs_empty : getargs_plural,
				len);
			message = msgbuf;
		}
		PyErr_SetString(PyExc_TypeError, message);
		return 0;
	}
	
	for (i = 0; i < len; i++) {
		if (*format == '|')
			format++;
		msg = convertitem(PyTuple_GetItem(args, i), &format, p_va,
				 levels, msgbuf);
		if (msg) {
			seterror(i+1, msg, levels, fname, message);
			return 0;
		}
	}

	if (*format != '\0' && !isalpha((int)(*format)) &&
	    *format != '(' &&
	    *format != '|' && *format != ':' && *format != ';') {
		PyErr_Format(PyExc_SystemError,
			     "bad format string: %.200s", formatsave);
		return 0;
	}
	
	return 1;
}



static inline void
seterror(int iarg, char *msg, int *levels, char *fname, char *message)
{
	char buf[256];
	int i;
	char *p = buf;

	if (PyErr_Occurred())
		return;
	else if (message == NULL) {
		if (fname != NULL) {
			sprintf(p, getargs_function_prefix, fname);
			p += strlen(p);
		}
		if (iarg != 0) {
			sprintf(p, getargs_argument_index, iarg);
			i = 0;
			p += strlen(p);
			while (levels[i] > 0) {
				sprintf(p, getargs_item_index, levels[i]-1);
				p += strlen(p);
				i++;
			}
		}
		else {
			sprintf(p, getargs_argument);
			p += strlen(p);
		}
		sprintf(p, getargs_message_suffix, msg);
		message = buf;
	}
	PyErr_SetString(PyExc_TypeError, message);
}


/* Convert a tuple argument.
   On entry, *p_format points to the character _after_ the opening '('.
   On successful exit, *p_format points to the closing ')'.
   If successful:
      *p_format and *p_va are updated,
      *levels and *msgbuf are untouched,
      and NULL is returned.
   If the argument is invalid:
      *p_format is unchanged,
      *p_va is undefined,
      *levels is a 0-terminated list of item numbers,
      *msgbuf contains an error message, whose format is:
         "must be <typename1>, not <typename2>", where:
            <typename1> is the name of the expected type, and
            <typename2> is the name of the actual type,
      and msgbuf is returned.
*/

static char *
converttuple(PyObject *arg, char **p_format, va_list *p_va, int *levels,
	     char *msgbuf, int toplevel)
{
	int level = 0;
	int n = 0;
	char *format = *p_format;
	int i;
	
	for (;;) {
		int c = *format++;
		if (c == '(') {
			if (level == 0)
				n++;
			level++;
		}
		else if (c == ')') {
			if (level == 0)
				break;
			level--;
		}
		else if (c == ':' || c == ';' || c == '\0')
			break;
		else if (level == 0 && isalpha(c))
			n++;
	}
	
	if (!PySequence_Check(arg) || PyString_Check(arg)) {
		levels[0] = 0;
		sprintf(msgbuf,
			toplevel ? "expected %d arguments, not %s" :
				   "must be %d-item sequence, not %s",
			n, arg == Py_None ? getargs_none : arg->ob_type->tp_name);
		return msgbuf;
	}
	
	if ((i = PySequence_Size(arg)) != n) {
		levels[0] = 0;
		sprintf(msgbuf,
			toplevel ? "expected %d arguments, not %d" :
				   "must be sequence of length %d, not %d",
			n, i);
		return msgbuf;
	}

	format = *p_format;
	for (i = 0; i < n; i++) {
		char *msg;
		PyObject *item;
		item = PySequence_GetItem(arg, i);
		msg = convertitem(item, &format, p_va, levels+1, msgbuf);
		/* PySequence_GetItem calls tp->sq_item, which INCREFs */
		Py_XDECREF(item);
		if (msg != NULL) {
			levels[0] = i+1;
			return msg;
		}
	}

	*p_format = format;
	return NULL;
}


/* Convert a single item. */

static inline char *
convertitem(PyObject *arg, char **p_format, va_list *p_va, int *levels,
	    char *msgbuf)
{
	char *msg;
	char *format = *p_format;
	
	if (*format == '(' /* ')' */) {
		format++;
		msg = converttuple(arg, &format, p_va, levels, msgbuf, 0);
		if (msg == NULL)
			format++;
	}
	else {
		msg = convertsimple(arg, &format, p_va, msgbuf);
		if (msg != NULL)
			levels[0] = 0;
	}
	if (msg == NULL)
		*p_format = format;
	return msg;
}


/* Convert a non-tuple argument.  Adds to convertsimple1 functionality
   by formatting messages as "must be <desired type>, not <actual type>". */

static inline char *
convertsimple(PyObject *arg, char **p_format, va_list *p_va, char *msgbuf)
{
	char *msg = convertsimple1(arg, p_format, p_va);
	if (msg != NULL) {
		sprintf(msgbuf, getargs_type_mismatch, msg,
			arg == Py_None ? getargs_none : arg->ob_type->tp_name);
		msg = msgbuf;
	}
	return msg;
}


/* Internal API needed by convertsimple1(): */
extern 
PyObject *_PyUnicode_AsDefaultEncodedString(PyObject *unicode,
				  const char *errors);

/* Convert a non-tuple argument.  Return NULL if conversion went OK,
   or a string representing the expected type if the conversion failed.
   When failing, an exception may or may not have been raised.
   Don't call if a tuple is expected. */

static char *
convertsimple1(PyObject *arg, char **p_format, va_list *p_va)
{
	char *format = *p_format;
	char c = *format++;
	
	switch (c) {
	
	case 'b': /* unsigned byte -- very short int */
		{
			char *p = va_arg(*p_va, char *);
			long ival = PyInt_AsLong(arg);
			if (ival == -1 && PyErr_Occurred())
				return "integer<b>";
			else if (ival < 0) {
				PyErr_SetString(PyExc_OverflowError,
			      "unsigned byte integer is less than minimum");
				return "integer<b>";
			}
			else if (ival > UCHAR_MAX) {
				PyErr_SetString(PyExc_OverflowError,
			      "unsigned byte integer is greater than maximum");
				return "integer<b>";
			}
			else
				*p = (unsigned char) ival;
			break;
		}
	
	case 'B': /* byte sized bitfield - both signed and unsigned values allowed */
		{
			char *p = va_arg(*p_va, char *);
			long ival = PyInt_AsLong(arg);
			if (ival == -1 && PyErr_Occurred())
				return "integer<b>";
			else if (ival < SCHAR_MIN) {
				PyErr_SetString(PyExc_OverflowError,
			      "byte-sized integer bitfield is less than minimum");
				return "integer<B>";
			}
			else if (ival > (int)UCHAR_MAX) {
				PyErr_SetString(PyExc_OverflowError,
			      "byte-sized integer bitfield is greater than maximum");
				return "integer<B>";
			}
			else
				*p = (unsigned char) ival;
			break;
		}
	
	case 'h': /* signed short int */
		{
			short *p = va_arg(*p_va, short *);
			long ival = PyInt_AsLong(arg);
			if (ival == -1 && PyErr_Occurred())
				return "integer<h>";
			else if (ival < SHRT_MIN) {
				PyErr_SetString(PyExc_OverflowError,
			      "signed short integer is less than minimum");
				return "integer<h>";
			}
			else if (ival > SHRT_MAX) {
				PyErr_SetString(PyExc_OverflowError,
			      "signed short integer is greater than maximum");
				return "integer<h>";
			}
			else
				*p = (short) ival;
			break;
		}
	
	case 'H': /* short int sized bitfield, both signed and unsigned allowed */
		{
			unsigned short *p = va_arg(*p_va, unsigned short *);
			long ival = PyInt_AsLong(arg);
			if (ival == -1 && PyErr_Occurred())
				return "integer<H>";
			else if (ival < SHRT_MIN) {
				PyErr_SetString(PyExc_OverflowError,
			      "short integer bitfield is less than minimum");
				return "integer<H>";
			}
			else if (ival > USHRT_MAX) {
				PyErr_SetString(PyExc_OverflowError,
			      "short integer bitfield is greater than maximum");
				return "integer<H>";
			}
			else
				*p = (unsigned short) ival;
			break;
		}
	
	case 'i': /* signed int */
		{
			int *p = va_arg(*p_va, int *);
			long ival = PyInt_AsLong(arg);
			if (ival == -1 && PyErr_Occurred())
				return "integer<i>";
			else if (ival > INT_MAX) {
				PyErr_SetString(PyExc_OverflowError,
				    "signed integer is greater than maximum");
				return "integer<i>";
			}
			else if (ival < INT_MIN) {
				PyErr_SetString(PyExc_OverflowError,
				    "signed integer is less than minimum");
				return "integer<i>";
			}
			else
				*p = ival;
			break;
		}
	case 'l': /* long int */
		{
			long *p = va_arg(*p_va, long *);
			long ival = PyInt_AsLong(arg);
			if (ival == -1 && PyErr_Occurred())
				return "integer<l>";
			else
				*p = ival;
			break;
		}
	
#ifdef HAVE_LONG_LONG
	case 'L': /* LONG_LONG */
		{
			LONG_LONG *p = va_arg( *p_va, LONG_LONG * );
			LONG_LONG ival = PyLong_AsLongLong( arg );
			if( ival == (LONG_LONG)-1 && PyErr_Occurred() ) {
				return "long<L>";
			} else {
				*p = ival;
			}
			break;
		}
#endif
	
	case 'f': /* float */
		{
			float *p = va_arg(*p_va, float *);
			double dval = PyFloat_AsDouble(arg);
			if (PyErr_Occurred())
				return "float<f>";
			else
				*p = (float) dval;
			break;
		}
	
	case 'd': /* double */
		{
			double *p = va_arg(*p_va, double *);
			double dval = PyFloat_AsDouble(arg);
			if (PyErr_Occurred())
				return "float<d>";
			else
				*p = dval;
			break;
		}
	
#ifndef WITHOUT_COMPLEX
	case 'D': /* complex double */
		{
			Py_complex *p = va_arg(*p_va, Py_complex *);
			Py_complex cval;
			cval = PyComplex_AsCComplex(arg);
			if (PyErr_Occurred())
				return "complex<D>";
			else
				*p = cval;
			break;
		}
#endif /* WITHOUT_COMPLEX */
	
	case 'c': /* char */
		{
			char *p = va_arg(*p_va, char *);
			if (PyString_Check(arg) && PyString_Size(arg) == 1)
				*p = PyString_AsString(arg)[0];
			else
				return "char";
			break;
		}
	
	case 's': /* string */
		{
			if (*format == '#') {
				void **p = (void **)va_arg(*p_va, char **);
				int *q = va_arg(*p_va, int *);

				if (PyString_Check(arg)) {
				    *p = PyString_AS_STRING(arg);
				    *q = PyString_GET_SIZE(arg);
				}
				else if (PyUnicode_Check(arg)) {
				    arg = _PyUnicode_AsDefaultEncodedString(
							            arg, NULL);
				    if (arg == NULL)
					return "(unicode conversion error)";
				    *p = PyString_AS_STRING(arg);
				    *q = PyString_GET_SIZE(arg);
				}
				else { /* any buffer-like object */
				    PyBufferProcs *pb = arg->ob_type->tp_as_buffer;
				    int count;
				    if ( pb == NULL ||
					 pb->bf_getreadbuffer == NULL ||
					 pb->bf_getsegcount == NULL )
					return "string or read-only buffer";
				    if ( (*pb->bf_getsegcount)(arg, NULL) != 1 )
					return "string or single-segment read-only buffer";
				    if ( (count =
					  (*pb->bf_getreadbuffer)(arg, 0, p)) < 0 )
					return "(unspecified)";
				    *q = count;
				}
				format++;
			} else {
				char **p = va_arg(*p_va, char **);
			
				if (PyString_Check(arg))
				    *p = PyString_AS_STRING(arg);
				else if (PyUnicode_Check(arg)) {
				    arg = _PyUnicode_AsDefaultEncodedString(
							            arg, NULL);
				    if (arg == NULL)
					return "(unicode conversion error)";
				    *p = PyString_AS_STRING(arg);
				}
				else
				  return "string";
				if ((int)strlen(*p) != PyString_Size(arg))
				  return "string without null bytes";
			}
			break;
		}

	case 'z': /* string, may be NULL (None) */
		{
			if (*format == '#') { /* any buffer-like object */
				void **p = (void **)va_arg(*p_va, char **);
				int *q = va_arg(*p_va, int *);

				if (arg == Py_None) {
				  *p = 0;
				  *q = 0;
				}
				else if (PyString_Check(arg)) {
				    *p = PyString_AS_STRING(arg);
				    *q = PyString_GET_SIZE(arg);
				}
				else if (PyUnicode_Check(arg)) {
				    arg = _PyUnicode_AsDefaultEncodedString(
							            arg, NULL);
				    if (arg == NULL)
					return "(unicode conversion error)";
				    *p = PyString_AS_STRING(arg);
				    *q = PyString_GET_SIZE(arg);
				}
				else { /* any buffer-like object */
				    PyBufferProcs *pb = arg->ob_type->tp_as_buffer;
				    int count;
				    if ( pb == NULL ||
					 pb->bf_getreadbuffer == NULL ||
					 pb->bf_getsegcount == NULL )
					return "string or read-only buffer";
				    if ( (*pb->bf_getsegcount)(arg, NULL) != 1 )
					return "string or single-segment read-only buffer";
				    if ( (count =
					  (*pb->bf_getreadbuffer)(arg, 0, p)) < 0 )
					return "(unspecified)";
				    *q = count;
				}
				format++;
			} else {
				char **p = va_arg(*p_va, char **);
			
				if (arg == Py_None)
				  *p = 0;
				else if (PyString_Check(arg))
				  *p = PyString_AsString(arg);
				else if (PyUnicode_Check(arg)) {
				  arg = _PyUnicode_AsDefaultEncodedString(
								  arg, NULL);
				  if (arg == NULL)
				      return "(unicode conversion error)";
				  *p = PyString_AS_STRING(arg);
				}
				else
				  return "string or None";
				if (*format == '#') {
				  int *q = va_arg(*p_va, int *);
				  if (arg == Py_None)
				    *q = 0;
				  else
				    *q = PyString_Size(arg);
				  format++;
				}
				else if (*p != NULL &&
					 (int)strlen(*p) != PyString_Size(arg))
				  return "string without null bytes or None";
			}
			break;
		}
	
	case 'e': /* encoded string */
		{
			char **buffer;
			const char *encoding;
			PyObject *u, *s;
			int size;

			/* Get 'e' parameter: the encoding name */
			encoding = (const char *)va_arg(*p_va, const char *);
			if (encoding == NULL)
			    	encoding = PyUnicode_GetDefaultEncoding();
			
			/* Get 's' parameter: the output buffer to use */
			if (*format != 's')
				return "(unknown parser marker combination)";
			buffer = (char **)va_arg(*p_va, char **);
			format++;
			if (buffer == NULL)
				return "(buffer is NULL)";
			
			/* Convert object to Unicode */
			u = PyUnicode_FromObject(arg);
			if (u == NULL)
				return "string or unicode or text buffer";
			
			/* Encode object; use default error handling */
			s = PyUnicode_AsEncodedString(u,
						      encoding,
						      NULL);
			Py_DECREF(u);
			if (s == NULL)
				return "(encoding failed)";
			if (!PyString_Check(s)) {
				Py_DECREF(s);
				return "(encoder failed to return a string)";
			}
			size = PyString_GET_SIZE(s);

			/* Write output; output is guaranteed to be
			   0-terminated */
			if (*format == '#') { 
				/* Using buffer length parameter '#':

				   - if *buffer is NULL, a new buffer
				   of the needed size is allocated and
				   the data copied into it; *buffer is
				   updated to point to the new buffer;
				   the caller is responsible for
				   PyMem_Free()ing it after usage

				   - if *buffer is not NULL, the data
				   is copied to *buffer; *buffer_len
				   has to be set to the size of the
				   buffer on input; buffer overflow is
				   signalled with an error; buffer has
				   to provide enough room for the
				   encoded string plus the trailing
				   0-byte

				   - in both cases, *buffer_len is
				   updated to the size of the buffer
				   /excluding/ the trailing 0-byte

				*/
				int *buffer_len = va_arg(*p_va, int *);

				format++;
				if (buffer_len == NULL)
					return "(buffer_len is NULL)";
				if (*buffer == NULL) {
					*buffer = PyMem_NEW(char, size + 1);
					if (*buffer == NULL) {
						Py_DECREF(s);
						return "(memory error)";
					}
				} else {
					if (size + 1 > *buffer_len) {
						Py_DECREF(s);
						return "(buffer overflow)";
					}
				}
				memcpy(*buffer,
				       PyString_AS_STRING(s),
				       size + 1);
				*buffer_len = size;
			} else {
				/* Using a 0-terminated buffer:

				   - the encoded string has to be
				   0-terminated for this variant to
				   work; if it is not, an error raised

				   - a new buffer of the needed size
				   is allocated and the data copied
				   into it; *buffer is updated to
				   point to the new buffer; the caller
				   is responsible for PyMem_Free()ing it
				   after usage

				 */
				if ((int)strlen(PyString_AS_STRING(s)) != size)
					return "(encoded string without NULL bytes)";
				*buffer = PyMem_NEW(char, size + 1);
				if (*buffer == NULL) {
					Py_DECREF(s);
					return "(memory error)";
				}
				memcpy(*buffer,
				       PyString_AS_STRING(s),
				       size + 1);
			}
			Py_DECREF(s);
			break;
		}

	case 'u': /* raw unicode buffer (Py_UNICODE *) */
		{
			if (*format == '#') { /* any buffer-like object */
				void **p = (void **)va_arg(*p_va, char **);
				PyBufferProcs *pb = arg->ob_type->tp_as_buffer;
				int *q = va_arg(*p_va, int *);
				int count;

				if ( pb == NULL ||
				     pb->bf_getreadbuffer == NULL ||
				     pb->bf_getsegcount == NULL )
				  return "unicode or read-only buffer";
				if ( (*pb->bf_getsegcount)(arg, NULL) != 1 )
				  return "unicode or single-segment read-only buffer";
				if ( (count =
				      (*pb->bf_getreadbuffer)(arg, 0, p)) < 0 )
				  return "(unspecified)";
				/* buffer interface returns bytes, we want
				   length in characters */
				*q = count/(sizeof(Py_UNICODE)); 
				format++;
			} else {
				Py_UNICODE **p = va_arg(*p_va, Py_UNICODE **);
			
				if (PyUnicode_Check(arg))
				    *p = PyUnicode_AS_UNICODE(arg);
				else
				  return "unicode";
			}
			break;
		}

	case 'S': /* string object */
		{
			PyObject **p = va_arg(*p_va, PyObject **);
			if (PyString_Check(arg))
				*p = arg;
			else
				return "string";
			break;
		}
	
	case 'U': /* Unicode object */
		{
			PyObject **p = va_arg(*p_va, PyObject **);
			if (PyUnicode_Check(arg))
				*p = arg;
			else
				return "unicode";
			break;
		}
	
	case 'O': /* object */
		{
			PyTypeObject *type;
			PyObject **p;
			if (*format == '!') {
				type = va_arg(*p_va, PyTypeObject*);
				p = va_arg(*p_va, PyObject **);
				format++;
				if (arg->ob_type == type)
					*p = arg;
				else
					return type->tp_name;

			}
			else if (*format == '?') {
				inquiry pred = va_arg(*p_va, inquiry);
				p = va_arg(*p_va, PyObject **);
				format++;
				if ((*pred)(arg)) 
					*p = arg;
				else
					return "(unspecified)";
				
			}
			else if (*format == '&') {
				typedef int (*converter)(PyObject *, void *);
				converter convert = va_arg(*p_va, converter);
				void *addr = va_arg(*p_va, void *);
				format++;
				if (! (*convert)(arg, addr))
					return "(unspecified)";
			}
			else {
				p = va_arg(*p_va, PyObject **);
				*p = arg;
			}
			break;
		}
		
		
	case 'w': /* memory buffer, read-write access */
		{
			void **p = va_arg(*p_va, void **);
			PyBufferProcs *pb = arg->ob_type->tp_as_buffer;
			int count;
			
			if ( pb == NULL || pb->bf_getwritebuffer == NULL ||
					pb->bf_getsegcount == NULL )
				return "read-write buffer";
			if ( (*pb->bf_getsegcount)(arg, NULL) != 1 )
				return "single-segment read-write buffer";
			if ( (count = pb->bf_getwritebuffer(arg, 0, p)) < 0 )
				return "(unspecified)";
			if (*format == '#') {
				int *q = va_arg(*p_va, int *);
				
				*q = count;
				format++;
			}
			break;
		}
		
	case 't': /* 8-bit character buffer, read-only access */
		{
			const char **p = va_arg(*p_va, const char **);
			PyBufferProcs *pb = arg->ob_type->tp_as_buffer;
			int count;

			if ( *format++ != '#' )
				return "invalid use of 't' format character";
			if ( !PyType_HasFeature(
				arg->ob_type,
				Py_TPFLAGS_HAVE_GETCHARBUFFER) ||
			     pb == NULL ||
			     pb->bf_getcharbuffer == NULL ||
			     pb->bf_getsegcount == NULL )
				return "string or read-only character buffer";
			if ( (*pb->bf_getsegcount)(arg, NULL) != 1 )
				return "string or single-segment read-only buffer";
			if ( (count = pb->bf_getcharbuffer(arg, 0, p)) < 0 )
				return "(unspecified)";

			*va_arg(*p_va, int *) = count;

			break;
		}
		
	
	default:
		return getargs_bad_format;
	
	}
	
	*p_format = format;
	return NULL;
}


/* Support for keyword arguments donated by
   Geoff Philbrick <philbric@delphi.hks.com> */

static inline int PyArg_ParseTupleAndKeywords(PyObject *args,
				PyObject *keywords,
				char *format, 
				char **kwlist, ...)
{
	int retval;
	va_list va;
	
	va_start(va, kwlist);
	retval = vgetargskeywords(args, keywords, format, kwlist, &va);	
	va_end(va);
	return retval;
}


static inline int
vgetargskeywords(PyObject *args, PyObject *keywords, char *format,
	         char **kwlist, va_list *p_va)
{
	char msgbuf[256];
	int levels[32];
	char *fname = NULL;
	char *message = NULL;
	int min = -1;
	int max = 0;
	char *formatsave = format;
	int i, len, tplen, kwlen;
	char *msg, *ks, **p;
	int nkwds, pos, match, converted;
	PyObject *key, *value;
	
	/* nested tuples cannot be parsed when using keyword arguments */
	
	for (;;) {
		int c = *format++;
		if (c == '(') {
			PyErr_SetString(PyExc_SystemError,
		      "tuple found in format when using keyword arguments");
			return 0;
		}
		else if (c == '\0')
			break;
		else if (c == ':') {
			fname = format;
			break;
		}
		else if (c == ';') {
			message = format;
			break;
		}
		else if (c == 'e')
			; /* Pass */
		else if (isalpha(c))
			max++;
		else if (c == '|')
			min = max;
	}	
	
	if (min < 0)
		min = max;
	
	format = formatsave;
	
	if (!PyTuple_Check(args)) {
		PyErr_SetString(PyExc_SystemError,
		    getargs_expected_tuple);
		return 0;
	}	
	
	tplen = PyTuple_Size(args);
	
	/* do a cursory check of the keywords just to see how many we got */
	   
	if (keywords) { 	
		if (!PyDict_Check(keywords)) {
			if (keywords == NULL)
				PyErr_SetString(PyExc_SystemError,
		     "NULL received when keyword dictionary expected");
			else
				PyErr_Format(PyExc_SystemError,
		     "%s received when keyword dictionary expected",
					     keywords->ob_type->tp_name);
			return 0;
		}	
		kwlen = PyDict_Size(keywords);
	}
	else {
		kwlen = 0;
	}
			
	/* make sure there are no duplicate values for an argument;
	   its not clear when to use the term "keyword argument vs. 
	   keyword parameter in messages */
	
	if (keywords) {
		for (i = 0; i < tplen; i++) {
			if (PyMapping_HasKeyString(keywords, kwlist[i])) {
				sprintf(msgbuf,
					"keyword parameter %s redefined",
					kwlist[i]);
				PyErr_SetString(PyExc_TypeError, msgbuf);
				return 0;
			}
		}
	}
	PyErr_Clear(); /* I'm not which Py functions set the error string */
		
	/* required arguments missing from args can be supplied by keyword 
	   arguments */
	
	len = tplen;
	if (keywords && tplen < min) {
		for (i = tplen; i < min; i++) {
		  if (PyMapping_HasKeyString(keywords, kwlist[i])) {
				len++;
		  }
		}
	}
	PyErr_Clear();	
	
	/* make sure we got an acceptable number of arguments; the message
	   is a little confusing with keywords since keyword arguments
	   which are supplied, but don't match the required arguments
	   are not included in the "%d given" part of the message */

	if (len < min || max < len) {
		if (message == NULL) {
			sprintf(msgbuf,
				getargs_argument_count,
				fname==NULL ? getargs_function : fname,
				fname==NULL ? getargs_empty : getargs_parentheses,
				min==max ? getargs_exactly
				         : len < min ? getargs_at_least : getargs_at_most,
				len < min ? min : max,
				(len < min ? min : max) == 1 ? getargs_empty : getargs_plural,
				len);
			message = msgbuf;
		}
		PyErr_SetString(PyExc_TypeError, message);
		return 0;
	}
	
	for (i = 0; i < tplen; i++) {
		if (*format == '|')
			format++;
		msg = convertitem(PyTuple_GetItem(args, i), &format, p_va,
				 levels, msgbuf);
		if (msg) {
			seterror(i+1, msg, levels, fname, message);
			return 0;
		}
	}

	/* handle no keyword parameters in call  */	
	   	   
	if (!keywords) return 1; 
		
	/* make sure the number of keywords in the keyword list matches the 
	   number of items in the format string */
	  
	nkwds = 0;
	p =  kwlist;
	for (;;) {
		if (!*(p++)) break;
		nkwds++;
	}

	if (nkwds != max) {
		PyErr_SetString(PyExc_SystemError,
	  "number of items in format string and keyword list do not match");
		return 0;
	}	  	  
			
	/* convert the keyword arguments; this uses the format 
	   string where it was left after processing args */
	
	converted = 0;
	for (i = tplen; i < nkwds; i++) {
		PyObject *item;
		if (*format == '|')
			format++;
		item = PyMapping_GetItemString(keywords, kwlist[i]);
		if (item != NULL) {
			msg = convertitem(item, &format, p_va, levels, msgbuf);
			if (msg) {
				seterror(i+1, msg, levels, fname, message);
				return 0;
			}
			converted++;
			Py_DECREF(item);
		}
		else {
			PyErr_Clear();
			msg = skipitem(&format, p_va);
			if (msg) {
				seterror(i+1, msg, levels, fname, message);
				return 0;
			}
		}
	}
	
	/* make sure there are no extraneous keyword arguments */
	
	pos = 0;
	if (converted < kwlen) {
		while (PyDict_Next(keywords, &pos, &key, &value)) {
			match = 0;
			ks = PyString_AsString(key);
			for (i = 0; i < nkwds; i++) {
				if (!strcmp(ks, kwlist[i])) {
					match = 1;
					break;
				}
			}
			if (!match) {
				sprintf(msgbuf,
			"%s is an invalid keyword argument for this function",
					ks);
				PyErr_SetString(PyExc_TypeError, msgbuf);
				return 0;
			}
		}
	}
	
	return 1;
}


static inline char *
skipitem(char **p_format, va_list *p_va)
{
	char *format = *p_format;
	char c = *format++;
	
	switch (c) {
	
	case 'b': /* byte -- very short int */
	case 'B': /* byte as bitfield */
		{
			(void) va_arg(*p_va, char *);
			break;
		}
	
	case 'h': /* short int */
		{
			(void) va_arg(*p_va, short *);
			break;
		}
	
	case 'H': /* short int as bitfield */
		{
			(void) va_arg(*p_va, unsigned short *);
			break;
		}
	
	case 'i': /* int */
		{
			(void) va_arg(*p_va, int *);
			break;
		}
	
	case 'l': /* long int */
		{
			(void) va_arg(*p_va, long *);
			break;
		}
	
#ifdef HAVE_LONG_LONG
	case 'L': /* LONG_LONG int */
		{
			(void) va_arg(*p_va, LONG_LONG *);
			break;
		}
#endif
	
	case 'f': /* float */
		{
			(void) va_arg(*p_va, float *);
			break;
		}
	
	case 'd': /* double */
		{
			(void) va_arg(*p_va, double *);
			break;
		}
	
#ifndef WITHOUT_COMPLEX
	case 'D': /* complex double */
		{
			(void) va_arg(*p_va, Py_complex *);
			break;
		}
#endif /* WITHOUT_COMPLEX */
	
	case 'c': /* char */
		{
			(void) va_arg(*p_va, char *);
			break;
		}
	
	case 's': /* string */
		{
			(void) va_arg(*p_va, char **);
			if (*format == '#') {
				(void) va_arg(*p_va, int *);
				format++;
			}
			break;
		}
	
	case 'z': /* string */
		{
			(void) va_arg(*p_va, char **);
			if (*format == '#') {
				(void) va_arg(*p_va, int *);
				format++;
			}
			break;
		}
	
	case 'S': /* string object */
		{
			(void) va_arg(*p_va, PyObject **);
			break;
		}
	
	case 'O': /* object */
		{
			if (*format == '!') {
				format++;
				(void) va_arg(*p_va, PyTypeObject*);
				(void) va_arg(*p_va, PyObject **);
			}
#if 0
/* I don't know what this is for */
			else if (*format == '?') {
				inquiry pred = va_arg(*p_va, inquiry);
				format++;
				if ((*pred)(arg)) {
					(void) va_arg(*p_va, PyObject **);
				}
			}
#endif
			else if (*format == '&') {
				typedef int (*converter)(PyObject *, void *);
				(void) va_arg(*p_va, converter);
				(void) va_arg(*p_va, void *);
				format++;
			}
			else {
				(void) va_arg(*p_va, PyObject **);
			}
			break;
		}
	
	default:
		return getargs_bad_format;
	
	}
	
	*p_format = format;
	return NULL;
}
