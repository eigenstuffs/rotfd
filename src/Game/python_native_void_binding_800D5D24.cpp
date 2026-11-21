/* Native void binding; see docs/notes/game-python-native-void-bindings.md. */
#include "Game/python_scalar_bindings.h"
extern "C" const char lbl_802A42F8[];
struct NativeVoidView_800D5D24;
extern "C" void fn_8006B9D4(NativeVoidView_800D5D24*, unsigned char);
extern "C" FactoryPyObject* fn_800D5D24(FactoryPyObject*, FactoryPyObject* args) {
    NativeVoidView_800D5D24* self;
    FactoryPyObject* parsed = 0;
    unsigned char value0;
    if (!PyArg_ParseTuple(args, lbl_802A42F8, &parsed, &value0)) return 0;
    if (fn_800CD864(parsed, (void**)&self, lbl_80318988[0x84 / 4], 1) == -1) return 0;
    fn_8006B9D4(self, value0);
    ++_Py_NoneStruct.references;
    return &_Py_NoneStruct;
}
