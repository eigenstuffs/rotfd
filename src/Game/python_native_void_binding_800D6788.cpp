#include "Game/python_scalar_bindings.h"
extern "C" const char lbl_802A44E4[];
struct NativeVoidView_800D6788;
extern "C" void fn_8006C6AC(NativeVoidView_800D6788*, unsigned char);
extern "C" FactoryPyObject* fn_800D6788(FactoryPyObject*, FactoryPyObject* args) {
    NativeVoidView_800D6788* self;
    FactoryPyObject* parsed = 0;
    unsigned char value0;
    if (!PyArg_ParseTuple(args, lbl_802A44E4, &parsed, &value0)) return 0;
    if (fn_800CD864(parsed, (void**)&self, lbl_80318988[0x84 / 4], 1) == -1) return 0;
    fn_8006C6AC(self, value0);
    ++_Py_NoneStruct.references;
    return &_Py_NoneStruct;
}
