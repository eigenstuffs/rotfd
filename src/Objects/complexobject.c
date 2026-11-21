/* Complex numbers in the Kalisto CPython runtime, GSQE78.
 * Derived from CPython 2.1 Objects/complexobject.c and Include/object.h.
 * Copyright (c) 2001 Python Software Foundation; all rights reserved.
 * Upstream license: reference/cpython-2.1/LICENSE.
 */

/* Complex object implementation */

/* Borrows heavily from floatobject.c */

/* Submitted by Jim Hugunin */

#ifndef WITHOUT_COMPLEX

#define NULL 0
#define PyObject_HEAD int ob_refcnt; struct _typeobject *ob_type;
#define PyObject_VAR_HEAD PyObject_HEAD int ob_size;
#define PyObject_HEAD_INIT(type) 1, type,
typedef unsigned int size_t;
typedef struct { unsigned char reserved[80]; } FILE;
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
#define PyObject_INIT(op, tp) ((op)->ob_type = (tp), _Py_NewReference(op), (op))
#define Py_None (&_Py_NoneStruct)
#define Py_NotImplemented (&_Py_NotImplementedStruct)
#define PyFloat_Check(op) ((op)->ob_type == &PyFloat_Type)
#define PyInt_Check(op) ((op)->ob_type == &PyInt_Type)
#define PyLong_Check(op) ((op)->ob_type == &PyLong_Type)
#define PyComplex_Check(op) ((op)->ob_type == &PyComplex_Type)
#define Py_PRINT_RAW 1
#define PyObject_MALLOC(n) malloc(n)
#define PyObject_DEL(p) free(p)
#define PyFPE_START_PROTECT(err, ret)
#define PyFPE_END_PROTECT(v)
#define ERANGE 34
#define EDOM 33
#define assert(x) ((void)0)
#define Py_EQ 2
#define Py_NE 3
#define Py_TPFLAGS_DEFAULT 0x6B

typedef struct { double real; double imag; } Py_complex;
typedef struct { PyObject_HEAD Py_complex cval; } PyComplexObject;
typedef struct { PyObject_HEAD long ob_ival; } PyIntObject;
typedef PyObject *(*PyCFunction)(PyObject *, PyObject *);
typedef struct PyMethodDef { char *ml_name; PyCFunction ml_meth; int ml_flags; char *ml_doc; } PyMethodDef;
extern PyTypeObject PyType_Type, PyFloat_Type, PyInt_Type, PyLong_Type, PyComplex_Type;
extern PyObject _Py_NoneStruct, _Py_NotImplementedStruct;
extern PyIntObject _Py_TrueStruct, _Py_ZeroStruct;
#define Py_True ((PyObject *)&_Py_TrueStruct)
#define Py_False ((PyObject *)&_Py_ZeroStruct)
extern PyObject *PyExc_ValueError, *PyExc_TypeError, *PyExc_ZeroDivisionError;
extern int errno;
extern void *malloc(size_t);
extern void free(void *);
extern PyObject *PyErr_NoMemory(void);
extern void PyErr_SetString(PyObject *, const char *);
extern PyObject *PyFloat_FromDouble(double);
extern double PyFloat_AsDouble(PyObject *);
extern PyObject *PyString_FromString(const char *);
extern long PyInt_AsLong(PyObject *);
extern double PyLong_AsDouble(PyObject *);
extern long _Py_HashDouble(double);
extern PyObject *Py_BuildValue(const char *, ...);
extern int PyArg_ParseTuple(PyObject *, const char *, ...);
extern PyObject *Py_FindMethod(PyMethodDef *, PyObject *, char *);
extern int PyNumber_CoerceEx(PyObject **, PyObject **);
extern int sprintf(char *, const char *, ...);
extern int fputs(const char *, FILE *);
extern int strcmp(const char *, const char *);
extern double pow(double, double), hypot(double, double), atan2(double, double);
extern double floor(double), exp(double), log(double), sin(double), cos(double);


/* Precisions used by repr() and str(), respectively.

   The repr() precision (17 significant decimal digits) is the minimal number
   that is guaranteed to have enough precision so that if the number is read
   back in the exact same binary value is recreated.  This is true for IEEE
   floating point by design, and also happens to work for all other modern
   hardware.

   The str() precision is chosen so that in most cases, the rounding noise
   created by various operations is suppressed, while giving plenty of
   precision for practical use.
*/

#define PREC_REPR	17
#define PREC_STR	12

/* elementary operations on complex numbers */

static Py_complex c_1 = {1., 0.};

