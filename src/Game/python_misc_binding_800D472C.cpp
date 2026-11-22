#include "Game/python_scalar_bindings.h"
extern "C" long PyInt_AsLong(FactoryPyObject*);
extern "C" const char lbl_802A3E14[];
extern "C" void fn_80069520(void*, signed char, short);
extern "C" FactoryPyObject* fn_800D472C(FactoryPyObject*, FactoryPyObject* args) {
    void* self;
    FactoryPyObject* parsed = 0;
    FactoryPyObject* number = 0;
    short option;
    if (!PyArg_ParseTuple(args, lbl_802A3E14, &parsed, &number, &option)) return 0;
    if (fn_800CD864(parsed, (void**)&self, lbl_80318988[0x84 / 4], 1) == -1) return 0;
    signed char value = PyInt_AsLong(number);
    fn_80069520(self, value, option);
    ++_Py_NoneStruct.references;
    return &_Py_NoneStruct;
}
