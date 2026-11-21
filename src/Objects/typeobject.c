
/* Type object implementation */

/* Adapted from CPython 2.1; see reference/cpython-2.1/LICENSE.
 * GSQE78 .text 0x80164EF8..0x80165010. */
#include "object.h"

typedef PyObject *(*getattrfunc)(PyTypeObject *, char *);
typedef PyObject *(*reprfunc)(PyTypeObject *);
struct _typeobject {
    PyObject_VAR_HEAD
    char *tp_name;
    int tp_basicsize, tp_itemsize;
    void *tp_dealloc, *tp_print;
    getattrfunc tp_getattr;
    void *tp_setattr, *tp_compare;
    reprfunc tp_repr;
    void *tp_as_number, *tp_as_sequence, *tp_as_mapping;
    void *tp_hash, *tp_call, *tp_str, *tp_getattro, *tp_setattro, *tp_as_buffer;
    long tp_flags;
    char *tp_doc;
    void *tp_traverse, *tp_clear, *tp_richcompare;
    long tp_weaklistoffset;
};
#define PyObject_HEAD_INIT(type) 1, type,
#define Py_None (&_Py_NoneStruct)
extern PyTypeObject PyType_Type;
extern PyObject _Py_NoneStruct;
extern PyObject *PyExc_AttributeError;
extern int strcmp(const char *, const char *);
extern int sprintf(char *, const char *, ...);
extern PyObject *PyString_FromString(const char *);
extern PyObject *Py_BuildValue(const char *, ...);
extern void PyErr_SetString(PyObject *, const char *);


/* Type object implementation */

static PyObject *
type_getattr(PyTypeObject *t, char *name)
{
	if (strcmp(name, "__name__") == 0)
		return PyString_FromString(t->tp_name);
	if (strcmp(name, "__doc__") == 0) {
		char *doc = t->tp_doc;
		if (doc != NULL)
			return PyString_FromString(doc);
		Py_INCREF(Py_None);
		return Py_None;
	}
	if (strcmp(name, "__members__") == 0)
		return Py_BuildValue("[ss]", "__doc__", "__name__");
	PyErr_SetString(PyExc_AttributeError, name);
	return NULL;
}

static PyObject *
type_repr(PyTypeObject *v)
{
	char buf[100];
	sprintf(buf, "<type '%.80s'>", v->tp_name);
	return PyString_FromString(buf);
}

PyTypeObject PyType_Type = {
	PyObject_HEAD_INIT(&PyType_Type)
	0,			/* Number of items for varobject */
	"type",			/* Name of this type */
	sizeof(PyTypeObject),	/* Basic object size */
	0,			/* Item size for varobject */
	0,			/*tp_dealloc*/
	0,			/*tp_print*/
	(getattrfunc)type_getattr, /*tp_getattr*/
	0,			/*tp_setattr*/
	0,			/*tp_compare*/
	(reprfunc)type_repr,	/*tp_repr*/
	0,			/*tp_as_number*/
	0,			/*tp_as_sequence*/
	0,			/*tp_as_mapping*/
	0,			/*tp_hash*/
	0,			/*tp_call*/
	0,			/*tp_str*/
	0,			/*tp_xxx1*/
	0,			/*tp_xxx2*/
	0,			/*tp_xxx3*/
	0,			/*tp_xxx4*/
	"Define the behavior of a particular type of object.",
};
