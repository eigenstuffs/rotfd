#include "Game/python_scalar_bindings.h"
extern "C" const char lbl_802A4650[];
struct NativeVoidView_800D6E44;
extern "C" void fn_80069B7C(NativeVoidView_800D6E44*, short);
extern "C" FactoryPyObject* fn_800D6E44(FactoryPyObject*, FactoryPyObject* args) {
    NativeVoidView_800D6E44* self;
    FactoryPyObject* parsed = 0;
    short value0;
    if (!PyArg_ParseTuple(args, lbl_802A4650, &parsed, &value0)) return 0;
    if (fn_800CD864(parsed, (void**)&self, lbl_80318988[0x84 / 4], 1) == -1) return 0;
    fn_80069B7C(self, value0);
    ++_Py_NoneStruct.references;
    return &_Py_NoneStruct;
}
