#include "Game/python_scalar_bindings.h"
extern "C" long PyInt_AsLong(FactoryPyObject*);
extern "C" const char lbl_802A3F78[];
extern "C" void fn_8006AE5C(void*, void*, float, float);

extern "C" FactoryPyObject* fn_800D4D9C(FactoryPyObject*, FactoryPyObject* args) {
    void* native0;
    void* native1;
    float arg2;
    float arg3;
    FactoryPyObject* arg0 = 0;
    FactoryPyObject* arg1 = 0;
    if (!PyArg_ParseTuple(args, lbl_802A3F78, &arg0, &arg1, &arg2, &arg3)) return 0;
    if (fn_800CD864(arg0, (void**)&native0, lbl_80318988[0x84 / 4], 1) == -1) return 0;
    if (fn_800CD864(arg1, (void**)&native1, lbl_80318988[0x28 / 4], 1) == -1) return 0;
    fn_8006AE5C(native0, native1, arg2, arg3);
    ++_Py_NoneStruct.references;
    return &_Py_NoneStruct;
}
