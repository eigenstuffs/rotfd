/* Generic object operations in the Kalisto CPython runtime, GSQE78.
 * Derived from CPython 2.1 Objects/object.c and Include/object.h.
 * Copyright (c) 2001 Python Software Foundation; all rights reserved.
 * Upstream license: reference/cpython-2.1/LICENSE.
 * Reconstructs .text 0x80156580..0x8015987C with deferred emission order.
 * The complete text and initialized data match after relocation.
 */

#define NULL 0
#define PyObject_HEAD int ob_refcnt; struct _typeobject *ob_type;
#define PyObject_VAR_HEAD PyObject_HEAD int ob_size;
#define PyObject_HEAD_INIT(type) 1, type,
typedef unsigned int size_t;
typedef struct { unsigned char reserved[10]; unsigned char error; } FILE;
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
#define _Py_NewReference(op) ((op)->ob_refcnt = 1)
#define PyType_HasFeature(t, f) (((t)->tp_flags & (f)) != 0)
#define Py_TPFLAGS_HAVE_RICHCOMPARE (1L << 5)
#define RICHCOMPARE(t) (PyType_HasFeature((t), Py_TPFLAGS_HAVE_RICHCOMPARE) ? (t)->tp_richcompare : NULL)
#define Py_None (&_Py_NoneStruct)
#define Py_NotImplemented (&_Py_NotImplementedStruct)
#define PyTuple_Check(op) ((op)->ob_type == &PyTuple_Type)
#define PyList_Check(op) ((op)->ob_type == &PyList_Type)
#define PyDict_Check(op) ((op)->ob_type == &PyDict_Type)
#define PyFrame_Check(op) ((op)->ob_type == &PyFrame_Type)
#define PyTraceBack_Check(op) ((op)->ob_type == &PyTraceBack_Type)
#define PyInstance_Check(op) ((op)->ob_type == &PyInstance_Type)
#define PyFunction_Check(op) ((op)->ob_type == &PyFunction_Type)
#define PyMethod_Check(op) ((op)->ob_type == &PyMethod_Type)
#define PyCFunction_Check(op) ((op)->ob_type == &PyCFunction_Type)
#define PyClass_Check(op) ((op)->ob_type == &PyClass_Type)
#define PyString_Check(op) ((op)->ob_type == &PyString_Type)
#define PyUnicode_Check(op) ((op)->ob_type == &PyUnicode_Type)

typedef struct { PyObject_VAR_HEAD PyObject **ob_item; } PyListObject;
/* String bytes start at +0x14 in the target (hash and interned fields precede them). */
typedef struct { PyObject_VAR_HEAD long ob_shash; PyObject *ob_sinterned; char ob_sval[1]; } PyStringObject;
#define PyList_GET_SIZE(op) (((PyListObject *)(op))->ob_size)
#define PyList_GET_ITEM(op, i) (((PyListObject *)(op))->ob_item[i])
#define PyString_AS_STRING(op) (((PyStringObject *)(op))->ob_sval)

extern PyTypeObject PyType_Type, PyTuple_Type, PyList_Type, PyDict_Type;
extern PyTypeObject PyFrame_Type, PyTraceBack_Type, PyInstance_Type;
extern PyTypeObject PyFunction_Type, PyMethod_Type, PyCFunction_Type;
extern PyTypeObject PyClass_Type, PyString_Type, PyUnicode_Type;
extern PyObject _Py_NoneStruct, _Py_NotImplementedStruct;
extern PyObject *PyExc_TypeError, *PyExc_AttributeError;
extern void Py_FatalError(const char *);
extern void abort(void);
extern void *malloc(size_t);
extern void free(void *);
extern void PyErr_SetString(PyObject *, const char *);
extern PyObject *PyErr_Format(PyObject *, const char *, ...);
extern void PyErr_Clear(void);
extern PyObject *PyThreadState_GetDict(void);
extern PyObject *PyDict_GetItemString(PyObject *, const char *);
extern int PyDict_SetItemString(PyObject *, const char *, PyObject *);
extern PyObject *PyList_New(int);
extern int PyList_Append(PyObject *, PyObject *);
extern int PyList_SetSlice(PyObject *, int, int, PyObject *);
extern PyObject *PyString_FromString(const char *);
extern PyObject *PyString_InternFromString(const char *);
extern void PyString_InternInPlace(PyObject **);
extern PyObject *PyUnicode_AsEncodedString(PyObject *, const char *, const char *);


