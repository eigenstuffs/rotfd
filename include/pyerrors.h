#ifndef PY_PYERRORS_H
#define PY_PYERRORS_H

#include "object.h"

extern PyObject *PyExc_IndexError;
void PyErr_SetString(PyObject *exception, const char *string);

#endif /* PY_PYERRORS_H */