static inline Py_complex
c_sum(Py_complex a, Py_complex b)
{
	Py_complex r;
	r.real = a.real + b.real;
	r.imag = a.imag + b.imag;
	return r;
}

static inline Py_complex
c_diff(Py_complex a, Py_complex b)
{
	Py_complex r;
	r.real = a.real - b.real;
	r.imag = a.imag - b.imag;
	return r;
}

static inline Py_complex
c_neg(Py_complex a)
{
	Py_complex r;
	r.real = -a.real;
	r.imag = -a.imag;
	return r;
}

static inline Py_complex
c_prod(Py_complex a, Py_complex b)
{
	Py_complex r;
	r.real = a.real*b.real - a.imag*b.imag;
	r.imag = a.real*b.imag + a.imag*b.real;
	return r;
}

static inline Py_complex
c_quot(Py_complex a, Py_complex b)
{
	/******************************************************************
	This was the original algorithm.  It's grossly prone to spurious
	overflow and underflow errors.  It also merrily divides by 0 despite
	checking for that(!).  The code still serves a doc purpose here, as
	the algorithm following is a simple by-cases transformation of this
	one:

	Py_complex r;
	double d = b.real*b.real + b.imag*b.imag;
	if (d == 0.)
		errno = EDOM;
	r.real = (a.real*b.real + a.imag*b.imag)/d;
	r.imag = (a.imag*b.real - a.real*b.imag)/d;
	return r;
	******************************************************************/

	/* This algorithm is better, and is pretty obvious:  first divide the
	 * numerators and denominator by whichever of {b.real, b.imag} has
	 * larger magnitude.  The earliest reference I found was to CACM
	 * Algorithm 116 (Complex Division, Robert L. Smith, Stanford
	 * University).  As usual, though, we're still ignoring all IEEE
	 * endcases.
	 */
	 Py_complex r;	/* the result */
 	 const double abs_breal = b.real < 0 ? -b.real : b.real;
	 const double abs_bimag = b.imag < 0 ? -b.imag : b.imag;

	 if (abs_breal >= abs_bimag) {
 		/* divide tops and bottom by b.real */
	 	if (abs_breal == 0.0) {
	 		errno = EDOM;
	 		r.real = r.imag = 0.0;
	 	}
	 	else {
	 		const double ratio = b.imag / b.real;
	 		const double denom = b.real + b.imag * ratio;
	 		r.real = (a.real + a.imag * ratio) / denom;
	 		r.imag = (a.imag - a.real * ratio) / denom;
	 	}
	}
	else {
		/* divide tops and bottom by b.imag */
		const double ratio = b.real / b.imag;
		const double denom = b.real * ratio + b.imag;
		assert(b.imag != 0.0);
		r.real = (a.real * ratio + a.imag) / denom;
		r.imag = (a.imag * ratio - a.real) / denom;
	}
	return r;
}

static inline Py_complex
c_pow(Py_complex a, Py_complex b)
{
	Py_complex r;
	double vabs,len,at,phase;
	if (b.real == 0. && b.imag == 0.) {
		r.real = 1.;
		r.imag = 0.;
	}
	else if (a.real == 0. && a.imag == 0.) {
		if (b.imag != 0. || b.real < 0.)
			errno = ERANGE;
		r.real = 0.;
		r.imag = 0.;
	}
	else {
		vabs = hypot(a.real,a.imag);
		len = pow(vabs,b.real);
		at = atan2(a.imag, a.real);
		phase = at*b.real;
		if (b.imag != 0.0) {
			len /= exp(at*b.imag);
			phase += b.imag*log(vabs);
		}
		r.real = len*cos(phase);
		r.imag = len*sin(phase);
	}
	return r;
}

static inline Py_complex
c_powu(Py_complex x, long n)
{
	Py_complex r, p;
	long mask = 1;
	r = c_1;
	p = x;
	while (mask > 0 && n >= mask) {
		if (n & mask)
			r = c_prod(r,p);
		mask <<= 1;
		p = c_prod(p,p);
	}
	return r;
}

static Py_complex
c_powi(Py_complex x, long n)
{
	Py_complex cn;

	if (n > 100 || n < -100) {
		cn.real = (double) n;
		cn.imag = 0.;
		return c_pow(x,cn);
	}
	else if (n > 0)
		return c_powu(x,n);
	else
		return c_quot(c_1,c_powu(x,-n));

}