typedef unsigned int Py_uintptr_t;
typedef struct { PyObject_HEAD long ob_ival; } PyIntObject;
typedef struct { PyObject_VAR_HEAD PyObject *ob_item[1]; } PyTupleObject;
extern PyIntObject _Py_ZeroStruct, _Py_TrueStruct;
extern PyTypeObject PyInt_Type;
#define Py_True ((PyObject *)&_Py_TrueStruct)
#define Py_False ((PyObject *)&_Py_ZeroStruct)
#define PyInt_Check(op) ((op)->ob_type == &PyInt_Type)
#define PyInt_AS_LONG(op) (((PyIntObject *)(op))->ob_ival)
#define PyTuple_SET_ITEM(op, i, v) (((PyTupleObject *)(op))->ob_item[i] = (v))
#define Py_XINCREF(op) if ((op) == NULL) ; else Py_INCREF(op)
#define Py_TPFLAGS_CHECKTYPES (1L << 4)
#define PyType_SUPPORTS_WEAKREFS(t) (PyType_HasFeature((t), (1L << 6)) && (t)->tp_weaklistoffset > 0)
#define PyObject_GET_WEAKREFS_LISTPTR(o) ((PyObject **) (((char *)(o)) + (o)->ob_type->tp_weaklistoffset))
#define PyObject_MALLOC(n) malloc(n)
#define PyObject_FREE(p) free(p)
#define _PyObject_SIZE(tp) ((tp)->tp_basicsize)
#define PyObject_INIT(op, tp) ((op)->ob_type = (tp), _Py_NewReference(op), (op))
#define Py_PRINT_RAW 1
#define Py_LT 0
#define Py_LE 1
#define Py_EQ 2
#define Py_NE 3
#define Py_GT 4
#define Py_GE 5
#define assert(x) ((void)0)
#define LONG_MAX 2147483647L
#define SIZEOF_LONG 4
#define SIZEOF_VOID_P 4
#define Py_IS_INFINITY(x) ((x) && (x)*0.5 == (x))
#define ferror(fp) ((fp)->error)
extern int strcmp(const char *, const char *);
extern int sprintf(char *, const char *, ...);
extern int fprintf(FILE *, const char *, ...);
extern void clearerr(FILE *);
extern double modf(double, double *);
extern double frexp(double, int *);
extern PyObject *PyErr_NoMemory(void);
extern PyObject *PyObject_Repr(PyObject *);
extern PyObject *PyObject_Str(PyObject *);
extern long PyObject_Hash(PyObject *);
extern int PyObject_IsTrue(PyObject *);
extern int PyNumber_CoerceEx(PyObject **, PyObject **);
extern PyObject *PyObject_GetAttrString(PyObject *, char *);
extern int PyErr_CheckSignals(void);
extern PyObject *PyErr_SetFromErrno(PyObject *);
extern PyObject *PyErr_Occurred(void);
extern int PyErr_ExceptionMatches(PyObject *);
extern PyObject *PyExc_SystemError, *PyExc_IOError, *PyExc_ValueError;
extern void _PyErr_BadInternalCall(const char *, int);
#define PyErr_BadInternalCall() _PyErr_BadInternalCall("object.c", __LINE__)
extern PyObject *PyUnicode_AsUnicodeEscapeString(PyObject *);
extern int PyUnicode_Compare(PyObject *, PyObject *);
extern PyObject *PyEval_CallObjectWithKeywords(PyObject *, PyObject *, PyObject *);
#define PyEval_CallObject(f, a) PyEval_CallObjectWithKeywords(f, a, NULL)
extern PyObject *PyDict_New(void);
extern PyObject *PyDict_GetItem(PyObject *, PyObject *);
extern int PyDict_SetItem(PyObject *, PyObject *, PyObject *);
extern int PyDict_DelItem(PyObject *, PyObject *);
extern PyObject *PyTuple_New(int);
extern PyObject *PyLong_FromVoidPtr(void *);
extern PyObject *PyLong_FromDouble(double);
extern PyObject *PyInt_FromLong(long);
PyObject *
PyObject_Init(PyObject *op, PyTypeObject *tp)
{
	if (op == NULL) {
		PyErr_SetString(PyExc_SystemError,
				"NULL object passed to PyObject_Init");
		return op;
  	}
#ifdef WITH_CYCLE_GC
	if (PyType_IS_GC(tp))
		op = (PyObject *) PyObject_FROM_GC(op);
#endif
	/* Any changes should be reflected in PyObject_INIT (objimpl.h) */
	op->ob_type = tp;
	_Py_NewReference(op);
	if (PyType_SUPPORTS_WEAKREFS(tp)) {
		PyObject **weaklist = PyObject_GET_WEAKREFS_LISTPTR(op);
		*weaklist = NULL;
	}
	return op;
}

PyVarObject *
PyObject_InitVar(PyVarObject *op, PyTypeObject *tp, int size)
{
	if (op == NULL) {
		PyErr_SetString(PyExc_SystemError,
				"NULL object passed to PyObject_InitVar");
		return op;
	}
#ifdef WITH_CYCLE_GC
	if (PyType_IS_GC(tp))
		op = (PyVarObject *) PyObject_FROM_GC(op);
#endif
	/* Any changes should be reflected in PyObject_INIT_VAR */
	op->ob_size = size;
	op->ob_type = tp;
	_Py_NewReference((PyObject *)op);
	if (PyType_SUPPORTS_WEAKREFS(tp)) {
		PyObject **weaklist = PyObject_GET_WEAKREFS_LISTPTR(op);
		*weaklist = NULL;
	}
	return op;
}

PyObject *
_PyObject_New(PyTypeObject *tp)
{
	PyObject *op;
	op = (PyObject *) PyObject_MALLOC(_PyObject_SIZE(tp));
	if (op == NULL)
		return PyErr_NoMemory();
#ifdef WITH_CYCLE_GC
	if (PyType_IS_GC(tp))
		op = (PyObject *) PyObject_FROM_GC(op);
#endif
	return PyObject_INIT(op, tp);
}

void
_PyObject_Del(PyObject *op)
{
#ifdef WITH_CYCLE_GC
	if (op && PyType_IS_GC(op->ob_type)) {
		op = (PyObject *) PyObject_AS_GC(op);
	}
#endif
	PyObject_FREE(op);
}

int
PyObject_Print(PyObject *op, FILE *fp, int flags)
{
	int ret = 0;
	if (PyErr_CheckSignals())
		return -1;
#ifdef USE_STACKCHECK
	if (PyOS_CheckStack()) {
		PyErr_SetString(PyExc_MemoryError, "stack overflow");
		return -1;
	}
#endif
	clearerr(fp); /* Clear any previous error condition */
	if (op == NULL) {
		fprintf(fp, "<nil>");
	}
	else {
		if (op->ob_refcnt <= 0)
			fprintf(fp, "<refcnt %u at %p>",
				op->ob_refcnt, op);
		else if (op->ob_type->tp_print == NULL) {
			if (op->ob_type->tp_repr == NULL) {
				fprintf(fp, "<%s object at %p>",
					op->ob_type->tp_name, op);
			}
			else {
				PyObject *s;
				if (flags & Py_PRINT_RAW)
					s = PyObject_Str(op);
				else
					s = PyObject_Repr(op);
				if (s == NULL)
					ret = -1;
				else {
					ret = PyObject_Print(s, fp,
							     Py_PRINT_RAW);
				}
				Py_XDECREF(s);
			}
		}
		else
			ret = (*op->ob_type->tp_print)(op, fp, flags);
	}
	if (ret == 0) {
		if (ferror(fp)) {
			PyErr_SetFromErrno(PyExc_IOError);
			clearerr(fp);
			ret = -1;
		}
	}
	return ret;
}

