/* Native void binding; see docs/notes/game-python-native-void-bindings.md. */
#include "Game/python_scalar_bindings.h"
extern "C" const char lbl_802A44C0[];
struct NativeVoidView_800D66EC;
extern "C" void fn_80068CB4(NativeVoidView_800D66EC*, unsigned char);
extern "C" FactoryPyObject* fn_800D66EC(FactoryPyObject*, FactoryPyObject* args) {
    NativeVoidView_800D66EC* self;
    FactoryPyObject* parsed = 0;
    unsigned char value0;
    if (!PyArg_ParseTuple(args, lbl_802A44C0, &parsed, &value0)) return 0;
    if (fn_800CD864(parsed, (void**)&self, lbl_80318988[0x84 / 4], 1) == -1) return 0;
    fn_80068CB4(self, value0);
    ++_Py_NoneStruct.references;
    return &_Py_NoneStruct;
}
