#ifndef PY_OBJECT_H
#define PY_OBJECT_H

/* Minimal historical CPython object header. Complete matched units establish
 * the CPython 2.1 lineage; these three leading offsets are shared with older
 * releases: ob_refcnt=0, ob_type=4, and ob_size=8. */

typedef struct _object PyObject;
typedef struct _typeobject PyTypeObject;

#define PyObject_HEAD              \
    int ob_refcnt;                 \
    PyTypeObject *ob_type;

#define PyObject_VAR_HEAD          \
    PyObject_HEAD                  \
    int ob_size;

struct _object {
    PyObject_HEAD
};

typedef struct {
    PyObject_VAR_HEAD
} PyVarObject;

#define Py_INCREF(op) ((op)->ob_refcnt++)

#ifndef NULL
#define NULL 0
#endif
#define Py_DECREF(op)                       \
    if (--(op)->ob_refcnt != 0)             \
        ;                                   \
    else                                    \
        /* _Py_Dealloc((PyObject *)(op)) */

#endif /* PY_OBJECT_H */