PyObject *
PyObject_Repr(PyObject *v)
{
	if (PyErr_CheckSignals())
		return NULL;
#ifdef USE_STACKCHECK
	if (PyOS_CheckStack()) {
		PyErr_SetString(PyExc_MemoryError, "stack overflow");
		return NULL;
	}
#endif
	if (v == NULL)
		return PyString_FromString("<NULL>");
	else if (v->ob_type->tp_repr == NULL) {
		char buf[120];
		sprintf(buf, "<%.80s object at %p>",
			v->ob_type->tp_name, v);
		return PyString_FromString(buf);
	}
	else {
		PyObject *res;
		res = (*v->ob_type->tp_repr)(v);
		if (res == NULL)
			return NULL;
		if (PyUnicode_Check(res)) {
			PyObject* str;
			str = PyUnicode_AsUnicodeEscapeString(res);
			Py_DECREF(res);
			if (str)
				res = str;
			else
				return NULL;
		}
		if (!PyString_Check(res)) {
			PyErr_Format(PyExc_TypeError,
				     "__repr__ returned non-string (type %.200s)",
				     res->ob_type->tp_name);
			Py_DECREF(res);
			return NULL;
		}
		return res;
	}
}

PyObject *
PyObject_Str(PyObject *v)
{
	PyObject *res;
	
	if (v == NULL)
		return PyString_FromString("<NULL>");
	else if (PyString_Check(v)) {
		Py_INCREF(v);
		return v;
	}
	else if (v->ob_type->tp_str != NULL)
		res = (*v->ob_type->tp_str)(v);
	else {
		PyObject *func;
		if (!PyInstance_Check(v) ||
		    (func = PyObject_GetAttrString(v, "__str__")) == NULL) {
			PyErr_Clear();
			return PyObject_Repr(v);
		}
		res = PyEval_CallObject(func, (PyObject *)NULL);
		Py_DECREF(func);
	}
	if (res == NULL)
		return NULL;
	if (PyUnicode_Check(res)) {
		PyObject* str;
		str = PyUnicode_AsEncodedString(res, NULL, NULL);
		Py_DECREF(res);
		if (str)
			res = str;
		else
		    	return NULL;
	}
	if (!PyString_Check(res)) {
		PyErr_Format(PyExc_TypeError,
			     "__str__ returned non-string (type %.200s)",
			     res->ob_type->tp_name);
		Py_DECREF(res);
		return NULL;
	}
	return res;
}

/* Macro to get the tp_richcompare field of a type if defined */
#define RICHCOMPARE(t) (PyType_HasFeature((t), Py_TPFLAGS_HAVE_RICHCOMPARE) \
                         ? (t)->tp_richcompare : NULL)

/* Map rich comparison operators to their swapped version, e.g. LT --> GT */
static int swapped_op[] = {Py_GT, Py_GE, Py_EQ, Py_NE, Py_LT, Py_LE};

/* Try a genuine rich comparison, returning an object.  Return:
   NULL for exception;
   NotImplemented if this particular rich comparison is not implemented or
     undefined;
   some object not equal to NotImplemented if it is implemented
     (this latter object may not be a Boolean).
*/
static inline PyObject *
try_rich_compare(PyObject *v, PyObject *w, int op)
{
	richcmpfunc f;
	PyObject *res;

	if ((f = RICHCOMPARE(v->ob_type)) != NULL) {
		res = (*f)(v, w, op);
		if (res != Py_NotImplemented)
			return res;
		Py_DECREF(res);
	}
	if ((f = RICHCOMPARE(w->ob_type)) != NULL) {
		return (*f)(w, v, swapped_op[op]);
	}
	res = Py_NotImplemented;
	Py_INCREF(res);
	return res;
}

/* Try a genuine rich comparison, returning an int.  Return:
   -1 for exception (including the case where try_rich_compare() returns an
      object that's not a Boolean);
   0 if the outcome is false;
   1 if the outcome is true;
   2 if this particular rich comparison is not implemented or undefined.
*/
static inline int
try_rich_compare_bool(PyObject *v, PyObject *w, int op)
{
	PyObject *res;
	int ok;

	if (RICHCOMPARE(v->ob_type) == NULL && RICHCOMPARE(w->ob_type) == NULL)
		return 2; /* Shortcut, avoid INCREF+DECREF */
	res = try_rich_compare(v, w, op);
	if (res == NULL)
		return -1;
	if (res == Py_NotImplemented) {
		Py_DECREF(res);
		return 2;
	}
	ok = PyObject_IsTrue(res);
	Py_DECREF(res);
	return ok;
}

/* Try rich comparisons to determine a 3-way comparison.  Return:
   -2 for an exception;
   -1 if v < w;
   0 if v == w;
   1 if v > w;
   2 if this particular rich comparison is not implemented or undefined.
*/
static inline int
try_rich_to_3way_compare(PyObject *v, PyObject *w)
{
	static struct { int op; int outcome; } tries[3] = {
		/* Try this operator, and if it is true, use this outcome: */
		{Py_EQ, 0},
		{Py_LT, -1},
		{Py_GT, 1},
	};
	int i;

	if (RICHCOMPARE(v->ob_type) == NULL && RICHCOMPARE(w->ob_type) == NULL)
		return 2; /* Shortcut */

	for (i = 0; i < 3; i++) {
		switch (try_rich_compare_bool(v, w, tries[i].op)) {
		case -1:
			return -1;
		case 1:
			return tries[i].outcome;
		}
	}

	return 2;
}