PyObject *
PyComplex_FromCComplex(Py_complex cval)
{
	register PyComplexObject *op;

	/* PyObject_New is inlined */
	op = (PyComplexObject *) PyObject_MALLOC(sizeof(PyComplexObject));
	if (op == NULL)
		return PyErr_NoMemory();
	PyObject_INIT(op, &PyComplex_Type);
	op->cval = cval;
	return (PyObject *) op;
}

PyObject *
PyComplex_FromDoubles(double real, double imag)
{
	Py_complex c;
	c.real = real;
	c.imag = imag;
	return PyComplex_FromCComplex(c);
}

double
PyComplex_RealAsDouble(PyObject *op)
{
	if (PyComplex_Check(op)) {
		return ((PyComplexObject *)op)->cval.real;
	}
	else {
		return PyFloat_AsDouble(op);
	}
}

double
PyComplex_ImagAsDouble(PyObject *op)
{
	if (PyComplex_Check(op)) {
		return ((PyComplexObject *)op)->cval.imag;
	}
	else {
		return 0.0;
	}
}

Py_complex
PyComplex_AsCComplex(PyObject *op)
{
	Py_complex cv;
	if (PyComplex_Check(op)) {
		return ((PyComplexObject *)op)->cval;
	}
	else {
		cv.real = PyFloat_AsDouble(op);
		cv.imag = 0.;
		return cv;
	}
}

static void
complex_dealloc(PyObject *op)
{
	PyObject_DEL(op);
}


static inline void
complex_to_buf(char *buf, PyComplexObject *v, int precision)
{
	if (v->cval.real == 0.)
		sprintf(buf, "%.*gj", precision, v->cval.imag);
	else
		sprintf(buf, "(%.*g%+.*gj)", precision, v->cval.real,
					     precision, v->cval.imag);
}

static int
complex_print(PyComplexObject *v, FILE *fp, int flags)
{
	char buf[100];
	complex_to_buf(buf, v,
		       (flags & Py_PRINT_RAW) ? PREC_STR : PREC_REPR);
	fputs(buf, fp);
	return 0;
}

static PyObject *
complex_repr(PyComplexObject *v)
{
	char buf[100];
	complex_to_buf(buf, v, PREC_REPR);
	return PyString_FromString(buf);
}

static PyObject *
complex_str(PyComplexObject *v)
{
	char buf[100];
	complex_to_buf(buf, v, PREC_STR);
	return PyString_FromString(buf);
}

static long
complex_hash(PyComplexObject *v)
{
	long hashreal, hashimag, combined;
	hashreal = _Py_HashDouble(v->cval.real);
	if (hashreal == -1)
		return -1;
	hashimag = _Py_HashDouble(v->cval.imag);
	if (hashimag == -1)
		return -1;
	/* Note:  if the imaginary part is 0, hashimag is 0 now,
	 * so the following returns hashreal unchanged.  This is
	 * important because numbers of different types that
	 * compare equal must have the same hash value, so that
	 * hash(x + 0*j) must equal hash(x).
	 */
	combined = hashreal + 1000003 * hashimag;
	if (combined == -1)
		combined = -2;
	return combined;
}

static PyObject *
complex_add(PyComplexObject *v, PyComplexObject *w)
{
	Py_complex result;
	PyFPE_START_PROTECT("complex_add", return 0)
	result = c_sum(v->cval,w->cval);
	PyFPE_END_PROTECT(result)
	return PyComplex_FromCComplex(result);
}

static PyObject *
complex_sub(PyComplexObject *v, PyComplexObject *w)
{
	Py_complex result;
	PyFPE_START_PROTECT("complex_sub", return 0)
	result = c_diff(v->cval,w->cval);
	PyFPE_END_PROTECT(result)
	return PyComplex_FromCComplex(result);
}

static PyObject *
complex_mul(PyComplexObject *v, PyComplexObject *w)
{
	Py_complex result;
	PyFPE_START_PROTECT("complex_mul", return 0)
	result = c_prod(v->cval,w->cval);
	PyFPE_END_PROTECT(result)
	return PyComplex_FromCComplex(result);
}

static PyObject *
complex_div(PyComplexObject *v, PyComplexObject *w)
{
	Py_complex quot;
	PyFPE_START_PROTECT("complex_div", return 0)
	errno = 0;
	quot = c_quot(v->cval,w->cval);
	PyFPE_END_PROTECT(quot)
	if (errno == EDOM) {
		PyErr_SetString(PyExc_ZeroDivisionError, "complex division");
		return NULL;
	}
	return PyComplex_FromCComplex(quot);
}

