#include "Game/python_scalar_bindings.h"
extern "C" const char lbl_802A4CC4[];
struct NativeVoidView_800D8FB8;
extern "C" void fn_80255A90(NativeVoidView_800D8FB8*);
extern "C" FactoryPyObject* fn_800D8FB8(FactoryPyObject*, FactoryPyObject* args) {
    NativeVoidView_800D8FB8* self;
    FactoryPyObject* parsed = 0;
    if (!PyArg_ParseTuple(args, lbl_802A4CC4, &parsed)) return 0;
    if (fn_800CD864(parsed, (void**)&self, lbl_80318988[0x28 / 4], 1) == -1) return 0;
    fn_80255A90(self);
    ++_Py_NoneStruct.references;
    return &_Py_NoneStruct;
}
