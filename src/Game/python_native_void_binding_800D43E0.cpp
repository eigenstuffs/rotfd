#include "Game/python_scalar_bindings.h"
extern "C" const char lbl_802A3D68[];
struct NativeVoidView_800D43E0;
extern "C" void fn_800692AC(NativeVoidView_800D43E0*, float);
extern "C" FactoryPyObject* fn_800D43E0(FactoryPyObject*, FactoryPyObject* args) {
    NativeVoidView_800D43E0* self;
    float value0;
    FactoryPyObject* parsed = 0;
    if (!PyArg_ParseTuple(args, lbl_802A3D68, &parsed, &value0)) return 0;
    if (fn_800CD864(parsed, (void**)&self, lbl_80318988[0x84 / 4], 1) == -1) return 0;
    fn_800692AC(self, value0);
    ++_Py_NoneStruct.references;
    return &_Py_NoneStruct;
}