static PyObject *
complex_remainder(PyComplexObject *v, PyComplexObject *w)
{
        Py_complex div, mod;
	errno = 0;
	div = c_quot(v->cval,w->cval); /* The raw divisor value. */
	if (errno == EDOM) {
		PyErr_SetString(PyExc_ZeroDivisionError, "complex remainder");
		return NULL;
	}
	div.real = floor(div.real); /* Use the floor of the real part. */
	div.imag = 0.0;
	mod = c_diff(v->cval, c_prod(w->cval, div));

	return PyComplex_FromCComplex(mod);
}


static PyObject *
complex_divmod(PyComplexObject *v, PyComplexObject *w)
{
        Py_complex div, mod;
	PyObject *d, *m, *z;
	errno = 0;
	div = c_quot(v->cval,w->cval); /* The raw divisor value. */
	if (errno == EDOM) {
		PyErr_SetString(PyExc_ZeroDivisionError, "complex divmod()");
		return NULL;
	}
	div.real = floor(div.real); /* Use the floor of the real part. */
	div.imag = 0.0;
	mod = c_diff(v->cval, c_prod(w->cval, div));
	d = PyComplex_FromCComplex(div);
	m = PyComplex_FromCComplex(mod);
	z = Py_BuildValue("(OO)", d, m);
	Py_XDECREF(d);
	Py_XDECREF(m);
	return z;
}

static PyObject *
complex_pow(PyComplexObject *v, PyObject *w, PyComplexObject *z)
{
	Py_complex p;
	Py_complex exponent;
	long int_exponent;

 	if ((PyObject *)z!=Py_None) {
		PyErr_SetString(PyExc_ValueError, "complex modulo");
		return NULL;
	}
	PyFPE_START_PROTECT("complex_pow", return 0)
	errno = 0;
	exponent = ((PyComplexObject*)w)->cval;
	int_exponent = (long)exponent.real;
	if (exponent.imag == 0. && exponent.real == int_exponent)
		p = c_powi(v->cval,int_exponent);
	else
		p = c_pow(v->cval,exponent);

	PyFPE_END_PROTECT(p)
	if (errno == ERANGE) {
		PyErr_SetString(PyExc_ValueError,
				"0.0 to a negative or complex power");
		return NULL;
	}
	return PyComplex_FromCComplex(p);
}

static PyObject *
complex_neg(PyComplexObject *v)
{
	Py_complex neg;
	neg.real = -v->cval.real;
	neg.imag = -v->cval.imag;
	return PyComplex_FromCComplex(neg);
}

static PyObject *
complex_pos(PyComplexObject *v)
{
	Py_INCREF(v);
	return (PyObject *)v;
}

static PyObject *
complex_abs(PyComplexObject *v)
{
	double result;
	PyFPE_START_PROTECT("complex_abs", return 0)
	result = hypot(v->cval.real,v->cval.imag);
	PyFPE_END_PROTECT(result)
	return PyFloat_FromDouble(result);
}

static int
complex_nonzero(PyComplexObject *v)
{
	return v->cval.real != 0.0 || v->cval.imag != 0.0;
}

static int
complex_coerce(PyObject **pv, PyObject **pw)
{
	Py_complex cval;
	cval.imag = 0.;
	if (PyInt_Check(*pw)) {
		cval.real = (double)PyInt_AsLong(*pw);
		*pw = PyComplex_FromCComplex(cval);
		Py_INCREF(*pv);
		return 0;
	}
	else if (PyLong_Check(*pw)) {
		cval.real = PyLong_AsDouble(*pw);
		*pw = PyComplex_FromCComplex(cval);
		Py_INCREF(*pv);
		return 0;
	}
	else if (PyFloat_Check(*pw)) {
		cval.real = PyFloat_AsDouble(*pw);
		*pw = PyComplex_FromCComplex(cval);
		Py_INCREF(*pv);
		return 0;
	}
	return 1; /* Can't do it */
}

static PyObject *
complex_richcompare(PyObject *v, PyObject *w, int op)
{
	int c;
	Py_complex i, j;
	PyObject *res;

	if (op != Py_EQ && op != Py_NE) {
		PyErr_SetString(PyExc_TypeError,
			"cannot compare complex numbers using <, <=, >, >=");
		return NULL;
	}

	c = PyNumber_CoerceEx(&v, &w);
	if (c < 0)
		return NULL;
	if (c > 0) {
		Py_INCREF(Py_NotImplemented);
		return Py_NotImplemented;
	}
	if (!PyComplex_Check(v) || !PyComplex_Check(w)) {
		Py_DECREF(v);
		Py_DECREF(w);
		Py_INCREF(Py_NotImplemented);
		return Py_NotImplemented;
	}

	i = ((PyComplexObject *)v)->cval;
	j = ((PyComplexObject *)w)->cval;
	Py_DECREF(v);
	Py_DECREF(w);

	if ((i.real == j.real && i.imag == j.imag) == (op == Py_EQ))
		res = Py_True;
	else
		res = Py_False;

	Py_INCREF(res);
	return res;
}

