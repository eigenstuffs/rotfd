#ifndef PY_TUPLEOBJECT_H
#define PY_TUPLEOBJECT_H

#include "object.h"

typedef struct {
    PyObject_VAR_HEAD
    PyObject *ob_item[1];
} PyTupleObject;

#endif /* PY_TUPLEOBJECT_H */