/* Try a 3-way comparison, returning an int.  Return:
   -2 for an exception;
   -1 if v < w;
   0 if v == w;
   1 if v > w;
   2 if this particular 3-way comparison is not implemented or undefined.
*/
static int
try_3way_compare(PyObject *v, PyObject *w)
{
	int c;
	cmpfunc f;

	/* Comparisons involving instances are given to instance_compare,
	   which has the same return conventions as this function. */

	if (PyInstance_Check(v))
		return (*v->ob_type->tp_compare)(v, w);
	if (PyInstance_Check(w))
		return (*w->ob_type->tp_compare)(v, w);

	/* If the types are equal, don't bother with coercions etc. */
	if (v->ob_type == w->ob_type) {
		if ((f = v->ob_type->tp_compare) == NULL)
			return 2;
		c = (*f)(v, w);
		if (PyErr_Occurred())
			return -2;
		return c < 0 ? -1 : c > 0 ? 1 : 0;
	}

	/* Try coercion; if it fails, give up */
	c = PyNumber_CoerceEx(&v, &w);
	if (c < 0)
		return -2;
	if (c > 0)
		return 2;

	/* Try v's comparison, if defined */
	if ((f = v->ob_type->tp_compare) != NULL) {
		c = (*f)(v, w);
		Py_DECREF(v);
		Py_DECREF(w);
		if (PyErr_Occurred())
			return -2;
		return c < 0 ? -1 : c > 0 ? 1 : 0;
	}

	/* Try w's comparison, if defined */
	if ((f = w->ob_type->tp_compare) != NULL) {
		c = (*f)(w, v); /* swapped! */
		Py_DECREF(v);
		Py_DECREF(w);
		if (PyErr_Occurred())
			return -2;
		return c < 0 ? 1 : c > 0 ? -1 : 0; /* negated! */
	}

	/* No comparison defined */
	Py_DECREF(v);
	Py_DECREF(w);
	return 2;
}

/* Final fallback 3-way comparison, returning an int.  Return:
   -2 if an error occurred;
   -1 if v < w;
   0 if v == w;
   1 if v > w.
*/
static inline int
default_3way_compare(PyObject *v, PyObject *w)
{
	int c;
	char *vname, *wname;

	if (v->ob_type == w->ob_type) {
		/* When comparing these pointers, they must be cast to
		 * integer types (i.e. Py_uintptr_t, our spelling of C9X's
		 * uintptr_t).  ANSI specifies that pointer compares other
		 * than == and != to non-related structures are undefined.
		 */
		Py_uintptr_t vv = (Py_uintptr_t)v;
		Py_uintptr_t ww = (Py_uintptr_t)w;
		return (vv < ww) ? -1 : (vv > ww) ? 1 : 0;
	}

	/* Special case for Unicode */
	if (PyUnicode_Check(v) || PyUnicode_Check(w)) {
		c = PyUnicode_Compare(v, w);
		if (!PyErr_Occurred())
			return c;
		/* TypeErrors are ignored: if Unicode coercion fails due
		   to one of the arguments not having the right type, we
		   continue as defined by the coercion protocol (see
		   above).  Luckily, decoding errors are reported as
		   ValueErrors and are not masked by this technique. */
		if (!PyErr_ExceptionMatches(PyExc_TypeError))
			return -2;
		PyErr_Clear();
	}

	/* None is smaller than anything */
	if (v == Py_None)
		return -1;
	if (w == Py_None)
		return 1;

	/* different type: compare type names */
	if (v->ob_type->tp_as_number)
		vname = "";
	else
		vname = v->ob_type->tp_name;
	if (w->ob_type->tp_as_number)
		wname = "";
	else
		wname = w->ob_type->tp_name;
	c = strcmp(vname, wname);
	if (c < 0)
		return -1;
	if (c > 0)
		return 1;
	/* Same type name, or (more likely) incomparable numeric types */
	return ((Py_uintptr_t)(v->ob_type) < (
		Py_uintptr_t)(w->ob_type)) ? -1 : 1;
}

#define CHECK_TYPES(o) PyType_HasFeature((o)->ob_type, Py_TPFLAGS_CHECKTYPES)

static int
do_cmp(PyObject *v, PyObject *w)
{
	int c;

	c = try_rich_to_3way_compare(v, w);
	if (c < 2)
		return c;
	c = try_3way_compare(v, w);
	if (c < 2)
		return c;
	return default_3way_compare(v, w);
}

/* compare_nesting is incremented before calling compare (for
   some types) and decremented on exit.  If the count exceeds the
   nesting limit, enable code to detect circular data structures.

   This is a tunable parameter that should only affect the performance
   of comparisons, nothing else.  Setting it high makes comparing deeply
   nested non-cyclical data structures faster, but makes comparing cyclical
   data structures slower.
*/
#define NESTING_LIMIT 20

static int compare_nesting = 0;

static inline PyObject*
get_inprogress_dict(void)
{
	static PyObject *key;
	PyObject *tstate_dict, *inprogress;

	if (key == NULL) {
		key = PyString_InternFromString("cmp_state");
		if (key == NULL)
			return NULL;
	}

	tstate_dict = PyThreadState_GetDict();
	if (tstate_dict == NULL) {
		_PyErr_BadInternalCall("object.c", 661);
		return NULL;
	} 

	inprogress = PyDict_GetItem(tstate_dict, key); 
	if (inprogress == NULL) {
		inprogress = PyDict_New();
		if (inprogress == NULL)
			return NULL;
		if (PyDict_SetItem(tstate_dict, key, inprogress) == -1) {
		    Py_DECREF(inprogress);
		    return NULL;
		}
		Py_DECREF(inprogress);
	}

	return inprogress;
}

