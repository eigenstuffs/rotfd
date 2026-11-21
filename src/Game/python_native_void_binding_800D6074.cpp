/* Native void binding; see docs/notes/game-python-native-void-bindings.md. */
#include "Game/python_scalar_bindings.h"
extern "C" const char lbl_802A43B0[];
struct NativeVoidView_800D6074;
extern "C" void fn_8006BFF8(NativeVoidView_800D6074*, unsigned char);
extern "C" FactoryPyObject* fn_800D6074(FactoryPyObject*, FactoryPyObject* args) {
    NativeVoidView_800D6074* self;
    FactoryPyObject* parsed = 0;
    unsigned char value0;
    if (!PyArg_ParseTuple(args, lbl_802A43B0, &parsed, &value0)) return 0;
    if (fn_800CD864(parsed, (void**)&self, lbl_80318988[0x84 / 4], 1) == -1) return 0;
    fn_8006BFF8(self, value0);
    ++_Py_NoneStruct.references;
    return &_Py_NoneStruct;
}
