/*
Written by Jim Hugunin and Chris Chase.

This includes both the singular ellipsis object and slice objects.

Guido, feel free to do whatever you want in the way of copyrights
for this file.
*/

/* 
Py_Ellipsis encodes the '...' rubber index token. It is similar to
the Py_NoneStruct in that there is no way to create other objects of
this type and there is exactly one in existence.
*/

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
extern PyTypeObject PyRange_Type, PyType_Type;
extern PyObject *PyExc_OverflowError, *PyExc_IndexError, *PyExc_TypeError;
extern PyObject *PyInt_FromLong(long);
extern long PyInt_AsLong(PyObject *), PyInt_GetMax(void);
extern PyObject *PyNumber_Multiply(PyObject *, PyObject *);
extern void PyErr_SetString(PyObject *, const char *), PyErr_Clear(void);
extern int PyErr_ExceptionMatches(PyObject *);
extern PyObject *PyErr_NoMemory(void), *PyErr_Occurred(void);
extern PyObject *PyList_New(int);
extern int PyList_SetItem(PyObject *, int, PyObject *);
extern int PyArg_ParseTuple(PyObject *, const char *, ...);
extern PyObject *Py_FindMethod(PyMethodDef *, PyObject *, char *);
extern PyObject *PyMember_Get(char *, struct memberlist *, char *);
extern PyObject *PyString_FromString(const char *);
extern int sprintf(char *, const char *, ...), strcmp(const char *, const char *);
extern void *malloc(unsigned int);
extern void free(void *);
extern PyObject *PyObject_Init(PyObject *, PyTypeObject *);



extern PyTypeObject PySlice_Type, PyInt_Type;
extern PyObject _Py_NoneStruct;
#define Py_None (&_Py_NoneStruct)
#define PyInt_Check(o) ((o)->ob_type == &PyInt_Type)
typedef struct { PyObject_HEAD PyObject *start, *stop, *step; } PySliceObject;
extern void PyString_Concat(PyObject **, PyObject *);
extern void PyString_ConcatAndDel(PyObject **, PyObject *);
extern PyObject *PyObject_Repr(PyObject *);
extern PyObject *Py_BuildValue(const char *, ...);
extern int PyObject_Cmp(PyObject *, PyObject *, int *);
extern PyObject *PyExc_AttributeError;


static PyObject *
ellipsis_repr(PyObject *op)
{
	return PyString_FromString("Ellipsis");
}

static PyTypeObject PyEllipsis_Type = {
	PyObject_HEAD_INIT(&PyType_Type)
	0,
	"ellipsis",
	0,
	0,
	0,		/*tp_dealloc*/ /*never called*/
	0,		/*tp_print*/
	0,		/*tp_getattr*/
	0,		/*tp_setattr*/
	0,		/*tp_compare*/
	(reprfunc)ellipsis_repr, /*tp_repr*/
	0,		/*tp_as_number*/
	0,		/*tp_as_sequence*/
	0,		/*tp_as_mapping*/
	0,		/*tp_hash */
};

PyObject _Py_EllipsisObject = {
	PyObject_HEAD_INIT(&PyEllipsis_Type)
};


/* Slice object implementation

   start, stop, and step are python objects with None indicating no
   index is present.
*/

PyObject *
PySlice_New(PyObject *start, PyObject *stop, PyObject *step)
{
	PySliceObject *obj = PyObject_NEW(PySliceObject, &PySlice_Type);

	if (obj == NULL)
		return NULL;

	if (step == NULL) step = Py_None;
	Py_INCREF(step);
	if (start == NULL) start = Py_None;
	Py_INCREF(start);
	if (stop == NULL) stop = Py_None;
	Py_INCREF(stop);

	obj->step = step;
	obj->start = start;
	obj->stop = stop;

	return (PyObject *) obj;
}

static void
slice_dealloc(PySliceObject *r)
{
	Py_DECREF(r->step);
	Py_DECREF(r->start);
	Py_DECREF(r->stop);
	PyObject_DEL(r);
}

static PyObject *
slice_repr(PySliceObject *r)
{
	PyObject *s, *comma;

	s = PyString_FromString("slice(");
	comma = PyString_FromString(", ");
	PyString_ConcatAndDel(&s, PyObject_Repr(r->start));
	PyString_Concat(&s, comma);
	PyString_ConcatAndDel(&s, PyObject_Repr(r->stop));
	PyString_Concat(&s, comma);
	PyString_ConcatAndDel(&s, PyObject_Repr(r->step));
	PyString_ConcatAndDel(&s, PyString_FromString(")"));
	Py_DECREF(comma);
	return s;
}


static PyObject *slice_getattr(PySliceObject *self, char *name)
{
	PyObject *ret;
  
	ret = NULL;
	if (strcmp(name, "start") == 0) {
		ret = self->start;
	}
	else if (strcmp(name, "stop") == 0) {
		ret = self->stop;
	}
	else if (strcmp(name, "step") == 0) {
		ret = self->step;
	}
	else if (strcmp(name, "__members__") == 0) {
		return Py_BuildValue("[sss]",
				     "start", "stop", "step");
	}
	else {
		PyErr_SetString(PyExc_AttributeError, name);
		return NULL;
	}
	Py_INCREF(ret);
	return ret;
}

static int
slice_compare(PySliceObject *v, PySliceObject *w)
{
	int result = 0;

        if (v == w)
		return 0;

	if (PyObject_Cmp(v->start, w->start, &result) < 0)
	    return -2;
	if (result != 0)
		return result;
	if (PyObject_Cmp(v->stop, w->stop, &result) < 0)
	    return -2;
	if (result != 0)
		return result;
	if (PyObject_Cmp(v->step, w->step, &result) < 0)
	    return -2;
	return result;
}

PyTypeObject PySlice_Type = {
	PyObject_HEAD_INIT(&PyType_Type)
	0,			/* Number of items for varobject */
	"slice",		/* Name of this type */
	sizeof(PySliceObject),	/* Basic object size */
	0,			/* Item size for varobject */
	(destructor)slice_dealloc, /*tp_dealloc*/
	0,			/*tp_print*/
	(getattrfunc)slice_getattr, /*tp_getattr*/
	0,			/*tp_setattr*/
	(cmpfunc)slice_compare, /*tp_compare*/
	(reprfunc)slice_repr,   /*tp_repr*/
	0,			/*tp_as_number*/
	0,	    		/*tp_as_sequence*/
	0,			/*tp_as_mapping*/
};
