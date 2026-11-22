#include "Game/python_scalar_bindings.h"
extern "C" long PyInt_AsLong(FactoryPyObject*);
extern "C" const char lbl_802A2F60[];
extern "C" const float lbl_8037970C;
extern "C" void fn_801FC26C(void*, int, void*, long, float);

extern "C" FactoryPyObject* fn_800CFDC8(FactoryPyObject*, FactoryPyObject* args) {
    void* native0;
    int arg1;
    void* native1;
    float arg4 = lbl_8037970C;
    FactoryPyObject* arg0 = 0;
    FactoryPyObject* arg2 = 0;
    FactoryPyObject* arg3 = 0;
    if (!PyArg_ParseTuple(args, lbl_802A2F60, &arg0, &arg1, &arg2, &arg3, &arg4)) return 0;
    if (fn_800CD864(arg0, (void**)&native0, lbl_80318988[0x1C / 4], 1) == -1) return 0;
    if (fn_800CD864(arg2, (void**)&native1, lbl_80318988[0xC4 / 4], 1) == -1) return 0;
    long value = PyInt_AsLong(arg3);
    fn_801FC26C(native0, arg1, native1, value, arg4);
    ++_Py_NoneStruct.references;
    return &_Py_NoneStruct;
}
