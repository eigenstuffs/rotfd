#include "Game/python_scalar_bindings.h"
extern "C" const char lbl_802A3CAC[];
struct NativeVoidView_800D40AC;
extern "C" void fn_80069C34(NativeVoidView_800D40AC*, unsigned char, short);
extern "C" FactoryPyObject* fn_800D40AC(FactoryPyObject*, FactoryPyObject* args) {
    NativeVoidView_800D40AC* self;
    FactoryPyObject* parsed = 0;
    short value1;
    unsigned char value0;
    if (!PyArg_ParseTuple(args, lbl_802A3CAC, &parsed, &value0, &value1)) return 0;
    if (fn_800CD864(parsed, (void**)&self, lbl_80318988[0x84 / 4], 1) == -1) return 0;
    fn_80069C34(self, value0, value1);
    ++_Py_NoneStruct.references;
    return &_Py_NoneStruct;
}
