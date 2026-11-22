#include "Game/python_scalar_bindings.h"
extern "C" const char lbl_802A5B20[];
struct NativeVoidView_800DFA98;
extern "C" void fn_80255678(NativeVoidView_800DFA98*);
extern "C" FactoryPyObject* fn_800DFA98(FactoryPyObject*, FactoryPyObject* args) {
    NativeVoidView_800DFA98* self;
    FactoryPyObject* parsed = 0;
    if (!PyArg_ParseTuple(args, lbl_802A5B20, &parsed)) return 0;
    if (fn_800CD864(parsed, (void**)&self, lbl_80318988[0x4C / 4], 1) == -1) return 0;
    fn_80255678(self);
    ++_Py_NoneStruct.references;
    return &_Py_NoneStruct;
}
