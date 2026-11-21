/* Native void binding; see docs/notes/game-python-native-void-bindings.md. */
#include "Game/python_scalar_bindings.h"
extern "C" const char lbl_802A42D4[];
struct NativeVoidView_800D5C88;
extern "C" void fn_8006B968(NativeVoidView_800D5C88*, unsigned char);
extern "C" FactoryPyObject* fn_800D5C88(FactoryPyObject*, FactoryPyObject* args) {
    NativeVoidView_800D5C88* self;
    FactoryPyObject* parsed = 0;
    unsigned char value0;
    if (!PyArg_ParseTuple(args, lbl_802A42D4, &parsed, &value0)) return 0;
    if (fn_800CD864(parsed, (void**)&self, lbl_80318988[0x84 / 4], 1) == -1) return 0;
    fn_8006B968(self, value0);
    ++_Py_NoneStruct.references;
    return &_Py_NoneStruct;
}
