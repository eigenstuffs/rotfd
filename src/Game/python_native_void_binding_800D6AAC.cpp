/* Native void binding; see docs/notes/game-python-native-void-bindings.md. */
#include "Game/python_scalar_bindings.h"
extern "C" const char lbl_802A459C[];
struct NativeVoidView_800D6AAC;
extern "C" void fn_8006C910(NativeVoidView_800D6AAC*, float);
extern "C" FactoryPyObject* fn_800D6AAC(FactoryPyObject*, FactoryPyObject* args) {
    NativeVoidView_800D6AAC* self;
    float value0;
    FactoryPyObject* parsed = 0;
    if (!PyArg_ParseTuple(args, lbl_802A459C, &parsed, &value0)) return 0;
    if (fn_800CD864(parsed, (void**)&self, lbl_80318988[0x84 / 4], 1) == -1) return 0;
    fn_8006C910(self, value0);
    ++_Py_NoneStruct.references;
    return &_Py_NoneStruct;
}
