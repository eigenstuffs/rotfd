
/* Module support implementation */

/* Adapted from CPython 2.1, Python/modsupport.c.
 * Copyright (c) 2001 Python Software Foundation; All Rights Reserved.
 * License: reference/cpython-2.1/LICENSE (retained with the reference source).
 * Changes: self-contained recovered ABI and inline-only un-emitted helpers;
 * omitted APIs absent from the linked original.
 * Original text: 0x8019E6A4..0x8019F914.
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

#define NULL 0
#define Py_INCREF(op) ((op)->ob_refcnt++)
#define Py_DECREF(op) if (--(op)->ob_refcnt != 0) ; else (*(op)->ob_type->tp_dealloc)((PyObject *)(op))
#define Py_None (&_Py_NoneStruct)
#define INT_MAX 2147483647
#define PYTHON_API_VERSION 1010
#define HAVE_LONG_LONG 1
#define LONG_LONG long long
#define VA_LIST_IS_ARRAY 1
typedef unsigned int size_t;
typedef unsigned short Py_UNICODE;
typedef struct { double real, imag; } Py_complex;
typedef PyObject *(*PyCFunction)(PyObject *, PyObject *);
typedef struct { char *ml_name; PyCFunction ml_meth; int ml_flags; char *ml_doc; } PyMethodDef;
typedef struct { char contents[80]; } FILE;
typedef struct { char gpr; char fpr; char reserved[2]; char *input_arg_area; char *reg_save_area; } va_list[1];
extern void __builtin_va_info(void *);
extern void *__va_arg(va_list, unsigned char);
#define va_start(ap,fmt) ((void)fmt,__builtin_va_info(&ap))
#define va_arg(ap,t) (*((t *)__va_arg(ap,_var_arg_typeof(t))))
#define va_end(ap) ((void)0)
extern FILE __files[];
#define stderr (&__files[2])
extern PyObject _Py_NoneStruct;
extern PyObject *PyExc_SystemError, *PyExc_OverflowError;
extern int fprintf(FILE *, const char *, ...);
extern char *strrchr(const char *, int);
extern int strcmp(const char *, const char *);
extern unsigned int strlen(const char *);
extern void *memcpy(void *, const void *, unsigned int);
extern int Py_IsInitialized(void);
extern void Py_FatalError(const char *);
extern PyObject *PyImport_AddModule(const char *);
extern PyObject *PyModule_GetDict(PyObject *);
extern PyObject *PyCFunction_New(PyMethodDef *, PyObject *);
extern int PyDict_SetItemString(PyObject *, const char *, PyObject *);
extern int PyDict_SetItem(PyObject *, PyObject *, PyObject *);
extern PyObject *PyDict_New(void);
extern PyObject *PyList_New(int);
extern int PyList_SetItem(PyObject *, int, PyObject *);
extern PyObject *PyTuple_New(int);
extern int PyTuple_SetItem(PyObject *, int, PyObject *);
extern PyObject *PyInt_FromLong(long);
extern PyObject *PyLong_FromLongLong(long long);
extern PyObject *PyUnicode_FromUnicode(Py_UNICODE *, int);
extern PyObject *PyFloat_FromDouble(double);
extern PyObject *PyComplex_FromCComplex(Py_complex);
extern PyObject *PyString_FromStringAndSize(const char *, int);
extern PyObject *PyString_FromString(const char *);
extern void PyErr_SetString(PyObject *, const char *);
extern PyObject *PyErr_Occurred(void);
PyObject *Py_VaBuildValue(char *, va_list);


#ifdef MPW /* MPW pushes 'extended' for float and double types with varargs */
typedef extended va_double;
#else
typedef double va_double;
#endif

/* Package context -- the full module name for package imports */
char *_Py_PackageContext = NULL;

/* Py_InitModule4() parameters:
   - name is the module name
   - methods is the list of top-level functions
   - doc is the documentation string
   - passthrough is passed as self to functions defined in the module
   - api_version is the value of PYTHON_API_VERSION at the time the
     module was compiled

   Return value is a borrowed reference to the module object; or NULL
   if an error occurred (in Python 1.4 and before, errors were fatal).
   Errors may still leak memory.
*/

static char api_version_warning[] =
"WARNING: Python C API version mismatch for module %s:\n\
  This Python has API version %d, module %s has version %d.\n";