static PyObject *
check_recursion(PyObject *v, PyObject *w, int op)
{
	PyObject *inprogress;
	PyObject *token;
	Py_uintptr_t iv = (Py_uintptr_t)v;
	Py_uintptr_t iw = (Py_uintptr_t)w;
	PyObject *x, *y, *z;

	inprogress = get_inprogress_dict();
	if (inprogress == NULL)
		return NULL;

	token = PyTuple_New(3);
	if (token == NULL)
		return NULL;

	if (iv <= iw) {
		PyTuple_SET_ITEM(token, 0, x = PyLong_FromVoidPtr((void *)v));
		PyTuple_SET_ITEM(token, 1, y = PyLong_FromVoidPtr((void *)w));
		if (op >= 0)
			op = swapped_op[op];
	} else {
		PyTuple_SET_ITEM(token, 0, x = PyLong_FromVoidPtr((void *)w));
		PyTuple_SET_ITEM(token, 1, y = PyLong_FromVoidPtr((void *)v));
	}
	PyTuple_SET_ITEM(token, 2, z = PyInt_FromLong((long)op));
	if (x == NULL || y == NULL || z == NULL) {
		Py_DECREF(token);
		return NULL;
	}

	if (PyDict_GetItem(inprogress, token) != NULL) {
		Py_DECREF(token);
		return Py_None; /* Without INCREF! */
	}

	if (PyDict_SetItem(inprogress, token, token) < 0) {
		Py_DECREF(token);
		return NULL;
	}

	return token;
}

static inline void
delete_token(PyObject *token)
{
	PyObject *inprogress;

	if (token == NULL || token == Py_None)
		return;
	inprogress = get_inprogress_dict();
	if (inprogress == NULL)
		PyErr_Clear();
	else
		PyDict_DelItem(inprogress, token);
	Py_DECREF(token);
}

int
PyObject_Compare(PyObject *v, PyObject *w)
{
	PyTypeObject *vtp;
	int result;

#if defined(USE_STACKCHECK)
	if (PyOS_CheckStack()) {
		PyErr_SetString(PyExc_MemoryError, "Stack overflow");
        return -1;
	}
#endif
	if (v == NULL || w == NULL) {
		_PyErr_BadInternalCall("object.c", 753);
		return -1;
	}
	if (v == w)
		return 0;
	vtp = v->ob_type;
	compare_nesting++;
	if (compare_nesting > NESTING_LIMIT &&
		(vtp->tp_as_mapping
		 || (vtp->tp_as_sequence
		     && !PyString_Check(v)
		     && !PyTuple_Check(v)))) {
		/* try to detect circular data structures */
		PyObject *token = check_recursion(v, w, -1);

		if (token == NULL) {
			result = -1;
		}
		else if (token == Py_None) {
			/* already comparing these objects.  assume
			   they're equal until shown otherwise */
                        result = 0;
		}
		else {
			result = do_cmp(v, w);
			delete_token(token);
		}
	}
	else {
		result = do_cmp(v, w);
	}
	compare_nesting--;
	return result < 0 ? -1 : result;
}

static inline PyObject *
try_3way_to_rich_compare(PyObject *v, PyObject *w, int op)
{
	int c;
	PyObject *result;

	c = try_3way_compare(v, w);
	if (c >= 2)
		c = default_3way_compare(v, w);
	if (c <= -2)
		return NULL;
	switch (op) {
	case Py_LT: c = c <  0; break;
	case Py_LE: c = c <= 0; break;
	case Py_EQ: c = c == 0; break;
	case Py_NE: c = c != 0; break;
	case Py_GT: c = c >  0; break;
	case Py_GE: c = c >= 0; break;
	}
	result = c ? Py_True : Py_False;
	Py_INCREF(result);
	return result;
}

static inline PyObject *
do_richcmp(PyObject *v, PyObject *w, int op)
{
	PyObject *res;

	res = try_rich_compare(v, w, op);
	if (res != Py_NotImplemented)
		return res;
	Py_DECREF(res);

	return try_3way_to_rich_compare(v, w, op);
}

PyObject *
PyObject_RichCompare(PyObject *v, PyObject *w, int op)
{
	PyObject *res;

	assert(Py_LT <= op && op <= Py_GE);

	compare_nesting++;
	if (compare_nesting > NESTING_LIMIT &&
		(v->ob_type->tp_as_mapping
		 || (v->ob_type->tp_as_sequence
		     && !PyString_Check(v)
		     && !PyTuple_Check(v)))) {
		/* try to detect circular data structures */
		PyObject *token = check_recursion(v, w, op);

		if (token == NULL) {
			res = NULL;
		}
		else if (token == Py_None) {
			/* already comparing these objects with this operator.
			   assume they're equal until shown otherwise */
			if (op == Py_EQ)
				res = Py_True;
			else if (op == Py_NE)
				res = Py_False;
			else {
				PyErr_SetString(PyExc_ValueError,
					"can't order recursive values");
				res = NULL;
			}
			Py_XINCREF(res);
		}
		else {
			res = do_richcmp(v, w, op);
			delete_token(token);
		}
	}
	else {
		res = do_richcmp(v, w, op);
	}
	compare_nesting--;
	return res;
}

int
PyObject_RichCompareBool(PyObject *v, PyObject *w, int op)
{
	PyObject *res = PyObject_RichCompare(v, w, op);
	int ok;

	if (res == NULL)
		return -1;
	ok = PyObject_IsTrue(res);
	Py_DECREF(res);
	return ok;
}

/* Set of hash utility functions to help maintaining the invariant that
	iff a==b then hash(a)==hash(b)

   All the utility functions (_Py_Hash*()) return "-1" to signify an error.
*/

