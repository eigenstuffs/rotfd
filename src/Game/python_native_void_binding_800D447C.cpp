/* Native void binding; see docs/notes/game-python-native-void-bindings.md. */
#include "Game/python_scalar_bindings.h"
extern "C" const char lbl_802A3D8C[];
struct NativeVoidView_800D447C;
extern "C" void fn_800692B4(NativeVoidView_800D447C*, unsigned char);
extern "C" FactoryPyObject* fn_800D447C(FactoryPyObject*, FactoryPyObject* args) {
    NativeVoidView_800D447C* self;
    FactoryPyObject* parsed = 0;
    unsigned char value0;
    if (!PyArg_ParseTuple(args, lbl_802A3D8C, &parsed, &value0)) return 0;
    if (fn_800CD864(parsed, (void**)&self, lbl_80318988[0x84 / 4], 1) == -1) return 0;
    fn_800692B4(self, value0);
    ++_Py_NoneStruct.references;
    return &_Py_NoneStruct;
}