PyObject *
Py_InitModule4(char *name, PyMethodDef *methods, char *doc,
	       PyObject *passthrough, int module_api_version)
{
	PyObject *m, *d, *v;
	PyMethodDef *ml;
	if (!Py_IsInitialized())
	    Py_FatalError("Interpreter not initialized (version mismatch?)");
	if (module_api_version != PYTHON_API_VERSION)
		fprintf(stderr, api_version_warning,
			name, PYTHON_API_VERSION, name, module_api_version);
	if (_Py_PackageContext != NULL) {
		char *p = strrchr(_Py_PackageContext, '.');
		if (p != NULL && strcmp(name, p+1) == 0) {
			name = _Py_PackageContext;
			_Py_PackageContext = NULL;
		}
	}
	if ((m = PyImport_AddModule(name)) == NULL)
		return NULL;
	d = PyModule_GetDict(m);
	for (ml = methods; ml->ml_name != NULL; ml++) {
		v = PyCFunction_New(ml, passthrough);
		if (v == NULL)
			return NULL;
		if (PyDict_SetItemString(d, ml->ml_name, v) != 0)
			return NULL;
		Py_DECREF(v);
	}
	if (doc != NULL) {
		v = PyString_FromString(doc);
		if (v == NULL || PyDict_SetItemString(d, "__doc__", v) != 0)
			return NULL;
		Py_DECREF(v);
	}
	return m;
}


/* Helper for mkvalue() to scan the length of a format */

static inline int countformat(char *format, int endchar)
{
	int count = 0;
	int level = 0;
	while (level > 0 || *format != endchar) {
		switch (*format) {
		case '\0':
			/* Premature end */
			PyErr_SetString(PyExc_SystemError,
					"unmatched paren in format");
			return -1;
		case '(':
		case '[':
		case '{':
			if (level == 0)
				count++;
			level++;
			break;
		case ')':
		case ']':
		case '}':
			level--;
			break;
		case '#':
		case '&':
		case ',':
		case ':':
		case ' ':
		case '\t':
			break;
		default:
			if (level == 0)
				count++;
		}
		format++;
	}
	return count;
}


/* Generic function to create a value -- the inverse of getargs() */
/* After an original idea and first implementation by Steven Miale */

static inline PyObject *do_mktuple(char**, va_list *, int, int);
static inline PyObject *do_mklist(char**, va_list *, int, int);
static PyObject *do_mkdict(char**, va_list *, int, int);
static PyObject *do_mkvalue(char**, va_list *);


static PyObject *
do_mkdict(char **p_format, va_list *p_va, int endchar, int n)
{
	PyObject *d;
	int i;
	if (n < 0)
		return NULL;
	if ((d = PyDict_New()) == NULL)
		return NULL;
	for (i = 0; i < n; i+= 2) {
		PyObject *k, *v;
		int err;
		k = do_mkvalue(p_format, p_va);
		if (k == NULL) {
			Py_DECREF(d);
			return NULL;
		}
		v = do_mkvalue(p_format, p_va);
		if (v == NULL) {
			Py_DECREF(k);
			Py_DECREF(d);
			return NULL;
		}
		err = PyDict_SetItem(d, k, v);
		Py_DECREF(k);
		Py_DECREF(v);
		if (err < 0) {
			Py_DECREF(d);
			return NULL;
		}
	}
	if (d != NULL && **p_format != endchar) {
		Py_DECREF(d);
		d = NULL;
		PyErr_SetString(PyExc_SystemError,
				"Unmatched paren in format");
	}
	else if (endchar)
		++*p_format;
	return d;
}

static inline PyObject *
do_mklist(char **p_format, va_list *p_va, int endchar, int n)
{
	PyObject *v;
	int i;
	if (n < 0)
		return NULL;
	if ((v = PyList_New(n)) == NULL)
		return NULL;
	for (i = 0; i < n; i++) {
		PyObject *w = do_mkvalue(p_format, p_va);
		if (w == NULL) {
			Py_DECREF(v);
			return NULL;
		}
		PyList_SetItem(v, i, w);
	}
	if (v != NULL && **p_format != endchar) {
		Py_DECREF(v);
		v = NULL;
		PyErr_SetString(PyExc_SystemError,
				"Unmatched paren in format");
	}
	else if (endchar)
		++*p_format;
	return v;
}

static inline int
_ustrlen(Py_UNICODE *u)
{
	int i = 0;
	Py_UNICODE *v = u;
	while (*v != 0) { i++; v++; } 
	return i;
}

static inline PyObject *
do_mktuple(char **p_format, va_list *p_va, int endchar, int n)
{
	PyObject *v;
	int i;
	if (n < 0)
		return NULL;
	if ((v = PyTuple_New(n)) == NULL)
		return NULL;
	for (i = 0; i < n; i++) {
		PyObject *w = do_mkvalue(p_format, p_va);
		if (w == NULL) {
			Py_DECREF(v);
			return NULL;
		}
		PyTuple_SetItem(v, i, w);
	}
	if (v != NULL && **p_format != endchar) {
		Py_DECREF(v);
		v = NULL;
		PyErr_SetString(PyExc_SystemError,
				"Unmatched paren in format");
	}
	else if (endchar)
		++*p_format;
	return v;
}

