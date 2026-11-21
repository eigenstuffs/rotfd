/* Native void binding; see docs/notes/game-python-native-void-bindings.md. */
#include "Game/python_scalar_bindings.h"
extern "C" const char lbl_802A449C[];
struct NativeVoidView_800D6648;
extern "C" void fn_80068C70(NativeVoidView_800D6648*, unsigned char, unsigned char);
extern "C" FactoryPyObject* fn_800D6648(FactoryPyObject*, FactoryPyObject* args) {
    NativeVoidView_800D6648* self;
    FactoryPyObject* parsed = 0;
    unsigned char value0;
    unsigned char value1;
    if (!PyArg_ParseTuple(args, lbl_802A449C, &parsed, &value0, &value1)) return 0;
    if (fn_800CD864(parsed, (void**)&self, lbl_80318988[0x84 / 4], 1) == -1) return 0;
    fn_80068C70(self, value0, value1);
    ++_Py_NoneStruct.references;
    return &_Py_NoneStruct;
}
