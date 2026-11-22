#include "Game/python_scalar_bindings.h"
extern "C" const char lbl_802A4698[];
struct NativeVoidView_800D6F7C;
extern "C" void fn_8006CC88(NativeVoidView_800D6F7C*, unsigned short);
extern "C" FactoryPyObject* fn_800D6F7C(FactoryPyObject*, FactoryPyObject* args) {
    NativeVoidView_800D6F7C* self;
    FactoryPyObject* parsed = 0;
    unsigned short value0;
    if (!PyArg_ParseTuple(args, lbl_802A4698, &parsed, &value0)) return 0;
    if (fn_800CD864(parsed, (void**)&self, lbl_80318988[0x84 / 4], 1) == -1) return 0;
    fn_8006CC88(self, value0);
    ++_Py_NoneStruct.references;
    return &_Py_NoneStruct;
}
