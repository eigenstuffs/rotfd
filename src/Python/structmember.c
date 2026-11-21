/* Adapted from CPython v2.1 Python/structmember.c; see reference/cpython-2.1/LICENSE. */
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

#define Py_XINCREF(op) if ((op) == NULL) ; else Py_INCREF(op)
#define Py_XDECREF(op) if ((op) == NULL) ; else Py_DECREF(op)
#define PyInt_Check(o) ((o)->ob_type == &PyInt_Type)
#define PyLong_Check(o) ((o)->ob_type == &PyLong_Type)
#define PyFloat_Check(o) ((o)->ob_type == &PyFloat_Type)
#define PyString_Check(o) ((o)->ob_type == &PyString_Type)
#define Py_None (&_Py_NoneStruct)
extern PyTypeObject PyInt_Type, PyLong_Type, PyFloat_Type, PyString_Type;
extern PyObject _Py_NoneStruct;
extern PyObject *PyExc_TypeError, *PyExc_SystemError, *PyExc_AttributeError;
extern PyObject *PyList_New(int), *PyString_FromString(const char *);
extern int PyList_SetItem(PyObject *, int, PyObject *), PyList_Sort(PyObject *);
extern PyObject *PyErr_Occurred(void);
extern int strcmp(const char *, const char *);
extern PyObject *PyInt_FromLong(long), *PyLong_FromDouble(double), *PyFloat_FromDouble(double);
extern PyObject *PyString_FromStringAndSize(const char *, int);
extern void PyErr_SetString(PyObject *, const char *);
extern int PyErr_BadArgument(void);
extern long PyInt_AsLong(PyObject *), PyLong_AsLong(PyObject *);
extern double PyFloat_AsDouble(PyObject *);
extern int PyString_Size(PyObject *);
extern char *PyString_AsString(PyObject *);

/* Types */
#define T_SHORT		0
#define T_INT		1

#define T_FLOAT		3
#define T_DOUBLE	4
#define T_STRING	5
#define T_OBJECT	6
/* XXX the ordering here is weird for binary compatibility */
#define T_CHAR		7	/* 1-character string */
#define T_BYTE		8	/* 8-bit signed int */
/* unsigned variants: */
#define T_UBYTE		9
#define T_USHORT	10
#define T_UINT		11
#define T_ULONG		12

/* Added by Jack: strings contained in the structure */
#define T_STRING_INPLACE	13
#ifdef macintosh
#define T_PSTRING	14	/* macintosh pascal-style counted string */
#define T_PSTRING_INPLACE	15
#endif /* macintosh */



/* Map C struct members to Python object attributes */





static inline PyObject *
listmembers(struct memberlist *mlist)
{
	int i, n;
	PyObject *v;
	for (n = 0; mlist[n].name != NULL; n++)
		;
	v = PyList_New(n);
	if (v != NULL) {
		for (i = 0; i < n; i++)
			PyList_SetItem(v, i,
				       PyString_FromString(mlist[i].name));
		if (PyErr_Occurred()) {
			Py_DECREF(v);
			v = NULL;
		}
		else {
			PyList_Sort(v);
		}
	}
	return v;
}

PyObject *
PyMember_Get(char *addr, struct memberlist *mlist, char *name)
{
	struct memberlist *l;
	
	if (strcmp(name, "__members__") == 0)
		return listmembers(mlist);
	for (l = mlist; l->name != NULL; l++) {
		if (strcmp(l->name, name) == 0) {
			PyObject *v;
			addr += l->offset;
			switch (l->type) {
			case T_BYTE:
				v = PyInt_FromLong((long)
						 (((*(char*)addr & 0xff)
						   ^ 0x80) - 0x80));
				break;
			case T_UBYTE:
				v = PyInt_FromLong((long) *(char*)addr & 0xff);
				break;
			case T_SHORT:
				v = PyInt_FromLong((long) *(short*)addr);
				break;
			case T_USHORT:
				v = PyInt_FromLong((long)
						 *(unsigned short*)addr);
				break;
			case T_INT:
				v = PyInt_FromLong((long) *(int*)addr);
				break;
			case T_UINT:
				v = PyInt_FromLong((long)
						   *(unsigned int*)addr);
				break;
			case T_LONG:
				v = PyInt_FromLong(*(long*)addr);
				break;
			case T_ULONG:
				v = PyLong_FromDouble((double)
						   *(unsigned long*)addr);
				break;
			case T_FLOAT:
				v = PyFloat_FromDouble((double)*(float*)addr);
				break;
			case T_DOUBLE:
				v = PyFloat_FromDouble(*(double*)addr);
				break;
			case T_STRING:
				if (*(char**)addr == NULL) {
					Py_INCREF(Py_None);
					v = Py_None;
				}
				else
					v = PyString_FromString(*(char**)addr);
				break;
			case T_STRING_INPLACE:
				v = PyString_FromString((char*)addr);
				break;
#ifdef macintosh
			case T_PSTRING:
				if (*(char**)addr == NULL) {
					Py_INCREF(Py_None);
					v = Py_None;
				}
				else
					v = PyString_FromStringAndSize(
						(*(char**)addr)+1,
						**(unsigned char**)addr);
				break;
			case T_PSTRING_INPLACE:
				v = PyString_FromStringAndSize(
					((char*)addr)+1,
					*(unsigned char*)addr);
				break;
#endif /* macintosh */
			case T_CHAR:
				v = PyString_FromStringAndSize((char*)addr, 1);
				break;
			case T_OBJECT:
				v = *(PyObject **)addr;
				if (v == NULL)
					v = Py_None;
				Py_INCREF(v);
				break;
			default:
				PyErr_SetString(PyExc_SystemError,
						"bad memberlist type");
				v = NULL;
			}
			return v;
		}
	}
	
	PyErr_SetString(PyExc_AttributeError, name);
	return NULL;
}