long
_Py_HashDouble(double v)
{
	double intpart, fractpart;
	int expo;
	long hipart;
	long x;		/* the final hash value */
	/* This is designed so that Python numbers of different types
	 * that compare equal hash to the same value; otherwise comparisons
	 * of mapping keys will turn out weird.
	 */

#ifdef MPW /* MPW C modf expects pointer to extended as second argument */
{
	extended e;
	fractpart = modf(v, &e);
	intpart = e;
}
#else
	fractpart = modf(v, &intpart);
#endif
	if (fractpart == 0.0) {
		/* This must return the same hash as an equal int or long. */
		if (intpart > LONG_MAX || -intpart > LONG_MAX) {
			/* Convert to long and use its hash. */
			PyObject *plong;	/* converted to Python long */
			if (Py_IS_INFINITY(intpart))
				/* can't convert to long int -- arbitrary */
				v = v < 0 ? -271828.0 : 314159.0;
			plong = PyLong_FromDouble(v);
			if (plong == NULL)
				return -1;
			x = PyObject_Hash(plong);
			Py_DECREF(plong);
			return x;
		}
		/* Fits in a C long == a Python int, so is its own hash. */
		x = (long)intpart;
		if (x == -1)
			x = -2;
		return x;
	}
	/* The fractional part is non-zero, so we don't have to worry about
	 * making this match the hash of some other type.
	 * Use frexp to get at the bits in the double.
	 * Since the VAX D double format has 56 mantissa bits, which is the
	 * most of any double format in use, each of these parts may have as
	 * many as (but no more than) 56 significant bits.
	 * So, assuming sizeof(long) >= 4, each part can be broken into two
	 * longs; frexp and multiplication are used to do that.
	 * Also, since the Cray double format has 15 exponent bits, which is
	 * the most of any double format in use, shifting the exponent field
	 * left by 15 won't overflow a long (again assuming sizeof(long) >= 4).
	 */
	v = frexp(v, &expo);
	v *= 2147483648.0;	/* 2**31 */
	hipart = (long)v;	/* take the top 32 bits */
	v = (v - (double)hipart) * 2147483648.0; /* get the next 32 bits */
	x = hipart + (long)v + (expo << 15);
	if (x == -1)
		x = -2;
	return x;
}

long
_Py_HashPointer(void *p)
{
#if SIZEOF_LONG >= SIZEOF_VOID_P
	return (long)p;
#else
	/* convert to a Python long and hash that */
	PyObject* longobj;
	long x;
	
	if ((longobj = PyLong_FromVoidPtr(p)) == NULL) {
		x = -1;
		goto finally;
	}
	x = PyObject_Hash(longobj);
	
finally:
	Py_XDECREF(longobj);
	return x;
#endif
}


long
PyObject_Hash(PyObject *v)
{
	PyTypeObject *tp = v->ob_type;
	if (tp->tp_hash != NULL)
		return (*tp->tp_hash)(v);
	if (tp->tp_compare == NULL && RICHCOMPARE(tp) == NULL) {
		return (long)v; /* Use address as hash value */
	}
	/* If there's a cmp but no hash defined, the object can't be hashed */
	PyErr_SetString(PyExc_TypeError, "unhashable type");
	return -1;
}

PyObject *
PyObject_GetAttrString(PyObject *v, char *name)
{
	if (v->ob_type->tp_getattro != NULL) {
		PyObject *w, *res;
		w = PyString_InternFromString(name);
		if (w == NULL)
			return NULL;
		res = (*v->ob_type->tp_getattro)(v, w);
		Py_XDECREF(w);
		return res;
	}

	if (v->ob_type->tp_getattr == NULL) {
		PyErr_Format(PyExc_AttributeError,
			     "'%.50s' object has no attribute '%.400s'",
			     v->ob_type->tp_name,
			     name);
		return NULL;
	}
	else {
		return (*v->ob_type->tp_getattr)(v, name);
	}
}

int
PyObject_HasAttrString(PyObject *v, char *name)
{
	PyObject *res = PyObject_GetAttrString(v, name);
	if (res != NULL) {
		Py_DECREF(res);
		return 1;
	}
	PyErr_Clear();
	return 0;
}

int
PyObject_SetAttrString(PyObject *v, char *name, PyObject *w)
{
	if (v->ob_type->tp_setattro != NULL) {
		PyObject *s;
		int res;
		s = PyString_InternFromString(name);
		if (s == NULL)
			return -1;
		res = (*v->ob_type->tp_setattro)(v, s, w);
		Py_XDECREF(s);
		return res;
	}

	if (v->ob_type->tp_setattr == NULL) {
		if (v->ob_type->tp_getattr == NULL)
			PyErr_SetString(PyExc_TypeError,
				   "attribute-less object (assign or del)");
		else
			PyErr_SetString(PyExc_TypeError,
				   "object has read-only attributes");
		return -1;
	}
	else {
		return (*v->ob_type->tp_setattr)(v, name, w);
	}
}

/* Internal API needed by PyObject_GetAttr(): */
extern 
PyObject *_PyUnicode_AsDefaultEncodedString(PyObject *unicode,
				  const char *errors);

PyObject *
PyObject_GetAttr(PyObject *v, PyObject *name)
{
	/* The Unicode to string conversion is done here because the
	   existing tp_getattro slots expect a string object as name
	   and we wouldn't want to break those. */
	if (PyUnicode_Check(name)) {
		name = _PyUnicode_AsDefaultEncodedString(name, NULL);
		if (name == NULL)
			return NULL;
	}

	if (!PyString_Check(name)) {
		PyErr_SetString(PyExc_TypeError,
				"attribute name must be string");
		return NULL;
	}
	if (v->ob_type->tp_getattro != NULL)
		return (*v->ob_type->tp_getattro)(v, name);
	else
	return PyObject_GetAttrString(v, PyString_AS_STRING(name));
}

