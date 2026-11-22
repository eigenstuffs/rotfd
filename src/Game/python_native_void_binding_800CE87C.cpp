#include "Game/python_scalar_bindings.h"
extern "C" const char lbl_802A2CE4[];
struct NativeVoidView_800CE87C;
extern "C" void fn_8023CEC4(NativeVoidView_800CE87C*, float);
extern "C" FactoryPyObject* fn_800CE87C(FactoryPyObject*, FactoryPyObject* args) {
    NativeVoidView_800CE87C* self;
    float value0;
    FactoryPyObject* parsed = 0;
    if (!PyArg_ParseTuple(args, lbl_802A2CE4, &parsed, &value0)) return 0;
    if (fn_800CD864(parsed, (void**)&self, lbl_80318988[0xC8 / 4], 1) == -1) return 0;
    fn_8023CEC4(self, value0);
    ++_Py_NoneStruct.references;
    return &_Py_NoneStruct;
}