static PyObject *
do_mkvalue(char **p_format, va_list *p_va)
{
	for (;;) {
		switch (*(*p_format)++) {
		case '(':
			return do_mktuple(p_format, p_va, ')',
					  countformat(*p_format, ')'));

		case '[':
			return do_mklist(p_format, p_va, ']',
					 countformat(*p_format, ']'));

		case '{':
			return do_mkdict(p_format, p_va, '}',
					 countformat(*p_format, '}'));

		case 'b':
		case 'B':
		case 'h':
		case 'i':
			return PyInt_FromLong((long)va_arg(*p_va, int));
			
		case 'H':
			return PyInt_FromLong((long)va_arg(*p_va, unsigned int));

		case 'l':
			return PyInt_FromLong((long)va_arg(*p_va, long));

#ifdef HAVE_LONG_LONG
		case 'L':
			return PyLong_FromLongLong((LONG_LONG)va_arg(*p_va, LONG_LONG));
#endif
		case 'u':
		{
			PyObject *v;
			Py_UNICODE *u = va_arg(*p_va, Py_UNICODE *);
			int n;
			if (**p_format == '#') {
				++*p_format;
				n = va_arg(*p_va, int);
			}
			else
				n = -1;
			if (u == NULL) {
				v = Py_None;
				Py_INCREF(v);
			}
			else {
				if (n < 0)
					n = _ustrlen(u);
				v = PyUnicode_FromUnicode(u, n);
			}
			return v;
		}
		case 'f':
		case 'd':
			return PyFloat_FromDouble(
				(double)va_arg(*p_va, va_double));

#ifndef WITHOUT_COMPLEX
		case 'D':
			return PyComplex_FromCComplex(
				*((Py_complex *)va_arg(*p_va, Py_complex *)));
#endif /* WITHOUT_COMPLEX */

		case 'c':
		{
			char p[1];
			p[0] = va_arg(*p_va, int);
			return PyString_FromStringAndSize(p, 1);
		}

		case 's':
		case 'z':
		{
			PyObject *v;
			char *str = va_arg(*p_va, char *);
			int n;
			if (**p_format == '#') {
				++*p_format;
				n = va_arg(*p_va, int);
			}
			else
				n = -1;
			if (str == NULL) {
				v = Py_None;
				Py_INCREF(v);
			}
			else {
				if (n < 0) {
					size_t m = strlen(str);
					if (m > INT_MAX) {
						PyErr_SetString(PyExc_OverflowError,
							"string too long for Python string");
						return NULL;
					}
					n = (int)m;
				}
				v = PyString_FromStringAndSize(str, n);
			}
			return v;
		}

		case 'N':
		case 'S':
		case 'O':
		if (**p_format == '&') {
			typedef PyObject *(*converter)(void *);
			converter func = va_arg(*p_va, converter);
			void *arg = va_arg(*p_va, void *);
			++*p_format;
			return (*func)(arg);
		}
		else {
			PyObject *v;
			v = va_arg(*p_va, PyObject *);
			if (v != NULL) {
				if (*(*p_format - 1) != 'N')
					Py_INCREF(v);
			}
			else if (!PyErr_Occurred())
				/* If a NULL was passed
				 * because a call that should
				 * have constructed a value
				 * failed, that's OK, and we
				 * pass the error on; but if
				 * no error occurred it's not
				 * clear that the caller knew
				 * what she was doing. */
				PyErr_SetString(PyExc_SystemError,
					"NULL object passed to Py_BuildValue");
			return v;
		}

		case ':':
		case ',':
		case ' ':
		case '\t':
			break;

		default:
			PyErr_SetString(PyExc_SystemError,
				"bad format char passed to Py_BuildValue");
			return NULL;

		}
	}
}


PyObject *Py_BuildValue(char *format, ...)
{
	va_list va;
	PyObject* retval;
	va_start(va, format);
	retval = Py_VaBuildValue(format, va);
	va_end(va);
	return retval;
}

PyObject *
Py_VaBuildValue(char *format, va_list va)
{
	char *f = format;
	int n = countformat(f, '\0');
	va_list lva;

#ifdef VA_LIST_IS_ARRAY
	memcpy(lva, va, sizeof(va_list));
#else
	lva = va;
#endif

	if (n < 0)
		return NULL;
	if (n == 0) {
		Py_INCREF(Py_None);
		return Py_None;
	}
	if (n == 1)
		return do_mkvalue(&f, &lva);
	return do_mktuple(&f, &lva, '\0', n);
}


