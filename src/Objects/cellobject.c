/* Adapted from CPython v2.1 Objects/cellobject.c.
 * License: reference/cpython-2.1/LICENSE. */
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
typedef struct { PyObject_VAR_HEAD PyObject *ob_ref; } PyCellObject;
typedef int (*visitproc)(PyObject *, void *);
typedef int (*traverseproc)(PyObject *, visitproc, void *);
#define PyCell_Check(op) ((op)->ob_type == &PyCell_Type)
#define PyCell_GET(op) (((PyCellObject *)(op))->ob_ref)
#define PyCell_SET(op, v) (((PyCellObject *)(op))->ob_ref = v)
#define Py_XINCREF(op) if ((op) == NULL) ; else Py_INCREF(op)
#define Py_XDECREF(op) if ((op) == NULL) ; else Py_DECREF(op)
#define PyObject_New(type, tp) ((type *)_PyObject_New(tp))
#define PyObject_Del(op) _PyObject_Del((PyObject *)(op))
#define PyObject_GC_Init(op)
#define PyObject_GC_Fini(op)
#define PyGC_HEAD_SIZE 0
#define Py_TPFLAGS_GC 0
#define PyErr_BadInternalCall() _PyErr_BadInternalCall(__FILE__, __LINE__)
extern PyTypeObject PyCell_Type, PyType_Type;
extern PyObject *_PyObject_New(PyTypeObject *);
extern void _PyObject_Del(PyObject *);
extern int PyObject_Compare(PyObject *, PyObject *);
extern PyObject *PyString_FromString(const char *);
extern int sprintf(char *, const char *, ...);
extern void _PyErr_BadInternalCall(const char *, int);

#line 1 "cellobject.c"
/* Cell object implementation */

/* Python ABI declarations are supplied above. */

PyObject *
PyCell_New(PyObject *obj)
{
	PyCellObject *op;

	op = (PyCellObject *)PyObject_New(PyCellObject, &PyCell_Type);
	op->ob_ref = obj;
	Py_XINCREF(obj);

	PyObject_GC_Init(op);
	return (PyObject *)op;
}

PyObject *
PyCell_Get(PyObject *op)
{
	if (!PyCell_Check(op)) {
		PyErr_BadInternalCall();
		return NULL;
	}
	Py_XINCREF(((PyCellObject*)op)->ob_ref);
	return PyCell_GET(op);
}

int
PyCell_Set(PyObject *op, PyObject *obj)
{
	if (!PyCell_Check(op)) {
		PyErr_BadInternalCall();
		return -1;
	}
	Py_XDECREF(((PyCellObject*)op)->ob_ref);
	Py_XINCREF(obj);
	PyCell_SET(op, obj);
	return 0;
}

static void
cell_dealloc(PyCellObject *op)
{
	PyObject_GC_Fini(op);
	Py_XDECREF(op->ob_ref);
	PyObject_Del(op);
}

static int
cell_compare(PyCellObject *a, PyCellObject *b)
{
	if (a->ob_ref == NULL) {
		if (b->ob_ref == NULL)
			return 0;
		return -1;
	} else if (b->ob_ref == NULL)
		return 1;
	return PyObject_Compare(a->ob_ref, b->ob_ref);
}

static PyObject *
cell_repr(PyCellObject *op)
{
	char buf[256];

	if (op->ob_ref == NULL)
		sprintf(buf, "<cell at %p: empty>", op);
	else
		sprintf(buf, "<cell at %p: %.80s object at %p>",
			op, op->ob_ref->ob_type->tp_name, op->ob_ref);
	return PyString_FromString(buf);
}

static int
cell_traverse(PyCellObject *op, visitproc visit, void *arg)
{
	if (op->ob_ref)
		return visit(op->ob_ref, arg);
	return 0;
}

static int
cell_clear(PyCellObject *op)
{
	Py_XDECREF(op->ob_ref);
	op->ob_ref = NULL;
	return 0;
}

PyTypeObject PyCell_Type = {
	PyObject_HEAD_INIT(&PyType_Type)
	0,
	"cell",
	sizeof(PyCellObject) + PyGC_HEAD_SIZE,
	0,
	(destructor)cell_dealloc,               /* tp_dealloc */
	0,                                      /* tp_print */
	0,	                                /* tp_getattr */
	0,					/* tp_setattr */
	(cmpfunc)cell_compare,			/* tp_compare */
	(reprfunc)cell_repr,			/* tp_repr */
	0,					/* tp_as_number */
	0,			                /* tp_as_sequence */
	0,					/* tp_as_mapping */
	0,					/* tp_hash */
	0,					/* tp_call */
	0,					/* tp_str */
	0,					/* tp_getattro */
	0,					/* tp_setattro */
	0,					/* tp_as_buffer */
	Py_TPFLAGS_DEFAULT | Py_TPFLAGS_GC,	/* tp_flags */
 	0,					/* tp_doc */
 	(traverseproc)cell_traverse,		/* tp_traverse */
 	(inquiry)cell_clear,			/* tp_clear */
};
