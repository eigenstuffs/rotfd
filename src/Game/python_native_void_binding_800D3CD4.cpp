#include "Game/python_scalar_bindings.h"
extern "C" const char lbl_802A3BD8[];
struct NativeVoidView_800D3CD4;
extern "C" void fn_80069B58(NativeVoidView_800D3CD4*, unsigned char, short);
extern "C" FactoryPyObject* fn_800D3CD4(FactoryPyObject*, FactoryPyObject* args) {
    NativeVoidView_800D3CD4* self;
    FactoryPyObject* parsed = 0;
    short value1;
    unsigned char value0;
    if (!PyArg_ParseTuple(args, lbl_802A3BD8, &parsed, &value0, &value1)) return 0;
    if (fn_800CD864(parsed, (void**)&self, lbl_80318988[0x84 / 4], 1) == -1) return 0;
    fn_80069B58(self, value0, value1);
    ++_Py_NoneStruct.references;
    return &_Py_NoneStruct;
}
