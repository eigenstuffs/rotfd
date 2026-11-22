#include "Game/python_scalar_bindings.h"
extern "C" const char lbl_802A4F34[];
struct NativeVoidView_800DA3B4;
extern "C" void fn_80257490(NativeVoidView_800DA3B4*);
extern "C" FactoryPyObject* fn_800DA3B4(FactoryPyObject*, FactoryPyObject* args) {
    NativeVoidView_800DA3B4* self;
    FactoryPyObject* parsed = 0;
    if (!PyArg_ParseTuple(args, lbl_802A4F34, &parsed)) return 0;
    if (fn_800CD864(parsed, (void**)&self, lbl_80318988[0x20 / 4], 1) == -1) return 0;
    fn_80257490(self);
    ++_Py_NoneStruct.references;
    return &_Py_NoneStruct;
}
