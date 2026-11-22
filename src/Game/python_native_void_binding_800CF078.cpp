#include "Game/python_scalar_bindings.h"
extern "C" const char lbl_802A2DE4[];
struct NativeVoidView_800CF078;
extern "C" void fn_802022FC(NativeVoidView_800CF078*);
extern "C" FactoryPyObject* fn_800CF078(FactoryPyObject*, FactoryPyObject* args) {
    NativeVoidView_800CF078* self;
    FactoryPyObject* parsed = 0;
    if (!PyArg_ParseTuple(args, lbl_802A2DE4, &parsed)) return 0;
    if (fn_800CD864(parsed, (void**)&self, lbl_80318988[0x1C / 4], 1) == -1) return 0;
    fn_802022FC(self);
    ++_Py_NoneStruct.references;
    return &_Py_NoneStruct;
}
