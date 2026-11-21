/* Native void binding; see docs/notes/game-python-native-void-bindings.md. */
#include "Game/python_scalar_bindings.h"
extern "C" const char lbl_802A4578[];
struct NativeVoidView_800D6A10;
extern "C" void fn_8006C88C(NativeVoidView_800D6A10*, float);
extern "C" FactoryPyObject* fn_800D6A10(FactoryPyObject*, FactoryPyObject* args) {
    NativeVoidView_800D6A10* self;
    float value0;
    FactoryPyObject* parsed = 0;
    if (!PyArg_ParseTuple(args, lbl_802A4578, &parsed, &value0)) return 0;
    if (fn_800CD864(parsed, (void**)&self, lbl_80318988[0x84 / 4], 1) == -1) return 0;
    fn_8006C88C(self, value0);
    ++_Py_NoneStruct.references;
    return &_Py_NoneStruct;
}