static PyObject *
complex_int(PyObject *v)
{
	PyErr_SetString(PyExc_TypeError,
		   "can't convert complex to int; use e.g. int(abs(z))");
	return NULL;
}

static PyObject *
complex_long(PyObject *v)
{
	PyErr_SetString(PyExc_TypeError,
		   "can't convert complex to long; use e.g. long(abs(z))");
	return NULL;
}

static PyObject *
complex_float(PyObject *v)
{
	PyErr_SetString(PyExc_TypeError,
		   "can't convert complex to float; use e.g. abs(z)");
	return NULL;
}

static PyObject *
complex_conjugate(PyObject *self, PyObject *args)
{
	Py_complex c;
	if (!PyArg_ParseTuple(args, ":conjugate"))
		return NULL;
	c = ((PyComplexObject *)self)->cval;
	c.imag = -c.imag;
	return PyComplex_FromCComplex(c);
}

static PyMethodDef complex_methods[] = {
	{"conjugate",	complex_conjugate,	1},
	{NULL,		NULL}		/* sentinel */
};


static PyObject *
complex_getattr(PyComplexObject *self, char *name)
{
	if (strcmp(name, "real") == 0)
		return (PyObject *)PyFloat_FromDouble(self->cval.real);
	else if (strcmp(name, "imag") == 0)
		return (PyObject *)PyFloat_FromDouble(self->cval.imag);
	else if (strcmp(name, "__members__") == 0)
		return Py_BuildValue("[ss]", "imag", "real");
	return Py_FindMethod(complex_methods, (PyObject *)self, name);
}

static PyNumberMethods complex_as_number = {
	(binaryfunc)complex_add, 		/* nb_add */
	(binaryfunc)complex_sub, 		/* nb_subtract */
	(binaryfunc)complex_mul, 		/* nb_multiply */
	(binaryfunc)complex_div, 		/* nb_divide */
	(binaryfunc)complex_remainder,		/* nb_remainder */
	(binaryfunc)complex_divmod,		/* nb_divmod */
	(ternaryfunc)complex_pow,		/* nb_power */
	(unaryfunc)complex_neg,			/* nb_negative */
	(unaryfunc)complex_pos,			/* nb_positive */
	(unaryfunc)complex_abs,			/* nb_absolute */
	(inquiry)complex_nonzero,		/* nb_nonzero */
	0,					/* nb_invert */
	0,					/* nb_lshift */
	0,					/* nb_rshift */
	0,					/* nb_and */
	0,					/* nb_xor */
	0,					/* nb_or */
	(coercion)complex_coerce,		/* nb_coerce */
	(unaryfunc)complex_int,			/* nb_int */
	(unaryfunc)complex_long,		/* nb_long */
	(unaryfunc)complex_float,		/* nb_float */
	0,					/* nb_oct */
	0,					/* nb_hex */
};

PyTypeObject PyComplex_Type = {
	PyObject_HEAD_INIT(&PyType_Type)
	0,
	"complex",
	sizeof(PyComplexObject),
	0,
	(destructor)complex_dealloc,		/* tp_dealloc */
	(printfunc)complex_print,		/* tp_print */
	(getattrfunc)complex_getattr,		/* tp_getattr */
	0,					/* tp_setattr */
	0,					/* tp_compare */
	(reprfunc)complex_repr,			/* tp_repr */
	&complex_as_number,    			/* tp_as_number */
	0,					/* tp_as_sequence */
	0,					/* tp_as_mapping */
	(hashfunc)complex_hash, 		/* tp_hash */
	0,					/* tp_call */
	(reprfunc)complex_str,			/* tp_str */
	0,					/* tp_getattro */
	0,					/* tp_setattro */
	0,					/* tp_as_buffer */
	Py_TPFLAGS_DEFAULT,			/* tp_flags */
	0,					/* tp_doc */
	0,					/* tp_traverse */
	0,					/* tp_clear */
	complex_richcompare,			/* tp_richcompare */
};

#endif
