/* Python integer-object input; see docs/notes/game-python-long-inputs.md. */
#include "Game/python_scalar_bindings.h"
extern "C" long PyInt_AsLong(FactoryPyObject*);
extern "C" FactoryPyObject* PyFloat_FromDouble(double);
extern "C" const char lbl_802A49C4[];
extern "C" void fn_8006EEB8(void*, signed char);
extern "C" FactoryPyObject* fn_800D7E50(FactoryPyObject*, FactoryPyObject* args) {
    void* self;
    FactoryPyObject* parsed = 0;
    FactoryPyObject* number = 0;
    if (!PyArg_ParseTuple(args, lbl_802A49C4, &parsed, &number)) return 0;
    if (fn_800CD864(parsed, &self, lbl_80318988[0x84 / 4], 1) == -1) return 0;
    signed char value = PyInt_AsLong(number);
    fn_8006EEB8(self, value);
    ++_Py_NoneStruct.references;
    return &_Py_NoneStruct;
}