int
PyObject_HasAttr(PyObject *v, PyObject *name)
{
	PyObject *res = PyObject_GetAttr(v, name);
	if (res != NULL) {
		Py_DECREF(res);
		return 1;
	}
	PyErr_Clear();
	return 0;
}

int
PyObject_SetAttr(PyObject *v, PyObject *name, PyObject *value)
{
	int err;

	/* The Unicode to string conversion is done here because the
	   existing tp_setattro slots expect a string object as name
	   and we wouldn't want to break those. */
	if (PyUnicode_Check(name)) {
		name = PyUnicode_AsEncodedString(name, NULL, NULL);
		if (name == NULL)
			return -1;
	}
	else
		Py_INCREF(name);
	
	if (!PyString_Check(name)){
		PyErr_SetString(PyExc_TypeError,
				"attribute name must be string");
		err = -1;
	}
	else {
		PyString_InternInPlace(&name);
		if (v->ob_type->tp_setattro != NULL)
			err = (*v->ob_type->tp_setattro)(v, name, value);
		else
			err = PyObject_SetAttrString(v, 
				        PyString_AS_STRING(name), value);
	}
	
	Py_DECREF(name);
	return err;
}

/* Test a value used as condition, e.g., in a for or if statement.
   Return -1 if an error occurred */

int
PyObject_IsTrue(PyObject *v)
{
	int res;
	if (v == Py_None)
		res = 0;
	else if (v->ob_type->tp_as_number != NULL &&
		 v->ob_type->tp_as_number->nb_nonzero != NULL)
		res = (*v->ob_type->tp_as_number->nb_nonzero)(v);
	else if (v->ob_type->tp_as_mapping != NULL &&
		 v->ob_type->tp_as_mapping->mp_length != NULL)
		res = (*v->ob_type->tp_as_mapping->mp_length)(v);
	else if (v->ob_type->tp_as_sequence != NULL &&
		 v->ob_type->tp_as_sequence->sq_length != NULL)
		res = (*v->ob_type->tp_as_sequence->sq_length)(v);
	else
		res = 1;
	if (res > 0)
		res = 1;
	return res;
}

/* equivalent of 'not v' 
   Return -1 if an error occurred */

/* Coerce two numeric types to the "larger" one.
   Increment the reference count on each argument.
   Return value:
   -1 if an error occurred;
   0 if the coercion succeeded (and then the reference counts are increased);
   1 if no coercion is possible (and no error is raised).
*/
int
PyNumber_CoerceEx(PyObject **pv, PyObject **pw)
{
	register PyObject *v = *pv;
	register PyObject *w = *pw;
	int res;

	if (v->ob_type == w->ob_type && !PyInstance_Check(v)) {
		Py_INCREF(v);
		Py_INCREF(w);
		return 0;
	}
	if (v->ob_type->tp_as_number && v->ob_type->tp_as_number->nb_coerce) {
		res = (*v->ob_type->tp_as_number->nb_coerce)(pv, pw);
		if (res <= 0)
			return res;
	}
	if (w->ob_type->tp_as_number && w->ob_type->tp_as_number->nb_coerce) {
		res = (*w->ob_type->tp_as_number->nb_coerce)(pw, pv);
		if (res <= 0)
			return res;
	}
	return 1;
}

/* Coerce two numeric types to the "larger" one.
   Increment the reference count on each argument.
   Return -1 and raise an exception if no coercion is possible
   (and then no reference count is incremented).
*/
int
PyNumber_Coerce(PyObject **pv, PyObject **pw)
{
	int err = PyNumber_CoerceEx(pv, pw);
	if (err <= 0)
		return err;
	PyErr_SetString(PyExc_TypeError, "number coercion failed");
	return -1;
}


/* Test whether an object can be called */

int
PyCallable_Check(PyObject *x)
{
	if (x == NULL)
		return 0;
	if (x->ob_type->tp_call != NULL ||
	    PyFunction_Check(x) ||
	    PyMethod_Check(x) ||
	    PyCFunction_Check(x) ||
	    PyClass_Check(x))
		return 1;
	if (PyInstance_Check(x)) {
		PyObject *call = PyObject_GetAttrString(x, "__call__");
		if (call == NULL) {
			PyErr_Clear();
			return 0;
		}
		/* Could test recursively but don't, for fear of endless
		   recursion if some joker sets self.__call__ = self */
		Py_DECREF(call);
		return 1;
	}
	return 0;
}


/*
NoObject is usable as a non-NULL undefined value, used by the macro None.
There is (and should be!) no way to create other objects of this type,
so there is exactly one (which is indestructible, by the way).
*/

/* ARGSUSED */
static PyObject *
none_repr(PyObject *op)
{
	return PyString_FromString("None");
}

/* ARGUSED */
static void
none_dealloc(PyObject* ignore) 
{
	/* This should never get called, but we also don't want to SEGV if
	 * we accidently decref None out of existance.
	 */
	abort();
}


static PyTypeObject PyNothing_Type = {
	PyObject_HEAD_INIT(&PyType_Type)
	0,
	"None",
	0,
	0,
	(destructor)none_dealloc,	     /*tp_dealloc*/ /*never called*/
	0,		/*tp_print*/
	0,		/*tp_getattr*/
	0,		/*tp_setattr*/
	0,		/*tp_compare*/
	(reprfunc)none_repr, /*tp_repr*/
	0,		/*tp_as_number*/
	0,		/*tp_as_sequence*/
	0,		/*tp_as_mapping*/
	0,		/*tp_hash */
};

PyObject _Py_NoneStruct = {
	PyObject_HEAD_INIT(&PyNothing_Type)
};

/* NotImplemented is an object that can be used to signal that an
   operation is not implemented for the given type combination. */

static PyObject *
NotImplemented_repr(PyObject *op)
{
	return PyString_FromString("NotImplemented");
}

