/* Python integer-object input; see docs/notes/game-python-long-inputs.md. */
#include "Game/python_scalar_bindings.h"
extern "C" long PyInt_AsLong(FactoryPyObject*);
extern "C" FactoryPyObject* PyFloat_FromDouble(double);
extern "C" const char lbl_802A5BB4[];
extern "C" float fn_8025E268(void*, long);
extern "C" FactoryPyObject* fn_800DFE5C(FactoryPyObject*, FactoryPyObject* args) {
    void* self;
    FactoryPyObject* parsed = 0;
    FactoryPyObject* number = 0;
    if (!PyArg_ParseTuple(args, lbl_802A5BB4, &parsed, &number)) return 0;
    if (fn_800CD864(parsed, &self, lbl_80318988[0x50 / 4], 1) == -1) return 0;
    long value = PyInt_AsLong(number);
    return PyFloat_FromDouble(fn_8025E268(self, value));
}