int
PyMember_Set(char *addr, struct memberlist *mlist, char *name, PyObject *v)
{
	struct memberlist *l;
	PyObject *oldv;
	
	for (l = mlist; l->name != NULL; l++) {
		if (strcmp(l->name, name) == 0) {
#ifdef macintosh
			if (l->readonly || l->type == T_STRING ||
			    l->type == T_PSTRING)
			{
#else
			if (l->readonly || l->type == T_STRING ) {
#endif /* macintosh */
				PyErr_SetString(PyExc_TypeError,
						"readonly attribute");
				return -1;
			}
			if (v == NULL && l->type != T_OBJECT) {
				PyErr_SetString(PyExc_TypeError,
				  "can't delete numeric/char attribute");
				return -1;
			}
			addr += l->offset;
			switch (l->type) {
			case T_BYTE:
			case T_UBYTE:
				if (!PyInt_Check(v)) {
					PyErr_BadArgument();
					return -1;
				}
				*(char*)addr = (char) PyInt_AsLong(v);
				break;
			case T_SHORT:
			case T_USHORT:
				if (!PyInt_Check(v)) {
					PyErr_BadArgument();
					return -1;
				}
				*(short*)addr = (short) PyInt_AsLong(v);
				break;
			case T_UINT:
			case T_INT:
				if (!PyInt_Check(v)) {
					PyErr_BadArgument();
					return -1;
				}
				*(int*)addr = (int) PyInt_AsLong(v);
				break;
			case T_LONG:
				if (!PyInt_Check(v)) {
					PyErr_BadArgument();
					return -1;
				}
				*(long*)addr = PyInt_AsLong(v);
				break;
			case T_ULONG:
				if (PyInt_Check(v))
					*(long*)addr = PyInt_AsLong(v);
				else if (PyLong_Check(v))
					*(long*)addr = PyLong_AsLong(v);
				else {
					PyErr_BadArgument();
					return -1;
				}
				break;
			case T_FLOAT:
				if (PyInt_Check(v))
					*(float*)addr =
						(float) PyInt_AsLong(v);
				else if (PyFloat_Check(v))
					*(float*)addr =
						(float) PyFloat_AsDouble(v);
				else {
					PyErr_BadArgument();
					return -1;
				}
				break;
			case T_DOUBLE:
				if (PyInt_Check(v))
					*(double*)addr =
						(double) PyInt_AsLong(v);
				else if (PyFloat_Check(v))
					*(double*)addr = PyFloat_AsDouble(v);
				else {
					PyErr_BadArgument();
					return -1;
				}
				break;
			case T_OBJECT:
				Py_XINCREF(v);
				oldv = *(PyObject **)addr;
				*(PyObject **)addr = v;
				Py_XDECREF(oldv);
				break;
			case T_CHAR:
				if (PyString_Check(v) &&
				    PyString_Size(v) == 1) {
					*(char*)addr =
						PyString_AsString(v)[0];
				}
				else {
					PyErr_BadArgument();
					return -1;
				}
				break;
			default:
				PyErr_SetString(PyExc_SystemError,
						"bad memberlist type");
				return -1;
			}
			return 0;
		}
	}
	
	PyErr_SetString(PyExc_AttributeError, name);
	return -1;
}