static PyTypeObject PyNotImplemented_Type = {
	PyObject_HEAD_INIT(&PyType_Type)
	0,
	"NotImplemented",
	0,
	0,
	(destructor)none_dealloc,	     /*tp_dealloc*/ /*never called*/
	0,		/*tp_print*/
	0,		/*tp_getattr*/
	0,		/*tp_setattr*/
	0,		/*tp_compare*/
	(reprfunc)NotImplemented_repr, /*tp_repr*/
	0,		/*tp_as_number*/
	0,		/*tp_as_sequence*/
	0,		/*tp_as_mapping*/
	0,		/*tp_hash */
};

PyObject _Py_NotImplementedStruct = {
	PyObject_HEAD_INIT(&PyNotImplemented_Type)
};


void *
PyMem_Malloc(size_t nbytes)
{
    if (nbytes == 0)
        nbytes = 1;
    return malloc(nbytes);
}

void
PyMem_Free(void *p)
{
    free(p);
}

/* Hook to clear up weak references only once the _weakref module is
   imported.  We use a dummy implementation to simplify the code at each
   call site instead of requiring a test for NULL.
*/

static void
empty_clear_weak_refs(PyObject *o)
{
    return;
}

void (*PyObject_ClearWeakRefs)(PyObject *) = empty_clear_weak_refs;



/* These methods are used to control infinite recursion in repr, str, print,
   etc.  Container objects that may recursively contain themselves,
   e.g. builtin dictionaries and lists, should used Py_ReprEnter() and
   Py_ReprLeave() to avoid infinite recursion.

   Py_ReprEnter() returns 0 the first time it is called for a particular
   object and 1 every time thereafter.  It returns -1 if an exception
   occurred.  Py_ReprLeave() has no return value.

   See dictobject.c and listobject.c for examples of use.
*/

#define KEY "Py_Repr"

int
Py_ReprEnter(PyObject *obj)
{
	PyObject *dict;
	PyObject *list;
	int i;

	dict = PyThreadState_GetDict();
	if (dict == NULL)
		return -1;
	list = PyDict_GetItemString(dict, KEY);
	if (list == NULL) {
		list = PyList_New(0);
		if (list == NULL)
			return -1;
		if (PyDict_SetItemString(dict, KEY, list) < 0)
			return -1;
		Py_DECREF(list);
	}
	i = PyList_GET_SIZE(list);
	while (--i >= 0) {
		if (PyList_GET_ITEM(list, i) == obj)
			return 1;
	}
	PyList_Append(list, obj);
	return 0;
}

void
Py_ReprLeave(PyObject *obj)
{
	PyObject *dict;
	PyObject *list;
	int i;

	dict = PyThreadState_GetDict();
	if (dict == NULL)
		return;
	list = PyDict_GetItemString(dict, KEY);
	if (list == NULL || !PyList_Check(list))
		return;
	i = PyList_GET_SIZE(list);
	/* Count backwards because we always expect obj to be list[-1] */
	while (--i >= 0) {
		if (PyList_GET_ITEM(list, i) == obj) {
			PyList_SetSlice(list, i, i + 1, NULL);
			break;
		}
	}
}

/*
  trashcan
  CT 2k0130
  non-recursively destroy nested objects

  CT 2k0223
  everything is now done in a macro.

  CT 2k0305
  modified to use functions, after Tim Peter's suggestion.

  CT 2k0309
  modified to restore a possible error.

  CT 2k0325
  added better safe than sorry check for threadstate

  CT 2k0422
  complete rewrite. We now build a chain via ob_type
  and save the limited number of types in ob_refcnt.
  This is perfect since we don't need any memory.
  A patch for free-threading would need just a lock.
*/

#define Py_TRASHCAN_TUPLE       1
#define Py_TRASHCAN_LIST        2
#define Py_TRASHCAN_DICT        3
#define Py_TRASHCAN_FRAME       4
#define Py_TRASHCAN_TRACEBACK   5
/* extend here if other objects want protection */

int _PyTrash_delete_nesting = 0;

PyObject * _PyTrash_delete_later = NULL;

void
_PyTrash_deposit_object(PyObject *op)
{
	int typecode;

	if (PyTuple_Check(op))
		typecode = Py_TRASHCAN_TUPLE;
	else if (PyList_Check(op))
		typecode = Py_TRASHCAN_LIST;
	else if (PyDict_Check(op))
		typecode = Py_TRASHCAN_DICT;
	else if (PyFrame_Check(op))
		typecode = Py_TRASHCAN_FRAME;
	else if (PyTraceBack_Check(op))
		typecode = Py_TRASHCAN_TRACEBACK;
	else /* We have a bug here -- those are the only types in GC */ {
		Py_FatalError("Type not supported in GC -- internal bug");
		return; /* pacify compiler -- execution never here */
	}
	op->ob_refcnt = typecode;

	op->ob_type = (PyTypeObject*)_PyTrash_delete_later;
	_PyTrash_delete_later = op;
}

void
_PyTrash_destroy_chain(void)
{
	while (_PyTrash_delete_later) {
		PyObject *shredder = _PyTrash_delete_later;
		_PyTrash_delete_later = (PyObject*) shredder->ob_type;

		switch (shredder->ob_refcnt) {
		case Py_TRASHCAN_TUPLE:
			shredder->ob_type = &PyTuple_Type;
			break;
		case Py_TRASHCAN_LIST:
			shredder->ob_type = &PyList_Type;
			break;
		case Py_TRASHCAN_DICT:
			shredder->ob_type = &PyDict_Type;
			break;
		case Py_TRASHCAN_FRAME:
			shredder->ob_type = &PyFrame_Type;
			break;
		case Py_TRASHCAN_TRACEBACK:
			shredder->ob_type = &PyTraceBack_Type;
			break;
		}
		_Py_NewReference(shredder);

		++_PyTrash_delete_nesting;
		Py_DECREF(shredder);
		--_PyTrash_delete_nesting;
	}
}

