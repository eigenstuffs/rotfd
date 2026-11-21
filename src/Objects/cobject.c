/* Adapted from CPython v2.1 Objects/cobject.c; see reference/cpython-2.1/LICENSE. */

/* Wrap void* pointers to be passed between C modules */

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
typedef int (*printfunc)(PyObject *, void *, int);
typedef long (*hashfunc)(PyObject *);
typedef PyObject *(*ternaryfunc)(PyObject *, PyObject *, PyObject *);
extern PyTypeObject PyCObject_Type, PyType_Type;
extern PyObject *PyExc_TypeError;
extern void PyErr_SetString(PyObject *, const char *);
extern PyObject *PyErr_Occurred(void);
extern void free(void *);



/* Declarations for objects of type PyCObject */

typedef void (*destructor1)(void *);
typedef void (*destructor2)(void *, void*);

typedef struct {
    PyObject_HEAD
    void *cobject;
    void *desc;
    void (*destructor)(void *);
} PyCObject;

void *
PyCObject_AsVoidPtr(PyObject *self)
{
    if (self) {
        if (self->ob_type == &PyCObject_Type)
            return ((PyCObject *)self)->cobject;
        PyErr_SetString(PyExc_TypeError,
                        "PyCObject_AsVoidPtr with non-C-object");
    }
    if (!PyErr_Occurred())
        PyErr_SetString(PyExc_TypeError,
                        "PyCObject_AsVoidPtr called with null pointer");
    return NULL;
}

static void
PyCObject_dealloc(PyCObject *self)
{
    if (self->destructor) {
        if(self->desc)
            ((destructor2)(self->destructor))(self->cobject, self->desc);
        else
            (self->destructor)(self->cobject);
    }
    PyObject_DEL(self);
}


static char PyCObject_Type__doc__[] = 
"C objects to be exported from one extension module to another\n\
\n\
C objects are used for communication between extension modules.  They\n\
provide a way for an extension module to export a C interface to other\n\
extension modules, so that extension modules can use the Python import\n\
mechanism to link to one another.";

PyTypeObject PyCObject_Type = {
    PyObject_HEAD_INIT(&PyType_Type)
    0,					/*ob_size*/
    "PyCObject",			/*tp_name*/
    sizeof(PyCObject),			/*tp_basicsize*/
    0,					/*tp_itemsize*/
    /* methods */
    (destructor)PyCObject_dealloc,	/*tp_dealloc*/
    (printfunc)0,			/*tp_print*/
    (getattrfunc)0,			/*tp_getattr*/
    (setattrfunc)0,			/*tp_setattr*/
    (cmpfunc)0,				/*tp_compare*/
    (reprfunc)0,			/*tp_repr*/
    0,					/*tp_as_number*/
    0,					/*tp_as_sequence*/
    0,					/*tp_as_mapping*/
    (hashfunc)0,			/*tp_hash*/
    (ternaryfunc)0,			/*tp_call*/
    (reprfunc)0,			/*tp_str*/

    /* Space for future expansion */
    0L,0L,0L,0L,
    PyCObject_Type__doc__ 		/* Documentation string */
};
