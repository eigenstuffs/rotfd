#include "Game/python_scalar_bindings.h"
extern "C" long PyInt_AsLong(FactoryPyObject*);
extern "C" const char lbl_802A49F0[];

extern "C" FactoryPyObject* fn_800D7EF8(FactoryPyObject*, FactoryPyObject* args) {
    void* self;
    FactoryPyObject* parsed = 0;

    if (!PyArg_ParseTuple(args, lbl_802A49F0, &parsed)) return 0;
    if (fn_800CD864(parsed, (void**)&self, lbl_80318988[0xDC / 4], 1) == -1) return 0;
    ++_Py_NoneStruct.references;
    return &_Py_NoneStruct;
}
