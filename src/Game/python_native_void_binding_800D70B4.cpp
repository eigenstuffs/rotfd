/* Native void binding; see docs/notes/game-python-native-void-bindings.md. */
#include "Game/python_scalar_bindings.h"
extern "C" const char lbl_802A46E0[];
struct NativeVoidView_800D70B4;
extern "C" void fn_8006CCD0(NativeVoidView_800D70B4*, unsigned short);
extern "C" FactoryPyObject* fn_800D70B4(FactoryPyObject*, FactoryPyObject* args) {
    NativeVoidView_800D70B4* self;
    FactoryPyObject* parsed = 0;
    unsigned short value0;
    if (!PyArg_ParseTuple(args, lbl_802A46E0, &parsed, &value0)) return 0;
    if (fn_800CD864(parsed, (void**)&self, lbl_80318988[0x84 / 4], 1) == -1) return 0;
    fn_8006CCD0(self, value0);
    ++_Py_NoneStruct.references;
    return &_Py_NoneStruct;
}
